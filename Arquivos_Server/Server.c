/*pipebid.c*/

/* --------------------------------------------------------------
                PUC Minas - Poços de Caldas
                     2º semestre 2018
                    Laboratorio de Redes

            Aluno: Leonardo Oliveira de Moura
            Aluno: Tassiano Cardoso

Servidor em C preparado para aceitar conexoes socket
e realizar comunicação sobre protocolo UDP.
Após a conexao:
1 - Envia uma lista com os arquivos contidos na pasta do executável.
2 - Recebe o nome do arquivo desejado pelo cliente
3 - Envia os dados do arquivo especificado

--------------------------------------------------------------------*/

#include "Lib.h"

void serverUDP(int);

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

	//Cria o socket UDP (SOCK_DGRM)
	if ( (socketfd = socket(AF_INET, SOCK_DGRAM, 0) ) < 0)
	{
		printf("servidor: erro na criacao do socket\n");
		exit(0);
	}

	//Preenche a estrutura do servidor e faz o Bind Local
	bzero( (char*) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family        = AF_INET;              //Família IPv4
	serv_addr.sin_addr.s_addr   = INADDR_ANY;		//Escuta qualquer interface
	//serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port          = htons(atoi(argv[1]));

	serv_len = sizeof(serv_addr);
	if (bind(socketfd, (struct sockaddr *) &serv_addr, serv_len)<0)
	{
		printf("servidor: erro no bind local\n");
		close(socketfd);
		exit(0);
	}

	//Mostra a porta alocada dinamicamente
	if (getsockname(socketfd, (struct sockaddr *)&serv_addr, &serv_len) < 0)
	{
		printf("servidor: erro na chamada da funcao getsockname\n");
		close(socketfd);
		exit(0);
	}

	printf("Porta alocada para o Servidor: %d\n", ntohs(serv_addr.sin_port));

	//Chama a funcao servidor para esperar uma requisicao de servico
	serverUDP(socketfd);

	//fecha o socket apos uso
	close (socketfd);
	exit(0);
}

/*
Funcao ServerUDP:
	Recebe um datagrama com 2 tipos de informacao:
	1- NOVA_CONEXAO -> Constante que simboliza um novo cliente. Responde com a lista de arquivos disponíveis.
	2- Nome do arquivo -> Responde com o conteúdo do arquivo especificado.
*/
void serverUDP(int socket)
{
	struct sockaddr_in cli_addr;
	int cli_addr_len;
	conexao conn;
	char strBuff[TAM_MAXIMO_MENSAGEM];
	strInfo info;

	while(1)
	{
		printf("Aguardando requisicao\n");
		strcpy(strBuff, RecebeString(socket, &cli_addr));
		printf("ServerUDP - Recebido: %s\n", strBuff);
		if (atoi(strBuff) == NOVA_CONEXAO)
		{
			strcpy(strBuff, Lista_Arquivos());

			//Envia a lista de arquivos na pasta do executável
			EnviaString(strBuff, socket, cli_addr);
			continue;
		}

		//Le o arquivo especificado
		strcpy(strBuff, le_arquivo_txt(strBuff));

		//Envia os dados do arquivo especificado
		EnviaString(strBuff, socket, cli_addr);
	}
}
