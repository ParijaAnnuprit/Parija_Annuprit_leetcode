class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>res;
        for(auto c: paths){
            stringstream str(c);
            string dir;
            string file;
            getline(str,dir,' ');
            while(getline(str,file,' ')){
                string content = file.substr(file.find('(')+1, file.find(')')-file.find('(')-1);
                mpp[content].push_back(dir + "/" + file.substr(0, file.find('(')));
            }
        }
        for(auto i:mpp){
            if(i.second.size()>1)
                res.push_back(i.second);
        }
        return res;
    }
};