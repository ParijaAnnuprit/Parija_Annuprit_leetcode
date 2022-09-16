class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adjls(n);
        priority_queue<pair<int,int>>q;
        long long res=0;
        long long w = n;
//         making an adjacency list storing all the nodes and their respective neighbours
        for(int i=0;i<roads.size();i++){
            adjls[roads[i][0]].push_back(roads[i][1]);
            adjls[roads[i][1]].push_back(roads[i][0]);
        }
//         queue stores the no of neighbours and the node to which they are attached
        for(int i=0;i<adjls.size();i++){
            int x = adjls[i].size();
            q.push({x,i});
        }
        while(!q.empty()){
            long long m = q.top().first* w;
            res+=m;
            w--;
            q.pop();
        }
       return res; 
    }
};