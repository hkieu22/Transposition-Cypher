#include <stdio.h>
#include <string.h>
#include "transposition.h"

int main(int argc, char **argv) {
    FILE *input_file1;
    size_t size;

    if (argc != 2 && argc != 4 && argc != 6) {
      printf("Incorrect command1\n");
      return 3;
    }
    if (argc > 2) {
      if (strcmp(argv[2], "-i") == 0) {
        input_file1 = fopen(argv[3], "r");
        if (input_file1 == NULL) {
          printf("Error opening %s\n", argv[1]);
          return 2;
        }
      }
      else if (strcmp(argv[2], "-o") == 0) {
        input_file1 = stdin;
      }
      else {
        printf("Incorrect command\n");
        return 5;
      }
    }
    else {
      input_file1 = stdin;
    }

    char *input = input_file(input_file1, &size);

    if (strcmp(argv[1], "-e") == 0) {

      char *encrypted = encrypt(input, size);

      if (argc == 4) {
        if (strcmp(argv[2], "-o") == 0) {
          output_file(argv[3], encrypted, size);
        }
        else {
          for (int i = 0; i < size; i++) {
            printf("%c", encrypted[i]);
          }
        }
      }

      else if (argc == 6) {
        output_file(argv[5], encrypted, size);
      }
      else {
        for (int i = 0; i < size; i++) {
          printf("%c", encrypted[i]);
        }
      }
    }

    else if (strcmp(argv[1], "-d") == 0) {
      char *decrypted = decrypt(input, size);
      if (argc == 4) {
        if (strcmp(argv[2], "-o") == 0) {
          output_file(argv[3], decrypted, size);
        }
        else {
          for (int i = 0; i < size; i++) {
            printf("%c", decrypted[i]);
          }
        }
      }

      else if (argc == 6) {
        output_file(argv[5], decrypted, size);
      }
      else {
        for (int i = 0; i < size; i++) {
          printf("%c", decrypted[i]);
        }
      }
    }

    else {
      printf("Incorrect command\n");
      return 4;
    }
    return 0;
}
