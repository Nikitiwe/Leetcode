class Solution {
public:
    int minFlips(string target) {
        int ans=0;
        for (int i=target.size()-1; i>0; i--)
        {
            if (target[i]!=target[i-1]) ans++;
        }
        return ans+target[0]-'0';
    }
};