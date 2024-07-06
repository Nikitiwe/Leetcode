class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> ans;
        vector<char> line;
        for (int i=0; i!=box[0].size(); i++)
        {
            line.clear();
            for (int j=box.size()-1; j>=0; j--) line.push_back(box[j][i]);
            ans.push_back(line);
        }
        int a;
        for (int i=ans.size()-2; i>=0; i--)
        {
            for (int j=0; j!=ans[0].size(); j++)
            {
                if (ans[i][j]=='#')
                {
                    a=0;
                    while (i+1+a<ans.size()&&ans[i+1+a][j]!='*'&&ans[i+1+a][j]!='#')
                    {
                        swap (ans[i+1+a][j], ans[i+a][j]);
                        a++;
                    }
                }
            }
        }
        return ans;
    }
};