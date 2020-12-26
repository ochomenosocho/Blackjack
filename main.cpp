#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Juego para jugar al 21 con la consola.
	Por: ochomenosocho			||||||||||	Suscribete	||||||||||
*/

char type_cards	[13]	= {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
char hearts		[13]	= {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
char diamonds	[13]	= {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
char pikes		[13]	= {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'}; //espadas
char clover		[13]	= {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
int number_of_elements	= sizeof(type_cards);

char player_cards[5] 	= {};
char computer_cards[5]	= {};

int player_card_counter		= 0;
int computer_card_counter	= 0;

int player_score	= 0;
int computer_score	= 0;

bool empty_hearts	= false;
bool empty_diamonds	= false;
bool empty_pikes	= false;
bool empty_clover	= false;

int carta_actual = 0;

char continuar = 'N';
char player[25];

int random(int max_value){
	unsigned long j;
    srand((unsigned)time(NULL));
    int a;
    
    for( j = 0; j < 100500; ++j ){
        int n;
        while( ( n = rand() ) > RAND_MAX - (RAND_MAX - 5) % max_value );
        a = n % max_value + 1;
    }

    return a;
}

char carta(){
	int type_card = random(4); 		// type of card in the range 0 to 4
	int card = random(12);         // card in the range 0 to 12
	char carta_tomada = '0';
	int counter_of_zero = 0;
	
	/*
	for(int i = 0; i < number_of_elements; i++){
		if(hearts[i] == '0'){
			counter_of_zero++;
		}
	}
	if(counter_of_zero == 13){
		carta_tomada = '0';	
		empty_hearts = true;
	}
	counter_of_zero = 0;
	for(int i = 0; i < number_of_elements; i++){
		if(diamonds[i] == '0'){
			counter_of_zero++;
		}
	}
	if(counter_of_zero == 13){
		carta_tomada = '0';	
		empty_diamonds = true;
	} 
	counter_of_zero = 0;
	for(int i = 0; i < number_of_elements; i++){
		if(pikes[i] == '0'){
			counter_of_zero++;
		}
	}
	if(counter_of_zero == 13){
		carta_tomada = '0';	
		empty_pikes = true;
	}
	counter_of_zero = 0;
	for(int i = 0; i < number_of_elements; i++){
		if(clover[i] == '0'){
			counter_of_zero++;
		}
	}
	if(counter_of_zero == 13){
		carta_tomada = '0';	
		empty_clover = true;
	} 
	counter_of_zero = 0;
	*/
	switch(type_card){
		case 0:
			while(carta_tomada == '0'){
				card = random(12);
				carta_tomada = hearts[card];
			}
			carta_tomada = hearts[card];
			hearts[card] = '0';
			return carta_tomada;
			break;
		case 1:
			while(carta_tomada == '0'){
				card = random(12);
				carta_tomada = diamonds[card];
			}
			carta_tomada = diamonds[card];
			diamonds[card] = '0';
			return carta_tomada;
			break;
		case 2:
			while(carta_tomada == '0'){
				card = random(12);
				carta_tomada = pikes[card];
			}
			carta_tomada = pikes[card];
			pikes[card] = '0';
			return carta_tomada;
			break;
		case 3:
			while(carta_tomada == '0'){
				card = random(12);
				carta_tomada = clover[card];
			}
			carta_tomada = clover[card];
			clover[card] = '0';
			return carta_tomada;
			break;
	}
}

int real_value(char fake_value){
	
	int real_card_value = 0;
	int A = 1;
	bool condicion_A = true;
	
	if (fake_value == 'J' || fake_value == 'Q' || fake_value == 'K'){
		real_card_value = 10;
	} else if (fake_value == 'A'){
		do{
			std::cout<< "Seleccione usar la carta A como un 1 o como un 11: "	<<std::endl;
			std::cin>> A;
			if(A == 1){
				condicion_A = true;
			} else if(A == 11){
				condicion_A = true;
			} else {
				condicion_A = false;
			}
		} while(condicion_A = false);
		real_card_value = A;
	} else {
		real_card_value = fake_value - '0';	//convirtiendo char a int
	}
	
	return real_card_value;
}

void partida(){
	
}

int main(int argc, char** argv) {
	std::cout<< "Ingrese el nombre del jugador (25 caracteres maximo): "	<<std::endl;
	std::cin>> player;

	while(true){
	
		std::cout<< "Barajeando el mazo..."	<<std::endl;
		
		player_cards[player_card_counter] = carta();
		player_card_counter++;
		//std::cout<< "La primera carta es: " <<player_cards[player_card_counter]	<<std::endl;
		player_cards[player_card_counter] = carta();
		player_card_counter++;
		
		std::cout<< "Repartiendo cartas..."	<<std::endl;
		
		computer_cards[computer_card_counter] = carta();
		computer_card_counter++;
		computer_cards[computer_card_counter] = carta();
		computer_card_counter++;
		
		std::cout<< "Las cartas de " <<player <<" son: "	<<std::endl << " , ";
		for(int j = 0; j < player_card_counter; j++){
			std::cout<< player_cards[j] << " , ";
		}
		std::cout<<std::endl;
		
		std::cout<< "Las cartas del CPU son: "	<<std::endl << " , ";
		for(int j = 0; j < computer_card_counter; j++){
			if (j==0){
				std::cout<< "? , ";
			} else {
				std::cout<< computer_cards[j] << " , ";
			}
		}
		std::cout<< "El numero secreto del ordenador es: " <<computer_cards[0] <<std::endl;
		std::cout<<std::endl;
		
		std::cout<< "Desea otra carta? (Y/N): ";
		std::cin>> continuar;
		std::cout<<std::endl;
		if (continuar == 'N' || continuar == 'n'){
			for(int i = 0; i < player_card_counter; i++){
				player_score += real_value(player_cards[i]);
				std::cout<< "player score " <<i << ": " <<player_score <<std::endl;
			}
			for(int i = 0; i < computer_card_counter; i++){
				computer_score += real_value(computer_cards[i]);
			}
			
			if (player_score < computer_score){
				std::cout<< "Ha ganado la computadora con: " <<computer_score << " puntos." <<std::endl;
			} else if (player_score == computer_score){
				std::cout<< "Ha sido un empate" <<std::endl;
			} else {
				std::cout<< "Ha ganado " <<player << " con: " <<player_score << " puntos."<<std::endl;
			}
		} else if (continuar == 'Y' || continuar == 'y' || continuar == 'S' || continuar == 's') {
			partida();
		} else {
			std::cout<< "Comando no valido ... Reiniciando" <<std::endl;
		}
		
		player_cards[5] 	= {};
		computer_cards[5]	= {};
		player_card_counter		= 0;
		computer_card_counter	= 0;
		player_score	= 0;
		computer_score	= 0;
		carta_actual = 0;
		
		std::cout<<std::endl;
		system("pause");
		std::cout<<std::endl;
	}
	
	return 0;
}

