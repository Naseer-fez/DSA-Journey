#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int target)
{

    // The condition is ,  arr[i-1]<arr[i]>arr[i+1]
    //-1 and n elment is -infinity
    int low = 1;
    int high = n - 2;
    int mid;
    if (arr[0] >arr[1])
    {
        return arr[0];
    }
    else if (arr[n - 1] > arr[n - 2])
    {
        return arr[n - 1];
    }
    while (low<=high)
    {
        mid=low + (high - low) / 2;
        //base condition
        if(arr[mid-1] < arr[mid] && arr[mid]> arr[mid+1]){
            return arr[mid];
        }
        //now the conditions
        if(arr[mid]>arr[mid-1]){
            low=mid+1;
          
        }else{
            high=mid-1;
            

        }

    }
    return -99;    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n, 7);
    cout << value;
}