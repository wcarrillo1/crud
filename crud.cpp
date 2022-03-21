#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.dat";

struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	char direccion[50];
	int telefono;
};
 void ingresar_estudiante();
 void abrir_estudiante();
 void modificar_estudiante();
 void eliminar_estudiante();
int main (){
	abrir_estudiante();
    ingresar_estudiante();
	modificar_estudiante();
	eliminar_estudiante();
	return 0;	
}



void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"TELEFONO"<<" "<<"DIRECCION"<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre<<" "<<estudiante.apellido<<" "<<estudiante.telefono<<" "<<estudiante.direccion<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
	
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Estudiante estudiante;
		 string nombre,apellido,direccion;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_estudiante();
}
void modificar_estudiante(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido,direccion;	
    	Estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese la Direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str());
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);
	abrir_estudiante();
		system("PAUSE");
}

void eliminar_estudiante(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	FILE* temporal = fopen(nombe_archivo, "w+b");
	int codigo;
	Estudiante estudiante;
	char elimina = 0;
 
	if (archivo == NULL || temporal == NULL) {
		elimina = 0;
	} else {
		cout << "Ingrese el codigo que desea eliminar: ";
    	cin >> codigo;
		/* Se copia en el archivo temporal los registros válidos */
		fread(&estudiante, sizeof(Estudiante), 1, archivo);
	
		while (!feof(archivo)) {
			if (estudiante.codigo != codigo) {
				fwrite(&estudiante, sizeof(Estudiante), 1, temporal);
			}
			fread(&estudiante, sizeof(Estudiante), 1, archivo);
		}
		/* Se cierran los archivos antes de borrar y renombrar */
		fclose(archivo);
		fclose(temporal);
 
		remove("archivo.dat");
		rename("temporal.dat", "archivo.dat");
 
		elimina = 1;
	}
 
		
	
		
	fclose(archivo);
	abrir_estudiante();
		system("PAUSE");
}

