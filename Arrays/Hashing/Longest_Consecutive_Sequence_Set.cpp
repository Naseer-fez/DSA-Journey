#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Sequence(int arr[], int n)
{
    std::unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    int longest = 0;
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(it + x) != st.end())
            {
                count++;
                x++;
            }
            longest = std::max(longest, count);
        }
    }
    return longest;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {101, 102, 2, 1, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "[" << Sequence(arr, n) << "]";
}