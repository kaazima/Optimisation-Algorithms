#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long double func(long double x)
{
    long double res=sin(x)+4*x*x;
    return res;
}
int main()
{
    long double a,b,len,lk,x1,x2,f1,f2;
    printf("Welcome to Fibonacci Search Method!!!\n\n");
    printf("Enter the lower bound & upper bound: ");
    scanf("%Lf %Lf",&a,&b);
    int option,n,m,k=1,count=1;
    printf("Enter 1 to input 'No of function evaluations', 2 to input 'No of Iterations': ");
    scanf("%d",&option);
    if(option==1)
    {
        printf("Enter the No of function evaluations: ");
        scanf("%d",&m);
    }
    else
    {
        printf("Enter the number of iterations: ");
        scanf("%d",&n);
        m=n+1;
    }
    len=b-a;
    long long int f[m+2];
    f[0]=f[1]=1;
    for(long long int i=2;i<m+2;i++)
        f[i]=f[i-1]+f[i-2];
    while(k!=m)
    {
        k++;
        lk=((long double)(f[m-k+1])/f[m+1])*len;
        x1=a+lk;
        x2=b-lk;
        f1=func(x1);
        f2=func(x2);
        if(f1<f2)
            b=x2;
        else if(f1>f2)
            a=x1;
        else
        {
            a=x1;
            b=x2;
        }
    }
    printf("\nMinimum lies in the interval (%.15Lf,%.15Lf)\n",a,b);
}
