#include <fstream>
#include <iostream>

int main() {
  std::ifstream input("../river.txt");
  std::ofstream output("../basket.txt");
  std::string buffer, target;
  std::cout << "Какую рыбу будем ловить? ";
  std::cin >> target;
  while (input >> buffer) {
    if (buffer == target)
      output << buffer << "\n";
  }
  input.close();
  output.close();
}
