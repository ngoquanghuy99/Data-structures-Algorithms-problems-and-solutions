#include <bits/stdc++.h> 
using namespace std;
char txt[1000001];
char pat[1000001];
void computeLPSArray(char* pat, int M, int* lps); 
bool KMPSearch(char* pat, char* txt) { 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int lps[M]; 
	computeLPSArray(pat, M, lps); 
	int i = 0; 
	int j = 0; 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 
		if (j == M) { 
			return true;
			j = lps[j - 1]; 
		}  
		else if (i < N && pat[j] != txt[i]) { 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
	return false;
} 
void computeLPSArray(char* pat, int M, int* lps) { 
	int len = 0; 
	lps[0] = 0;
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else { 
			if (len != 0) { 
				len = lps[len - 1]; 
			} 
			else { 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	while (t--){
		gets(txt);
		gets(pat);
		KMPSearch(pat, txt) ? cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0; 
} 

