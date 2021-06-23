#include<stdio.h>
#include<math.h>
float func(float x)
{
    float res=pow(x,4)+10*x+12-exp(0.2*x);
    return res;
}
int main()
{
    float a,b,x1,x2,x3,delta_x,p,q;
    int n,flag=0,i=1,option,acc;
    printf("Welcome to Exhaustive Search algorithm!!!\n\n");
    printf("Enter the lower bound & upper bound: ");
    scanf("%f %f",&a,&b);
    printf("Enter 1 to input 'accuracy' and 2 to input 'number of sub-intervals: ");
    scanf("%d",&option);
    if(option==1)
    {
        printf("Enter the decimal accuracy: ");
        scanf("%d",&acc);
        n=2*(b-a)*pow(10,acc);
    }
    else
    {
        printf("Enter the number of sub-intervals: ");
        scanf("%d",&n);
    }
    delta_x=(b-a)/n;
    x1=a;
    x2=x1+delta_x;
    x3=x2+delta_x;
    while(x3<=b)
    {
        float f1,f2,f3;
        f1=func(x1);
        f2=func(x2);
        f3=func(x3);
        if(f2<=f1 && f2<=f3)
        {
            flag=1;
            p=x1;
            q=x3;
        }
        if(flag==1)
            break;
        x1=x2;
        x2=x3;
        x3=x2+delta_x;
    }
    if(flag==1)
        printf("\nMinimum lies in the interval (%f,%f)\n",p,q);
    else
        printf("\nNo minimum exists in (%f,%f) or a boundary point is the minimum point\n",a,b);
}
