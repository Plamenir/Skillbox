#include <iostream>

void evenCnt(long long number, int &ans) {
  while (number != 0) {
    if ((number % 10) % 2 == 0) ++ans;
    number /= 10;
  }
}

int main() {
  long long number;
  int ans = 0;
  std::cout << "Введите число: ";
  std::cin >> number;
  evenCnt(number, ans);
  std::cout << ans << "\n";
}
