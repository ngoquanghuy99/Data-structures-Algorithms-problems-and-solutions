#include<iostream>
using namespace std;
int printMaxsizesquare(int **arr,int m,int n)
{
    int DP[m][n],i,j,maxi=0;
    
    for(i=0;i<m;i++)
    {
        DP[i][0] = arr[i][0];
        maxi = max(arr[i][0],maxi);
    }
    for(j=0;j<n;j++)
    {
        DP[0][j] = arr[0][j];
        maxi = max(maxi,arr[0][j]);
    }
    
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                DP[i][j] = min(min(DP[i-1][j],DP[i-1][j-1]),DP[i][j-1]) + 1; 
            }
            else
            {
                DP[i][j] = 0;
            }
                
            if(DP[i][j]>maxi)
                maxi = DP[i][j];
        }
    }
    return maxi;
}
int main()
 {
	//code
    int t,N,**arr,i,j,M;
    cin>>t;
    while(t--)
    {
        cin>>M>>N;
        arr = new int*[M];
        for(i=0;i<M;i++)
            arr[i] = new int[N];
        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
                cin>>arr[i][j];
        }
        cout<<printMaxsizesquare(arr,M,N)<<endl;
    }
	return 0;
}
