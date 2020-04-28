package lab1_2;

import java.util.Scanner;
public class Lab1_2 {

    public static void main(String[] args) {
        float real,img;
        Complex c1 =new Complex();
        Complex c2 =new Complex();
        Scanner reader=new Scanner(System.in);
        System.out.println("please enter the first real number ");
        real=reader.nextFloat();
        System.out.println("please enter the first img number ");
        img=reader.nextFloat();
        c1.setReal(real);
        c1.setImg(img);
        c1.printComplex();
        
        System.out.println("please enter the first real number ");
        real=reader.nextFloat();
        System.out.println("please enter the first img number ");
        img=reader.nextFloat();
        c2.setReal(real);
        c2.setImg(img);
        
        System.out.println("the sum of two complex ");
        Complex.addComplex(c1,c2);
        
        System.out.println("the sub of two complex ");
        Complex.subtractComplex(c1, c2);
        
    }
    
}
