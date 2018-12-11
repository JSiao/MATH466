#include <stdio.h>
#include <math.h>

unsigned long int factorial(unsigned long int x)
{
    unsigned long int k = 1;
    while (x>1)
    {
        k *= x;
        x--;
    }
    return k;
}

unsigned long int ncr(long int n,  long int r)
{
    if(r<1)
    {
        return 0;
    }
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int main()
{
    //bernoulli numbers to be found
    int n=30;
    double poly[n][n];
    double calcArr[n][n];
    double scaleFactor;
    //generates matrix of pascal's triangle
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            poly[i][j] = ncr(i+1,i-j+1)*1.0/(double)(i+1);
        }
    }
//  for(int i=0;i<n;i++)
//  {
//      for(int j=0;j<n;j++)
//      {
//          printf("%lf ", poly[i][j]);
//      }
//      printf("\n");
//  }
    //generates bernoulli polynomials and numbers
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            for (int k=i;k>=0;k--)
            {
                calcArr[j][k] = poly[j][k];
            }
        }
        //generates coefficients on terms of polynomial
        for(int j=i-1;j>=0;j--)
        {
            scaleFactor = calcArr[i][j]*-1;
            for(int k=0;k<n;k++)
            {
                calcArr[j][k] = calcArr[j][k]*scaleFactor;
                calcArr[i][k] = calcArr[j][k]+calcArr[i][k];
            }
        }        
        //reports bernoulli polynomials
        printf("The n=%d bernoulli polynomial is: \n",i);
        for(int j=i;j>=0;j--)
        {
            if(j>1)
            {
                printf("%lfx^%d + ",calcArr[j][j],j);
            } 
            else if(j==1)
            {
                printf("%lfx + ",calcArr[1][1]);
            } 
            else 
            {
                printf("%lf\n",calcArr[0][0]);
            }
        }
        //reports bernoulli numbers
        printf("The n=%i bernoulli number is: %lf\n",i,calcArr[0][0]);
        printf("\n");
    }
    return 0;
}
