#include<stdio.h>
#include<string.h> 
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<errno.h>       
#include<wiringSerial.h>

int main()
{
    int sock, fd, a, i, aux;
    struct sockaddr_in servidor;
    char mensagem[500], mensagemServidor[500];
         
    //Realiza a cracao do soquete, atribuindo o Dominio da internet, o soquete de transmissao e o protoculo TCP padrao
    sock = socket(AF_INET , SOCK_STREAM , 0);
    printf("\nSocket criado\n" );

    //Familia de endereco, no caso internet
    servidor.sin_family = AF_INET;
    //Atribui o IP do localhost
    servidor.sin_addr.s_addr = inet_addr("192.168.0.103");
    //Atribui o numero da porta, utilizando a funcao htons 
    servidor.sin_port = htons(5560);
    
    //Atribui zero para todos os bits do campo de preenchimento
    memset(mensagemServidor,'\0',sizeof(mensagemServidor));
 
 	//Verifica a possibilidade de conecao do soquete com o servidor
    if (connect(sock , (struct sockaddr *)&servidor , sizeof(servidor)) < 0) {
        printf("\nErro na hora de estabelecer a conecao.\n");
        return 1;
    }
     
    printf("\nConecao estabelecida.\n");
    
    //Comeca a abrir a conecao serial 
    printf("Abrindo Serial\n");
    
    if ((fd = serialOpen ("/dev/ttyAMA0", 115200)) < 0)
      {
        printf ("\nNao foi possivel abrir a conecao serial: %s\n", strerror (errno)) ;
        return 1 ;
      }
    
    printf("\nAbriu!!\n");

    //Enquanto o cliente digitar as mensagens, o loop permanece
    while(1) {
        //Permanece no while enquanto nao receber a respota do arduino
        while((a=serialDataAvail(fd))==0);
        delay(50);
        //Realiza a leitura do a novamente devido ao tempo de espera necessario para receber todos os bytes
        a = serialDataAvail(fd);        
        //Atribui zero para todos os bytes do vetor
        memset(mensagem,'\0',sizeof(mensagem));
 
        aux = 0;
        //Coloca todos os caracteres da mensagem na string mensagem   
        for (i = a, aux = 0; i > 0; i--, aux++)                    
          mensagem[aux] = serialGetchar (fd);
        //Verifica a possibilidade de envio da mensagem recebida do arduino para o servidor  
        if( send(sock , mensagem , strlen(mensagem) , 0) < 0) {
            printf("\nNao foi possivel enviar a mensagem\n");
            return 1;
        }
        //Verifica a possibilidade do recebimento da resposta do servidor
        if (recv(sock, mensagemServidor, 500, 0) < 0) {
            printf("\nNao foi possivel receber a resposta do servidor.\n");("recv failed");
            break;
        }
        printf("\nA reposta do servidor foi: %s\n", mensagemServidor);    
        //Atribui zero para todos os bytes do vetor
        memset(mensagemServidor,'\0',sizeof(mensagemServidor));
 
        
        delay(2000);
    }
    //Necessario fechar a comunicacao serial para que possa ser utilizada em outros programas
    serialClose(fd);    
    return 0;           
}
