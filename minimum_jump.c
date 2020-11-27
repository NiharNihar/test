// C++ program for Minimum number
// of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x < y) ? x : y; }

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{
	int jmp[n];
	if (arr[0] == 0)
		return -1;
	if (n == 1)
		return 0;

	jmp[0] = 0;

	for(int i = 1; i < n; i++) {
		jmp[i] = INT_MAX;
		for(int j = 0; j < i; j++) {
			if (i <= j + arr[j] && jmp[j] != INT_MAX) {
				jmp[i] = min (jmp[i], jmp[j] + 1);
				break;
			}

		}
	}
	return jmp[n -1];
}

int minJumps2(int arr[], int n)
{
	if (arr[0] == 0)
		return -1;
	if (n == 1)
		return 0;

	int maxreach = arr[0];
	int step    = arr[0];
	int jump    = 1;

	for(int i = 1;  i < n; i++) {
		if (i == n -1)
			return jump;
		maxreach = max (maxreach, i + arr[i]);
		step--;
		if (step == 0) {
			jump++;
			if (i >= maxreach)
				return -1;
			step = maxreach - i;
		}
	} 
	return -1;

}
// Driver code
int main()
{
	int arr[] = { 1, 3, 6, 1, 0, 9 };
	//int arr2[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
	int size = sizeof(arr) / sizeof(int);
	cout << "Minimum number of jumps to reach end is "
		<< minJumps(arr, size) << endl;
	cout << "Minimum number of jumps to reach end is "
		<< minJumps2(arr, size) << endl;
	return 0;
}


