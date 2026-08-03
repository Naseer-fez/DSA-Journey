#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 4

void setzero(int arr[][N], int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                for (int k = 0; k < m; k++)
                {
                    if (arr[i][k] == 0)
                        continue;
                    arr[i][k] = -1;
                }
                for (int k = 0; k < m; k++)
                {
                    if (arr[k][j] == 0)
                        continue;
                    arr[i][k] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == -1)
                arr[i][j] = 0;
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