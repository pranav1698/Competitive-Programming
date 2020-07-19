// Implementation of non reqpeating character using queue and hashmap
// SlothyCoder16
// July 20, 2020

string Solution::solve(string v) {
    map<char,int> mp;
    queue<char>q;
    string res;
    for(int i=0;i<v.length();i++){
        if(mp.find(v[i])==mp.end()){
            //char not found in map
            q.push(v[i]);
        }
        mp[v[i]]++;
        if(!q.empty() && q.front() == v[i] ) {
            //cleaning q top if it encountered q.front()
            while(!q.empty() && mp[q.front()]>1){
                q.pop();

            }
        }

        if(q.empty()){
            res.push_back('#');
        } else{
            res.push_back(q.front());
        }
    }
    return res;
}
