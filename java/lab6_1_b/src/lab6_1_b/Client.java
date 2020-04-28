/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab6_1_b;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;

public class Client {

    Socket mySocket;
    DataInputStream in;
    PrintStream out;
    public static void main(String[] args) {
        
        new Client();
    }
    
    public Client()
    {
        try
        {
            mySocket=new Socket("127.0.0.1",5005);
            in=new DataInputStream(mySocket.getInputStream());
            out=new PrintStream(mySocket.getOutputStream());
            out.println("hiiii");
            String m=in.readLine();
           
            System.out.println(m);
        }catch(IOException ex){
            System.out.println("Cannot able to connect to server");
       
                    }    
            try
            {
                in.close();
                out.close();
                mySocket.close();
        }catch(Exception ex)
        {
            System.out.println("cannot able to close objects");
        }
    }
    
}
