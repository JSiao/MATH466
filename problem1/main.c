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
    if(n<r){
        return 0;
    }
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int main(){
    //bernoulli numbers to be found
    int n=4;
    double poly[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            poly[i][j] = polyCoeff(i+1,j+1);
            printf("%f ",poly[i][j]);
        }
        printf("\n");
    }
    return 0;
}
