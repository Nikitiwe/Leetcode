class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> arr(10, 0);
        vector<string> s={"0","1","2","3","4","5","6","7","8","9"};
        for (int i=0; i!=num.size(); i++) arr[num[i]-'0']++;
        string a, b;
        for (int i=9; i>=1; i--)
        {
            while (arr[i]>1)
            {
                a+=s[i];
                b+=s[i];
                arr[i]--;
                arr[i]--;
            }
        }
        if (a.size()>0) while (arr[0]>1)
        {
            a+=s[0];
            b+=s[0];
            arr[0]--;
            arr[0]--;
        }
        for (int i=9; i>=0; i--)
        {
            if (arr[i]>0)
            {
                a+=s[i];
                break;
            }
        }
        reverse(b.begin(), b.end());
        a+=b;
        return a;
    }
};