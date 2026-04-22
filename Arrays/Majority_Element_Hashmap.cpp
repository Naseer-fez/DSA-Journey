#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int majorityelemnt(int arr[], int n)
{

    std::unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {

        map[arr[i]]++;
    }
    int max = 0;
    int elemnt = 0;
    for (auto i = map.begin(); i != map.end(); i++)
    {
        if (i->second > max)
        {
            max = i->second;
            elemnt = i->first;
        }
    }

    cout << "" << elemnt << "->";

    return max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, 2, 3, 3, 2, 2, 2, 3, 1};
    cout << "[" << majorityelemnt(arr, sizeof(arr) / sizeof(arr[0])) << "]";

    return 0;
}