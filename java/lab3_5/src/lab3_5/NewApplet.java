/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab3_5;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.Toolkit;
public class NewApplet extends Applet {
    public void paint(Graphics g)
    {
        g.setColor(Color.pink);
        g.fillOval(100,50,150,20);
        g.drawLine(100,60,70,150);
        g.drawLine(250,60,280,150);
        g.fillOval(70,145,210,15);
        g.drawLine(150,145,130,200);
        g.drawLine(180,145,200,200);
        g.setColor(Color.blue);
        g.drawRect(100,200,130,12);
        g.setColor(Color.LIGHT_GRAY);
        g.fillOval(120,80,12,50);
        g.fillOval(210,80,12,50);
        g.fillOval(150,80,40,50);
        
    }

    
}
