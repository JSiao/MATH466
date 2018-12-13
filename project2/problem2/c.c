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

int main(){
	double h = 0.1;
	double y1 = 0;
	double y = y1;
	int stepNumber = 0;
	printf("#\tt\ty\ty_exact\terror\n");
	for(double t=1; t<2.1; t+=h){
		printf("%d\t%g\t%1.5g\t%1.5g\t%1.5g\n", stepNumber, t, y, yexact(t), fabs(yexact(t)-y));
		y = taylor4(h,t,y);
		stepNumber++;
	}
	return 0;
}
