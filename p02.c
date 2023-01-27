/**
 *  Question:
 *  Input a string of alphabets. Now count frequency of each 
 *  alphabet present in that string.
 * 
 *  Author:
 *  Mr. Rabbit
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    size_t length;
    const char *value;
} String;

const String *getString(char *, FILE *);
void destroy(const String *);


int main(void)
{
    const String *s = getString("Enter a string: ", stdin);
    size_t freq[26] = { 0 };
    
    for (size_t i = 0; i < s->length; ++i) {
        char offset = 'a';
        if (s->value[i] >= 'A' && s->value[i] <= 'Z')
            offset = 'A';
        freq[s->value[i] - offset]++;
    }
    
    for (int i = 0; i < 26; ++i) {
        if (freq[i] == 0) continue;
        printf("\n%c = %lu", 'A' + i, freq[i]);
    }
    
    destroy(s);
    return 0;
}


const String *getString(char *label, FILE *file)
{
    printf("%s", label);
    
    String *s = malloc(sizeof(String));
    s->size   = 1;
    s->length = 0;
    char *value = malloc((s->size + 1) * sizeof(char));
    
    int c;
    while ((c = getc(file)) != '\n' && c != EOF) {
        if (s->length == s->size) {
            s->size *= 2;
            value = realloc(
                value, 
                (s->size + 1) * sizeof(char)
            );
        }
        value[s->length++] = c;
    }
    
    value[s->size] = '\0';
    s->value = (const char *)value;
    return (const String *)s;
}


void destroy(const String *s)
{
    free((char *)s->value);
    free((String *)s);
}