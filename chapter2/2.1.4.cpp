/* Follow up search in Rotated Sorted Array
What if duplicates are allowed? Would this affect the running time complexity? How and why? 
Write a function to determine if a given target is in the array.
*/

class solution{
public:
	int rotated_binary_search_dup(int arr[], int n, int target){
		int left = 0;
		int right = n-1;
		while(left <= right){
			int mid = (left+right)/2;
			if(arr[mid] == target) return true;
			
			//upper sorted
			if((arr[left]<arr[mid]) && (target>arr[left]) && (target<arr[mid])){
				right = mid-1;
			}
			//lower sorted
			else if((arr[mid]<arr[right]) && (target<arr[right]) && (target>arr[mid])){
				left = mid+1;
			}
			else{
				// skip duplicate ones
				left++;
			}
			
		}
		return false;
	}
};