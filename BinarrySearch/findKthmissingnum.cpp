#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int element)
{

    int low = 0;
    int high = n - 1;
    int mid;
    // for (int i = 1; i < arr[n-1]; i++)
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int sub = (arr[mid] - (mid + 1));
        
        if (mid + 1 < n && sub < element && (arr[mid + 1] - (mid + 2)) >= element)
        {
            // that measn i have found the 2 places where the elemnt is
            return arr[mid] + (element - sub);
        }

        if (sub < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    int missingBeforeLast = arr[n - 1] - n;

    // return arr[n - 1] + (element - missingBeforeLast);
    //out of bound elemnts
    return low+element;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {2, 3, 4, 7, 11};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n, 4);
    cout << value;
}