#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> doUnion(std::vector<int> &a, std::vector<int> &b)
    {
        int an = a.size();
        int bn = b.size();
        int i = 0, j = 0;
        vector<int> unq;
        while (i<an & j<bn)
        {
        if (a[i]==b[j]){
            unq.push_back(a[i]);
            i++;
            j++;

        }            
        else if(a[i]>b[j]){
            j++;
        }
        else{
            i++;
        }


        }
        



     return unq;
    }
};

int main()
{
    Solution sol;

    std::vector<int> arr1 = {1, 2, 3, 4, 5, 6,7};
    std::vector<int> arr2 = {1, 2, 3, 3, 4, 3, 3, 3, 5, 6};

    auto result = sol.doUnion(arr1, arr2);
    // std::cout << "Size of Union: " << result << std::endl;
    for (auto i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i] << "]";
    }

    return 0;
}