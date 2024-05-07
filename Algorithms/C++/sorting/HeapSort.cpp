#include <bits/stdc++.h>
using namespace std;


void Heapify(int arr[], int N, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < N && arr[l] > arr[largest])
		largest = l;

	if (r < N && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);

		Heapify(arr, N, largest);
	}
}

void HeapSort(int arr[], int N){

	for (int i = N / 2 - 1; i >= 0; i--)
		Heapify(arr, N, i);

	for (int i = N - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

void PrintArray(int arr[], int size){ 
	int i; 
	for (i = 0; i < size; i++) { 
		cout << arr[i] << " "; 
	}
    cout << endl; 
}

int main(){
    int n;
	cin >> n;
    int arr[n];
    for(int  i=0;i<n;i++){
        cin >> arr[i];
    }
	HeapSort(arr, n); 
	cout << "Sorted array: \n"; 
	PrintArray(arr, n); 
	return 0; 
}