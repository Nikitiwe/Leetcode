class Solution {
public:
    int countDays(int d, vector<vector<int>>& m) {
        /*vector<int> arr(d+2, 0);
        //arr[0]=0;
        for (int i=0; i!=m.size(); i++)
        {
            arr[m[i][0]]++;
            arr[m[i][1]+1]--;
        }
        int ans=0;
        //if (arr[0]>=1) ans++;
        for (int i=1; i<arr.size()-1; i++)
        {
            arr[i]+=arr[i-1];
            if (arr[i]==0) ans++;
        }*/
        vector<int> b, e;
        for (int i=0; i!=m.size(); i++)
        {
            b.push_back(m[i][0]);
            e.push_back(m[i][1]);
        }
        sort(b.begin(), b.end());
        sort(e.begin(), e.end());
        int ans=b[0]-1;
        int l=0, r=0;
        while (r<e.size())
        {
            while (l+1<b.size()&&b[l+1]<=e[r]) l++;
            if (l+1==b.size()) {ans+=(d-e[e.size()-1]); break;}
            else
            {
                //if (l+1<b.size()&&b[l+1]<=e[r]) continue;
                if (l==r)
                {
                    ans+=(b[l+1]-e[r]-1);
                    l++;
                }
                r++;
            }
        }
        return ans;
    }
};