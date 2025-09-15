#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdbool.h> 
typedef union { 
  int   int_value;
  float float_value;
  char *string_value;
} answer_t;

typedef bool check_func(char *str);
typedef answer_t convert_func(char *str);

extern char *strdup(const char *);

int read_string(char *buf, int buf_siz);
bool is_number(char *str);
int ask_question_int(char *question);
char *ask_question_string(char *question, char *buf, int buf_siz);
void print(const char *str);
void println(const char *str);

#endif