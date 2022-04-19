#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define SIZE 80

bool larger_than(int number_1[SIZE], int number_2[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    // Also works if both of them == 0
    if (number_1[i] == number_2[i]) continue;
    else if (number_1[i] > number_2[i]) return true;
    else return false;
  }

  return true;
}

void input_number(int number[SIZE]) {
  char number_array[255];
  scanf(" %s", number_array);

  int number_of_prepending_0 = SIZE - strlen(number_array);

  for (int i = 0; i < number_of_prepending_0; i++) {
    number[i] = 0;
  }

  for (int i = number_of_prepending_0, j = 0; i < SIZE; i++, j++) {
    number[i] = number_array[j] - '0';
  }
}

void print_number(int* number) {
  bool no_more_leading_zero = false;

  for (int i = 0; i < SIZE; i++) {
    if (number[i] == 0 && !no_more_leading_zero) {
      continue;
    } else {
      no_more_leading_zero = true;
      printf("%d", number[i]);
    }
  }

  if (no_more_leading_zero == false) printf("0"); // number == 0
  printf("\n");
}

void addition(int number_1[SIZE], int number_2[SIZE], int result[SIZE]) {
  int carry = 0;

  for (int i = SIZE - 1; i >= 0; i--) {
    int result_for_i = number_1[i] + number_2[i] + carry;
    carry = result_for_i / 10;
    result[i] = result_for_i % 10;
  }

  result[0] = carry * 10 + result[0];
}

void subtraction(int number_1[SIZE], int number_2[SIZE], int result[SIZE]) {
  int carry = 0;
  bool number_1_larger_than_number_2 = larger_than(number_1, number_2);
  int* larger_number = number_1_larger_than_number_2 ? number_1 : number_2;
  int* smaller_number = number_1_larger_than_number_2 ? number_2 : number_1;
  int last_digit = SIZE - 1;

  for (int i = SIZE - 1; i >= 0; i--) {
    int result_for_i = larger_number[i] - smaller_number[i] - carry;
    carry = 0;

    // Borrowing
    if (result_for_i < 0) {
      result_for_i += 10;
      carry = 1;
    }

    result[i] = result_for_i;
    if (result_for_i != 0) last_digit = i;
  }

  if (!number_1_larger_than_number_2) result[last_digit] = result[last_digit] * -1;
}

void multiplication(int number_1[SIZE], int number_2[SIZE], int result[SIZE]) {
  int carry = 0;
  bool number_1_larger_than_number_2 = larger_than(number_1, number_2);
  int* larger_number = number_1_larger_than_number_2 ? number_1 : number_2;
  int* smaller_number = number_1_larger_than_number_2 ? number_2 : number_1;

  for (int i = 0; i < SIZE; i++) {
    int no_of_addition = smaller_number[i];
    if (no_of_addition == 0) continue;

    int multiplication_result[SIZE] = {0};

    // Adding the same number for no_of_addition times
    // e.g. 5 * 3 = 5 + 5 + 5
    for (int j = 0; j < no_of_addition; j++) {
      addition(larger_number, multiplication_result, multiplication_result);
    }

    // Mutipling resulted number with 10^i
    for (int k = 0; k < SIZE; k++) {
      if (k - i > 0) multiplication_result[k] = 0;
      else multiplication_result[k] = multiplication_result[k + (SIZE - 1) - i];
    }

    addition(result, multiplication_result, result);
  }
}

int main() {
  int number_1[SIZE];
  int number_2[SIZE];
  int result[SIZE] = {0};

  input_number(number_1);
  input_number(number_2);

  multiplication(number_1, number_2, result);
  print_number(result);
}
