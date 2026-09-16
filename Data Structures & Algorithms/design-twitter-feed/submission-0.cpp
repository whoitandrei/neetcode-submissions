class Twitter {
    int timestamp = 0;
    // uid -> list (timestamp, tweetId)
    unordered_map<int, vector<pair<int, int>>> tweets;

    // uid -> set<uid>
    unordered_map<int, set<int>> follows;

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // (time, tweetId, ownerId, indexInOwnerVector)
        priority_queue<tuple<int, int, int, int>> pq;

        set<int> candidates = follows[userId];
        candidates.insert(userId);

        for (auto& uid : candidates) {
            auto it = tweets.find(uid);
            if (it != tweets.end() && !it->second.empty()) {
                int idx = it->second.size() - 1;
                auto [time, tweetId] = it->second[idx];
                pq.push({time, tweetId, uid, idx});
            }
        }

        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            auto [time, tweetId, uid, idx] = pq.top();
            pq.pop();
            res.push_back(tweetId);

            if (idx > 0) {
                idx--;
                auto [newTime, newTweetId] = tweets[uid][idx];
                pq.push({newTime, newTweetId, uid, idx});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
