#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int i,j,k,n = 4,p;   // n is number of unknown variable
    float A[n][n] = {{0.4096 , 0.1234 ,0.3678 ,0.2943},{0.2246 ,0.3872 , 0.4015,0.1129},{0.3645,0.1921,0.3781,0.0643},{0.1784,0.4002,0.2786,0.3927}}; //
    float  b[n] = {0.4043,0.1550,0.4240,0.2557};
    float x[n],s[n]={0,0,0,0},sum,f=0;
//
     for(i =0 ;i<n;i++)
     {
         for(j =0 ;j<n;j++)
         {
             cout<<A[i][j]<<" ";
             if( abs(A[i][j])>abs(s[i]))
             {
                 s[i]= abs(A[i][j]);
                   //cout<<s[i]<<" ";
             }
         }
         cout<<endl;
     }


     for(k = 0;k<n-1;k++)
     {
        f =0;
         for(j = k ;j<n;j++)
         {
             if(f<abs(A[j][k])/s[j])
             {
                 f = abs(A[j][k])/s[j];
                 p = j;
             }
         }

         for(j=k;j<n;j++)
         {
             f = A[k][j];
             A[k][j]= A[p][j];
             A[p][j] = f;


         }
        f = b[k];
        b[k] = b[p];
        b[p] = f;

        for(i=k+1;i<n;i++)
         {
             for(j =k+1;j<n;j++)
             {
                A[i][j] = A[i][j] - (A[k][j]/A[k][k])*A[i][k] ;


             }

                 b[i] = b[i]- (A[i][k]/A[k][k])*b[k] ;
         }

     }



     x[n-1] = b[n-1]/A[n-1][n-1];
     cout<<endl<<"The value of x"<<n<<" = "<<x[n-1]<<endl;
     for(k = n-2;k>=0;k-=1)
     {
         sum = b[k];
         for(j = k+1;j<n;j++)
         {
             sum = sum - A[k][j]*x[j];

         }
         x[k] = sum/A[k][k];
          cout<<endl<<"The value of x"<<k+1<<" = "<<x[k]<<endl;

     }



     return 0;
}
