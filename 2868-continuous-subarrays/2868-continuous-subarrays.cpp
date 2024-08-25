class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=1;
        vector<int> next(5, 1), arr(5, 1);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]==nums[i-1]+2)
            {
                next[0]=1;
                next[1]=1;
                next[2]=arr[0]+1;
                next[3]=arr[0]+1;
                next[4]=arr[0]+1;
            }
            else if (nums[i]==nums[i-1]+1)
            {
                next[0]=1;
                next[1]=min(arr[1], arr[0])+1;
                next[2]=arr[1]+1;
                next[3]=arr[1]+1;
                next[4]=min(arr[1], arr[3])+1;
            }
            else if (nums[i]==nums[i-1])
            {
                next[0]=arr[0]+1;
                next[1]=arr[1]+1;
                next[2]=arr[2]+1;
                next[3]=arr[3]+1;
                next[4]=arr[4]+1;
            }
            else if (nums[i]==nums[i-1]-1)
            {
                next[0]=min(arr[3], arr[1])+1;
                next[1]=arr[3]+1;
                next[2]=arr[3]+1;
                next[3]=min(arr[3], arr[4])+1;
                next[4]=1;
            }
            else if (nums[i]==nums[i-1]-2)
            {
                next[0]=arr[4]+1;
                next[1]=arr[4]+1;
                next[2]=arr[4]+1;
                next[3]=1;
                next[4]=1;
            }
            else
            {
                next[0]=1;
                next[1]=1;
                next[2]=1;
                next[3]=1;
                next[4]=1;
            }
            ans+=next[2];
            arr=next;
        }
        return ans;
    }
};