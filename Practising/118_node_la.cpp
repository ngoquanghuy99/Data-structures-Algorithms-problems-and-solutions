 #include<bits/stdc++.h> 
using namespace std; 

void leafNode(int preorder[], int n) { 
	stack<int> s; 
	for (int i = 0, j = 1; j < n; i++, j++) { 
		bool found = false; 
		if (preorder[i] > preorder[j]) 
			s.push(preorder[i]); 
		else{ 
			while (!s.empty()) { 
				if (preorder[j] > s.top()) { 
					s.pop(); 
					found = true; 
				} 
				else
					break; 
			} 
		} 
		if (found) 
			cout << preorder[i] << " "; 
	} 
	cout << preorder[n - 1]; 
} 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t; 
	while (t--){
		int n; cin >> n;
		int preorder[10005];
		for(int i = 0; i < n; i++) cin >> preorder[i];
		leafNode(preorder, n); 
		cout << endl;
	}
	return 0; 
} 

