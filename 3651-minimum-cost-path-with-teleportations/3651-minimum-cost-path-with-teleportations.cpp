class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        vector<vector<vector<int>>> dist(
            m, vector<vector<int>>(n, vector<int>(k + 1, INF))
        );

        vector<tuple<int,int,int>> cells;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({grid[i][j], i, j});

        sort(cells.begin(), cells.end());

        vector<int> ptr(k + 1, 0);

        priority_queue<
            tuple<int,int,int,int>,
            vector<tuple<int,int,int,int>>,
            greater<>
        > pq;

        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        while (!pq.empty()) {
            auto [cost, i, j, used] = pq.top();
            pq.pop();

            if (cost > dist[i][j][used]) continue;
            if (i == m - 1 && j == n - 1) return cost;

            if (i + 1 < m) {
                int nc = cost + grid[i + 1][j];
                if (nc < dist[i + 1][j][used]) {
                    dist[i + 1][j][used] = nc;
                    pq.push({nc, i + 1, j, used});
                }
            }

            if (j + 1 < n) {
                int nc = cost + grid[i][j + 1];
                if (nc < dist[i][j + 1][used]) {
                    dist[i][j + 1][used] = nc;
                    pq.push({nc, i, j + 1, used});
                }
            }

            if (used < k) {
                while (ptr[used] < cells.size() &&
                       get<0>(cells[ptr[used]]) <= grid[i][j]) {

                    auto [v, x, y] = cells[ptr[used]];
                    if (cost < dist[x][y][used + 1]) {
                        dist[x][y][used + 1] = cost;
                        pq.push({cost, x, y, used + 1});
                    }
                    ptr[used]++;
                }
            }
        }

        return -1;
    }
};
