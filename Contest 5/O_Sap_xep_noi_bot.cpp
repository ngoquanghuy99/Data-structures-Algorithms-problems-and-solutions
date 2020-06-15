#include<iostream>

using namespace std;
void printOut(int arr[], int N){
	for(int i=0; i<N; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int N = 0, arr[101], count, dem;
	count = dem = 0;
	cin>>N;
	for(int i=0; i<N; i++) cin>> arr[i];
	for(int i=0; i<N-1; i++){
		for(int j=0; j<N-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				count = 1;
			}
			
		}
		if(count == 1){
			cout << "Buoc " << ++dem << ": ";
			printOut(arr,N);
		}
		count = 0;
	}
	return 0;
}

