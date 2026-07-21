import java.util.*;

class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        //Count the number of 1
        int ones = 0;
        for(char c: s.toCharArray()){
            if(c == '1')
                ones++;
        }

        String t = "1" + s + "1"; //Augment
        List<Character> ch = new ArrayList<>();
        List<Integer> len = new ArrayList<>();

        //Run length encoding
        int cnt = 1;

        for(int i = 1; i < t.length(); i++){
            if(t.charAt(i) == t.charAt(i-1)){
                cnt++;
            }
            else{
                ch.add(t.charAt(i-1));
                len.add(cnt);
                cnt = 1;
            }
        }

        // Add the last run
        ch.add(t.charAt(t.length() - 1));
        len.add(cnt);

        int maxGain = 0;

        //Finding the pattern of 0-1-0
        for(int i = 1; i < ch.size() - 1; i++){
            if(ch.get(i) == '1' && ch.get(i-1) == '0' && ch.get(i+1) == '0'){
                int gain = len.get(i-1) + len.get(i+1);
                maxGain = Math.max(gain, maxGain);
            }
        }

        return ones + maxGain;
    }
}
