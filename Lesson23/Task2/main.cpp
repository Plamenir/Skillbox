#include <ctime>
#include <fstream>
#include <iostream>

int main() {
  std::srand(std::time(nullptr));
  std::ofstream picture("../pic.txt");
  int x, y;
  std::cout << "Введите размер картины: ";
  std::cin >> x >> y;
  for (int i = 0; i < x; ++i) {
    for (int k = 0; k < y; ++k) {
      picture << rand() % 2;
    }
    picture << "\n";
  }
  picture.close();
}
