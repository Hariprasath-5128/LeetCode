class Solution {
    public int[] circularGameLosers(int n, int k) {

        int turn = 1;
        int current = 1;
        boolean[] visited = new boolean[n + 1];
        List<Integer> result = new ArrayList<>();

        while(true){
            if(visited[current])
                break;

            // Mark the current friend as visited
            visited[current] = true;

            int next = (current + (turn * k)) % n;

            // If modulo gives 0, it actually means friend n
            if (next == 0)
                next = n;

            current = next;
            turn++;
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i])
                result.add(i);
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
