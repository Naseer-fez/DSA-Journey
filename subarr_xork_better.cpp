#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int zorcont(int arr[], int n, int k)
{
    int count = 0;
    std::unordered_map<int, int> mp;
    int xr = 0;
    mp[0]=1;
    for (int i = 0; i < n; i++)
    {
        xr^=arr[i];
        int tar=xr^k;
        if(mp.find(tar)!=mp.end()){

            count+=mp[tar];

        }    

        mp[xr]++;
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {4, 2, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    cout << "[" << zorcont(arr, n, k) << "]";

    return 0;
}