
/* --------------------------------------------------------------
                PUC Minas - Pocos de Caldas
                     2o semestre 2018
                    Laboratorio de Redes

            Aluno: Leonardo Oliveira de Moura
            Aluno: Tassiano Cardoso

Cliente em C para receber dados atraves de conexão socket sobre
protocolo UDP

Após a conexao:
1 - Recebe uma lista com os arquivos contidos na pasta do servidor.
2 - Envia o nome do arquivo desejado.
3 - Recebe os dados do arquivo especificado

--------------------------------------------------------------------*/

#include "Lib.h"

struct sockaddr_in   serv_addr;    //Estrutura de endereco do servidor

clientUDP(int);
char *itoa(int);

main (int argc, char *argv[])
{
	int       socketfd;

	//Verifica se entrou com todos os parametros
	if (argc != 3)
	{
		printf("\n Digite o ip e a porta do servidor\n\n");
		exit(0);
	}

	//Preenche a estrutura "serv_addr" com o endereco do servidor
	bzero( (char*) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family        = AF_INET;              //Familia IPv4
	//serv_addr.sin_addr.s_addr   = inet_addr(argv[1]);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port          = htons(atoi(argv[2]));

	//Cria o socket UDP(SOCK_DGRAM)
	if ( (socketfd = socket(PF_INET, SOCK_DGRAM, 0) ) < 0)
	{
		printf("cliente: erro na criacao do socket\n");
		exit(0);
	}
	
	printf("IP: %s\nPorta: %s\n", argv[1], argv[2]);
	//Se conecta ao servidor
	if (connect(socketfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("cliente: erro na conexao com o servidor\n");
		close(socketfd);
		exit(0);
	}

	printf("\Conectado ao servidor\n");
	//Chama a funcao cliente para enviar o pedido e receber a resposta
	clientUDP(socketfd);

	//Fecha o socket apos uso
	close (socketfd);
	exit(0);

}//Fim main()


clientUDP (int socket)
{
	char strBuff[TAM_MAXIMO_MENSAGEM];

	//Envia uma solicitacao com um codigo informando que e uma nova conexao
	strcpy(strBuff, itoa(NOVA_CONEXAO));
	EnviaString(strBuff, socket, serv_addr);
	printf("Cliente Enviou requisicao de conexao\n");

	//Apos a conexao, recebe a lista de arquivos do servidor
	strcpy(strBuff, RecebeString(socket, &serv_addr));
	printf("Recebeu a lista de Arquivos no servidor\n");
	scanf("%s", strBuff);

	//Implemetar envio de Dados para interface grafica
	//EnviaDadosParaGUI(strBuff);

	//Implementar requisicao de Dados da Interface Grafica
	//strBuff = ?;

	//Envia o nome do arquivo selecionado
	EnviaString(strBuff, socket, serv_addr);
	printf("Enviou o nome do arquivo\n");

	//Recebe os dados do arquivo selecionado
	strcpy(strBuff, RecebeString(socket, &serv_addr));
	printf("Recebeu os dados do arquivo\n");
	printf("\n%s\n", strBuff);

	//Implementar envio de Dados para interface Grafica
	//ExibeDados(strBuff);
} // Fim da Funcao CLIENT

char *itoa(int num)
{
	char aux[15];
	char *retorno;
	int i = 0;
	int atual, loop;

	retorno = malloc(15 * sizeof(char));

	if (num == 0) return ("0");

	while (num != 0)
	{
		atual = num % 10;
		aux[i] = atual + '0';
		i++;
		num = num / 10;
	}

	for (loop = 0; loop < i; loop++)
	{
		retorno[loop] = aux[i - (loop + 1)];
	}

	retorno[i] = '\0';

	return (retorno);
}
