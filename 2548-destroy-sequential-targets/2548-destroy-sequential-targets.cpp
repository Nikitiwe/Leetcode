class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int ,int> m, arr;
        int t, ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            t=nums[i]%space;
            m[t]++;
            if (arr.count(t)>0) arr[t]=min(arr[t], nums[i]);
            else arr[t]=nums[i];
        }
        t=0;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second>t)
            {
                t=i->second;
                ans=arr[i->first];
            }
            else if (i->second==t)
            {
                ans=min(ans, arr[i->first]);
            }
        }
        return ans;
    }
};