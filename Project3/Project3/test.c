#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 카드 구조체 입니다.
typedef struct {
	char name[10];
	int hp;
	int atk;
}Card;

//카드의 배열을 가지고 있는 덱 구조체 입니다.
typedef struct {
	Card* cards;
	int size;
}Deck;

//덱을 가지고 있는 플레이어 구조체 입니다.
typedef struct {
	Deck deck;
	int number;
	int livedCard;
}Player;

void error_call(int error_code);
//카드를 초기화합니다.
int init(Card* c);
//카드를 업데이트합니다.
void update(Card* c, int hp, int atk, char* name);
void update_hp(Card* c, int hp);
void update_atk(Card* c, int atk);
void update_name(Card* c, char* name);
//카드의 정보를 출력합니다.
void print_card_data(Card c);
//문자열로부터 카드의 정보를 만들어 반환합니다.
Card StringToCard(char* str);

//덱을 초기화합니다.
void init_deck(Deck* d, int size);
//덱을 업데이트합니다. values는 cards 배열의 index를 가지고 있는 정수 배열입니다. size는 배열의 크기입니다.
void update_deck(Deck* d, int* values, int size);
const char* cards[] = { "Warrior 1 1", "Mage 2 2", "Archer 3 3" };

int main() {
	////////////////////////////////////////////////////////////
	//값 입력 부분
	int input;
	scanf("%d", &input);

	//홀수 입력시 -1 출력하고 종료
	if (input % 2 == 1) {
		printf("-1");
		return -1;
	}

	int* values = (int*)malloc(sizeof(int) * input); // input 사이즈만큼 배열 할당
	int decksize = input / 2;
	for (int i = 0; i < input; i++) {
		scanf("%d", &values[i]);
	}
	////////////////////////////////////////////////////////////
	//write youre code here
////////////////////////////////////////////////////////////
//플레이어 데이터 초기화
	Player p1, p2;
	init_deck(&p1.deck, decksize);
	init_deck(&p2.deck, decksize);
	////////////////////////////////////////////////////////////
	//플레이어 데이터 업데이트
	//작성해주세요.



	////////////////////////////////////////////////////////////
	//플레이어 데이터 출력
	printf("p1 haves : ");
	for (int i = 0; i < decksize; i++) {
		printf("%s ", p1.deck.cards[i].name);
	}
	printf("\n");
	printf("p2 haves : ");
	for (int i = 0; i < decksize; i++) {
		printf("%s ", p2.deck.cards[i].name);
	}
	printf("\n");

	////////////////////////////////////////////////////////////
	//전투 및 전투 결과 출력
	//작성해주세요.





	printf("0");
	///////////////////////////////////////////////////////////	
	return 0;
}

void error_call(int error_code) {
	if (error_code == 0) printf("success\n");
	else printf("error code occur [%d] : \n", error_code);
}

int init(Card* c) {
	c->atk = 0;
	c->hp = 0;
	c->name = NULL;
	return 0;
}

void update(Card* c, int hp, int atk, char* name) {
	update_hp(c, hp);
	update_atk(c, atk);
	update_name(c, name);
}
void update_hp(Card* c, int hp) {
	c->hp = hp;
}
void update_atk(Card* c, int atk) {
	c->atk = atk;
}

void update_name(Card* c, char* name) {
	int length = strlen(name);
	//c->name이 할당되지 않았을 경우 할당해줌
	if (c->name == NULL)c->name = (char*)malloc(sizeof(char) * length);
	//할당되어 있으면 재할당함
	else c->name = (char*)realloc(c->name, sizeof(char) * length);
	strcpy(c->name, name);
}

void print_card_data(Card c) {
	printf("[%s]: hp[%d], atk[%d]\n", c.name, c.hp, c.atk);
}


Card StringToCard(char* str) {
	Card result; // 새로운 카드 선언
	init(&result); // 카드 초기화

	int wordTable[3][2];
	memset(wordTable, -1, sizeof(int) * 3 * 2);

	char c = ' '; int i = 0, wordsize = 0, len = 0;
	for (;;) {
		c = str[i];
		if (c == ' ' || c == '\0') {
			wordTable[wordsize++][1] = len;
			len = 0;
			i++;
			if (c == '\0') break;
			else continue;
		}
		else if (wordTable[wordsize][0] == -1) {
			wordTable[wordsize][0] = i;
		}
		i++;
		len++;
	}

	//워드 테이블을 이용해 분리될 문자열 크기 할당
	char* names = (char*)malloc(sizeof(char) * (wordTable[0][1] + 1));
	char* hps = (char*)malloc(sizeof(char) * (wordTable[1][1] + 1));
	char* atks = (char*)malloc(sizeof(char) * (wordTable[2][1] + 1));

	//워드 테이블을 이용해 문자열 복사, 끝 문자에는 널이 들어가야함
	strncpy(names, (str + wordTable[0][0]), sizeof(char) * wordTable[0][1]); names[wordTable[0][1]] = '\0';
	strncpy(hps, (str + wordTable[1][0]), sizeof(char) * wordTable[1][1]); hps[wordTable[1][1]] = '\0';
	strncpy(atks, (str + wordTable[2][0]), sizeof(char) * wordTable[2][1]); atks[wordTable[2][1]] = '\0';

	//atoi를 사용하여 string to integer
	int hp = atoi(hps);
	int atk = atoi(atks);

	//카드에 내용을 업데이트함
	update(&result, hp, atk, names);

	//필요 없어진 문자열의 메모리를 풀어줌, names도 업데이트 함수에서 재할당하므로 풀어줘야함
	free(names);
	free(hps);
	free(atks);
	return result;
}

void init_deck(Deck* d, int size) {
	d->cards = (Card*)malloc(sizeof(Card) * size);
	d->size = size;
}

void update_deck(Deck* d, int* values, int size) {
	for (int i = 0; i < size; i++) {
		d->cards[i] = StringToCard(cards[values[i]]);
	}
}