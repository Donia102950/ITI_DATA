/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab5_3;

import java.applet.Applet;
import java.awt.Button;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

/**
 *
 * @author DELL
 */
public class PressedKey extends Applet{
    
    
    
    int x=100;
    int y=100;
    public void init() {
        
       
      this.addKeyListener(new KeyListener() {

          @Override
          public void keyTyped(KeyEvent e) {
              throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
          }

          @Override
          public void keyPressed(KeyEvent e) {
              switch(e.getKeyCode())
              {
                  case KeyEvent.VK_LEFT:
                      x-=10;
                      break;
                  case KeyEvent.VK_UP:
                      y-=10;
                      break;
                      
                  case KeyEvent.VK_RIGHT:
                      x+=10;
                      break;
                      
                  case KeyEvent.VK_DOWN:
                      y+=10;
                      break;
              }      
               repaint();       
                     
              }
          

          @Override
          public void keyReleased(KeyEvent e) {
             
          }
      });
        
    
      
      
        
    }

    @Override
    
       public void paint(Graphics g)
        {
           g.drawString("Donia",x,y); 
        }

    
}


