/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab6_3_a;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import static java.lang.System.in;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ChatServer  {

    ServerSocket myServer;
    
    
    
    public ChatServer() 
    {
        try{
           myServer =new ServerSocket(5005); 
           while(true)
           {
               Socket mySocket=myServer.accept();
               new ChatHandler(mySocket);
           }
        }catch(IOException ex)
        {
            System.out.println("the server not initialize");
        }
        
        
    }
    public static void main(String[] args) {
        new ChatServer();
    }
}
    class ChatHandler extends Thread
    {
        DataInputStream inn;
        PrintStream outt;
        static Vector<ChatHandler> clients= new Vector<ChatHandler>();
        
        ChatHandler(Socket s)
        {
            try {
                inn =new DataInputStream(s.getInputStream());
                outt=new PrintStream(s.getOutputStream());
            } catch (IOException ex) {
               System.out.println("The inputs&outputs not correct ");
            }
            
            clients.add(this);
            start();
            
        }
    
    
      public void run() {
         while(true)
            {
               String str;
             try {
                 str = inn.readLine();
                  sendMessageToAll(str);
             } catch (IOException ex) {
                 Logger.getLogger(ChatHandler.class.getName()).log(Level.SEVERE, null, ex);
             }
              

             }    
    }
    void sendMessageToAll(String msg)
{
for(ChatHandler ch : clients)
{
ch.outt.println(msg);
}
}
    }

