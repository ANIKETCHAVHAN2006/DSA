class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<int> parent(n), size(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };

        int components = n;

        for (const auto& edge : connections) {
            int a = find(edge[0]);
            int b = find(edge[1]);

            if (a != b) {
                if (size[a] < size[b])
                    swap(a, b);
                parent[b] = a;
                size[a] += size[b];
                --components;
            }
        }

        return components - 1;
    }
};