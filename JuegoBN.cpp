# include <stdio.h>
# include <conio.h>
# include <fstream>
# include <ctype.h>
# include <stdlib.h>
# include <String.h>
# include "utilerias.cpp"
#include <cstdlib>
#include <iostream>


using namespace std;

	class JuegoBN{
		public:
			char matriz[8][8], desc[20], file[100], cad[20], r[2];
			int fila, col;
			int aciertos = 0;
			int errores = 0;
			bool archivo;
			Utilerias obj_ut;

		public:
			JuegoBN(){ // creando el constructor, tiene que tener el mismo nombre que la clase
				printf("===================================================================\n");
	        	printf("Para iniciar indica el nombre del archivo que deseas cargar\n");
	        	printf("si deseas un juego nuevo oprime ENTER\n");
	        	printf("===================================================================\n");
				
				obj_ut.pide_cadena("Ingresa el nombre de el archivo:",file, 0,10);
				if (strlen(file)==0){
					printf("Partida nueva\n");
					strcpy(file,"incial.csv");
			}
				else{
					strcat(file, ".csv");
			}
		}
			
			void carga_matriz() {
			archivo = false;
			while (archivo == false){ // si el archivo no existe, entra el loop hasta que nos de uno existente
				ifstream arch; //input file stream 
				arch.open(file,ios::in);
				if (arch.is_open()){
					fila = 0;
					col = 0;
					while (!arch.eof()){
						arch >> cad;
						if (!arch.eof()){
							for (int i=0; i<strlen(cad); i=i+2){
								matriz[fila][col] = cad[i];
								if (matriz[fila][col] == 'A') aciertos++;
								if (matriz[fila][col] == 'X') errores++;
								col ++;
							}
							col = 0;
							fila ++;
						}
						//manejar los puntos
						archivo = true;
						}
						
					}
						else{
						obj_ut.error("Archivo inexistente");
						obj_ut.pide_cadena("Ingresa el nombre de el archivo de nuevo:",file, 0,10);
						if (strlen(file)==0){
							strcpy(file,"incial.csv");
					}
							else{
								strcat(file, ".csv");
					}	
				}
			}
		}
		
		//guardar los aciertos y fallos de los archivos, se intentó desde el carga matriz, pero daba error, por eso se creo nuevo método 
			void score(){
				if (matriz[fila][col] == 'A'){
				aciertos+=1;
			}
				if (matriz[fila][col] == 'X'){
				errores+=1;
		}
	}
			
			
			void muestra_tablero() {
				printf("   0 1 2 3 4 5 6 7 \n");
				printf("  ----------------- \n");
		   		for (int fila = 0; fila < 8; fila++) {
		      		printf("%d |", fila);
		      		
		      		for (int col = 0; col < 8; col++) {
		        		if (matriz[fila][col] == 'V' || matriz[fila][col] == 'B') {
		          			printf(" |"); // Ocultar barcos sin revelar
		        } 
						else {
		          			printf("%c|", matriz[fila][col]);
		       	}
		      }
					if (fila == 0){
						printf("       Aciertos: %d", aciertos);
				}
					if (fila == 1){
						printf("       Errores: %d", errores);
				}
					printf("\n  -----------------\n");
		}
	}			
						
		    void descargar_matriz(){
				obj_ut.pide_cadena("Nombre del archivo nuevo: ", desc,1,10);
				strcat(desc,".csv");
				ofstream arch;
				arch.open(desc,ios::out);
				for (int fila =0;fila<8;fila++){
					for(int col=0;col<8;col++){
						if (col == 7){
							arch << matriz[fila][col]<<"\n";
						}
						else{
							arch << matriz[fila][col]<<",";
						}
					}
				}
				arch.close();
				
			/*char respuesta;
            cout << "¿Deseas seguir jugando? (s/n): ";
            cin >> respuesta;
            if (respuesta == 'n' || respuesta == 'N') {
                exit(0); // Sale del programa si la respuesta es no
            }
        } 
        */
			}
	
			void tiro(int fila, int col){
				if (fila ==8 || col == 8){
					descargar_matriz();
				}	
				else {
					if (matriz[fila][col]=='A' || matriz[fila][col]=='X'){
						obj_ut.error("Tiro en la misma casilla");
					}
					else{
						if (matriz[fila][col]=='V'){
							obj_ut.error("Tiro incorrecto");
							errores++;
							matriz[fila][col] = 'X';
						}
						else{
							obj_ut.error("Casilla con barco !");
							aciertos ++;
							matriz[fila][col]='A';
						}
					}
				}
		}
};
