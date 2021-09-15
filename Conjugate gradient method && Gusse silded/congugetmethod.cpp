#include<iostream>
#include<cmath>
using namespace std;
const int n =5;
double Dot_product(double x[],double y[],int n)
{
   int i ;
   double p =0;
   for(i =0 ;i<n;i++)
   {
        p += x[i]*y[i];
   }
   return p;
}
double* matricx_multiply(double x[n][n],double y[n])
{
   int i ,j;
   double sum;
   double* p  = new double [n];
   for(i =0 ;i<n;i++)
   {
       sum =0;
        for(j =0;j<n;j++)
        {
            sum += x[i][j]*y[j];
        }
        p[i] = sum;
   }
   return p;
}

void print2Darray(double x[n][n])
{
    int i,j;

    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
         {
           cout<<x[i][j]<<" ";
         }
         cout<<endl;
    }

}
void print1Darray(double x[n])
{
    int i,j;

    for(i=0;i<n;i++)
    {
           cout<<x[i]<<endl;
    }
    cout<<endl;

}


int main ()
{
    int i,j,k=0;
    double A[n][n] = {{0.2,0.1,1,1,0},{0.1,4,-1,1,-1},{1,-1,60,0,-2},{1,1,0,8,4},{0,-1,-2,4,700}};
    double b[n]   = {1,2,3,4,5};
    double x[n] = {1,1,1,1,1};
    double m = Dot_product(x,b,n);
    double *p = matricx_multiply(A,x);
    double d[n],r[n],it_r[n],alfa,bita,g[n],sum,error=10;


    cout<<"Matrics A  is "<<endl;
    print2Darray(A);
    cout<<"Vector b is "<<endl;
    print1Darray(b);
    cout<<"intial Vector x is "<<endl;
    print1Darray(x);
    double tollr = pow(10,-12);
     for(i=0;i<n;i++)
   {
        d[i] = b[i] - p[i];
        r[i] = d[i];
       //cout<<r[i]<<" "<<d[i]<<endl;
   }
    cout<<"----------------------------------------------------------------------------------------"<<endl;
   cout<<"Nu.of itr. | X1        |X2        |X3           |X4             |X5            |error"<<endl;
   cout<<"----------------------------------------------------------------------------------------"<<endl;



    while (sqrt(error)>=tollr)
        {
          double *l = matricx_multiply(A,d);

          alfa = Dot_product(r,d,n)/(Dot_product(d,l,n));
           for(i =0;i<n;i++)
           {
               x[i] = x[i]+alfa*d[i];

               it_r[i] = r[i];
               r[i] = r[i]-alfa*l[i];
           }
           bita = Dot_product(r,r,n)/Dot_product(d,it_r,n);
           for(i =0;i<n;i++)
           {
               d[i] = r[i]+bita*d[i];
           }
           k++;
         error = 0;
        for(i =0;i<n;i++)
        {
            sum =0;
            for(j=0;j<n;j++)
            {
                sum = sum + A[i][j]*x[j];
            }

            g[i] = b[i] - sum;
            error = error + pow(g[i],2);


        }
        cout<<k<<"       "<<x[0]<<"       "<<x[1]<<"     "<<x[2]<<"    "<<x[3]<<"     "<<x[4]<<"    "<<sqrt(error)<<endl;


        }


         cout<<endl<<"solution to the problem"<<endl;
           for(i =0;i<n;i++)
           {
               cout<<"value of x"<<i<<" is = "<<  x[i] <<endl;
           }
          cout<<" tottal error in solution  =  "<<sqrt(error);

    return 0;
}
