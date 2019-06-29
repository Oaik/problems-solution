/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public static void main(String[] args) {
	BigInteger m;
    int n;
    Scanner in = new Scanner(System.in);
    while(in.hasNext()) {
	    n = in.nextInt();
        m = in.nextBigInteger();
        int can;
        long lo = 1, hi = 1000000000, mid;
        while(lo <= hi) {
            BigInteger ans = new BigInteger("1");
            mid = lo + (hi - lo) / 2;
            for (int i = 0; i < n; i++) {
                ans = ans.multiply(BigInteger.valueOf(mid));
            }
            can = ans.compareTo(m);
            if(can == 0) {
                System.out.println(mid);
    	        break;
            } else if(can < 0) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
	        }
    	}
	}
}
