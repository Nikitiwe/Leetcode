class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_set<int> s;
        float sum = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            s.insert(nums[i]);
            sum += nums[i];
        }
        sum /= (float)nums.size();
        int t = 1;
        t = max((int)sum, t);
        int j = 0;
        while (true)
        {
            if (s.count(t + j) == 0 && t+j > sum) return t+j;
            j++;
        }
        return -1;
    }
};