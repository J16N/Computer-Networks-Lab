/**
 *  Question:
 *  Write a C code to decode a user provided codeword using 
 *  Even and Odd Parity bit procedure. Provide the output along 
 *  with original data (good/bad).
 * 
 *  Author:
 *  Mr. Rabbit
**/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[100];
    printf("Codeword: ");
    scanf("%s", s);
    int length = strlen(s);
    
    int mode = 0;
    printf("Mode (0: Even | 1: Odd): ");
    scanf("%d", &mode);
    
    if (mode > 1 || mode < 0) {
        printf("Invalid mode.");
        return -1;
    }
    
    int parity = s[length - 1] - '0';
    
    int result = 0;
    for (int i = 0; i < length; ++i)
        result = result ^ (s[i] - '0');
        
    int expected_parity = mode ? !result : result;
    printf("%s\n", parity == expected_parity ? "Accepted" : "Rejected");

    return 0;
}
