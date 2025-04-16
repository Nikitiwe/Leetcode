class Solution {
public:
    int f(int a, int b)
    {
        return a*128 + b;
    }

    int scoreOfParentheses(string s) {
        stack<int> st;
        vector<vector<int>> arr;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] == '(') st.push(i);
            else
            {
                int a = st.top();
                st.pop();
                arr.push_back({a, i});
            }
        }
        unordered_map<int, int> m;
        vector<int> c(arr.size(), 1);
        int ans = 1;
        for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i][0] + 1 == arr[i][1]) m[f(arr[i][0], arr[i][1])] = 1;
        }
        for (int k = 0; k<50; k++) //(m.count(f(0, s.size()-1)) == 0)
        {
            for (int i=0; i!=arr.size(); i++)
            {
                if (c[i] == 1 && m.count(f(arr[i][0], arr[i][1])) != 0)
                {
                    bool isit = 0;
                    for (int j=0; j!=arr.size(); j++)
                    {
                        if (i != j && c[j] == 1 )
                        {
                            if (arr[i][1]+1 == arr[j][0] && m.count(f(arr[j][0], arr[j][1])) != 0)
                            {
                                m[f(arr[i][0], arr[j][1])] = m[f(arr[i][0], arr[i][1])] + m[f(arr[j][0], arr[j][1])];
                                ans = max(ans, m[f(arr[i][0], arr[j][1])]);
                                isit = 1;
                                arr.push_back({arr[i][0], arr[j][1]});
                                c.push_back(1);
                                c[i] = 0;
                                c[j] = 0;
                                break;
                            }
                            else if (arr[i][0]-1 == arr[j][0] && arr[i][1]+1 == arr[j][1])
                            {
                                m[f(arr[j][0], arr[j][1])] = 2*m[f(arr[i][0], arr[i][1])];
                                ans = max(ans, m[f(arr[j][0], arr[j][1])]);
                                isit = 1;
                                c[i] = 0;
                                break;
                            }
                        }
                    }
                    if (isit == 1) break;
                }
            }
        }
        return ans;
    }
};