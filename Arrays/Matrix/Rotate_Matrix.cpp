#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 3

void rotatemat(int arr[][N], int n, int m)
{

    for (int i = 0; i < n ; i++)
    {
        for (int j = i+1; j < m ; j++)
        {   
            // for (int j = 0; j < m ; j++){  //This also work s, ut dont over complicte it 
            // if (i < j)
            //     continue;
            std::swap(arr[i][j], arr[j][i]);
        }
    }
for (int i = 0; i < n; i++)
{
    std::reverse(arr[i],arr[i]+m);
}


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int matrix[][N] = {
        {1,2,3,},
        {4,5,6},
        {7,8,9}

    };
    int n = sizeof(matrix) / sizeof(matrix[0]);
    int m = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "[" << matrix[i][j] << "]";
        }
        cout << "\n";
    }
    cout << "\n";
    rotatemat(matrix, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "[" << matrix[i][j] << "]";
        }
        cout << "\n";
    }

    return 0;
}