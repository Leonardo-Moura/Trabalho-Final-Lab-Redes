/*pipebid.c*/

/* --------------------------------------------------------------
                PUC Minas - Poços de Caldas
                     2º semestre 2018
                    Laboratorio de Redes

            Aluno: Leonardo Oliveira de Moura

Servidor em C preparado para aceitar ate 5 conexoes socket.
Após a conexao:
1 - Envia uma lista com os arquivos contidos na pasta do executável.
2 - Recebe o nome do arquivo desejado pelo cliente
3 - Envia os dados do arquivo especificado

--------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#include "Lib.h"

void *NewSocketThread (void *fdnewsock);
server(int socketfd);
void thread_server(int socketfd);

/* -----------------------------------------------------------------------------------------------------------
Funcao Main:
    Cria o socket servidor e inicia a função server
----------------------------------------------------------------------------------------------------------- */
main (int argc, char *argv[])
{
    int    socketfd, serv_len;
    struct sockaddr_in   serv_addr;

    // A chamada do aplicativo deve ser sucedida pela porta que será alocado o servidor
    // Verifica se existe o segundo argumento
    if (argc != 2)
    {
    printf("Informe a porta!");
    exit(0);
    }

    //Cria o socket UDP (SOCK_DGRM) ou TCP (SOCK_STREAM)
    if ( (socketfd = socket(AF_INET, SOCK_DGRAM, 0) ) < 0)
    {
        printf("servidor: erro na criacao do socket");
        exit(0);
    }

    //Preenche a estrutura do servidor e faz o Bind Local
    bzero( (char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family        = AF_INET;              //Família IPv4
    serv_addr.sin_addr.s_addr   = htonl(INADDR_ANY);
    serv_addr.sin_port          = htons(atoi(argv[1]));

    serv_len = sizeof(serv_addr);
    if (bind(socketfd, (struct sockaddr *) &serv_addr, serv_len)<0)
    {
        printf("servidor: erro no bind local");
        close(socketfd);
        exit(0);
    }

    //Mostra a porta alocada dinamicamente
    if (getsockname(socketfd, (struct sockaddr *)&serv_addr, &serv_len) < 0)
    {
        printf("servidor: erro na chamada da funcao getsockname");
        close(socketfd);
        exit(0);
    }

    printf("\nPorta alocada para o Servidor: %d\n", ntohs(serv_addr.sin_port));

    //Chama a funcao servidor para esperar uma requisicao de servico

    server(socketfd);

    //fecha o socket apos uso

    close (socketfd);
    exit(0);
}

/* -----------------------------------------------------------------------------------------------------------
Funcao Server:
    Aceita conexões clientes e inicia a thread para tratá-los
----------------------------------------------------------------------------------------------------------- */
server(int socketfd)
{
    int *newsocketfd, cli_len;
    struct sockaddr_in   cli_addr;
    pthread_t *sockthread;
    conexao conn;

    //Prepara para receber conexoes dos clientes
    listen(socketfd,5);

    //Estrutura de repetição para continuar recebendo conexoes de clientes
    for(;;)
    {
        //Aloca espaço na memória para o novo descritor - newsocketfd
        newsocketfd = (int *)malloc(sizeof(newsocketfd));
        //Aguarda a conexao de algum cliente e quando o cliente conecta, o valor de accept
        //� recebido pelo conte�do do endere�o de newsocketfd (que est� alocado na mem�ria)
        cli_len=sizeof(newsocketfd);
        printf("antes do accept\n");
        if ((*newsocketfd=accept(socketfd,(struct sockaddr *)&cli_addr,&cli_len))<0)
        {
            printf("Funcao server: erro no accept");
            close(socketfd); //Fecha o socket do servidor
            exit(0);
        }
        conn.addr = cli_addr;
        conn.socket = *newsoocketfd;
        //Aloca espa�o na mem�ria para uma nova thread - sockthread
        sockthread = (pthread_t *)malloc(sizeof(pthread_t));
        //Cria e chama a nova thread(NewSocketThread) para tratar da comunica��o do novo
        //cliente, passando como argumento o descritor(newsocketfd) do novo cliente

        printf("Vai abrir a thread");
        pthread_create(sockthread,NULL,thread_server,conn);
  }
} //Fim Funcao server

/* -----------------------------------------------------------------------------------------------------------
Funcao thread_server:
    Realiza as comunicações da aplicação com o cliente
----------------------------------------------------------------------------------------------------------- */
void thread_server(conexao conn)
{
	info buff;
	int n;
	char strBuff[TAM_MAXIMO_MENSAGEM];

	strBuff = Lista_Arquivos();

    //Envia a lista de arquivos na pasta do executável
	EnviaString(strBuff, conn.socket, conn.addr);

	//Recebe o nome do arquivo para enviar
	strcpy(strBuff, RecebeString(conn.socket, conn.addr));

	//Le o arquivo especificado
    strBuff = le_arquivo_txt(strbuff);

    //Envia os dados do arquivo especificado
    EnviaString(strBuff, conn.socket, conn.addr);
} // Fim da Funcao Server
