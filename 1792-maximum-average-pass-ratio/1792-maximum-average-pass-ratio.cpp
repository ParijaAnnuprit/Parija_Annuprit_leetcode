class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double cls = classes.size();
        double deltasum=0;
        priority_queue<pair<double,pair<int,int>>>q;
        for(int i=0;i<classes.size();i++){
            int pass = classes[i][0];
            int total = classes[i][1];
            deltasum += (double) pass/total;
            double delta = (double)(pass+1)/(total+1) - (double)(pass)/(total);
            q.push({delta,{++pass,++total}});
        }
        while(extraStudents--){
            int pass = q.top().second.first;
            int total = q.top().second.second;
            deltasum += q.top().first;
            double newdelta = (double)(pass+1)/(total+1) - (double)(pass)/(total);
            q.pop();
            q.push({newdelta,{++pass,++total}});
        }
        
        return deltasum/cls;
                                                                             
    }
};


