/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab5_2;

import java.applet.Applet;
import java.awt.Button;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Level;
import java.util.logging.Logger;

public class BallPutton extends  Applet implements Runnable
{
    volatile int flag=0;
    Button b1,b2;
    
    Thread th;
    int x=getWidth(),y=0,dx=50,dy=50;
    
    public void init()
    {
        th=new Thread(this);
        if(flag==0)
             th.start();
        
        b1=new Button("Stop");
        b2=new Button("Start");
        add(b1);
        add(b2);
        b1.addActionListener(new ActionListener()
        {

            @Override
            public void actionPerformed(ActionEvent e) 
                
                {
                   //th.suspend();
                   flag=1;
                }
            
            
        });
        b2.addActionListener(new ActionListener()
        {

            @Override
            public void actionPerformed(ActionEvent e) {
                if(flag==1)
                {
                //th.resume();
                flag=0;
                }
                
            }
 
        
        });
    }
        public void run() {
        while(true)
        {
            if(flag==0)
            repaint();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                System.out.println("Sleep unsported");
            }
        }
    }
      public void paint(Graphics g)
       {
       x+=dx;
       y+=dy;
        if(x<=0)
        {
            g.setColor(Color.red);
            dx=-dx;
            //dy=-dy;
        }
        else if(y<=0)
        {
            g.setColor(Color.pink);
           dy=-dy;
        }
        else if(x>=getWidth())
        {
            g.setColor(Color.GREEN);
          dx=-dx;
        }
        else if(y>=getHeight())
        {
            g.setColor(Color.YELLOW);
            dy=-dy;
        }
        
        
        g.fillOval(x,y,50,50);
        
          
    }
    }

