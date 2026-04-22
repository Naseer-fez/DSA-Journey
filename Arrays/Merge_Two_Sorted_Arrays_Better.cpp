#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergingarr(int arr[], int n, int arr2[], int m)
{
    int l1=0;
    int l2=0;
    int r1=n-1;
    int r2=m-1;

    while (r1>=0 && l2<=r2)
    {
        if(arr[r1]>arr2[l2]){
            std::swap(arr[r1],arr2[l2]);
           l2++;
           r1--;
        }        
        else{
            break;
        }


    }
    std::sort(arr,arr+n);
    std::sort(arr2,arr2+m);






    for (int i = 0; i < n; i++)
        cout << "[" << arr[i] << "]";

    for (int i = 0; i < m; i++)
        cout << "[" << arr2[i] << "]";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 3, 4};
    int arr2[] = {2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr2) / sizeof(arr[0]);
    mergingarr(arr, n, arr2, m);
    return 0;
}