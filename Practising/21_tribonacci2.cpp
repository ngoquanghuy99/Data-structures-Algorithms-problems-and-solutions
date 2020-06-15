#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
const i64 Mod = 1000000000000007LL;

i64 N;
vector<vector<i64> > IniMat;
vector<vector<i64> > Mult, Unit;

void Preprocess() {
	IniMat.resize(4, vector<i64>(1));
	IniMat[0][0] = 1; IniMat[1][0] = 3;
	IniMat[2][0] = 6; IniMat[3][0] = 2;
	Mult.resize(4, vector<i64>(4));
	Unit.resize(4, vector<i64>(4));
	for (int i=0; i<4; i++) Unit[i][i] = 1;
	Mult[0][1] = Mult[1][2] = 1; Mult[3][3] = 1;
	for (int i=0; i<4; i++) Mult[2][i] = 1;
}

i64 mulPow(i64 a, i64 b) {
	i64 res = 0;
	while (b > 0) {
		if (b % 2) {b--; res += a; res %= Mod;}
		else {b /= 2; a *= 2; a %= Mod;}
	}
	return res;
}

vector<vector<i64> > matMul(vector<vector<i64> > A, vector<vector<i64> > B) {
	int n = A.size(), p = A[0].size(), m = B[0].size();
	vector<vector<i64> > C(n, vector<i64>(m));
	for (int k=0; k<p; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				C[i][j] += mulPow(A[i][k], B[k][j]);
				C[i][j] %= Mod;
			}
		}
	}
	return C;
}

vector<vector<i64> > matPow(vector<vector<i64> > A, int n) {
	vector<vector<i64> > res = Unit;
	while (n > 0) {
		if (n % 2) {n--; res = matMul(res, A);}
		else {n /= 2; A = matMul(A, A);}
	}
	return res;
}

void Input() {
	cin >> N;
}

void Solve() {
	vector<vector<i64> > FinalMat = matMul(matPow(Mult, N-1), IniMat);
	cout << FinalMat[0][0] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); Preprocess();
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

