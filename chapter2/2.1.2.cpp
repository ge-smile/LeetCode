/* Follow up for "Remove Duplicates" : What if duplicates are allowed at most twice? 
   For example, given sorted array A = [1,1,1,2,2,3],
   Your function should return length = 5, and A is now [1,1,2,2,3]
*/

class solution{
public:
	int removeDuplicates(int[] arr, int n){
		if(n <= 2)  return n;
		
		int idx = 2;
		for(int i = 2; i < n; i++){
			if(arr[i] != arr[idx-2]){
				arr[++idx] = a[i];
			}
		}
		return idx;
	}
};


// if not sorted, need to use hashmap