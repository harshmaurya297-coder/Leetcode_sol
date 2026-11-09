class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // n -> nodes of directed graph


        // adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // dist[node][count]
        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, LLONG_MAX)
        );  

        // {cost, node, consecutive_count}
        using State = tuple<long long, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        // Starting node has count = 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});


        while (!pq.empty()) {

            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt])
                continue;

            if (u == n - 1)
                return cost;

            for (auto [v, w] : adj[u]) {

                int newCount = 0;

                if (labels[u] == labels[v])
                    newCount = cnt + 1;
                else
                    newCount = 1;

                if (newCount > k)
                    continue;

                long long newCost = cost + w;

                if (newCost < dist[v][newCount]) {

                    dist[v][newCount] = newCost;

                    pq.push({
                        newCost,
                        v,
                        newCount
                    });
                }
            }
        }

        return -1;
    }
};