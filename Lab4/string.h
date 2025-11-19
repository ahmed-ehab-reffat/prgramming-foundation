#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

int str_len(char arr[]);

int str_cmp(char str1[], char str2[]);

void tolower(char arr[]);

void tocapital(char arr[]);

int str_concat(char str1[], char str2[], int size_str1);

int str_cpy(char str1[], char str2[], int size_str1);

#endif // STRING_H_INCLUDED