#include <math.h>
#include <stdio.h>

int inputInt() {
  int input;
  scanf("%d", &input);
  return input;
}

int main() {
  int first_moth_working_hours = inputInt();
  int second_month_working_hours = inputInt();
  int salary_per_hour = inputInt();
  int minimum_wage = inputInt();

  int total_salary = salary_per_hour * (first_moth_working_hours + second_month_working_hours);
  float tax = total_salary * 0.08;
  float labor_insurance_premium = minimum_wage * 0.05;

  printf("%.1f\n", total_salary - tax - labor_insurance_premium);
  printf("%.1f\n", labor_insurance_premium);
  printf("%.1f", tax);
}
