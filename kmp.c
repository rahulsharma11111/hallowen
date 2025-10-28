#include <stdio.h>
#include <string.h>
#include <conio.h>

void prefixSuffixArray(char *pat, int M, int *pps) {
    int length;      // declare all variables at the top
    int i;

    length = 0;      // length of the previous longest prefix suffix
    pps[0] = 0;      // first value is always 0
    i = 1;

    while (i < M) {
        if (pat[i] == pat[length]) {
            length++;
            pps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = pps[length - 1];
            } else {
                pps[i] = 0;
                i++;
            }
        }
    }
}

void KMPAlgorithm(char *text, char *pattern) {
    int M, N;
    int pps[100];     // fixed size array for Turbo C++
    int i, j;

    M = strlen(pattern);
    N = strlen(text);

    prefixSuffixArray(pattern, M, pps);

    i = 0; // index for text[]
    j = 0; // index for pattern[]

    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = pps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = pps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    char text[] = "xyztrwqxyzfg";
    char pattern[] = "xyz";

    clrscr(); // Clear screen

    printf("The pattern is found in the text at the following index:\n");
    KMPAlgorithm(text, pattern);

    getch(); // Wait for key press
    return 0;
}
