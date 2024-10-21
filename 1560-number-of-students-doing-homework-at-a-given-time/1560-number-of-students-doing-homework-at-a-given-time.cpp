class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& e, int t) {
        int ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]<=t&&t<=e[i]) ans++;
        }
        return ans;
    }
};