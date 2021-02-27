#include <ctime>
#include <fstream>
#include <iostream>

void fillingATM();
void withdrawal(int cash);

int main() {
  char symb;
  std::cout << "Хотите заполнить банкомат или снять деньги? (+/-) ";
  std::cin >> symb;
  if (symb == '+')
    fillingATM();
  else if (symb == '-') {
    int cash;
    std::cout << "Какую сумму вы хотите снять ? ";
    std::cin >> cash;
    withdrawal(cash);
  }
}

void fillingATM() {
  std::srand(std::time(nullptr));
  std::ofstream filling("../ATM.txt", std::ios::binary);
  if (!filling.is_open()) {
    std::cerr << "Не могу открыть файл!"
              << "\n";
    exit(1);
  }
  int bill;
  for (int i = 0; i < 1000; ++i) {
    if (rand() % 2 == 0)
      bill = 100;
    else
      bill = 5000;
    filling.write((char *)&bill, sizeof(int));
  }
  filling.close();
}

void withdrawal(int cash) {
  if (cash % 100 != 0) {
    std::cerr << "Вы ввели неверую сумму!"
              << "\n";
    exit(1);
  }
  std::ifstream take("../ATM.txt", std::ios::binary);
  if (!take.is_open()) {
    std::cerr << "Не могу открыть файл!"
              << "\n";
    exit(1);
  }
  int bill;
  std::cout << "Вы получаете купюры следующего номинала:"
            << "\n";
  while (take.read((char *)&bill, sizeof(int))) {
    if (cash - bill == 0) {
      std::cout << bill << "\n";
      return;
    } else if (cash - bill < 0) {
      continue;
    } else {
      std::cout << bill << "\n";
      cash -= bill;
    }
  }
}
