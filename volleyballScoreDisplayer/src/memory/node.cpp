#include "memory/node.hpp"


Node::Node(GameState* gameState, Node* nextNode):
    gameState_(gameState), next_(nextNode) {}

/* Node destructor, deletes the GameState*/
Node::~Node() {
    if (gameState_ != nullptr) {
        delete gameState_;
    }
}

/* GameState getter */
GameState* Node::getGameState() {
    return gameState_;
}

/* GameState getter but unlinks game state from Node */
GameState* Node::popGameState() {
    GameState* poppedGameState = gameState_;
    gameState_ = nullptr;
    return poppedGameState;
}

/* Next Node getter */
Node* Node::getNext() {
    return next_;
}