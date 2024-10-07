class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        if (s.size()==1) return 0;
        sort(s.begin(), s.end());
        /*vector<int> arr(s.size(), 0);
        for (int i=1; i<s.size(); i++)
        {
            if (s[i-1][0]!=s[i][0])
            {
                arr[i-1]=(s[i][1]-s[i-1][1])/(s[i][0]-s[i-1][0]);
            }
        }*/
        int ans=1;
        for (int i=2; i<s.size(); i++)
        {
            if ( (long)(s[i][1]-s[i-1][1])*(s[i-1][0]-s[i-2][0])!=(long)(s[i-1][1]-s[i-2][1])*(s[i][0]-s[i-1][0]) )
            {
                ans++;
            }
        }
        return ans;
    }
};

// (s[i][2]-s[i-1][2])/(s[i][1]-s[i-1][1])!=(s[i-1][2]-s[i-2][2])/(s[i-1][1]-s[i-2][1])