/*
    Autor: Leonardo Oliveira de Moura
*/
#define MAXBUFF 1024  // numero de caract. do buffer
#define TAM_BUFF 50
#define TAM_MAXIMO_MENSAGEM 2000
#define TRUE 1
#define FALSE 0

typedef struct
{
	int indice;
	char msg[TAM_BUFF];
} strInfo;

typedef struct
{
    struct sockaddr_in addr
    int socket
} conexao;
