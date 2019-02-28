import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;
import java.util.Scanner;

public class ServerTCP {
	public static void main(String[] args) {
	    try {
	      // Instancia o ServerSocket ouvindo a porta 5560
	      ServerSocket servidor = new ServerSocket(5560);
	      System.out.println("Servidor ouvindo a porta 5560");
	        	      
	      while(true) {
	        // o método accept() bloqueia a execução até que
	        // o servidor receba um pedido de conexão
	        Socket cliente = servidor.accept();
	        System.out.println("Cliente conectado: " + cliente.getInetAddress().getHostAddress());
	        
	        
	        System.out.println("Digite um numero para reproduzir um som.");
	        Scanner reader = new Scanner(System.in);
	        char c = reader.next().charAt(0);		//realiza a leitura	
	        
	        var out = new PrintWriter(cliente.getOutputStream(), true);
	        out.println(c);		//passa o comando para a Raspberry Pi
		     
	        ObjectOutputStream saida = new ObjectOutputStream(cliente.getOutputStream());
	        saida.flush();
	        saida.writeObject(new Date());
	        saida.close();
	        cliente.close();
	      }  
	    }   	
	    catch(Exception e) {
	       System.out.println("Erro: " + e.getMessage());
	    }
	  }     
}
