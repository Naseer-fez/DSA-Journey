#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int upperbound(int arr[], int n, int tar)
{

    int low = 0;
    int high = n - 1;
    int cnt = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= tar)
        {
            cnt = mid;
            low = mid + 1;
        }

        else
            high = mid - 1;
    }

    return cnt + 1;
}
int smallerval(int arr[][5], int n, int m, int mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += upperbound(arr[i], m, mid);
    }
    return cnt;
}

int getthemedain(int arr[][5], int n, int m)
{
    int low = arr[0][0];
    int high = arr[0][m - 1];

    // Find the  actual minimum and maximum in the matrix
    for (int i = 0; i < n; i++)
    {
        low = min(low, arr[i][0]);
        high = max(high, arr[i][m - 1]);
    }
    int val = (n * m) / 2;
    while (low <= high)
    {
        // int mid=(low+high)>>1;
        int mid = (low + high) / 2;
        int smalls = smallerval(arr, n, m, mid); // wht to do here
        if (smalls <= val)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[][5] = {
        {1, 5, 7, 9, 11},
        {2, 3, 4, 5, 10},
        {9, 10, 12, 14, 16}

    };
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr[0]) / sizeof(int);
    cout << getthemedain(arr, n, m);

    return 0;
}