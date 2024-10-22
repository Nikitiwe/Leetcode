class Solution {
public:
    int vowelStrings(vector<string>& w, int l, int r) {
        int ans=0;
        for (int i=l; i<=r; i++)
        {
            int t=w[i].size()-1;
            if ((w[i][0]=='a'||w[i][0]=='e'||w[i][0]=='i'||w[i][0]=='o'||w[i][0]=='u')&&
                (w[i][t]=='a'||w[i][t]=='e'||w[i][t]=='i'||w[i][t]=='o'||w[i][t]=='u'))
                ans++;
        }
        return ans;
    }
};