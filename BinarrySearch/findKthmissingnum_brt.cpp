#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int brute(int arr[], int n, int element)
{
    int find = 0;
    int index=0;
    for (int i = 1; i < arr[n-1]; i++)
    {
        if(arr[index]>i){
            find++;
            if(find==element)return i;
            continue;
        }
        index++;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {2, 3, 4, 7, 11};
    int n = sizeof(arr) / sizeof(int);

    int value = brute(arr, n, 4);
    cout << value;
}