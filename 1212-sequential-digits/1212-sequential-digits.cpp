class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int a=1, fl;
        string temp;
        for (int i=to_string(low).length(); i<=to_string(high).length(); i++)
        {
            a=1;
            while (a+i<=10)
            {
                fl=1;
                for (int j=a; j!=a+i&&j<10; j++)
                {
                    temp+=to_string(j);
                }
                if (temp.length()==i&&stoi(temp)<=high&&stoi(temp)>=low) ans.push_back(stoi(temp));
                temp.clear();
                a++;
            }
        }
        return ans;
    }
};