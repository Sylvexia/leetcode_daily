class Solution {
    struct Node {
        int ch[26];
        int min_sz;
        int best_i;

        Node() {
            memset(ch, -1, sizeof(ch));
            min_sz = INT_MAX;
            best_i = 0;
        }
    };

    vector<Node> trie;

    void insert(const string& w, int idx) {
        int cur = 0;

        // update root
        if (trie[cur].min_sz > w.size()) {
            trie[cur].min_sz = w.size();
            trie[cur].best_i = idx;
        }

        for (int j = w.size() - 1; j >= 0; --j) {
            int c = w[j] - 'a';

            if (trie[cur].ch[c] == -1) {
                trie[cur].ch[c] = trie.size();
                trie.emplace_back();
            }

            cur = trie[cur].ch[c];

            if (trie[cur].min_sz > w.size()) {
                trie[cur].min_sz = w.size();
                trie[cur].best_i = idx;
            }
        }
    }

    int find(const string& q) {
        int cur = 0;

        for (int j = q.size() - 1; j >= 0; --j) {
            int c = q[j] - 'a';

            if (trie[cur].ch[c] == -1)
                break;

            cur = trie[cur].ch[c];
        }

        return trie[cur].best_i;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.emplace_back(); // root

        for (int i = 0; i < wordsContainer.size(); ++i)
            insert(wordsContainer[i], i);

        vector<int> res;
        for (auto& q : wordsQuery)
            res.push_back(find(q));

        return res;
    }
};
