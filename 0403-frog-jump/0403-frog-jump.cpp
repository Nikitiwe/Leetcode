class Solution {
public:
    bool canCross(vector<int>& s) {
        vector<unordered_set<int>> arr(s.size());
        arr[0].insert(0);
        {
            for (int i=0; i<s.size()-1; i++)
            {
                for (auto j=arr[i].begin(); j!=arr[i].end(); j++)
                {
                    for (int k=1; k+i<s.size(); k++)
                    {
                        if (s[i+k]==s[i]+*j-1)
                        {
                            arr[i+k].insert(*j-1);
                        }
                        else if (s[i+k]==s[i]+*j)
                        {
                            arr[i+k].insert(*j);
                        }
                        else if (s[i+k]==s[i]+*j+1)
                        {
                            arr[i+k].insert(*j+1);
                        }
                        else if (s[i+k]>s[i]+*j+1) break;
                    }
                    if (arr[s.size()-1].size()>0) return 1;
                }
            }
        }
        return 0;
    }
};


/*
class Solution {
public:
    bool canCross(vector<int>& s) {
        vector<vector<int>> arr(s.size(), {-2});
        arr[0].push_back(0);
        int temp;
        while (1)
        {
            temp=0;
            for (int i=0; i<s.size()-1; i++)
            {
                for (int j=arr[i].size()-1; j>=0; j--)
                {
                    for (int k=1; k+i<s.size(); k++)
                    {
                        if (s[i+k]==s[i]+arr[i][j]-1)
                        {
                            temp++;
                            arr[i+k].push_back(arr[i][j]-1);
                        }
                        else if (s[i+k]==s[i]+arr[i][j])
                        {
                            temp++;
                            arr[i+k].push_back(arr[i][j]);
                        }
                        else if (s[i+k]==s[i]+arr[i][j]+1)
                        {
                            temp++;
                            arr[i+k].push_back(arr[i][j]+1);
                        }
                        else if (s[i+k]>s[i]+arr[i][j]+1) break;
                    }
                    if (arr[s.size()-1].size()>1) return 1;
                    arr[i].pop_back();
                }
            }
            if (temp==0) return 0;
        }
        return 0;
    }
};
*/