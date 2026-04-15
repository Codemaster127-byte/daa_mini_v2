#include <stdio.h>
#include <string.h>

void computeLPS(char *pat, int m, int *lps) {
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
}

void KMP(char *txt, char *pat) {
    int n = strlen(txt), m = strlen(pat);
    int lps[m];

    computeLPS(pat, m, lps);

    int i = 0, j = 0;
    int found = 0;

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++; j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        printf("No match found\n");
}

// Helper to run test
void runTest(char *txt, char *pat) {
    printf("Text: %s\n", txt);
    printf("Pattern: %s\n", pat);

    KMP(txt, pat);

    printf("-----------------------------\n");
}

int main() {

    printf("=== KMP Test Cases ===\n\n");

    // Test Case 1 (Standard)
    runTest("ABABDABACDABABCABAB", "ABABCABAB");

    // Test Case 2 (Multiple matches)
    runTest("AAAAA", "AA");

    // Test Case 3 (No match)
    runTest("ABCDE", "FG");

    // Test Case 4 (Pattern = text)
    runTest("ABC", "ABC");

    // Test Case 5 (Pattern longer than text)
    runTest("AB", "ABC");

    return 0;
}