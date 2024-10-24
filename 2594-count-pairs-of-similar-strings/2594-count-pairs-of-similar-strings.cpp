class Solution {
public:
    int similarPairs(vector<string>& w) {
        int ans=0;
        unordered_map<int, int> m;
        for (int i=0; i!=w.size(); i++)
        {
            vector<int> arr(26, 0);
            for (int j=0; j!=w[i].size(); j++) arr[w[i][j]-'a']=max(arr[w[i][j]-'a'], 1);
            int t=0, d=1;
            for (int k=0; k!=26; k++)
            {
                t+=d*arr[k];
                d*=2;
            }
            m[t]++;
            ans+=m[t]-1;
        }
        return ans;
    }
};