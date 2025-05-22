
class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string,string> mp;
    int n=1;
    string encode(string longUrl) {
        // string res="https://leetcode.com/"+to_string(n++);
        // mp[res]=longUrl;
        // return res;
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
      //  return mp[shortUrl];
      return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));