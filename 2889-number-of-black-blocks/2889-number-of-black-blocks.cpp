class Solution {
public:
    vector<long long> countBlackBlocks(int mm, int n, vector<vector<int>>& nums) {
        vector<long long> ans(5, 0);
        unordered_set<long long> m;
        long long d=1000000;
        for (int i=0; i!=nums.size(); i++)
        {
            long long t=nums[i][0];
            t*=d;
            t+=nums[i][1];
            m.insert(t);
        }
        for (int i=0; i!=nums.size(); i++)
        {
            long long t=nums[i][0];
            t*=d;
            t+=nums[i][1];
            long long ru=1, rd=1, lu=1, ld=1;
            if (m.count(t+1)>0) {ru++; rd++;}
            if (m.count(t-1)>0) {lu++; ld++;}
            if (m.count(t-d)>0) {ru++; lu++;}
            if (m.count(t+d)>0) {rd++; ld++;}
            if (m.count(t+d+1)>0) rd++;
            if (m.count(t+d-1)>0) ld++;
            if (m.count(t-d+1)>0) ru++;
            if (m.count(t-d-1)>0) lu++;

            if (nums[i][0]<mm-1&&nums[i][1]>0) ans[ld]++;
            if (nums[i][0]<mm-1&&nums[i][1]<n-1) ans[rd]++;
            if (nums[i][0]>0&&nums[i][1]>0) ans[lu]++;
            if (nums[i][0]>0&&nums[i][1]<n-1) ans[ru]++;
        }
        ans[2]/=2;
        ans[3]/=3;
        ans[4]/=4;
        ans[0]=(long long)(mm-1)*(n-1)-ans[1]-ans[2]-ans[3]-ans[4];
        return ans;
    }
};