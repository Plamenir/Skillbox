#include <iostream>
#include <sstream>

std::string output(float speed) {
  std::stringstream output;
  output << "Текущая скорость " << speed << " км/ч";
  return output.str();
}

int main() {
  float speed = 0, changeSpeed;
  std::cout << output(speed) << "\n";
  do {
    std::cout << "Введите ускорение: ";
    std::cin >> changeSpeed;
    speed += changeSpeed;
    std::cout << output(speed) << "\n";
  } while (speed != 0);
}
