class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> Integer.compare(a[0], b[0]));
        List<int[]> result = new ArrayList<>();

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < intervals.length; i++){
            int end2 = intervals[i][1];
            int start2 = intervals[i][0];

            if(end >= start2){
                //Overlapping
                end = Math.max(end, end2);
            }

            else{
                //Non-Overlapping
                result.add(new int[]{start, end});
                start = start2;
                end = end2;
            }
        }

        // Add the last interval
        result.add(new int[]{start, end});

        return result.toArray(new int[result.size()][]);
    }
}