#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void majority(int arr[], int n)
{
    int count = 0;
    int con = 0;
    int elem = arr[0];
    int elem2 = arr[1];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == elem)
        {
            count++;
        }
        else if (elem2 == arr[i])
        {

            count++;
        }
        else if (count == 0)
        {
            elem = arr[i];
            count = 1;
        }
        else if(con==0){
            elem2=arr[i];
            con=1;
        }
        else{
            con--;
            count++;
        }


    }
    count = 0;
    con = 0;
    for (int i = 0; i < n; i++)
    {
        if (elem == arr[i])
            count++;
        if (elem2 == arr[i])
            con++;
    }
    if (count > (n / 3))
        cout << "\n"
             << elem;
    if (con > (n / 3))
        cout << "\n"
             << elem2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {3, 2, 3, 4, 3, 5, 2, 2, 3, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    majority(arr, n);
    // cout << "[" << majority(arr, n) << "]";

    return 0;
}