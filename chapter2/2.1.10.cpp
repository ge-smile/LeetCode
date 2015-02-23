#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


vector< vector<int> > fourSum(vector<int> &num, int target)
{
    vector< vector<int> > result;
    sort(num.begin(), num.end());
    
    if(num.size() < 4){
        cout << "Elements' number is smaller than 4" << endl;
        return result;
    }
    
    unordered_multimap< int, pair<int, int> > cache;
    for(int i = 0; i+1< num.size(); i++){
        for(int j = i+1; j<num.size(); j++){
            cache.insert(make_pair(num[i]+num[j], make_pair(num[i],num[j])));
        }
    }
    
    for(auto i=cache.begin(); i!=cache.end(); i++){
        int x = target - (i->first);
        auto range = cache.equal_range(x); // returns a pair of iterator
        for(auto j = range.first; j!= range.second; j++){
            auto a = i->second.first;
            auto b = i->second.second;
            auto c = j->second.first;
            auto d = j->second.second;
            if(a!= c& a!= d & b!=c & b!=d){
                vector<int> vec;
                vec.push_back(a);
                vec.push_back(b);
                vec.push_back(c);
                vec.push_back(d);
                sort(vec.begin(), vec.end());
                result.push_back(vec);
            }
        }
    }
    
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}


int main(){
    vector<int> S;
    S.push_back(1);
    S.push_back(0);
    S.push_back(-1);
    S.push_back(0);
    S.push_back(-2);
    S.push_back(2);
    
    vector< vector<int> > result = fourSum(S, 0);
    for(auto it = result.begin(); it != result.end(); it++){
        cout << "( ";
        for( auto inner = (*it).begin(); inner != (*it).end(); inner++){
            cout << *inner << ", ";
        }
        cout << ")" << endl;
    }
    return 0;
}

