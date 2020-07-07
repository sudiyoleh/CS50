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
        printf("Error! More argc!\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Error! Not alpha!\n");
            return 1;
        }
    }

    printf("plaintext: ");
    string codeword = get_string();
    printf("ciphertext: ");
    int j = 0;
    for (int i = 0, n = strlen(codeword); i < n; i++)
    {
        j = j % strlen(argv[1]);

        if (isalpha(codeword[i]))
        {
            if (islower(codeword[i]) && islower(argv[1][j]))
                printf("%c", (((codeword[i] - 97) + (argv[1][j] - 97)) % 26) + 97);
            else if (isupper(codeword[i]) && islower(argv[1][j]))
                printf("%c", (((codeword[i] - 65) + (argv[1][j] - 97)) % 26) + 65);
            else if (islower(codeword[i]) && isupper(argv[1][j]))
                printf("%c", (((codeword[i] - 97) + (argv[1][j] - 65)) % 26) + 97);
            else if (isupper(codeword[i]) && isupper(argv[1][j]))
                printf("%c", (((codeword[i] - 65) + (argv[1][j] - 65)) % 26) + 65);
            j++;
        }
        else
        {
            printf("%c", codeword[i]);
        }
    }
    printf("\n");
    return 0;
}
