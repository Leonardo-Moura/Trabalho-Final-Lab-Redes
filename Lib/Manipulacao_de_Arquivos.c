/*
	Autor: Leonardo Oliveira de Moura

	Funcoes para manipulacoes de arquivos
*/

#include <dirent.h>

#include "Lib.h"

char* le_arquivo_txt(char *nomeComExtensao)
{
	int descritor;
	char *dados = malloc(TAM_MAXIMO_MENSAGEM * sizeof(char));
	char *caminhoCompletoTxt = malloc(5000 * sizeof(char));

	memset(dados, 0, TAM_MAXIMO_MENSAGEM);
	memset(caminhoCompletoTxt, 0, 500);

	//Monta o caminho para abrir o arquivo na pasta do executável
	//strcpy(caminhoCompletoTxt, get_current_dir_name());
	getwd(caminhoCompletoTxt);
	strcat(caminhoCompletoTxt, "/");
	strcat(caminhoCompletoTxt, nomeComExtensao);
	printf("Caminho completo do arquivo a ser lido: %s\n", caminhoCompletoTxt);
	//Abre o arquivo para leitura
	descritor = open(caminhoCompletoTxt, O_RDONLY);
	if (descritor < 0)
	{
		printf("Erro ao abrir o arquivo para leitura\n");
		return "";
	}
	//Le o conteudo do arquivo
	if (read(descritor, dados, TAM_MAXIMO_MENSAGEM) < 0)
	{
		printf("\n\n------------    Erro    --------");
		printf("\n\tErro ao ler arquivo %s", caminhoCompletoTxt);
		exit (0);
	}
	else
	{
		close(descritor);
		printf("Dados lidos: \n%s\n", dados);
		return(dados);
	}
}

char* Lista_Arquivos()
{
	DIR *dir;
	struct dirent *lsdir;
	char *retorno = malloc(TAM_MAXIMO_MENSAGEM * sizeof(char));
	char *current_dir = malloc(500 * sizeof(char));
	int p;

	getwd(current_dir);
	dir = opendir(current_dir);
	memset(retorno, 0, TAM_MAXIMO_MENSAGEM);

	while((lsdir = readdir(dir)) != NULL)
	{
		strcat(retorno, lsdir->d_name);
		p = strlen(retorno);
		retorno[p] = '\n';
		retorno[p + 1] = '\0';
	}

	printf("Lista de arquivos lida: \n%s\n", retorno);
	closedir(dir);
	return retorno;
}
