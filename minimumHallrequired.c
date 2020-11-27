// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

#define MAX 100001 

// Function to return the minimum 
// number of halls required 
int minHalls(int lectures[][2], int n) 
{ 

	// Array to store the number of 
	// lectures ongoing at time t 
	int prefix_sum[MAX] = { 0 }; 

	// For every lecture increment start 
	// point s decrement (end point + 1) 
	for (int i = 0; i < n; i++) { 
		prefix_sum[lectures[i][0]]++; 
		prefix_sum[lectures[i][1] + 1]--; 
	} 

	int ans = prefix_sum[0]; 

	// Perform prefix sum and update 
	// the ans to maximum 
	for (int i = 1; i < MAX; i++) { 
		prefix_sum[i] += prefix_sum[i - 1]; 
		ans = max(ans, prefix_sum[i]); 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 
	int lectures[][2] = { { 0, 5 }, 
						{ 1, 2 }, 
						{ 1, 10 } }; 
	int n = sizeof(lectures) / sizeof(lectures[0]); 

	cout << minHalls(lectures, n); 

	return 0; 
} 

