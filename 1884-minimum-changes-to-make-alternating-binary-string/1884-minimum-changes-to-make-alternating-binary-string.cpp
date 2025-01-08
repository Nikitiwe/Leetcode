class Solution {
public:
    int minOperations(string s) {
        int t=0, k=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (i%2==0)
            {
                if (s[i]=='1') t++;
                else k++;
            }
            else
            {
                if (s[i]=='0') t++;
                else k++;
            }
        }
        return min(k, t);
    }
};