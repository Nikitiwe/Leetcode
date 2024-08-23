bool customComparison(string a, string b) 
{ 
    return a.size() > b.size();
}

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), customComparison);
        for (int i=0; i!=strs.size(); i++)
        {
            bool isit=0;
            for (int j=0; j<strs.size(); j++)
            {
                if (strs[j].size()<strs[i].size()) break;
                int a=0, b=0;
                if (i!=j) while (a<strs[i].size()&&b<strs[j].size())
                {
                    if (strs[i][a]==strs[j][b])
                    {
                        a++;
                        b++;
                        if (a==strs[i].size()) {isit=1; break;}
                    }
                    else b++;
                }
                if (isit==1) {break;}
            }
            if (isit==0) return strs[i].size();
        }
        return -1;
    }
};