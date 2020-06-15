#include<cstdio>
using namespace std;
const int N = 1005;
 
/* Stack */
int stack[N], topS;
void init() { topS = 0; }
int top() { return stack[topS-1]; }
int pop() { return stack[--topS]; }
void push(const int &x) { stack[topS++] = x; }
/* End of Stack */
 
int m, n, a[N][N], f[N][N], left[N], right[N];
/* f[y][x] = k <=> a[y..y+k-1][x] = 11..., k max */
 
void enter() {
	scanf("%d%d",&m,&n);
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
}
 
void calcF() {
	for(int j = 0; j < n; ++j)
		for(int i = m-1; i >= 0; --i)
			f[i][j] = a[i][j] ? f[i+1][j] + 1 : 0;
}
 
void maximize(int &a, const int &b) { if(a < b) a = b; }
 
void solve() {
	int res = 0;
	for(int i = 0; i < m; ++i) {
		left[0] = 0; init();
		for(int j = 1; j < n; ++j)
			if(f[i][j] > f[i][j-1]) left[j] = j, push(j-1);
			else {
				while(topS && f[i][j] <= f[i][top()]) pop();
				left[j] = topS ? top() + 1 : 0;
			}
		right[n-1] = n-1; init();
		for(int j = n-2; j >= 0; --j)
			if(f[i][j] > f[i][j+1]) right[j] = j, push(j+1);
			else {
				while(topS && f[i][j] <= f[i][top()]) pop();
				right[j] = topS ? top() - 1 : n-1;
			}
		for(int j = 0; j < n; ++j) maximize(res, (right[j] - left[j] + 1) * f[i][j]);
	}
	printf("%d\n", res);
}
 
int main() {
	int t = 0;
	scanf("%d", &t);
	while (t--){
		enter();
		calcF();
		solve();
	}
	return 0;
}
