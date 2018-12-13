#include <stdio.h>
#include <math.h>

static double h = 0.1f;

double y_exact(double);
double f(double, double);
double euler(double, double);

/*--------------------------------------------------------

  Approximates :
  y' = 2/t * y t^2 * e^2 ;  1 <= t <= 2 ;  y(1) = 0;

  Runs Euler's method of:

  y = y0 + h * f(t0, y0)

--------------------------------------------------------*/

int main(int argc, char **argv)
{

    double y = 0;
    double t_prev = 1.0;
    double t_next;
    printf("t\ty\ty_exact\terror\n");
    for (double t_next = t_prev + h; t_prev-2 <= 1e-7; t_next = t_next + h)
    {
        printf("%g\t%.5g\t%.5g\t%.5g\n", t_prev, y, y_exact(t_prev), fabs(y-y_exact(t_prev)));
        y=euler(t_prev, y);
        t_prev = t_next;
    }
    return 0;
}

//--------------------------------------------------------

double y_exact(double t)
{
    return t*t * (exp(t) - exp(1));
}

double f(double t, double y)
{
    return 2*y/t + t*t * exp(t);
}

double euler(double t, double y)
{
    return y + h * f(t,y);
}
