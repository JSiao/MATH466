#include <stdio.h>
#include <math.h>

double factorial(int x)
{
    double k = 1;
    while (x > 1){
        k *= x;
        x--;
    }
    return k;
}

double polyCoeff(int n, int r){
    if(r<1){
        return 0;
    }
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int main(){
    //bernoulli numbers to be found
    int n=6;
    double poly[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            poly[i][n-j-1] = polyCoeff(i+1,i-j+1);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%f ",poly[i][j]);
        }
    printf("\n");
    }
    return 0;
}
