class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i=0; i<nums.size(); i++) sum+=nums[i];
        if (sum%2==1) return 0;
        unordered_set<int> prev, next;
        prev.insert(nums[0]);
        for (int i=1; i<nums.size(); i++)
        {
            for (auto it=prev.begin(); it!=prev.end(); it++) 
            {
                next.insert(*it+nums[i]);
                next.insert(*it-nums[i]);
            }
            //if (i<nums.size()-1&&next.count(sum/2)>0) return 1;
            prev=next;
            next.clear();
        }
        if (prev.count(0)>0) return 1;
        return 0;
    }
};