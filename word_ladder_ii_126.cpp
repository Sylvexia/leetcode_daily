// 126. Word Ladder II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string &beginWord, string &endWord, vector<string> &wordList)
    {
        unordered_map<string, int> nodeLadder;
        unordered_map<string, vector<string>> graph;
        vector<vector<string>> solution;
        vector<string> state{endWord};

        for (const string &word : wordList)
            nodeLadder[word] = INT_MAX;

        if (nodeLadder.count(endWord) == 0)
            return {};

        BFS(beginWord, endWord, graph, nodeLadder);
        DFS(beginWord, endWord, graph, state, solution);

        for (auto &path : solution)
            reverse(path.begin(), path.end());

        return solution;
    }

private:
    void BFS(const string &beginWord, const string &endWord, unordered_map<string, vector<string>> &graph,
             unordered_map<string, int> &nodeLadder)
    {
        queue<string> queue;
        queue.push(beginWord);

        int ladder = 1;
        while (queue.size())
        {
            int size = queue.size();

            while (size--)
            {
                string node = queue.front(), new_node = node;
                queue.pop();

                for (char &c : new_node)
                {
                    char backup_c = c;
                    for (int new_c = 'a'; new_c <= 'z'; new_c++)
                    {
                        c = new_c;
                        if (node != new_node && nodeLadder.count(new_node) && nodeLadder[new_node] >= ladder)
                        {
                            graph[new_node].emplace_back(node);
                            if (nodeLadder[new_node] == ladder)
                                continue;
                            nodeLadder[new_node] = ladder;
                            if (new_node != endWord)
                                queue.emplace(new_node);
                        }
                    }
                    c = backup_c;
                }
            }
            ladder++;
        }
    }

    void DFS(const string &target, const string &node, unordered_map<string, vector<string>> &graph,
             vector<string> &state, vector<vector<string>> &solution)
    {

        if (node == target)
        {
            solution.emplace_back(state);
            return;
        }

        for (const string &neighbor : graph[node])
        {
            state.emplace_back(neighbor);
            DFS(target, neighbor, graph, state, solution);
            state.pop_back();
        }
    }
};