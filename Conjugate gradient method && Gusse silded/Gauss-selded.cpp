#include<iostream>
#include<cmath>
using namespace std;

const int n =5;


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

int main()
{   int i,j,k=0;
    double sum;
    double A[n][n] = {{0.2,0.1,1,1,0},{0.1,4,-1,1,-1},{1,-1,60,0,-2},{1,1,0,8,4},{0,-1,-2,4,700}};
    double b[n]   = {1,2,3,4,5};
    double x[n] = {0,1.4,1.6,1.8,1};
    double r[n],del =10;
    double tolr = pow(10,-12);



    cout<<"Matrics A  is "<<endl;
    print2Darray(A);
    cout<<"Vector b is "<<endl;
    print1Darray(b);
    cout<<"intial Vector x is "<<endl;
    print1Darray(x);

   cout<<"----------------------------------------------------------------------------------------"<<endl;
   cout<<"Nu. of itration  | X1        |X2        |X3        |X4       |X5        |error"<<endl;
   cout<<"----------------------------------------------------------------------------------------"<<endl;
   while(sqrt(del)>tolr)
   {
        for(i =0;i<n;i++)
        {
            sum = 0;
            for (j =0;j<n;j++)
            {
                if(i!=j)
                    {
                       sum+=A[i][j]*x[j];
                    }
            }
            x[i] = (b[i]- sum)/A[i][i];
            //cout<<x[i]<<" ";
        }
        //cout<<endl;
     k++;
 del =0;
    for(i =0;i<n;i++)
        {

            sum =0;
            for(j=0;j<n;j++)
            {

                sum = sum + A[i][j]*x[j];
            }
           // cout<<sum<<endl;
            r[i] = b[i] - sum;
            del = del + pow(r[i],2);

    }
    cout<<k<<"       "<<x[0]<<"       "<<x[1]<<"     "<<x[2]<<"    "<<x[3]<<"     "<<x[4]<<"    "<<sqrt(del)<<endl;
    //cout<<sqrt(del)<<endl;
   }
   cout<<endl<<"solution to the problem"<<endl;
           for(i =0;i<n;i++)
           {
               cout<<"value of x"<<i<<" is = "<<  x[i] <<endl;
           }
          cout<<" tottal error in solution  =  "<<sqrt(del);

return 0;
}



