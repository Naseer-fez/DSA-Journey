#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countinversion(int *arr, int n)
{

    
    int count = 0;
    for (int i = 0; i < n; i++)
    {   int c=0;
        for (int j = i+1; j < n; j++)
        {
                if(arr[i]>arr[j]){
                    c++;
                }

        }
        count+=c;

    }
    


    cout << "{" << count << "}";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, 5, 2, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    countinversion(arr, n);

    return 0;
}