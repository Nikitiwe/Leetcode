class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<bool> arr(time+1, 0), arrh(time, 0);
        int l=0, r=0, ans=0;
        for (int i=0; i!=clips.size(); i++)
        {
            for (int j=clips[i][0]; j<=clips[i][1]&&j<=time; j++)
            {
                arr[j]=1;
            }
            for (int j=clips[i][0]; j<clips[i][1]&&j<=time; j++)
            {
                arrh[j]=1;
            }
        }
        for (int i=0; i<=time; i++) if (arr[i]==0) return -1;
        for (int i=0; i<time; i++) if (arrh[i]==0) return -1;
        while (1)
        {
            for (int i=0; i!=clips.size(); i++)
            {
                if (clips[i][0]<=l) r=max(r, clips[i][1]);
            }
            ans++;
            if (r>=time) return ans;
            l=r;
        }
        return ans;
    }
};