#include <stdio.h>
#include <math.h>

#define N 3

double x[N] =  { /* Insert Values Here */ };
double f[N] =  { /* Insert Values Here */ };
double df[N] = { /* Insert Values Here */ };

double Q[2*N+1][2*N+1];
double z[2*N+1];

void hermite()
{
    for(int i = 0; i <= N; i++)
    {
        z[2*i+1]    = z[2*i]    =  x[i];
        Q[2*i+1][0] = Q[2*i][0] =  f[i];
        Q[2*i+1][1]             = df[i];
        if (i)
        {
            Q[2*i][1] = (Q[2*1][0] - Q[2*i-1][0])/(z[2*i]-z[2*i-1]);
        }
    }
    for (int i = 2; i <= 2*N+1; i++)
    {
        for(int j = 2; j <= i; j++)
        {
            Q[i][j] = (Q[i][j-1] - Q[i-1][j-1])/(z[i] - z[i-j]);
        }
    }
}

int main()
{
    hermite();
    for (int x = 0; x <= 2*N+1; x++)
    {
        printf("Q[%d][%d] = %g\n", x, x, Q[x][x]);
    }
    return 0;
}

