#include "consoleUtils.h"
#include "displayMenu.h"
#include "keyboardRead.h"
#include <iostream>

using namespace std;

int main() {
  enableRawMode();

  int selected = 1;
  int exitFlag = 0;
  bool inMenu = true;

  while (exitFlag != 1) {
    if (inMenu) {
      displayMenu(selected);
      int key = getKey();

      switch (key) {
      case DOWN:
      case RIGHT:
        selected = changeSelected(selected + 1);
        break;

      case UP:
      case LEFT:
        selected = changeSelected(selected - 1);
        break;

      case HOME:
        selected = 1;
        break;

      case END:
        selected = 3;
        break;

      case ENTER:
        if (selected == 1) {
          inMenu = false;
          showScreen("New");
        } else if (selected == 2) {
          inMenu = false;
          showScreen("Display");
        } else if (selected == 3) {
          exitFlag = 1; // or make the while(true) and return 0; // Exit program
        }
        break;
      }

    } else { // if not inMenu
      int key = getKey();
      if (key == ESC) {
        inMenu = true; // Back to main menu
      }
    }

    delay(50);
  }

  disableRawMode();
}
