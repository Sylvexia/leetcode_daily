// 535. Encode and Decode TinyURL

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
    long long id = 6942023543;
    const string BASE =
        "0123456789abcdefghijklmmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-_";

    string toBase62(long long x)
    {
        string res;
        while (x) {
            res.push_back(BASE[x % 64]);
            x /= 64;
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        if (longToShort.count(longUrl))
            return longToShort[longUrl];

        string key = toBase62(id++);
        shortToLong[key] = longUrl;
        string shortUrl = "http://tinyurl.com/" + key;
        longToShort[longUrl] = shortUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        string key = shortUrl.substr(shortUrl.find_last_of('/') + 1);
        return shortToLong[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main()
{
    Solution sol;
    string shortUrl = sol.encode("https://uwu.com");
    string longUrl = sol.decode(shortUrl);
    cout << shortUrl << "\n";
    cout << longUrl << "\n";
    return 0;
}