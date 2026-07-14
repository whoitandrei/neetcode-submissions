class LRUCache {
private:
    list<pair<int, int>> l_;
    map<int, list<pair<int, int>>::iterator> mp_;
    int capacity_;

public:
    LRUCache(int capacity) : capacity_(capacity) {
        
    }
    
    int get(int key) {
        auto it = mp_.find(key);
        if (it == mp_.end()) return -1;

        l_.splice(l_.begin(), l_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp_.find(key);
        if (it != mp_.end()) {
            it->second->second = value;
            l_.splice(l_.begin(), l_, it->second);
            return;
        }

        while (mp_.size() >= capacity_) {
            mp_.erase(l_.back().first);
            l_.pop_back();
        }

        l_.emplace_front(key, value);
        mp_[key] = l_.begin();
    }
};
