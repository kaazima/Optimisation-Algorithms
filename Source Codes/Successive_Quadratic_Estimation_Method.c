#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float func(float x)
{
    float res=pow(pow(x,3)-1,3)+pow(2*x*x-5,4);
    return res;
}
int main()
{
    float x[3],f[3],Xmin,Fmin,Xbar,Fbar,a1,a2,delta,e,min;
    printf("Welcome to Successive Quadratic Estimation Method!!!\n\n");
    printf("Enter the initial point: ");
    scanf("%f",&x[0]);
    printf("Enter the increment value: ");
    scanf("%f",&delta);
    int option,n,count=0,flag;
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
    x[1]=x[0]+delta;
    f[0]=func(x[0]);
    f[1]=func(x[1]);
    if(f[0]>f[1])
        x[2]=x[1]+delta;
    else
        x[2]=x[0]-delta;
    f[2]=func(x[2]);
    do
    {
        flag=0;
        count++;
        a1=(f[1]-f[0])/(x[1]-x[0]);
        a2=(((f[2]-f[0])/(x[2]-x[0]))-a1)/(x[2]-x[1]);
        Xbar=((x[0]+x[1])/2)-(a1/(2*a2));
        Fbar=func(Xbar);
        Fmin=f[0]<f[1] ? f[0]<f[2]?f[0]:f[2] : f[1]<f[2]?f[1]:f[2];
        Xmin=Fmin==f[0] ? x[0] : Fmin==f[1]?x[1]:x[2];
        if(fabs(Fmin-Fbar)>=e && fabs(Xmin-Xbar)>=e && count<n)
        {
            flag=1;
            // Find best 3 values
            for(int i=0;i<2;i++)
                for(int j=i+1;j<3;j++)
                    if(f[i]>f[j])
                    {
                        float temp=f[i];
                        f[i]=f[j];
                        f[j]=temp;
                        temp=x[i];
                        x[i]=x[j];
                        x[j]=temp;
                    }
            if(Fbar<f[2])
            {
                f[2]=Fbar;
                x[2]=Xbar;
            }
            // Arrange those 3 values in ascending order
            for(int i=0;i<2;i++)
                for(int j=i+1;j<3;j++)
                    if(x[i]>x[j])
                    {
                        float temp=f[i];
                        f[i]=f[j];
                        f[j]=temp;
                        temp=x[i];
                        x[i]=x[j];
                        x[j]=temp;
                    }
            for(int i=0;i<3;i++)
                f[i]=func(x[i]);
        }
    }while(flag==1);
    min=Fmin<Fbar?Xmin:Xbar;
    printf("\nMinimum of the given function is at %f\n",min);
}
