class Solution {
public:
    int minTimeToType(string s) {
        int ans=0;
        ans+=min({abs('a'-s[0]), abs('a'-s[0]-26), abs('a'-s[0]+26)})+1;
        for (int i=1; i<s.size(); i++)
        {
            ans+=min({abs(s[i-1]-s[i]), abs(s[i-1]-s[i]-26), abs(s[i-1]-s[i]+26)})+1;
        }
        return ans;
    }
};