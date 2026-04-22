#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void threesum(int arr[], int n, int sum)
{
    int first = 0;
    int second = 0;
    int third = 0;
    for (int i = 0; i < n; i++)
    {
        int f = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            int s = arr[j];
            for (int k = j + 1; k < n; k++)
            {
                int t = arr[k];
                int add = f + s + t;
                if (sum == add)
                {
                    first = f;
                    second = s;
                    third = t;
                    cout << "First Element:" << first << "\nSecond elemnt: " << second << "\nThird Elemnt:" << third;
                    cout << "\nThe sum is:" << sum;
                    cout<<"\n\n";
                }
            }
        }
    }
    if (first || second || third)
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
    threesum(arr, n, k);
    return 0;
}