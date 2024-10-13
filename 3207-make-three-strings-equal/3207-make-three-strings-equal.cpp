class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int ans=(int)s1.size()+s2.size()+s3.size();
        if (s1[0]!=s2[0]||s2[0]!=s3[0]) return -1;
        for (int i=0; i<min((int)s1.size(), min((int)s2.size(), (int)s3.size())); i++)
        {
            if (s1[i]==s2[i]&&s2[i]==s3[i]) ans-=3;
            else break;
        }
        return ans;
    }
};