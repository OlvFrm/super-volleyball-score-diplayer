#include "memory/limitedStack.hpp"
#include "state/gameState.hpp"

LimitedStack::LimitedStack() :
	head_(0), queue_(0), count_(0) {}

LimitedStack::~LimitedStack() {
	reset();
}

void LimitedStack::deleteLast() {
	delete buffer_[queue_];
	queue_ = (queue_ + 1) % STACK_SIZE;
	count_--;
}

void LimitedStack::reset() {
	while (count_ != 0) {
		deleteLast();
	}
}

void LimitedStack::push(GameState* state) {
	if (state == nullptr) return;
	if (count_ == STACK_SIZE) {
		// Free space for the new one
		deleteLast();
	}
	buffer_[head_] = state;
	head_ = (head_ + 1) % STACK_SIZE;
	count_++;
}

GameState* LimitedStack::pop() {
	if (count_ == 0) return nullptr;

	head_ = (head_ + STACK_SIZE - 1) % STACK_SIZE;
	count_--;

	return buffer_[head_];
}

