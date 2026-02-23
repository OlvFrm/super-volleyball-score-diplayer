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
  Stack();

  /* Destructor iteratively deletes all elements of the Stack */
  ~Stack();

  /* Push an element on top of the Stack */
  void push(GameState* newState);

  /* Pop the top element of the Stack */
  GameState* pop();

  /* Peek at the top element without removing it from the stack */
  GameState* peek();

  bool isEmpty();

  int size();
};
