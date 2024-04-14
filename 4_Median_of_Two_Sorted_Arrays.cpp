// #include<iostream>
// #include<vector>
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    double median = 0;
    vector<int> nums(nums1);
    nums.insert(nums.end(), nums2.begin(), nums2.end());
    sort(nums.begin(), nums.end());

    int n = nums.size();
    if (n % 2 != 0)
    {
        median = nums[(n - 1) / 2];
    }
    else
    {
        median += nums[n / 2];
        median += nums[n / 2 - 1];
        median /= 2;
    }
    return median;
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    double median = findMedianSortedArrays(nums1, nums2);
    // for (auto i = 0; i < nums1.size(); i++)
    //     cout << nums1[i] << " ";
    // cout << endl;
    // for (auto i = 0; i < nums2.size(); i++)
    //     cout << nums2[i] << " ";
    // cout << endl;
    cout << median << endl;
    return 0;
}