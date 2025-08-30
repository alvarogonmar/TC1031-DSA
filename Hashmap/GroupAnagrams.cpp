class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res = {};
        unordered_map<string, vector<string>> table = {};
