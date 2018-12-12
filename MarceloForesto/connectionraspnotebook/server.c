#include<stdio.h>
#include<string.h> 
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>  
 
int main()
{
    int sock , client_sock , c, read_size;
    struct sockaddr_in servidor , client;
    char client_message[2000], send_msg[100];

    //Realiza a cracao do soquete, atribuindo o Dominio da internet, o soquete de transmissao e o protoculo TCP padrao
    sock = socket(AF_INET , SOCK_STREAM , 0);

    printf("\nSocket craido\n");
    
    //Familia de endereco, no caso internet
    servidor.sin_family = AF_INET;
    //Atribui o IP do localhost
    servidor.sin_addr.s_addr = inet_addr("192.168.43.192");
    //Atribui o numero da porta, utilizando a funcao htons 
    servidor.sin_port = htons(5560);

    //Verifica a possibilidade da ligacao com  o soquete, com o endereco atribuido
    if( bind(sock,(struct sockaddr *)&servidor , sizeof(servidor)) < 0) {
        //print the error message
        printf("\nLicacao nao estabelecida.\n");
        return 1;
    }
    
    printf("\nLigacao realizada com sucesso.\n");
    
    //Realiza a escuta atraves do soquete 
    if (listen(sock, 3) == 0) 
        printf("\nEsperando por novos clientes.\n");
    
    //Com a chamada aceita, cria um novo soquete para a conecao de entrada(soquete do cliente)
    c = sizeof(struct sockaddr_in);
    client_sock = accept(sock, (struct sockaddr *) &client, (socklen_t*)&c);
     
    //Verifica se o soquete do cliente foi criado
    if (client_sock < 0) {
        printf("\nConecao com o cliente nao foi aceita.\n");
        return 1;
    }

    printf("\nConecao com o cliente estabelecida.\n");

    //Atribui zero para todos os bits do campo de preenchimento
    memset(client_message,'\0',sizeof(client_message));

    //Equanto houver mensagem do cliente, o loop permanece
    while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 ) {

        printf("\nA menssagem do cliente foi: %s\n", client_message);
    	
        //Retorna a mensagem recebida para o cliente
        write(client_sock , client_message , strlen(client_message));
        //Atribui zero para todos os bits do campo de preenchimento
        memset(client_message,'\0',sizeof(client_message));
    }
     
    return 0;
}