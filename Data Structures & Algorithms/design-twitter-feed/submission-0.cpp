#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Tweet{
        int tweetId;
        int time;
};

class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        followers[userId].insert(userId);
        tweets[userId].push_back({tweetId, time});
        ++time;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, Compare> pq;

        for(const auto& follower : followers[userId]){
            int n = static_cast<int>(tweets[follower].size());
            int stop = max(0, n - 10);
            while(n > stop){
                pq.push(tweets[follower][n - 1]);
                --n;
            }
        }
        vector<int> ans;
        while(!pq.empty() && ans.size() < 10){
            ans.push_back(pq.top().tweetId);
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }

private:
    int time = 0;
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> followers;

    

    struct Compare{
        bool operator()(const Tweet& a, const Tweet& b) const {
            return a.time < b.time;
        }
    };


};
