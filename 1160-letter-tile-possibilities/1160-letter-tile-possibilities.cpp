class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        unordered_set<string> m;
        int n=1, t=tiles.size();
        while (t>0)
        {
            n*=t;
            t--;
        }
        for (int i=0; i!=n; i++)
        {
            string s=tiles;
            while (s.size()>0)
            {
                m.insert(s);
                s.pop_back();
            }
            next_permutation(tiles.begin(), tiles.end());
        }
        return m.size();
    }
};