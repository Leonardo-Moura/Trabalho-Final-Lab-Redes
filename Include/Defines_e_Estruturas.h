/*
    Autor: Leonardo Oliveira de Moura
*/
#define TAM_BUFF 50
#define TAM_MAXIMO_MENSAGEM 20000
#define NOVA_CONEXAO 1
#define FIM 100000

typedef struct
{
	int indice;
	char msg[TAM_BUFF];
} strInfo;

typedef struct
{
    struct sockaddr_in addr;
    int socket;
} conexao;
