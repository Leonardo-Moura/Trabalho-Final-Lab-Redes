/*pipebid.c*/

/* --------------------------------------------------------------
                PUC Minas - Poços de Caldas
                     2º semestre 2018
                    Laboratorio de Redes

            Aluno: Leonardo Oliveira de Moura

Cliente em C para receber dados atraves de conexão socket sobre
protocolo UDP

Após a conexao:
1 - Recebe uma lista com os arquivos contidos na pasta do servidor.
2 - Envia o nome do arquivo desejado.
3 - Recebe os dados do arquivo especificado

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
#include <fcntl.h>

#include "Lib.h"

struct sockaddr_in   serv_addr;    //Estrutura de endereco do servidor

main (int argc, char *argv[])
{
    int       socketfd;
    char      filename[256];

    //Verifica se entrou com todos os parametros
    if (argc != 3)
    {
        printf("\n Digite o ip e a porta do servidor\n\n");
        exit(0);
    }

    //Preenche a estrutura "serv_addr" com o endereco do servidor
    bzero( (char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family        = AF_INET;              //Família IPv4
    serv_addr.sin_addr.s_addr   = inet_addr(argv[1]);
    serv_addr.sin_port          = htons(atoi(argv[2]));

    //Cria o socket UDP(SOCK_DGRAM) ou TCP(SOCK_STREAM)
    if ( (socketfd = socket(AF_INET, SOCK_DGRAM, 0) ) < 0)
    {
        printf("cliente: erro na criacao do socket");
        exit(0);
    }

    //Se conecta ao servidor
    if (connect(socketfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("cliente: erro na conexao com o servidor");
        close(socketfd);
        exit(0);
    }

    //Chama a funcao cliente para enviar o pedido e receber a resposta
    client(socketfd, filename);

    //Fecha o socket apos uso
    close (socketfd);
    exit(0);

}//Fim main()


client (int socketfd)
{
    char strBuff[TAM_MAXIMO_MENSAGEM];
    char auxiliar[20];
    info buff;

    //Apos a conexao, recebe a lista de arquivos do servidor
    strBuff = RecebeString(socketfd, serv_addr);

    //Implemetar envio de Dados para interface gráfica
    //EnviaDados(strBuff);

    //Implementar requisição de Dados da Interface Gráfica
    //strBuff = ?;

    //Envia o nome do arquivo selecionado
    EnviaString(strBuff, socketfd, serv_addr);

    //Recebe os dados do arquivo selecionado
    strBuff = RecebeString(socketfd, serv_addr);

    //Implementar envio de Dados para interface Gráfica
    //ExibeDados(strBuff);
} // Fim da Funcao CLIENT
