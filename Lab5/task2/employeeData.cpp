#include "employeeData.h"
#include "consoleUtils.h"
#include <iostream>

using namespace std;

employee employees[MAX_EMPLOYEES];
int count = 0;

void createEmployee() {
  clearScreen();
  print("==== New Empoyee ====", 2, 6, GREEN);
  if (count == MAX_EMPLOYEES) {
    print("You reached the maximum limit of employees", 4, 2, RED);
    print("You cant add another employee", 5, 2, RED);
    print("Press ESC to return to Main Menu", 7, 2, RED);
  } else {
    employee emp;

    emp.id = count + 1;
    print("First Name:", 4, 10, BLUE);
    gotoRowCol(4, 22);
    cin >> emp.firstName;
    print("Last Name:", 5, 10, BLUE);
    gotoRowCol(5, 22);
    cin >> emp.lastName;
    print("Age:", 6, 10, BLUE);
    gotoRowCol(6, 22);
    cin >> emp.age;
    employees[count] = emp;
    count++;
    print("Employee added sucssefully", 8, 2, GREEN);
    print("Press ESC to return to Main Menu", 9, 2, RED);
  }
};

void displayEmployees() {
  clearScreen();
  print("==== Employees ====", 2, 6, GREEN);

  for (int i = 0; i < count; i++) {
    print("ID: " + to_string(employees[i].id) + "   Name: " +
              employees[i].firstName + " " +
              employees[i].lastName + "   Age: " +
              to_string(employees[i].age),
          i + 4, 3, BLUE);
  }
  setColor(RED);
  cout << "\n Press ESC to return to Main Menu \n";
  resetColor();
};