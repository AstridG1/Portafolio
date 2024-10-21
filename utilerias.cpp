# include <stdio.h>
#include <conio.h>
#include <String.h>
#include <stdlib.h>
#include <ctype.h>

class Utilerias{
	public:
		void error(char * msg)
		{
			printf("%s\n", msg);
			printf("Error, oprima [ENTER] para continuar");
			getche();
		}
		
		int pide_entero(char* msg, int LI, int LS){
			char v[20];
			int valor;
			bool archivo;
			archivo = true;
			while (archivo == true){
				printf(msg); gets(v);
				for(int i=0; i<strlen(v); i++){
					if(!isdigit(v[i])){
						archivo = false;
						break;
					}
					
				}
				if(archivo){
					valor = atoi(v);
				}
				else{
					error("Error, el valor fuera de rango");
				}
				if (valor < LI || valor > LS){
					error("Valor fuera de rango, intenta otra");
				}
				else{
					return valor;
				}
			}		
		}
           
		void pide_cadena(char*msg, char*cad,int LI, int LS){
			while (true) {
				printf("%\s", msg);gets(cad);
				if (strlen(cad) < LI || strlen(cad) > LS){
					error("Error, cadena fuera de rango");
				}
				else{
					break;
				}
    		}
  		}
};
