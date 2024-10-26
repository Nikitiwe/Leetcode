class Solution {
public:
    int shortestSequence(vector<int>& r, int k) {
        unordered_set<int> m;
        int ans=1;
        for (int i=0; i!=r.size(); i++)
        {
            m.insert(r[i]);
            if (m.size()==k)
            {
                ans++;
                m.clear();
            }
        }
        return ans;
    }
};