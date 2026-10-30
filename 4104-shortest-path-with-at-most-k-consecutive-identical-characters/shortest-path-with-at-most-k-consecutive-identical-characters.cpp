#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // 1. Build weighted adjacency list: g[u] = {{neighbor, weight}, ...}
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            g[u].push_back({v, wt}); // Assuming directed; add reverse if undirected
        }

        // min_consec[u] stores the lowest consecutive streak count seen when POPPING node u
        vector<int> min_consec(n, INT_MAX);

        // Min-Heap ordered by cost: tuple<cost, node, consecutive_streak>
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        // Start at node 0: cost = 0, consecutive streak = 1 (node 0 itself)
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            // Structured binding to unpack tuple
            auto [curr_cost, curr_node, curr_consec] = pq.top();
            pq.pop();

            // 1. POP CHECK: Prune if this path's streak is >= a previous cheaper path's streak
            if (curr_consec >= min_consec[curr_node]) continue;

            // 2. UPDATE ON POP!
            min_consec[curr_node] = curr_consec;

            // Target reached! Guaranteed minimum cost due to Min-Heap
            if (curr_node == n - 1) return curr_cost;

            for (auto& edge : g[curr_node]) {
                int neigh_node = edge.first;
                int weight = edge.second;

                // Calculate new streak count
                int next_consec = (labels[neigh_node] == labels[curr_node]) ? curr_consec + 1 : 1;

                // Transition Guard: Must stay within 'k' consecutive matching labels
                if (next_consec <= k) {
                    // Push-time filter using min_consec
                    if (next_consec < min_consec[neigh_node]) {
                        // DO NOT set min_consec[neigh_node] here! Just push.
                        pq.push({curr_cost + weight, neigh_node, next_consec});
                    }
                }
            }
        }

        return -1; // Unreachable
    }
};