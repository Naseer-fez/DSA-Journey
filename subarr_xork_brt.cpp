#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int zorcont(int arr[], int n, int k)
{
int count=0;
for (int i = 0; i < n; i++)
{
    int prev=arr[i];
for (int j =i+1; j < n; j++)
{
    prev^=arr[j];
    if(prev==0){
        count++;
    }


}


}

return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {4, 2, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    cout << "[" << zorcont(arr, n, k) << "]";

    return 0;
}