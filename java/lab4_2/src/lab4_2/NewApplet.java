

package lab4_2;

import java.applet.Applet;
import java.awt.Graphics;
import java.util.logging.Level;
import java.util.logging.Logger;

public class NewApplet extends Applet implements Runnable {

    Thread th;
    int x=0,y=10;
    public void init() {
       th=new Thread(this);
       th.start();
       
    }
    public void paint(Graphics g)
    {
       String s=new String();
       s="Hello";
       if(x>=getWidth())
       {
           x=0;
       }
       g.drawString(s,x,y);
    }
    @Override
    public void run() {
        while(true)
        {
            x+=20;
            repaint();
            try {
                th.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(NewApplet.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("Sleep unstable");
            }
        }
    }
}
