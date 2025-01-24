bool ssort (vector<int> &a, vector<int> &b)
{
    if (a[0]!=b[0]) return a[0]>b[0];
    else return a[1]<b[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& s) {
        vector<vector<int>> ans;
        sort(s.begin(), s.end(), ssort);
        ans.push_back(s[0]);
        for (int i=1; i<s.size(); i++)
        {
            ans.insert(ans.begin()+s[i][1], s[i]);
        }
        return ans;
    }
};