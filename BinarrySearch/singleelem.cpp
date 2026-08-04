#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int target)
{
    int low = 1;
    int high = n - 2;
    int mid;
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];
    int flip = 1;
    while (low <= high)
    {
        mid = high + ((low - high) / 2);
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        } // that measn we have found the elemnt
        if (mid % 2 == 1)
        {
            if (arr[mid] == arr[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {

            if (arr[mid] == arr[mid - 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -99;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n, 7);
    cout << value;
}