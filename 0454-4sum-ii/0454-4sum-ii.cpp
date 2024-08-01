class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans=0;
        unordered_map<int, int> s1, s2;
        for (int i=0; i!=nums1.size(); i++)
        {
            for (int j=0; j!=nums2.size(); j++)
            {
                s1[nums1[i]+nums2[j]]++;
            }
        }
        for (int i=0; i!=nums3.size(); i++)
        {
            for (int j=0; j!=nums4.size(); j++)
            {
                s2[-nums3[i]-nums4[j]]++;
            }
        }
        for (auto i=s1.begin(); i!=s1.end(); i++)
        {
            ans+=s2[i->first]*(i->second);
        }
        return ans;
    }
};