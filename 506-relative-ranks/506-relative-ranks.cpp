class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,string>mpp;
        priority_queue<int>q;
        vector<string>res;
        for(int i=0;i<score.size();i++){
            q.push(score[i]);
        }
        int count =1;
        while(!q.empty()){
            if(count==1){
                mpp[q.top()]="Gold Medal";
                count++;
                q.pop();
            }
            else if(count==2){
                mpp[q.top()]="Silver Medal";
                count++;
                q.pop();
            }
            else if(count==3){
                mpp[q.top()]="Bronze Medal";
                count++;
                q.pop();
            }
            else{
                mpp[q.top()]= to_string(count);
                count++;
                q.pop();
            }
        }
        for(int i=0;i<score.size();i++){
            res.push_back(mpp[score[i]]);
        }
        return res;
    }
};