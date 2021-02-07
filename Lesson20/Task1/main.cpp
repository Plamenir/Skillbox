#include <iostream>

void swap(int* a, int* b);
int main() {
  int a = 10, b = 20;
  swap(&a, &b);
  std::cout << a << " " << b << "\n";
}

void swap(int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
