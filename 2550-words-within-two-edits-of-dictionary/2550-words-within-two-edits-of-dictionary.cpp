class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int temp=0;
        for (int i=0; i!=queries.size(); i++)
        {
            for (int j=0; j!=dictionary.size(); j++)
            {
                if (queries[i].size()!=dictionary[j].size()) continue;
                temp=0;
                for (int k=0; k!=dictionary[j].size(); k++)
                {
                    if (dictionary[j][k]!=queries[i][k]) temp++;
                }
                if (temp<3) {ans.push_back(queries[i]); break;}
            }
        }
        return ans;
    }
};