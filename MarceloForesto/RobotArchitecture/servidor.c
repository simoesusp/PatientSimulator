#include<stdio.h>
#include<string.h> 
#include<sys/socket.h>
#include<arpa/inet.h>

 
int main()
{
    int sock , sockCliente ,  tamanhoMensagem, tamanhoServidor;
    struct sockaddr_in servidor , cliente;
    char mensagemCliente[500], mensagem[500], velocidadeSom[5];

    //Realiza a cracao do soquete, atribuindo o Dominio da internet, o soquete de transmissao e o protoculo TCP padrao
    sock = socket(AF_INET , SOCK_STREAM , 0);

    printf("\nSocket craido\n");
    
    //Familia de endereco, no caso internet
    servidor.sin_family = AF_INET;
    //Atribui o IP do localhost
    servidor.sin_addr.s_addr = inet_addr("10.0.0.113");
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

    //Atribui zero para todos os bytes dos vetor
    memset(mensagemCliente,'\0',sizeof(mensagemCliente));
    memset(mensagem,'\0',sizeof(mensagem));
    memset(velocidadeSom,'\0',sizeof(velocidadeSom));  
    
    //Equanto houver mensagem do cliente, o loop permanece
    while(1) {

        printf("\nDigite o comando para a Raspberry: ");
        scanf("%s", mensagemCliente);

        //Verifica a possibilidade do envio da mensagem
        if ((send (sockCliente, mensagemCliente, strlen(mensagemCliente), 0)) < 0 ) {
            printf("\nNao foi possivel enviar a mensagem para a Raspberry.\n");
            break;
        }
        if ((strcmp(mensagemCliente, "som1") == 0) || (strcmp(mensagemCliente, "som2") == 0)) {
            printf("Digite a velocidade do som para a Raspberry: ");
            scanf("%s", velocidadeSom);

            //Verifica a possibilidade do envio da mensagem
            if ((send (sockCliente, velocidadeSom, strlen(velocidadeSom), 0)) < 0 ) {
                printf("\nNao foi possivel enviar a mensagem para a Raspberry.\n");
                break;
            }
        }

        //Verifica a possibilidade do recebimento da resposta do servidor
        if ((tamanhoMensagem = recv(sockCliente , mensagem , 500 , 0)) < 0 ) {
            printf("\nNao foi possivel receber a resposta da Raspberry.\n");("recv failed");
            break;
        }

        printf("A mensagem do cliente foi: %s\n", mensagem);

        //Atribui zero para todos os bytes dos vetor
        memset(mensagemCliente,'\0',sizeof(mensagemCliente));
        memset(mensagem,'\0',sizeof(mensagem));
        memset(velocidadeSom,'\0',sizeof(velocidadeSom)); 
    }
     
    return 0;
}