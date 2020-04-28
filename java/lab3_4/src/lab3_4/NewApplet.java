/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab3_4;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.Toolkit;
public class NewApplet extends Applet {

    public void paint(Graphics g)
    {
        //g.setColor(Color.pink);
        //g.fillOval(100,50,150,15);
        //g.drawLine(100,50,50,0);
        
        Polygon poly = new Polygon();                // Roof Polygon
        poly.addPoint (50,90);
        poly.addPoint (150, 50);
        poly.addPoint (250, 90);
        g.setColor (new Color(218,165,32));      // Custom brown color
        g.fillPolygon (poly);

        g.setColor (Color.black);  
        g.drawLine (50, 90, 150, 50);     // Roof outline
        g.drawLine (150, 50, 250, 90);

  g.setColor (Color.yellow);            
  g.fillRect (50, 90, 200, 100);  // House base with houseColor
  g.setColor (Color.black);  
  g.drawRect (50, 90, 200, 100);  // House outline

  g.setColor (Color.black);
  g.fillRect (75, 110, 30, 25);   // Window 1
  g.fillRect (190, 110, 30, 25);  // Window 2    

  g.setColor (Color.blue);
  g.drawLine (75, 123, 105, 123);   // Window Frame 1
  g.drawLine (89, 110, 89, 134);
  g.fillRect (70, 110, 5, 25);      // Shutter 1
  g.fillRect (105, 110, 5, 25);     // Shutter 2
g.drawLine (75+115, 123, 105+115, 123);   // Window Frame 2
  g.drawLine (89+115, 110, 89+115, 134);
  g.fillRect (70+115, 110, 5, 25);     // Shutter 3
  g.fillRect (105+115, 110, 5, 25);     // Shutter 4

  g.setColor (Color.blue);
  g.fillRect (130, 150, 35, 40);  // Door

  g.setColor (Color.red);           
  g.fillOval (155, 170, 4, 4);    // Door knob
    }
   
}
