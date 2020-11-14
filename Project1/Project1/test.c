#include <stdio.h>


struct card {                   // 카드 구조체
	char card_type[10];
	int score;
	int needtok_white;
	int needtok_blue;
	int needtok_red;
	int needtok_brown;
	int needtok_green;
};

void choice1()  // 서로 다른 색깔의 보석 3개 가져오기
{

	rule();
}
void choice2() // 같은 색깔의 보석 토큰 2개 가져오기
{

	rule();
}
void choice3() // 개발 카드 구매하기
{

	rule();
}
void choice4() // 개발카드 예약하기(with 황금토큰)
{

}

int rule()
{
	// 개발 카드에 제공하는 보석만큼 할인(3번 초이스때 실행)
	// 보석 토큰은 총 10개까지 보유, 색깔이 4개이상 남아있어야 2개 가져올 수 있음(1,2번 초이스때 실행)
	// 매턴마다 플레이어가 15점이상 모았는지 확인
}

void print_map()
{
	// 매 턴마다 카드 세팅 상황을 시각화해줌
}
int main(void)
{
	int players, choice;
	printf("SPLENDER\n");
	printf("몇 명에서 하신 건가요?");
	scanf_s("%d", &players);
	// 플레이어 수에 맞게 귀족카드, 토큰 배분
	while (1)              // 게임이 끝날때까지 턴이 반복됌
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