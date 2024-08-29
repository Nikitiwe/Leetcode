class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        unordered_map<int, int> m;
        int ans=0, i=0;
        /*int tt=0;
        for (int j=0; j!=apples.size(); j++) tt=max(tt, j+days[j]);*/
        while (i<apples.size()||m.size()>0)
        {
            if (i<apples.size()&&apples[i]>0) m[i+days[i]-1]+=apples[i];
            int t=500000000;
            for (auto j=m.begin(); j!=m.end(); j++)
            {
                if (j->first>=i) t=min(t, j->first);
            }
            if (t!=500000000)
            {
                m[t]--;
                if (m[t]==0) m.erase(t);
                ans++;
                m.erase(i);
            }
            i++;
            //if (i>tt+1) break;
        }
        return ans;
    }
};