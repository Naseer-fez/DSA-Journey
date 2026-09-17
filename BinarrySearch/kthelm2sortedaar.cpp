#include <iostream>
#include <bits/stdc++.h>
using namespace std;

float binary(int arr[], int n, int arr2[], int m, int k)
{
    if (n > m)
    {
        return binary(arr2, m, arr, n,k);
        // to get the smallest array
    }
    int low = max(0, k - m), high = min(k, n);
    int n1 = (n + m);
    int left = k;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = (left - mid1);
        int l1 = -999, l2 = -999;
        int r1 = 999, r2 = 999;
        if (mid1 < n)
            r1 = arr[mid1];
        if (mid2 < m)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {

            return std::max(l1, l2);
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }

    return 0.0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {2,3,6,7,9};
    int arr2[] = {1,4,8,10};
    int n = sizeof(arr) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);

    float value = binary(arr, n, arr2, m, 4);
    cout << value;
}