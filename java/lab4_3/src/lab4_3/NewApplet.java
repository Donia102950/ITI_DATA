

package lab4_3;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.util.logging.Level;
import java.util.logging.Logger;

public class NewApplet extends Applet implements Runnable {
    
    Thread th;
    int x=getWidth(),y=0,dx=50,dy=50;
    public void init() {
      th=new Thread(this);
      th.start();
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
    @Override
    public void run() {
       while(true)
       {
           repaint();
           try {
               th.sleep(500);
           } catch (InterruptedException ex) {
               Logger.getLogger(NewApplet.class.getName()).log(Level.SEVERE, null, ex);
               System.out.println("Sleep not support");
           }
       }
    }

   
}
