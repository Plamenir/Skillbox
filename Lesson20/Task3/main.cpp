#include <iostream>

bool substr(char* a, char* b) {
  for (int i = 0; *(a + i) != '\0'; ++i) {
    if (*(a + i) == *b) {
      bool isFound = true;
      for (int j = 0; *(b + j) != '\0'; ++j) {
        if (*(a + i + j) != *(b + j)) {
          isFound = false;
          break;
        }
      }
      if (isFound) return isFound;
    }
  }
  return false;
}

int main() {
  char* a = "Hello world";
  char* b = "wor";
  char* c = "banana";
  std::cout << substr(a, b) << " " << substr(a, c) << "\n";
}
