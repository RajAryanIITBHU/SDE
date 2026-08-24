// Link: https://leetcode.com/problems/design-twitter/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Hash Map Following + K-Way Merge Max-Heap for News Feed)
// ==========================================
// Time Complexity  : postTweet, follow, unfollow: O(1), getNewsFeed: O(F log 10) where F is followees
// Space Complexity : O(Users + Tweets)
/*
PSEUDOCODE:
1. Maintain globalTimestamp counter.
2. userTweets map: userId -> vector of pair<timestamp, tweetId>.
3. following map: userId -> unordered_set of followeeIds.
4. postTweet(userId, tweetId):
     userTweets[userId].push_back({++globalTimestamp, tweetId})
5. getNewsFeed(userId):
     Max-heap pq storing {timestamp, tweetId}.
     following[userId].insert(userId) // Include own tweets
     For each followee in following[userId]:
         Push recent tweets to pq.
     Extract top 10 most recent tweets.
*/

class Twitter {
private:
    int globalTimestamp;
    unordered_map<int, vector<pair<int, int>>> userTweets; // userId -> {timestamp, tweetId}
    unordered_map<int, unordered_set<int>> following;     // userId -> set of followees

public:
    Twitter() {
        globalTimestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({++globalTimestamp, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // Max-heap: {timestamp, tweetId}

        following[userId].insert(userId); // Self-follow to include own tweets

        for (int followeeId : following[userId]) {
            const auto& tweets = userTweets[followeeId];
            int count = 0;
            // Take at most 10 most recent tweets from each followee
            for (int i = (int)tweets.size() - 1; i >= 0 && count < 10; i--, count++) {
                pq.push(tweets[i]);
            }
        }

        vector<int> feed;
        int count = 0;
        while (!pq.empty() && count < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};
