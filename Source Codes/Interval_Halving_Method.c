#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float func(float x)
{
    float res=pow(x,4)-5*pow(x,3)+2*exp(x)-5*cos(3*x);
    return res;
}
int main()
{
    float a,b,e,x1,x2,xm,f1,f2,fm,len;
    printf("Welcome to Interval Halving Method!!!\n\n");
    printf("Enter the lower bound & upper bound: ");
    scanf("%f %f",&a,&b);
    int k=1,option,n=0,count=0;
    printf("Enter 1 to input 'Termination parameter', 2 to input 'No of Iterations': ");
    scanf("%d",&option);
    if(option==1)
    {
        printf("Enter the termination parameter: ");
        scanf("%f",&e);
    }
    else
    {
        printf("Enter the number of iterations: ");
        scanf("%d",&n);
        e=100000;
    }
    xm=(a+b)/2;
    printf("\nIteration\tNew Interval\n");
    do
    {
        len=b-a;
        x1=a+len/4;
        x2=b-len/4;
        f1=func(x1);
        f2=func(x2);
        fm=func(xm);
        if(f1<fm)
        {
            b=xm;
            xm=x1;
        }
        else if(f2<fm)
        {
            a=xm;
            xm=x2;
        }
        else
        {
            a=x1;
            b=x2;
        }
        len=b-a;
        count++;
        printf("%d\t\t(%.4f,%.4f)\n",k++,a,b);
    }while(fabs(len)>=e || count<n);
    printf("\nMinimum lies in the interval (%.4f,%.4f)\n",a,b);
}
