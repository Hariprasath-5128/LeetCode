class Solution {
    public String smallestSubsequence(String s) {

        // Step 1: Count the frequency of each character
        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++) {
            char t = s.charAt(i);
            freq[t - 'a']++;
        }

        // Step 2: Track whether a character is already in the stack
        boolean[] visited = new boolean[26];

        // Step 3: Use StringBuilder as a stack
        StringBuilder stack = new StringBuilder();

        // Step 4: Process each character
        for (char c : s.toCharArray()) {
            freq[c - 'a']--;

            if (visited[c - 'a'])
                continue;

            int top = stack.length() - 1;

            while (top + 1 > 0 &&
                   stack.charAt(top) > c &&
                   freq[stack.charAt(top) - 'a'] > 0) {

                char removed = stack.charAt(top);
                stack.deleteCharAt(top);
                top--;
                visited[removed - 'a'] = false;
            }

            stack.append(c);
            visited[c - 'a'] = true;
        }

        return stack.toString();
    }
}
