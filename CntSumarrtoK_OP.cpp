#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Arrsumcount(int arr[], int n, int k)
{
    int count = 0;
    std::unordered_map<int, int> mp;
    int prefix[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {   sum+=arr[i];
        prefix[i]=sum;
    }
    for (int i = 0; i < n; i++)
    {
        if(prefix[i]==k)count++;
        int value=prefix[i]-k;
        if(mp.find(value)!=mp.end()){
            
            count+=mp[value];
        }
        if(mp.find(value)==mp.end())
        {
            mp[prefix[i]]=0;

        }
        mp[prefix[i]]++;

    }
    
    


    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, -1, 3, 4, -1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "[" << Arrsumcount(arr, n, 3) << "]";

    return 0;
}