#include<iostream>
#include<ctime>
#include<conio.h>

using namespace std;

int random();
void tirardados(int v[5]);
int puntuacion(const int v[5]);
int maximo(const int v[5]);
void ordenar(int v[5]);
int x1(const int v[5], int valor);
bool full(const int v[5]);
bool poker(const int v[5]);
bool escalera(const int v[5]);
bool generala(const int v[5]);

int main(){
	//CREAMOS LAS VARIABLES
	int jugador;
	int pc;
	int dadosjugador[5];
	int dadosPC[5];
	int salida = -1;
	//NUMEROS ALEATORIOS
	srand(time(NULL));
	//WHILE PARA PODER SALIR DEL PROGRAMA
	while(salida <= 1){
		
	cout<<"[-----BIENVENIDO A LA GENERALA-----]"<<endl;

	cout<<endl;
	
	cout<<"[-----JUGADOR-----]"<<endl;
	getch();
	cout<<endl;
	
	cout << "Tirada del Jugador: ";
	
	tirardados(dadosjugador);
	jugador = puntuacion(dadosjugador);
	
	cout << "La puntuacion total es:: "<< jugador << endl;
	
	cout<<endl;
	
	cout<<"[-----PC-----]"<<endl;
	getch();
	cout<<endl;
	
	cout << "Tirada del PC: ";
	
	tirardados(dadosPC);
	pc = puntuacion(dadosPC);
	
	cout << "La puntuacion total es: "<< pc << endl;
	
	cout<<endl;
	//MUESTRA SI EL GANADOR ES: JUGADOR O PC
	cout << "El ganador es: ";
	if (pc < jugador){
		cout << "[-Jugador-]";
		cout << endl;
	}else if (pc > jugador){
		cout << "[-PC-]";
		cout << endl;
	}else{
		cout << "[-Empate-]";
		cout << endl;
	}
	
	cout << endl;
	//PREGUNTA SI DESEA SALIR DEL JUEGO
	cout<<"Desea salir del juego?:"<<endl;
	cout<<"1=NO - 2=SI"<<endl;
	cout<<"respuesta:";
	cin>>salida;
	
	}
	return 0;
	
}
//NUMEROS RANDOM DEL 1 AL 6
int random()
{
	return rand() % 6 + 1;
}
//TIRA LOS DADOS PARA QUE GENERE LOS NUMEROS
void tirardados(int v[5])
{
	for (int i = 0; i < 5; i++){
		v[i] = random();
	}	
	
	ordenar(v);
	
	for (int i = 0; i < 5; i++){
		cout << v[i] << " ";
}	}

//INGRESA LOS PUNTOS GANADOS 
int puntuacion(const int v[5])
{	
	int puntos[6];
	
	puntos[0] = x1(v, 1);
	puntos[1] = x1(v, 2);
	puntos[2] = x1(v, 3);
	puntos[3] = x1(v, 4);
	puntos[4] = x1(v, 5);
	puntos[5] = x1(v, 6);
	
	cout << endl;
	
	cout << "Todo al 1: " << puntos[0] << endl;
	cout << "Todo al 2: " << puntos[1] << endl;
	cout << "Todo al 3: " << puntos[2] << endl;
	cout << "Todo al 4: " << puntos[3] << endl;
	cout << "Todo al 5: " << puntos[4] << endl;
	cout << "Todo al 6: " << puntos[5] << endl;
	
	if (generala(v)){
		cout << "Generala: 60" << endl;
		return 60;
	}else if (escalera(v)){
		cout << "Escalera: 50" << endl;
		return 50;
	}else if (poker(v)){
		cout << "Poker: 40" << endl;
		return 40;
	}else if (full(v)){
		cout << "Full: 30" << endl;
		return 30;
	}else{
		return maximo(puntos);
	}
	
}
//VARIABLE DE MAXIMO DE PUNTAJE
int maximo(const int v[6]){
	int max;
	
	for (int i = 0; i < 6; i++){
		if (i == 0 || v[i] > max){
			max = v[i];
		}	
	}
	return max;
}

int x1(const int v[5], int valor){
	int suma = 0;
	
	for (int i = 0; i < 5; i++){
		if (v[i] == valor){
			suma += v[i];
		}	
	}
	return suma;
}
// ORDENA LOS VALORES ALEATORIOS
void ordenar(int v[5]){
	int valor;
	int j;
	
	for (int i = 1; i < 6; i++) {
		valor = v[i];
		j = i;
		while (j > 0 && valor < v[j-1]){
			v[j] = v[j-1];
			j--;
		}
		v[j] = valor;
	}
}

bool full(const int v[5]){
	int n1, n2 = 0, count1 = 1, count2 = 0;
	
	n1 = v[0];
	for (int i = 1; i < 5; i++){
		if (n1 == v[i]){
			count1++;
		}else if (n2 == 0){
			n2 = v[i];
			count2++;
		}else if (n2 == v[i]){
			count2++;
		}	
	}
	
	return ((count1 == 3 && count2 == 2) || (count2 == 3 && count1 == 2));
}

bool poker(const int v[5]){
	
	int n1, n2 = 0, count1 = 1, count2 = 0;
	
	n1 = v[0];
	
	for (int i = 1; i < 5; i++){
		if (n1 == v[i]){
			count1++;
		}else if (n2 == 0){
			n2 = v[i];
			count2++;
		}else if (n2 == v[i]){
			count2++;
		}
	}

 return (count1 == 4 || count2 == 4);
}

bool escalera(const int v[5]){
	
	if (v[0] == 1 || v[0] == 2){
		for (int i = 1; i < 5; i++){
			if (v[i] != v[i - 1] + 1){
				return false;
			}	
		}
	}else{
		return false;
	}
	return true;
}
	
bool generala(const int v[5]){
	for (int i = 1; i < 5; i++){
		if (v[i] != v[i - 1]){
			return false;
		}	
	}
	
	return true;
}
