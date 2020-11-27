#include <bits/stdc++.h>

using namespace std; 
  
int maxSubArraySum1(int a[], int size) 
{
	int max_cur = a[0], max_s = a[0];

	for(int i = 1; i < size; i++) {
		max_cur = max(a[i], max_cur + a[i]);
		max_s   = max(max_s, max_cur);
	}  
 	return max_s;
} 

int maxSubArraySum2(int a[], int size) 
{
	int max_cur = 0;
	int max_s = INT_MIN;
	for(int i = 0; i < size; i++) {
		max_cur += a[i];
		if(max_cur > max_s) {
			max_s = max_cur;
		}
		if(max_cur < 0)
			max_cur = 0;

	}
	return max_s; 
} 

int maxSubArraySum3(int arr[], int size)
{
	int max_so_far   = arr[0];
	int max_end_here = arr[0];

	for(int i = 1; i < size; i++) {
		max_end_here = max(arr[i], max_end_here + arr[i]);
		max_so_far   = max(max_so_far, max_end_here);
	}
	return max_so_far;
}
/* Driver program to test maxSubArraySum */
int main() 
{ 
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3}; 
   int n = sizeof(a)/sizeof(a[0]); 
   int max_sum = maxSubArraySum1(a, n); 
   cout << "Maximum contiguous sum is " << max_sum<< endl; 
   max_sum = maxSubArraySum2(a, n); 
   cout << "Maximum contiguous sum is " << max_sum<< endl; 
   max_sum = maxSubArraySum3(a, n); 
   cout << "Maximum contiguous sum is " << max_sum<< endl; 
   return 0; 
} 
