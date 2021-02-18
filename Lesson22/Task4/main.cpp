#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
  char buff[4];
  std::ifstream pic;
  std::string path;
  std::cout << "Введите путь к файлу: ";
  std::cin >> path;
  pic.open(path, std::ios::binary);
  if (!pic.is_open()) {
    std::cerr << "Вы ввели неверный путь к файлу!"
              << "\n";
    exit(1);
  }
  int pos = path.find_last_of(".");
  if (path.substr(pos + 1) != "png") {
    std::cerr << "Неверный тип файла!"
              << "\n";
    exit(1);
  }
  pic.read(buff, sizeof(buff));
  int prefix;
  prefix = (int)*buff;
  if (prefix == -119 && buff[1] == 'P' && buff[2] == 'N' && buff[3] == 'G') {
    std::cout << "Файл является файлом формата png."
              << "\n";
  } else
    std::cerr << "Неверный тип файла!"
              << "\n";
  pic.close();
}
