class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
        }
        return (abs(goal-sum)+limit-1)/limit;
    }
};