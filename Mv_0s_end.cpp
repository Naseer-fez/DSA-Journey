#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        int j=0;

        for (auto i = 0; i < n; i++)
        {
            if(nums[i]!=0){
                nums[j++]=nums[i];
            }
        }
        for (int i = j+1; i < n; i++)
        {
            nums[i]=0;
        }
       


    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 0, 3, 12};
    
    sol.moveZeroes(nums);

    int n=nums.size();
    for (int i = 0; i < n; i++)
    {
        cout<<nums[i]<< " ";
    }
    
    // cout << endl;

    return 0;
}