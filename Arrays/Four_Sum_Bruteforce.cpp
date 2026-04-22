#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void foursum(int arr[], int n, int sum)
{
    int first = 0;
    int second = 0;
    int third = 0;
    int fourt = 0;
    for (int i = 0; i < n; i++)
    {
        int f = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            int s = arr[j];
            for (int k = j + 1; k < n; k++)
            {
                int t = arr[k];
                for (int l = k + 1; l < n; l++)
                {
                    int add = arr[i]+arr[j]+arr[k]+arr[l];
                    if (sum == add)
                    {
                        first = f;
                        second = s;
                        third = t;
                        cout << "First Element:" << arr[i] << "\nSecond elemnt: " << arr[j] << "\nThird Elemnt:" << arr[k]<<"\nFourth elemnt:"<<arr[l];
                        cout << "\nThe sum is:" << sum;
                        cout << "\n\n";
                    }
                }
            }
        }
    }
    if (first || second || third || fourt)
    {

        return;
    }
    cout << "No sum Available";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 11;
    foursum(arr, n, k);
    return 0;
}