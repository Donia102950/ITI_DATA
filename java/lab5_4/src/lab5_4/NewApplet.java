/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab5_4;

import java.applet.Applet;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class NewApplet extends Applet implements MouseMotionListener{

    int x,y,x1,y1,i=0,j=0;
    int[]arr1=new int[20];
    int[]arr2=new int[20];
    int[]arr3=new int[20];
    int[]arr4=new int[20];
    
    
    public void init() {
        
       this.addMouseListener(new MouseListener()
       {

           @Override
           public void mouseClicked(MouseEvent e) {
           
           }

           @Override
           public void mousePressed(MouseEvent e) {
               
               x1=e.getX();
               y1=e.getY();
               
               arr1[i]=x1;
               arr2[i]=y1;
               i++;
           }

           @Override
           public void mouseReleased(MouseEvent e) {
               
           }

           @Override
           public void mouseEntered(MouseEvent e) {
               
           }

           @Override
           public void mouseExited(MouseEvent e) {
                         }
           
       });
       
      addMouseMotionListener(this);
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        x=e.getX();
        y=e.getY();
        arr3[i-1]=x;
        arr4[i-1]=y;
       
        repaint();
    }

    @Override
    public void mouseMoved(MouseEvent e){
        
    }

     
    public void paint(Graphics g)
        {
            
              int k;  
            for(k=0;k<arr1.length;k++) 
            {
           g.drawLine(arr1[k],arr2[k],arr3[k],arr4[k]);
            if(k==arr1.length)
            {
                System.out.println("no more lines");
                break;
            }
            }
            
            
        } 
}
