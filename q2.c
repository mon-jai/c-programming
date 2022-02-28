#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int no_of_batters = 5;
const int no_of_bases = 3;

int input_hit() {
  char input;
  scanf(" %c", &input);
  return input == 'H' ? 4 : atoi(&input);
}

int main() {
  // 0: the batter has not start batting yet
  // value larger than 3: the batter have already score a point
  int location_of_batters[] = {0, 0, 0, 0, 0};
  int current_batter_index = 0;
  int strikes_accrued = 0;

  for (int _ = 0; _ < no_of_batters; _++) {
    int hit = input_hit();

    if (hit != 0) {
      for (int batter = 0; batter < no_of_batters; batter++) {
        if (batter == current_batter_index || location_of_batters[batter] != 0) { location_of_batters[batter] += hit; }
      }
      current_batter_index++;
    } else {
      if (strikes_accrued != 3) {
        current_batter_index++;
        strikes_accrued++;
      } else {
        for (int batter = 0; batter < no_of_batters; batter++) { location_of_batters[batter] = 0; }
        current_batter_index = 0;
        strikes_accrued = 0;
      }
    }
  }

  for (int base = 1; base <= no_of_bases; base++) {
    bool has_batter = 0;
    for (int batter = 0; batter < no_of_batters; batter++) {
      if (location_of_batters[batter] == base) {
        has_batter = 1;
        break;
      }
    }

    printf("%d\n", has_batter);
  }
}