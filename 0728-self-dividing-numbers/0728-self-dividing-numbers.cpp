class Solution {
public:
    vector<int> selfDividingNumbers(int l, int r) {
        vector<int> ans;
        for (int i=l; i<=r; i++)
        {
            string t=to_string(i);
            bool isit=1;
            for (int j=0; j!=t.size(); j++)
            {
                if (t[j]=='0'||i%(t[j]-'0')!=0)
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1) ans.push_back(i);
        }
        return ans;
    }
};