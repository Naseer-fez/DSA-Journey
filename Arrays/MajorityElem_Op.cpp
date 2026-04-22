#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int majorityelemnt(int arr[], int n)
{
    int element = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {

        if (element == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {

            element = arr[i];
            count = 1;
        }
    }
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            check++;
    }

    if (check > n / 2)
        return element;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    cout << "[" << majorityelemnt(arr, sizeof(arr) / sizeof(arr[0])) << "]";

    return 0;
}