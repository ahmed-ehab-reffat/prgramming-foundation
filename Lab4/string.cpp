int str_len(char arr[]) {
  int length = 0;
  for (int i = 0; arr[i] != '\0'; i++) {
    length++;
  }
  return length;
};

int str_cmp(char str1[], char str2[]) {
  int length1 = str_len(str1);
  int length2 = str_len(str2);
  if (length1 < length2) {
    return -1;
  }
  if (length1 > length2) {
    return 1;
  }
  for (int i = 0; str1[i] != '\0'; i++) {
    if (str1[i] < str2[i]) {
      return -1;
    }
    if (str1[i] > str2[i]) {
      return 1;
    }
  }
  return 0;
};

void tocapital(char arr[]) {
  for (int i = 0; arr[i] != '\0'; i++) {
    if (arr[i] >= 'a' && arr[i] <= 'z') {
      arr[i] = arr[i] - 32;
    }
  }
};

void tolower(char arr[]) {
  for (int i = 0; arr[i] != '\0'; i++) {
    if (arr[i] >= 'A' && arr[i] <= 'Z') {
      arr[i] = arr[i] + 32;
    }
  }
};

int str_concat(char str1[], char str2[], int size_str1) {
  int length1 = str_len(str1);
  int length2 = str_len(str2);
  int totalLength = length1 + length2 + 1;

  if (size_str1 < totalLength) {
    return 0;
  }

  int i = length1;
  int j = 0;
  while (i < totalLength) {
    str1[i] = str2[j];
    i++;
    j++;
  }
  return 1;
};

int str_cpy(char str1[], char str2[], int size_str1) {
  int length2 = str_len(str2);
  if (size_str1 < length2 + 1) {
    return 0;
  }

  for (int i = 0; i <= length2; i++) {
    str1[i] = str2[i];
  }
  return 1;
};