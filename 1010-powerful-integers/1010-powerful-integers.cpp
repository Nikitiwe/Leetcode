class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> xx, yy, ans;
        xx.push_back(1);
        yy.push_back(1);
        int a=x, b=y;
        unordered_set<int> anss;
        if (x>1) while (a<bound)
        {
            xx.push_back(a);
            a*=x;
        }
        if (y>1) while (b<bound)
        {
            yy.push_back(b);
            b*=y;
        }
        for (int i=0; i!=xx.size(); i++)
        {
            for (int j=0; j!=yy.size(); j++)
            {
                if (xx[i]+yy[j]<=bound) anss.insert(xx[i]+yy[j]);
                else break;
            }
        }
        for (auto i=anss.begin(); i!=anss.end(); i++)
        {
            ans.push_back(*i);
        }
        return ans;
    }
};