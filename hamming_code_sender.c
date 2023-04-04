/*
 * TOPIC  : Hamming Code Sender Side
 * AUTHOR : Mr. Rabbit
 * 
**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 100

bool is_power_of_two(int n)
{
    double temp = log2(n);
    return temp == (int) temp;
}

int main(void)
{
    char dataword[SIZE];
    printf("Dataword: ");
    scanf("%s", dataword);
    int m = strlen(dataword);

    int r = 0;
    while (pow(2, r) < m + r + 1) ++r;

    int s = m + r;
    char codeword[s + 1];
    codeword[s] = '\0';
    // initialize codeword
    for (int i = 0; i < s; ++i) codeword[i] = 'P';
    
    for (int a = m - 1, b = s - 1, i = 1; b >= 0; ++i, --b) {
        if (is_power_of_two(i)) continue;
        codeword[b] = dataword[a--];
    }

    printf("CHECK: %s\n", codeword);

    for (int i = 1; i <= r; ++i) {
        int offset = pow(2, i - 1);
        int result = 0;

        for (int j = offset; j <= s; j += offset) {
            for (int k = 0; k < offset; ++j, ++k) {
                if (codeword[s - j] == 'P') continue;
                if (s - j < 0) break;
                result ^= (codeword[s - j] - '0');
            }
        }

        codeword[s - offset] = result + '0';
    }

    printf("Codeword: %s\n", codeword);
    return 0;
}