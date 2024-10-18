class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> m;
        for (int i=0; i!=nums.size(); i++)
        {
            m.insert(nums[i]);
            while (nums[i]%10==0) nums[i]/=10;
            string s=to_string(nums[i]);
            reverse(s.begin(), s.end());
            m.insert(stoi(s));
        }
        return m.size();
    }
};