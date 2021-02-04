#include <iostream>
#include <sstream>

double action(std::string input, char act) {
  std::stringstream buffer;
  std::string number1, number2;
  buffer << input;
  buffer >> number1 >> number2;
  switch (act) {
    case '+':
      return stod(number1) + stod(number2);
    case '-':
      return stod(number1) - stod(number2);
    case '*':
      return stod(number1) * stod(number2);
    case '/':
      return stod(number1) / stod(number2);
  }
}

int main() {
  std::string input;
  char act;
  std::cout << "Что нужно посчитать?\n";
  std::cin >> input;

  for (int i = 0; i < input.length(); ++i) {
    if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
        input[i] == '/') {
      act = input[i];
      input[i] = ' ';
      break;
    }
  }
  double result;
  result = action(input, act);
  std::cout << "Результат: " << result << "\n";
}
