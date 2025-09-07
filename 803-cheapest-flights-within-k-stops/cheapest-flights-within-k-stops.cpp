class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue <pair<int,pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}}); //stops,node,cost

        while(!q.empty()){            
            int curr_stops=q.front().first;
            int curr_node=q.front().second.first;
            int curr_cost=q.front().second.second;
            q.pop();
            if (curr_stops>k) continue;
            for (auto& flight:flights){
                if (flight[0]==curr_node){
                    int adjnode=flight[1];
                    int weight=flight[2];
                    if (curr_cost+weight<dist[adjnode]){
                        dist[adjnode]=curr_cost+weight;
                        q.push({curr_stops+1,{adjnode,dist[adjnode]}});                  
                    }
                }
                }
            }
        if (dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};