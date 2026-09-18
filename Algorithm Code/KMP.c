#include <stdio.h>
#include <string.h>

void KMP(char *text, char *pattern)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int lps[m];
    int i = 0; // index for text
    int j = 0; // index for pattern

    // Preprocess the pattern to create the longest prefix suffix (lps) array
    lps[0] = 0;  // lps[0] is always 0
    int len = 0; // length of the previous longest prefix suffix
    int k = 1;

    while (k < m)
    {
        if (pattern[k] == pattern[len])
        {
            len++;
            lps[k] = len;
            k++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            } 
            else
            {
                lps[k] = 0;
                k++;
            }
        }
    }

    // Search for the pattern in the text using the lps array
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main()
{
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    KMP(text, pattern);
    return 0;
}