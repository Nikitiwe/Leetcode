class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> arr(max(startPos, fruits[fruits.size()-1][0])+1, 0);
        int t=0, l=0, ans=0, tt=0, c;
        for (int i=0; i<fruits.size(); i++) if (fruits[i][0]==startPos) {tt=fruits[i][1]; break;}
        for (int i=startPos+1; i<arr.size(); i++)
        {
            while(l<fruits.size()&&fruits[l][0]<i) l++;
            if (l<fruits.size()&&fruits[l][0]==i) t+=fruits[l][1];
            arr[i]=t;
        }
        t=0; l=fruits.size()-1;
        for (int i=startPos-1; i>=0; i--)
        {
            while(l>0&&fruits[l][0]>i) l--;
            if (l>=0&&fruits[l][0]==i) t+=fruits[l][1];
            arr[i]=t;
        }
        c=startPos+k;
        for (int i=1; i<=k; i++)
        {
            t=0;
            if (startPos>=i)
            {
                t=arr[startPos-i];
                if (c-2*i<arr.size()&&k>2*i) t+=arr[c-2*i];
                else if (c-2*i>=arr.size()) t+=arr[arr.size()-1];
            }
            ans=max(ans, t);
        }
        c=startPos-k;
        for (int i=1; i<=k; i++)
        {
            t=0;
            if (startPos+i<arr.size())
            {
                t=arr[startPos+i];
                if (c+2*i>=0&&2*i<k) t+=arr[c+2*i];
                else if (c+2*i<0) t+=arr[0];
            }
            ans=max(ans, t);
        }
        return ans+tt;
    }
};