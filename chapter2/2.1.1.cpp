/* Given a sorted array, remove the duplicates in place such that each element appear only
once and return the new length.
   Do not allocate extra space for another array, you must do this in place with constant memory.
   For example, given input array A = [1,1,2]. 
   Your function should return length = 2, and A is now [1,2]
*/

// developed by Qian, 11/23/2014

class solution{
public:
	int removeDuplicates(int []arr, int n){
		if(n == 0) return n;  // don't forget the 0 
		
		int j = 0;
		for(int i = 0; i < n; i++){
			if(arr[j] != arr[i+1])  
				arr[++j] = arr[i];
		}
		
		return j+1;
	}
};

// Time: O(n), Space: O(1)