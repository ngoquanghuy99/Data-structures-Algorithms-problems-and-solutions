#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }

void prepare(char a[], char b[]){
   int cnt=0;
   b[++cnt]='#';
   for (int i=1; a[i]; i++)
   { b[++cnt]=a[i]; b[++cnt]='#'; }
   b[++cnt]=0;
   b[0]='^';
}

int manacher(char b[]){
   int C=1, R=1, n=strlen(b+1);
   int *P=new int[n+2], r=0;

   for (int i=2; i<n; i++) {
      int i_mirror = 2*C-i;
      P[i] = (R>i) ? min(R-i, P[i_mirror]) : 0;
      while (b[i-1-P[i]] == b[i+1+P[i]]) P[i]++;
      maximize(r, P[i]);
      if (i+P[i]>R) { C=i; R=i+P[i]; }
   }
   delete[] P;
   return r;
}

#define N 100005
char a[N], b[2*N];

main(){
   ios :: sync_with_stdio(false);
   int n;
   int t = 0; cin >> t;
   while (t--){
	   cin >> a+1;
	   n = strlen(a);
	   prepare(a, b);
	   cout << manacher(b) << endl;
	}
}
