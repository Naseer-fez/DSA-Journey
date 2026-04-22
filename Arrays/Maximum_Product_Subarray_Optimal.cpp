#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxprd(int arr[], int n)
{
    int maxsub = -9999;
    int prefix=1;
    int suffix=1;

    for (int i = 0; i < n; i++)
    {
    if(suffix==0)suffix=1;
    if(prefix==0)prefix=1;
    prefix=prefix*arr[i];
    suffix=suffix*arr[n-i-1];
    maxsub=std::max(maxsub,std::max(prefix,suffix));
    
    
    }

    return maxsub;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, -1, 3, 4, 0, -1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "[" << maxprd(arr, n) << "]";

    return 0;
}