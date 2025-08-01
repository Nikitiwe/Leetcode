class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> str, next;
        str.push_back(1);
        ans.push_back(str);
        for (int i=1; i<numRows; i++)
        {
            next.push_back(1);
            for (int j=0; j<i-1; j++)
            {
                next.push_back(str[j]+str[j+1]);
            }
            next.push_back(1);
            ans.push_back(next);
            str=next;
            next.clear();
        }
        return ans;
    }
};