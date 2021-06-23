#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float func(float x)
{
    float res=pow(x,4)-7*pow(x,3)+2*pow(x,2)+3*x+3;
    return res;
}
float differ1(float x)
{
    float delta=x>0.01 ? 0.01*fabs(x) : x<-0.01?0.01*fabs(x):0.0001;
    return (func(x+delta)-func(x-delta))/(2*delta);
}
float differ2(float x)
{
    float delta=x>0.01 ? 0.01*fabs(x) : x<-0.01?0.01*fabs(x):0.0001;
    return (func(x+delta)-2*func(x)+func(x-delta))/pow(delta,2);
}
int main()
{
    float x[50],e,diff1,min;
    printf("Welcome to Newton Raphson Method!!!\n\n");
    printf("Enter the initial point: ");
    scanf("%f",&x[0]);
    int option,n,count=0,k=0;
    printf("Enter 1 to input 'Termination parameter', 2 to input 'No of Iterations': ");
    scanf("%d",&option);
    if(option==1)
    {
        printf("Enter the termination parameter: ");
        scanf("%f",&e);
        n=1000;
    }
    else
    {
        printf("Enter the number of iterations: ");
        scanf("%d",&n);
        e=-1;
    }
    diff1=differ1(x[k]);
    do
    {
        count++;
        x[k+1]=x[k]-(diff1/differ2(x[k]));
        k++;
        diff1=differ1(x[k]);
        min=x[k];
    }while(fabs(diff1)>e && count<n);
    printf("\nMinimum of the given function lies at %f\n",min);
}
