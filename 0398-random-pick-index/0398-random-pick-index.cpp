class Solution {
public:
    unordered_map<int, int> m;
    vector<vector<int>> arr;
    Solution(vector<int>& nums) {
        for (int i=0; i!=nums.size(); i++)
        {
            if (m.count(nums[i]) == 0)
            {
                m[nums[i]] = arr.size();
                arr.push_back({i});
            }
            else arr[m[nums[i]]].push_back(i);
        }
    }
    
    int pick(int target) {
        int d = arr[m[target]].size();
        int id = rand()%d;
        return arr[m[target]][id];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */