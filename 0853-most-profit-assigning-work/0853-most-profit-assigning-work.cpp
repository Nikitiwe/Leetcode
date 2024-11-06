class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<vector<int>> arr(p.size(), vector<int> (2, 0));
        for (int i=0; i!=p.size(); i++)
        {
            arr[i][0]=d[i];
            arr[i][1]=p[i];
        }
        vector<bool> isit(p.size(), 1);
        int ans=0;
        sort(arr.begin(), arr.end());
        sort(w.begin(), w.end());
        int pma=*min_element(p.begin(), p.end());
        for (int i=0; i<p.size(); i++)
        {
            if (arr[i][1]<pma) isit[i]=0;
            else pma=arr[i][1];
        }

        int r=w.size()-1, l=p.size()-1;
        for (int i=w.size()-1; i>=0; i--)
        {
            while (l>=0&&(isit[l]==0||(isit[l]==1&&arr[l][0]>w[i]))) l--;
            if (l>=0&&isit[l]==1&&arr[l][0]<=w[i]) ans+=arr[l][1];
        }
        return ans;
    }
};