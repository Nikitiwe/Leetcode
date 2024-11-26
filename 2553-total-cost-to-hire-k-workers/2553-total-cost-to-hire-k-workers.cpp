class Solution {
public:
    long long totalCost(vector<int>& nums, int k, int c) {
        priority_queue<long> m;
        long long ans=0;
        int l=0, r=nums.size()-1;
        while (l<c)
        {
            m.push((long)1000000000000-(long)nums[l]*1000000-l);
            l++;
        }
        while (r>=l&&r>=nums.size()-c)
        {
            m.push((long)1000000000000-(long)nums[r]*1000000-r);
            r--;
        }
        for (int i=0; i!=k; i++)
        {
            long t=m.top();
            m.pop();
            t*=-1;
            t+=1000000000000;
            long d=t%1000000;
            t-=d;
            t/=1000000;
            ans+=t;
            if (d<l&&l<=r)
            {
                m.push((long)1000000000000-(long)nums[l]*1000000-l);
                l++;
            }
            else if (r>=l)
            {
                m.push((long)1000000000000-(long)nums[r]*1000000-r);
                r--;
            }
        }
        return ans;
    }
};