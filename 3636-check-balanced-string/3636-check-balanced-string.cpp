class Solution {
public:
    bool isBalanced(string s) {
        int sum=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (i%2==0) sum+=s[i]-'0';
            else sum-=s[i]-'0';
        }
        if (sum==0) return 1;
        else return 0;
    }
};