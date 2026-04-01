#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void BestTime(int arr[],int n){

int minp=arr[0];
int profit=0;

for (int i = 1; i < n; i++)
{
    int cost=arr[i]-minp;
    profit=max(profit,cost);
    minp=min(minp,arr[i]);



}

cout<<"The Min price is "<<minp<<"\nProfit is "<<profit;

} 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]={7,1,2,5,3,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    BestTime(arr,n);

    return 0;
}