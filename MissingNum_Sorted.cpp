#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int missing(int a[], int n)
{
    int miss = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            return miss=i+1;

        }
    }

    return miss;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[] = {1, 2,3, 4, 5};
    cout << "[" << missing(a, 4) << "]";

    return 0;
}