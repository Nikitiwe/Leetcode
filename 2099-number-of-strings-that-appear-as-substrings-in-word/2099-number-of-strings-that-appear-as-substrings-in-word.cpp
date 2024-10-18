class Solution {
public:
    int numOfStrings(vector<string>& p, string w) {
        int ans=0;
        for (int i=0; i!=p.size(); i++)
        {
            if (w.find(p[i])!=std::string::npos) ans++;
        }
        return ans;
    }
};