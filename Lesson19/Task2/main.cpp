#include <iostream>
#include <sstream>

int main() {
  std::stringstream stroke;
  int firstPart, secondPart;
  double result;
  std::cout << "Введите целую часть числа: ";
  std::cin >> firstPart;
  std::cout << "Введите вторую часть числа: ";
  std::cin >> secondPart;
  stroke << firstPart << "." << secondPart;
  result = stod(stroke.str());
  std::cout << result << "\n";
}
