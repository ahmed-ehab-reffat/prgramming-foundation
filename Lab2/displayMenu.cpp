#include "consoleUtils.h"
#include "keyboardRead.h"

#include <string>

void displayMenu(int selected) {
  clearScreen();
  print("==== Main Menu ====", 2, 6, GREEN);

  if (selected == 1) {
    print("New", 4, 14, BLUE);
  } else {
    print("New", 4, 14, WHITE);
  }
  if (selected == 2) {
    print("Display", 6, 12, BLUE);
  } else {
    print("Display", 6, 12, WHITE);
  }
  if (selected == 3) {
    print("Exit", 8, 13, BLUE);
  } else {
    print("Exit", 8, 13, WHITE);
  }
}

void showScreen(std::string title) {
  clearScreen();
  print("==== Screen 1 ====", 2, 6, GREEN);
  print(title, 4, 12, BLUE);
  print("Press ESC to return to Main Menu", 6, 2, RED);
}

int changeSelected(int selected) {
  if (selected > 3) {
    return 1;
  } else if (selected < 1) {
    return 3;
  }
  return selected;
}

// int navigateMenu(int key, int selected) {
//   if (key == DOWN || key == RIGHT) {
//     return changeSelected(selected + 1);
//   }
//   if (key == UP || key == LEFT) {
//     return changeSelected(selected - 1);
//   }
//   return 2;
// }
