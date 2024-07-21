class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if ((double)nums1.size()/nums2.size()>6) return -1;
        if ((double)nums2.size()/nums1.size()>6) return -1;
        int s1=0, s2=0, delta, ans=0;
        vector<int> n1(7, 0), n2(7, 0);
        for (int i=0; i!=nums1.size(); i++)
        {
            s1+=nums1[i];
            n1[nums1[i]]++;
        }
        for (int i=0; i!=nums2.size(); i++)
        {
            s2+=nums2[i];
            n2[nums2[i]]++;
        }
        delta=s1-s2;
        if (delta<0) {swap(n2, n1); delta*=-1;}
        if (delta>0)
        {
            for (int i=0; i<5; i++)
            {
                while (n1[6-i]>0&&delta>0)
                {
                    n1[6-i]--;
                    delta-=(5-i);
                    ans++;
                    if (delta<=0) return ans;
                }
                while (n2[1+i]>0&&delta>0)
                {
                    n2[1+i]--;
                    delta-=(5-i);
                    ans++;
                    if (delta<=0) return ans;
                }
            }
        }
        return ans;
    }
};