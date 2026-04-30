#pragma once
#include <stdint.h>

class GameState;

#define STACK_SIZE  10

class LimitedStack {

private:
	GameState* buffer_ [STACK_SIZE];
	uint8_t head_;
	uint8_t queue_;
	uint8_t count_;

	void deleteLast();

public:
	LimitedStack();
	~LimitedStack();

	void reset();
	void push(GameState* state);
	GameState* pop();
};
