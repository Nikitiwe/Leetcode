class Solution {
public:
    int getLucky(string ss, int k) {
        int sum=0;
        string s;
        for (int i=0; i!=ss.size(); i++)
        {
            sum+=(ss[i]-'a'+1)%10;
            sum+=(ss[i]-'a'+1)/10;
        }
        if (k==1) return sum;
        if (k>3&&sum%9!=0) return sum%9;
        if (k>3&&sum%9==0) return 9;
        while (k>0)
        {
            if (k==1) return sum;
            s=to_string(sum);
            sum=0;
            for (int i=0; i!=s.size(); i++)
            {
                sum+=s[i]-'0';
            }
            k--;
        }
        return -1;
    }
};