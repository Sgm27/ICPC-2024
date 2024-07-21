/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Asus
 */
import java.util.*;
import java.math.BigInteger;
public class ICPCI {
    public static void main(String[] argc)
    {
        Scanner input = new Scanner(System.in);
        BigInteger ans= new BigInteger(Integer.toString(0));
        while (input.hasNext())
        {
            String s= input.next();
            int check=0;
            for (int i=0;i<s.length();i++)
                if (!(s.charAt(i)>='0'&&s.charAt(i)<='9'))
                    check=1;
            if (check==1)
                continue;
            BigInteger a= new BigInteger(Long.toString(Long.MAX_VALUE));
            BigInteger b= new BigInteger(Long.toString(Integer.MAX_VALUE));
            BigInteger c= new BigInteger(s);
            if (c.compareTo(b)==1&&c.compareTo(a)!=1)
                ans=ans.add(c);
           
        } 
        System.out.println(ans);
    }
}
