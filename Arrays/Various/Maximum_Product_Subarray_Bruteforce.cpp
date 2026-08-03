#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxprd(int arr[], int n)
{
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        int innprod = 1;
        for (int j = i + 1; j < n; j++)
        {
            innprod *= arr[j];
            prod = std::max(prod, innprod);
        }
    }

    return prod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, -1, 3, 4, 0,-1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "[" << maxprd(arr, n) << "]";

    return 0;
}