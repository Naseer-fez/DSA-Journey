#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int majority(int arr[], int n)
{
    int count = 0;
    int elem = arr[0];
    for (int i = 1; i < n; i++)
    {

        if (arr[i] == elem)
        {
            count++;
        }
        else
            count--;
        if (count == 0)
        {
            elem = arr[i];
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (elem == arr[i])
            count++;
    }

    if(count>n/3)return elem;
    else return 0;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "[" << majority(arr, n) << "]";

    return 0;
}