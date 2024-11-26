class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0, u=0, d=0;
        for (int i=1; i<arr.size(); i++)
        {
            if (arr[i]>arr[i-1])
            {
                if (d>0) u=0;
                u++;
                d=0;
            }
            else if (arr[i]<arr[i-1])
            {
                d++;
                if (u>0) ans=max(ans, u+d+1);
            }
            else
            {
                u=0;
                d=0;
            }
        }
        return ans;
    }
};