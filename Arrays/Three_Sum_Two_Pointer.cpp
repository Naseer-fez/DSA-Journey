#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void threesum(int arr[], int n, int sum)
{

    std::sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        int fr = arr[i];
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int curnt = arr[i] + arr[left] + arr[right];
            if (curnt == sum)
            {

                cout << arr[i] << "\t" << arr[left] << "\t" << arr[right] << "\n";
                    while (left<right && arr[left]==arr[left+1])
                    {
                        left++;
                    }
                    while (left<right && arr[right]==arr[right-1])
                    {
                        right--;
                    }
                    



                left++;
                right--;
            }
            else if(curnt<0){
                left++;

            }
            else{
                right--;
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
    threesum(arr, n, k);
    return 0;
}