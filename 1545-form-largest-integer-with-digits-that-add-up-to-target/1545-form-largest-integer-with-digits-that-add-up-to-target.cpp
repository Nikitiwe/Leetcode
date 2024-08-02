class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> arr(target+1, "");
        string temp;
        for (int j=0; j!=9; j++)
        {
            if (cost[j]<=target) arr[cost[j]]=to_string(j+1);
        }
        for (int i=1; i<=target; i++)
        {
            for (int j=0; j!=9; j++)
            {
                temp="";
                if (i-cost[j]>0&&arr[i-cost[j]]!="")
                {
                    temp+=to_string(j+1)+arr[i-cost[j]];
                    if (arr[i]=="") arr[i]=temp;
                    else if (temp.size()>=arr[i].size()) arr[i]=temp;
                }
            }
        }
        if (arr[target]!="") return arr[target];
        else return "0";
    }
};