#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[],int n){

int low=0;
int mid=low;
int high=n-1;
int i=0;
while (mid<=high)
{
    

    if(arr[mid]==0){
        std::swap(arr[low++],arr[mid++]);
        i++;
    }
    else if(arr[mid]==1){


    mid++;
        i++;

    }
    else{

        std::swap(arr[mid],arr[high--]);
   

    }



}



}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[]={0,0,1,2,1,0,1};
    sort012(arr,sizeof(arr)/sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {

        cout<<"["<<arr[i]<<"]";

    }
    

    return 0;
}