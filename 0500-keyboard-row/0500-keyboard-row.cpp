class Solution {
public:
    vector<string> findWords(vector<string>& w) {
        vector<string> ans;
        string s1="QWERTYUIOPqwertyuiop", s2="ASDFGHJKLasdfghjkl", s3="ZXCVBNMzxcvbnm";
        for (int i=0; i!=w.size(); i++)
        {
            bool isit=1;
            int c;
            if (s1.find(w[i][0])!=string::npos) c=1;
            else if (s2.find(w[i][0])!=string::npos) c=2;
            else c=3;
            if (c==1) for (int j=1; j<w[i].size(); j++)
            {
                if (s1.find(w[i][j])==string::npos)
                {
                    isit=0;
                    break;
                }
            }
            else if (c==2) for (int j=1; j<w[i].size(); j++)
            {
                if (s2.find(w[i][j])==string::npos)
                {
                    isit=0;
                    break;
                }
            }
            else for (int j=1; j<w[i].size(); j++)
            {
                if (s3.find(w[i][j])==string::npos)
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1) ans.push_back(w[i]);
        }
        return ans;
    }
};