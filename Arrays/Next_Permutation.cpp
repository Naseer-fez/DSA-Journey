#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void NextPer(int arr[], int n)
{
    int idx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        std::reverse(arr, arr + n);
        return;
    }
    for (int i = n - 1; i > idx; i--)
    {
        if (arr[i] > arr[idx])
        {
            std::swap(arr[i],arr[idx]);
            break;
        }
    }
    // std::reverse(arr+idx,arr+n);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
      for (int i = 0; i < n; i++)
    {
        cout << "[" << arr[i] << "]";
    }
    cout<<"\n";
    NextPer(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << "[" << arr[i] << "]";
    }

    return 0;
}