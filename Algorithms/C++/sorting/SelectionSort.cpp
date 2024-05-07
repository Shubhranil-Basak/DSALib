#include <bits/stdc++.h> 
using namespace std; 

void SelectionSort(int arr[], int n){ 
	int i, j, min_idx; 
	for (i = 0; i < n - 1; i++) { 
		min_idx = i; 
		for (j = i + 1; j < n; j++) { 
			if (arr[j] < arr[min_idx]) 
				min_idx = j; 
		}
		if(min_idx != i)
            swap(arr[min_idx], arr[i]); 
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
	SelectionSort(arr, n); 
	cout << "Sorted array: \n"; 
	PrintArray(arr, n); 
	return 0; 
}