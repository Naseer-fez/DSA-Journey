#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestsubarray(int a[], int n, int k)
{   int s,e;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k < j; k++)
                sum += a[k];
            if (sum == k)
            {
                s=i;
                e=j;
            }
        }
    }
    cout<<s<<e<<"\n";
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[] = {1, 1, 1, 3, 4, 1};
    cout << "[" << longestsubarray(a, sizeof(a) / sizeof(a[0]), 4) << "]";

    return 0;
}