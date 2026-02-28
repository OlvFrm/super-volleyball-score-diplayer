#include "memory/node.hpp"


Node::Node(GameState* gameState, Node* nextNode):
    gameState_(gameState), next_(nextNode) {}