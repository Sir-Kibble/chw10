#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cards.h"

void drawHand(int numofcards, struct Hand *H){

	static struct Card cardz[52] = {{0, "Ace of Clubs"},{1,"Ace of Diamonds"},{2,"Ace of Hearts"},
	{3,"Ace of Spades"},{4,"King of Clubs"},{5,"King of Diamonds"},{6,"King of Hearts"}, \
	{7,"King of Spades"},{8,"Queen of Clubs"},{9,"Queen of Diamonds"},{10,"Queen of Hearts"}, \
	{11,"Queen of Spades"},{12,"Jack of Clubs"},{13,"Jack of Diamonds"},{14,"Jack of Hearts"}, \
	{15,"Jack of Spades"},{16,"10 of Clubs"},{17,"10 of Diamonds"},{18,"10 of Hearts"},{19,"10 of Spades"}, \
	{20,"9 of Clubs"},{21,"9 of Diamonds"},{22,"9 of Hearts"},{23,"9 of Spades"},{24,"8 of Clubs"}, \
	{25,"8 of Diamonds"},{26,"8 of Hearts"},{27,"8 of Spades"},{28,"7 of Clubs"},{29,"7 of Diamonds"}, \
	{30,"7 of Hearts"},{31,"7 of Spades"},{32,"6 of Clubs"},{33,"6 of Diamonds"},{34,"6 of Hearts"}, \
	{35,"6 of Spades"},{36,"5 of Clubs"},{37,"5 of Diamonds"},{38,"5 of Hearts"},{39,"5 of Spades"}, \
	{40,"4 of Clubs"},{41,"4 of Diamonds"},{42,"4 of Hearts"},{43,"4 of Spades"},{44,"3 of Clubs"}, \
	{45,"3 of Diamonds"},{46,"3 of Hearts"},{47,"3 of Spades"},{48,"2 of Clubs"},{49,"2 of Diamonds"}, \
	{50,"2 of Hearts"},{51,"2 of Spades"}};
	static struct Deck D = {52,{{0, "Ace of Clubs"},{1,"Ace of Diamonds"},{2,"Ace of Hearts"},
	{3,"Ace of Spades"},{4,"King of Clubs"},{5,"King of Diamonds"},{6,"King of Hearts"}, \
	{7,"King of Spades"},{8,"Queen of Clubs"},{9,"Queen of Diamonds"},{10,"Queen of Hearts"}, \
	{11,"Queen of Spades"},{12,"Jack of Clubs"},{13,"Jack of Diamonds"},{14,"Jack of Hearts"}, \
	{15,"Jack of Spades"},{16,"10 of Clubs"},{17,"10 of Diamonds"},{18,"10 of Hearts"},{19,"10 of Spades"}, \
	{20,"9 of Clubs"},{21,"9 of Diamonds"},{22,"9 of Hearts"},{23,"9 of Spades"},{24,"8 of Clubs"}, \
	{25,"8 of Diamonds"},{26,"8 of Hearts"},{27,"8 of Spades"},{28,"7 of Clubs"},{29,"7 of Diamonds"}, \
	{30,"7 of Hearts"},{31,"7 of Spades"},{32,"6 of Clubs"},{33,"6 of Diamonds"},{34,"6 of Hearts"}, \
	{35,"6 of Spades"},{36,"5 of Clubs"},{37,"5 of Diamonds"},{38,"5 of Hearts"},{39,"5 of Spades"}, \
	{40,"4 of Clubs"},{41,"4 of Diamonds"},{42,"4 of Hearts"},{43,"4 of Spades"},{44,"3 of Clubs"}, \
	{45,"3 of Diamonds"},{46,"3 of Hearts"},{47,"3 of Spades"},{48,"2 of Clubs"},{49,"2 of Diamonds"}, \
	{50,"2 of Hearts"},{51,"2 of Spades"}}};
	
	srand(time(NULL));
	int temp = numofcards;	
	H->count = numofcards;
	H->cards[numofcards];
	int pickednums[numofcards];
	int x,y,flag1;

	for(x = 0; x < numofcards; x++){
		while(1){
			temp = rand() % 52;
			flag1 = 1;
			for(y = 0;y < sizeof(pickednums)/sizeof(int);y++)
				if(pickednums[y] == temp){
					flag1 = 0;
					break;
				}
				if(flag1){
					
					break;	
				}
		}//end while
		H->cards[x] = D.cards[temp];
		pickednums[x] = temp;
	}//end for
}//end drawhand

void sortHand(int numofcards, struct Hand *H){
	//qsort((void *) H->cards, numofcards, sizeof(Card), compar);
	int flag,x,y;
	struct Card temp;
	while(1){
		flag = 1;
		for(x = 0; x < numofcards-1; x++){
			if(H->cards[x].member > H->cards[x+1].member){
				temp = H->cards[x];
				H->cards[x] = H->cards[x+1];
				H->cards[x+1] = temp;
				flag = 0;
			}
			
		}//end for
		if(flag)
				break;
	}//end while
	
	
}//end sortHand

int compar(const void * elem1, const void * elem2){
	return (*(Card*)elem1 - *(Card*)elem2);
}

//end comp	