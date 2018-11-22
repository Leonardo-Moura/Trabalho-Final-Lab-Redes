void exibe_anamnese(anamnese dados)
{
	system("clear");
	printf("Nome: %s", dados.nome);
	printf("\nCPF: %s", dados.cpf);
	printf("\nData de Nascimento: %s", dados.nascimento);
	printf("\nSexo: %c", dados.sexo);
	printf("\nTelefone: %s", dados.telefone);
	printf("\nEsta tomando algum medicamento: %s", dados.toma_algum_medicamento == SIM ? "Sim" : "Nao");
	if (dados.toma_algum_medicamento == SIM) { printf("\nMedicamento(s): %s", dados.qual_medicamento); }
	printf("\nTem alguma alergia: %s", dados.tem_alguma_alergia == SIM ? "Sim" : dados.tem_alguma_alergia == NAO ? "Nao" : "Nao sabe");
	if (dados.tem_alguma_alergia == SIM) { printf("\nAlergia(s): %s", dados.qual_alergia); }
	printf("\nTem ou teve algum problema de coracao: %s", dados.teve_problema_de_coracao == SIM ? "Sim" : "Nao");
	if (dados.teve_problema_de_coracao == SIM) { printf("\nProblema(s) de coracao: %s", dados.qual_problema_de_coracao); }
	printf("\nSente falta de ar com frequencia: %s", dados.sente_falta_de_ar_com_frequencia == SIM ? "Sim" : "Nao");
	printf("\nTem diabetes: %s", dados.tem_diabetes == SIM ? "Sim" : dados.tem_diabetes == NAO ? "Nao" : "Nao sabe");
	printf("\nQuando se corta ha um sangramento: %s", dados.tipo_de_sangramento == NORMAL ? "Normal" : "Excessivo");
	printf("\nSua cicatrizacao e: %s", dados.tipo_de_cicatrizacao == NORMAL ? "Normal" : "Complicada");
	printf("\nJa fez alguma cirurgia: %s", dados.ja_fez_cirurgia == SIM ? "Sim" : "Nao");
	if (dados.sexo == 'F')
	{
		printf("\nGestante: %s", dados.gestante == SIM ? "Sim" : "Nao");
		if (dados.gestante == SIM) { printf("\nSemanas: %d", dados.semanas_de_gestacao); }
	}
	if (strcmp(dados.problemas_de_saude_passados, "") != 0)
	{
		printf("\nProblemas de saude que ja teve: %s", dados.problemas_de_saude_passados);
	}
	printf("\nFuma: %s", dados.fuma == SIM ? "Sim" : "Nao");
	if (dados.fuma == SIM) { printf("\nQuantidade de cigarros por dia: %d", dados.qtd_de_cigarros_por_dia); }

	printf("\n\nPressione qualquer tecla para continuar...");
	getchar();
}

anamnese captura_anamnese()
{
	anamnese dados;
	char auxiliar[20];

	system("clear");
	printf("Nome: ");
	setbuf(stdin, 0);
	gets(dados.nome);
	printf("CPF: ");
	setbuf(stdin, 0);
	gets(dados.cpf);
	printf("Data de nascimento: ");
	setbuf(stdin, 0);
	gets(dados.nascimento);
	printf("Sexo(M|F): ");
	scanf("%c", &dados.sexo);
	printf("Telefone: ");
	setbuf(stdin, 0);
	getchar();
	gets(dados.telefone);
	printf("Esta tomando algum medicamento(Sim|Nao): ");
	gets(auxiliar);
	dados.toma_algum_medicamento = (strcasecmp(auxiliar, "Sim") == 0 ? SIM : NAO);
	if (dados.toma_algum_medicamento == SIM)
	{
		printf("Qual: ");
		gets(dados.qual_medicamento);
	}
	printf("Tem alguma alergia(Sim|Nao|Nao Sabe): ");
	gets(auxiliar);
	dados.tem_alguma_alergia = (strcasecmp(auxiliar, "Sim") == 0 ? SIM : (strcasecmp(auxiliar, "Nao") == 0 ? NAO : NAO_SABE));
	if (dados.tem_alguma_alergia == SIM)
	{
		printf("Qual: ");
		gets(dados.qual_alergia);
	}
	printf("Tem ou teve algum problema de coracao(Sim|Nao): ");
	gets(auxiliar);
	dados.teve_problema_de_coracao = (strcasecmp(auxiliar, "Sim") == 0 ? SIM : NAO);
	if (dados.teve_problema_de_coracao == SIM)
	{
		printf("Qual: ");
		gets(dados.qual_problema_de_coracao);
	}
	printf("Sente falta de ar com frequencia(Sim|Nao): ");
	gets(auxiliar);
	dados.sente_falta_de_ar_com_frequencia = (strcasecmp(auxiliar, "Sim") == 0 ? SIM : NAO);
	printf("Tem diabetes(Sim|Nao): ");
	gets(auxiliar);
	dados.tem_diabetes = (strcasecmp(auxiliar, "Sim") == 0 ? SIM : NAO);
	printf("Quando se corta ha um sangramento(Normal|Excessivo): ");
	gets(auxiliar);
	dados.tipo_de_sangramento = (strcasecmp(auxiliar, "Normal") == 0 ? NORMAL : EXCESSIVO);
	printf("Sua cicatrizacao e(Normal|Complicada): ");
	gets(auxiliar);
	dados.tipo_de_cicatrizacao = (strcasecmp(auxiliar, "Normal") == 0 ? NORMAL : COMPLICADO);
	printf("Ja fez alguma cirurgia(Sim|Nao): ");
	gets(auxiliar);
	dados.ja_fez_cirurgia = (strcasecmp(auxiliar, "Sim") == 0 ? SIM : NAO);
	if (dados.sexo == 'F')
	{
		printf("Gestante(Sim|Nao): ");
		gets(auxiliar);
		dados.gestante = (strcasecmp(auxiliar, "Sim") == 0 ? SIM : NAO);
		if (dados.gestante == SIM)
		{
			printf("Semanas de gestacao: ");
			scanf("%d", &dados.semanas_de_gestacao);
		}
	}
	printf("Fuma(Sim|Nao): ");
	gets(auxiliar);
	dados.fuma = (strcasecmp(auxiliar, "Sim") == 0 ? SIM : NAO);
	if (dados.fuma == SIM)
	{
		printf("Quantos cigarros por dia: ");
		scanf("%d", &dados.qtd_de_cigarros_por_dia);
	}

	return (dados);
}
