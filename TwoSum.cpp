#include <vector>
#include <iostream>
using namespace std;

vector<int> TwoSum(vector<int> nums, int target)
{
    vector<int> result = {};
    int l = 0;
    int r = nums.size() - 1;
