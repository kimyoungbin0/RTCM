#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct card {                   // 카드 구조체
	char card_type[10];
	int score;                   //gameplayers[][6]
	int needtok_white;           //gameplayers[][0]
	int needtok_blue;            //gameplayers[][1]
	int needtok_red;             //gameplayers[][2]
	int needtok_brown;           //gameplayers[][3]
	int needtok_green;           //gameplayers[][4]
};


void choice1(int *_gameplayers)  // 서로 다른 색깔의 보석 3개 가져오기
{
	// 보석 토큰은 총 10개까지 보유, 색깔이 4개이상 남아있어야 2개 가져올 수 있음
}
void choice2(int* _gameplayers) // 같은 색깔의 보석 토큰 2개 가져오기
{
	// 보석 토큰은 총 10개까지 보유, 색깔이 4개이상 남아있어야 2개 가져올 수 있음
}
void choice3(int* _gameplayers,int _card_discount) // 개발 카드 구매하기
{
	// 개발 카드에 표시된 만큼 토큰을 지불하여 카드를 구입한다
	// 개발 카드에 제공하는 보석만큼 할인
}
void choice4(int* _gameplayers) // 개발카드 예약하기(with 황금토큰)
{
	// 개발 카드를 구매할 수 없지만, 추후 구매를 희망하면 해당카드를 가져와 보관
	// 황금토큰도 함께 가져온다
}

int rule(int* _gameplayers)
{
	// 귀족 카드 조건이되면 귀족 카드를 얻음 ( 만약 여러개면 선택을 할 수 있게 해줌 and 귀족방문는 한번만 가능)
	// 매턴마다 플레이어가 15점이상 모았는지 확인후 있으면 그 바퀴를 마지막으로 게임 종료(마지막 바퀴인걸 출력해줌, 만약 같은 점수가 있을시 카드 개수가 더 작은 사람이 승리)
}

void print_map()
{
	// 매 턴마다 카드 세팅 상황을 시각화해줌   
}

int main(void)
{
	int players, choice;
	int gameplayers[4][7] = { 0 };  //최대 게임 인원수와 보석(6개),점수를 나타낸 2차원 배열
	int card_discount[4][5] = { 0 };  // 플레이어별 카드(개발,귀족)로 인한 할인 

	printf("SPLENDER\n");
	printf("몇 명에서 하신 건가요?(2~4인용 게임)");
	scanf_s("%d", &players);

	// 난수를 이용해 플레이어 수에 맞게 카드, 토큰 배분  

	while (1)              // 게임이 끝날때까지 턴이 반복됌
	{
		for (int n = 0; n < players; n++)
		{
			print_map();
			printf("----------------player%d turn----------------\n", n);
			printf("*선택*\n1.서로 다른 색깔의 보석 토큰 3개 가져오기\n2.같은 색깔의 보석 토큰 2개 가져오기\n3.개발 카드 구매하기\n4.개발 카드 예약하기\n");
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