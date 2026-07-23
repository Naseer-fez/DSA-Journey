#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int mid = high + ((low - high) / 2);
    while (low <= high)
    {
        mid = high + ((low - high) / 2);
        if (arr[mid] == target)
        {
            return mid;
        }
        else
        {
            if (arr[low] < arr[mid])
            { // Measn the array is still sorted so first check the numbers in this
                if (arr[mid] > target)
                {
                    high = mid - 1;
                }
                else if (arr[mid] < target)
                {
                    low = mid + 1;
                }
            } //NOw the low>mid condtion means the array on the left is not sorted so chck the vaibles values first
            else{
                if(arr[low]<=target && target>arr[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }


            }

        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n,7);
    cout << value;
}