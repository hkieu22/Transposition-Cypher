#include "transposition.h"

char *input_file(FILE *input_filename, size_t *size) {
      *size = 1;
      char x;
      int number_of_element = 0;
      char *string = malloc(1 * sizeof(char));

      while (fscanf(input_filename, "%c", &x) == 1) {
          if (*size == number_of_element) {
              *size = *size * 2;
              string = realloc(string, *size * sizeof(char));
          }
          string[number_of_element] = x;
          number_of_element++;
      }
      *size = number_of_element;

      if (*size > number_of_element) {
          string = realloc(string, number_of_element * sizeof(char));
      }
      return string;
}

char *encrypt(char *string, size_t size) {
    int a, b;
    a = 0;
    b = 0;

    if (size == 0) {
      char *empty = malloc(size * sizeof(char));
      return empty;
    }
    else if (size == 1) {
      char *one_char = malloc((size) * sizeof(char));
      one_char[0] = string[0];
      return one_char;
    }
    else {
      char *even_char = malloc((size + 1) * sizeof(char));
      char *odd_char = malloc((size + 1) * sizeof(char));

      if (size % 2 == 0) {
          for (int i = 0; i <= (size - 2); i += 2) {
              even_char[a] = string[i];
              a++;
          }

          for (int j = 1; j <= (size - 1); j += 2) {
              odd_char[b] = string[j];
              b++;
          }
      }
      else {
          for (int i = 0; i <= (size - 1); i += 2) {
              even_char[a] = string[i];
              a++;
          }

          for (int j = 1; j <= (size - 2); j += 2) {
              odd_char[b] = string[j];
              b++;
          }
      }
      strcat(even_char, odd_char);
      return even_char;
    }
}

char *decrypt(char *string, size_t size) {
    int a, b, c, d ;
    a = 0;
    b = 1;
    c = 0;
    d = 1;

    if (size == 0) {
      char *empty = malloc(size * sizeof(char));
      return empty;
    }
    else if (size == 1) {
      char *one_char = malloc((size) * sizeof(char));
      one_char[0] = string[0];
      return one_char;
    }

    else {
      char *original_string = malloc((size + 1) * sizeof(char));


      if (size % 2 == 0) {
          for (int i = 0; i <= (size / 2) - 1; i++) {
              original_string[a] = string[i];
              a += 2;
          }

          for (int j = (size / 2); j < size; j++) {
              original_string[b] = string[j];
              b += 2;
          }
      }

      else {
          for (int k = 0; k <= ((size / 2) - (1 / 2)); k++) {
              original_string[c] = string[k];
              c += 2;
        }

        for (int h = ((size / 2) + (3 / 2)); h < size; h++) {
            original_string[d] = string[h];
            d += 2;
        }
      }
      return original_string;
    }
}

void output_file(char *output_filename, char *result, size_t size) {
    FILE *fp = fopen(output_filename, "w");
    for (int i = 0; i < size; i++) {
        fputc(result[i], fp);
    }
    fclose(fp);
}
