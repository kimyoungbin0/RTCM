#include <stdio.h>


struct card {                   // ī�� ����ü
	char card_type[10];
	int score;
	int needtok_white;
	int needtok_blue;
	int needtok_red;
	int needtok_brown;
	int needtok_green;
};

void choice1()  // ���� �ٸ� ������ ���� 3�� ��������
{

	rule();
}
void choice2() // ���� ������ ���� ��ū 2�� ��������
{

	rule();
}
void choice3() // ���� ī�� �����ϱ�
{

	rule();
}
void choice4() // ����ī�� �����ϱ�(with Ȳ����ū)
{

}

int rule()
{
	// ���� ī�忡 �����ϴ� ������ŭ ����(3�� ���̽��� ����)
	// ���� ��ū�� �� 10������ ����, ������ 4���̻� �����־�� 2�� ������ �� ����(1,2�� ���̽��� ����)
	// ���ϸ��� �÷��̾ 15���̻� ��Ҵ��� Ȯ��
}

void print_map()
{
	// �� �ϸ��� ī�� ���� ��Ȳ�� �ð�ȭ����
}
int main(void)
{
	int players, choice;
	printf("SPLENDER\n");
	printf("�� ���� �Ͻ� �ǰ���?");
	scanf_s("%d", &players);
	// �÷��̾� ���� �°� ����ī��, ��ū ���
	while (1)              // ������ ���������� ���� �ݺ���
	{
		for (int n = 0; n < players; n++)
		{
			print_map();
			scanf_s("%d", &choice);
			switch (choice)
			{
			case 1:
				choice1();
				break;
			case 2:
				choice2();
				break;
			case 3:
				choice3();
				break;
			case 4:
				choice4();
				break;
			}
		}
	}
}