#include <stdio.h>
#include <math.h>

static double alpha[11];
static double temp[11];
static int n;

double generate_alpha(int n);
void generate_b(int);

int main(int argc, char **argv)
{
    alpha[0] = 1;
    alpha[1] = -0.5;
    for (int h = 2; h < 11; h++)
    {
        generate_alpha(h);
        generate_b(h);
        printf("%d\t\t", h);
        for (int y = 0; y <= h; y++)
        {
            printf("%3.6lf\t", alpha[y]);
        }
        putchar('\n');
    }
    return 0;
}

double generate_alpha(int n)
{
    double return_val = 0;
    for (int u = 0; u < n; u++)
    {
        return_val += alpha[u] / (n-u+1);
    }
    return return_val * n;
}

void generate_b(int n)
{
    double r[n];
    for (int i = 0; i < n; i ++)
    {
        r[i] = alpha[i] * n / (n - i);
    }
    alpha[n] = generate_alpha(n);
    for (int i = 0; i < n; i ++)
    {
        alpha[i] = r[i];
    }
}
