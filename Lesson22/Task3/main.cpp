#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
  std::ifstream bill("../bill.txt");
  std::string name, secondName, date, maxName;
  int payment, summ = 0, max = 0;

  if (!bill.is_open()) {
    std::cerr << "Ошибка при открытии файла!"
              << "\n";
    exit(1);
  }

  while (!bill.eof()) {
    bill >> name >> secondName >> payment >> date;
    if (payment > max) {
      max = payment;
      maxName = name + " " + secondName;
    }
    summ += payment;
  }
  std::cout << "Общая сумма выплат " << summ << "\n";
  std::cout << "Максимальная выплата: " << maxName << " " << max;
  std::cout << "\n";
}
