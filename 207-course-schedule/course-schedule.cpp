class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> indegree(numCourses,0);
        vector <vector<int>> adj(numCourses);

        for (auto& it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue <int> q;
        for (int i=0;i<numCourses;++i){
            if (indegree[i]==0) q.push(i);
        }
        vector<int> result;
        int count=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            result.push_back(u);
            count++;
            for (int v:adj[u]){
                indegree[v]--;
                if (indegree[v]==0) q.push(v);
            }


        }
        if (count==numCourses) return 1;
        return 0;
    }
};