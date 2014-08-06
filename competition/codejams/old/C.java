import java.util.*;
import java.math.*;

public class C
{
	public static void main(String[] args)
	{
		String num;
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		
		
		
	}

	static boolean isPali(String a)
	{
		for(int i = 0; i < a.length()/2; i++)
			if (a.charAt(i) != a.charAt(a.length()-i))
				return false;
		return true;
	}	
	
	static BigInteger sqrt(BigInteger n) {
	  BigInteger a = BigInteger.ONE;
	  BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
	  while(b.compareTo(a) >= 0) {
		BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		else a = mid.add(BigInteger.ONE);
	  }
	  return a.subtract(BigInteger.ONE);
	}
}
