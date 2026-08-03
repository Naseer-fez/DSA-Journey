#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
class Solution {
public:

    vector<int> doUnion(std::vector<int>& a, std::vector<int>& b) {

        set<int> unq;
        for (auto i = 0; i < a.size(); i++)
        {
                unq.insert(a[i]);


        }
        for (auto i = 0; i < b.size(); i++)
        {
            unq.insert(b[i]);
        }
        vector <int> uni;
        for (const auto& element : unq)
        {
         uni.push_back(element);   
        }
        
return uni;


   
    }
};


int main() {
    Solution sol;
    
    std::vector<int> arr1 = {1, 2, 3, 4, 5,6};
    std::vector<int> arr2 = {1, 2, 3,3,4,3,3,3,5,6};
    
    auto result = sol.doUnion(arr1, arr2);
    // std::cout << "Size of Union: " << result << std::endl;
    for(auto i=0;i<result.size();i++){
        cout<<"["<<result[i]<<"]";

    }
    
    return 0;
}