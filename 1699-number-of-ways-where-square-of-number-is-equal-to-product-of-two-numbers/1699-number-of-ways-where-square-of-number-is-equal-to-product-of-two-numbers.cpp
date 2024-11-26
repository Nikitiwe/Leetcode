class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        unordered_map<long, int> m, n;
        for (int i=0; i!=nums1.size(); i++) m[(long)nums1[i]*nums1[i]]++;
        for (int i=0; i!=nums2.size(); i++)
        {
            for (int j=i+1; j<nums2.size(); j++)
            {
                ans+=m[(long)nums2[i]*nums2[j]];
            }
        }
        m=n;
        for (int i=0; i!=nums2.size(); i++) m[(long)nums2[i]*nums2[i]]++;
        for (int i=0; i!=nums1.size(); i++)
        {
            for (int j=i+1; j<nums1.size(); j++)
            {
                ans+=m[(long)nums1[i]*nums1[j]];
            }
        }
        return ans;
    }
};