#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int *a,*b;
    int n,q;
    cin>>n;
    a=new int[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    cin>>q;
    b=new int[q];
    for(int j=0;j<q;++j)
        cin>>b[j];
    sort(a,a+n);
    for(int j=0;j<q;j++)
    {
        if(b[j]<a[0]) cout<<"0"<<endl;
        else {
            cout<<upper_bound (a,a+n, b[j])-a<<endl;
        }
    }
    delete[] a;
    delete[] b;

}
