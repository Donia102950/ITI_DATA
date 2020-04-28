/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab1_2;

  class Complex {
    private float real;
    private float img;
    
    Complex()
    {
        real=0;
        img=0;
    }
    Complex(float x,float y)
    {
        real=x;
        img=y;
    }
    void setReal(float x)
    {
        real=x;
    }
    void setImg(float y)
    {
        img=y;
    }
    void printComplex()
    {
        if(img==0)
        {
           System.out.println("the complex number is "+real); 
        }
        else if(img==1)
        {
            System.out.println("the complex number is "+real+"+i");
        }
        else if(img==-1)
        {
            System.out.println("the complex number is "+real+"i");
        }
        else if(img<0)
        {
            System.out.println("the complex number is "+real+img+"i");
        }
        else
        {
            System.out.println(" the complex number is "+real+"+"+img+"i");
        }
    }
    static void addComplex(Complex c1,Complex c2)
    {
        Complex c3=new Complex();
        c3.real=c1.real+c2.real;
        c3.img=c1.img+c2.img;
        c3.printComplex();
    }
     static void subtractComplex(Complex c1,Complex c2)
    {
        Complex c3=new Complex();
        c3.real=c1.real-c2.real;
        c3.img=c1.img-c2.img;
        c3.printComplex();
    }
}
