/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab6_3_b;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;


public class Client1 extends JFrame implements Runnable {

    Socket mySocket;
    DataInputStream in;
    DataInputStream inn;
    PrintStream out;
    PrintStream out1;
    Thread th;
    String remsg=null;
    String remsg2=null;
    JTextArea ta;
    public static void main(String[] args) {
        
        Client1 c=new Client1();
        c.setSize(400, 500);
        c.setVisible(true);
    }
    
    public Client1() 
    {
        
        try {
            mySocket=new Socket("127.0.0.1",5005);
            in=new DataInputStream(mySocket.getInputStream());
            inn=new DataInputStream(mySocket.getInputStream());
            out=new PrintStream(mySocket.getOutputStream());
            out1=new PrintStream(mySocket.getOutputStream());
        } catch (IOException ex) {
            System.out.println("Cannot able to connect to server");
        }
            
           this.setLayout(new FlowLayout());
           ta=new JTextArea(5,30);
           JScrollPane scroll=new JScrollPane(ta);
           scroll.setViewportView(ta);
           JButton sendButton=new JButton("user");
           JTextField tf=new JTextField(10);
           JTextField tf2=new JTextField(10);
           JButton okButton=new JButton("send");
           
           sendButton.addActionListener(new ActionListener(){

            @Override
            public void actionPerformed(ActionEvent e) {
                     //out1.println(tf2.getText());
            }
        
         });
           okButton.addActionListener(new ActionListener()
           {

               @Override
               public void actionPerformed(ActionEvent e) {
                  //while(true)
                  //{
                      //ta.append(tf.getText()+"\n");
                   out1.println(tf2.getText());
                   out.println(tf.getText());
                   
                  //}
               } 
           });
           
           add(scroll);
           add(sendButton);
           add(tf);
           add(tf2);
           add(okButton);
            /*try
            {
                in.close();
                out.close();
                mySocket.close();
        }catch(Exception ex)
        {
            System.out.println("cannot able to close objects");
        }*/
           th=new Thread(this); 
                    
            th.start();
    }
      
   
    @Override
    public void run() {
        
        while(true)
        {
            try {
                remsg=in.readLine();
                remsg2=inn.readLine();
                
                ta.append(remsg2+":"+remsg+"\n");
            } catch (IOException ex) {
                Logger.getLogger(Client1.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
}
