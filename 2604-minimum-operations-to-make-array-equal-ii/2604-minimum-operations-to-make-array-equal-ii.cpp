class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long sum=0;
        if (k==0)
        {
            for (int i=0; i!=nums1.size(); i++)
            {
                if (nums1[i]!=nums2[i]) return -1;
            }
            return 0;
        }
        for (int i=0; i!=nums1.size(); i++)
        {
            sum-=nums1[i];
            sum+=nums2[i];
            if (sum%k!=0) return -1;
        }
        if (sum!=0) return -1;
        sum=0;
        for (int i=0; i!=nums1.size(); i++)
        {
            sum+=abs(nums1[i]-nums2[i])/k;
        }
        if (sum%2==0)return sum/2;
        else return -1;
    }
};