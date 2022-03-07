#include <stdio.h>

int main() {
  char output[1000] = "";
  int room_timetable[5][9] = {0};

  for (int i = 0; i < 3; i++) {
    int course_code;
    int no_of_hours;

    scanf("%d", &course_code);
    scanf(" %d", &no_of_hours);

    for (int i = 0; i < no_of_hours; i++) {
      char weekday_char;
      char section_char;

      scanf(" %c%c", &weekday_char, &section_char);

      int weekday = weekday_char - '0';
      int section = section_char - '0';

      int *selected_section = &room_timetable[weekday - 1][section - 1];

      if (*selected_section == 0) {
        *selected_section = course_code;
      } else {
        sprintf(output, "%s%d and %d conflict on %d%d\n", output, *selected_section, course_code, weekday, section);
      }
    }
  }

  printf("%s", output);
}
