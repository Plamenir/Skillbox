#include <fstream>
#include <iostream>

int main() {
  std::ofstream blank("../blank.txt");
  std::string input;
  do {
    std::cout << "Введите имя и фамилию: ";
    getline(std::cin, input);
    blank << input << " ";
    std::cout << "Введите дату: ";
    std::cin >> input;
    blank << std::stoi(input.substr(0, 1)) << std::stoi(input.substr(1, 1))
          << "." << std::stoi(input.substr(3, 1))
          << std::stoi(input.substr(4, 1)) << "."
          << std::stoi(input.substr(6, 2)) << " ";
    std::cout << "Введите сумму: ";
    std::cin >> input;
    blank << std::stoi(input) << "\n";
    std::cout << "Добавить еще одну запись? ";
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore();
  } while (input == "да" || input == "Да");
  blank.close();
}
