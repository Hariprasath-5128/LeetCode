class Solution {
    public int romanToInt(String s) {
        int result = 0;
        int n = s.length();

        HashMap<Character, Integer> Map = new HashMap<>();
        Map.put('I', 1);
        Map.put('V', 5);
        Map.put('X', 10);
        Map.put('L', 50);
        Map.put('C', 100);
        Map.put('D', 500);
        Map.put('M', 1000);

        for(int i = 0; i < n; i++){
            char curr = s.charAt(i);

            if(i == n-1){
                //System.out.println(Map.get(curr));
                result += Map.get(curr);
                break;
            }

            char next = s.charAt(i+1);
            int currNum = Map.get(curr);
            int nextNum = Map.get(next);    

            if(currNum < nextNum){
                //System.out.println(nextNum - currNum);
                result += nextNum - currNum;
                i++;
            }
            else
                result += currNum;
        }

        return result;
    }
}