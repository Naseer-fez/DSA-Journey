#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int consq1s(int a[], int n)
{
    int count = 0;
    int maxcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            count++;
        else
        {
            if (maxcount < count)
                maxcount = count;
            count = 0;
        }
    }
    return std::max(maxcount,count);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int a[] = {1, 1,  1, 1, 1, 1, 1, 1, 1, 1};
    cout << "[" << consq1s(a, sizeof(a) / sizeof(a[0])) << "]";

    return 0;
}