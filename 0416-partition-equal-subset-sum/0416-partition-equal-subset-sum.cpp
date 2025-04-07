class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i=0; i<nums.size(); i++) sum+=nums[i];
        if (sum%2==1) return 0;
        sum /= 2;
        unordered_set<int> prev, next;
        prev.insert(0);
        for (int i=0; i<nums.size(); i++)
        {
            for (auto it=prev.begin(); it!=prev.end(); it++) 
            {
                next.insert(*it+nums[i]);
            }
            if (next.count(sum)>0) return 1;
            prev=next;
        }
        // if (prev.count(0)>0) return 1;
        return 0;
    }
};