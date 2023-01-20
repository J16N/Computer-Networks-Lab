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
    size_t rem = length % segment;
    if (rem) {
        for (size_t i = 0; i < rem; ++i) 
            result[i] = '0';
    }
    strcat(result, s);
    
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
