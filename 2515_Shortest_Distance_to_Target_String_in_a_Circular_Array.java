class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {

        // If the starting index itself is the target
        if (words[startIndex].equals(target))
            return 0;

        int n = words.length;
        int i = (startIndex + 1) % n;

        int a = Integer.MAX_VALUE; // Forward distance
        int b = Integer.MAX_VALUE; // Backward distance

        int steps = 1;

        // Forward circular traversal
        while (i != startIndex) {
            if (words[i].equals(target)) {
                a = steps; // Store distance
                break;
            }
            i = (i + 1) % n;
            steps++;
        }

        // Reset for backward traversal
        i = (startIndex - 1 + n) % n;
        steps = 1;

        // Backward circular traversal
        while (i != startIndex) {
            if (words[i].equals(target)) {
                b = steps; // Store distance
                break;
            }
            i = (i - 1 + n) % n;
            steps++;
        }

        // Target not found
        if (a == Integer.MAX_VALUE && b == Integer.MAX_VALUE)
            return -1;

        // Return the shorter distance
        return Math.min(a, b);
    }
}
