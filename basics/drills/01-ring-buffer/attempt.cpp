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

void push(int value) {
  buf[head] = value;
  head = head + 1;
  if (head == 4) {
    head = 0;
  }
}

int main() {
  push(10);
  push(20);
  push(30);
  push(40);
  push(50);

  for (int i = 0; i < 4; i = i + 1) {
    std::cout << buf[i] << " ";
  }
  std::cout << "head=" << head << std::endl;
}
