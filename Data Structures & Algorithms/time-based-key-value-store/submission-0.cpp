class TimeMap {
    map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) return "";

        const auto& vals = it->second;
        int l = 0, h = vals.size();
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (vals[mid].first <= timestamp) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }

        if (l == 0) return "";
        return vals[l - 1].second;
    }
};
