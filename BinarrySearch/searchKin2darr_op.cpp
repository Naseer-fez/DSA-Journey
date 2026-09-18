#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void binarysearch2D(int arr[][5], int n, int m, int target)
{
    int row = -9;

    // Even better optmised now
    int low = 0;
    int high = n * m - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        int row = mid / m;
        int coloum = mid % m;
        if (arr[row][coloum] == target)
        {
            cout << "Row: " << row << "\n";
            cout << "Column: " << coloum;
            return;
        }
        if (arr[row][coloum] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << "No Element found";
    // return indexis;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[][5] = {
        {3, 4, 7, 8, 9},
        {12, 13, 16, 18},
        {20, 21, 23, 29}};

    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr[0]) / sizeof(arr[0][0]);
    // cout << binarysearch2D(arr, n, m, 16);
    binarysearch2D(arr, n, m, 16);
    return 0;
}