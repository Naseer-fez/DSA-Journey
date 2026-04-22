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
        // back()
        while (i < an && j < bn)
        {
            int current;

            if (a[i] < b[j])
            {
                current = a[i++];
            }
            else if (a[i] > b[j])
            {

                current = b[j++];
            }
            else
            {
                current = a[i++];
                j++;
            }
            if (unq.empty() || (current != unq.back()))
            {

                unq.push_back(current);
            }
        }

        while (i < an)
        {
            if (a[i] != unq.back())
            {

                unq.push_back(a[i]);
            }
            i++;
        }

        while (j < bn)
        {
            if (b[j] != unq.back())
            {

                unq.push_back(b[i]);
            }
            j++;
        }

        return unq;
    }
};

int main()
{
    Solution sol;

    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {1, 2, 3, 3, 4};

    auto result = sol.doUnion(arr1, arr2);
    // std::cout << "Size of Union: " << result << std::endl;
    for (auto i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i] << "]";
    }

    return 0;
}