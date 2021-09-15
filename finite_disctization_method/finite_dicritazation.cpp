// deferential equation solution.
#include<iostream>
#include<math.h>
using namespace std;

const int n = 1000;  // step size
const float t0 = 0;  // initial value independent variable
const float tn = 1;
const float x0 = 0;  // initial value dependent variable at t0 and tn
const float xn = 1;

 // x'' + u(t)*x' + v(t)*x = f(t)

 // u(t) = -cos t ,v(t) = -sin(t) , f(t) = -exp(t)
float v_fun(float x)
{
    return(-sin(x));
}
float u_fun(float x)
{
    return(-cos(x));
}
float f_fun(float x)
{
    return(-exp(x));
}

int main ()
{
    int i,j;
    float h ,x;
    float  b[n],a[n];
    float c[n],d[n],B[n],t[n];
    h = (xn-x0)/n;
    x = t0;

    for(i = 0;i<=n;i++)
    {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
        d[i] = 0;
        B[i] =0;

    }

  // element of tridiagonal metrix
  for(i=1;i<n;i++)
  {

        x = x+h;
        a[i] = 1- h* u_fun(x)/2;
        c[i] = 1+ h*u_fun(x)/2;
        d[i] = h*h*v_fun(x) - 2;   //diagonal element of tridiagonal matrix
        b[i] = h*h*f_fun(x);

}



    B[1] = b[1]-t0*a[1];
    B[n-1] = b[n-1] - c[n-1]*tn;

// simple gauss elimination for getting solution (thomes algorithm )
    for(i = 2;i<n;i++)
    {
        d[i] = d[i]- a[i-1]*c[i-1]/d[i-1];
        B[i] = B[i] - a[i-1]*B[i-1]/d[i-1];
    }
    t[n-1] = B[n-1]/d[n-1];
    for(i=n-2;i>0;i--)
    {
        t[i] = (B[i]-c[i]*t[i+1])/d[i];
    }
   cout<<endl<<"Boundary value proble"<<" domain range "<<t0<<" to "<<tn<<endl<<"Number of discretization n ="<<n;
   cout<<endl<<"step size = "<<h;
   cout<<endl<<"solution of differential equation";

    for(i=1;i<n;i++)
    {
       cout<<endl<< t[i]<<","; // printing solution
    }

    return 0;

}
