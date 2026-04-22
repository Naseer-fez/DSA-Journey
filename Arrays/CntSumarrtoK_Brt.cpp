#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Arrsumcount(int arr[], int n,int k)
{
    int count=0;
    
    for (int i = 0; i < n; i++)
    {   int sum=arr[i];
        for (int j = i+1; j < n; j++)
        {
            sum=+arr[j];
            if(sum==k){
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
    int arr[]={1,2,-1,3,4,-1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"["<<Arrsumcount(arr,n,3)<<"]";


    return 0;
}