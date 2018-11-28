//									 Universidad de El Salvador 
//							    Facultad Multidisciplinaria Oriental
//											Ing: LIGIA ASTRID
//										     Programacion I
//										CESIA REBECA REYES ESCOBAR
//	El presente programa realiza la serie de Fibonacci y serie de taylor, guarda resultados en un documento y muestra resultados almacenados en consola. 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>//libreria cargada para realizar la serie de taylor 
#include <fstream>//libreria utilizada para la creacion de archivo asi como para guardar y cargar informacion de los mismos


using namespace std;
int c[9]={0,0,0,0,0,0,0,0,0};
char denuevo=' ';

double factorial(int n);
double taylor(int n, int x);


void lectura();//funcion para ejecutar archivos 
void lectura2();//funcion para ejecutar archivos

int main(){
	ofstream carp;
	ofstream archivo2;
	ofstream carp2; 
	
	
	carp.open("Ultimo resultado fibonacci.txt",ios::app);//abrimos y almacenamos los datos en el archivo en modo añadir
	carp2.open("Ultimo resultado de la serie de taylor.txt",ios::app);//abrimos y almacenamos los datos en el archivo en modo añadir
	
do
{// Este es el menu que nos permite navegar en todo nuesto documento 
    int h, menu, x , n,i;
   
    cout<<"---------------------------------------------------------";
    cout<<"	\n|	Seleccione la operacion que desea realizar: 	|\n";
    cout<<"---------------------------------------------------------\n";
    cout<<"	---------------------------------";
    cout<<"\n	|	1)Serie Fibonacci 	|\n"; 
	cout<<"	---------------------------------";
	cout<<"\n	|	2)Serie de Taylor	| \n";
	cout<<"	---------------------------------";
	cout<<"\n	|	3)Ver Resultados	|  \n";
	cout<<"	---------------------------------";
	cout<<"\n	|	4)Salir			| \n";
	cout<<"	---------------------------------\n";
	cout<<"		";cin>>menu;//seleccionamos la variable en el menu para acceder a ella
	
    switch(menu)//hacemos uso de switch ya que nos facilida a la hora de trabajar con varias funciones en este caso el menú
    {
         case 1: // este caso es el encargado de ejecutar la serie de Fibonacci              
                int fibonacci[30]; //declaramos la variable fibonacci de manera entera con un rango de 30
				int x, a, b;  //declaracion de cariables 
					fibonacci[0]=0; 
					fibonacci[1]=1;
				cout<<"	---------------------------------";
				cout<<"\n	|	Serie de Fibonacci	| \n";
				cout<<"	---------------------------------";
				cout<<"--------------------------------";
				cout<<"\n	|	Ingrese el rango de la serie Fibonacci que desea:	| \n";
				cout<<"	-----------------------------------------------------------------";
				cout<<"\n	|	Ingrese el primer valor	| \n";
				cout<<"	---------------------------------";
				cout<<"		"; cin>>a; //ingresamos el primer valor que deseamos conocer el rango de Fibonacci
				cout<<"	---------------------------------";
				cout<<"\n	|	Ingrese el segundo valor| \n";
				cout<<"	---------------------------------";
				cout<<"		"; cin>>b;	//Ingresamos el valor final del rango de Fibonacci
				
				carp<<"Proceso Fibonacci generado\n";
																
				cout<< fibonacci[0] << endl << fibonacci[1] << endl; 
					for(x = a; x <= b; x++){ //operamos la serie de Fibonacci para x = al valor asignado y x <= al valor final asignado para el rango
						fibonacci[x] = fibonacci[x - 1] + fibonacci[x - 2]; //hacemos la operacion correspondiente  
						cout<< fibonacci[x] << endl; //Imprimimos la serie
			
					carp<<fibonacci[x]<<endl; //Guardamos en la carperta cada uno de los procesos generados 	
								
					}
					
				system("pause");                                                 
                 
                 break;
           	case 2:// Caso para la serie de taylor 
              	int n, e;
				cout<<"	---------------------------------";
				cout<<"\n	|	Serie de Taylor		| \n";
				cout<<"	-----------------------------------------";
				cout<<"\n	|	Integrese el valor de n:	|\n"; 
				cout<<"	-----------------------------------------";
				cout<<"\n	";cin>>n;// se solicita el acceso del primer digito 
				cout<<"	-----------------------------------------";
				cout<<"\n	|	Ingrese el valor de x:		|\n";
				cout<<"	-----------------------------------------"; 
				cout<<"\n	"; cin>>e;// se solicita el ingreso del segundo dato
			
					carp2<<"Proceso Taylor generado  \n "; //linea que marca el inicio de cada proceso para su almacenamiento
					printf("El valor de Taylor para n = %d, x = %d, es = %f \n",n,e,taylor(n, e));//proceso de imprecion en consola del proceso
							
				carp2<<"El valor de Taylor para n = "<<n<<", x = "<<e<<", es = "<<taylor(n, e)<<endl;//linea que almacena cada uno de los datos del proceso de taylor en el archivo		
					
	
					system("pause");
              break;
           	case 3:
              	cout<<"////////////-----HISTORIAL DE PROCESOS PARA LA SERIE DE FIBONACCI-----////////////\n";
                lectura();//funcion que es llamanda la cual posee lectura de datos desde el archivo de FIBONACCI para cargarlos en consola 
                cout<<"////////////-----HISTORIAL DE PROCESOS PARA LA SERIE DE TAYLOR-----////////////\n";
                lectura2();//funbcion que es llamada la cual posee lectura de datos desde el archivo de TAYLOR para cargarlos en consola
              
              break;
            case 4://Caso que hace el proceso de salir del programa
               
               	exit(1);
               	
              break;    
         } 
         cout<<"	---------------------------------";
         cout<<"\n	| Volver al menu? (s o n)	| \n";
         cout<<"	---------------------------------\n\n";
         cout<<"	"; cin>>denuevo;//aca controlamos las funciones del menu
         if (denuevo>=97) denuevo-=32;
         if ((denuevo!='s')&&(denuevo!='n'))
         for (h=0;h<=8;h++) c[h]=0;         
}
while (denuevo=='S');             
getchar();

}

void lectura(){//funcion declarada para lectura del archivo de FIBONACCI
    	ifstream doc1;//variable
		string proc1;//variable
             
        doc1.open("Ultimo resultado fibonacci.txt",ios::in);// aqui abrimos el archivo de modo lectura
        while(!doc1.eof()){//Funcion utilizada para decir que mientras existan datos en el archivo no dejara de cargarlos
            getline(doc1,proc1);
            cout<<"Ultimo resutado guardado en el proceso de Fibonacci:  "<<proc1<<endl; //texto que se muestra e imprime para cada dato guardado
			  }
	  
	doc1.close();//cerramos el archivo 1
}

void lectura2(){//funcion declarada para lectura del archivo de TAYLOR
	ifstream doc2;//variable
	string proc2;//variable
		
	 doc2.open("Ultimo resultado de la serie de taylor.txt",ios::in);// aqui abrimos el archivo de modo lectura
        while(!doc2.eof()){//Funcion utilizada para decir que mientras existan datos en el archivo no dejara de cargarlos
            getline(doc2,proc2);
            cout<<"Ultimo resutado guardado en el proceso de Taylor:  "<<proc2<<endl; //texto que se muestra e imprime para cada dato guardado
          }
           doc2.close();//cerramos el archivo 2
}

//este proceso es utilizado para ejecutar la serie de taylor y ser llamado en el caso 2
double taylor(int n, int e){
	double t, s=0;	
		for(int i=0; i<n; i++){
			t=pow(e, i) / factorial(i);
			s += t;
		}	
	return s;
}

double factorial(int n){
	double fac =1;
	for(int i=2; i<=n;i++){
		fac+=i;
	}
	return fac;
}
