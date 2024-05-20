// Registro de funcionario

#include<iostream>
#include<string.h>
#include <windows.h>
int menu(){
	int opcao;
	system("Color 7");
	system("cls");
	printf("[ 1 ] Inclusao do funcionario \n");
	printf("[ 2 ] Consulta aos dados do funcionario \n");
	printf("[ 3 ] Consulta salario liquido \n");
	printf("[ 4 ] Fim do App \n");
	printf("Opcao: ");
	scanf("%d",&opcao);
	return opcao;
}
main(){
	int opcao,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,cargo;
	float salariofinal;
	char nome[100];
	char cpf[12];
	char data[20];
	for(;;){
		opcao = menu ();
		switch(opcao){
			case 1:
				printf("\n \n ** Menu de Cadastro **\n\n");
				printf("Digite o nome: ");
					fflush(stdin);
					gets(nome);
					if (strlen(nome)>0){
					strupr(nome);
					}
					else { 
					system("Color 4");
					printf ("Nome invalido.Por favor, digite um nome.\n");
					break;
					}
				printf("Digite o CPF: ");
					fflush(stdin);
					gets(cpf);
				
					//conta cpf
					d1= cpf[0]- '0';
					d2= cpf[1]- '0';
					d3= cpf[2]- '0';
					d4= cpf[3]- '0';
					d5= cpf[4]- '0';
					d6= cpf[5]- '0';
					d7= cpf[6]- '0';
					d8= cpf[7]- '0';
					d9= cpf[8]- '0';
						
					d10 = ((d1*1)+(d2*2)+(d3*3)+(d4*4)+(d5*5)+(d6*6)+(d7*7)+(d8*8)+(d9*9))%11;
					if(d10==10) d10=0;
						
					d11 = ((d1*0)+(d2*1)+(d3*2)+(d4*3)+(d5*4)+(d6*5)+(d7*6)+(d8*7)+(d9*8)+(d10*9))%11;
					
					if (strlen(cpf)>0){
					strupr(cpf);
					}
					else { 
					system("Color 4");
					printf ("CPF invalido.Por favor, digite um CPF valido.\n");
					break;
					}
					
					//digitar id e data
					printf("Digite seu Cargo ID: ");
					scanf ("%d", &cargo);
					if((cargo<100)||(cargo>103)){
						system("Color 4");
						printf("CARGO INEXISTENTE\n");
						break;
					}else{
					printf("Digite a data de admissao dd/mm/aaaa: ");
					fflush(stdin);
					gets(data);
					if((d10==cpf[9]-'0')&&(d11==cpf[10]-'0')){
						system("Color 2");
						printf("\nCPF VALIDO\n");
					}else{
						system("Color 4");
						printf("CPF INVALIDO\n");
					}
					}
				break;
			case 2:
				printf("\n\n ** Menu de Consulta **\n\n");
				if((d10==cpf[9]-'0')&&(d11==cpf[10]-'0')){//so mostra se for valido as inf
						printf("CPF: %s\n",cpf);
						printf("CPF VALIDO\n");
						printf("NOME: %s\n",nome);
						printf("ID: %d\n",cargo);
						if (cargo==100){
							printf("CARGO: Estoquista\n");
						}
						else if (cargo==101){
						printf("CARGO: Administrativo\n");
						}
						else if (cargo==102){
						printf("CARGO: Vendedor\n");
						}
						else if (cargo==103){
						printf("CARGO: Gerente Filial\n");
						}
						printf("DATA DE ADMISSAO: %s\n",data);
					}else{//nao mostra as inf do case 1
						printf("%c\n",cpf);
						printf("CPF INVALIDO\n");
					}
			
				break;
			case 3:
				printf("\n\n ** Menu de Calculo Salario **\n\n");
				if(cargo==100){
					salariofinal = 2500 - ((2500*0.09)-21.18);
					printf("O salario final e de R$ %.2f\n",salariofinal);
				}else if(cargo==101){
					salariofinal = 3000 - ((3000*0.12)-101.18);
					printf("O salario final e de R$ %.2f\n",salariofinal);
				}else if(cargo==102){
					salariofinal = 4500 - ((4500*0.14)-181.18);
					printf("O salario final e de R$ %.2f\n",salariofinal);
				}else if(cargo==103){
					salariofinal = 5000 - ((5000*0.14)-181.18);
					printf("O salario final e de R$ %.2f\n",salariofinal);
				}else{
					system("Color 4");
					printf("Cargo inexistente\n");
				}
				break;
			case 4:
				printf("\n\n ** Fim do Programa **\n\n");
				return(0);
				break;
			default:
				printf("\n\n ** Opcao invalida **\n\n");
				break;
		}		
		system("pause");
	}
}