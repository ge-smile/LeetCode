/* 3 Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution. 
For example, given array S = {-1 2 1 -4}, and target=1
The sum that is closest to the target is 2. (-1+2+1 = 2)
*/

int threeSumCloset(vector<int> &num, int target)
{
	sort(num.begin(), num.end());
	for(auto a = num.begin(); a!= prev(num.end(),2); a++){
		auto b = next(a);
		auto c = prev(num.end());
		
		int min_gap = INT_MAX;
		int result = 0;
		
		while(b < c){
			const int sum = *a+*b+*c;
			const int gap = abs(sum - target);
			
			if(gap< min_gap){
				min_gap = gap;
				result = sum;
			}
			
		
			if( sum < target){
				++b;
			}
			else{
				--c;
			}
		}
		return result;
	}
}