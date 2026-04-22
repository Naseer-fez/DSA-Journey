#include<iostream>
#include <bits/stdc++.h>
using namespace std;



void Arrangeing(int arr[],int n){

int pos[n/2];
int neg[n/2];
int p=0;
int ng=0;
for (int i = 0; i < n; i++)
{
    if(arr[i]>0)pos[p++]=arr[i];
    else neg[ng++]=arr[i];
}
int idx=0;
for (int i = 0; i < ng; i++)
{
    arr[idx++]=neg[i];

}
for (int i = 0; i < p; i++)
{
    arr[idx++]=pos[i];
}








}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]={-1,1,-2,2,2,-3,-3};
    int n=sizeof(arr)/sizeof(arr[0]);
    Arrangeing(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<"["<<arr[i]<<"]";
    }
    




    return 0;
}