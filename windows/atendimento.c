#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


// definindo tamanho maximo para a string nome em Medicamento.
#define MAX_MEDICAMENTOS 100
#define MAX_SERVICOS 100
#define MAX_EQUIPES 10 
#define MAX_PROFISSIONAIS 5 
#define MAX_NOME 100 

// informacoes de todos os clientes. 
typedef struct{
	
	char nome[20][50], estado[27][4], cidade[20][20], rua[20][50], historico[20][50];
	int idade, tam_string[5], opc,i, AtualizaCad;

}InfoCliente;

// informacoes das consultas.
typedef struct
{
	
	char prof_consul[100], semana[20], consul_horas[20], *pont_consul;

}MarcarConsulta;

// informacoes dos registros de atendimentos
typedef struct {
	
	int estado_paciente, atendimento_geral, pediatria, urologista, otorrinolaringologista, exame;
	char Apneia;

}RegistroConsulta;

// informacoes dos medicamentos
typedef struct {

    char nome[100];
    int quantidade;
    float preco;

} Medicamento;

// informacoes para controle financeiro da instituicao
typedef struct {

    char descricao[100];
    float valor;
    float faturamentoTotal; 
    float despesasTotal; 
    float lucroTotal; 

}Servico;

// informacoes de gerenciamento de equipes
typedef struct {
    char nome[MAX_NOME];
    int idade;
    char cargo[MAX_NOME];
} Profissional;

// informacoes de gerenciamento de equipes
typedef struct {
    Profissional profissionais[MAX_PROFISSIONAIS];
    int numProfissionais;
    char escalaTrabalho[7]; 
} Equipe;

// prototypes para as funcoes do programa.
void cadastroAlteracaoCliente(InfoCliente Cliente);
void agendamentoConsultas(MarcarConsulta Paciente);
void registroDeAtendimentos(RegistroConsulta Medico);
void gerenciamentoEstoque(Medicamento[], int, int, char []);
void controleFinanceiro(Servico[],int, int);
void integracaoSistemas();
void gerenciamentoEquipes(Equipe[], int, int);

int main()
{
	//mudanca de cor do console no sistema windows 
	system("color 0F");
	
	// declaracao de variaveis e tipos.
	InfoCliente Cliente;
	MarcarConsulta Paciente;
	RegistroConsulta Medico;
	Medicamento medicamentos[MAX_MEDICAMENTOS];
    Servico servicos[MAX_SERVICOS];
	Equipe equipes[MAX_EQUIPES]; 
    int numEquipes = 0, option, numServicos = 0, escolha, opc, opcao, index = 0;
    char nomeBusca[100];

	//goto para validacao dos campos abaixo.
	inicioAtendimento:;
	
	// menu principal.
	printf("\n\t ESCOLHA UMA OP%c%cO DE ATENDIMENTO: \n\t 1 -- Cliente \n\t 2 -- Empregado \n\t 3 -- Sair. \n\t >>> ",128,199);
	scanf("%d",&opc);

	//validacao do campo acima.
	if(opc == 1)
	{
		//abre o menu de atendimento ao cliente.
		printf("\n\t ESCOLHA UMA OP%c%cO DE ATENDIMENTO AO CLIENTE: \n\t 1 -- Cadastro/Alter%c%co de Clientes \n\t 2 -- Agendamento de consultas \n\t 3 -- Voltar. \n\t >>> ",128,199,135,198);
		scanf("%d",&opc);

		if(opc == 1)
		{
			//abre o sistema de cadastro e atualizacao de informacaoes do cliente.
			cadastroAlteracaoCliente(Cliente);
			goto inicioAtendimento;
		}
		else if(opc == 2)
		{
			//abre o sistema de agendamento de consultas.
			agendamentoConsultas(Paciente);
			goto inicioAtendimento;
		}
		else if(opc == 3)
		{
			goto inicioAtendimento;
		}
		else
		{
			printf("\n\t INSIRA UMA OP%c%cO V%cLIDA!! \n\t Tente novamente:	",128,199,181);
			goto inicioAtendimento;
		}
	}
	else if(opc == 2)
	{
		//abre o menu de atendimento do funcionario.
		printf("\n\t ESCOLHA UMA OP%c%cO DE ATENDIMENTO AO FUNCIONARIO: \n\t 1 -- Registro de atendimentos \n\t 2 -- Gerenciamento de estoque \n\t 3 -- Faturamento e controle financeiro.	\n\t 4 -- Gerenciamento de equipes. \n\t 5 -- Voltar. \n\t >>> ",128,199);
		scanf("%d",&opc);
		
		if(opc == 1)
		{
			// 
			registroDeAtendimentos(Medico);
			goto inicioAtendimento;
		}
		else if(opc == 2)
		{
			gerenciamentoEstoque(medicamentos, opcao, index, nomeBusca);
			goto inicioAtendimento;
		}
		else if(opc == 3)
		{
			controleFinanceiro(servicos, numServicos, escolha);
			goto inicioAtendimento;
		}
		else if(opc == 4)
		{
			gerenciamentoEquipes(equipes, numEquipes, option);
			goto inicioAtendimento;
		}
		else if(opc == 5)
		{
			goto inicioAtendimento;
		}
		else
		{
			printf("\n\t INSIRA UMA OP%c%cO V%cLIDA!! \n\t Tente novamente:	",128,199,181);
			goto inicioAtendimento;
		}
	}
	else if(opc == 3)
	{
		goto fimAtendimento;
	}
	else
	{
		
		printf("\n\t INSIRA UMA OP%c%cO V%cLIDA!! \n\t Tente novamente:	",128,199,181);
		goto inicioAtendimento;
		
	}
	
	fimAtendimento:;

	return(0);
}


void cadastroAlteracaoCliente(InfoCliente Cliente)
{
	Cliente.i = 0;
	iniCad:;
	
	printf("\n\t Voc%c deseja cadastrar ou atualizar dados de um paci%cnte? \n\t 1 -- Atualizar \n\t 2 -- Cadastrar \n\t 3 -- Voltar \n\t >>> ");
	scanf("%d",&Cliente.AtualizaCad);

	if(Cliente.AtualizaCad == 2)
	{
		do{
		//goto para validacao dos campos abaixo.
		inicio:;
		//compos para cadastro do paciente/cliente.
		fflush(stdin);
		printf("\n\t Insira o nome do %d%c paciente:	",Cliente.i+1,167);
		fgets(Cliente.nome[Cliente.i],50,stdin);



		fflush(stdin);
		printf("\n\t Insira o endere%co %d%c do paciente:\n\tESTADO (Ex.: MA ou M.A.):	",135,Cliente.i+1,167);
		fgets(Cliente.estado[Cliente.i],4,stdin);


		fflush(stdin);
		printf("\n\t Insira o endere%co %d%c do paciente:\n\tCIDADE:	",135,Cliente.i+1,167);
		fgets(Cliente.cidade[Cliente.i],20,stdin);
		


		fflush(stdin);
		printf("\n\t Insira o endere%co %d%c do paciente:\n\tRUA:	",135,Cliente.i+1,167);
		fgets(Cliente.rua[Cliente.i],50,stdin);
		


		fflush(stdin);
		printf("\n\t Insira o hist%crico do paciente:\n\t (Caso n%co possua hist%crico deixe em branco)	",162,198,162);
		fgets(Cliente.historico[Cliente.i],50,stdin);

		//medindo o tamanho das strings dos campos acima.
		Cliente.tam_string[0] = strlen(Cliente.nome[Cliente.i]);
		Cliente.tam_string[1] = strlen(Cliente.estado[Cliente.i]);
		Cliente.tam_string[2] = strlen(Cliente.cidade[Cliente.i]);
		Cliente.tam_string[3] = strlen(Cliente.rua[Cliente.i]);
		Cliente.tam_string[4] = strlen(Cliente.historico[Cliente.i]);
		//validacao dos campos do cadastro.
		if(Cliente.tam_string[0] > 50)
		{
			
			printf("\n\t Nome inv%clido \n\t Insira um nome com menos de 49 caracteres! \n\t Ultilize abrevia%c%ces.",160,135,228);
			goto inicio;
		
		}
		else if(Cliente.tam_string[1] > 4)
		{
			
			printf("\n\t Estado inv%clido \n\t Insira um estado com menos de 3 caracteres! \n\t Ultilize abrevia%c%ces.",160,135,228);
			goto inicio;
		
		}
		else if(Cliente.tam_string[2] > 20)
		{
		
			printf("\n\t Cidade inv%clido \n\t Insira uma cidade com menos de 20 caracteres! \n\t Ultilize abrevia%c%ces.",160,135,228);
			goto inicio;
		
		}
		else if(Cliente.tam_string[3] > 50) 
		{
			printf("\n\t Rua inv%clida \n\t Insira um nome de uma rua com menos de 20 caracteres! \n\t Ultilize abrevia%c%ces.");
			goto inicio;
		}
		else if(Cliente.tam_string[3] > 50)
		{
			
			printf("\n\t Hist%crico inv%clido \n\t Insira um hist%crico com menos de 50 caracteres! \n\t Ultilize abrevia%c%ces.",162,135,162,135,228);	
			goto inicio;
		}
		else
		{
			//confirmacao das informacoes inseridas.
			printf("\n\t CADASTRO REALIZADO COM SUCESSO!");
			printf("\n\t %s",Cliente.nome[Cliente.i]);
			printf("\n\t %s",Cliente.estado[Cliente.i]);
			printf("\n\t %s",Cliente.cidade[Cliente.i]);
			printf("\n\t %s",Cliente.rua[Cliente.i]);
			printf("\n\t %s",Cliente.historico[Cliente.i]);

			//opcao para cadastro de mais de um paciente/cliente.
			printf("\n\t Deseja cadastrar outro cliente? \n\t <1> para sim <2> para n%co:	",198);
			scanf("%d",&Cliente.opc);		
		
		}

		//incrementando a cada cliente cadastrado
		Cliente.i++;

		}while(Cliente.opc == 1 && Cliente.i < 20);

		//"barra de carregamento."
		printf("\n\t\tCARREGANDO\n\t");
		for(int ind = 0; ind < 30;ind++)
		{
			printf("=");
			//pausando a execucao por menos de meio milisegundo.

			_sleep(50);
		}

		//exibindo o total de pacientes/clientes cadastrados.
		printf("\n");
		printf("\n\t TOTAL DE CADASTROS:	%d",Cliente.i);
		
		if(Cliente.i != 0)
		{
			for(int index = 0; index < Cliente.i;index++)
			{
				printf("\n\t----------------------------\n\t %s \n\t %s \n\t %s \n\t %s \n\t %s \n\t----------------------------",Cliente.nome[index],Cliente.estado[index],Cliente.cidade[index],Cliente.rua[index],Cliente.historico[index]);
			}
		}
		else
		{
			printf("\n\t TOTAL DE CADASTROS:	%d",Cliente.i);
		}
	}
	else if(Cliente.AtualizaCad == 1)
	{
		iniAtu:;
		for(int in = 0; in < 20;in++)
		{
			printf("\n\t N%c:	%d -- Nome:		%s.",167,in+1,Cliente.nome[in]);
			printf("\n\t Hist%crico:	%s",162,Cliente.historico[in]);
		}

		printf("\n\t Selecione o numero do cliente para fazer a alteracao:	");
		scanf("%d",&Cliente.AtualizaCad);

		printf("\n\tNome Anterior:	%s Nome Atual:	",Cliente.nome[Cliente.AtualizaCad]);
		scanf("%s",&Cliente.nome[Cliente.AtualizaCad]);

		printf("\n\tNome Anterior:	%s Nome Atual:	",Cliente.estado[Cliente.AtualizaCad]);
		scanf("%s",&Cliente.estado[Cliente.AtualizaCad]);

		printf("\n\tNome Anterior:	%s Nome Atual:	",Cliente.cidade[Cliente.AtualizaCad]);
		scanf("%s",&Cliente.cidade[Cliente.AtualizaCad]);

		printf("\n\tNome Anterior:	%s Nome Atual:	",Cliente.rua[Cliente.AtualizaCad]);
		scanf("%s",&Cliente.rua[Cliente.AtualizaCad]);

		printf("\n\tNome Anterior:	%s Nome Atual:	",Cliente.historico[Cliente.AtualizaCad]);
		scanf("%s",&Cliente.historico[Cliente.AtualizaCad]);

		iniAtuNovo:;

		printf("\n\t Deseja alterar novamente? 1 -- sim \n\t 2 -- nao");
		scanf("%d",&Cliente.AtualizaCad);

		if(Cliente.AtualizaCad == 1)
		{
			goto iniAtu;
		}
		else if(Cliente.AtualizaCad == 2)
		{
			goto iniCad;
		}
		else
		{
			printf("\n\t INSIRA UMA OP%c%cO V%cLIDA!! \n\t Tente novamente:	",128,199,181);
			goto iniAtuNovo;
		}
	}
	else if(Cliente.AtualizaCad == 3)
	{
		return;
	}
	else
	{

		printf("\n\t INSIRA UMA OP%c%cO V%cLIDA!! \n\t Tente novamente:	",128,199,181);
		goto iniCad;

	}
}

void agendamentoConsultas(MarcarConsulta Paciente)
{

	FILE *pont_consul;
    
    printf("ol� seja Bem vindo ao Hospital Murkoff?\nveja a seguir nossos profissionais e agende sua consulta:\n\n");
    printf("\nAtendemos de segunda � sab�do\n");
	printf("Atendimento Geral (Valor R$120,00)\nHorarios:(8:00h AM), (13:00h PM), (19:00h PM)");
    printf("\n\nUolrogista (Valor R$375,00)\nHorarios:(10:00h AM), (16:00h PM), (20:00h PM)");
    printf("\n\nPediatria (Valor R$150,00)\nHorarios:(9:30h AM), (15:00h PM), (18:00h PM)");
    printf("\n\nrdiologia (Valor R$250,00)\nHorarios:(11:00h AM), (17:00h PM), (21:00h PM)");
    printf("\n\nOtorrinolaringologista (Valor R$450,00)\nHorarios:(7:00h AM), (14:00h PM), (17:30h PM)");
    
    
    Paciente.pont_consul = fopen("consulta.txt", "w");
	
	printf("\n\nDeseja agendar uma consulta com qual Profissional?\n\n");
	scanf("%s", &Paciente.prof_consul);
	
	fprintf(Paciente.pont_consul, "%s\n", Paciente.prof_consul);
	
	fclose(Paciente.pont_consul);
	
	Paciente.pont_consul = fopen("consulta.txt", "a");
	
	printf("\n\nQue dia da semana ?\n\n");
	scanf("%s", &Paciente.semana);
	
	fprintf(Paciente.pont_consul, "%s\n", Paciente.semana);
	
	printf("\n\nEm qual horario?\n\n");
	scanf("%s", &Paciente.consul_horas);
	
	fprintf(Paciente.pont_consul, "%s\n", Paciente.consul_horas);
	
	fclose(Paciente.pont_consul);
	
	printf("\n\nOk, consulta agendada com Sucesso\n\n");
	
	printf("\n\t Pressione qualquer tecla para voltar.");
	getch();

	return;
}

void registroDeAtendimentos(RegistroConsulta Medico)
{
	printf("Olá, Bem vindo (a) ao registro de atendimentos Albert Einstein.\n");
	
	printf("Tudo bem ? Digite em uma escala de 1 a 3 com você está se sentindo.\n1(Extremamente bem.) 2(Levemente Ruim) 3(Morrendo aos Poucos.)");
	scanf("%d", &Medico.estado_paciente);
	switch (Medico.estado_paciente){
		case 1:
			printf("Você está muito bem e a demora do atendimento será de 15 minutos.\n");
			break;
		case 2:
			printf("Você está com um certo risco, aguarde 10 minutos para ser atendido(a).\n");
			break;
		case 3:
			printf("Faça a sua oração e aguarde de 3 a 5 minutos.\n");
			break;
		default :
    		printf ("Valor invalido!\n");
    		break;
	}
	
	printf("\nAgora, você receberá sua prescrição médica sobre os cuidados que deverá ter com sua saúde.\n");
	printf("Qual foi o exame que você fez ?\n 1(Atendimento Geral) 2(Pediatria) 3(Urologista) 4(Cardiologia) 5(Otorrinolaringologia): \n");
	scanf("%d",&Medico.exame);
	if(Medico.exame == 1){
	    
	    printf("Pois bem, Digite em uma escala de 1 a 3 qual é o seu problema.\n1(Dores no peito.) 2(Dores de cabeça.) 3(Alergias.)");
	    scanf("%d",&Medico.atendimento_geral);
	    
	    if(Medico.atendimento_geral == 1){
	        printf("As dores no peito\n...");
	   }
	   else if(Medico.atendimento_geral == 2){
	       printf("As dores de cabeça\n...");
	   }
	   else if(Medico.atendimento_geral == 3){
	       printf("A Alergias é\n...");
	   }
	   else{
	        printf("Valor invalido.");
	    }
	}
	
	if(Medico.exame == 2){
	     printf("Pois bem, Digite em uma escala de 1 a 3 qual é o seu problema.\n1(Febre.) 2(Falta de apetite.) 3(Pneumonia.)");
	    scanf("%d",&Medico.atendimento_geral);
	    
	    if(Medico.atendimento_geral == 1){
	        printf("A Febre\n...");
	   }
	   else if(Medico.atendimento_geral == 2){
	       printf("As Falta de apetite\n ...");
	   }
	   else if(Medico.atendimento_geral == 3){
	       printf("A Pneumonia\n ...");
	   }
	   else{
	        printf("Valor invalido.");
	    }
	}
	
	if(Medico.exame == 3){
	     printf("Pois bem, Digite em uma escala de 1 a 3 qual é o seu problema.\n1(DSTs.) 2(Infecções.) 3(Cálculos Renais.)");
	    scanf("%d",&Medico.atendimento_geral);
	    
	    if(Medico.atendimento_geral == 1){
	        printf("As DSTs\n...");
	   }
	   else if(Medico.atendimento_geral == 2){
	       printf("As infecções\n ...");
	   }
	   else if(Medico.atendimento_geral == 3){
	       printf("Os Cálculos Renais\n ...");
	   }
	   else{
	        printf("Valor invalido.");
	    }
	}
	
	if(Medico.exame == 4){
	     printf("Pois bem, Digite em uma escala de 1 a 3 qual é o seu problema.\n 1(Aterosclerose.) 2(AVC-Acidente Vascular Cerebral) 3(Hipertensão.)\n");
	    scanf("%d",&Medico.atendimento_geral);
	    
	    if(Medico.atendimento_geral == 1){
	        printf("Aterosclerose são veias entupidas por placas de gorduras. \nO acúmulo de gorduras mal ingeridas podem ir para alguma veia do coração e prejudicar a sua saúde. \nO seu tratamento pode começar por hábitos mais saudaveis na alimentação e a prática de exercícios físicos no dia dia.\n");
	   }
	   else if(Medico.atendimento_geral == 2){
	       printf("O AVC causa danos ao cérebro devido à interrupção do fornecimento de sangue, não existe cura, mas o tratamento pode ajudar. \nO tratamento é feito com o uso de anticoagulantes que pode minimizar os danos, além do monitoramento cardíaco e outros.\n");
	   }
	   else if(Medico.atendimento_geral == 3){
	       printf("A Hipertensão é a condição em que a força do sangue contra a pressão das artérias é muito grande. \nNormalmente, acima de 14/9 já é definido como hipertensão e é considerada grave acima de 18/12.\n");
	   }
	   else{
	        printf("Valor invalido.");
	    }
	}
	
	if(Medico.exame == 5){
	     printf("Pois bem, Digite em uma escala de 1 a 3 qual é o seu problema.\n 1(Surdez.) 2(Amigdalite) 3(Apneia.)");
	    scanf("%d",&Medico.atendimento_geral);
	    
	    if(Medico.atendimento_geral == 1){
	        printf("A Surdez...");
	   }
	   else if(Medico.atendimento_geral == 2){
	       printf("As Amigdalite\n ...");
	   }
	   else if(Medico.atendimento_geral == 3){
	       printf("À Apneia ...", Medico.Apneia);
	   }
	   else{
	        printf("Valor invalido\n.");
	    }
	}
}

void gerenciamentoEstoque(Medicamento medicamentos[], int opcao, int index, char nomeBusca[])
{
    do {
		printf("\n*** Controle de Estoque de Medicamentos ***\n");
		printf("1. Cadastrar Medicamento\n");
		printf("2. Consultar Medicamento\n");
		printf("3. Atualizar Medicamento\n");
		printf("4. Excluir Medicamento\n");
		printf("5. Exibir Relat�rio de Medicamentos\n");
		printf("6. Sair\n");
		printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (index < MAX_MEDICAMENTOS) {
                    printf("\n--- Cadastro de Medicamento ---\n");
                    printf("Nome: ");
                    scanf("%s", &medicamentos[index].nome);
                    printf("Quantidade: ");
                    scanf("%d", &medicamentos[index].quantidade);
                    printf("Pre�o: ");
                    scanf("%f", &medicamentos[index].preco);
                    index++;
                    printf("Medicamento cadastrado com sucesso!\n");
                } else {
                    printf("Limite m�ximo de medicamentos alcan�ado.\n");
                }
                break;
            case 2:
                if (index > 0) {
                    printf("\n--- Consulta de Medicamento ---\n");
                    printf("Digite o nome do medicamento: ");
                    scanf("%s", nomeBusca);
                    int encontrado = 0;
                    for (int j = 0; j < index; j++) {
                        if (strcmp(medicamentos[j].nome, nomeBusca) == 0) {
                            printf("Nome: %s\n", medicamentos[j].nome);
                            printf("Quantidade: %d\n", medicamentos[j].quantidade);
                            printf("Pre�o: %.2f\n", medicamentos[j].preco);
                            encontrado = 1;
                            break;
                        }
                    }
                    if (!encontrado) {
                        printf("Medicamento n�o encontrado.\n");
                    }
                } else {
                    printf("Nenhum medicamento cadastrado.\n");
                }
                break;
            case 3:
                if (index > 0) {
                    printf("\n--- Atualiza��o de Medicamento ---\n");
                    printf("Digite o nome do medicamento: ");
                    scanf("%s", nomeBusca);
                    int encontrado = 0;
                    for (int j = 0; j < index; j++) {
                        if (strcmp(medicamentos[j].nome, nomeBusca) == 0) {
                            printf("Novo nome (ou enter para manter o mesmo): ");
                            scanf("%s", medicamentos[j].nome);
                            printf("Nova quantidade (ou -1 para manter a mesma): ");
                            scanf("%d", &medicamentos[j].quantidade);
                            if (medicamentos[j].quantidade != -1) {
                                printf("Novo pre�o (ou -1 para manter o mesmo): ");
                                scanf("%f", &medicamentos[j].preco);
                            }
                            printf("Medicamento atualizado com sucesso!\n");
                            encontrado = 1;
                            break;
                        }
                    }
                    if (!encontrado) {
                        printf("Medicamento n�o encontrado.\n");
                    }
                } else {
                    printf("Nenhum medicamento cadastrado.\n");
                }
                break;
            case 4:
                if (index > 0) {
                    printf("\n--- Exclus�o de Medicamento ---\n");
                    printf("Digite o nome do medicamento: ");
                    scanf("%s", nomeBusca);
                    int encontrado = 0;
                    for (int j = 0; j < index; j++) {
                        if (strcmp(medicamentos[j].nome, nomeBusca) == 0) {
                            for (int k = j; k < index - 1; k++) {
                                medicamentos[k] = medicamentos[k + 1];
                            }
                            index--;
                            printf("Medicamento exclu�do com sucesso!\n");
                            encontrado = 1;
                            break;
                        }
                    }
                    if (!encontrado) {
                        printf("Medicamento n�o encontrado.\n");
                    }
                } else {
                    printf("Nenhum medicamento cadastrado.\n");
                }
                break;
            case 5:
                if (index > 0) {
                    printf("\n--- Relat�rio de Medicamentos ---\n");
                    printf("Nome\tQuantidade\tPre�o\n");
                    for (int j = 0; j < index; j++) {
                        printf("%s\t%d\t\t%.2f\n", medicamentos[j].nome, medicamentos[j].quantidade, medicamentos[j].preco);
                    }
                } else {
                    printf("Nenhum medicamento cadastrado.\n");
                }
                break;
            case 6:
                printf("Voltando para o menu principal...\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
                break;
        }

    } while (opcao != 6);

	return;
}

void controleFinanceiro(Servico servicos[],int numServicos, int escolha)
{
	    do {
        printf("\n--- Faturamento e Controle Financeiro ---\n");
        printf("1. Registrar novo servi�o\n");
        printf("2. Consultar servi�os\n");
        printf("3. Exibir faturamento e controle financeiro\n");
        printf("4. Sair\n");
        printf("Digite a op��o desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (numServicos < MAX_SERVICOS) {
                    printf("\n--- Registrar novo servi�o ---\n");
                    printf("Descri��o do servi�o: ");
                    scanf(" %[^\n]s", servicos[numServicos].descricao);
                    printf("Valor do servi�o: R$ ");
                    scanf("%f", &servicos[numServicos].valor);
                    printf("Servi�o registrado com sucesso!\n");
                    numServicos++;
                } else {
                    printf("N�mero m�ximo de servi�os registrados alcan�ado.\n");
                }
                break;
            case 2:
                if (numServicos > 0) {
                    printf("\n--- Consultar servi�os ---\n");
                    for (int i = 0; i < numServicos; i++) {
                        printf("Servi�o %d:\n", i + 1);
                        printf("Descri��o: %s\n", servicos[i].descricao);
                        printf("Valor: R$ %.2f\n", servicos[i].valor);
                    }
                } else {
                    printf("Nenhum servi�o registrado ainda.\n");
                }
                break;
            case 3:
                printf("\n--- Faturamento e Controle Financeiro ---\n");
                printf("Total de servi�os prestados: %d\n", numServicos);
                for (int i = 0; i < numServicos; i++) {
                    servicos->faturamentoTotal += servicos[i].valor;
                }
                printf("Faturamento Total: R$ %.2f\n", servicos->faturamentoTotal);
                printf("Digite o total de despesas: R$ ");
                scanf("%f", &servicos->despesasTotal);
                servicos->lucroTotal = servicos->faturamentoTotal - servicos->despesasTotal;
                printf("Lucro Total: R$ %.2f\n", servicos->lucroTotal);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Op��o inv�lida. Por favor, tente novamente.\n");
                break;
        }

    } while (escolha != 4);

}

void integracaoSistemas()
{

}

void gerenciamentoEquipes(Equipe equipes[], int numEquipes, int option)
{
	    do {
        printf("\n--- Gerenciamento de Equipes ---\n");
        printf("1. Registrar nova equipe\n");
        printf("2. Registrar profissional em equipe\n");
        printf("3. Exibir escala de trabalho de equipe\n");
        printf("4. Sair\n");
        printf("Digite a op��o desejada: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (numEquipes < MAX_EQUIPES) {
                    printf("\n--- Registrar nova equipe ---\n");
                    printf("Digite a escala de trabalho (7 dias da semana): ");
                    scanf(" %[^\n]s", equipes[numEquipes].escalaTrabalho);
                    equipes[numEquipes].numProfissionais = 0;
                    printf("Equipe registrada com sucesso!\n");
                    numEquipes++;
                } else {
                    printf("N�mero m�ximo de equipes registradas alcan�ado.\n");
                }
                break;
            case 2:
                if (numEquipes > 0) {
                    printf("\n--- Registrar profissional em equipe ---\n");
                    char escala[MAX_NOME];
                    printf("Digite a escala de trabalho (7 dias da semana): ");
                    scanf(" %[^\n]s", escala);

                    int equipeEncontrada = 0;
                    for (int i = 0; i < numEquipes; i++) {
                        if (strcmp(escala, equipes[i].escalaTrabalho) == 0) {
                            printf("Digite o nome do profissional: ");
                            scanf(" %[^\n]s", equipes[i].profissionais[equipes[i].numProfissionais].nome);
                            printf("Digite a idade do profissional: ");
                            scanf("%d", &equipes[i].profissionais[equipes[i].numProfissionais].idade);
                            printf("Digite o cargo do profissional: ");
                            scanf(" %[^\n]s", equipes[i].profissionais[equipes[i].numProfissionais].cargo);
                            printf("Profissional registrado na equipe com sucesso!\n");
                            equipes[i].numProfissionais++;
                            equipeEncontrada = 1;
                            break;
                        }
                    }

                    if (!equipeEncontrada) {
                        printf("Nenhuma equipe encontrada para a escala de trabalho informada.\n");
                    }
                } else {
                    printf("Nenhuma equipe encontrada. Por favor, registre uma equipe antes de adicionar profissionais.\n");
                }
                break;
            case 3:
                if (numEquipes > 0) {
                    printf("\n--- Exibir escala de trabalho de equipe ---\n");
                    char escala[MAX_NOME];
                    printf("Digite a escala de trabalho (7 dias da semana): ");
                    scanf(" %[^\n]s", escala);

                    int equipeEncontrada = 0;
                    for (int i = 0; i < numEquipes; i++) {
                        if (strcmp(escala, equipes[i].escalaTrabalho) == 0) {
                            printf("Escala de trabalho da equipe:\n");
                            printf("Escala: %s\n", equipes[i].escalaTrabalho);
                            printf("Profissionais:\n");
                            for (int j = 0; j < equipes[i].numProfissionais; j++) {
                                printf("Nome: %s\n", equipes[i].profissionais[j].nome);
                                printf("Idade: %d\n", equipes[i].profissionais[j].idade);
                                printf("Cargo: %s\n", equipes[i].profissionais[j].cargo);
                            }
                            equipeEncontrada = 1;
                            break;
                        }
                    }

                    if (!equipeEncontrada) {
                        printf("Nenhuma equipe encontrada para a escala de trabalho informada.\n");
                    }
                } else {
                    printf("Nenhuma equipe registrada. Por favor, registre uma equipe antes de exibir a escala de trabalho.\n");
                }
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Op��o inv�lida. Por favor, digite uma op��o v�lida.\n");
                break;
        }
    } while (option != 4);
}