#include "tests.h"
#include <stdio.h>
#include <string.h>


#define K_1 3
#define K_2 2
#define K_NEG_1 -1
#define K_NEG_3 -3
#define K_29 29


// See full documentation in header file
int test_cipher_non_cyclic_lower_case_positive_k() {
  char in[] = "abc";
  char out[] = "def";
  cipher(in, K_1);
  return strcmp(in, out) != 0;
}

int test_cipher_cyclic_lower_case_special_char_positive_k() {
  char in[] = "xyz!";
  char out[] = "zab!";
  cipher(in, K_2);
  return strcmp(in, out) != 0;
}

int test_cipher_non_cyclic_lower_case_special_char_negative_k() {
  char in[] = "def!";
  char out[] = "cde!";
  cipher(in, K_NEG_1);
  return strcmp(in, out) != 0;
}

int test_cipher_cyclic_lower_case_negative_k() {
  char in[] = "abc";
  char out[] = "xyz";
  cipher(in, K_NEG_3);
  return strcmp(in, out) != 0;
}

int test_cipher_cyclic_upper_case_positive_k() {
  char in[] = "XYZ";
  char out[] = "ABC";
  cipher(in, K_29);
  return strcmp(in, out) != 0;
}

int test_decipher_non_cyclic_lower_case_positive_k() {
  char in[] = "def";
  char out[] = "abc";
  decipher(in, K_1);
  return strcmp(in, out) != 0;
}

int test_decipher_cyclic_lower_case_special_char_positive_k() {
  char in[] = "zab!";
  char out[] = "xyz!";
  decipher(in, K_2);
  return strcmp(in, out) != 0;
}

int test_decipher_non_cyclic_lower_case_special_char_negative_k() {
  char in[] = "cde!";
  char out[] = "def!";
  decipher(in, K_NEG_1);
  return strcmp(in, out) != 0;
}

int test_decipher_cyclic_lower_case_negative_k() {
  char in[] = "xyz";
  char out[] = "abc";
  decipher(in, K_NEG_3);
  return strcmp(in, out) != 0;
}

int test_decipher_cyclic_upper_case_positive_k() {
  char in[] = "ABC";
  char out[] = "XYZ";
  decipher(in, K_29);
  return strcmp(in, out) != 0;
}
