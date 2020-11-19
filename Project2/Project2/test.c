#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct card {                   // ī�� ����ü
	char card_type[10];
	int score;                   //gameplayers[][6]
	int needtok_white;           //gameplayers[][0]
	int needtok_blue;            //gameplayers[][1]
	int needtok_red;             //gameplayers[][2]
	int needtok_brown;           //gameplayers[][3]
	int needtok_green;           //gameplayers[][4]
}Card;


void choice1(int *_gameplayers)  // ���� �ٸ� ������ ���� 3�� ��������
{
	// ���� ��ū�� �� 10������ ����, ������ 4���̻� �����־�� 2�� ������ �� ����
}
void choice2(int* _gameplayers) // ���� ������ ���� ��ū 2�� ��������
{
	// ���� ��ū�� �� 10������ ����, ������ 4���̻� �����־�� 2�� ������ �� ����
}
int choice3(int* _gameplayers,int* _card_discount) // ���� ī�� �����ϱ�
{
	// ���� ī�忡 ǥ�õ� ��ŭ ��ū�� �����Ͽ� ī�带 �����Ѵ�
	// ���� ī�忡 �����ϴ� ������ŭ ����
}
void choice4(int* _gameplayers) // ����ī�� �����ϱ�(with Ȳ����ū)
{
	// ���� ī�带 ������ �� ������, ���� ���Ÿ� ����ϸ� �ش�ī�带 ������ ����
	// Ȳ����ū�� �Բ� �����´�
}

void rule(int* _gameplayers)
{
	// ���� ī�� �����̵Ǹ� ���� ī�带 ���� ( ���� �������� ������ �� �� �ְ� ���� and �����湮�� �ѹ��� ����)
	// ���ϸ��� �÷��̾ 15���̻� ��Ҵ��� Ȯ���� ������ �� ������ ���������� ���� ����(������ �����ΰ� �������, ���� ���� ������ ������ ī�� ������ �� ���� ����� �¸�)
}

void print_map(int players, int gameplayers[][7], Card *blue, Card *orange, Card *green, Card *nob, int *totaltok,int *emtycard)
{
	// �� �ϸ��� ī�� ���� ��Ȳ�� �ð�ȭ����   
	printf("-------------����ī��-----------------\n");
	for (int n = 0; n < players + 1; n++)
	{
		printf("     *    |");
	}
	printf("\n");
	for (int n = 0; n < players + 1; n++)
	{
		printf("  ���� %d  |", nob[players].score);
	}
	printf("\n");
	for (int n = 0; n < players + 1; n++)
	{
		printf("���Ļ�����|");
	}
	printf("\n");
	for (int n = 0; n < players + 1; n++)
	{
		printf("%d %d %d %d %d |",nob[players].needtok_white, nob[players].needtok_blue, nob[players].needtok_red, nob[players].needtok_brown,nob[players].needtok_green);
	}
	printf("\n");
	printf("-------------����ī��(�ʷ�)-----------------\n");
	printf("���� �ʷ� |");
	int card_number = 1;
	for (int n = 0; n <4; n++)
	{
		printf("  (%2d)-%s   |",card_number++,green[n].card_type);
	}
	printf("\n");
	printf(" %2d��     |",emtycard[2]);
	for (int n = 0; n < 4; n++)
	{
		printf("���Ļ�����|");
	}
	printf("\n");
	printf("          |");
	for (int n = 0; n < 4; n++)
	{
		printf("%d %d %d %d %d |", green[n].needtok_white, green[n].needtok_blue, blue[n].needtok_red, blue[n].needtok_brown, blue[n].needtok_green);
	}
	printf("\n");
	
	printf("-------------����ī��(��Ȳ)-----------------\n");
	printf("���� ��Ȳ |");
	for (int n = 0; n < 4; n++)
	{
		printf("  (%2d)-%s   |", card_number++, orange[n].card_type);
	}
	printf("\n");
	printf(" %2d��     |", emtycard[1]);
	for (int n = 0; n < 4; n++)
	{
		printf("���Ļ�����|");
	}
	printf("\n");
	printf("          |");
	for (int n = 0; n < 4; n++)
	{
		printf("%d %d %d %d %d |", orange[n].needtok_white, orange[n].needtok_blue, orange[n].needtok_red, orange[n].needtok_brown, orange[n].needtok_green);
	}
	printf("\n");
	
	printf("-------------����ī��(�Ķ�)-----------------\n");
	printf("���� �Ķ� |");
	for (int n = 0; n < 4; n++)
	{
		printf("  (%2d)-%s   |", card_number++, blue[n].card_type);
	}
	printf("\n");
	printf(" %2d��     |", emtycard[0]);
	for (int n = 0; n < 4; n++)
	{
		printf("���Ļ�����|");
	}
	printf("\n");
	printf("          |");
	for (int n = 0; n < 4; n++)
	{
		printf("%d %d %d %d %d |", blue[n].needtok_white, blue[n].needtok_blue, green[n].needtok_red, green[n].needtok_brown, green[n].needtok_green);
	}
	printf("\n");
	
	printf("-------------���� ��ū-----------------\n");
	printf("��(%d��) ��(%d��) ��(%d��) ��(%d��) ��(%d��)\n",totaltok[0],totaltok[1],totaltok[2],totaltok[3],totaltok[4]);
	
	printf("------------�÷��̾� ��Ȳ-----------------\n");
	for (int n = 0; n < players; n++)
	{
		printf("  -player%d- |",n);
	}
	printf("\n");
	for (int n = 0; n < players; n++)
	{
		printf("  ����: %2d  |", gameplayers[n][6]);
	}
	printf("\n");
	for (int n = 0; n < players; n++)
	{
		printf("���Ļ����ʰ�|");
	}
	printf("\n");
	for (int n = 0; n < players; n++)
	{
		printf("%d %d %d %d %d %d |", gameplayers[n][0], gameplayers[n][1], gameplayers[n][2], gameplayers[n][3], gameplayers[n][4], gameplayers[n][5]);
	}
	printf("\n");

	
}
int put_card(Card *blue,Card *orange, Card *green, Card *mixblue, Card *mixorange, Card *mixgreen,int choice)   // ����ī�带 ��� ���ڸ��� ���ο� ����ī�带 ����ִ� �Լ�
{
	static blue_count = 4;
	static orange_count = 4;
	static green_count = 4;
	if (0 < choice && choice < 5) {
		blue[choice - 1] = mixblue[blue_count++];
		return 0;
	}
	else if (4 < choice && choice < 9) {
		orange[choice - 5] = mixorange[orange_count++];
		return 1;
	}
	else {
		green[choice - 9] = mixgreen[green_count++];
		return 2;
	}

}

int main(void)
{
	Card blue[40] = { 0 };          // �Է� �־�� �� ī���
	Card orange[30] = { 0 };
	Card green[20] = { 0 };
	Card nob[10] = { 0 };

	int players, choice;
	int gameplayers[4][7] = { 0 };  //�ִ� ���� �ο����� ����(6��),������ ��Ÿ�� 2���� �迭
	int card_discount[4][5] = { 0 };  // �÷��̾ ī��(����,����)�� ���� ���� 
	int totaltok[6] = { 0,0,0,0,0,999 };  // ���ӿ� ����� �ִ� ���� ��ū ����
	int tok = { 0 };                    // �ο����� ���� �� ��ū ������ ��Ÿ���� ����
	int emtycard[3] = { 36,26,16 };      // ���ӿ� ����� �ִ� ���� ī�� ����

	Card mixblue[40] = { 0 };            // ī�带 ��� �迭
	Card mixorange[30] = { 0 };
	Card mixgreen[20] = { 0 };
	Card mixnob[10] = { 0 };

	printf("SPLENDER\n");
	printf("�� ���� �Ͻ� �ǰ���?(2~4�ο� ����)");
	scanf_s("%d", &players);
	
	if (players == 2) tok = 4;             // �ο����� ���� ��ū ������ ����
	else if (players == 3) tok = 5;
	else tok = 7;
	for (int n = 0; n < 5; n++)
		totaltok[n] = tok;

	srand(time(NULL));

	//�������� ī��迭�� �� 
	for (int n = 0; n < 40; n++)
	{
		int check[40] = { 0 };
		int k = rand() % 40;
		while (1) {
			if (check[k] == 0) {
				mixblue[n] = blue[k];
				check[k] = 1;
				break;
			}
		}
	}
	for (int n = 0; n < 30; n++)
	{
		int check[40] = { 0 };
		while (1) {
			int k = rand() % 30;
			if (check[k] == 0) {
				mixorange[n] = orange[k];
				check[k] = 1;
				break;
			}
		}
		for (int n = 0; n < 20; n++)
		{
			int check[40] = { 0 };
			while (1) {
				int k = rand() % 20;
				if (check[k] == 0) {
					mixgreen[n] = green[k];
					check[k] = 1;
					break;
				}
			}
		}
		for (int n = 0; n < players + 1; n++)
		{
			int check[10] = { 0 };
			int k = rand() % 10;
			while (1) {
				if (check[k] == 0) {
					mixnob[n] = nob[k];
					check[k] = 1;
					break;
				}
			}
		}
		
		// �������� �迭�� ī���� ���ӿ� ��ĥ ī�� 4���� ��Ÿ���� �迭
		Card setblue[4] = { mixblue[0],mixblue[1],mixblue[2],mixblue[3] };    
		Card setorange[4] = { mixorange[0],mixorange[1],mixorange[2],mixorange[3] };
		Card setgreen[4] = { mixgreen[0],mixgreen[1],mixgreen[2],mixgreen[3] };
		Card setnob[5] = { mixnob[0],mixnob[1],mixnob[2],mixnob[3],mixnob[4] };
		
		while (1)              // ������ ���������� ���� �ݺ���
		{
			for (int n = 0; n < players; n++)
			{
				print_map(players, gameplayers, setblue, setorange, setgreen, setnob,totaltok,emtycard);   // ���ϸ��� �������� ������
				printf("----------------player%d turn----------------\n", n);
				printf("*����*\n1.���� �ٸ� ������ ���� ��ū 3�� ��������\n2.���� ������ ���� ��ū 2�� ��������\n3.���� ī�� �����ϱ�\n4.���� ī�� �����ϱ�\n");
				scanf_s("%d", &choice);              // �÷��̾ 1~4�߿��� ��������
				switch (choice)
				{
				case 1:
					choice1(gameplayers[players]);
					break;
				case 2:
					choice2(gameplayers[players]);
					break;
				case 3:
				{	
					int number = choice3(gameplayers[players], card_discount[players]);      // ���� ī�� �� ��ȣ�� return �Ѵ�
					int changecard= put_card(blue, orange, green, mixblue, mixorange, mixgreen, number);  // �� ��ȣ��  ���ο� ī�带 �־��ְ�, ���� ������ ī������ ��ȣ�� return�Ѵ�. 
					emtycard[changecard]--;                                                     // ��ȣ�� �޾� �� ������ ���� ī�带 �ϳ� ���δ�.
					break;
				}
				case 4:
					choice4(gameplayers[players]);
					break;
				}
				rule(gameplayers[players]);                          // ���ϸ��� ���� �����Ų��.
			}
		}
	}
}