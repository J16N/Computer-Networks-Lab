/*
 * TOPIC  : Checksum Receiver
 * AUTHOR : Mr. Rabbit
 * 
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 100

int convert_to_decimal(int size, int start, char str[size])
{
    int result = 0;

    for (int i = start, pos = size - 1; i < start + size; ++i, --pos) {
        int bit = str[i] - '0';
        result += (bit * pow(2, pos));
    }

    return result;
}

int main(void)
{
    char codeword[SIZE];
    printf("Codeword: ");
    scanf("%s", codeword);
    int n = strlen(codeword);
    
    int segment = 0;
    printf("Segment Length: ");
    scanf("%d", &segment);

    char padded_codeword[SIZE];
    strcpy(padded_codeword, codeword);
    int remainder = n % segment;

    if (remainder) {
        int offset = segment - remainder;
        padded_codeword[offset] = '\0';
        for (int i = 0; i < offset; ++i) padded_codeword[i] = '0';
        strcat(padded_codeword, codeword);
        n = n + offset; // update the new length
    }

    int result = 0;
    for (int i = 0; i <= n - segment; i += segment) {
        int num = convert_to_decimal(segment, i, padded_codeword);
        result += num;
    }
    
    int bit_size = result > 0 ? log2(result) + 1 : 1;
    if (bit_size > segment) {
        int extra_bits = result >> segment;
        result = (result & ((int) pow(2, segment) - 1)) + extra_bits;
    }
    
    result = result ^ ((int) pow(2, segment) - 1);
    if (result) {
      printf("Data received: NOT OK!\n");
      return -1;
    }
    n = strlen(codeword);
    codeword[n - segment] = '\0';
    printf("Data received: OK!\n");
    printf("Dataword: %s\n", codeword);

    return 0;
}