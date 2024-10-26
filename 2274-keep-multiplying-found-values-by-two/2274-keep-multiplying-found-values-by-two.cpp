class Solution {
public:
    int findFinalValue(vector<int>& nums, int n) {
        unordered_set<int> m(nums.begin(), nums.end());
        while (m.count(n)>0)
        {
            n*=2;
        }
        return n;        
    }
};