#ifndef LIB
#define LIB

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
#include <unistd.h>

#include "Defines_e_Estruturas.h"

void EnviaString(char* , int, struct sockaddr_in);
char* RecebeString(int, struct sockaddr_in*);
char* le_arquivo_txt(char*);
char* Lista_Arquivos();
void Grava_Arquivo(char*, char*);

#endif
