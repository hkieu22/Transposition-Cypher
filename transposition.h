#ifndef TRANSPOSITION
#define TRANSPOSITION

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* Parameters:
*     input_filename - pointer to the file that contains input file or standard
*     input
*     size - pointer to the size of the input file or standard input
*
* Return value:
*     Return the pointer to the input file
*/
char *input_file(FILE *input_filename, size_t *size);

/*
* Encrypt the content from an input file or standard input
*
* Parameters:
*     string - pointer to the string to be encrypted
*     size - the size of the string
*
* Return value:
*     Return the encrpyted string
*/
char *encrypt(char *string, size_t size);

/*
* Decrypt the content from an input file or standard input
*
* Parameters:
*     string - pointer to the string to be decrypted
*     size - the size of the string
*
* Return value:
*     Return the decrpyted string
*/
char *decrypt(char *string, size_t size);

/*
* Print the result to the output file if user provide
*
* Parameters:
*     output_filename - pointer to the file that user want to put the output in
*     result - pointer to the encrypted string or decrypted string
*     size - the size of the result string
*
* Return value:
*     Return the decrpyted string
*/
void output_file(char *output_filename, char *result, size_t size);

#endif
