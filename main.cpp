# include <stdio.h>
# include <conio.h>
# include "JuegoBN.cpp"


main(){
	Utilerias obj_ut;
	JuegoBN obj_jbn;
	int ren, col;
	obj_jbn.carga_matriz();
	while(obj_jbn.aciertos < 9 && obj_jbn.errores < 10){
		obj_jbn.muestra_tablero();
		ren = obj_ut.pide_entero("Indica el renglon de tiro: \n", 0, 8);
		col = obj_ut.pide_entero("Indica la columna de tiro: \n", 0, 8);
    	obj_jbn.tiro(ren,col);
	}
	
	if (obj_jbn.aciertos==9){
		obj_ut.error("Felicidades, ganaste \n");
		obj_jbn.muestra_tablero();
	}
	else{
		obj_ut.error("Perdiste , suerte para la otra \n");
		obj_jbn.muestra_tablero();
	}
}
