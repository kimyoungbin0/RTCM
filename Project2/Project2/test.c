#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct card {                   // ī�� ����ü
	char card_type[10];
	int score;                   //gameplayers[][6]
	int needtok_white;           //gameplayers[][0]
	int needtok_blue;            //gameplayers[][1]
	int needtok_red;             //gameplayers[][2]
	int needtok_brown;           //gameplayers[][3]
	int needtok_green;           //gameplayers[][4]
};


void choice1(int *_gameplayers)  // ���� �ٸ� ������ ���� 3�� ��������
{
	// ���� ��ū�� �� 10������ ����, ������ 4���̻� �����־�� 2�� ������ �� ����
}
void choice2(int* _gameplayers) // ���� ������ ���� ��ū 2�� ��������
{
	// ���� ��ū�� �� 10������ ����, ������ 4���̻� �����־�� 2�� ������ �� ����
}
void choice3(int* _gameplayers,int _card_discount) // ���� ī�� �����ϱ�
{
	// ���� ī�忡 ǥ�õ� ��ŭ ��ū�� �����Ͽ� ī�带 �����Ѵ�
	// ���� ī�忡 �����ϴ� ������ŭ ����
}
void choice4(int* _gameplayers) // ����ī�� �����ϱ�(with Ȳ����ū)
{
	// ���� ī�带 ������ �� ������, ���� ���Ÿ� ����ϸ� �ش�ī�带 ������ ����
	// Ȳ����ū�� �Բ� �����´�
}

int rule(int* _gameplayers)
{
	// ���� ī�� �����̵Ǹ� ���� ī�带 ���� ( ���� �������� ������ �� �� �ְ� ���� and �����湮�� �ѹ��� ����)
	// ���ϸ��� �÷��̾ 15���̻� ��Ҵ��� Ȯ���� ������ �� ������ ���������� ���� ����(������ �����ΰ� �������, ���� ���� ������ ������ ī�� ������ �� ���� ����� �¸�)
}

void print_map()
{
	// �� �ϸ��� ī�� ���� ��Ȳ�� �ð�ȭ����   
}

int main(void)
{
	int players, choice;
	int gameplayers[4][7] = { 0 };  //�ִ� ���� �ο����� ����(6��),������ ��Ÿ�� 2���� �迭
	int card_discount[4][5] = { 0 };  // �÷��̾ ī��(����,����)�� ���� ���� 

	printf("SPLENDER\n");
	printf("�� ���� �Ͻ� �ǰ���?(2~4�ο� ����)");
	scanf_s("%d", &players);

	// ������ �̿��� �÷��̾� ���� �°� ī��, ��ū ���  

	while (1)              // ������ ���������� ���� �ݺ���
	{
		for (int n = 0; n < players; n++)
		{
			print_map();
			printf("----------------player%d turn----------------\n", n);
			printf("*����*\n1.���� �ٸ� ������ ���� ��ū 3�� ��������\n2.���� ������ ���� ��ū 2�� ��������\n3.���� ī�� �����ϱ�\n4.���� ī�� �����ϱ�\n");
			scanf_s("%d", &choice);
			switch (choice)
			{
			case 1:
				choice1(gameplayers[players]);
				break;
			case 2:
				choice2(gameplayers[players]);
				break;
			case 3:
				choice3(gameplayers[players], card_discount[players]);
				break;
			case 4:
				choice4(gameplayers[players]);
				break;
			}
			rule(gameplayers[players]);
		}
	}
}