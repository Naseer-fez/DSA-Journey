#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }

    if (arr[mid] > target)
    {
        return binary(arr, low, mid - 1, target);
    }
    else
    {
        return binary(arr, mid + 1, high, target);
    }
}

void lowerbound(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;  
    int lower = high+1;
    while (low<=high)
    {   int mid = low + (high - low) / 2;
        if(arr[mid]>=target){
            lower = std::min(lower, mid);
            high=mid-1;
            // low=mid+1;
            continue;
        }
        if (arr[mid] < target)
        {
         
            low=mid+1;
        }
        else{
           
            high=mid-1;
        }
        
    }
    cout<<"Elemnt is :"<<lower;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {2, 8, 8, 8,12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(int);
    std::sort(arr, arr + n);
    lowerbound(arr, n, 8);
}