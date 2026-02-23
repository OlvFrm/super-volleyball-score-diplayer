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
  
  
  /* Node constructor*/
  Node(GameState* gameState, Node* nextNode);

  /* Node destructor, deletes the GameState*/
  ~Node();

  /* GameState getter */
  GameState* getGameState();

  /* GameState getter but unlinks game state from Node */
  GameState* popGameState();

  /* Next Node getter */
  Node* getNext();
};