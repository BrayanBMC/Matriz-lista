#include<iostream>
#include<fstream>
#define tam 10
using namespace std;
	
	int Numf, NumC, num[tam][tam], sumaF, sumaC, sumaDI=0, col[100];

int menu(){
	int opc;
	system("cls");
	cout<<"1.Registrar Datos\n2.Consultar Matriz"<<endl;
	cout<<"3.Guardar Archivo \n4.Consultar Archivo\n5.Salir"<<endl;
	cout<<"Digite opcion: "; cin>>opc;
	cout<<endl;
	return opc;
}
	
void llenarMatriz(){
	
	cout<<"Digite el numero de filas: "; cin>>Numf;
	cout<<"Digite el numero de columnas: "; cin>>NumC;	
	
	for(int i=0;i<Numf;i++){
		for(int j=0;j<NumC;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: "; cin>>num[i][j];
		}
	} 
}

void mostrarMatriz(){
	int c=0;
	cout<<"Matriz"<<endl;
	
	for(int i=0;i<Numf;i++){
		sumaF=0;
		sumaC=0;	
		for(int j=0;j<NumC;j++){
			cout<<num[i][j]<<"  ";
			sumaF+=num[i][j];	
			sumaC+=num[j][c];
			if((j+i)==NumC-1){
				sumaDI+=num[i][j];
			}
		}
		cout<<"= "<<sumaF<<endl; 
		col[c]=sumaC;
		c++;	
	}
	for(int i=0; i<Numf;i++){
		cout<<"= ";
	}	
	cout<<endl;
	
	for(int i=0;i<c;i++){
		if(col[i]<10){
			cout<<col[i]<<"  ";	
		}else{
			cout<<col[i]<<" ";	
		}
	}

	cout<<"\nSuma Diagonal Inversa: "<<sumaDI<<endl;
}

void guardarArchivo(){
	ofstream archM;
	archM.open("matriz.txt",ios::trunc);
	if(archM.fail()){
		cout<<"Error"<<endl;
	}else{
		for(int i=0;i<Numf;i++){
			for(int j=0;j<NumC;j++){
				archM<<num[i][j]<<"  ";
			}
			archM<<endl;
		} 	
	}
	
	cout<<"Datos registrados"<<endl;
	
	archM.close();
}

void consultarArchivo(){
	ifstream archL;
	archL.open("matriz.txt");
	if(archL.fail()){
		cout<<"Error"<<endl;
	}else{
		for(int i=0;i<Numf;i++){
			for(int j=0;j<NumC;j++){
				archL>>num[i][j];
				cout<<num[i][j]<<"  ";
			}
			cout<<endl;
		} 		
	}
	archL.close();
}


		                                                                                                          
int main(){
	char resp;
	do{
		int op=menu();
	switch(op){
		case 1: llenarMatriz(); break;
		case 2: mostrarMatriz(); break;
		case 3:	guardarArchivo(); break;
		case 4:	consultarArchivo(); break;
		case 5: cout<<"Salir"<<endl; exit(0);
		default: cout<<"Error: Opcion no existe"<<endl;
		break;
	}		
	cout<<"Desea regresar al menu? s/n "; cin>>resp;
	cout<<endl;
	}while(resp=='s'||resp=='S');

}


