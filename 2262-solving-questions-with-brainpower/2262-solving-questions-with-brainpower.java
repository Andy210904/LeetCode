class Solution {
    long[] cache;
    public long backtrack(int index, int[][] questions) {
        if (index >= questions.length) {
            return 0;
        }
        if (cache[index] != -1) {
            return cache[index];
        }
        long skip = backtrack(index + 1, questions);
        long take = questions[index][0] + backtrack(index + 1 + questions[index][1], questions);
        return cache[index] = Math.max(skip, take);
    }
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        cache = new long[n]; 
        Arrays.fill(cache, -1); 
        return backtrack(0, questions);
    }
}
