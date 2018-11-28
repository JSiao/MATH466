#include <stdio.h>
#include <math.h>

static double alpha[11];
static int n;

double generate_alphas(int n);
double b_(int, double);

int main(int argc, char **argv)
{
    alpha[0] = 1;
    alpha[1] = -0.5;
    for (int h = 0; h < 11; h++)
    {
        generate_alphas(h);
        printf("%d\t\t", h);
        for (int y = 0; y <= h; y++)
        {
            printf("%3.6lf\t", alpha[y]);
        }
        putchar('\n');
    }
    return 0;
}

double generate_alphas(int n)
{
    for (int u = 0; u <= n; u++)
    {
        alpha[u] = (1.0/(u+2)) + (1.0/(u+1));
    }
}

double b_(int n, double x)
{
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        total += (alpha[i]/(i+2) + (alpha[i] * pow(x, i))/(i+1));
    }
    return total;
}
