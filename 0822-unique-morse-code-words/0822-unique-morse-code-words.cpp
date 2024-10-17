class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& w) {
        unordered_set<string> m;
        for (int i=0; i!=w.size(); i++)
        {
            string s;
            for (int j=0; j!=w[i].size(); j++)
            {
                if (w[i][j]=='a') s+=".-";
                else if (w[i][j]=='b') s+="-...";
                else if (w[i][j]=='c') s+="-.-.";
                else if (w[i][j]=='d') s+="-..";
                else if (w[i][j]=='e') s+=".";
                else if (w[i][j]=='f') s+="..-.";
                else if (w[i][j]=='g') s+="--.";
                else if (w[i][j]=='h') s+="....";
                else if (w[i][j]=='i') s+="..";
                else if (w[i][j]=='j') s+=".---";
                else if (w[i][j]=='k') s+="-.-";
                else if (w[i][j]=='l') s+=".-..";
                else if (w[i][j]=='m') s+="--";
                else if (w[i][j]=='n') s+="-.";
                else if (w[i][j]=='o') s+="---";
                else if (w[i][j]=='p') s+=".--.";
                else if (w[i][j]=='q') s+="--.-";
                else if (w[i][j]=='r') s+=".-.";
                else if (w[i][j]=='s') s+="...";
                else if (w[i][j]=='t') s+="-";
                else if (w[i][j]=='u') s+="..-";
                else if (w[i][j]=='v') s+="...-";
                else if (w[i][j]=='w') s+=".--";
                else if (w[i][j]=='x') s+="-..-";
                else if (w[i][j]=='y') s+="-.--";
                else s+="--..";
            }
            m.insert(s);
        }
        return m.size();
    }
};