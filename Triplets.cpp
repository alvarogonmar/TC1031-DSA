#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ThreeSum(vector<int> nums);

int main()
{
    vector<int> nums = {0, -1, 2, -3, 1};
    vector<vector<int>> result = ThreeSum(nums);
    cout << "Triplets encontrados:" << endl;
    for (const auto &triplet : result)
    {
        cout << "[";
        for (int i = 0; i < triplet.size(); ++i)
        {
            cout << triplet[i];
            if (i < triplet.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}
#include <vector>
using namespace std;

vector<vector<int>> findPairs(vector<int> nums, int start, int target);

vector<vector<int>> ThreeSum(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> triplets = {};

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            return triplets;
        }
        if (i > 0 and nums[i] == nums[i - 1])
        {
            continue;
        }
        // Retornar todos los pares
        vector<vector<int>> pairs = findPairs(nums, i + 1, -nums[i]);
        for (int j = 0; j < pairs.size(); j++)
        {
            triplets.push_back({nums[i], pairs[j][0], pairs[j][1]});
        }
    }
    return triplets;
