// C program to find Maximum Product Subarray
#include <stdio.h>

// Utility functions to get minimum of two integers
int min(int x, int y) { return x < y ? x : y; }

// Utility functions to get maximum of two integers
int max(int x, int y) { return x > y ? x : y; }

/* Returns the product of max product subarray.
Assumes that the given array always has a subarray
with product more than 1 */
int maxSubarrayProduct(int arr[], int n)
{
	// max positive product 
	// ending at the current position
	int max_ending_here = 1;

	// min negative product ending 
	// at the current position
	int min_ending_here = 1;

	// Initialize overall max product
	int max_so_far = 0;
	int flag = 0;

	/* Traverse through the array. Following values are
	maintained after the i'th iteration:
	max_ending_here is always 1 or some positive product
					ending with arr[i]
	min_ending_here is always 1 or some negative product
					ending with arr[i] */
	for (int i = 0; i < n; i++) {
		/* If this element is positive, update
		max_ending_here. Update min_ending_here only if
		min_ending_here is negative */
		if (arr[i] > 0) {
			max_ending_here = max_ending_here * arr[i];
			min_ending_here
				= min(min_ending_here * arr[i], 1);
			flag = 1;
		}

		/* If this element is 0, then the maximum product
		cannot end here, make both max_ending_here and
		min_ending_here 0
		Assumption: Output is alway greater than or equal
					to 1. */
		else if (arr[i] == 0) {
			max_ending_here = 1;
			min_ending_here = 1;
		}

		/* If element is negative. This is tricky
		max_ending_here can either be 1 or positive.
		min_ending_here can either be 1 or negative.
		next min_ending_here will always be prev.
		max_ending_here * arr[i] next max_ending_here
		will be 1 if prev min_ending_here is 1, otherwise
		next max_ending_here will be prev min_ending_here *
		arr[i] */
		else {
			int temp = max_ending_here;
			max_ending_here
				= max(min_ending_here * arr[i], 1);
			min_ending_here = temp * arr[i];
		}

		// update max_so_far, if needed
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	if (flag == 0 && max_so_far == 0)
		return 0;
	return max_so_far;
}

int maxSubarrayProduct2(int arr[], int n)
{
	int  max_end_here = 1;
	int  min_end_here = 1;
	int  max_so_far   = 0;
	bool flag         = false;
	for(int i  = 0; i < n; i++) {
		if(arr[i] == 0) {
			max_end_here = min_end_here = 1;
		} else if( arr[i] > 0) {
			max_end_here = arr[i] * max_end_here;
			min_end_here = min(arr[i] * min_end_here, 1);
			flag = true;
		} else {
			int tmp = max_end_here;
			max_end_here = max(arr[i] * min_end_here, 1);
			min_end_here = tmp * arr[i];
		}

		if(max_so_far < max_end_here)
			max_so_far = max_end_here;

	}
	if(!flag && max_so_far == 0)
		return 0;
	return max_so_far;
}

int maxSubarrayProduct3(int arr[], int n)
{
	int  max_end_here = 1;
	int  min_end_here = 1;
	int  max_so_far   = 0;
	bool pfl          = false;

	for(int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			max_end_here = 1;
			min_end_here = 1;
		}
		else if (arr[i] > 0) {
			pfl = true;
			max_end_here = max_end_here * arr[i];
			min_end_here = min(min_end_here * arr[i], 1);
		}
		else {
			int tmp = max_end_here;
			max_end_here = max(min_end_here * arr[i], 1);
			min_end_here = tmp * arr[i];
		}

		if (max_end_here > max_so_far)
			max_so_far = max_end_here;
	}
	if(!pfl && max_so_far == 0)
		return 0;
	return max_so_far;
}
// Driver code
int main()
{
	int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Maximum Sub array product is %d\n",
		maxSubarrayProduct(arr, n));
	printf("Maximum Sub array product is %d\n",
		maxSubarrayProduct2(arr, n));
	printf("Maximum Sub array product is %d\n",
		maxSubarrayProduct3(arr, n));
	return 0;
}

