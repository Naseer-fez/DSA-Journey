#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int target)
{

    // The condition is ,  arr[i-1]<arr[i]>arr[i+1]
    //-1 and n elment is -infinity
    int low = 1;
    int high = target;
    int mid;
    int ans=1;
    while (low<=high)
    {
        mid=low + (high - low) / 2;
        int vlaue=mid*mid;
        
        if(vlaue==target){
            return mid;
        }
        if(vlaue>target){
            high=mid-1;
        }else{
            low=mid+1;
            ans=mid;
            
        }
       
    }
    return ans;    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n, 181);
    cout << value;
}