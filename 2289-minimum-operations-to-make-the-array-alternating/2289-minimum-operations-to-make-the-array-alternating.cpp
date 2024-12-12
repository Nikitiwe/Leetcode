class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> m0, m1;
        for (int i=0; i<nums.size(); i+=2) m0[nums[i]]++;
        for (int i=1; i<nums.size(); i+=2) m1[nums[i]]++;
        int ans=nums.size(), a=-1, b=-1, c=-1, d=-1;
        for (auto i=m0.begin(); i!=m0.end(); i++)
        {
            if (a==-1) a=i->first;
            else if (b==-1)
            {
                b=i->first;
                if (m0[a]<m0[b]) swap(a, b);
            }
            else
            {
                if (i->second>=m0[a])
                {
                    b=a;
                    a=i->first;
                }
                else if (i->second>=m0[b])
                {
                    b=i->first;
                }
            }
        }
        for (auto i=m1.begin(); i!=m1.end(); i++)
        {
            if (c==-1) c=i->first;
            else if (d==-1)
            {
                d=i->first;
                if (m1[c]<m1[d]) swap(c, d);
            }
            else
            {
                if (i->second>=m1[c])
                {
                    d=c;
                    c=i->first;
                }
                else if (i->second>=m1[d])
                {
                    d=i->first;
                }
            }
        }
        if (a!=c) ans=min(ans, (int)nums.size()-m0[a]-m1[c]);
        if (a!=d) ans=min(ans, (int)nums.size()-m0[a]-m1[d]);
        if (b!=c) ans=min(ans, (int)nums.size()-m0[b]-m1[c]);
        return ans;
    }
};