class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {

        HashMap<Integer, HashSet<Integer>> map = new HashMap<>();

        for (int[] seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            map.putIfAbsent(row, new HashSet<>());
            map.get(row).add(col);
        }

        int count = (n - map.size()) * 2;
        //System.out.println(count);

        for (int row : map.keySet()) {

            HashSet<Integer> seats = map.get(row);

            boolean left = true;
            boolean right = true;
            boolean middle = true;

            // 2,3,4,5
            for (int j = 2; j <= 5; j++) {
                if (seats.contains(j)) {
                    left = false;
                    break;
                }
            }

            // 6,7,8,9
            for (int j = 6; j <= 9; j++) {
                if (seats.contains(j)) {
                    right = false;
                    break;
                }
            }

            // 4,5,6,7
            for (int j = 4; j <= 7; j++) {
                if (seats.contains(j)) {
                    middle = false;
                    break;
                }
            }

            if (left && right)
                count += 2;
            else if (left || middle || right)
                count += 1;
        }

        return count;
    }
}