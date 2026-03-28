#include "cipher.h"
#include "tests.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define ARGC_ERR "The program receives 1 or 4 arguments only.\n"
#define TEST_ERR "Usage: cipher test\n"
#define COMMAND_ERR "The given command is invalid.\n"
#define K_ERR "The given shift value is invalid.\n"
#define FILE_ERR "The given file is invalid.\n"
#define COMMAND_ARG 1
#define SHIFT_VAL_ARG 2
#define INPUT_ARG 3
#define OUTPUT_ARG 4

int is_integer (char *str)
{
    if (!*str) return 0;
    if (*str=='+' || *str=='-') str++;
    if (!*str) return 0;
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

int test_result()
{
    int result = 0;
    result += test_cipher_non_cyclic_lower_case_positive_k ();
    result += test_cipher_cyclic_lower_case_special_char_positive_k ();
    result += test_cipher_non_cyclic_lower_case_special_char_negative_k ();
    result += test_cipher_cyclic_lower_case_negative_k ();
    result += test_cipher_cyclic_upper_case_positive_k ();
    result += test_decipher_non_cyclic_lower_case_positive_k ();
    result += test_decipher_cyclic_lower_case_special_char_positive_k ();
    result += test_decipher_non_cyclic_lower_case_special_char_negative_k ();
    result += test_decipher_cyclic_lower_case_negative_k ();
    result += test_decipher_cyclic_upper_case_positive_k ();

    return result;
}



int run_test(char* argstring[])
{
    if (strcmp(argstring[COMMAND_ARG], "test"))
    {
        fprintf(stderr, TEST_ERR);
        return 1;
    }
    if (test_result() != 0)
    {
        return 1;
    }
    return 0;
}

int run_cipher(FILE* input_file, FILE* output_file, int shift_val)
{
    char str[1024] = "\0";
    while (fgets(str, 1024, input_file) != NULL)
    {
        cipher(str, shift_val);
        fprintf(output_file, "%s", str);
    }
    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}

int run_decipher(FILE* input_file, FILE* output_file, int shift_val)
{
    char str[1024] = "\0";
    while (fgets(str, 1024, input_file) != NULL)
    {
        decipher(str, shift_val);
        fprintf(output_file, "%s", str);
    }
    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}

int run_cipher_decipher(char* argstring[])
{
    if (strcmp(argstring[COMMAND_ARG], "cipher") != 0 && strcmp(argstring[COMMAND_ARG], "decipher") != 0)
    {
        fprintf(stderr, COMMAND_ERR);
        return EXIT_FAILURE;
    }

    if (!is_integer(argstring[SHIFT_VAL_ARG]))
    {
        fprintf(stderr, K_ERR);
        return EXIT_FAILURE;
    }
    FILE *input_file = fopen(argstring[INPUT_ARG], "r");
    FILE *output_file = fopen(argstring[OUTPUT_ARG], "w");
    if (input_file == NULL)
    {
        fprintf(stderr, FILE_ERR);
        return EXIT_FAILURE;
    }
    if (output_file == NULL)
    {
        fprintf(stderr, FILE_ERR);
        fclose(input_file);
        return EXIT_FAILURE;
    }
    char remain[1] = "";
    char *ptr = remain;
    int shift_val = strtol(argstring[SHIFT_VAL_ARG], &ptr, 10);

    if (!strcmp(argstring[COMMAND_ARG],"cipher"))
    {
        return run_cipher(input_file, output_file,shift_val);
    }
    if (!strcmp(argstring[COMMAND_ARG],"decipher"))
    {
        return run_decipher(input_file, output_file, shift_val);
    }
    return EXIT_FAILURE;
}

int main (int argc, char *argv[])
{
    if (argc != 2 && argc != 5)
    {
        fprintf(stderr, ARGC_ERR);
        return EXIT_FAILURE;
    }
    if (argc == 2)
    {
        return run_test(argv);
    }

    return run_cipher_decipher(argv);
}


