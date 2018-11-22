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
#include <fcntl.h>

#include "Defines_e_Estruturas.c"
#include "Funcoes_de_Manipulacao.c"


main (int argc, char *argv[])
{
   int       socketfd;
   char      filename[256];
   struct sockaddr_in   serv_addr;    //Estrutura de endereco do servidor

   //Verifica se entrou com todos os parametros
   if (argc != 3){
      printf("\n Digite o ip e a porta do servidor\n\n");
      exit(0);
   }

   //Guarda o nome do arquivo entrado na linha de comando 
   //strcpy(filename, argv[3]);
   
   //Preenche a estrutura "serv_addr" com o endereco do servidor
   bzero( (char*) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family        = AF_INET;
   serv_addr.sin_addr.s_addr  = inet_addr(argv[1]);
   serv_addr.sin_port        = htons(atoi(argv[2]));

   //Cria o socket TCP
   if ( (socketfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0){
  printf("cliente: erro na criacao do socket");
  exit(0);
   }

   //Se conecta ao servidor
   if (connect(socketfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
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
	anamnese dados;
	char auxiliar[20];
	info buff;
	int menu;
	int n;

	while (1)
	{
		system("clear");
		printf("(1) Ler anamnese \t (2) Nova anamnese \t (3) Sair");
		printf("\n\nOpcao: ");
		scanf("%d", &menu);

		switch (menu)
		{
		case LEITURA:
			buff.operacao = LEITURA;
			printf("Digite o CPF: ");
			setbuf(stdin, 0);
			gets(dados.cpf);
			buff.dados = dados;
			if(write(socketfd, &buff, sizeof(info)) != sizeof(info))
			{
				printf("Erro ao enviar dados para o processo filho.");
			}
			else
			{
				n = read(socketfd, &dados, sizeof(anamnese));
				if (n == sizeof(int))
				{
					printf("Erro ao ler arquivo.");
					getchar();
				}
				else if (n == sizeof(anamnese))
				{
					exibe_anamnese(dados);
				}
				else
				{
					printf("Erro ao receber dados do processo filho.");
				}
			}
			break;
		case ESCRITA:
			buff.operacao = ESCRITA;
			buff.dados = captura_anamnese();

			if ((n = write(socketfd, &buff, sizeof(info))) != sizeof(info))
			{
				printf("Erro ao enviar dados para o processo filho");
			}
			break;
		case SAIR:
			buff.operacao = SAIR;
			write(socketfd, &buff, sizeof(info));
			system("clear");
			exit(0);
		default:
			printf("Opcao invalida");
			getchar();
		}
	}
} // Fim da Funcao CLIENT
