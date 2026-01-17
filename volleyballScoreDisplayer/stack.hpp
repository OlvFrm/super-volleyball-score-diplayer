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
    Node* tempNode;

    while (top_ != nullptr) {
      tempNode = top_;
      top_ = top_->getNext();
      delete tempNode;
      count_--;
    }
  }

  /* Push an element on top of the Stack */
  void push(GameState* newState) {
    Node* newNode = new Node(newState, top_);
    top_ = newNode;
    count_++;
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
