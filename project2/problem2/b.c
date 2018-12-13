#include <stdio.h>
#include <math.h>

/*--------------------------------------------------------
Approximates:
 y' = 2/t * y t^2 * e^2 ;  1 <= t <= 2 ;  y(1) = 0;
Using second order Taylor's method:
 Given some stepsize h
 y_n+1=y_n+h*f(y_n,t_n)+(h^2/2)*f'(y_n,t_n)
--------------------------------------------------------*/

//to calculate, N=(a-b)/h where a and b are bounds and h is step size
#define N 10

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

//taylor's method of order 2
double taylor2(double h,double t,double y){
	return y+h*f(y,t)+(h*h)/2*fderiv(y,t);
}

//interpolation
double interpolate(double y0,double y1,double t0,double t1,double t){
	return (y0*(t1-t)+y1*(t-t0))/(t1-t0);
}

//finds values to use for interpolation
int findGPoint(double t,double h,double lBound){
	for(int p=0;p<N+1;p++){
		if(t<(lBound+h*p)){
			return p-1;
		}
	}
}

int main(){
	double Y[N];
	//values to interpolate
	double T[3]={1.04,1.55,1.97};
	//step size
	double h = 0.1;
	//initial value
	Y[0] = 0;
	//upper boundery
	double uBound=2.0;
	//lower boundery
	double lBound=1.0;
	
	int i = 0;
	int gPoint;
	double approx;
	printf("#\tt\ty\ty_exact\terror\n");
	for(double t=lBound; t<(uBound+h); t+=h){
		if(i<N){
			Y[i+1] = taylor2(h,t,Y[i]);
		}
		i++;
	}
	for(int j=0; j<3; j++){
		gPoint = findGPoint(T[j],h,lBound);
		approx = interpolate(Y[gPoint],Y[gPoint+1],lBound+(h*gPoint),lBound+(h*(gPoint+1)),T[j]);
		printf("%d\t%g\t%1.5g\t%1.5g\t%1.5g\n", j, T[j], approx, yexact(T[j]), fabs(yexact(T[j])-approx));
	}
	return 0;
}
