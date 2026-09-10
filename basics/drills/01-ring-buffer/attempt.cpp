// Fixed-size ring buffer, cold
// Fixed capacity known at construction
// No new/malloc, no std::vector
// push(T) returns whether it succeeded
// pop(T&) or std::optional<T> — your call, but be able to defend it
// full() and empty() must be distinguishable when head and tail coincide
// size() correct across wraparound

#include <iostream>

int buf[4];
int head = 0;
int tail = 0;

int push(int) {
  while (head > 4)
    head ++;
}

int pop() {
  while (push(0)) {
    tail ++;
  }
}

int main() {
push(0);
  std::cout << head << std::endl;
push(1);
  std::cout << head << std::endl;
push(2);
  std::cout << head << std::endl;
push(3);
  std::cout << head << std::endl;
push(4);
  std::cout << head << std::endl;
}
