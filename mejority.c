// C++ program to find Majority 
// element in an array 
#include <bits/stdc++.h> 
using namespace std; 

void findMajority(int arr[], int n) 
{
	int mejority = arr[0];
	int count    = 1;

	for(int i = 1; i < n; i++) {
		if (arr[i] == mejority)
			count++;
		else {
			count--;
			if (count == 0) {
				mejority = arr[i];
				count = 1;
			}
		}
	}

	count = 0;
	for (int i = 0; i < n; i++) {
		if ( arr[i] == mejority)
			count++;
	}

	if (count >= n/2)
		cout << "Mejority found " << mejority << endl;
	else
		cout << "Mejority not found " << endl;
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 2, 2, 1, 2, 5 , 2 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Function calling 
	findMajority(arr, n); 

	return 0; 
}

