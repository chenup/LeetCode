struct cmp{  
    bool operator() (const pair<int, int>& a, const pair<int, int>& b )
    {   
        return a.first < b.first;   
    }  
}; 

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() : timestamp(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        news[userId].push_back({tweetId, ++timestamp});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        unordered_map<int, int> pos;
        unordered_map<int, pair<int, int>> tmp;
        priority_queue<int> max_heap;
        vector<int> res;
        if(!news[userId].empty() && follows[userId].find(userId) == follows[userId].end())
        {
            int p = news[userId].size() - 1;
            pos[userId] = p - 1;
            auto t = news[userId][p];
            tmp[t.second] = {t.first, userId};
            max_heap.push(t.second);
        }   
        for(auto id : follows[userId])
        {
            if(!news[id].empty())
            {
                int p = news[id].size() - 1;
                pos[id] = p - 1;
                auto t = news[id][p];
                tmp[t.second] = {t.first, id};
                max_heap.push(t.second);
            }            
        }
        int i = 0;
        while(i < 10)
        {
            if(max_heap.empty())
            {
                break;
            }
            int r = max_heap.top();
            max_heap.pop(); 
            auto t = tmp[r];
            res.push_back(t.first);
            tmp.erase(r);
            if(pos[t.second] >= 0)
            {
                auto s = news[t.second][pos[t.second]];
                tmp[s.second] = {s.first, t.second};
                max_heap.push(s.second);
                pos[t.second]--;
            }
            i++;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
private:
    unordered_map<int, vector<pair<int, int>>> news;
    unordered_map<int, set<int>> follows;
    int timestamp;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */