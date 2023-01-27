/**
 *  Question:
 *  Write a C code to encode a user provided dataword 
 *  using Even and Odd Parity bit procedure.
 * 
 *  Author:
 *  Mr. Rabbit
**/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100];
    printf("Dataword: ");
    scanf("%s", s);
    int length = strlen(s);
    
    int result = 0;
    for (int i = 0; i < length; ++i)
        result = result ^ (s[i] - '0');
        
    int even_parity = result;
    int odd_parity = !result;
    
    char even_parity_codeword[length + 2];
    char odd_parity_codeword[length + 2];
    
    strcat(even_parity_codeword, s);
    strcat(odd_parity_codeword, s);
    
    even_parity_codeword[length] = '0' + even_parity;
    odd_parity_codeword[length]  = '0' + odd_parity;
    
    printf("Even parity bit: %d\n", even_parity);
    printf("Even parity codeword: %s\n\n", even_parity_codeword);
    printf("Odd parity bit: %d\n", odd_parity);
    printf("Odd parity codeword: %s\n\n", odd_parity_codeword);

    return 0;
}
