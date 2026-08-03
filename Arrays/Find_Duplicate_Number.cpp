#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Numtwic(int a[], int n)
{
    int XOrCh = 0;
    for (int i = 0; i < n; i++)
    {
    XOrCh^=a[i];
    
    }
return XOrCh;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int a[] = {1, 1, 2, 3, 3, 4, 4,2};
    cout << "[" << Numtwic(a, sizeof(a) / sizeof(a[0])) << "]";

    return 0;
}