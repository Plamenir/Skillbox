#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
  std::ifstream dict;
  std::string word, buff;
  int cnt = 0;
  dict.open("../dictionary.txt");
  if (!dict.is_open()) {
    std::cerr << "Произошла ошибка при открытии файла!"
              << "\n";
    std::exit(1);
  }

  std::cout << "Что ищем?"
            << "\n";
  std::cin >> word;

  while (!dict.eof()) {
    buff = "";
    dict >> buff;
    if (buff == word) ++cnt;
  }
  dict.close();
  std::cout << "Слово \"" << word << "\" повторяется " << cnt << " раз."
            << "\n";
}
