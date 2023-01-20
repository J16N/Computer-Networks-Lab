/*
 *  Question:
 *  Input a string of 0 and 1.
 *    a. Divide it into segments of equal length.
 *    b. If the string length is not an exact multiple of 
 *       segment length then use left padding with 0s.
 *    c. Now count number of 1’s present in each segment.
 * 
 *  Author:
 *  Mr. Rabbit
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

void divide(size_t, size_t, size_t, char [], char []);


int main(void)
{
    char s[100];
    printf("Enter String: ");
    scanf("%s", s);
    size_t length = strlen(s);
    
    size_t segment = 0;
    printf("Enter segment size: ");
    scanf("%lu", &segment);
    
    size_t segments = ceil((double)length / segment);
    size_t size = segment * segments + 1;
    char result[size + 1];
    size_t frequency[segments];
    
    divide(1, segment, length, s, result);
    
    for (size_t i = 0; i < segments; ++i) {
        printf("\nSegment-%lu: ", i + 1);
        for (size_t j = i * segment; j < (i + 1) * segment; ++j) {
            printf("%c", result[j]);
            if (result[j] == '1') frequency[i]++;
        }
    }
    
    printf("\n\nFrequency: ");
    for (size_t i = 0; i < segments; ++i) {
        printf("\nSegment-%lu: %lu", i + 1, frequency[i]);
    }
    
    return 0;
}


void divide(size_t i, size_t segment, 
            size_t len, char str[], char result[])
{
    if (i > len) return;
    
    divide(i + segment, segment, len, str, result);
    
    int start = i - (len % segment);
    int end = start + segment;
    
    for (int j = start; j < end; ++j, ++i) {
        result[i - 1] = j > 0 ? str[j - 1] : '0';
    }
}
