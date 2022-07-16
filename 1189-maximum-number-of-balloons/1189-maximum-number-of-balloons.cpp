class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m;
        m['b']=0;
        m['a']=0;
        m['l']=0;
        m['o']=0;
        m['n']=0;
        for(int i=0;i<text.size();i++){
            if(m.find(text[i])!=m.end())
                m[text[i]]++;
        }
        // if(m['o']>=2*m['b'] && m['l']>=2*m['b'])
        //     return m['b'];
        m['l']=m['l']/2;
        m['o']=m['o']/2;
        int mn = INT_MAX;
        for(auto i=m.begin();i!=m.end();i++){
            mn = min(mn,i->second);
        }
        // for(auto i:m){
        //     mn = min(mn,i.second);
        // }
        return mn;
        // return 0;
    }
};




// class Solution {
// public:
// int maxNumberOfBalloons(string text) {

//     unordered_map<char, int> mp, mp2;
//     for(auto &i : text)
//         mp[i]++;
    
//     string tmp = "balloon";
//     for(auto &i : tmp)
//         mp2[i]++;
    
//     int mn = INT_MAX;
//     for(auto &i : mp2)
//         if(mp.find(i.first) == mp.end())
//         {
//             mn = 0;
//             break;
//         }
//         else
//             mn = min(mn, mp[i.first] / i.second);
    
//     return mn;
// }
// };