class Solution {
public:
    string interpret(string command) {
        string ans;
        int i=0;
        while (i<command.size())
        {
            if (command[i]=='G') {ans=ans+"G"; i++;}
            else if (command[i+1]==')') {ans=ans+"o"; i=i+2;}
            else {ans=ans+"al"; i=i+4;}
        }
        return ans;
    }
};