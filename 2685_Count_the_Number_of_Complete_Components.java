import java.util.*;

class Solution {
    public int countCompleteComponents(int n, int[][] edges) {

        // Build adjacency List
        List<List<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        boolean[] visited = new boolean[n];
        int completeComponents = 0;

        // Traverse all the components
        for (int i = 0; i < n; i++) {

            if (visited[i])
                continue;

            List<Integer> component = new ArrayList<>();
            Queue<Integer> q = new LinkedList<>();

            q.offer(i); // insert the first node
            visited[i] = true;

            // BFS
            while (!q.isEmpty()) {

                int node = q.poll();
                component.add(node);

                for (int neighbor : adj.get(node)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.offer(neighbor);
                    }
                }
            }

            // Check if the component is complete
            int size = component.size();
            boolean complete = true;

            for (int node : component) {
                if (adj.get(node).size() != size - 1) {
                    complete = false;
                    break;
                }
            }

            if (complete)
                completeComponents++;
        }

        return completeComponents;
    }
}
