#include <stdio.h>
#include <stdlib.h>


int main()

{
	system("color 0F");
	int opc;
	//goto para validacao dos campos abaixo.
	inicio:;
	
	printf("\n\t ESCOLHA UMA OP%c%cO DE ATENDIMENTO: \n\t 1-Cliente \n\t 2-Empregado:	",128,199);
	scanf("%d",&opc);
	//validacao do campo acima.
	if(opc == 1)
	{
		//abre o sistema de atendimento do cliente.
		system("atendimento-cliente.exe");
	}
	else if(opc == 2)
	{
		//abre o sistema de atendimento do funcionario.
		system(" .exe");
	}
	else
	{
		
		printf("\n\t INSIRA UMA OP%c%cO V%cLIDA!! \n\t Tente novamente:	",128,199,181);
		goto inicio;
		
	}
	

	return(0);
}
