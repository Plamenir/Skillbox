#include <iostream>

int jumps(int n, int k = 3);

int main() {
  int n, k;

  std::cout << "Введите количество ступенек: ";
  std::cin >> n;
  std::cout << "Введите максимальную длину прыжка: ";
  if (std::cin >> k)
    std::cout << jumps(n, k) << '\n';
  else
    std::cout << jumps(n) << "\n";
}

int calc(int k, int n, int i) {
  return (i ? jumps(n - i, k) + calc(k, n, i - 1) : n <= k);
}

int jumps(int n, int k) { return (n <= 0 ? 0 : calc(k, n, k)); }
