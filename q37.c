#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial_item {
  int coefficient;
  int power;
  struct polynomial_item* next;
} Polynomial;

void append_item(Polynomial** polynomial_result_end_ptr, int coefficient, int power, bool first_item) {
  Polynomial* new_item = malloc(sizeof(Polynomial));
  new_item->coefficient = coefficient;
  new_item->power = power;
  new_item->next = NULL;

  if (!first_item) (*polynomial_result_end_ptr)->next = new_item;
  *polynomial_result_end_ptr = new_item;
}

Polynomial* input_polynomial() {
  char trailing_whitespace;
  int coefficients[1000];
  int max_power = 0;

  Polynomial* polynomial_result;
  Polynomial* polynomial_result_end;

  while (true) {
    scanf(" %d", &coefficients[max_power]);
    trailing_whitespace = getchar();

    if (trailing_whitespace == EOF || trailing_whitespace == '\n') break;
    max_power++;
  }

  bool first_run = true;

  for (int i = max_power; i >= 0; i--) {
    append_item(&polynomial_result_end, coefficients[max_power - i], i, first_run);

    if (first_run) {
      polynomial_result = polynomial_result_end;
      first_run = false;
    }
  }

  return polynomial_result;
}

void print_polynomial(Polynomial* polynomial) {
  bool first_run = true;

  while (true) {
    if (polynomial->coefficient != 0) {
      if (!first_run && polynomial->coefficient >= 0) printf("+");

      if (polynomial->coefficient != 0) {
        if (polynomial->coefficient == -1) {
          if (polynomial->power == 0) printf("-1");
          else printf("-");
        } else if (polynomial->coefficient != 1 || polynomial->power == 0) {
          printf("%d", polynomial->coefficient);
        }
      }

      if (polynomial->power > 0) {
        printf("x");
        if (polynomial->power > 1) printf("^%d", polynomial->power);
      }
    }

    if (polynomial->next != NULL) polynomial = polynomial->next;
    else break;

    first_run = false;
  }

  printf("\n");
}

Polynomial* add(Polynomial* polynomial_1, Polynomial* polynomial_2) {
  Polynomial* polynomial_result;
  Polynomial* polynomial_result_end;

  bool first_item = true;

  while (polynomial_1 != NULL && polynomial_2 != NULL) {
    int coefficient;
    int power;

    if (polynomial_1->power == polynomial_2->power) {
      coefficient = polynomial_1->coefficient + polynomial_2->coefficient;
      power = polynomial_1->power;

      polynomial_1 = polynomial_1->next;
      polynomial_2 = polynomial_2->next;
    }

    else if (polynomial_1->power > polynomial_2->power) {
      coefficient = polynomial_1->coefficient;
      power = polynomial_1->power;

      polynomial_1 = polynomial_1->next;
    }

    else {
      coefficient = polynomial_2->coefficient;
      power = polynomial_2->power;

      polynomial_2 = polynomial_2->next;
    }

    append_item(&polynomial_result_end, coefficient, power, first_item);

    if (first_item) {
      polynomial_result = polynomial_result_end;
      first_item = false;
    }
  }

  return polynomial_result;
}

Polynomial* sub(Polynomial* polynomial_1, Polynomial* polynomial_2) {
  Polynomial* polynomial_result;
  Polynomial* polynomial_result_end;

  bool first_item = true;

  while (polynomial_1 != NULL && polynomial_2 != NULL) {
    int coefficient;
    int power;

    if (polynomial_1->power == polynomial_2->power) {
      coefficient = polynomial_1->coefficient - polynomial_2->coefficient;
      power = polynomial_1->power;

      polynomial_1 = polynomial_1->next;
      polynomial_2 = polynomial_2->next;
    }

    else if (polynomial_1->power > polynomial_2->power) {
      coefficient = polynomial_1->coefficient;
      power = polynomial_1->power;

      polynomial_1 = polynomial_1->next;
    }

    else {
      coefficient = -polynomial_2->coefficient;
      power = polynomial_2->power;

      polynomial_2 = polynomial_2->next;
    }

    append_item(&polynomial_result_end, coefficient, power, first_item);

    if (first_item) {
      polynomial_result = polynomial_result_end;
      first_item = false;
    }
  }

  return polynomial_result;
}

int main() {
  Polynomial* polynomial_1 = input_polynomial();
  Polynomial* polynomial_2 = input_polynomial();

  print_polynomial(add(polynomial_1, polynomial_2));
  print_polynomial(sub(polynomial_1, polynomial_2));
}
