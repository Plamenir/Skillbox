#include <cstdlib>
#include <fstream>
#include <iostream>

void fileIsOk(std::ifstream &file) {
  if (!file.is_open()) {
    std::cerr << "Ошибка чтения файла!"
              << "\n";
    exit(1);
  }
}

void congrat(std::string winner) {
  std::cout << "Победу одержали " << winner << "!"
            << "\n";
  exit(0);
}

int main() {

  std::ifstream question, answer;
  std::string buffer, filename;
  int cntSector = 13, sector = 1, round, expertScore = 0, viewerScore = 0;
  bool happenedBefore[13] = {};

  while (cntSector) {

    std::cout << "Счет: "
              << "\n"
              << "Знатоки " << expertScore << " Телезрители " << viewerScore
              << "\n";
    std::cout << "Введите смещение: ";
    std::cin >> round;
    sector += round;
    if (sector > 13)
      sector %= 13;
    while (happenedBefore[sector]) {
      ++sector;
      if (sector > 13)
        sector %= 13;
    }
    happenedBefore[sector] = true;
    --cntSector;
    filename = "../question" + std::to_string(sector) + ".txt";
    question.open(filename);
    fileIsOk(question);
    std::cout << "Сектор " << sector << "\n";
    std::cout << "Внимание вопрос!"
              << "\n";
    while (question >> buffer) {
      std::cout << buffer << " ";
    }
    question.close();
    std::string userAnswer;
    std::cout << "\n"
              << "Ваш ответ: ";
    std::cin >> userAnswer;
    filename = "../answer" + std::to_string(sector) + ".txt";
    answer.open(filename);
    fileIsOk(answer);
    answer >> buffer;
    if (userAnswer == buffer) {
      std::cout << "Это верный ответ!"
                << "\n";
      ++expertScore;
      if (expertScore == 6)
        congrat("знатоки");
    } else {
      std::cout << "Это неверный ответ!"
                << "\n";
      ++viewerScore;
      if (viewerScore == 6)
        congrat("телезрители");
    }
    answer.close();
  }
}
