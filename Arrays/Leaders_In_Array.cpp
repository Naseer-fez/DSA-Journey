#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void learder(int arr[], int n)
{
    int inx = 0;
    int max = -99999;
    int sampl[n];
    for (int i = n - 1; i >= 0; i--)
    {
        if (max < arr[i])
        {
            max = arr[i];
            sampl[inx++] = arr[i];
        }
    }
    for (int i = 0; i < inx; i++)
    {
            cout<<"["<<sampl[i]<<"]";


    }
    


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {12, 70, 34, 69, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    learder(arr, n);
    
}