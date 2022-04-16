#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int m;
  int no_of_run;
} Profiler;

int input_binary_number() {
  int result = 0;
  for (int i = 7; i >= 0; i--) {
    char c = getchar();
    if (c == '-') return -1;
    result += (c - '0') << i;
  }
  return result;
}

void C(Profiler* profiler) {
  int m = profiler->m;

  if (m == 1 || m == 0) return;

  profiler->m = (m % 2 == 0) ? m / 2 : (m + 1) / 2;
  profiler->no_of_run += 1;

  C(profiler);
}

int R(int m) {
  Profiler profiler = {.no_of_run = 0, .m = m};

  C(&profiler);

  return profiler.no_of_run;
}

int main() {
  while (true) {
    int input = input_binary_number();

    int result = R(input);
    char result_in_binary[255];
    itoa(result, result_in_binary, 2);

    for (int i = 0; i < 4 - strlen(result_in_binary); i++) printf("0");
    printf("%s\n", result_in_binary);

    scanf(" %d", &input);
    if (input == -1) break;
    getchar();
  }
}
