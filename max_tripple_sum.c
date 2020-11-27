#include <bits/stdc++.h> 
using namespace std; 

bool find3Numbers(int A[], int arr_size, int sum) 
{ 
	int l, r; 

	/* Sort the elements */
	sort(A, A + arr_size); 

	for (int i = 0; i < arr_size - 2; i++) { 

		l = i + 1; // index of the first element in the 

		r = arr_size - 1; // index of the last element 
		while (l < r) { 
			if (A[i] + A[l] + A[r] == sum) { 
				printf("Triplet is %d, %d, %d\n", A[i], 
					A[l], A[r]); 
				return true; 
			} 
			else if (A[i] + A[l] + A[r] < sum) 
				l++; 
			else // A[i] + A[l] + A[r] > sum 
				r--; 
		} 
	} 

	return false; 
} 

bool find3Numbers2(int arr[], int arr_size, int sum)
{
	sort(arr, arr + arr_size);
	for (int i = 0; i < arr_size - 2; i++) {
		int left  = i + 1;
		int right = arr_size - 2;
		while( left < right) {
			int tsum = arr[left] + arr[right] + arr[i];
			if (tsum == sum) {
				cout << "found " << arr[left]  << " " << arr[right] << " " << arr[i] << endl;
				return true;
			}
			if(tsum > sum)
				right--;
			else
				left++;
		}
	}
	return false;
}
/* Driver program to test above function */
int main() 
{ 
	int A[] = { 1, 4, 45, 6, 10, 8 }; 
	int sum = 22; 
	int arr_size = sizeof(A) / sizeof(A[0]); 

	find3Numbers(A, arr_size, sum); 
	find3Numbers2(A, arr_size, sum); 

	return 0; 
} 

