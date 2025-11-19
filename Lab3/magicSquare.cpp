#include "consoleUtils.h"
#include <cmath>
#include <vector>

using namespace std;

void generateMagicSquare(int squareLength) {
  // 1. Initial position: Center of the top row (0-based indexing)
  int currentSquareRow = 0;
  int currentSquareCol = (squareLength / 2);

  // Total number of elements in the square
  int totalElements = squareLength * squareLength;
  int cellWidth = to_string(totalElements).length() + 4; // For spacing

  // Calculate the terminal starting position for the square (centered display)
  int startRow = 4;
  int startCol = 5;

  // --- Set curser position ---
  int currentScreenRow = startRow + currentSquareRow;
  int currentScreenCol = startCol + currentSquareCol * cellWidth;

  // Calculate the Magic Constant (sum of each row/col/diagonal)
  long long magicSum = (long long)squareLength * (squareLength * squareLength + 1) / 2;

  // Format the number to be centered/aligned in its cell
  string numberStr = to_string(1);
  string outputStr = "[ " + numberStr + " ]";

  print(outputStr, currentScreenRow, currentScreenCol, BLUE);

  delay(200); // Delay for animation effect

  for (int i = 2; i <= totalElements; i++) {

    if ((i - 1) % squareLength == 0) {

    } else {
    }

    currentScreenRow = startRow + currentSquareRow;
    currentScreenCol = startCol + currentSquareCol * cellWidth;

    print(outputStr, currentScreenRow, currentScreenCol, BLUE);

    delay(200); // Delay for animation effect
  }
  // --- Prepare for the next number (k+1) ---
  // Move diagonally up-right (Rule 1 & 2)
  // Update the position for the next iteration
  currentSquareRow = (currentSquareRow - 1 + squareLength) % squareLength; // Wrap top (Rule 3)
  currentSquareCol = (currentSquareCol + 1) % squareLength;                // Wrap right (Rule 4)

  // --- Display Result ---
  int result_row = startRow + squareLength + 1;
  print("Magic Square Generation Complete!", result_row, startCol, GREEN);
  print("Side length (N): " + to_string(squareLength), result_row + 1, startCol, GREEN);
  print("Sum of all rows/cols/diagonals: " + to_string(magicSum), result_row + 2, startCol, GREEN);
}
