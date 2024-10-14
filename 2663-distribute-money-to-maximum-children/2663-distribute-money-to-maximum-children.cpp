class Solution {
public:
    int distMoney(int m, int c) {
        if (m<c) return -1;
        m-=c;
        int ans=0;
        while (m>=7&&ans<c)
        {
            ans++;
            m-=7;
        }
        if (m==3&&ans==c-1) ans--;
        if (m>0&&ans==c) ans--;
        return ans;
    }
};