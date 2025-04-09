class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& r) {
        vector<int> ans;
        unordered_set<int> in;
        for (int i=0; i!=n; i++) in.insert(i);
        for (int i=0; i!=r.size(); i++) in.erase(r[i][1]);
        for (auto i = in.begin(); i != in.end(); i++) ans.push_back(*i);
        return ans;
    }
};