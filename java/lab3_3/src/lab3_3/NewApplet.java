/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab3_3;


import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Toolkit;
public class NewApplet extends Applet {

    String[] s = Toolkit.getDefaultToolkit().getFontList();
    int x=0;
   public void paint(Graphics g)
   {
      for(String ff :s)
      {
          Font f=new Font(ff,1,30);
          g.setFont(f);
          g.setColor(Color.pink);
          g.drawString("Donia",50,x+=35);
          
      }
   }

   
}
