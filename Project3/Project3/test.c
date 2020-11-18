#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ī�� ����ü �Դϴ�.
typedef struct {
	char name[10];
	int hp;
	int atk;
}Card;

//ī���� �迭�� ������ �ִ� �� ����ü �Դϴ�.
typedef struct {
	Card* cards;
	int size;
}Deck;

//���� ������ �ִ� �÷��̾� ����ü �Դϴ�.
typedef struct {
	Deck deck;
	int number;
	int livedCard;
}Player;

void error_call(int error_code);
//ī�带 �ʱ�ȭ�մϴ�.
int init(Card* c);
//ī�带 ������Ʈ�մϴ�.
void update(Card* c, int hp, int atk, char* name);
void update_hp(Card* c, int hp);
void update_atk(Card* c, int atk);
void update_name(Card* c, char* name);
//ī���� ������ ����մϴ�.
void print_card_data(Card c);
//���ڿ��κ��� ī���� ������ ����� ��ȯ�մϴ�.
Card StringToCard(char* str);

//���� �ʱ�ȭ�մϴ�.
void init_deck(Deck* d, int size);
//���� ������Ʈ�մϴ�. values�� cards �迭�� index�� ������ �ִ� ���� �迭�Դϴ�. size�� �迭�� ũ���Դϴ�.
void update_deck(Deck* d, int* values, int size);
const char* cards[] = { "Warrior 1 1", "Mage 2 2", "Archer 3 3" };

int main() {
	////////////////////////////////////////////////////////////
	//�� �Է� �κ�
	int input;
	scanf("%d", &input);

	//Ȧ�� �Է½� -1 ����ϰ� ����
	if (input % 2 == 1) {
		printf("-1");
		return -1;
	}

	int* values = (int*)malloc(sizeof(int) * input); // input �����ŭ �迭 �Ҵ�
	int decksize = input / 2;
	for (int i = 0; i < input; i++) {
		scanf("%d", &values[i]);
	}
	////////////////////////////////////////////////////////////
	//write youre code here
////////////////////////////////////////////////////////////
//�÷��̾� ������ �ʱ�ȭ
	Player p1, p2;
	init_deck(&p1.deck, decksize);
	init_deck(&p2.deck, decksize);
	////////////////////////////////////////////////////////////
	//�÷��̾� ������ ������Ʈ
	//�ۼ����ּ���.



	////////////////////////////////////////////////////////////
	//�÷��̾� ������ ���
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
	//���� �� ���� ��� ���
	//�ۼ����ּ���.





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
	//c->name�� �Ҵ���� �ʾ��� ��� �Ҵ�����
	if (c->name == NULL)c->name = (char*)malloc(sizeof(char) * length);
	//�Ҵ�Ǿ� ������ ���Ҵ���
	else c->name = (char*)realloc(c->name, sizeof(char) * length);
	strcpy(c->name, name);
}

void print_card_data(Card c) {
	printf("[%s]: hp[%d], atk[%d]\n", c.name, c.hp, c.atk);
}


Card StringToCard(char* str) {
	Card result; // ���ο� ī�� ����
	init(&result); // ī�� �ʱ�ȭ

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

	//���� ���̺��� �̿��� �и��� ���ڿ� ũ�� �Ҵ�
	char* names = (char*)malloc(sizeof(char) * (wordTable[0][1] + 1));
	char* hps = (char*)malloc(sizeof(char) * (wordTable[1][1] + 1));
	char* atks = (char*)malloc(sizeof(char) * (wordTable[2][1] + 1));

	//���� ���̺��� �̿��� ���ڿ� ����, �� ���ڿ��� ���� ������
	strncpy(names, (str + wordTable[0][0]), sizeof(char) * wordTable[0][1]); names[wordTable[0][1]] = '\0';
	strncpy(hps, (str + wordTable[1][0]), sizeof(char) * wordTable[1][1]); hps[wordTable[1][1]] = '\0';
	strncpy(atks, (str + wordTable[2][0]), sizeof(char) * wordTable[2][1]); atks[wordTable[2][1]] = '\0';

	//atoi�� ����Ͽ� string to integer
	int hp = atoi(hps);
	int atk = atoi(atks);

	//ī�忡 ������ ������Ʈ��
	update(&result, hp, atk, names);

	//�ʿ� ������ ���ڿ��� �޸𸮸� Ǯ����, names�� ������Ʈ �Լ����� ���Ҵ��ϹǷ� Ǯ�������
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