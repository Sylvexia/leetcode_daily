// 2115. Find All Possible Recipes from Given Supplies

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes,
                                  vector<vector<string>> &ingredients,
                                  vector<string> &supplies)
    {
        int n = recipes.size();

        unordered_map<string, vector<string>> graph;
        unordered_set<string> set;
        for (auto &s : supplies)
            set.insert(s);

        unordered_map<string, int> indegree;
        for (auto &r : recipes)
            indegree[r] = 0;


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ingredients[i].size(); j++) {
                if (set.find(ingredients[i][j]) == set.end()) {
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for (auto &[key, val] : indegree) {
            if (val == 0)
                q.push(key);
        }

        vector<string> res;
        while (!q.empty()) {
            string front = q.front();
            q.pop();
            res.push_back(front);
            for (auto &child : graph[front]) {
                indegree[child]--;
                if (indegree[child] == 0)
                    q.push(child);
            }
        }
        return res;
    }
};