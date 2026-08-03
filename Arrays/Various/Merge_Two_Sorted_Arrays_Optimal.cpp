#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergingarr(int arr[], int n, int arr2[], int m)
{

    for (int i = 0; i < n; i++)
        cout << "[" << arr[i] << "]";

    for (int i = 0; i < m; i++)
        cout << "[" << arr2[i] << "]";
    cout << "\n";
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // Now time for the condtion and placemnts
            if (left < n && right >= n)
            {
                // Both are on diffent arrays
                if (arr[left] > arr2[right-n])
                {
                    std::swap(arr[left], arr2[right-n]);
                }
            }
            else if (left >= n)
            { // Both are on the second array
                if (arr2[left-n] > arr2[right-n])
                {
                    std::swap(arr2[left-n], arr2[right-n]);
                }
            }
            else
            {
                if (arr[left] > arr[right])
                {
                    std::swap(arr[left], arr[right]);
                }
            }
            left++;
            right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }

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