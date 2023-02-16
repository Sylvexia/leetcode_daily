// 355. Design Twitter

#include <bits/stdc++.h>

using namespace std;

class Twitter
{
    unordered_map<int, unordered_set<int>> follow_map;
    vector<pair<int, int>> tweet_vec;

public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        tweet_vec.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<pair<int, int>> temp_vec;
        temp_vec = tweet_vec;
        vector<int> res;

        while (res.size() < 10 && !temp_vec.empty())
        {
            auto [user, tweet] = temp_vec.back();
            temp_vec.pop_back();

            if ((user == userId) or (follow_map[userId].find(user) != follow_map[userId].end()))
                res.push_back(tweet);
        }
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        follow_map[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        follow_map[followerId].erase(followeeId);
    }
};