#include<stdio.h>
#include<string.h> 
#include<sys/socket.h>
#include<arpa/inet.h>

 
int main()
{
    int sock , sockCliente ,  tamanhoMensagem, tamanhoServidor;
    struct sockaddr_in servidor , cliente;
    char mensagemCliente[500], mensagem[500];

    //Realiza a cracao do soquete, atribuindo o Dominio da internet, o soquete de transmissao e o protoculo TCP padrao
    sock = socket(AF_INET , SOCK_STREAM , 0);

    printf("\nSocket craido\n");
    
    //Familia de endereco, no caso internet
    servidor.sin_family = AF_INET;
    //Atribui o IP do localhost
    servidor.sin_addr.s_addr = inet_addr("192.168.0.101");
    //Atribui o numero da porta, utilizando a funcao htons 
    servidor.sin_port = htons(5560);
    //Atribui o tamanho do servidor
    tamanhoServidor = sizeof(servidor);

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
    sockCliente = accept(sock, (struct sockaddr *) &cliente, (socklen_t*)&tamanhoServidor);
     
    //Verifica se o soquete do cliente foi criado
    if (sockCliente < 0) {
        printf("\nConecao com o cliente nao foi aceita.\n");
        return 1;
    }

    printf("\nConecao com o cliente estabelecida.\n");


    //Equanto houver mensagem do cliente, o loop permanece
    while( (tamanhoMensagem = recv(sockCliente , mensagemCliente , 100 , 0)) > 0 ) {

        printf("\nA mensagem do cliente foi: %s\n", mensagemCliente);
    	
        //Retorna a mensagem recebida para o cliente
        send (sockCliente, mensagemCliente, strlen(mensagemCliente), 0);
        //Atribui zero para todos os bits do campo de preenchimento
        memset(mensagemCliente,'\0',sizeof(mensagemCliente));
    }
     
    return 0;
}