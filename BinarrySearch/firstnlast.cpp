#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int last(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (first == -1)
    {
        cout << "No elemnt exist";
        return -1;
    }
    return first;
}

int first(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (first == -1)
    {
        cout << "No elemnt exist";
        return -1;
    }
    return first;
}
void firstnlast(int arr[], int n, int target)
{
    int v = last(arr, n, target);
    if (v != -1)
        cout << "LastElment is " << v;
    else
    {
        cout << "No elemnt is found!!!!!!!";
        return;
    }
    v = first(arr, n, target);
    if (v != -1)
        cout << "\nFirst element is:" << v;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {2, 8, 8, 8, 12, 16, 23};
    int n = sizeof(arr) / sizeof(int);
    std::sort(arr, arr + n);
    firstnlast(arr, n, 8);
}