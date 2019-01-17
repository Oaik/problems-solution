
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger; 
import java.util.Scanner; 

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger cur = new BigInteger("0");
		BigInteger b1;
		Vector v = new Vector();
		for(int i = 1; i < 50001; ++i) {
			b1 = new BigInteger( Integer.toString(i)); 
			BigInteger result = b1.pow(3);
			cur = cur.add(result);;
			v.add(cur);
		}
		int n;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			n = sc.nextInt();
			System.out.println(v.get(n-1));
		}
		System.out.println();
	}
}
