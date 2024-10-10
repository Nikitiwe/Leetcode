class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        string s=to_string(x);
        int sum=0;
        for (int i=0; i!=s.size(); i++)
        {
            sum+=s[i]-'0';
        }
        if (x%sum==0) return sum;
        else return -1;
    }
};