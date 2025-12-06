#include "consoleUtils.h"
#include "displayMenu.h"
#include "employeeData.h"
#include "keyboardRead.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {

  while (true) {
    clearScreen();
    print("==== Main Menu ====", 2, 2, GREEN);
    print("Press ESC to exit", 7, 2, RED);

    print("Enter file name: ", 4, 2, BLUE);
    gotoRowCol(4, 19);
    string fileName = "";
    if (getName(fileName) == -1) {
      clearScreen();
      return 0;
    }
    clearScreen();

    ifstream file(fileName);

    if (!file.is_open()) ;

    int size = 1024;
    char ch;
    int cursorIndex = 0;
    char * textPtr = new char[size];
    while (file.get(ch)) {
      textPtr[cursorIndex] = ch;
      cursorIndex++;
    }


    file.close();
    delay(6000);
  }

  return 0;
}
