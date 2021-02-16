#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
  char buff[1];
  std::ifstream txt("../text.txt", std::ios::binary);

  if (!txt.is_open()) {
    std::cerr << "Ошибка открытия файла!"
              << "\n";
    exit(1);
  }
  while (!txt.eof()) {
    txt.read(buff, sizeof(char));
    std::cout << *buff;
  }
  txt.close();
}
