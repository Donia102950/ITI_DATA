/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab5_1;

import java.applet.Applet;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class ButtonPressed extends Applet
{
    int x;
    Button inc,dec;
    
    public void init()
    {
        inc=new Button("Increment");
        dec=new Button("Decrement");
        
        inc.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e) {
              if(x<10)
                x++;
              repaint();
            }
        });
        add(inc);
        dec.addActionListener(new ActionListener()
        {

            @Override
            public void actionPerformed(ActionEvent e) {
                if(x>0)
                    x--;
                repaint();
            }
        });
        
        add(dec);
        
        
    }
        public void paint(Graphics g)
        {
           g.drawString("The count now"+x,50,200); 
        }
    }
