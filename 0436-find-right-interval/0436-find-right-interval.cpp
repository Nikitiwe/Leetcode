/*bool ssort(vector<int> a, vector<int> b)
{
    if (a[0]!=b[0]) return a[0]<b[0];
    else return a[1]<b[1];
}*/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& ss) {
        if (ss.size()==1&&ss[0][0]!=ss[0][1]) return {-1};
        if (ss.size()==1&&ss[0][0]==ss[0][1]) return {0};
        unordered_map<int, int> n;
        for (int i=0; i!=ss.size(); i++) n[ss[i][0]]=i;
        vector<vector<int>> s=ss;
        sort(s.begin(), s.end());
        vector<int> ans(ss.size(), -1);
        for (int i=0; i!=ss.size(); i++)
        {
            int l=0, r=ss.size()-1, m;
            while (l<r)
            {
                m=(l+r)/2;
                if (s[m][0]==ss[i][1]) break;
                else if (s[m][0]>ss[i][1]) r=m;
                else l=m+1;
            }
            m=(l+r)/2;
            if (s[m][0]>=ss[i][1]) ans[i]=n[s[m][0]];
        }
        return ans;
    }
};