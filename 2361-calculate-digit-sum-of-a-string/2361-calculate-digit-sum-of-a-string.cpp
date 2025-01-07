class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size()>k)
        {
            string arr;
            int i=0, sum=0;
            while (i<s.size())
            {
                sum+=s[i]-'0';
                i++;
                if (i%k==0||i==s.size())
                {
                    arr+=to_string(sum);
                    sum=0;
                }
            }
            s=arr;
        }
        return s;
    }
};