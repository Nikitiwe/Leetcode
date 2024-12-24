class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& s) {
        int id=s[0][0], t=s[0][1];
        for (int i=1; i<s.size(); i++)
        {
            if (s[i][1]-s[i-1][1]==t)
            {
                t=s[i][1]-s[i-1][1];
                id=min(id, s[i][0]);
            }
            else if (s[i][1]-s[i-1][1]>t)
            {
                t=s[i][1]-s[i-1][1];
                id=s[i][0];
            }
        }
        return id;
    }
};