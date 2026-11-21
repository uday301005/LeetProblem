#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);

        auto dfsModified = [&](auto self, int u) -> void {
            char currChar = s[u];
            int prevNode = last[currChar - 'a'];

            if (prevNode != -1) {
                newParent[u] = prevNode;
            }

            last[currChar - 'a'] = u;

            for (int v : adj[u]) {
                self(self, v);
            }

            last[currChar - 'a'] = prevNode;
        };

        dfsModified(dfsModified, 0);

        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; ++i) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> subtreeSize(n, 1);

        auto dfsSize = [&](auto self, int u) -> void {
            for (int v : newAdj[u]) {
                self(self, v);
                subtreeSize[u] += subtreeSize[v];
            }
        };

        dfsSize(dfsSize, 0);

        return subtreeSize;
    }
};