#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/*
	Juego para jugar al 21 con la consola.
	Por: ochomenosocho			||||||||||	Suscribete	||||||||||
*/

const int total_numbers	= 13;
const int best_score 	= 21;

char type_cards	[13]	= {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
char save_cards	[13]	= {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
char hearts		[13]	= {};
char diamonds	[13]	= {};
char pikes		[13]	= {}; //espadas
char clover		[13]	= {};
int number_of_elements	= sizeof(type_cards);

char player_cards	[5] 	= {};
char computer_cards	[5]		= {};

int player_card_counter		= 0;
int computer_card_counter	= 0;

int player_score	= 0;
int computer_score	= 0;

char continuar = 'N';
char player	[25];

//para saber si la comptuadora tiene un AZ
bool computer_has_A = false;

//for random generator
char num_check		[13] 	= {};
char hearts_check	[13]	= {};
char diamonds_check	[13]	= {};
char pikes_check	[13]	= {};
char clover_check	[13]	= {};
char reset_values			= 'X';

int random(int low,int high){  /* generates a random number within given range*/
    return rand()%(high-low+1)+low;   
}

int random_without_repeating(int low,int high){
	bool checking = false;
	int number;
	for (int i = 0; i < total_numbers; i++){
		do{
			number = random(low, high);
			for(int j = 0; j < sizeof(save_cards); j++){
				if(number == num_check[j]){
					checking = false;
				}
				else {
					checking = true;
				}
			}
		} while(checking == false);
		num_check[i] = number;
	}
	return number;
}

int random_without_repeating_hearts(int low,int high){
	bool checking = false;
	int number;
	for (int i = 0; i < total_numbers; i++){
		do{
			number = random(low, high);
			for(int j = 0; j < sizeof(save_cards); j++){
				if(number == hearts_check[j]){
					checking = false;
				}
				else {
					checking = true;
				}
			}
		} while(checking == false);
		hearts_check[i] = number;
	}
	return number;
}

int random_without_repeating_diamonds(int low,int high){
	bool checking = false;
	int number;
	for (int i = 0; i < total_numbers; i++){
		do{
			number = random(low, high);
			for(int j = 0; j < sizeof(save_cards); j++){
				if(number == diamonds_check[j]){
					checking = false;
				}
				else {
					checking = true;
				}
			}
		} while(checking == false);
		diamonds_check[i] = number;
	}
	return number;
}

int random_without_repeating_pikes(int low,int high){
	bool checking = false;
	int number;
	for (int i = 0; i < total_numbers; i++){
		do{
			number = random(low, high);
			for(int j = 0; j < sizeof(save_cards); j++){
				if(number == pikes_check[j]){
					checking = false;
				}
				else {
					checking = true;
				}
			}
		} while(checking == false);
		pikes_check[i] = number;
	}
	return number;
}

int random_without_repeating_clover(int low,int high){
	bool checking = false;
	int number;
	for (int i = 0; i < total_numbers; i++){
		do{
			number = random(low, high);
			for(int j = 0; j < sizeof(save_cards); j++){
				if(number == clover_check[j]){
					checking = false;
				}
				else {
					checking = true;
				}
			}
		} while(checking == false);
		clover_check[i] = number;
	}
	return number;
}

char carta(){
	char carta_tomada;
	//Problem: without dowhile, it returns a 0 sometimes, still working on to fix it. I just dont know the reason
	do{
		int type_card = random(0,3); 		// type of card in the range 0 to 3
		int card;         // card in the range 0 to 12
		
		switch(type_card){
			case 0:
				card = random_without_repeating_hearts(0,12);
				carta_tomada = hearts[card];
				break;
			case 1:
				card = random_without_repeating_diamonds(0,12);
				carta_tomada = diamonds[card];
				break;
			case 2:
				card = random_without_repeating_pikes(0,12);
				carta_tomada = pikes[card];
				break;
			case 3:
				card = random_without_repeating_clover(0,12);
				carta_tomada = clover[card];
				break;
		}
	} while(carta_tomada == '0');
	return carta_tomada;
}

int real_value_player(char fake_value){
	
	int real_card_value;
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

int real_value_computer(char fake_value){
	
	int real_card_value;
	int A = 1;
	bool condicion_A = true;
	
	if (fake_value == 'J' || fake_value == 'Q' || fake_value == 'K'){
		real_card_value = 10;
	} else if (fake_value == 'A'){
		real_card_value == 1;
		computer_has_A = true;
	} else {
		real_card_value = fake_value - '0';	//convirtiendo char a int
	}
	
	return real_card_value;
}

void restart_cards_value(){
	for(int i = 0; i < sizeof(save_cards); i++){
		type_cards[i] = save_cards[i];
	}
}

void prepare_cards(){
	for(int i = 0; i < sizeof(save_cards); i++){
		hearts_check[i] = reset_values;
	}
	for(int i = 0; i < sizeof(save_cards); i++){
		diamonds_check[i] = reset_values;
	}
	for(int i = 0; i < sizeof(save_cards); i++){
		pikes_check[i] = reset_values;
	}
	for(int i = 0; i < sizeof(save_cards); i++){
		clover_check[i] = reset_values;
	}
}

void mix_cards(){
	int card;
	restart_cards_value();
	for(int i = 0; i < sizeof(type_cards); i++){
		card = random_without_repeating(0,12);
		hearts[i] = type_cards[card];
	}
	restart_cards_value();
	for(int i = 0; i < sizeof(type_cards); i++){
		card = random_without_repeating(0,12);
		diamonds[i] = type_cards[card];
	}
	restart_cards_value();
	for(int i = 0; i < sizeof(type_cards); i++){
		card = random_without_repeating(0,12);
		pikes[i] = type_cards[card];
	}
	restart_cards_value();
	for(int i = 0; i < sizeof(type_cards); i++){
		card = random_without_repeating(0,12);
		clover[i] = type_cards[card];
	}
	restart_cards_value();
}

void partida_extendida(){
	
	//just in case player wants another card.
	
}

void reset_score(){
	player_cards[5] 		= {};
	computer_cards[5]		= {};
	player_card_counter		= 0;
	computer_card_counter	= 0;
	player_score			= 0;
	computer_score			= 0;	
}

int main(int argc, char** argv) {
	std::cout<< "Ingrese el nombre del jugador (25 caracteres maximo): "	<<std::endl;
	std::cin>> player;

	while(true){
	
		std::cout<< "Barajeando el mazo..."	<<std::endl;
		prepare_cards();
		mix_cards();
		
		std::cout<< "Repartiendo cartas..."	<<std::endl;
		player_cards[player_card_counter] = carta();
		player_card_counter++;
		//std::cout<< "La primera carta es: " <<player_cards[player_card_counter]	<<std::endl;
		player_cards[player_card_counter] = carta();
		player_card_counter++;
		
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
			if (j == 0){
				std::cout<< "? , ";
			} else {
				std::cout<< computer_cards[j] << " , ";
			}
		}
		//std::cout<< "El numero secreto del ordenador es: " <<computer_cards[0] <<std::endl;
		std::cout<<std::endl;
		
		std::cout<< "Desea otra carta? (Y/N): ";
		std::cin>> continuar;
		std::cout<<std::endl;
		if (continuar == 'N' || continuar == 'n'){
			for(int i = 0; i < player_card_counter; i++){
				player_score += real_value_player(player_cards[i]);
			}
			for(int i = 0; i < computer_card_counter; i++){
				computer_score += real_value_computer(computer_cards[i]);
			}
			
			if(computer_has_A == true){
				int prueba = 0;
				prueba = (computer_score - 1) + 11;
				if(prueba == best_score){
					computer_score = prueba;
				}
				computer_has_A = false;
			}
			
			if (player_score < computer_score){
				std::cout<< "Ha ganado la computadora con: " <<computer_score << " puntos." <<std::endl;
				std::cout<< "Ha perdido " <<player << " con: " <<player_score << " puntos."<<std::endl;
			} else if (player_score == computer_score){
				std::cout<< "Ha sido un empate" <<std::endl;
				std::cout<< "La computadora ha obtenido: " <<computer_score << " puntos." <<std::endl;
				std::cout<<player << "ha obtenido: " <<player_score << " puntos."<<std::endl;
			} else {
				std::cout<< "Ha ganado " <<player << " con: " <<player_score << " puntos."<<std::endl;
				std::cout<< "Ha perdido la computadora con: " <<computer_score << " puntos." <<std::endl;
			}
		} else if (continuar == 'Y' || continuar == 'y' || continuar == 'S' || continuar == 's') {
			//partida_extendida();
			std::cout<< "Aun no programo esta parte :v" <<std::endl;
		} else {
			std::cout<< "Comando no valido ... Reiniciando" <<std::endl;
		}
		
		reset_score();
		
		std::cout<<std::endl;
		system("pause");
		std::cout<<std::endl;
	}
	
	return 0;
}
