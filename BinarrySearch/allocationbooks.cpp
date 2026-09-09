#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxbookalocated(int arr[], int n, int students)
{

    if (students > n)
        return -1;

    // int minofmax = *std::max_element(arr, arr + n);
    // if (students == n)
    //     return minofmax;
    // int sumofthearray = std::accumulate(arr, arr + n, 0);
    int sumofthearray = 0;
    int minofmax = -999;
    for (int i = 0; i < n; i++)
    {
        sumofthearray += arr[i];
        minofmax = std::max(minofmax, arr[i]);
    }
    int maxofmin = -9999;
    while (minofmax < sumofthearray)
    {
        int mid = minofmax + (sumofthearray - minofmax) / 2;

        int pagesallocated =1;
        int pagessum = 0;
        for (int i = 0; i < n; i++)
        {
            pagessum += arr[i];
            if (pagessum <= mid)
            {
            }
            else
            {
                pagesallocated++;
                pagessum = arr[i];
            }
        }
        if (pagesallocated <= students)
        {
            maxofmin = mid;
            sumofthearray = mid - 1;
        }
        else
        {
            minofmax = mid + 1;
        }
    }

    return maxofmin;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {25, 46, 28, 49, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << maxbookalocated(arr, n, 4);

    return 0;
}