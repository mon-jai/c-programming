#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int to_grey_code(int i) {
  return i ^ (i >> 1);
}

int main() {
  char results[255][255];
  int no_of_result = 0;

  while (1) {
    int no_of_bit;
    int number;
    scanf(" %d %d", &no_of_bit, &number);

    int grey_code_value = to_grey_code(number);
    char grey_code[255];

    itoa(grey_code_value, grey_code, 2);
    for (int i = 0; i < no_of_bit - strlen(grey_code); i++) {
      results[no_of_result][i] = '0';
    }
    strcat(results[no_of_result], grey_code);
    no_of_result++;

    int action;
    scanf(" %d", &action);
    if (action == -1) break;
  }

  for (int i = 0; i < no_of_result; i++) {
    printf("%s\n", results[i]);
  }
}
