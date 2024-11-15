class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int la) {
        vector<int> arr(h.size(), 0);
        for (int i=1; i<h.size(); i++)
        {
            if (h[i]-h[i-1]>0) arr[i]=h[i]-h[i-1];
        }
        int l=0, r=h.size()-1, m=(r+l)/2, ans=0;
        while (l<=r)
        {
            m=(r+l)/2;
            vector<int> t;
            long s=0;
            for (int i=0; i<=m; i++) if (arr[i]>0) t.push_back(arr[i]);
            sort(t.begin(), t.end());
            /*if (t.size()-la>0)*/ for (int i=0; i<(int)t.size()-la; i++) s+=t[i];
            if (s>b) r=m-1;
            else
            {
                ans=max(ans, m);
                l=m+1;
            }
        }
        /*m=ans+1;
        {
            vector<int> t;
            long s=0;
            for (int i=0; i<=m; i++) if (arr[i]>0) t.push_back(arr[i]);
            sort(t.begin(), t.end());
            for (int i=0; i<t.size()-la; i++) s+=t[i];
            if (s>b) r=m-1;
            else
            {
                ans=max(ans, m);
                l=m+1;
            }
        }*/
        return ans;
    }
};