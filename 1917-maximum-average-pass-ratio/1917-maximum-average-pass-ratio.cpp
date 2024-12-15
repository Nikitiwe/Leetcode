class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& nums, int k) {
        double ans=0;
        priority_queue<pair<double, pair<int, int>>> q;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i][0]==nums[i][1]) ans+=1;
            else
            {
                q.push({(double)(nums[i][1]-nums[i][0])/((double)nums[i][1]*(nums[i][1]+1)), {nums[i][0], nums[i][1]}});
                ans+=(double)nums[i][0]/nums[i][1];
            }
        }
        if (q.size()>0) for (int i=0; i!=k; i++)
        {
            pair<int, int> p=q.top().second;
            double t=q.top().first;
            q.pop();
            ans+=t;
            p.first++;
            p.second++;
            q.push({(double)(p.second-p.first)/((double)p.second*(p.second+1)), p});
        }
        return ans/nums.size();
    }
};