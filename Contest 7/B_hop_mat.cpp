#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector <int> person;
vector <int> adj[1003];
bool visited[1005];
int count[1003];
void read (){
	cin>>K>>N>>M;
	int ps;
	for (int i=1; i<=K; i++){
		cin>>ps;
		person.push_back(ps);
	}
	for (int i=1; i<=M; i++){
		int A, B;
		cin>>A>>B;
		adj[A].push_back(B);
	}
	for (int i=1; i<=N; i++){
		count[1003];
	}
}

void init (){
	for (int i=1; i<=N; i++)
		visited[i] = false;
}

void DFS(int u){
	for (int i=0; i<adj[u].size(); i++){
		int v=adj[u][i];
		if (!visited[v]){
			visited[v] = true;
			count[v]++;
			DFS(v);
		}
	}
}

int main (){
	read ();
	for (int i=0; i<person.size(); i++){
		init ();
		visited[person[i]]=1;
		count[person[i]]++;
		DFS(person[i]);
	}
	int answer=0;
	for (int i=1; i<=N; i++)
		if (count[i]==K) answer++;
	cout<<answer;
	return 0;
}
