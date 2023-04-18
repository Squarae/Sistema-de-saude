#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
	
	char nome[20][50], estado[27][4], cidade[20][20], rua[20][50], historico[20][50];
	int idade, i = 0, tam_string[5], opc;
	
	do{
	//goto para validacao dos campos abaixo.
	inicio:;
	//compos para cadastro do paciente/cliente.
	fflush(stdin);
	printf("\n\t Insira o nome do %d%c paciente:	insira <p> para pular o cadastro	",i+1,167);
	fgets(nome[i],50,stdin);

	if(nome[i][50] == 'p')
	{

		break;

	}

	fflush(stdin);
	printf("\n\t Insira o endere%co %d%c do paciente:\n\tESTADO (Ex.: MA ou M.A.):		insira <p> para pular o cadastro	",135,i+1,167);
	fgets(estado[i],4,stdin);
	
	if(estado[i][4] == 'p')
	{

		break;

	}

	fflush(stdin);
	printf("\n\t Insira o endere%co %d%c do paciente:\n\tCIDADE:	insira <p> para pular o cadastro	",135,i+1,167);
	fgets(cidade[i],20,stdin);
	
	if(cidade[i][20] == 'p')
	{

		break;

	}

	fflush(stdin);
	printf("\n\t Insira o endere%co %d%c do paciente:\n\tRUA:	insira <p> para pular o cadastro	",135,i+1,167);
	fgets(rua[i],50,stdin);
	
	if(rua[i][50] == 'p')
	{
		break;
	}

	fflush(stdin);
	printf("\n\t Insira o hist%crico do paciente:\n\t Caso n%co possua hist%crico insira <p> para pular	",162,198,162);
	fgets(historico[i],50,stdin);

	if(historico[i][50] == 'p')
	{
		break;
	}

	//medindo o tamanho das strings dos campos acima.
	tam_string[0] = strlen(nome[i]);
	tam_string[1] = strlen(estado[i]);
	tam_string[2] = strlen(cidade[i]);
	tam_string[3] = strlen(rua[i]);
	tam_string[4] = strlen(historico[i]);
	//validacao dos campos do cadastro.
	if(tam_string[0] > 50)
	{
		
		printf("\n\t Nome inv%clido \n\t Insira um nome com menos de 49 caracteres! \n\t Ultilize abrevia%c%ces.",160,135,228);
		goto inicio;
	
	}
	else if(tam_string[1] > 4)
	{
		
		printf("\n\t Estado inv%clido \n\t Insira um estado com menos de 3 caracteres! \n\t Ultilize abrevia%c%ces.",160,135,228);
		goto inicio;
	
	}
	else if(tam_string[2] > 20)
	{
	
		printf("\n\t Cidade inv%clido \n\t Insira uma cidade com menos de 20 caracteres! \n\t Ultilize abrevia%c%ces.",160,135,228);
		goto inicio;
	
	}
	else if(tam_string[3] > 50) 
	{
		printf("\n\t Rua inv%clida \n\t Insira um nome de uma rua com menos de 20 caracteres! \n\t Ultilize abrevia%c%ces.");
		goto inicio;
	}
	else if(tam_string[3] > 50)
	{
		
		printf("\n\t Hist%crico inv%clido \n\t Insira um hist%crico com menos de 50 caracteres! \n\t Ultilize abrevia%c%ces.",162,135,162,135,228);	
		goto inicio;
	}
	else
	{
		//confirmacao das informacoes inseridas.
		printf("\n\t CADASTRO REALIZADO COM SUCESSO!");
		printf("\n\t %s",nome[i]);
		printf("\n\t %s",estado[i]);
		printf("\n\t %s",cidade[i]);
		printf("\n\t %s",rua[i]);
		printf("\n\t %s",historico[i]);
		//opcao para cadastro de mais de um paciente/cliente.
		printf("\n\t Deseja cadastrar outro cliente? \n\t <1> para sim <2> para n%co:	",198);
		scanf("%d",&opc);		
	
	}

	//incrementando a cada cliente cadastrado
	i++;

	}while(opc == 1);
	//"load-bar."
	printf("\n\t\tCARREGANDO\n\t");
	for(int ind = 0; ind < 30;ind++)
	{
		printf("=");
		//pausando a execucao por menos de meio milisegundo.
		Sleep(50);
	}
	//exibindo o total de pacientes/clientes cadastrados.
	printf("\n");
	printf("\n\t TOTAL DE CADASTROS:	%d",i);
	
	if(i != 0)
	{
		for(int index = 0; index < i;index++)
		{
			printf("\n\t----------------------------\n\t %s \n\t %s \n\t %s \n\t %s \n\t %s \n\t----------------------------",nome[index],estado[index],cidade[index],rua[index],historico[index]);
		}
	}
	else
	{
		printf("\n\t TOTAL DE CADASTROS:	%d",i);
	}

	
	
	return(0);
}
