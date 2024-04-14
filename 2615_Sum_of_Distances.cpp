// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> nums = {1, 3, 1, 1, 2};

    int n = nums.size();
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < n; i++)
    {
        map[nums[i]].push_back(i);
        ;
    }
    vector<long long> arr(n, 0);

    // for (int i = 0; i < n; i++)
    // {
    //     int size = map[nums[i]].size();
    //     for (int j = 0; j < size; j++)
    //     {
    //         int index = map[nums[i]][j];
    //         if (i != index)
    //         {
    //             arr[i] += abs(i - index);
    //         }
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        int size = map[nums[i]].size();
        long long sum = 0;
        long long left_sum = 0, right_sum = 0;

        if (arr[i] != 0)
            continue;

        for (int j = 0; j < size; j++)
            sum += map[nums[i]][j];

        for (int j = 0; j < size; j++)
        {
            long long index = map[nums[i]][j];
            right_sum = sum - left_sum - index;
            arr[index] = ((right_sum - (size - j - 1) * index) + (j * index - left_sum));
            left_sum += index;
        }
    }

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}