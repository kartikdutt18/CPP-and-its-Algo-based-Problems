//https://leetcode.com/problems/happy-number/submissions/
import java.io.*;
import java.util.*;

class Solution {
    public int sumOfSquares(int n) {
        int t = 0;
        while (n > 0) {
            t += (n % 10) * (n % 10);
            n /= 10;
        }
        return t;
    }

    public boolean isHappy(int n) {
        Set<Integer> s = new HashSet<Integer>();
        while (!s.contains(n) && n != 1) {
            s.add(n);
            n = sumOfSquares(n);
            // System.out.println(n);

        }
        if (n == 1)
            return true;
        return false;
    }
}