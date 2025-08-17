#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ThreeSum(vector<int> nums);

int main()
{
    vector<int> nums = {0, -1, 2, -3, 1};
    vector<vector<int>> result = ThreeSum(nums);
