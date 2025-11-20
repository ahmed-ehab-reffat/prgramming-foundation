#include "string.h"
#include <iostream>

using namespace std;

int main() {

  char str1[10] = {'a', 'h', 'm', 'e', 'd', '\0'};
  int length = str_len(str1);
  cout << length << endl;

  char str2[10] = {'A', 'H', 'm', 'e', 'd', '\0'};
  tolower(str2);
  cout << str2 << endl;

  char str3[10] = {'a', 'h', 'm', 'e', 'd', '\0'};
  tocapital(str3);
  cout << str3 << endl;

  char str4[10] = {'a', 'h', 'm', 'e', 'd', '\0'};
  char str5[10] = {'a', 'h', 'm', 'e', 'd', '\0'};
  int status = str_cmp(str4, str5);
  cout << status << endl;

  char str6[11] = {'a', 'h', 'm', 'e', 'd', '\0'};
  char str7[10] = {'a', 'h', 'm', 'e', 'd', '\0'};
  int isConcated = str_concat(str6, str7, sizeof(str6) / sizeof(str6[0]));
  cout << isConcated << endl;
  cout << str6 << endl;

  char str8[11] = {'a', 'h', 'm', 'e', 'd', '\0'};
  char str9[10] = {'M', 'o', 'h', 'a', 'm', 'e', 'd', '\0'};
  int isCoped = str_cpy(str8, str9, sizeof(str8) / sizeof(str8[0]));
  cout << isCoped << endl;
  cout << str8 << endl;

  return 0;
}