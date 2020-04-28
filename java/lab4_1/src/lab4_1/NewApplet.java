/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab4_1;

import java.applet.Applet;
import java.awt.Graphics;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

public class NewApplet extends Applet implements Runnable{

    Thread th; 
    public void init() {
        th=new Thread(this);
        th.start();
    }
    public void paint(Graphics g)
    {
        Date d=new Date();
        g.drawString(d.toString(),20,20);
    }
    @Override
    public void run() {
        while(true)
        {
            repaint();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(NewApplet.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("Sleep unsported");
            }
        }
    }

   
}
