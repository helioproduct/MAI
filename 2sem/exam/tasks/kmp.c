#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool kmp(char *t, char *a)
{
    const int m = strlen(t);
    const int n = strlen(a);

    int p[m];
    p[0] = 0;

    int j = 0;
    int i = 1;

    while (i < m) 
    {
        if (t[j] == t[i]) {
            p[i] = j + 1;
            i++;
            j++;
        }
        else {
            if (j == 0) {
                p[i] = 0;
                i++;
            }
            else {
                j = p[j - 1];
            }
        }
    }

    i = 0;
    j = 0;

    while (i < n)
    {
        if (a[i] == t[j]) {
            i++;
            j++;
            if (j == m) {
                return true;
            }
        }
        else {
            if (j > 0) {
                j = p[j - 1];
            } else {
                i++;
            }
        }   
    }
    if (i == n) {
        return false;
    }
}


int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("usage: %s substring string\n", argv[0]);
        return 0;
    }

    bool result = kmp(argv[1], argv[2]);
    if (result) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    return 0;
}
