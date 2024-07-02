class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max=0, temp;
        for (int i=0; i!=sentences.size(); i++)
        {
            temp=0;
            for (int j=0; j!=sentences[i].size(); j++)
            {
                if (sentences[i][j]==' ') temp++;
            }
            if (temp>max) max=temp;
        }
        return max+1;
    }
};