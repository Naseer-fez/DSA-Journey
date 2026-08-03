#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int Twosum(int arr[],int n,int k){


std:: unordered_map<int,int> m;
int in=0;
for (int i = 0; i < n; i++)
{
    
m[in++]=arr[i];

}

for (int i = 0; i < n; i++)
{
    int el=m[i];
    int search=k-el;
    auto src=m.find(search);
if (src!= m.end()){
    cout<< "["<<el<<" "<<src->first<<"] "; 
}





}



return 0;

} 





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]={1,23,4,5,6};
    int k=3;
    cout<<Twosum(arr,sizeof(arr)/sizeof(arr[0]),k);


    return 0;
}