#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef enum {
  INSERT_BEFORE,
  REPLACE
} EditType;

typedef enum {
  WORDS,
  CHARACTERS
} CountType;

typedef struct {
  char key[255];
  int count;
} CountRecord;

void edit_string(char* input_str, char* word_1, char* word_2, char* str_with_word_inserted, EditType edit_type) {
  int input_str_len = strlen(input_str);
  int word_1_len = strlen(word_1);

  str_with_word_inserted[0] = '\0';

  for (int i = 0; i < input_str_len;) {

    if (i <= input_str_len - word_1_len) {
      bool match = true;

      if (input_str[i] == word_1[0]) {
        int j;

        for (j = 0; j < word_1_len; j++) {
          if (input_str[i + j] != word_1[j]) match = false;
        }

        if (!(i + j == input_str_len || input_str[i + j] == ' ')) match = false;
      } else {
        match = false;
      }

      if (match == true) {
        strcat(str_with_word_inserted, word_2);
        if (edit_type == INSERT_BEFORE) {
          strcat(str_with_word_inserted, " ");
          strcat(str_with_word_inserted, word_1);
        }

        i += word_1_len;
        continue;
      }
    }

    char to_be_insetred[2];
    to_be_insetred[0] = input_str[i];
    to_be_insetred[1] = '\0';
    strcat(str_with_word_inserted, to_be_insetred);
    i++;
  }
}

void print_all_records(CountRecord count_records[], int* count_records_len) {
  int highest_count = 0;
  int second_highest_count = 0;

  for (int i = 0; i < *count_records_len; i++) {
    int count = count_records[i].count;

    if (count > highest_count) {
      second_highest_count = highest_count;
      highest_count = count;
    } else if (count > second_highest_count) {
      second_highest_count = count;
    }
  }

  for (int i = 0; i < *count_records_len; i++) {
    if (count_records[i].count == highest_count) {
      printf("%s: %d\n", count_records[i].key, count_records[i].count);
    }
  }

  for (int i = 0; i < *count_records_len; i++) {
    if (count_records[i].count == second_highest_count) {
      printf("%s: %d\n", count_records[i].key, count_records[i].count);
    }
  }
}

CountRecord* add_or_create_record(CountRecord count_records[], int* count_records_len, char* key) {
  for (int i = 0; i < *count_records_len; i++) {
    if (strcmp(count_records[i].key, key) == 0) {
      return &count_records[i];
    }
  }

  CountRecord count_record;
  strcpy(count_record.key, key);
  count_record.count = 0;

  count_records[*count_records_len] = count_record;
  *count_records_len += 1;

  return &count_records[*count_records_len - 1];
}

void print_count_results(char* input_str, CountType count_type) {
  CountRecord count_records[1000];
  int count_records_len = 0;
  int input_str_len = strlen(input_str);

  for (int i = 0; i < input_str_len;) {
    if (input_str[i] == ' ') {
      i++;
      continue;
    }

    int copy_length;

    if (count_type == WORDS) {
      int j;
      for (j = i; j < input_str_len; j++) {
        if (input_str[j] == ' ' || input_str[j] == '\0') break;
      }

      copy_length = j - i;
    } else {
      copy_length = 1;
    }

    char key[1000];
    strncpy(key, &input_str[i], copy_length);
    key[copy_length] = '\0';

    CountRecord* count_record_ptr = add_or_create_record(count_records, &count_records_len, key);
    count_record_ptr->count++;

    if (count_type == WORDS) i += copy_length;
    else i++;
  }

  print_all_records(count_records, &count_records_len);
}

int main() {
  char input_str[1000];
  char word_1[1000];
  char word_2[1000];

  // Can you can a can as a canner can can a can
  scanf(" %[^\n]", input_str);
  // can
  scanf(" %[^\n]", word_1);
  // ban
  scanf(" %[^\n]", word_2);

  char str_with_word_inserted[1000];

  edit_string(input_str, word_1, word_2, str_with_word_inserted, INSERT_BEFORE);
  printf("%s\n", str_with_word_inserted);

  edit_string(input_str, word_1, word_2, str_with_word_inserted, REPLACE);
  printf("%s\n", str_with_word_inserted);

  print_count_results(input_str, WORDS);

  print_count_results(input_str, CHARACTERS);
}
