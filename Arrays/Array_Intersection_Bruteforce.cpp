#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> doUnion(std::vector<int> &a, std::vector<int> &b)
    {

        vector<int> uni;
        for (int i = 0; i < a.size(); i++)
        {

            for (int j = 0; j < b.size(); j++)
            {
                if (a[i] == b[j])

                {

                    uni.push_back(a[i]);
                    break;
                }
            }
        }

        return uni;
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