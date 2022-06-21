#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
  int input_str_len = strlen(input_str); // STUDY
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
    strcat(str_with_word_inserted, to_be_insetred); // STUDY
    i++;
  }
}

int compare_count_records(const void* s1, const void* s2) {
  CountRecord* record_1_ptr = (CountRecord*)s1;
  CountRecord* record_2_ptr = (CountRecord*)s2;

  if (record_1_ptr->count != record_2_ptr->count)
    return record_2_ptr->count - record_1_ptr->count;
  else
    return strcmp(record_1_ptr->key, record_2_ptr->key); // STUDY
}

void print_all_records(CountRecord count_records[], int* count_records_len) {
  int highest_count = 0;
  int second_highest_count = 0;

  qsort(count_records, *count_records_len, sizeof(CountRecord), compare_count_records); // STUDY

  for (int i = 0; i < 2; i++) {
    printf("%s : %d\n", count_records[i].key, count_records[i].count);
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

void count_and_print(char* input_str, CountType count_type) {
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

  scanf(" %[^\n]", input_str);
  scanf(" %[^\n]", word_1);
  scanf(" %[^\n]", word_2);

  char str_with_word_inserted[1000];

  edit_string(input_str, word_1, word_2, str_with_word_inserted, INSERT_BEFORE);
  printf("%s\n", str_with_word_inserted);

  edit_string(input_str, word_1, word_2, str_with_word_inserted, REPLACE);
  printf("%s\n", str_with_word_inserted);

  count_and_print(input_str, WORDS);

  count_and_print(input_str, CHARACTERS);
}
