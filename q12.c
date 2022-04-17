#include <stdbool.h>
#include <stdio.h>

typedef struct {
  int numerator;
  int denominator;
} Fraction;

void input_fraction(Fraction* fraction) {
  scanf(" %d/%d", &(fraction->numerator), &(fraction->denominator));
}

char input_char() {
  char result;
  scanf(" %c", &result);
  return result;
}

int abs(int i) {
  if (i < 0) return i * -1;
  else return i;
}

int get_gcd(int a, int b) {
  for (int i = a > b ? a : b; i > 1; i--) {
    if (i % a == 0 && i % b == 0) return i;
  }

  return 1;
}

void addition(Fraction* fraction_1, Fraction* fraction_2, Fraction* fraction_result) {
  fraction_result->numerator = fraction_1->numerator * fraction_2->denominator + fraction_2->numerator * fraction_1->denominator;
  fraction_result->denominator = fraction_1->denominator * fraction_2->denominator;
}

void substraction(Fraction* fraction_1, Fraction* fraction_2, Fraction* fraction_result) {
  fraction_result->numerator = fraction_1->numerator * fraction_2->denominator - fraction_2->numerator * fraction_1->denominator;
  fraction_result->denominator = fraction_1->denominator * fraction_2->denominator;
}

void multiplication(Fraction* fraction_1, Fraction* fraction_2, Fraction* fraction_result) {
  fraction_result->numerator = fraction_1->numerator * fraction_2->numerator;
  fraction_result->denominator = fraction_1->denominator * fraction_2->denominator;
}

void division(Fraction* fraction_1, Fraction* fraction_2, Fraction* fraction_result) {
  Fraction fraction_3 = {
    .numerator = fraction_2->denominator,
    .denominator = fraction_2->numerator,
  };
  multiplication(fraction_1, &fraction_3, fraction_result);
}

void print_fraction(Fraction* fraction_result) {
  if (fraction_result->numerator == 0) {
    printf("0\n");
    return;
  }

  int gcd = get_gcd(fraction_result->numerator, fraction_result->denominator);
  fraction_result->numerator /= gcd;
  fraction_result->denominator /= gcd;

  if (fraction_result->numerator < 0 || fraction_result->denominator < 0) {
    if (!(fraction_result->numerator < 0 && fraction_result->denominator < 0)) printf("-");

    fraction_result->numerator = abs(fraction_result->numerator);
    fraction_result->denominator = abs(fraction_result->denominator);
  }

  int remainder = fraction_result->numerator % fraction_result->denominator;

  if (remainder == 0) {
    printf("%d\n", fraction_result->numerator / fraction_result->denominator);
  } else if (fraction_result->numerator > fraction_result->denominator) {
    printf("%d(%d/%d)\n", fraction_result->numerator / fraction_result->denominator, remainder, fraction_result->denominator);
  } else {
    printf("%d/%d\n", fraction_result->numerator, fraction_result->denominator);
  }
}

int main() {
  while (true) {
    Fraction fraction_1;
    Fraction fraction_2;
    Fraction fraction_result;

    input_fraction(&fraction_1);
    input_fraction(&fraction_2);
    char operation = input_char();
    char continue_input = input_char();

    if (fraction_1.denominator == 0 || fraction_2.denominator == 0) {
      printf("Error\n");
    } else {
      if (operation == '+') {
        addition(&fraction_1, &fraction_2, &fraction_result);
      } else if (operation == '-') {
        substraction(&fraction_1, &fraction_2, &fraction_result);
      } else if (operation == '*') {
        multiplication(&fraction_1, &fraction_2, &fraction_result);
      } else {
        division(&fraction_1, &fraction_2, &fraction_result);
      }

      print_fraction(&fraction_result);
    }

    if (continue_input == 'n') break;
  }
}
