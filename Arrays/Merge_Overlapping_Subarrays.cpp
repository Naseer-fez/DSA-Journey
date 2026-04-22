#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergesub(std::vector<std::vector<int>> &arr)
{

    std::sort(arr.begin(), arr.end());
    // std::vector<std::vector<int>> samp;
    std::vector<std::vector<int>> samp = {{arr[0][0], arr[0][1]}};
    int ind = 0;
    for (int i = 1; i < arr.size() ; i++)
    {
       
            if ((samp[ind][1] >= arr[i ][0]))
            {

                samp[ind][1] = std::max(samp[ind][1], arr[i][1]);
            }
            else{
                ind++;
                samp.emplace_back(arr[i]);

            }
       
    }

for (const auto& row : samp) 
{
    for (int val : row) 
    {
        std::cout << "[" << val << "]";
    }
    std::cout << std::endl;
}


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::vector<std::vector<int>> arr = {{1, 3}, {3, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};

    mergesub(arr);
    return 0;
}