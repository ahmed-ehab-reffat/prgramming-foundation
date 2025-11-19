#include "consoleUtils.h"
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

// Enable raw mode
void enableRawMode() {
  termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag &= ~(ICANON | ECHO); // disable canonical mode & echo
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Disable raw mode (optional cleanup)
void disableRawMode() {
  termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag |= ICANON | ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// blocking getchar function
int kbhitBlock() {
  unsigned char ch = 0;
  int nread = read(STDIN_FILENO, &ch, 1);

  if (nread == 1)
    return ch;
  return 0;
}
// Non-blocking getchar function
int kbhitNonblock() {
  int old_flags = fcntl(STDIN_FILENO, F_GETFL);
  fcntl(STDIN_FILENO, F_SETFL, old_flags | O_NONBLOCK);

  unsigned char ch = 0;
  int nread = read(STDIN_FILENO, &ch, 1);

  fcntl(STDIN_FILENO, F_SETFL, old_flags);
  if (nread == 1)
    return ch;
  return 0;
}

int getKey() {
  int c = kbhitBlock();

  if (c == '\n') { // ENTER
    return '\n';
  }

  if (c == '\033') { // ESC
    delay(1);

    c = kbhitNonblock();
    if (c == '[') {
      delay(1);

      c = kbhitNonblock();
      return c;

    } else if (c == 0) {
      return '\033';
    }
  }

  return 0;
}
