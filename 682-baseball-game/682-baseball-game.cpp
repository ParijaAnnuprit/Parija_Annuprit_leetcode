class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>rec;
        for(int i=0;i<ops.size();i++){
            if(isdigit(ops[i][0]) || ops[i][0]=='-'){
                rec.push_back(stoi(ops[i]));
            }
            else if(ops[i]=="D"){
                rec.push_back(rec[rec.size()-1]*2);
            }
            else if(ops[i]=="C"){
                rec.pop_back();
            }
            else if(ops[i]=="+"){
                rec.push_back(rec[rec.size()-1]+rec[rec.size()-2]);
            }
        }
        int f = 0;
        for(int i=0;i<rec.size();i++){
            f = f+rec[i];
        }
        return f;
    }
};