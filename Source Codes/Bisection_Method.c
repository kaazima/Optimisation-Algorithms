#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float func(float x)
{
    float res=pow(x,4)+10*pow(x,2)+x-exp(0.2*x);
    return res;
}
float differ(float x)
{
    float delta;
    if(x>0.01 || x<-0.01)
        delta=0.01*fabs(x);
    else
        delta=0.0001;
    return (func(x+delta)-func(x-delta))/(2*delta);
}
int main()
{
    float a,b,z,diff_a,diff_b,diff_z,e;
    printf("Welcome to Bisection Method!!!\n\n");
    printf("Enter the lower bound & upper bound: ");
    scanf("%f %f",&a,&b);
    int option,n,count=0;
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
    diff_a=differ(a);
    diff_b=differ(b);
    if(diff_a<0 && diff_b>0)
    {}
    else
    {
        printf("Minimum doesnot lie in the interval (%f,%f)\n",a,b);
        return 0;
    }
    printf("\nIteration\ta\tz\tb\tf'(a)\tf'(z)\tf'(b)\tNew Interval\n");
    do
    {
        count++;
        z=(a+b)/2;
        diff_z=differ(z);
        char sign_a=diff_a>0?'+':'-';
        char sign_b=diff_b>0?'+':'-';
        char sign_z=diff_z>0?'+':'-';
        printf("    %d\t\t%.4f\t%.4f\t%.4f\t%c\t%c\t%c\t",count,a,z,b,sign_a,sign_z,sign_b);
        if(diff_z>0)
        {
            b=z;
            diff_b=diff_z;
        }
        else
        {
            a=z;
            diff_a=diff_z;
        }
        printf("(%f,%f)\n",a,b);
    }while(fabs(diff_z)>e && count<n);
    printf("\nMinimum of the given function is at mid-point of (%f,%f) i.e, at %f\n",a,b,(a+b)/2);
    printf("Bisection Method is successfully executed");
}