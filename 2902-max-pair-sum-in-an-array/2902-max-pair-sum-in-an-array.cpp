class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<priority_queue<int>> arr(10, priority_queue<int> ());
        int ans=-1;
        for (int i=0; i!=nums.size(); i++)
        {
            string s=to_string(nums[i]);
            int m=0;
            for (int j=0; j!=s.size(); j++) m=max(m, s[j]-'0');
            arr[m].push(nums[i]);
        }
        for (int i=0; i!=10; i++)
        {
            
            if (arr[i].size()>1)
            {
                int a=arr[i].top(), b;
                arr[i].pop();
                b=arr[i].top();
                ans=max(ans, a+b);
            }
        }
        return ans;
    }
};