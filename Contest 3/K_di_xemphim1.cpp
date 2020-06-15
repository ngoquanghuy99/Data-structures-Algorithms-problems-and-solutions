#include <iostream>
//#include <conio.h>
int sum, result, C, N;
int A[17]; 
using namespace std;
int dequy(int i)
{
   int j;
   sum=sum+A[i];
   if (sum<=C)
      {
              if (result<sum) result=sum;
              for (j=i+1; j<=N; j++) dequy(j);
      }        
   sum=sum-A[i]; 
}               
main ()
{
  int i;    
  cin>>C; cin>>N; 
  for (i=1; i<=N; i++) cin>>A[i];
  result=sum=0;
  A[0]=0;
  dequy(0);
  cout<<result;
  //getch();
}
