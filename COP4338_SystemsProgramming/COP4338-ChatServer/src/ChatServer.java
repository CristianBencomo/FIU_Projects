package src;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/*
 * A server that hosts a chatroom communication
 */

public class ChatServer 
{
    public static void main(String[] args) throws IOException
    {
        
        final int PORT = 1234;
        ServerSocket server = new ServerSocket(PORT);
        Chatroom chatroom = new Chatroom();

        System.out.println("Server has been initiated\nWaiting for clients to connect\n");
            
        while(true)
        {
            
            Socket socket = server.accept();
            System.out.println("Client connected.");
            ChatService service = new ChatService(socket, chatroom);
            Thread thread = new Thread(service);
            thread.start();

        }
    }
}
