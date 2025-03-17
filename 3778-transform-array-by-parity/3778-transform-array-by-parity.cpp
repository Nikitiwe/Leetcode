class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]%2==0) a++;
            else b++;
        }
        vector<int> ans;
        for (int i=0; i!=a; i++) ans.push_back(0);
        for (int i=0; i!=b; i++) ans.push_back(1);
        return ans;
    }
};