#pragma once

#include "node.hpp"

/* LIFO stack of GameStates */
class Stack {
private:
  /* Pointer to the top Node of the Stack*/
  Node* top_;
  /* Number of elements on the Stack */
  int count_;

public:
  /* Construct an empty stack */
  Stack() {
    top_ = nullptr;
    count_ = 0;
  }

  /* Destructor iteratively deletes all elements of the Stack */
  ~Stack() {
    Node* nextNode;
    while (count_ > 0) {
      nextNode = top_->getNext();
      delete top_;
      top_ = nextNode;
      count_--;
    }
  }

  /* Push an element on top of the Stack */
  Node* push(GameState* newState) {  // TODO maybe the Node shouldn't be accessible outside the stack.
    Node* newNode = new Node(newState, top_);
    top_ = newNode;
    count_++;

    return newNode;
  }

  /* Pop the top element of the Stack */
  GameState* pop() {
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
  GameState* peek() {
    if (top_ == nullptr) {
      // Stack is Empty
      return nullptr;
    }
    return top_->getGameState();
  }

  bool isEmpty() {
    return top_ == nullptr;
  }

  int size() {
    return count_;
  }
};
