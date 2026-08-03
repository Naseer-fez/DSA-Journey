#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int min = 99999;
    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        // now if th earray is not roatated
        if (arr[low] <= arr[high])
        {
            if (arr[low] < min)
            {
                min = arr[low];
            }
            break;
        }

        if (arr[low] > arr[mid])
        {

            if (arr[mid] < arr[high])
            {
                // now we are checking a sorted array 0,1,2
                if (arr[mid] < min)
                {
                    min = arr[mid];
                }
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[low] < min)
            {
                min = arr[low];
            }
            low = mid + 1;
        }
    }
    return min;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {4, 5, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n, 7);
    cout << value;
}