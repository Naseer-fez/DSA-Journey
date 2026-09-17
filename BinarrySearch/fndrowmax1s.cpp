#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarysrcrow(int arr[], int n)
{

    int low = 0;
    int high = n - 1;
    int elem = arr[0];
    if (arr[high] == 0)
    {

        return -99;
    }
    int whereis1 = n;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (arr[mid] == 0)
        {

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            whereis1 = std::min(whereis1, mid);
        }
    }
    return n - whereis1;
}

int binarysearch2D(int arr[][5], int n, int m)
{
    int row = -9;
    int indexis = 0;
    for (int i = 0; i < n; i++)
    {
        // row=std::min(binarysrcrow(arr[0], m),row);
        int minval = binarysrcrow(arr[i], m);
        if (minval > row)
        {
            // cout<<"Index is "<<i<<"\nThe count is: "<<minval<<"\n";
            row = minval;
            indexis = i;
        }
    }
    return indexis;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[][5] = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr[0]) / sizeof(arr[0][0]);
    cout << binarysearch2D(arr, n, m);

    return 0;
}