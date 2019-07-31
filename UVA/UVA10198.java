import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;
import java.util.*;

public class Main {
    static public class Pair<A, B> {
        private A first;
        private B second;

        public Pair(A first, B second) {
            super();
            this.first = first;
            this.second = second;
        }

        public int hashCode() {
            int hashFirst = first != null ? first.hashCode() : 0;
            int hashSecond = second != null ? second.hashCode() : 0;

            return (hashFirst + hashSecond) * hashSecond + hashFirst;
        }

        public boolean equals(Object other) {
            if (other instanceof Pair) {
                Pair otherPair = (Pair) other;
                return
                        ((  this.first == otherPair.first ||
                                ( this.first != null && otherPair.first != null &&
                                        this.first.equals(otherPair.first))) &&
                                (  this.second == otherPair.second ||
                                        ( this.second != null && otherPair.second != null &&
                                                this.second.equals(otherPair.second))) );
            }

            return false;
        }

        public String toString()
        {
            return "(" + first + ", " + second + ")";
        }

        public A getFirst() {
            return first;
        }

        public void setFirst(A first) {
            this.first = first;
        }

        public B getSecond() {
            return second;
        }

        public void setSecond(B second) {
            this.second = second;
        }
    }

    static Map<Pair<Integer, Integer>, BigInteger> mp = new HashMap<Pair<Integer, Integer>, BigInteger>();
    static int n;
    static BigInteger DP(int sum, int num) {
        if(sum == n)
            return new BigInteger("1");
        if(sum > n)
            return new BigInteger("0");
        Pair<Integer, Integer> k = new Pair<Integer, Integer>(sum, num);
        boolean f = mp.containsKey(k);
        if(f)
            return mp.get(k);
        BigInteger ret = new BigInteger("0");
        ret = ret.add(DP(sum + 1, 1));
        ret = ret.add(DP(sum + 1, 4));
        ret = ret.add(DP(sum + 2, 2));
        ret = ret.add(DP(sum + 3, 3));
        mp.put(k, ret);
        return ret;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger m;
        n = 1000;
        m = DP(0, 1);
        while(in.hasNextInt()) {
            n = in.nextInt();
            Pair<Integer, Integer> k = new Pair<Integer, Integer>(1000 - n, 1);
            m = mp.get(k);
            System.out.println(m);
        }
    }
}
