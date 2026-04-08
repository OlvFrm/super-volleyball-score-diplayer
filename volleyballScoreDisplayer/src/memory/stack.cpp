#include "memory/stack.hpp"
#include "state/gameState.hpp"


Stack::Stack() {
    top_ = nullptr;
    count_ = 0;
}

/* Destructor iteratively deletes all elements of the Stack*/
Stack::~Stack() {
    reset();
}

/* Push an element on top of the Stack */
void Stack::push(GameState* newState) {
    Node* newNode = new Node(newState, top_);
    top_ = newNode;
    count_++;
}

/* Pop the top element of the Stack */
GameState* Stack::pop() {
    if (isEmpty()) {
        return nullptr;
    }

    Node* tempNode = top_;
    top_ = top_->next_;
    GameState* gameState = tempNode->gameState_;

    count_--;

    delete tempNode;
    return gameState;
}

/* Peek at the top element without removing it from the stack */
GameState* Stack::peek() {
    if (isEmpty()) {
        return nullptr;
    }
    return top_->gameState_;
}

/* Empty the stack */
void Stack::reset() {
    Node* tempNode;

    while (top_ != nullptr) {
        tempNode = top_;
        top_ = top_->next_;
        if (tempNode->gameState_ != nullptr) {
            delete tempNode->gameState_;
        }
        delete tempNode;
        count_--;
    }
}

bool Stack::isEmpty() {
    return top_ == nullptr;
}

int Stack::size() {
    return count_;
}

