#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int missing(int a[], int n)
{   int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum^=i+1;
        sum^=a[i];


    }
return (sum^(n+1));

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[] = {5, 1, 2, 4};
    cout << "[" << missing(a, sizeof(a) / sizeof(a[0])) << "]";

    return 0;
}