#include <math.h>
#include <stdio.h>

int inputInt() {
  int input;
  scanf("%d", &input);
  return input;
}

int main() {
  int a = inputInt();
  int b = inputInt();
  int c = inputInt();

  double x1 = ((-b) + sqrt(b * b - 4 * a * c)) / (2 * a);
  double x2 = ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a);

  printf("%.1f\n", x1);
  printf("%.1f", x2);
}