class Solution {
    private int tot = 0;
    private Edge[] edge;
    private int[] head;
    private int[] dp;
    private int[] nodesum;
    private int[] dissum;
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        edge = new Edge[2 * N + 5];
        head = new int[N + 5];
        dp = new int[N + 5];
        nodesum = new int[N  + 5];
        dissum = new int[N];
        Arrays.fill(head,-1);
        for (int i = 0;i < edges.length;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(0,0);
        dissum[0] = dp[0];
        dfs2(0,0,N);
        return dissum;
    }

    public void addedge(int u,int v){
        edge[tot] = new Edge();
        edge[tot].u = u;
        edge[tot].v = v;
        edge[tot].next = head[u];
        head[u] = tot++;
    }

    public void dfs1(int u,int fa){
        dp[u] = 0;
        nodesum[u] = 1;
        for (int i = head[u];i != -1;i = edge[i].next){
            int v = edge[i].v;
            if (v == fa)    continue;
            dfs1(v,u);
            dp[u] += dp[v] + nodesum[v];
            nodesum[u] += nodesum[v];
        }
    }

    public void dfs2(int u,int fa,int sum){
        for (int i = head[u];i != -1;i = edge[i].next){
            int v = edge[i].v;
            if (v == fa)    continue;
            dissum[v] = dissum[u] - nodesum[v] + sum - nodesum[v];
            dfs2(v,u,sum);
        }
    }
    class Edge{
        int u,v,next;
    }
}