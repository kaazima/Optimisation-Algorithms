#include<stdio.h>
#include<math.h>
float func(float x)
{
    float res=2+pow(x-1,2)-cos(pow(x,3));
    return res;
}
float new_func(float w,float a,float b)
{
    return func((b-a)*w+a);
}
int main()
{
    float a,b,len,aw=0,bw=1,e;
    printf("Welcome to Golden Section Search Method!!!\n\n");
    printf("Enter the lower bound & upper bound: ");
    scanf("%f %f",&a,&b);
    int option,n,count=0;
    printf("Enter 1 to input 'Length of the final interval', 2 to input 'No of Iterations', 3 to enter 'Desired accuracy': ");
    scanf("%d",&option);
    if(option==1)
    {
        printf("Enter the maximum length of the final interval: ");
        scanf("%f",&len);
        for(int i=1;i<100;i++)
            if((pow(0.618,i)*(b-a))<len)
            {
                n=i;
                break;
            }
    }
    else if(option==2)
    {
        printf("Enter the number of iterations: ");
        scanf("%d",&n);
    }
    else
    {
        printf("Enter the desired accuracy: ");
        scanf("%f",&e);
        n=floor((log(e/(b-a)))/(log(0.618)));
    }
    printf("\nNo\t(aw,bw)\t\t\tw1\tw2\tf1\tf2\tNew Interval\n");
    while(count<n)
    {
        count++;
        float w1,w2,f1,f2,Lw=bw-aw;
        w1=aw+0.618*Lw;
        w2=bw-0.618*Lw;
        f1=new_func(w1,a,b);
        f2=new_func(w2,a,b);
        printf("%d\t(%f,%f)\t%.4f\t%.4f\t%.4f\t%.4f\t",count,aw,bw,w1,w2,f1,f2);
        if(f1<f2)
            aw=w2;
        else
            bw=w1;
        printf("(%f,%f)\n",aw,bw);
    }
    float final_a=(b-a)*aw+a;
    float final_b=(b-a)*bw+a;
    printf("\nMinimum lies in the interval (%f,%f)\n",final_a,final_b);
}
