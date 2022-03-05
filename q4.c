#include <stdio.h>

#define PI 3.14159

float input_float() {
  float input;
  scanf("%f", &input);
  return input;
}

int main() {
  float radius = input_float();

  printf("%.3f\n", radius * radius * PI);
  printf("%.3f", 2 * radius * PI);
}
