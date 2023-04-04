/*
 * TOPIC  : Checksum Sender
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

void convert_to_binary(int size, int n, char str[size])
{
    int i = size - 1;
    
    do {
        int rem = n % 2;
        n = n / 2;
        str[i--] = '0' + rem;
    } while (i >= 0);

    str[size] = '\0';
}

int main(void)
{
    char dataword[SIZE];
    printf("Dataword: ");
    scanf("%s", dataword);
    int n = strlen(dataword);
    
    int segment = 0;
    printf("Segment Length: ");
    scanf("%d", &segment);

    char padded_dataword[SIZE];
    strcpy(padded_dataword, dataword);
    int remainder = n % segment;

    if (remainder) {
        int offset = segment - remainder;
        padded_dataword[offset] = '\0';
        for (int i = 0; i < offset; ++i) padded_dataword[i] = '0';
        strcat(padded_dataword, dataword);
        n = n + offset; // update the new length
    }

    int result = 0;
    for (int i = 0; i <= n - segment; i += segment) {
        int num = convert_to_decimal(segment, i, padded_dataword);
        result += num;
    }
    
    int bit_size = result > 0 ? log2(result) + 1 : 1;
    if (bit_size > segment) {
        int extra_bits = result >> segment;
        result = (result & ((int) pow(2, segment) - 1)) + extra_bits;
    }
    
    int checksum = result ^ ((int) pow(2, segment) - 1);
    char csum[segment + 1];
    convert_to_binary(segment, checksum, csum);
    printf("Checksum: %s\n", csum);
    
    char codeword[n + segment + 1];
    strcpy(codeword, dataword);
    strcat(codeword, csum);
    printf("Codeword: %s\n", codeword);

    return 0;
}