class Solution {
    public int minimumPushes(String word) {
        int n = word.length();
        int[] freq = new int[26];
        int cost = 0;

        for (int i = 0; i < word.length(); i++) {
            freq[word.charAt(i) - 'a']++;
        }

        Arrays.sort(freq);
        int idx = 0;

        for(int i = 25; i >= 0; i--){
            if(freq[i] == 0)
                break;

            cost += freq[i] * ((idx/8) + 1);
            idx++;
        }

        return cost;
    }
}
