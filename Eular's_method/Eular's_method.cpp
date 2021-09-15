#include<iostream>
using namespace std;

// solving  ordinary differential equation using Euler's Method

//Y' = -100*y + 100*t+101

double y_derivative(double y,double t)
{

    return(-100*y+100*t+101);  //
}

int main()
{
    double h = 0.1,x=0,y1=1,y2=0.99,y3=1.01;

    cout<<"x"<<"\t"<<"analytical solution."<<"\t"<<"y(0)=1"<<"\t"<<"y(0) =0.99"<<"\t"<<"y(0)=1.1"<<endl;
    while(x<1)
    {

        cout<<x<<"\t"<<x+1<<"\t\t\t"<<y1<<"\t"<<y2<<"\t\t"<<y3<<endl;
        y1 = y1 + h*y_derivative(y1,x);
        y2 = y2 + h*y_derivative(y2,x);
        y3 = y3 + h*y_derivative(y3,x);

        x+=h;
    }
return 0;
}
