#include<stdio.h>
#include<string.h> 
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>       
#include<wiringSerial.h>

//Funcao que verifica se uma string eh ou nao um float.
bool is_float(const char *s, float *dest) {
  if (s == NULL) {
    return false;
  }
  char *endptr;
  *dest = (float) strtod(s, &endptr);
  if (s == endptr) {
    return false; // no conversion;
  }
  // Look at trailing text
  while (isspace((unsigned char ) *endptr))
    endptr++;
  return *endptr == '\0';
}
//Funcao que utiliza a funcao is_float para realizar a vericacao de uma string
bool is_float_test(const char *s) {
  float x;

  if (is_float(s, &x)) {
    return true;
  } else {
    return false;
  }
}

int main()
{
    int sock, fd, a, i, aux;
    struct sockaddr_in servidor;
    char mensagem[500], mensagemServidor[500], velocidadeSom[5], comandoSom[50];
         
    //Realiza a cracao do soquete, atribuindo o Dominio da internet, o soquete de transmissao e o protoculo TCP padrao
    sock = socket(AF_INET , SOCK_STREAM , 0);
    printf("\nSocket criado\n" );

    //Familia de endereco, no caso internet
    servidor.sin_family = AF_INET;
    //Atribui o IP do localhost
    servidor.sin_addr.s_addr = inet_addr("10.0.0.113");
    //Atribui o numero da porta, utilizando a funcao htons 
    servidor.sin_port = htons(5560);
    
    //Atribui zero para todos os bytes dos vetores
    memset(mensagemServidor,'\0',sizeof(mensagemServidor));
    memset(mensagem,'\0',sizeof(mensagem));
    memset(velocidadeSom,'\0',sizeof(velocidadeSom)); 
    memset(comandoSom,'\0',sizeof(comandoSom));   
 
 	//Verifica a possibilidade de conecao do soquete com o servidor
    if (connect(sock , (struct sockaddr *)&servidor , sizeof(servidor)) < 0) {
        printf("\nErro na hora de estabelecer a conecao.\n");
        return 1;
    }
     
    printf("\nConecao estabelecida.\n");
    
    //Comeca a abrir a conecao serial 
    printf("Abrindo Serial...\n");
    
    //Veifica a possibilidade de abrir a conecao serial
    if ((fd = serialOpen ("/dev/ttyAMA0", 115200)) < 0)
      {
        printf ("\nNao foi possivel abrir a conecao serial: %s\n", strerror (errno)) ;
        return 1 ;
    }
    
    printf("\nConecao serial estabelecida.\n");

    //Enquanto o cliente digitar as mensagens, o loop permanece
    while(1) {
    	
        //Verifica a possibilidade do recebimento da resposta do servidor
        if (recv(sock, mensagemServidor, 500, 0) < 0) {
            printf("\nNao foi possivel receber a resposta do servidor.\n");("recv failed");
            break;
        }
        //Verifica se o comando digitado eh do som da frequebcia cardiaca
        if (strcmp(mensagemServidor, "som1") == 0) {
            //Verifica a possibilidade do recebimento da resposta do servidor da frequencia do som
            if ((recv(sock, velocidadeSom, 5, 0) > 0) && is_float_test(velocidadeSom)) {
                system("pkill play");
                strcat(comandoSom, "play /home/pi/Raspberry/Atritopleural.mp3 ");
                strcat(comandoSom, "speed ");
                strcat(comandoSom, velocidadeSom);
                strcat(comandoSom, " &");
                system(comandoSom);  
                strcpy(mensagem, "Reproduzindo som da frequencia cardiaca");
            }
            //Caso o usario nao digite um float, o comando nao sera executado
            else {
                strcpy( mensagem, "Comando desconhecido");
            }    
        }
        //Verifica se o comando digitado eh do som da frequencia respiratoria
        if (strcmp(mensagemServidor, "som2") == 0) {
            //Verifica a possibilidade do recebimento da resposta do servidor da frequencia do som
            if ((recv(sock, velocidadeSom, 5, 0) > 0) && is_float_test(velocidadeSom)) {
                system("pkill play");
                strcat(comandoSom, "play /home/pi/Raspberry/Atritopleural.mp3 ");
                strcat(comandoSom, "speed ");
                strcat(comandoSom, velocidadeSom);
                strcat(comandoSom, " &");
                system(comandoSom);  
                strcpy(mensagem, "Reproduzindo som da frequencia respiratoria");
            }
            //Caso o usario nao digite um float, o comando nao sera executado
            else {
                strcpy( mensagem, "Comando desconhecido");
            }    
        }
        //Verifica se o comando digitado eh para parar alguns dos sons
        else if (strcmp(mensagemServidor, "stop") == 0) {
        	system("pkill play");
            strcpy( mensagem, "Som interrompido");
        }
        //Verifica se o comando digitado eh do leitor de RFID
        else if (strcmp(mensagemServidor, "1") == 0) {
        	//Envia o comando para o Arduino
        	serialPuts(fd, mensagemServidor);
    		delay(1000);

            while((a=serialDataAvail(fd))==0);
            delay(50);
            //Realiza a leitura do a novamente devido ao tempo de espera necessario para receber todos os bytes
            a = serialDataAvail(fd);        
            aux = 0;
            //Coloca todos os caracteres da mensagem na string mensagem   
            for (i = a, aux = 0; i > 0; i--, aux++)                    
                mensagem[aux] = serialGetchar (fd);

            printf("\nA mensagem do Arduino foi: %s\n", mensagem);
    	}
    	//Caso nenhum dos comandos digitados forem valido, returna uma mensagem de comando invalido
        if (mensagem[0] == '\0')
            strcpy( mensagem, "Comando desconhecido");

        //Verifica se a possibilidade de mandar a menssagem para o servidor
        if( send(sock , mensagem , strlen(mensagem) , 0) < 0) {
            printf("\nNao foi possivel enviar a mensagem\n");
            return 1;
        }

        //Atribui zero para todos os bytes dos vetor
        memset(mensagemServidor,'\0',sizeof(mensagemServidor));
        memset(mensagem,'\0',sizeof(mensagem));
        memset(velocidadeSom,'\0',sizeof(velocidadeSom));
        memset(comandoSom,'\0',sizeof(comandoSom));     		
    }
    //Necessario fechar a comunicacao serial para que possa ser utilizada em outros programas
    serialClose(fd);    
    return 0;           
}