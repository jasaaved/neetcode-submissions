#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter {
public:
    Twitter() {
        time = 0;
        most_recent = 10;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time});
        ++time;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, Comparer> pq;
        const unordered_set<int>& followers_set = followers[userId];

        for(const auto& follower : followers_set){
            addPQ(pq, tweets[follower]);
        }

        addPQ(pq, tweets[userId]);

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
    struct Tweet{
        int tweetId;
        int time;
    };

    struct Comparer{
        bool operator()(const Tweet& a, const Tweet& b) const {
            return a.time < b.time;
        }
    };

    void addPQ(priority_queue<Tweet, vector<Tweet>, Comparer>& pq, const vector<Tweet>& user_tweets){
        const int n = static_cast<int>(user_tweets.size());
        const int stop = max(0, n - most_recent);

        for(int i = n - 1; i >= stop; --i){
            pq.push(user_tweets[i]);
        }
    }

    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> followers;
    int time;
    int most_recent;
};
