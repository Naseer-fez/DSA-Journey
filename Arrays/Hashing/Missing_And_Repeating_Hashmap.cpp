#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void missingnun(int arr[], int n)
{
    int repeat = 0, missing = 0;
    std::unordered_map<int, int> mp;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        auto it = mp.find(arr[i]);
        if (it != mp.end())
        {
            repeat = arr[i];
        }
        else
        {
            mp[arr[i]]++;
        }
        sum+=arr[i];


    }
    int actual=(n*(n+1))/2;
    int current=sum-repeat;
    missing=actual-current;

    cout << "Repeated  number:{" << repeat << "}\n";
    cout << "Missing number:{" << missing << "}";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1,2,5,2,4,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    missingnun(arr, n);

    return 0;
}