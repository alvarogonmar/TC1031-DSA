#include <vector>
#include <iostream>
using namespace std;

vector<int> TwoSum(vector<int> nums, int target)
{
    vector<int> result = {};
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int op = nums[i] + nums[j];
            if (op = nums[i] + nums[j])
            {
                result.push_back(i);
