class Solution {
public int[] validSequence(String word1, String word2) {

    int n = word1.length();
    int m = word2.length();

    //last[j + 1] tells us the latest position in word1 where the remaining part of word2 can still be completed
    int[] last = new int[m];

    int j = m - 1;

    // Find the positions for matching word2 from the end
    for (int i = n - 1; i >= 0; i--) {
        if (j >= 0 && word1.charAt(i) == word2.charAt(j)) {
            last[j] = i;
            j--;
        }
    }

    int[] ans = new int[m];

    j = 0;
    int usedMismatch = 0;

    // Build the lexicographically smallest sequence
    for (int i = 0; i < n && j < m; i++) {

        // Exact match
        if (word1.charAt(i) == word2.charAt(j)) {
            ans[j] = i;
            j++;
        }

        // Use the one allowed mismatch
        // j == m - 1 ; Came to the last element in the word 2
        // Is there enough space after index i to complete the remaining word2?
        else if (usedMismatch == 0 &&
                (j == m - 1 || i + 1 <= last[j + 1])) {

            ans[j] = i;
            j++;
            usedMismatch = 1;
        }
    }

    if (j != m) {
        return new int[0];
    }

    return ans;
}
}