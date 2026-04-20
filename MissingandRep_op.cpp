#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void missingnun(int arr[], int n)
{
    int repeat = 0, missing = 0;
    int sum = (n*(n+1))/2;
    int sqrsum = (n * (n + 1) * (2 * n + 1)) / 6;
    int actualsum=0;
    int actualsqr=0;
    for (int i = 0; i < n; i++)
    {
        actualsqr +=( arr[i] * arr[i]);
        actualsum+=arr[i];
    }
    int z=sqrsum-actualsqr; //x-y=z
    int  k=sum-actualsum; // (x+y)(x-y)=k
    int a= k/(z); //(x+y)=k/(x-y)=> a=(x+y)
    int b=z; // b=x-y
    int x=repeat=(a+b)/2; //x+y+x-y=2x/2=> value=x
    int y=missing=z-x; // y= x-x+y
    cout<<"The missing:{"<<y<<"}\n";
    cout<<"The Repeat:{"<<x<<"}\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, 5, 2, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    missingnun(arr, n);

    return 0;
}