/*
 * @lc app=leetcode.cn id=2039 lang=java
 *
 * [2039] 网络空闲的时刻
 */

// @lc code=start
class Solution {
    public int networkBecomesIdle(int[][] edges, int[] patience) {
        int n = patience.length;
        Vertex[] vertices = new Vertex[n];
        for (int i = 0; i < n; i++) {
            vertices[i] = new Vertex(patience[i]);
        }
        for (int[] edge : edges) {
            vertices[edge[0]].addEdge(vertices[edge[1]]);
            vertices[edge[1]].addEdge(vertices[edge[0]]);
        }

        Deque<Vertex> queue = new LinkedList<>();
        vertices[0].used = true;
        queue.add(vertices[0]);
        while (!queue.isEmpty()) {
            Vertex vertex = queue.removeFirst();
            for (Vertex next : vertex.edges) {
                if (next.used) {
                    continue;
                }
                next.used = true;
                next.distance = vertex.distance + 1;
                queue.addLast(next);
            }
        }

        int max = 0;
        for (int i = 1; i < vertices.length; i++) {
            Vertex vertex = vertices[i];
            int transmissionDelay = vertex.distance << 1;
            int packetCount = (transmissionDelay + vertex.patience - 1) / vertex.patience;
            int sendDelay = packetCount > 0 ? (packetCount - 1) * vertex.patience : 0;
            int time = sendDelay + transmissionDelay;
            max = Math.max(max, time);
        }
        return max + 1;
    }

    private static class Vertex {
        private final int patience;
        private boolean used;
        private List<Vertex> edges;
        private int distance;

        public Vertex(int patience) {
            this.edges = new ArrayList<>();
            this.patience = patience;
        }

        public void addEdge(Vertex next) {
            this.edges.add(next);
        }
    }
}
// @lc code=end
