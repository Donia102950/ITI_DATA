/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab3_1;

import java.applet.*;
import java.awt.*;



public class NewApplet extends Applet {

    @Override
    public void paint(Graphics g) {
            //g.drawString("Hello java",20,80);
        
            String S=getParameter("string");
            g.drawString(S, 20, 80);
        
    }

 

    
}
