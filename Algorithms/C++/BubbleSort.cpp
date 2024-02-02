#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1; j++){
			if(arr[j] > arr[j + 1]){
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void PrintArray(int arr[], int size){
	int i;
	for (i = 0; i < size; i++){
		cout << " " << arr[i];
	}
	cout << endl;
}

int main(){
    int n;
	cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
	BubbleSort(arr, n); 
	cout << "Sorted array: \n"; 
	PrintArray(arr, n); 
	return 0; 
}