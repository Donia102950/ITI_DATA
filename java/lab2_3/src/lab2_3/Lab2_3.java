/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab2_3;

public class Lab2_3 {
    public static void main(String[] args) {
        String seperated="\\.";
        String[] ip=args[0].split(seperated);
        System.out.println("The ip written is ");
        for(int i=0;i<ip.length;i++)
        {
            System.out.println(ip[i]);
        }
    }
    
}

/*package lab2_3;

import java.util.StringTokenizer;

public class Lab2_3 {
    public static void main(String[] args) {
        //String seperated="\\.";
        StringTokenizer st=new StringTokenizer(args[0],".");
        //st.nextToken(seperated);
        System.out.println("The ip written is ");
        while(st.hasMoreTokens())
        {
            System.out.println(st.nextToken());
        }
    
    }
    
}*/
