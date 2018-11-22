/*pipebid.c*/

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

#include "Defines_e_Estruturas.c"
#include "Manipulacao_de_Arquivos.c"


void *NewSocketThread (void *fdnewsock);
server(int socketfd);
void thread_server(int socketfd);

main (int argc, char *argv[])
{
   int    socketfd, serv_len;
   struct sockaddr_in   serv_addr;

   if (argc != 2)
   {
	printf("Informe a porta!");
	exit(0);
   }

   //Cria o socket UDP
   if ( (socketfd = socket(AF_INET, SOCK_DGRAM, 0) ) < 0)
   {
        printf("servidor: erro na criacao do socket");
        exit(0);
   }

   //Preenche a estrutura do servidor e faz o Bind Local
   bzero( (char*) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family        = AF_INET;
   serv_addr.sin_addr.s_addr  = htonl(INADDR_ANY);
   serv_addr.sin_port        = htons(atoi(argv[1]));

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

server(int socketfd)
{
  int *newsocketfd, cli_len;
  struct sockaddr_in   cli_addr;
  pthread_t *sockthread;
  conexao conn;

  //Prepara para receber conexoes dos clientes
  listen(socketfd,5);

  //Estrutura de repeti��o para continuar recebendo conex�es de clientes
  for(;;)
  {
       //Aloca espa�o na mem�ria para o novo descritor - newsocketfd
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

       //Aloca espa�o na mem�ria para uma nova thread - sockthread
       sockthread = (pthread_t *)malloc(sizeof(pthread_t));
       //Cria e chama a nova thread(NewSocketThread) para tratar da comunica��o do novo
       //cliente, passando como argumento o descritor(newsocketfd) do novo cliente
    conn.addr = cli_addr;
    conn.socket = *newsoocketfd;
	printf("Vai abrir a thread");
       pthread_create(sockthread,NULL,thread_server,conn);

  }


} //Fim Funcao server

/* -----------------------------------------------------------------------------------------------------------
Funcao Server: 		Executa no processo FILHO
			Abre o arquivo solicitado e envia seu conteudo
			para o PAI
----------------------------------------------------------------------------------------------------------- */
void thread_server(conexao conn)
{
	info buff;
	int n;
	char strBuff[2000];

	strBuff = Lista_Arquivos();

	EnviaString(strBuff, conn.socket, conn.addr);

	strcpy(strBuff, RecebeString(conn.socket, conn.addr));


	//anamnese dados;
	/*printf("abriu a thread");
	if ( ( n= read(socketfd, &buff, sizeof(info)) ) <=0)
	   {
		printf("Funcao Server: Erro no recebimento do comando");
	     	exit(0);
	   }
	printf("%d\n", n);
	if (buff.operacao == LEITURA)
	{
		dados = le_arquivo(buff.dados.cpf);
		if (strcmp(dados.cpf, "") == 0)
		{
			n = FALSE;
			if (write(socketfd, &n, sizeof(int)) != sizeof(int))
			{
				printf("Erro de Leitura do arquivo e envio para o processo pai.");
			}
		}
		else
		{
			if (write(socketfd, &dados, sizeof(anamnese)) != sizeof(anamnese))
			{
				printf("Erro ao enviar os dados para o processo pai");
			}
		}
	}
	else if(buff.operacao == ESCRITA)
	{
		printf("Vai tentar printar\n");
		printf("%s\n", buff.dados.nome);
		if(escreve_arquivo(buff.dados) == TRUE)
		{
			n = TRUE;
		    if(write(socketfd, &n, sizeof(int)) != sizeof(int))
			{
                		printf("Erro ao enviar confirmação de gravação para o processo pai.");
            		}
		}
		else
        	{
			n = FALSE;
		    if(write(*socketfd, &n, sizeof(int)) != sizeof(int))
		    {
		        printf("Erro ao enviar erro de gravação para o processo pai.");
		    }
        	}
	}
	else if(buff.operacao == SAIR)
	{
		exit(0);
	}*/


} // Fim da Funcao Server
