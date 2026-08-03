#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void foursum(int arr[], int n, int sum)
{
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    std::set<vector<int>> elem;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            for (int k = 0; k < n; k++)
            {
                int fin = sum - (arr[i] + arr[j] + arr[k]);
                auto it = mp.find(fin);
                if (it != mp.end())
                {
                    // Main logic here
                    if ((i == j) || (j == k) || (k == i))
                        break;
                    vector<int> a = {arr[i], arr[j], arr[k], fin};
                    elem.insert(a);
                    // cout<<"["<<arr[i]<<"]"<<"["<<arr[j]<<"]"<<"["<<arr[k]<<"]"<<"["<<fin<<"]"<<endl;
                    flag = 1;
                }
            }
        }
    }
    if (!flag)
    {
        cout << "No sum found";
        return;
    }
    for (const auto &vec : elem)
    {
        for (int element : vec)
        {
            std::cout << "[" << element << "]" << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {-1, 0, 1, 2, -1, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    foursum(arr, n, k);
    return 0;
}