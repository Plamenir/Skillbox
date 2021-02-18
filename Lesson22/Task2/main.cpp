#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
  char buff[20];
  std::ifstream txt("../text.txt");

  if (!txt.is_open()) {
    std::cerr << "Ошибка открытия файла!"
              << "\n";
    exit(1);
  }
  txt.seekg(0, std::ios::end);
  int size = txt.tellg();
  txt.seekg(0, std::ios::beg);
  while (size >= 20) {
    txt.read(buff, 20);
    std::cout << buff;
    size -= 20;
  }
  txt.read(buff, size);
  buff[size + 1] = '\0';
  std::cout << buff;
  txt.close();
}
