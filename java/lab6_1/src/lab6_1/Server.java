
package lab6_1;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;


public class Server {

    ServerSocket myServer;
    Socket mySocket;
    DataInputStream in;
    PrintStream out;
    public static void main(String[] args) {
      
        new Server();
    }
    public Server() 
    {
        try
        {
        myServer=new ServerSocket(5005);
        mySocket=myServer.accept();
        in=new DataInputStream(mySocket.getInputStream());
        out=new PrintStream(mySocket.getOutputStream());
        String m=in.readLine();
        System.out.println(m);
        out.println("correct");
        }catch(IOException ex)
        {
            //ex.printStackTrace();
            System.out.println("the client not connected");
        }
        try
        {
            in.close();
            out.close();
            mySocket.close();
            myServer.close();
        }catch(Exception ex)
        {
            System.out.println("the files not closed");
        }
    }
}
