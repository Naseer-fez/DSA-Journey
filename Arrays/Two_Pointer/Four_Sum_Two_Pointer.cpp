#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void foursum(int arr[], int n, int sum)
{
    std::sort(arr, arr + n);

    for (int i = -1; i < n-3; i++)
    {   
        if(i>0 && arr[i]==arr[i-1])continue;// For duplicates
        for (int j = i+1; j < n-2; j++)
        {
            if(j>i+1 && arr[j]==arr[j-1])continue;// For duplicates
            int left=j+1;
            int right=n-1;
            int su=arr[i]+arr[j];
            while (left<right)
            {
                //Now the tow pointer    
                int tot=arr[left]+arr[right]+su;
                if(tot==sum){
                    cout<<"["<<arr[i]<<"]";
                    cout<<"["<<arr[j]<<"]";
                    cout<<"["<<arr[left]<<"]";
                    cout<<"["<<arr[right]<<"]";
                    cout<<endl;
                    while(left<right && arr[left]==arr[left+1])left++;
                    while(left<right && arr[right]==arr[right-1])right--;
                    
                    left++;
                    right--;
                }
                else if(tot<sum){
                    left++;
                }
                else{
                    right--;
                }

            }
            




        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {-1, 0, 1, 2, -1, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 0;
    foursum(arr, n, k);
    return 0;
}