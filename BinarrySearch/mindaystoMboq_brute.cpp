#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary(int arr[], int n, int boq, int adjacent)
{
    int count = 0;
    int elm=100;
    for (int i = 0; i < n; i++)
    {
        int currentelem = arr[i];
        int adj = 0;
        int boquo = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] <= currentelem)
            {
                adj++;

                if (adj == adjacent)
                {
                    adj = 0;
                    boquo++;
                    if (boquo == boq)
                    {
                        elm= std::min(elm,currentelem);
                        boquo=0;
                        
                    }
                }
            }else{
                adj=0;
            }

        }
    }
    return elm;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {7, 7, 7, 7, 13, 11, 12, 7};
    int n = sizeof(arr) / sizeof(int);

    int value = binary(arr, n, 2, 3);
    cout << value;
}
