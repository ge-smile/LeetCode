/* 3 Sum
Given an array S of n integers, are there elements a,b,c in S such that a+b+c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: 
- Elements in a triplet(a,b,c) must be in non-descending order.(ie, a<=b<=c) 
- The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4}.
A solution set is (-1, 0, 1), (-1, -1, 2)
*/
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > threeSum(vector<int> &num){
	// elements in non-descending order, take O(nlogn)
	sort(num.begin(), num.end());
	const int target = 0;
	
	vector< vector<int> > result;
	vector<int>::iterator add; 
	for(vector<int>::iterator neg= num.begin(); *neg < 0; neg++){
		/*vector<int>::iterator pos = prev(num.end());
		while(*pos > 0){
			if(-(*neg) > *pos){
				add = pos;
				while(*add > 0){
					if(*add + *neg + *pos == target){
						result.push_back({*neg, *add, *pos});
						break;
					}
					add--;
				} 
			}
			else{
				add = neg;
				while(*add <= 0){
					if(*add + *neg + *pos == target){
						result.push_back({*neg, *add, *pos});
						break;
					}
				}
				add++;
			}
			pos--;
		}*/   // not efficient enough
		auto a = neg;
		auto b = next(a);
		auto c = prev(num.end());
		
		while(b < c){
			if(*a + *b + *c < target){
				++b;
			}
			else if(*a + *b + *c > target){
				--c;
			}
			else{
				vector<int> record;
				record.push_back(*a);
				record.push_back(*b);
				record.push_back(*c);
				result.push_back(record);
				++b;
				--c;
			}
		}
	}
	
	// maybe don't need the following two lines
	                                        sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}

int main(){
	vector<int> S;
	S.push_back(-1);
	S.push_back(-2);
	S.push_back(-2);
	S.push_back(0);
	S.push_back(1);
	S.push_back(1);
	S.push_back(2);
	S.push_back(-1);
	S.push_back(-4);

	vector< vector<int> > result = threeSum(S);
	for(auto it = result.begin(); it != result.end(); it++){
		cout << "( ";
		for( auto inner = (*it).begin(); inner != (*it).end(); inner++){
			cout << *inner << ", ";
		}
		cout << ")" << endl;
	}
	return 0;
}

