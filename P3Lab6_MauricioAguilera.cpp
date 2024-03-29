#include "admLiga.cpp"
#include <ctime>
#include <cstdlib>

admLiga al("./ligas.txt");

void Adminliga();
void Adminequipo(int);
void Adminjugador(int, int);

int main(){
	char op='0';
	while (op!='8'){
		system("cls");
		cout<<"...:::MENU PRINCIPAL:::..."<<endl;
		cout<<"1. Administrar ligas"<<endl<<
		"2. Administar equipos"<<endl<<
		"3. Administrar Jugadores"<<endl<<
		"4. Jugar partido"<<endl<<
		"5. Cargar Archivo"<<endl<<
		"6. Escribir Archivo"<<endl<<
		"7. Mostrar tabla"<<endl<<
		"8. Salir"<<endl<<
		"Ingrese una opcion: ";
		cin>>op;
		switch (op){
			case '1':{
				Adminliga();
				break;
			}
			case '2':{
				system("cls");
				if (al.getN()>0){
					for (int i=0; i<al.getN(); i++){
						cout<<i<<". "<<al.getLigas().at(i)->getNombre()<<endl;
					}
					int pos;
					cout<<"Ingrese una posicion: ";
					cin>>pos;
					Adminequipo(pos);
				}else{
					cout<<"No se puede crear equipos sin ligas existentes"<<endl;
					system("pause");
				}
				break;
			}
			case '3':{
				system("cls");
				if (al.getN()>0){
					for (int i=0; i<al.getN(); i++){
						cout<<i<<". "<<al.getLigas().at(i)->getNombre()<<endl;
					}
					int pos;
					cout<<"Ingrese una posicion: ";
					cin>>pos;
					if (al.getLigas().at(pos)->getEquipos().size()>0){
						system("cls");
						for (int i=0; i<al.getLigas().at(pos)->getEquipos().size(); i++){
							cout<<i<<". "<<al.getLigas().at(pos)->getEquipos().at(i)->getNombre()<<endl;
						}
						int pos2;
						cout<<"Ingrese una posicion: ";
						cin>>pos2;
						Adminjugador(pos, pos2);
					}else{
						cout<<"No se puede crear jugadores sin equipos existentes en esta liga"<<endl;
						system("pause");
					}
				}else{
					cout<<"No se puede crear equipos sin ligas existentes"<<endl;
					system("pause");
				}
				break;
			}
			case '4':{
				system("cls");
				int pos, pos2;
				if (al.getN()>0){
					for (int i=0; i<al.getN(); i++){
						cout<<i<<". "<<al.getLigas().at(i)->getNombre()<<endl;
					}
					cout<<"Ingrese una posicion: ";
					cin>>pos;
					if (al.getLigas().at(pos)->getEquipos().size()>0){
						system("cls");
						for (int i=0; i<al.getLigas().at(pos)->getEquipos().size(); i++){
							cout<<i<<". "<<al.getLigas().at(pos)->getEquipos().at(i)->getNombre()<<endl;
						}
						cout<<"Seleccione el primer equipo: ";
						cin>>pos2;
					}else{
						cout<<"No se puede hacer una partida sin equipos"<<endl;
						system("pause");
					}
				}else{
					cout<<"No se pueden elegir equipos sin ligas existentes"<<endl;
					system("pause");
				}
				system("cls");
				if (al.getN()>0){
					for (int i=0; i<al.getN(); i++){
						cout<<i<<". "<<al.getLigas().at(i)->getNombre()<<endl;
					}
					int pos3;
					cout<<"Ingrese una posicion: ";
					cin>>pos3;
					if (al.getLigas().at(pos3)->getEquipos().size()>0){
						system("cls");
						for (int i=0; i<al.getLigas().at(pos3)->getEquipos().size(); i++){
							cout<<i<<". "<<al.getLigas().at(pos3)->getEquipos().at(i)->getNombre()<<endl;
						}
						int pos4;
						cout<<"Ingrese una posicion: ";
						cin>>pos4;
						al.getLigas().at(pos)->getEquipos().at(pos2)->setPartido(new Partido());
						al.getLigas().at(pos3)->getEquipos().at(pos4)->setPartido(new Partido());
						al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->setPj(al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->getPj()+1);
						al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->setPj(al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->getPj()+1);
						srand(time(0));
						int temp=(rand() % 10);
						srand(time(0));
						int temp2=(rand() % 10);
						srand(time(0));
						if (temp>temp2){
							al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->setPg(al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->getPg()+1);
							al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->setPt(al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->getPt()+3);
							al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->setPp(al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->getPp()+1);
						}else{
							if (temp<temp2){
								al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->setPg(al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->getPg()+1);
								al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->setPt(al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->getPt()+3);
								al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->setPp(al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->getPp()+1);
							}else{
								al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->setPe(al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->getPe()+1);
								al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->setPt(al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->getPt()+1);
								al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->setPe(al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->getPe()+1);
								al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->setPt(al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->getPt()+1);
							}
						}
						al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->setGf(al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->getGf()+temp);
						al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->setGf(al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->getGf()+temp2);
						
						al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->setGc(al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->getGc()+temp);
						al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->setGc(al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->getGc()+temp2);
						
						al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->setDg(al.getLigas().at(pos)->getEquipos().at(pos2)->getPartido()->getDg()+(temp-temp2));
						al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->setDg(al.getLigas().at(pos3)->getEquipos().at(pos4)->getPartido()->getDg()+(temp2-temp));
						system("cls");
						cout<<"El partido ha finalizado, puede ver los resultados en la tabla"<<endl;
						system("pause");
					}else{
						cout<<"No se puede hacer una partida sin equipos"<<endl;
						system("pause");
					}
				}else{
					cout<<"No se pueden elegir equipos sin ligas existentes"<<endl;
					system("pause");
				}
				
				break;
			}
			case '5':{
				al.leer();
				system("cls");
				cout<<"Archivo exitosamente cargado"<<endl;
				system("pause");
				break;
			}
			case '6':{
				al.escribir();
				system("cls");
				cout<<"Archivo exitosamente actualizado"<<endl;
				system("pause");
				break;
			}
			case '7':{
				system("cls");
				if (al.getN()>0){
					cout<<"Seleccione una liga"<<endl;
					for (int i=0; i<al.getN(); i++){
							cout<<i<<". "<<al.getLigas().at(i)->getNombre()<<endl;
					}
					int pos;
					cout<<"Ingrese una posicion: ";
					cin>>pos;
					system("cls");
					for (int i=0; i<al.getLigas().at(pos)->getEquipos().size(); i++){
						al.getLigas().at(pos)->getEquipos().at(i)->print();
					}
					system("pause");
				}else{
					cout<<"No hay ligas presentes para crear la tabla"<<endl;
					
				}
				break;
			}
			case '8':{
				system("cls");
				system("pause");
				return 0;
				break;
			}
			default :{
				system("cls");
				cout<<"Esta opcion no es valida, intentelo de nuevo"<<endl;
				system("pause");
				break;
			}
		}
	}
	
}

void Adminliga(){
	char op='0';
	while (op!='3'){
		system("cls");
		cout<<"ADMINISTAR LIGAS"<<endl;
		cout<<"1. Agregar liga"<<endl<<
		"2. Eliminar liga"<<endl<<
		"3. Regresar"<<endl<<
		"Ingrese una opcion: ";
		cin>>op;
		switch (op){
			case '1':{
				system("cls");
				string nombre, pais;
				cout<<"Nombre: ";
				cin>>nombre;
				cout<<"Pais: ";
				cin>>pais;
				al.addLiga(new Liga(nombre, pais));
				cout<<"Liga agregada"<<endl;
				system("pause");
				break;
			}
			case '2':{
				system("cls");
				for (int i=0; i<al.getN(); i++){
					cout<<i<<". "<<al.getLigas().at(i)<<endl;
				}
				int pos;
				cout<<"Ingrese una posicion: ";
				cin>>pos;
				al.remLiga(pos);
				system("cls");
				cout<<"Liga eliminado"<<endl;
				system("pause");
				break;
			}
			case '3':{
				
				break;
			}
			default:{
				system("cls");
				cout<<"Esta opcion no es valida, intentelo de nuevo"<<endl;
				system("pause");
				break;
			}
		}
	}
	
}

void Adminequipo(int pos){
	char op='0';
	while (op!='3'){
		system("cls");
		cout<<"ADMINISTAR EQUIPOS"<<endl;
		cout<<"1. Agregar equipo"<<endl<<
		"2. Eliminar equipo"<<endl<<
		"3. Regresar"<<endl<<
		"Ingrese una opcion: ";
		cin>>op;
		switch (op){
			case '1':{
				system("cls");
				string nombre, fundacion;
				cout<<"Nombre: ";
				cin>>nombre;
				cout<<"Fundacion: ";
				cin>>fundacion;
				al.getLigas().at(pos)->setEquipo(new Equipo(nombre, fundacion));
				cout<<"Equipo agregada"<<endl;
				system("pause");
				break;
			}
			case '2':{
				system("cls");
				for (int i=0; i<al.getLigas().at(pos)->getEquipos().size(); i++){
					cout<<i<<". "<<al.getLigas().at(pos)->getEquipos().at(i)->getNombre()<<endl;
				}
				int pos2;
				cout<<"Ingrese una posicion: ";
				cin>>pos;
				al.getLigas().at(pos)->remEquipo(pos2);
				system("cls");
				cout<<"Equipo eliminado"<<endl;
				system("pause");
				break;
			}
			case '3':{
				
				break;
			}
			default:{
				system("cls");
				cout<<"Esta opcion no es valida, intentelo de nuevo"<<endl;
				system("pause");
				break;
			}
		}
	}
}

void Adminjugador(int pos, int pos2){
	char op='0';
	while (op!='3'){
		system("cls");
		cout<<"ADMINISTAR JUGADORES"<<endl;
		cout<<"1. Agregar jugador"<<endl<<
		"2. Eliminar jugador"<<endl<<
		"3. Regresar"<<endl<<
		"Ingrese una opcion: ";
		cin>>op;
		switch (op){
			case '1':{
				system("cls");
				string nombre, pais;
				int dorsal;
				cout<<"Nombre: ";
				cin>>nombre;
				cout<<"Dorsal: ";
				cin>>dorsal;
				cout<<"Pais: ";
				cin>>pais;
				al.getLigas().at(pos)->getEquipos().at(pos2)->setJugador(new Jugador(nombre, dorsal, pais));
				cout<<"Jugador agregada"<<endl;
				system("pause");
				break;
			}
			case '2':{
				system("cls");
				for (int i=0; i<al.getLigas().at(pos)->getEquipos().at(pos2)->getJugadores().size(); i++){
					cout<<i<<". ";
					al.getLigas().at(pos)->getEquipos().at(pos2)->getJugadores().at(i)->print();
				}
				int pos3;
				cout<<"Ingrese una posicion: ";
				cin>>pos;
				al.getLigas().at(pos)->getEquipos().at(pos2)->remJugador(pos3);
				system("cls");
				cout<<"Liga eliminado"<<endl;
				system("pause");
				break;
			}
			case '3':{
				
				break;
			}
			default:{
				system("cls");
				cout<<"Esta opcion no es valida, intentelo de nuevo"<<endl;
				system("pause");
				break;
			}
		}
	}
}

