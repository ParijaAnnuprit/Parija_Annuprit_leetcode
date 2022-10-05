class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
//         bipartite solution
        
//         create an adjacency list
        vector<vector<int>>adjls(n+1);
        vector<int>colour(n+1,-1);
        queue<pair<int,int>>q;
        for(int i=0;i<dislikes.size();i++){
            adjls[dislikes[i][0]].push_back(dislikes[i][1]);
            adjls[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=0;i<adjls.size();i++){
            if(colour[i]==-1){
                q.push({i,0});
                colour[i]=0;
                while(!q.empty()){
                    int node = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for(int j : adjls[node]){
                        if(colour[j]==-1){
                            if(col==0){
                                colour[j]=1;
                                q.push({j,colour[j]});
                            }
                            else{
                                colour[j]=0;
                                q.push({j,colour[j]});
                            }
                        }
                        else if(colour[j]!=-1 && colour[j]==col) return false;
                    }
                }
            }
        }
        return true;
    }
};