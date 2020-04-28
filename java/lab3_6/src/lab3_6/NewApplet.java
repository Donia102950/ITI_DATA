/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab3_6;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;

public class NewApplet extends Applet {
      public void paint(Graphics g)
      {
          Image img;
          img = getImage(getDocumentBase(),"one.png"); 
          setBackground(Color.darkGray);
          g.fillRect(0,0,130,70);
          g.setColor(Color.pink);
          g.drawLine(130,70,110,120);
          g.drawLine(0,120,110,120);
          g.setColor(Color.black);
          g.drawLine(110,120,110,150);
          g.drawLine(130,70,130,100);
          g.fillOval(100,140,30,15);
          g.fillOval(120,90,30,15);
          g.setColor(Color.pink);
          g.drawLine(170,200,150,300);
          g.drawLine(400,200,370,300);
          g.drawLine(170,200,400,200);
          g.drawLine(150,300,370,300);
          g.drawImage(img,450,0,100,100, this);
          g.setColor(Color.black);
          g.drawLine(450,0,450,100);
          g.drawLine(550,0,550,100);
          g.drawLine(450,0,550,0);
          g.drawLine(450,100,550,100);
          g.setColor(Color.black);
          g.fillOval(200,150,150,20);
          g.drawLine(200,160,200,250);
          g.drawLine(350,160,350,250);
          g.setColor(Color.pink);
          g.fillOval(190,240,30,15);
          g.fillOval(340,240,30,15);
          //g.drawImage(img,0,0,130,70, this);
          
        g.setColor(Color.pink);
        g.fillOval(220,70,100,20);
        g.drawLine(220,80,210,130);
        g.drawLine(320,80,330,130);
        g.fillOval(200,125,150,15);
        g.drawLine(230,135,230,150);
        g.drawLine(320,135,320,150);
        g.setColor(Color.blue);
        //g.fillRect(210,150,130,10);
        g.setColor(Color.LIGHT_GRAY);
        g.fillOval(220,80,12,50);
        g.fillOval(310,80,12,50);
        //g.fillOval(150,80,40,50);
          
          
          
          
          
          
          
      }
}
