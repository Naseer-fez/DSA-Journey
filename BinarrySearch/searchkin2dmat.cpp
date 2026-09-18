#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarysrcrow(int arr[], int n, int target)
{

    int low = 0;
    int high = n - 1;

    int index = -1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] > target)
        {

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

void binarysearch2D(int arr[][5], int n, int m, int target)
{
    int row = -9;
    int indexis = -1;
    for (int i = 0; i < n; i++)
    {
        const int value = binarysrcrow(arr[i], m, target);
        if (value != -1)
        {
            cout << "The Row is "<<i<<"\nThe coloum is "<<value;
            return;
        }
    }
    cout<<"No Element found";
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