class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int b=0, a=0, l=0, o=0, n=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='b') b++;
            else if (s[i]=='a') a++;
            else if (s[i]=='l') l++;
            else if (s[i]=='o') o++;
            else if (s[i]=='n') n++;
        }
        return min({a, b, l/2, o/2, n});
    }
};