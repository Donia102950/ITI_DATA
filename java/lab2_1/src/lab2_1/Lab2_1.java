/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//calculator 

package lab2_1;

public class Lab2_1 {

    public static void main(String[] args) {
        String s=new String();
        int x=0;
        int res=0;
        for(int i=0;i<args.length;i++)
        {
            if(i==0)
            {
                res=Integer.parseInt(args[0]);
            }
            else if(i%2==1)
            {
              
                if(i+1>=args.length)
                {
                    System.out.println("There is wrong operation");
                    break;
                }
                x=Integer.parseInt(args[i+1]);
                switch(args[i])
                {
                    case "+":
                        System.out.println("x: "+x);
                        res+=x;
                        break;
                    case "-":
                        res-=x;
                        break;
                    case "/":
                        res/=x;
                        break;
                    case "*":
                        res*=x;
                        break;
                }
            }
        }
        System.out.println("the result is "+res);
    }
    
}
