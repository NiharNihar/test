// C++ program for coin change problem. 
#include<bits/stdc++.h> 

using namespace std; 

int count1( int S[], int m, int n ) 
{ 
	int mp[n + 1];
	memset(mp, 0, sizeof(mp));
	mp[0] = 1;
	for (int i = 0; i < m; i++) {
		for( int j = S[i]; j <= n; j++) {
			mp[j] +=mp[j - S[i]];
		}
	}
	return mp[n];	
}

int count1( int S[], int m, int n )
{
	int mp[n + 1];
	memset(mp, 0, sizeof(mp));

	mp[0] = 1;
	for (int i = 1; i < m; i++) {
		for(int j = S[i]; j <= n; j++) {
			mp[j] + = mp[j - S[i]];
		}
	}
	return mp[n];
} 
int count( int S[], int m, int n ) 
{ 
	int i, j, x, y; 

	// We need n+1 rows as the table 
	// is constructed in bottom up 
	// manner using the base case 0 
	// value case (n = 0) 
	int table[n + 1][m]; 
	
	// Fill the enteries for 0 
	// value case (n = 0) 
	for (i = 0; i < m; i++) 
		table[0][i] = 1; 

	// Fill rest of the table entries 
	// in bottom up manner 
	for (i = 1; i < n + 1; i++) 
	{ 
		for (j = 0; j < m; j++) 
		{ 
			// Count of solutions including S[j] 
			x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 

			// Count of solutions excluding S[j] 
			y = (j >= 1) ? table[i][j - 1] : 0; 

			// total count 
			table[i][j] = x + y; 
		} 
	} 
	return table[n][m - 1]; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {1, 2, 3}; 
	int m = sizeof(arr)/sizeof(arr[0]); 
	int n = 4; 
	cout << count(arr, m, n) << endl; 
	cout << count1(arr, m, n) << endl; 
	return 0;
} 
