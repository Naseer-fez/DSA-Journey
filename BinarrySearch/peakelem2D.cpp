#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxvalue(int arr[][6], int mid, int n)
{
    int mx = arr[0][mid];
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i][mid] > mx)
        {
            mx = arr[i][mid];
            index = i;
        }
    }

    return index;
}

void peakelem2d(int arr[][6], int n, int m, int target)
{
    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // This is the coloumn
        int maxelm = maxvalue(arr, n, mid); // cause the n is same for all
        // Now we need to check if it is peak or not
        int right = -1;
        int left = -1;
        if (mid == 0)
            right = arr[mid + 1][maxelm];
        else if (mid == n - 1)
            left = arr[mid - 1][maxelm];
        else
        {
            right = arr[mid + 1][maxelm];
            left = arr[mid - 1][maxelm];
        }
        // Now checking time
        if (left < arr[mid][maxelm] && arr[mid][maxelm] > right)
        {
            cout << "Peak element: " << arr[mid][maxelm] << "\n";
            cout << "Row: " << maxelm << "\n";
            cout << "Column: " << mid << "\n";
            return;
        }
        if (left > arr[mid][maxelm])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "No elemnt found";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[][6] = {
        {4, 2, 5, 1, 4, 5},
        {2, 9, 3, 2, 3, 2},
        {1, 7, 6, 0, 1, 1},
        {3, 6, 2, 3, 7, 2}};

    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr[0]) / sizeof(arr[0][0]);
    // cout << binarysearch2D(arr, n, m, 16);
    peakelem2d(arr, n, m, 16);
    return 0;
}