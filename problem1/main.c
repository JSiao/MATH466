#include <stdio.h>
#include <math.h>

unsigned long factorial(unsigned long);
unsigned long ncr(unsigned long, unsigned long);

int main(int argc, char **argv)
{
    printf("Kaixo Mundo\n");
    return 0;
}

unsigned long factorial(unsigned long x)
{
    int k = 1;
    while (x < 1)
    {
        k *= x;
        x--;
    }
    return k;
}

unsigned long ncr(unsigned long n, unsigned long r)
{
    return factorial(n) / (factorial(r) * factorial(n-r));
}
