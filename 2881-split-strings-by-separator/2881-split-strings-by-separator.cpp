class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& w, char s) {
        vector<string> ans;
        int i=0, l=0;
        while (i<w.size())
        {
            string t;
            l=0;
            while (l<w[i].size())
            {
                t="";
                while (l<w[i].size()&&w[i][l]!=s)
                {
                    t+=w[i][l];
                    l++;
                }
                if (t!="") ans.push_back(t);
                t="";
                l++;
            }
            i++;
        }
        return ans;
    }
};