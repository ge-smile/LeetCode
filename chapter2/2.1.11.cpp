/* Remove Element
Given an array and a value, remove all instances of that value in place and return the new length. The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

int removeElement(int A[], int n, int element)
{
	int index = 0;
	for(int i = 0; i<n ; i++){
		if(A[i] != element){
			A[index++] = A[i];
		}
	}
}