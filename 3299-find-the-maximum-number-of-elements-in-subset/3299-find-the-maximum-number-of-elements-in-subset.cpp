class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=1;
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++) m[nums[i]]++;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->first==1)
            {
                if (i->second%2==1) ans=max(ans, i->second);
                else ans=max(ans, i->second-1);
            }
            else if (i->second>1)
            {
                int count=1;
                long t=(long)i->first*i->first;
                while (m.count(t)>0)
                {
                    ans=max(ans, count*2+1);
                    if (m[t]==1||t>32000) break;
                    t*=t;
                    count++;
                }
            }
        }
        return ans;
    }
};