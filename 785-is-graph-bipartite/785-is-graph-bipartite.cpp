class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
//         check if bipartite considers two colours 0,1
        int n = graph.size();
        vector<int>colour(n,-1);
//         pair of node and colour
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(colour[i]==-1){
                q.push({i,0});
                colour[i]=0;
                while(!q.empty()){
                    int num = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for(int i=0;i<graph[num].size();i++){
                        if(colour[graph[num][i]]==col) return false;
                        else if(colour[graph[num][i]]==-1){
                            if(col==0){
                                colour[graph[num][i]]=1;
                                q.push({graph[num][i],1});
                            }
                            else{
                                colour[graph[num][i]]=0;
                                q.push({graph[num][i],0});
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};