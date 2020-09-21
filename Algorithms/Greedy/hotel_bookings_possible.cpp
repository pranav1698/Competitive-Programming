// Hotel Bookings Possible depending on K
// SlothyCoder16
// September 22, 2020

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    if(K==0) return false;
    int N=arrive.size();

    vector<pair<int, int>> v;
    for(int i=0; i<N; i++) {
        v.push_back({arrive[i], 1});
        v.push_back({depart[i], 0});
    }
    sort(v.begin(), v.end());

    int currGuests=0;
    int maxGuests=0;
    for(int i=0; i<v.size(); i++) {
        if(v[i].second == 1) {
            currGuests++;
            maxGuests = max(maxGuests, currGuests);
        } else {
            currGuests--;
        }
    }

    if(K>=maxGuests) return true;
    return false;
}
