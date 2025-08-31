#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res = {};
        unordered_map<string, vector<string>> table = {};

        for (string s : strs)
        {
            string copy = s;
            sort(copy.begin(), copy.end());
            table[copy].push_back(s);
        }
        for (auto it = table.begin(); it != table.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};