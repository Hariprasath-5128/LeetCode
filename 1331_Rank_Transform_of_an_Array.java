import java.util.*;

class Solution {
    public int[] arrayRankTransform(int[] arr) {

        if (arr.length == 0)
            return new int[0];

        List<List<Integer>> rankArr = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            List<Integer> temp = new ArrayList<>();

            temp.add(arr[i]); // value
            temp.add(i);      // original index
            temp.add(-1);     // rank

            rankArr.add(temp);
        }

        rankArr.sort((a, b) -> Integer.compare(a.get(0), b.get(0)));

        int r = 1;
        rankArr.get(0).set(2, r);

        for (int i = 1; i < arr.length; i++) {
            if (rankArr.get(i).get(0).equals(rankArr.get(i - 1).get(0))) {
                rankArr.get(i).set(2, r);
            } else {
                r++;
                rankArr.get(i).set(2, r);
            }
        }

        int[] getI = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            getI[rankArr.get(i).get(1)] = i;
        }

        int[] rank = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            rank[i] = rankArr.get(getI[i]).get(2);
        }

        return rank;
    }
}
