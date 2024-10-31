class Solution {
public:
    vector<string> letterCombinations(string s) {
        vector<string> next, prev;
        if (s.size()==0) return prev;
        if (s[0]=='2') {prev.push_back("a"); prev.push_back("b"); prev.push_back("c");}
        else if (s[0]=='3') {prev.push_back("d"); prev.push_back("e"); prev.push_back("f");}
        else if (s[0]=='4') {prev.push_back("g"); prev.push_back("h"); prev.push_back("i");}
        else if (s[0]=='5') {prev.push_back("j"); prev.push_back("k"); prev.push_back("l");}
        else if (s[0]=='6') {prev.push_back("m"); prev.push_back("n"); prev.push_back("o");}
        else if (s[0]=='7') {prev.push_back("p"); prev.push_back("q"); prev.push_back("r");prev.push_back("s");}
        else if (s[0]=='8') {prev.push_back("t"); prev.push_back("u"); prev.push_back("v");}
        else if (s[0]=='9') {prev.push_back("w"); prev.push_back("x"); prev.push_back("y");prev.push_back("z");}
        
        for (int k=1; k!=s.size(); k++)
        {
            for (int i=0; i!=prev.size(); i++)
            {
                if (s[k]=='2') {next.push_back(prev[i]+"a"); next.push_back(prev[i]+"b"); next.push_back(prev[i]+"c");}
                else if (s[k]=='3') {next.push_back(prev[i]+"d"); next.push_back(prev[i]+"e"); next.push_back(prev[i]+"f");}
                else if (s[k]=='4') {next.push_back(prev[i]+"g"); next.push_back(prev[i]+"h"); next.push_back(prev[i]+"i");}
                else if (s[k]=='5') {next.push_back(prev[i]+"j"); next.push_back(prev[i]+"k"); next.push_back(prev[i]+"l");}
                else if (s[k]=='6') {next.push_back(prev[i]+"m"); next.push_back(prev[i]+"n"); next.push_back(prev[i]+"o");}
                else if (s[k]=='7') {next.push_back(prev[i]+"p"); next.push_back(prev[i]+"q"); next.push_back(prev[i]+"r");next.push_back(prev[i]+"s");}
                else if (s[k]=='8') {next.push_back(prev[i]+"t"); next.push_back(prev[i]+"u"); next.push_back(prev[i]+"v");}
                else if (s[k]=='9') {next.push_back(prev[i]+"w"); next.push_back(prev[i]+"x"); next.push_back(prev[i]+"y");next.push_back(prev[i]+"z");}
            }
            prev=next;
            next.clear();
        }
        return prev;
    }
};