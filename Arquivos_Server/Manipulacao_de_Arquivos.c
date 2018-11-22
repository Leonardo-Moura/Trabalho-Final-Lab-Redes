#include <dirent.h>

anamnese le_arquivo(char id[])
{
	int descritor;
	char dados[2000];
	char nome_arquivo[100] = "";
	anamnese retorno;

	strcpy(nome_arquivo, get_current_dir_name());
	strcat(nome_arquivo, "/");
	strcat(nome_arquivo, id);
	strcat(nome_arquivo, ".anm");

	descritor = open(nome_arquivo, O_RDONLY);

	if (descritor < 0)
	{
		//Retorna vazio se não conseguiu abrir o arquivo
		strcpy(retorno.cpf, "");
		close(descritor);
		return(retorno);
	}
	else
	{
		if (read(descritor, &retorno, sizeof(anamnese)) < 0)
        	{
			strcpy(retorno.cpf, "");
            		close(descritor);
		            return(retorno);
        	}
        	else
        	{
            		close(descritor);
            		return(retorno);
        	}
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
	char retorno[2000];

	dir = opendir(get_current_dir_name());

	retorno = "";
	while((lsdir = readdir(dir)) != NULL)
	{
		strcat(retorno, lsdir->d_name);
	}

	closedir(dir);
	return retorno;
}
