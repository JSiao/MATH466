#include <stdio.h>
#include <math.h>

static double h = 0.1f;

double y_exact(double);
double f(double, double);
double euler(double, double);
double interpolate(double, double, double, double);

/*--------------------------------------------------------
 
  Runs the euler's algorithm until the next step just
  slightly above the desired t value. Then runs an
  interpolation function to approximate the y value at t
  outputs the respective values for t, approximate y,
  exact y, and the error value

--------------------------------------------------------*/

int main(int argc, char **argv)
{
    double t_vals[3] = {1.04, 1.55, 1.97};
    printf("#\tt\ty\ty_exact\terror\n");
    for (int x = 0; x < 3; x++)
    {
        double t = t_vals[x];
        double y = 0;
        double t_prev = 1.0;
        double t_next;
        for (t_next = t_prev + h; t_next <= t; t_next = t_next + h)
        {
            y=euler(t_prev, y);
            t_prev = t_next;
        }
        double approx = interpolate(t, t_prev, t_next, y);
        printf("%d\t%g\t%1.5g\t%1.5g\t%1.5g\n", x+1, t, approx, y_exact(t), fabs(y_exact(t)-approx));
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

/*--------------------------------------------------------
  y = y0 + (t-t0)*(y1-y0)/(t1-t0)

  Source: Wikipedia :)
--------------------------------------------------------*/

double interpolate(double t, double t0, double t1, double y0)
{
    return y0 + (t - t0) * (euler(t0, y0) - y0) / (t1 - t0);
}
