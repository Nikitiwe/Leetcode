class Solution {
public:
    void f(vector<vector<int>>& g, int s, int k)
    {
        vector<int> arr;
        for (int j=s; j < g[0].size()-1-s; j++) arr.push_back(g[s][j]);
        for (int i=s; i < g.size()-1-s; i++) arr.push_back(g[i][g[0].size()-1-s]);
        for (int j=g[0].size()-1-s; j > s; j--) arr.push_back(g[g.size()-1-s][j]);
        for (int i=g.size()-s-1; i > s; i--) arr.push_back(g[i][s]);
        k %= arr.size();
        for (int j=s; j < g[0].size()-1-s; j++)
        {
            g[s][j] = arr[k];
            k++;
            k %= arr.size();
        }
        for (int i=s; i < g.size()-1-s; i++)
        {
            g[i][g[0].size()-1-s] = arr[k];
            k++;
            k %= arr.size();
        }
        for (int j=g[0].size()-1-s; j > s; j--)
        {
            g[g.size()-1-s][j] = arr[k];
            k++;
            k %= arr.size();
        }
        for (int i=g.size()-s-1; i > s; i--)
        {
            g[i][s] = arr[k];
            k++;
            k %= arr.size();
        }
        
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& g, int k) {
        for (int i=0; i!= min(g.size(), g[0].size())/2; i++) f(g, i, k);
        return g;
    }
};