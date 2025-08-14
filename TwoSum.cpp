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
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return result;
}

int main()
{
    vector<int> result = TwoSum({-5, 2, 3, 4, 6}, 7);

    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
