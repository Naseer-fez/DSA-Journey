#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 4

void setzero(int arr[][N], int n, int m)
{

    int common = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                if (j!=0){

                    arr[0][j]=0;
                }
                else{
                    common=0;
                }

            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] != 0)
            {
                if (arr[i][0] == 0 || arr[0][j] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }
    // Now time for the first row and coloumn

    if (arr[0][0] == 0)
    {

        for (int i = 0; i < m; i++)
        {
            arr[0][i] = 0;
        }
    }
    if (common == 0)
    {
        for (int i = 0; i < n; i++)
        {
            arr[n][0] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int matrix[][N] = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}};
    int n = sizeof(matrix) / sizeof(matrix[0]);
    int m = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    setzero(matrix, n, m);

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