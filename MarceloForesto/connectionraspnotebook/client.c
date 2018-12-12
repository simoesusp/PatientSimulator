#include<stdio.h>
#include<string.h> 
#include<sys/socket.h>
#include<arpa/inet.h>
 
int main()
{
    int sock;
    struct sockaddr_in server;
    char message[500], server_reply[1000];
         
    //Realiza a cracao do soquete, atribuindo o Dominio da internet, o soquete de transmissao e o protoculo TCP padrao
    sock = socket(AF_INET , SOCK_STREAM , 0);
    printf("\nSocket criado\n" );

    //Familia de endereco, no caso internet
    server.sin_family = AF_INET;
    //Atribui o IP do localhost
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    //Atribui o numero da porta, utilizando a funcao htons 
    server.sin_port = htons(5560);
    
    //Atribui zero para todos os bits do campo de preenchimento
    memset(server_reply,'\0',sizeof(server_reply));
 
 	//Verifica a possibilidade de conecao do soquete com o servidor
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        printf("\nErro na hora de estabelecer a conecao.\n");
        return 1;
    }
     
    printf("\nConecao estabelecida.\n");
     
    //Enquanto o cliente digitar as mensagens, o loop permanece
    while(1) {
        printf("\nDigite a mensagem para o servidor :");
        scanf("%s", message);

        //Verifica se a possibilidade de mandar uma menssagem
        if( send(sock , message , strlen(message) , 0) < 0) {
            printf("\nNao foi possivel enviar a mensagem\n");
            return 1;
        }
        
        //Verifica a possobilidade de receber a mensagem resposta do servidor
        if( recv(sock , server_reply , 1000 , 0) < 0) {
            printf("\nNao foi possivel receber a respota do servidor.\n");("recv failed");
            break;
        }
        printf("\nA resposta do servidor foi : %s\n", server_reply);   
    }
    return 0;
}
