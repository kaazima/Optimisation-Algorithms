#include<stdio.h>
#include<math.h>
float func(float x)
{
    float res=pow(x,2)+sin(2*x)+21;
    return res;
}
int main()
{
    int k=0,temp=0,flag=0;
    float x[100],f[100],delta,a,b;
    printf("Welcome to Bounding Phase Method!!!\n\n");
    printf("Enter the initial point: ");
    do
    {
        float f1,f2,f3;
        scanf("%f",&x[0]);
        printf("Enter the increment value: ");
        scanf("%f",&delta);
        f1=func(x[0]-delta);
        f2=func(x[0]);
        f[0]=f2;
        f3=func(x[0]+delta);
        if(f1<=f2 && f2<=f3)
        {
            delta=-1*delta;
            printf("\nMinimum lies towards the left of x(0)=%.2f\nSo, △ is taken as %.2f\n",x[0],delta);
        }
        else if(f1>=f2 && f2>=f3)
            printf("\nMinimum lies towards the right of x(0)=%.2f\nSo, △ is taken as %.2f\n",x[0],delta);
        else if(f1>=f2 && f2<=f3)
        {
            a=x[0]-delta;
            b=x[0]+delta;
            flag=1;
            return 0;
        }
        else
        {
            printf("Please enter a different initial point: ");
            temp=1;
        }
    }while(temp==1);
    printf("\ni\tx(i)\tf(x(i))\n");
    printf("%d\t%.2f\t%.5f\n",k,x[k],f[k]);
    if(flag==1)
    {
        printf("\nMinimum lies in (%.2f,%.2f)\n",a,b);
        return 0;
    }
    do
    {
        x[k+1]=x[k]+pow(2,k)*delta;
        f[k+1]=func(x[k+1]);
        printf("%d\t%.2f\t%.5f\n",k+1,x[k+1],f[k+1]);
        if(f[k+1]<f[k])
            k++;
        else
        {
            if(delta>0)
                printf("\nMinimum lies in (%.2f,%.2f)\n",x[k-1],x[k+1]);
            else
                printf("\nMinimum lies in (%.2f,%.2f)\n",x[k+1],x[k-1]);
            flag=1;
        }
    }while(flag==0);
}