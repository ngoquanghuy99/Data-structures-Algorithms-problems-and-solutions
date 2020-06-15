#include <iostream> 
using namespace std; 
long long n, arr[100005];
void heapify(long long arr[], long long n, long long i) 
{ 
	long long largest = i;
	long long l = 2 * i + 1; 
	long long r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 
		heapify(arr, n, largest); 
	} 
} 

void heapSort(long long arr[], long long n) 
{ 
	for (long long i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 
	for (long long i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]); 
		heapify(arr, i, 0); 
	} 
} 
void printArray(long long arr[], long long n) 
{ 
	for (long long i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 
int main() 
{ 	cin >> n;
	for(long long i = 0; i < n; i++) cin >> arr[i];
	heapSort(arr, n); 
	printArray(arr, n); 
} 

