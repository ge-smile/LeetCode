/* There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log(m+n)).

Could convert to: given two sorted array, find the kth biggest element
*/

class solution{
public:
	int find_median(int arr1[], int arr2[], int m, int n){
		int total = m+n;
		if( total & 0x1) // total is odd
			return find_kth(arr1, m, arr2, n, total/2+1);
		else             // total is even
		{
			int a = find_kth(arr1, m, arr2, n, total/2);
			int b = find_kth(arr1, m, arr2, n, total/2+1);
			return (a+b)/2;
		}
	}
private:
	int find_kth(int arr1[], int m, int arr2[], int n, int k){
		// stop situation
		if(m > n) return find(arr2, n, arr1, m, k); // always check the situation that m<n 
		if(m == 0) return arr2[k-1];
		if(k == 1) return min(arr1[0], arr2[0]);
		
		// divide arr1 and arr2 into two parts
		int a = min(k/2, m);
		int b = k-a;
		
		if(arr1[a-1] == arr2[b-1])
			return arr1[a-1];
		else if(arr1[a-1] < arr2[b-1])
			return find_kth(arr1+a, m-a, B, n, k-a);
		else
			return find_kth(arr1, m, arr2+b, n-b, k-b);
	}
};