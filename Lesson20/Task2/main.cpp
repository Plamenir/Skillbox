#include <iostream>
int* swapmatrix(int* matrix);
int main() {
  int matrix1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int* matrix2;
  matrix2 = swapmatrix(matrix1);
  for (int i = 0; i < 10; ++i) {
    std::cout << *(matrix2 + i) << " ";
  }
  std::cout << "\n";
}

int* swapmatrix(int* matrix) {
  int swap;
  for (int i = 0; i < 5; ++i) {
    swap = *(matrix + i);
    *(matrix + i) = *(matrix + 9 - i);
    *(matrix + 9 - i) = swap;
  }
  return matrix;
}
