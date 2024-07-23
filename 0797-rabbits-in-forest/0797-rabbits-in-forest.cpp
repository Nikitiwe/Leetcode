class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0, temp=1;
        sort(answers.begin(), answers.end());
        if (answers[0]==0) ans++;
        for (int i=1; i!=answers.size(); i++)
        {
            if (answers[i]==0) ans++;
            else
            {
                if (answers[i-1]==answers[i]) temp++;
                else if (answers[i-1]!=0)
                {
                    ans+=((temp+answers[i-1])/(answers[i-1]+1))*(answers[i-1]+1);
                    temp=1;
                }
                else temp=1;
            }
        }
        ans+=((temp+answers[answers.size()-1])/(answers[answers.size()-1]+1))*(answers[answers.size()-1]+1);
        return ans;
    }
};