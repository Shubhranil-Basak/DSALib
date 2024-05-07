#include <bits/stdc++.h>
using namespace std; 

 
int getSum(int BITree[], int index) 
{ 
	int sum = 0; // Initialize result 

	// index in BITree[] is 1 more than the index in arr[] 
	index = index + 1; 

	// Traverse ancestors of BITree[index] 
	while (index>0) 
	{ 
		sum += BITree[index]; 
		index -= index & (-index); 
	} 
	return sum; 
} 


void updateBIT(int BITree[], int n, int index, int val) 
{ 
	// index in BITree[] is 1 more than the index in arr[] 
	index = index + 1; 

	// Traverse all ancestors and add 'val' 
	while (index <= n) 
	{ 
	// Add 'val' to current node of BI Tree 
	BITree[index] += val; 

	// Update index to that of parent in update View 
	index += index & (-index); 
	} 
} 

int sum(int x, int BITTree1[], int BITTree2[])
{
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}
 
void updateRange(int BITTree1[], int BITTree2[], int n, int val, int l, int r)
{
 
    // Update BIT1
    updateBIT(BITTree1, n, l, val);
    updateBIT(BITTree1, n, r + 1, -val);
 
    // Update BIT2
    updateBIT(BITTree2, n, l, val * (l - 1));
    updateBIT(BITTree2, n, r + 1, -val * r);
}
 
int rangeSum(int l, int r, int BITTree1[], int BITTree2[])
{
    return sum(r, BITTree1, BITTree2) - sum(l - 1, BITTree1, BITTree2);
}
 
int *constructBITree(int arr[], int n) 
{ 
	// Create and initialize BITree[]
	int *BITree = new int[n+1]; 
	for (int i=1; i<=n; i++) 
		cin >> BITree[i]; 

	// Store the actual values in BITree[] using update() 
	for (int i=0; i<n; i++) 
		updateBIT(BITree, n, i, arr[i]); 
 
	return BITree; 
} 


// Driver code 
int main() 
{ 
	int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
	int n = sizeof(freq)/sizeof(freq[0]); 
	int *BITree = constructBITree(freq, n); 
	cout << "Sum of elements in arr[0..5] is "
		<< getSum(BITree, 5); 

	freq[3] += 6; 
	updateBIT(BITree, n, 3, 6);

	cout << "\nSum of elements in arr[0..5] after update is "
		<< getSum(BITree, 5); 

	return 0; 
} 
