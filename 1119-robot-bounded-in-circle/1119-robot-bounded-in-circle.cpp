class Solution {
public:
    bool isRobotBounded(string instructions) {
        char state='N';
        int x=0, y=0;
        for (int i=0; i!=4; i++)
        {
            for (int j=0; j!=instructions.size(); j++)
            {
                if (instructions[j]=='G'&&state=='N') {y++;}
                else if (instructions[j]=='G'&&state=='S') {y--;}
                else if (instructions[j]=='G'&&state=='E') {x++;}
                else if (instructions[j]=='G'&&state=='W') {x--;}
                else if (instructions[j]=='L'&&state=='N') {state='W';}
                else if (instructions[j]=='L'&&state=='S') {state='E';}
                else if (instructions[j]=='L'&&state=='E') {state='N';}
                else if (instructions[j]=='L'&&state=='W') {state='S';}
                else if (instructions[j]=='R'&&state=='N') {state='E';}
                else if (instructions[j]=='R'&&state=='S') {state='W';}
                else if (instructions[j]=='R'&&state=='E') {state='S';}
                else if (instructions[j]=='R'&&state=='W') {state='N';}
            }
            if (state=='N'&&x==0&&y==0) return 1;
        }
        return 0;
    }
};