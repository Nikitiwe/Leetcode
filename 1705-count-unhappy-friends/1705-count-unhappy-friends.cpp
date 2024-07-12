class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        int ans=0;
        vector<int> isit(pref.size(), 0);
        for (int i=0; i!=pairs.size(); i++)
        {
            for (int j=0; j!=pairs.size(); j++)
            {
                if (find(pref[pairs[i][0]].begin(), pref[pairs[i][0]].end(), pairs[i][1])>
                    find(pref[pairs[i][0]].begin(), pref[pairs[i][0]].end(), pairs[j][0])
                    &&
                    find(pref[pairs[j][0]].begin(), pref[pairs[j][0]].end(), pairs[j][1])>
                    find(pref[pairs[j][0]].begin(), pref[pairs[j][0]].end(), pairs[i][0])) { isit[pairs[i][0]]=1; isit[pairs[j][0]]=1; }
                    
                if (find(pref[pairs[i][1]].begin(), pref[pairs[i][1]].end(), pairs[i][0])>
                    find(pref[pairs[i][1]].begin(), pref[pairs[i][1]].end(), pairs[j][1])
                    &&
                    find(pref[pairs[j][1]].begin(), pref[pairs[j][1]].end(), pairs[j][0])>
                    find(pref[pairs[j][1]].begin(), pref[pairs[j][1]].end(), pairs[i][1])) { isit[pairs[i][1]]=1; isit[pairs[j][1]]=1; }
                    
                if (find(pref[pairs[i][0]].begin(), pref[pairs[i][0]].end(), pairs[i][1])>
                    find(pref[pairs[i][0]].begin(), pref[pairs[i][0]].end(), pairs[j][1])
                    &&
                    find(pref[pairs[j][1]].begin(), pref[pairs[j][1]].end(), pairs[j][0])>
                    find(pref[pairs[j][1]].begin(), pref[pairs[j][1]].end(), pairs[i][0])) { isit[pairs[i][0]]=1; isit[pairs[j][1]]=1; }
            }
        }
        for (int i=0; i!=isit.size(); i++) if (isit[i]==1) ans++;
        return ans;
    }
};