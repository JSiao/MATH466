#include <stdio.h>
#include <math.h>

/*--------------------------------------------------------
Approximates:
 y' = 2/t * y t^2 * e^2 ;  1 <= t <= 2 ;  y(1) = 0;
Using fourth order Taylor's method:
 Given some stepsize h
 y_n+1=y_n+h*f(y_n,t_n)+(h^2/2)*f'(y_n,t_n)+(h^3/6)*f''(y_n,t_n)+(h^4/24)*f'''(y_n,t_n)
--------------------------------------------------------*/

//exact solution
double yexact(double t){
    return t*t*(exp(t)-exp(1));
}

//ODE to be solved
double f(double y,double t){
    return (2/t)*y+t*t*exp(t);
}

//derivative of ODE wrt t
double fderiv(double y, double t){
    return 2*y/(t*t)+4*t*exp(t)+t*t*exp(t);
}

double fderiv2(double y, double t){
    return 6*exp(t)+6*t*exp(t)+t*t*exp(t);
}

double fderiv3(double y, double t){
    return 12*exp(t)+8*t*exp(t)+t*t*exp(t);
}

//taylor's method of order 4
double taylor4(double h,double t,double y){
    return y+h*f(y,t)+(h*h)/2*fderiv(y,t)+(h*h*h)/6*fderiv2(y,t)+(h*h*h*h)/24*fderiv3(y,t);
}

double cubic_hermite(double x, double x0, double x1, double y0, double y1){
    double h = x1 - x0;
    return (1 + 2 * (x-x0) / (h)) * pow((x1 - x)/(h), 2) * y0 + (x - x0)*pow((x1-x)/h, 2)*fderiv(y0, x0) + (1+2*(x1-x)/h) * pow((x-x0)/h,2)*y1 + (x-x1) * pow((x-x0)/h, 2) * fderiv(y1, x1);
}

int main(){
    double check[3] = {1.04, 1.55, 1.97};
    printf("t\ty\ty_exact\terror\n");
    for (int i = 0; i < 3; i++)
    {
        double stop = check[i];
        double h = 0.1;
        double y0 = 0;
        double y = y0;
        double t = 1;
        for(; t<stop; t+=h){
            y0 = y;
            y = taylor4(h,t,y);
        }
        y = cubic_hermite(stop, t-h, t, y0, y);
        printf("%g\t%1.5g\t%1.5g\t%1.5g\n", stop, y, yexact(stop), fabs(yexact(stop)-y));
    }
    return 0;
}
