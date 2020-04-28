/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Image;

public class NewApplet extends Applet {

    
    Image pic;  
    public void init()  
    {  
        pic = getImage(getDocumentBase(),getParameter("image1"));  
    }
  public void paint(Graphics g)
  {
      g.drawImage(pic,0,0,getWidth(),getHeight(),this);
     
   }
}
