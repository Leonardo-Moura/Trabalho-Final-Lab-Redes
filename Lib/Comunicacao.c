/*
    Autor: Leonardo Oliveira de Moura

    Funcoes para comunicao usando socket com protocolo UDP
*/

void EnviaString(char buff[], int socket, sockaddr_in addr)
(
	int tam, ind, cont;
	char msg[TAM_BUFF];
	strInfo dados;

	tam = sizeof(buff);
    ind = 0;

	//for(ind = 0; ind < (tam/TAM_BUFF); ind++)
	while(strlen(buff) > 0)
	{
		if(sizeof(buff) > TAM_BUFF)
        {
            strncpy(msg, buff, TAM_BUFF - 1);
            msg[TAM_BUFF - 1] = '\0';
            buff = buff + (TAM_BUFF * sizeof(char));
        }
        else
        {
            memset(msg, 0, TAM_BUFF);
            strcpy(msg, buff);
            memset(buff, 0, sizeof(buff))
        }

        memset(dados.msg, 0, TAM_BUFF);
        if(strlen(msg) > 0)
        {
            strcpy(dados.msg, msg);
            dados.indice = ind;

            cont = sendto(socket, &dados, sizeof(dados), (sockaddr_in *)&addr, sizeof(addr));
            //cont = sendto(socket, &dados, sizeof(dados), addr);

            if(cont == -1)
            {
                printf("\n\n--------------  Erro  ------------");
                printf("\n\t\t  Erro ao enviar dados.");
                exit (-1);
            }
        }
        ind++;
	}
)

char* RecebeString(int socket, sockaddr_in addr)
{
    strInfo buff, recebido[TAM_MAXIMO_MENSAGEM/TAM_BUFF], ordenado[TAM_MAXIMO_MENSAGEM/TAM_BUFF];
    int ind, bytes, cont, loop;
    char retorno[TAM_MAXIMO_MENSAGEM];

    ind = 0;

    //Recebe os dados
    do
    {
          if((bytes = recvfrom(socket, &buff, sizeof(strInfo), 0, (sockaddr_in *)&addr, sizeof(addr))) < 0)
          {
            printf("\n\n--------------  Erro  ------------");
            printf("\n\t\t  Erro ao receber dados");
            exit (-1);
          }

          recebido[ind] = buff;
          ind++;
    }while(strlen(buff.msg) >= TAM_BUFF);

    cont = ind;
    ind = 0;
    while(ind <= cont)
    {
        for(loop = 0; loop <= cont, loop++)
        {
            if(recebido[loop].indice == ind) ordenado[ind] = recebido[loop];
        }
    }

    memset(retorno, 0, TAM_MAXIMO_MENSAGEM);
    loop = 0;
    for(loop = 0; loop <= cont; loop++)
        strcat(retorno, ordenado[loop]);

    return(retorno);
}
