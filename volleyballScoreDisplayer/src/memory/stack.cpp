#include "memory/stack.hpp"


Stack::Stack() {
    top_ = nullptr;
    count_ = 0;
}

/* Destructor iteratively deletes all elements of the Stack */
Stack::~Stack() {
    Node* tempNode;

    while (top_ != nullptr) {
        tempNode = top_;
        top_ = top_->getNext();
        delete tempNode;
        count_--;
    }
}

/* Push an element on top of the Stack */
void Stack::push(GameState* newState) {
    Node* newNode = new Node(newState, top_);
    top_ = newNode;
    count_++;
}

/* Pop the top element of the Stack */
GameState* Stack::pop() {
    if (top_ == nullptr) {
        return nullptr;
}

Node* temp = top_;
    top_ = top_->getNext();
    GameState* gameState = temp->popGameState();

    count_--;

    delete temp;
    return gameState;
}

/* Peek at the top element without removing it from the stack */
GameState* Stack::peek() {
    if (top_ == nullptr) {
        // Stack is Empty
        return nullptr;
    }
    return top_->getGameState();
}

bool Stack::isEmpty() {
    return top_ == nullptr;
}

int Stack::size() {
    return count_;
}

