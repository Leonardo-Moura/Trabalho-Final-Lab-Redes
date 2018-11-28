/*
	Autor: Leonardo Oliveira de Moura

	Funcoes para comunicao usando socket com protocolo UDP
*/

#include "Lib.h"

void EnviaString(char buff[], int socket, struct sockaddr_in addr)
{
	int tam, ind, cont;
	char msg[TAM_BUFF];
	strInfo dados;

	tam = strlen(buff);
	ind = 0;
	printf("\n\nEnviando dados\n");
	printf("\nPreparando para enviar a string: %s\n", buff);
	//for(ind = 0; ind < (tam/TAM_BUFF); ind++)
	while(strlen(buff) > 0)
	{
		if(strlen(buff) > TAM_BUFF)
		{
			strncpy(msg, buff, TAM_BUFF - 1);
			msg[TAM_BUFF - 1] = '\0';
			buff = buff + ((TAM_BUFF * sizeof(char)) - 1);
		}
		else
		{
			memset(msg, 0, TAM_BUFF);
			strcpy(msg, buff);
			memset(buff, 0, tam);
		}

		memset(dados.msg, 0, TAM_BUFF);

		if(strlen(msg) > 0)
		{
			strcpy(dados.msg, msg);
			dados.indice = ind;

			cont = sendto(socket, &dados, sizeof(dados), 0, (struct sockaddr_in*)&addr, sizeof(addr));
			printf("\nEnviou:\n%s\n", dados.msg);

			if(cont == -1)
			{
				printf("\n\n--------------  Erro  ------------");
				printf("\n\t\t  Erro ao enviar dados.\n");
				exit (-1);
			}
		}
		ind++;
	}

	memset(dados.msg, 0, TAM_BUFF);
	dados.indice = FIM;
	printf("\nFinalizando envio de dados\n");
	cont = sendto(socket, &dados, sizeof(dados), 0, (struct sockaddr_in*)&addr, sizeof(addr));
	if (cont == -1)
	{
		printf("\n\n-------------  Erro	  -----------");
		printf("\n\t\t Erro ao enviar mensagem de termino de solicitação\n");
		exit (-1);
	}
}

char *RecebeString(int socket, struct sockaddr_in *addr)
{
	strInfo buff, recebido[TAM_MAXIMO_MENSAGEM/TAM_BUFF], ordenado[TAM_MAXIMO_MENSAGEM/TAM_BUFF];
	struct sockaddr_in addr_atual;
	int ind, bytes, cont, loop, tam_addr;
	char *retorno = malloc(TAM_MAXIMO_MENSAGEM * sizeof(char));

	ind = 0;

	//Recebe os dados
	do
	{
		tam_addr = sizeof(addr);
		printf("\nPronto para receber\n");
		buff.indice = 0;
		memset(buff.msg, 0, TAM_BUFF);
		if((bytes = recvfrom(socket, &buff, sizeof(strInfo), 0, addr, &tam_addr)) < 0)
		{
			printf("\n\n--------------  Erro  ------------");
			printf("\n\t\t  Erro ao receber dados");
			exit (-1);
		}

		if (ind == 0) addr_atual = *addr;

		if (ind != 0 && (ntohl(addr_atual.sin_addr.s_addr) != ntohl(addr -> sin_addr.s_addr)))
		{
			printf("Mensagem ignorada do IP: %x\n", ntohl(addr -> sin_addr.s_addr));
			continue;
		}

		recebido[ind].indice = buff.indice;
		strcpy(recebido[ind].msg, buff.msg);
		printf("Recebido: %s \nIndice: %d\n", recebido[ind].msg, recebido[ind].indice);
		ind++;
	}while(buff.indice != FIM);

	cont = ind;
	ind = 0;
	printf("Total de frames: %d\n", cont);
	while(ind < cont)
	{
		memset(ordenado[ind].msg, 0, TAM_BUFF);
		for(loop = 0; loop < cont; loop++)
		{
			if(recebido[loop].indice == ind)
			{
				ordenado[ind].indice = recebido[loop].indice;
				strcpy(ordenado[ind].msg, recebido[loop].msg);
			}
		}
		ind++;
	}
	printf("Frames ordenados com sucesso\n");

	memset(retorno, 0, TAM_MAXIMO_MENSAGEM);
	loop = 0;
	for(loop = 0; loop < cont; loop++)
	{
		printf("Adicionando ao retorno: %s\n", ordenado[loop].msg);
		strcat(retorno, ordenado[loop].msg);
	}
	//printf("\nResultado final do dados recebidos: %s\n", retorno);
	return(retorno);
}
