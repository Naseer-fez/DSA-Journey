#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int target)
{

    // The condition is ,  arr[i-1]<arr[i]>arr[i+1]
    //-1 and n elment is -infinity
    int low=1;
    int high=arr[n-1]; //for the sorted or take the max if the arrar is nto sorted 
    int mid;
    // for (int i = 1; i <=target; i++) // means target banas per hour
    // int mid=1;
    while(low<=high)
    {
        int mid=low + ((high - low) / 2);
        int totalhr = 0;
        for (int j = 0; j < n; j++)
        {
            //(a + b - 1) / b
           totalhr =totalhr+ (arr[j] + mid - 1) / mid;
        }
        // cout<<"\nThe current mid is:"<<mid;
        if(totalhr==target){
            return mid; //case the array is sorted or else store the data 
        }
        if(totalhr<target){
            high=mid-1;
        }else{
            low=mid+1;
        }
        // mid++;

    }
    return -99;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {31286, 31287, 31288, 31289};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n, 4);
    cout << value;
}