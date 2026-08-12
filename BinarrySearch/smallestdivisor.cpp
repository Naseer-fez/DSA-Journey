#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int threshold)
{
    int low = 1;
    // int high = threshold;
    //Problem here we dont know the elemtn it is better to take a threshold elment as the max elemnt of the array
    int high=*std::max_element(arr,arr+n);
    int mid;
    int elem = threshold;

    while (low <= high)
    {
        mid = (low + high) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (arr[i] + mid - 1) / mid;
        }
        if (sum <= threshold)
        {
            elem = std::min(mid, elem);
        }
        if (sum > threshold)
        {
            low = mid+ 1;
        }else{
            high=mid-1;
        }
    }
    return elem;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, 5, 19};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n, 6);
    cout << value;
}