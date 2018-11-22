/*
    Autor: Leonardo Oliveira de Moura

    Funcoes para manipulacoes de arquivos
*/

#include <dirent.h>

char* le_arquivo_txt(char nomeComExtensao[])
{
    int descritor;
    char dados[TAM_MAXIMO_MENSAGEM];
    char caminhoCompletoTxt[500] = "";

    //Monta o caminho para abrir o arquivo na pasta do executável
    strcpy(caminhoCompletoTxt, get_current_dir_name);
    strcat(caminhoCompletoTxt, "/");
    strcat(caminhoCompletoTxt, nomeComExtensao);

    //Abre o arquivo para leitura
    descritor = open(caminhoCompletoTxt, O_RDONLY);

    //Le o conteudo do arquivo
    if (read(descritor, &retorno, sizeof(anamnese)) < 0)
    {
        printf("\n\n------------    Erro    --------");
        printf("\n\tErro ao ler arquivo %s", caminhoCompletoTxt);
        exit (0);
    }
    else
    {
        close(descritor);
        return(retorno);
    }
}

int escreve_arquivo(anamnese dados)
{
	int descritor, n;
	char string_de_gravacao[2000]; //Verificar qual o tamanho em bytes de uma anamnese
	char nome_arquivo[100];

	strcpy(nome_arquivo, get_current_dir_name());
	strcat(nome_arquivo, "/");
	strcat(nome_arquivo, dados.cpf);
	strcat(nome_arquivo, ".anm");

	descritor = open(nome_arquivo, O_WRONLY|O_CREAT, 0744);

	if (descritor < 0)
	{
		printf("%s\n", strerror(errno));
		close(descritor);
		return(FALSE);
	}
	else
	{
		//escreve no arquivo
		n = write(descritor, &dados, sizeof(anamnese));
        	if (n != sizeof(anamnese))
        	{
            		close(descritor);
            		return (FALSE);
        	}
        	else
        	{
			printf("Salvando em %s", nome_arquivo);
            		close(descritor);
            		return(TRUE);
        	}
	}
}

string Lista_Arquivos()
{
	DIR *dir;
	struct dirent *lsdir;
	char retorno[TAM_MAXIMO_MENSAGEM];

	dir = opendir(get_current_dir_name());

	retorno = "";
	while((lsdir = readdir(dir)) != NULL)
	{
		strcat(retorno, lsdir->d_name);
	}

	closedir(dir);
	return retorno;
}
