class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int ans=0, l=1;
        if (f.size()==1&&f[0]==0) ans++;
        if (f.size()>1&&f[0]==0&&f[1]==0)
        {
            ans++;
            l++;
        }
        while (l<f.size())
        {
            if (f[l-1]==1) l++;
            else
            {
                if (f[l]==1) l+=2;
                else
                {
                    if (l+1<f.size()&&f[l+1]==1) l+=3;
                    else if (l+1>=f.size())
                    {
                        ans++;
                        break;
                    }
                    else
                    {
                        ans++;
                        l+=2;
                    }
                }
            }
            if (ans>=n) return 1;
        }
        if (ans>=n) return 1;
        else return 0;
    }
};