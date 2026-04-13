//Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.
#include <stdio.h>
#include <string.h>

char firstRepeatedChar(const char* s) {
    int seen[26] = {0};  // track lowercase letters

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        if (seen[idx]) {
            return s[i];  // found the first repeated character
        }
        seen[idx] = 1;
    }
    return '\0';  // no repeated character
}

int main() {
    char s[] = "abca";
    char ans = firstRepeatedChar(s);

    if (ans != '\0')
        printf("First repeated character: %c\n", ans);
    else
        printf("No repeated character found\n");

    return 0;
}