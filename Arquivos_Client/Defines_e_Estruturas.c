#define MAXBUFF 1024  // numero de caract. do buffer
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
    char nome[100];
    char cpf[15];
    char nascimento[11];
    char sexo;
    char telefone[15];
    int toma_algum_medicamento;
    char qual_medicamento[200];
    int tem_alguma_alergia;
    char qual_alergia[200];
    int teve_problema_de_coracao;
    char qual_problema_de_coracao[200];
    int sente_falta_de_ar_com_frequencia;
    int tem_diabetes;
    int tipo_de_sangramento; //normal | excessivo
    int tipo_de_cicatrizacao; //normal | complicada
    int ja_fez_cirurgia;
    int gestante;
    int semanas_de_gestacao;
    char problemas_de_saude_passados[1000];
    int fuma;
    int qtd_de_cigarros_por_dia;
} anamnese;

typedef struct
{
	int operacao;
	char nome[100];
	anamnese dados;
} info;
