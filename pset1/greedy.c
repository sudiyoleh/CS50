#include <stdio.h>
#include <cs50.h>
#include <math.h>

int a = 0;
int b = 0;
int c = 0;
int d = 0;
int f = 0;
int main(void)
{
   float coin;
   do
   {
       printf("How much change is owed?\n");
       coin = get_float();
   }
       while (coin < 0);

       coin = coin * 100;
       int z = round (coin);

       a = z % 25;
       f = f + z / 25;
       b = a % 10;
       f = f + a / 10;
       c = z % 5;
       f = f + b / 5;
       d = z % 1;
       f = f + c / 1;
       printf("%d\n", f);
}
