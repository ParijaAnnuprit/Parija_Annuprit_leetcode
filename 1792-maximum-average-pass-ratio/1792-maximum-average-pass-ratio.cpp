// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {\
//         double deltasum=0;
//         priority_queue<pair<double,pair<int,int>>>q;
//         for(int i=0;i<classes.size();i++){
//             int pass = classes[i][0];
//             int total = classes[i][1];
//             deltasum += (double) pass/total;
//             double delta = (double)(pass+1)/(total+1) - (double)(pass)/(total);
//             q.push({delta,{++pass,++total}});
//         }
//         while(extraStudents--){
//             int pass = q.top().second.first;
//             int total = q.top().second.second;
//             deltasum += q.top().first;
//             double newdelta = (double)(pass+1)/(total+1) - (double)(pass)/(total);
//             q.pop();
//             q.push({newdelta,{++pass,++total}});
//         }
//         return deltasum;
                                                                             
//     }
// };


struct klass {
    int pass;
    int total;
    double ratio;
    klass() {}
    klass(int pass, int total) {
        this->pass = pass;
        this->total = total;
        update_ratio();
    }
    void update_ratio() { ratio = pass * 1.0 / total; }
    void increase(int by = 1) {
        pass += by;
        total += by;
        update_ratio();
    }
    double delta() {
        return (pass + 1) * 1.0 / (total + 1) - (pass)*1.0 / (total);
    }
    bool operator()(klass &a, klass &b) { return a.delta() < b.delta(); }
};

class Solution {
   public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
        priority_queue<klass, vector<klass>, klass> pq;
        int total = classes.size();
        double sum = 0;
        klass k;
        for (auto i : classes) {
            k = klass(i[0], i[1]);
            pq.push(k);
        }
        while (extraStudents--) {
            k = pq.top();
            pq.pop();
            k.increase();
            pq.push(k);
        }
        while (pq.size()) {
            sum += pq.top().ratio;
            pq.pop();
        }
        return sum / total;
    }
};