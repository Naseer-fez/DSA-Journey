#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i=0;
        for(auto j=1;j<nums.size();j++){

            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }

        }
        
        return nums.size(); 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    
    int k = sol.removeDuplicates(nums);

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}