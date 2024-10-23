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
            int l=0;
            while (l+1<nums.size()&&nums[l+1]<=q[i]) l++;
            if (nums[0]>q[i]) l=-1;
            q[i]=l+1;
        }
        return q;
    }
};