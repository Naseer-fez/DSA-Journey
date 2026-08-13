#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int days)
{
    int low = *std::max_element(arr, arr + n);
    int high = std::accumulate(arr, arr + n, 0);
    int currentcapacity = 9999;
    int mid;
    int totalweight = high;
    // Assuiing it is a sorted array , if not just lop for ht emax elemnt

    while (low <= high)
    {
        mid = low + (high - low) / 2; //simple 
        int currentday = 0;
        int sum = 0;
        bool possible=true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] + sum > mid)
            {
                sum = 0;
                currentday++;

                if (arr[i] > mid)
                {
                    possible=false;
                    continue;
                }
            }

            sum += (arr[i]);
            
        }
        if ((currentday <= days) && (possible))
        {
            // totalweight = min(totalweight, mid);
            currentcapacity = std::min(currentcapacity, mid);
        }
        if (currentday<days)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return currentcapacity;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n, 5);
    cout << value;
}