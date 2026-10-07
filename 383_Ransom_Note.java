class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] freq = new int[26];

        for(char c: magazine.toCharArray()){
            freq[c - 'a']++;
        }

        for(char c: ransomNote.toCharArray()){
            freq[c - 'a']--;
        }

        for(int i: freq){
            if(i < 0)
                return false;
        }

        return true;
    }
}
