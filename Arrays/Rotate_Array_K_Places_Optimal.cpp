#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
        void reverse(vector<int>&a,int s,int e){
            int length = e - s + 1;
            for(int i=s;i<length/2;i++){
                std::swap(a[s+i],a[e-i]);

            }

        }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;
        if (k == 0) return;
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
        reverse(nums,0,n-1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    sol.rotate(nums, k);

    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}