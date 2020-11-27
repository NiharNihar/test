#include <bits/stdc++.h>
using namespace std;

void printPairs1(int A[], int arr_size,
                           int sum)
{
	int left, right;
	sort(A, A + arr_size);
	left = 0;
	right = arr_size -1;

	while( left < right) {
		int cs = A[left] + A[right];
		if(cs == sum) {
			cout << "Pair with given sum "  << sum << " found " <<endl;
			return;
		}
		if( cs > sum)
			right--;
		else
			left++;
	}
}

void printPairs2(int arr[], int arr_size, int sum)
{
	unordered_set<int> ms;
	for(int i = 0; i < arr_size; i++) {
		if (ms.find(sum - arr[i]) != ms.end())
			cout << "Pair with given sum "  << sum << " found " <<endl;
		ms.insert(arr[i]);
	} 

}

/* Driver Code */
int main()
{
	int A[] = { 1, 4, 45, 6, 10, 8 };
	int n = 16;
	int arr_size = sizeof(A) / sizeof(A[0]);

	// Function calling
	printPairs1(A, arr_size, n);
	printPairs2(A, arr_size, n);

	return 0;
}

