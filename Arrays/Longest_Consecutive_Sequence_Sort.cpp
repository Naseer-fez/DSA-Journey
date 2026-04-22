#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Sequence(int arr[], int n)
{
    std::map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = 1;
    }
    int len = 0;
    int prev = len;
    int currentElm = mp.begin()->first;
    auto i = mp.begin();
    while (i != mp.end())
    {   auto search=mp.find(currentElm + 1);
        if (search !=mp.end())
        {
            len++;
        }
        else
        {
            prev = std::max(prev,len);
            len = 0;
        }
        currentElm = i->first;
        i++;
    }

    return std::max(prev,len);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {101, 102, 2, 1, 0,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "[" << Sequence(arr, n) << "]";
}