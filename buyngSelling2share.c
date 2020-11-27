#include <bits/stdc++.h>
using namespace std;

// Returns maximum profit with 
// two transactions on a given
// list of stock prices, price[0..n-1]
int maxProfit(int price[], int n)
{
	int profit[n];
	memset(profit, 0, sizeof(profit));

	int maxp = price[n-1];
	for(int i = n - 2; i >= 0; i--) {
		if(price[i] > maxp)
			maxp = price[i];
		profit[i] = max(profit[i + 1], profit[i] + maxp - price[i]); 
	}

	int minp = price[0];
	for(int i = 1; i < n; i++) {
		if(price[i] < minp)
			minp = price[i];
		profit[i] = max(profit[i-1], profit[i] + price[i] - minp);
	}

	return profit[n-1];
}

int maxProfit2(int arr[], int n)
{
	int profit[n];
	memset(profit, 0, sizeof(profit));

	int maxp = arr[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		if (maxp < arr[i])
			maxp = arr[i];
		profit[i] = max( profit[i+1], profit[i] + (maxp - arr[i]));
	}

	int minp = arr[0];
	for (int i = 1; i < n; i++) {
		if(minp > arr[i])
			minp = arr[i];
		profit[i] = max(profit[i - 1], profit[i] + (arr[i] - minp));
	}
	return profit[n-1];
}

// Driver code
int main()
{
	int price[] = { 2, 30, 15, 10, 8, 25, 80 };
	int n = sizeof(price) / sizeof(price[0]);
	cout << "Maximum Profit = " << maxProfit(price, n) << endl;
	cout << "Maximum Profit = " << maxProfit2(price, n) << endl;
	return 0;
}

