/* Search in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2)
You are given a target value to search. If found in the array, return its index, otherwise 
return -1. You may assume no duplicate exists in the array
*/

class solution{
public:
	int rotated_binary_search(int arr[], int n, int target){
		int left = 0;
		int right = n-1;
		while(left <= right){
			int middle = (left+right)/2;
			if(target == arr[middle]) return middle;
			
			// upper is sorted
			if((arr[left]<arr[middle]) && (arr[middle]>target) && (arr[left]<= target) ){
				right = middle-1;
			}
			// lower is sorted
			else{
				left = middle+1;
			}
		}
		return -1;
	}
};


//Time complexity: O(logn), Space complexity: O(1)