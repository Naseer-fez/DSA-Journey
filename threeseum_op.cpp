#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void threesum(int arr[], int n, int sum)
{
    std::unordered_map<int, int> mp, cp;

    for (size_t i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    set<vector<int>> uniqueTriplets;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int fin = -(arr[i] + arr[j]);
            auto it = mp.find(fin);
            if (it != mp.end())
            {
                int cnt = 1;
                if (i == j)
                    cnt++;
                if (fin == i)
                    cnt++;
                if (it->second >= cnt)
                {
                    if (arr[i] <= arr[j] && arr[j] <= fin)
                    {
                        // cout << "The elemnts are:\n";
                        // cout << arr[i] << "\t" << arr[j] << "\t" << fin;
                        // cout << "\n"; thsi sdoe snto gurante unqiue elemnts
                        vector<int> triplet = {arr[i], arr[j], fin};
                        uniqueTriplets.insert(triplet);
                    }
                }
            }
        }
    }
  for (const auto& triplet : uniqueTriplets) {
    cout<<"The Elment are::";
    for (int num : triplet) {
      
        cout << num << "\t";
    }
    cout << "\n"; 
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