#include <iostream>

/* Class that contains the state of the game. 
  For now just for debugging purposes
*/
class GameState {
private:
  /* Score for team A */
  unsigned int scoreA_;
  /* Score for team B */
  unsigned int scoreB_;
  /* Team that serves the ball */
  bool service_;

public:
  /* Constructor that does nothing */
  GameState(int scoreA, int scoreB, bool service)
    : scoreA_(scoreA), scoreB_(scoreB), service_(service) {}

  void print() {
      std::cout << "(" << std::to_string(scoreA_) << ", "
      << std::to_string(scoreB_)   << ") serve: "
      << std::to_string(service_) << "\n";
  }

  // void print() {
  //   Serial.print("(");
  //   Serial.print(scoreA_);
  //   Serial.print(", ");
  //   Serial.print(scoreB_);
  //   Serial.print(") service ");
  //   Serial.print(service_);
  // }
};

/* Node for the stack of GameStates */
class Node {
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
    delete gameState_;
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
  friend class Stack;
};

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
    while (count_ > 0) {
      Node* nextNode = top_->getNext();
      delete top_;
      top_ = nextNode;
      count_--;
    }
  }

  /* Push an element on top of the Stack */
  Node* push(GameState* newState) {
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


int main(void) {
  Stack* stack = new Stack();

  // Stacking
  GameState* gameState = new GameState(0, 0, 0);
  gameState->print();
  stack->push(gameState);

  gameState = new GameState(1, 0, 0);
  gameState->print();
  stack->push(gameState);

  gameState = new GameState(2, 0, 0);
  gameState->print();
  stack->push(gameState);

  gameState = new GameState(2, 1, 1);
  gameState->print();
  stack->push(gameState);

  // Unstacking
  gameState = stack->pop();  // (2, 1), 1
  gameState->print();

  gameState = stack->pop();  // (2, 0), 0
  gameState->print();

  gameState = stack->pop();  // (1, 0), 0
  gameState->print();

  gameState = stack->pop();  // (0, 0), 0
  gameState->print();

  gameState = stack->pop();  // empty, returns nullptr
}


// void setup() {
//   Serial.begin(9600);
// }

// void loop() {
//   Serial.println("In loop");
//   delay(1000);  // Wait for 1000 millisecond(s)
//   main();
// }