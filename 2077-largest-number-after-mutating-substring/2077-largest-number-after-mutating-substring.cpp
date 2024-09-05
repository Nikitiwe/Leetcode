class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool isit=0;
        for (int i=0; i!=num.size(); i++)
        {
            if (num[i]-'0'<change[num[i]-'0'])
            {
                num[i]=change[num[i]-'0']+'0';
                isit=1;
            }
            else if (isit==1&&num[i]-'0'>change[num[i]-'0']) break;
        }
        return num;
    }
};