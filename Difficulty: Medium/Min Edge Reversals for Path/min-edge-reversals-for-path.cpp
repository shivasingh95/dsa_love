class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  

        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>visited(n+1,0);
        deque<pair<int,int>>q;
        q.push_front({src,0});
        int u = 0;
        int v = 0;

        for(int i=0;i<edges.size();i++){
            u=edges[i][0];
            v=edges[i][1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }

        while(!q.empty()){

            int node = q.front().first;
            int weight = q.front().second;
            q.pop_front();

            if(node==dst)return weight;
            if(visited[node])continue;

            visited[node]=1;

            for(int i=0;i<adj[node].size();i++){

                v = adj[node][i].first;
                int w = adj[node][i].second;
                if(visited[v])continue;
                if(w) q.push_back({v,w + weight});
                else  q.push_front({v,weight});

            }


        }

        return -1;
    }
};