#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Maxiumsum(int arr[], int n)
{
    int min = -9999;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
        if (sum > min)
            min = sum;
        if (sum < 0)
            sum = 0;
    }

    return sum;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {-1, -3, 4, -1, -2, 1, 5, -3};
    cout << "[" << Maxiumsum(arr, sizeof(arr) / sizeof(arr[0])) << "]";

    return 0;
}