class Solution {
public:
    int distributeCandies(vector<int>& c) {
        unordered_set<int> m(c.begin(), c.end());
        return min(c.size()/2, m.size());
    }
};