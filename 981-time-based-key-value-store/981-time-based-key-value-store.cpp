// class TimeMap {
// public:
//     unordered_map<string,unordered_map<int,string>>mpp;
//     vector<int>v;
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         mpp[key][timestamp] = value;
//         v.push_back(timestamp);
//     }
    
//     string get(string key, int timestamp) {
//         int b = 0;
//         int e = v.size()-1;
//         int m;
//         while(b<e){
//             m = b+((e-b)/2);
//             if(timestamp == v[m]) return mpp[key][v[m]];
//             else if(v[m]>timestamp) e = m-1;
//             else if(v[m]<timestamp) b = m+1;
//         }
//         if(v[m]>timestamp) return "";
//         return mpp[key][v[m]]; 
//     }
// };

// /**
//  * Your TimeMap object will be instantiated and called as such:
//  * TimeMap* obj = new TimeMap();
//  * obj->set(key,value,timestamp);
//  * string param_2 = obj->get(key,timestamp);
//  */


class TimeMap {
public:
unordered_map<string,vector<pair<string,int>>> mpp;
//i guess stack is not an option stack s;
TimeMap() {

}

void set(string key, string value, int timestamp) {
    
    pair<string,int> p;
    p = make_pair(value,timestamp);
    mpp[key].push_back(p);
}

string get(string key, int timestamp) {
    
    string res = "";
    
    int n = mpp[key].size();
    int l = 0, r = n-1;
    //binary search
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(mpp[key][mid].second<=timestamp)
        {
            l = mid+1;
            res = mpp[key][mid].first;
        }
        else
        {
            r = mid-1;
        }
    }
    return res;
}
};