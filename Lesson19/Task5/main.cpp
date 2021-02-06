#include <iostream>
#include <sstream>

int autoAction(std::stringstream &buffer, int tumbler, int time);

int main() {
  int tumbler = 0;
  std::string state;
  std::stringstream buffer;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 24; ++j) {
      std::cout << "Сейчас идет день №" << i << " Время " << j << ":00\n";
      std::cout << "Введите показатели: ";
      std::getline(std::cin, state);
      buffer.str("");
      buffer.clear();
      buffer << state;
      tumbler = autoAction(buffer, tumbler, j);
    }
  }
}

int autoAction(std::stringstream &buffer, int tumbler, int time) {
  std::string tempExt, tempInt, moving, lightInt;
  enum condition {
    SOCKETS = 0b00000001,
    INTERNAL_LIGHT = 0b00000010,
    EXTERNAL_LIGHT = 0b00000100,
    INTERNAL_HEATING = 0b00001000,
    PIPES_HEATING = 0b00010000,
    CONDITIONER = 0b00100000
  };
  buffer >> tempExt >> tempInt >> moving >> lightInt;
  std::cout << tempExt << " " << tempInt << " " << moving << " " << lightInt;

  if (lightInt == "on") {
    if (!(tumbler & INTERNAL_LIGHT)) {
      tumbler |= INTERNAL_LIGHT;
      std::cout << "Свет в помещении включен. Световая температура: ";
      switch (time) {
        case 16:
          std::cout << "4540";
          break;
        case 17:
          std::cout << "4080";
          break;
        case 18:
          std::cout << "3620";
          break;
        case 19:
          std::cout << "3160";
          break;
        case 20 ... 23:
          std::cout << "2700";
          break;
        default:
          std::cout << "5000";
          break;
      }
      std::cout << "K\n";
    }
  } else {
    if (tumbler & INTERNAL_LIGHT) {
      tumbler &= ~INTERNAL_LIGHT;
      std::cout << "Свет в помещении отключен.\n";
    }
  }

  if (moving == "yes") {
    if (!(tumbler & EXTERNAL_LIGHT)) {
      if (time >= 16 || time <= 5) {
        tumbler |= EXTERNAL_LIGHT;
        std::cout << "Внешний свет включен.\n";
      }
    } else {
      if (time < 16 && time > 5) {
        tumbler &= ~EXTERNAL_LIGHT;
        std::cout << "Внешний свет отключен.\n";
      }
    }
  } else {
    if (tumbler & EXTERNAL_LIGHT) {
      tumbler &= ~EXTERNAL_LIGHT;
      std::cout << "Внешний свет отключен.\n";
    }
  }

  if (stoi(tempInt) < 22 && !(tumbler & INTERNAL_HEATING)) {
    tumbler |= INTERNAL_HEATING;
    std::cout << "Отопление в доме включено.\n";
  }
  if (stoi(tempInt) >= 25 && (tumbler & INTERNAL_HEATING)) {
    tumbler &= ~INTERNAL_HEATING;
    std::cout << "Отопление выключено.\n";
  }
  if (stoi(tempInt) >= 30 && !(tumbler & CONDITIONER)) {
    tumbler |= CONDITIONER;
    std::cout << "Кондиционер включен.\n";
  }
  if (stoi(tempInt) <= 25 && (tumbler & CONDITIONER)) {
    tumbler &= ~CONDITIONER;
    std::cout << "Кондиционер выключен.\n";
  }

  if (stoi(tempExt) < 0 && !(tumbler & PIPES_HEATING)) {
    tumbler |= PIPES_HEATING;
    std::cout << "Отопление трубопровода включено.\n";
  }
  if (stoi(tempExt) > 5 && (tumbler & PIPES_HEATING)) {
    tumbler &= ~PIPES_HEATING;
    std::cout << "Отопление трубопровода отключено.\n";
  }

  return tumbler;
}
