#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define M 3

void Spiral(int arr[][M], int n, int m)
{
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = m - 1;

    while (left <= right && top <= bottom)
    {

        for (int i = left; i <= right; i++)
        {
            cout << "[" << arr[top][i] << "]";
        }
        top++; // right =2 ,left=0
        for (int i = top; i <= bottom; i++)
        {
            cout << "[" << arr[i][right] << "]";
        }
        right--; // bottom =2 , top =0
        for (int i = right; i >= left; i--)
        {
            cout << "[" << arr[bottom][i] << "]";
        }
        bottom--; // right =2 left =1
        for (int i = bottom; i >= top; i--)
        {

            cout << "[" << arr[i][left] << "]";
        }
        left++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int matrix[][M] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}

    };
    int n = sizeof(matrix) / sizeof(matrix[0]);
    int m = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    cout << "\n";
    Spiral(matrix, n, m);

    return 0;
}