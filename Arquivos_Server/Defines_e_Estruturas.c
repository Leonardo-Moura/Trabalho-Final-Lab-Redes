#define MAXBUFF 1024  // numero de caract. do buffer
#define TAM_BUFF 50
#define TRUE 1
#define FALSE 0
#define LEITURA 1
#define ESCRITA 2
#define SAIR 3
#define LISTAGEM 3
#define SIM 1
#define NAO 2
#define NAO_SABE 3
#define NORMAL 4
#define EXCESSIVO 5
#define COMPLICADO 6

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
