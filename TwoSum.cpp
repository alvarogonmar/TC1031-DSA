#include <vector>
#include <iostream>
using namespace std;

vector<int> TwoSum(vector<int> nums, int target)
{
    vector<int> result = {};
    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
        int op = nums[l] + nums[r];
        if (op == target)
        {
            result.push_back(l);
            result.push_back(r);
            return result;
        }
        else if (op < target)
