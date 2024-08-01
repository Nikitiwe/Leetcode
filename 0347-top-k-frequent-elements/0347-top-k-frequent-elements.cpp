class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++)
        {
            m[nums[i]]++;
        }
        vector<int> ans, temp;
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            temp.push_back(it->second);
        }
        sort(temp.begin(), temp.end());
        int a=temp[temp.size()-k];
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            if (it->second>=a) ans.push_back(it->first);
        }
        return ans;
    }
};