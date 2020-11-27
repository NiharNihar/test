// C++ code for Max 
// Water Container 
#include<iostream> 
using namespace std; 

int maxArea1(int A[], int len) 
{ 
    int area = 0; 
   for(int i = 0; i < len; i++)  
   { 
        for(int j = i + 1; j < len; j++) 
        { 
           // Calculating the max area 
           area = max(area, min(A[j], 
                        A[i]) * (j - i)); 
                          
         }   
    } 
    return area; 
} 

int maxArea2(int A[], int len) 
{ 
	int l = 0; 
	int r = len -1; 
	int area = 0; 
	
	while (l < r) 
	{ 
		// Calculating the max area 
		area = max(area, min(A[l], A[r]) * (r - l)); 
		if (A[l] < A[r]) 
			l += 1; 
		else
			r -= 1; 
	} 
	return area; 
} 

int farea(int arr[], int n)
{
	int left  = 0;
	int right = n -1;
	int area  = 0;
	while(left < right) {
		area = max(area, min(arr[left], arr[right]) * (right - left));
		if(arr[left] < arr[right])
			left++;
		else
			right--;
	}
	return area;
}


// Driver code 
int main() 
{ 
	int a[] = {1, 5, 4, 3}; 
	int b[] = {3, 1, 2, 4, 5}; 
	
	int len1 = sizeof(a) / sizeof(a[0]); 
	cout << maxArea1(a, len1) << endl; 
	
	int len2 = sizeof(b) / sizeof(b[0]); 
	cout << maxArea2(b, len2) << endl; 
	cout << farea(b, len2) << endl; 
} 

