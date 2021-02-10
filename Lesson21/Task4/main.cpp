#include <iostream>

void evenCnt(long long number, int &cnt);

int main() {
  long long number;
  int ans = 0;
  std::cout << "Введите число: ";
  std::cin >> number;
  evenCnt(number, ans);
  std::cout << ans << "\n";
}
void evenCnt(long long number, int &cnt) {
  if ((number % 10) % 2 == 0) cnt++;
  if (number / 10) evenCnt(number / 10, cnt);
}
