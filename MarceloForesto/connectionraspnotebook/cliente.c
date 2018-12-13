#include<stdio.h>
#include<string.h> 
#include<sys/socket.h>
#include<arpa/inet.h>
 
int main()
{
    int sock;
    struct sockaddr_in servidor;
    char mensagem[500], mensagemServidor[500];
         
    //Realiza a cracao do soquete, atribuindo o Dominio da internet, o soquete de transmissao e o protoculo TCP padrao
    sock = socket(AF_INET , SOCK_STREAM , 0);
    printf("\nSocket criado\n" );

    //Familia de endereco, no caso internet
    servidor.sin_family = AF_INET;
    //Atribui o IP do localhost
    servidor.sin_addr.s_addr = inet_addr("192.168.0.101");
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
     
    //Enquanto o cliente digitar as mensagens, o loop permanece
    while(1) {
        printf("\nDigite a mensagem para o servidor :");
        scanf("%s", mensagem);

        //Verifica se a possibilidade de mandar uma menssagem
        if( send(sock , mensagem , strlen(mensagem) , 0) < 0) {
            printf("\nNao foi possivel enviar a mensagem\n");
            return 1;
        }
        
        //Verifica a possobilidade de receber a mensagem resposta do servidor
        if( recv(sock , mensagemServidor , 1000 , 0) < 0) {
            printf("\nNao foi possivel receber a respota do servidor.\n");("recv failed");
            break;
        }
        printf("\nA resposta do servidor foi : %s\n", mensagemServidor);   
    }
    return 0;
}
