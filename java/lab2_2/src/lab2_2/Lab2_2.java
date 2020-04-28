/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab2_2;

public class Lab2_2 {

    public static void main(String[] args) {
        int lines;
        int row,col,star=0;
        
        if(args.length>=1)
        {
        lines=Integer.parseInt(args[0]);
        
        for(int i=0;i<lines;i++)
        {
            for(int j=0;j<i;j++)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        }
        else
        {
            System.out.println("error in arquments ");
        }
        if(args.length==2)
        {
        row=Integer.parseInt(args[1]);
        
        
        for(int i=1;i<=row;i++)
        {
          for(col=i;col<=row-1;col++)
          {
              System.out.print(" ");
          }
          
          while(star!=(2*i-1))
          {
              System.out.print("*");
              star++;
          }
          star=0;
          System.out.println();
          
        }
        }
        if(args.length<2) 
        {System.out.println("The error done in arguments ");}
    
}
}
