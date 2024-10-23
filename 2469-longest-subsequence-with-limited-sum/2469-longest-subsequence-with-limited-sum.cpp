class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(), nums.end());
        int sum=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            nums[i]=sum;
        }
        for (int i=0; i!=q.size(); i++)
        {
            int l=1;
            while (l<nums.size()&&nums[l]<=q[i]) l++;
            if (nums[0]>q[i]) l=0;
            q[i]=l;
        }
        return q;
    }
};