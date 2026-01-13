#pragma once

class GameState;


/* Node for the stack of GameStates */
class Node {
friend class Stack;

private:
  /* Pointer to the game state object */
  GameState* gameState_;
  /* Pointer to the next Node in the stack */
  Node* next_;

  Node(GameState* gameState, Node* nextNode)
    : gameState_(gameState), next_(nextNode) {
  }

  /* Node destructor, deletes the GameState*/
  ~Node() {
    if (gameState_ != nullptr) {
      delete gameState_;
    }
  }

  /* GameState getter */
  GameState* getGameState() {
    return gameState_;
  }

  /* GameState getter but unlinks game state from Node */
  GameState* popGameState() {
    GameState* poppedGameState = gameState_;
    gameState_ = nullptr;
    return poppedGameState;
  }

  /* Next Node getter */
  Node* getNext() {
    return next_;
  }
};