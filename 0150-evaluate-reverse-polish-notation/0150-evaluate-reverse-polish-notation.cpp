class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> arr;
        int temp;
        for (int i=0; i!=tokens.size(); i++)
        {
            if (tokens[i][0]=='+')
            {
                temp=arr[arr.size()-2]+arr[arr.size()-1];
                arr.pop_back();
                arr.pop_back();
                arr.push_back(temp);
            }
            else if (tokens[i][0]=='-'&&tokens[i].size()==1)
            {
                temp=arr[arr.size()-2]-arr[arr.size()-1];
                arr.pop_back();
                arr.pop_back();
                arr.push_back(temp);
            }
            else if (tokens[i][0]=='*')
            {
                temp=arr[arr.size()-2]*arr[arr.size()-1];
                arr.pop_back();
                arr.pop_back();
                arr.push_back(temp);
            }
            else if (tokens[i][0]=='/')
            {
                temp=arr[arr.size()-2]/arr[arr.size()-1];
                arr.pop_back();
                arr.pop_back();
                arr.push_back(temp);
            }
            else
            {
                arr.push_back(stoi(tokens[i]));
            }
        }
        return arr[0];
    }
};