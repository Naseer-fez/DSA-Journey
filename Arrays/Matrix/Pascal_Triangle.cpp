#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long  ncr(int n, int r)
{

    long long res = 1;

    for (int i = 0; i < n; i++)
    {
        res = res * (r - i);
        res = res / (i + 1);
    }
    return res;
}

void prtrow(int r)
{

    for (int i = 0; i < r; i++)
    {
        cout << ncr(i, r - 1);
        cout << "   ";
    }
    return;
}
void prtgap(int n){

for (int i = 0; i < n; i++)
{   
    cout << "  ";
}


}

void PascalTriangle(int rows)
{
    for (int i = 0; i < rows; i++)
    {   
        prtgap(rows-i-1);
        prtrow(i+1);
        cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PascalTriangle(9);
    return 0;
}