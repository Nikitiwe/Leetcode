class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int> zero(k+1, 0), cost(k+1, 0);
        cost[0]=nums.size()/2;
        int temp;
        for (int i=0; i!=nums.size()/2; i++)
        {
            zero[abs(nums[i]-nums[nums.size()-1-i])]++;
            temp=max(max(nums[i], nums[nums.size()-1-i]), k-min(nums[i], nums[nums.size()-1-i]));
            if (temp<k) cost[temp+1]++;
        }
        for (int i=1; i!=k+1; i++)
        {
            cost[i]=cost[i]+cost[i-1];
        }
        for (int i=0; i!=k+1; i++)
        {
            cost[i]-=zero[i];
        }
        return *min_element(cost.begin(), cost.end());
    }
};