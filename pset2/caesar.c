#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error more argc!\n");
        return 1;
    }

    int k = atoi(argv[1]);
    if (k < 0 || k > pow(2, 31) - 26)
    {
        printf("Error k < 0 or k > int!\n");
        return 1;
    }
    printf("plaintext: ");
    string p = get_string();
    printf("ciphertext: ");
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isalpha(p[i]))
        {
            if (isupper(p[i]))
            {
                p[i] = (p[i] + k - 'A') % 26;
                printf("%c", p[i] + 'A');
            }

            if (islower(p[i]))
            {
                p[i] = (p[i] + k - 'a') % 26;
                printf("%c", p[i] + 'a');
            }
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}
