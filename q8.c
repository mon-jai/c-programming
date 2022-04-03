#include <stdio.h>

int input_int() {
  int result;
  scanf("%d", &result);
  return result;
}

int main() {
  int shape = input_int();
  int no_of_rows = input_int();

  for (int i = 1; i <= no_of_rows; i++) {
    int no_of_star = i <= no_of_rows / 2 + 1 ? i : no_of_rows - i + 1;

    if (shape == 1) {
      for (int j = 0; j < no_of_star; j++) { printf("*"); }
    } else if (shape == 2) {
      for (int j = 0; j < no_of_rows / 2 + 1 - no_of_star; j++) { printf("."); }
      for (int j = 0; j < no_of_star; j++) { printf("*"); }
    } else {
      for (int j = 0; j < no_of_rows / 2 + 1 - no_of_star; j++) { printf("."); }
      for (int j = 0; j < no_of_star * 2 - 1; j++) { printf("*"); }
    }

    printf("\n");
  }
}
