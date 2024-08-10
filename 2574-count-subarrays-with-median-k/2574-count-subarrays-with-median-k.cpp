class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int id=0;
        while (nums[id]!=k) id++;
        unordered_map<int, int> l, r;
        int temp=0;
        for (int i=id+1; i<nums.size(); i++)
        {
            if (nums[i]>k) temp++;
            else temp--;
            r[temp]++;
        }
        r[0]++;
        temp=0;
        for (int i=id-1; i>=0; i--)
        {
            if (nums[i]<k) temp++;
            else temp--;
            l[temp]++;
        }
        l[0]++;
        int ans=0;
        for (auto i=r.begin(); i!=r.end(); i++)
        {
            /*if (l.count(i->first)!=0)*/ ans+=(i->second)*(l[i->first]);
            /*if (l.count(i->first-1)!=0)*/ ans+=(i->second)*(l[i->first-1]);
        }
        return ans;
    }
};