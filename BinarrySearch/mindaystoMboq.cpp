#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int boq, int adjacent)
{
    int count = 0;
    int elm = 100;
    int low = 0;
    int high = *std::max_element(arr, arr + n);
    while (low <= high)
    {
        int mid=(low+high)/2;
        int adj = 0;
        int boquo = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] <= mid)
            {
                adj++;

                if (adj == adjacent)
                {
                    adj = 0;
                    
                    boquo++;
                   
                }
            }
            else
            {
                adj = 0;
                //Binarry search code
              
            }
        }
        if(boquo>=boq){
            elm = mid; 
            high=mid-1;
        }else{
            low=mid+1;
        }
        


    }
    return elm;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {7, 7, 7, 7, 13, 8, 19, 7};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n, 2, 3);
    cout << value;
}
