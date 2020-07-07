#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        printf("height:\n");
        n = get_int();
    }
    while (n <0 || n >= 24);

    for (int a = 2; a <= n + 1; a++)
    {
        for (int space = a; space <= n; space++)
        {
            printf(" ");
        }

        for (int hash = 1; hash <= a; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
