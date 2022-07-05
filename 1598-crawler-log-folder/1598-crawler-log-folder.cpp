class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c=0;
        for(auto&i:logs){
            if(i=="../"){
                if(c>0)--c;
            }
            else if(i=="./")continue;
            else ++c;
        }
        return c;
    }
};