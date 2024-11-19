// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans=n, l=0, r=n, m;
        while (l<=r)
        {
            m=r-(r-l)/2;
            if (isBadVersion(m)==1)
            {
                ans=min(ans, m);
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};