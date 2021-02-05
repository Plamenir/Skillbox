#include <iostream>
#include <sstream>

void playingMusic(std::stringstream &buffer);

int main() {
  std::string input;
  std::stringstream buffer;
  for (int i = 0; i < 12; ++i) {
    std::cout << "Введите трехзначную комбинацию нот: ";
    std::cin >> input;
    buffer << input;
  }
  playingMusic(buffer);
}

void playingMusic(std::stringstream &buffer) {
  std::string tempStroke;
  enum notes {
    DO = 0b00000001,
    RE = 0b00000010,
    MI = 0b00000100,
    FA = 0b00001000,
    SOL = 0b00010000,
    LA = 0b00100000,
    TI = 0b01000000
  };
  for (int i = 0; i < 12; ++i) {
    buffer >> tempStroke;
    for (int j = 0; j < 3; ++j) {
      if (tempStroke[j] < '1' || tempStroke[j] > '9') {
        std::cout << "Вы ввели неверные данные!\n";
        return;
      }
      switch (1 << (tempStroke[j] - '0' - 1)) {
        case DO:
          std::cout << "ДО ";
          break;
        case RE:
          std::cout << "РЕ ";
          break;
        case MI:
          std::cout << "МИ ";
          break;
        case FA:
          std::cout << "ФА ";
          break;
        case SOL:
          std::cout << "СОЛЬ ";
          break;
        case LA:
          std::cout << "ЛЯ ";
          break;
        case TI:
          std::cout << "СИ ";
      }
    }
    std::cout << "\t";
  }
  std::cout << "\n";
}
