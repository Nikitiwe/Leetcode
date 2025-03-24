class TopVotedCandidate {
public:
    vector<int> t, ans;
    unordered_map<int, int> m;
    int id = 0;
    TopVotedCandidate(vector<int>& p, vector<int>& times) {
        t = times;
        m[p[0]]++;
        id = p[0];
        ans.push_back(id);
        for (int i=1; i<p.size(); i++)
        {
            m[p[i]]++;
            if (m[p[i]] >= m[id]) id = p[i];
            ans.push_back(id);
        }
    }
    
    int q(int tar) {
        int l = 0, r = t.size()-1, m, mom = 0;
        while (l <= r)
        {
            m = (l+r)/2;
            if (t[m] <= tar)
            {
                mom = max(mom, m);
                l = m+1;
                
            }
            else r = m-1;
        }
        return ans[mom];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */