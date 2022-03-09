#include <stdio.h>

typedef struct {
  int monthly_fee;

  float intra_network_call_rate;
  float inter_network_call_rate;
  float fixed_lines_call_rate;

  float intra_network_message_rate;
  float inter_network_message_rate;
} DataPlan;

int input_int() {
  int input;
  scanf(" %d", &input);
  return input;
}

float calculate_data_charges(
  DataPlan data_plan,
  int intra_network_call_second,
  int inter_network_call_second,
  int fixed_lines_call_second,
  int intra_network_message_number,
  int inter_network_message_number) {
  float charge =
    intra_network_call_second * data_plan.intra_network_call_rate +
    inter_network_call_second * data_plan.inter_network_call_rate +
    fixed_lines_call_second * data_plan.fixed_lines_call_rate +
    intra_network_message_number * data_plan.intra_network_message_rate +
    inter_network_message_number * data_plan.inter_network_message_rate;

  return charge > data_plan.monthly_fee ? charge : data_plan.monthly_fee;
}

int main() {
  DataPlan plan_183 = {
    .monthly_fee = 183,
    .intra_network_call_rate = 0.08,
    .inter_network_call_rate = 0.1393,
    .fixed_lines_call_rate = 0.1349,
    .intra_network_message_rate = 1.1287,
    .inter_network_message_rate = 1.4803,
  };
  DataPlan plan_383 = {
    .monthly_fee = 383,
    .intra_network_call_rate = 0.07,
    .inter_network_call_rate = 0.1304,
    .fixed_lines_call_rate = 0.1217,
    .intra_network_message_rate = 1.1127,
    .inter_network_message_rate = 1.2458,
  };
  DataPlan plan_983 = {
    .monthly_fee = 983,
    .intra_network_call_rate = 0.06,
    .inter_network_call_rate = 0.1087,
    .fixed_lines_call_rate = 0.1018,
    .intra_network_message_rate = 0.9572,
    .inter_network_message_rate = 1.1243,
  };

  int intra_network_call_second = input_int();
  int inter_network_call_second = input_int();
  int fixed_lines_call_second = input_int();
  int intra_network_message_number = input_int();
  int inter_network_message_number = input_int();

  float plan_183_charge = calculate_data_charges(
    plan_183,
    intra_network_call_second,
    inter_network_call_second,
    fixed_lines_call_second,
    intra_network_message_number,
    inter_network_message_number);
  float plan_383_charge = calculate_data_charges(
    plan_383,
    intra_network_call_second,
    inter_network_call_second,
    fixed_lines_call_second,
    intra_network_message_number,
    inter_network_message_number);
  float plan_983_charge = calculate_data_charges(
    plan_983,
    intra_network_call_second,
    inter_network_call_second,
    fixed_lines_call_second,
    intra_network_message_number,
    inter_network_message_number);

  if (plan_183_charge < plan_383_charge && plan_183_charge < plan_983_charge) {
    printf("183");
  } else if (plan_383_charge < plan_983_charge) {
    printf("383");
  } else {
    printf("983");
  }
}