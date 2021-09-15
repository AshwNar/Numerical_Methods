#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
float  *coffic_cal(int n,float a,float b)
{
    int j,k,i;    // number of point n
    //float a =1 ,b = 6;   // range of x
    float x[n+1],c[n+1];   // array  for x value and coefficient value
    float del_x,multy=1,diff=1,sum,p;

    del_x = (b-a)/n;   //step size
    p = a;

   for(i =0;i<=n;i++ )
    {
        x[i]=p;
        p +=del_x;

    }
     cout<<"values of coefficients of "<<n<<"th order polynomial are"<<endl;
     std::ofstream file("coefficients_value.txt",std::ios::app);     // writing result in text file
     file<<"values of coefficients of "<<n<<"th order polynomial are"<<endl;
    for(k=0;k<=n;k++)
    {

           diff =1 ;
           sum =0;
           multy = 1;
           for(i=0;i<=k-1;i++)
        {
            for(j=0;j<=i-1;j++)
            {
                diff =diff*(x[k]-x[j]);
            }
            sum=sum+c[i]*diff;
            diff=1;
        }
        for(i=0;i<=k-1;i++)
        {
            multy = multy *(x[k]-x[i]);
        }

           c [k] = (atan(x[k])- sum)/(multy);
           cout<<c[k]<<endl;
           file<<c[k]<<endl;
    }



 return c ;
}

int main ()
{

    float *coef,a=1,b =6;
    int n=2;
    coffic_cal( n, a, b) ;  // of order 2
    n = 4;
    coffic_cal( n, a, b) ;   // of order 4
    n= 10 ;
    coffic_cal( n, a, b) ;    // of order 10

    return 0;
}



