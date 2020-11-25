#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct card {                   // 카드 구조체
    char card_type[10];
    int score;                   //gameplayers[][6]
    int needtok_white;           //gameplayers[][0]
    int needtok_blue;            //gameplayers[][1]
    int needtok_red;             //gameplayers[][2]
    int needtok_brown;           //gameplayers[][3]
    int needtok_green;           //gameplayers[][4]
}Card;


void choice1(int gameplayers[][7], int* totaltok, int turn)  // 서로 다른 색깔의 보석 3개 가져오기
{
    // 보석 토큰은 총 10개까지 보유, 색깔이 4개이상 남아있어야 2개 가져올 수 있음

}
void choice2(int gameplayers[][7], int* totaltok, int turn) // 같은 색깔의 보석 토큰 2개 가져오기
{


}
int choice3(int* _gameplayers, int* _card_discount) // 개발 카드 구매하기
{
    // 개발 카드에 표시된 만큼 토큰을 지불하여 카드를 구입한다
    // 개발 카드에 제공하는 보석만큼 할인
}
void choice4(int* _gameplayers) // 개발카드 예약하기(with 황금토큰)
{
    // 개발 카드를 구매할 수 없지만, 추후 구매를 희망하면 해당카드를 가져와 보관
    // 황금토큰도 함께 가져온다
}

int rule(int* _gameplayers[][7], int* _card_discount[][6], int players, int turn, Card* setnob)
{
    // 귀족 카드 조건이되면 귀족 카드를 얻음 ( 만약 여러개면 선택을 할 수 있게 해줌 and 귀족방문는 한번만 가능)
    int condition = 0;
    int select_card[5] = { 0 }; // 고를 수 있는 귀족 카드가 여러 개일 고를 수 있도록 번호 제공
    int choose = 0;
    if (_card_discount[turn][6] == 1)
    {
        printf("You already have nobility-card. \n");
        return -1;
    }
    for (int n = 0; n < players + 1; n++)
    {
        if (_card_discount[turn][0] >= setnob[n].needtok_white)
            condition++;
        if (_card_discount[turn][1] >= setnob[n].needtok_blue)
            condition++;
        if (_card_discount[turn][2] >= setnob[n].needtok_red)
            condition++;
        if (_card_discount[turn][3] >= setnob[n].needtok_brown)
            condition++;
        if (_card_discount[turn][4] >= setnob[n].needtok_green)
            condition++;
        if (condition == 5)
            select_card[n] = n + 1;
    }
    printf("You can select nobility-card. [");
    for (int i = 0; i < 5; i++)
    {
        if (select_card[i] != 0)
        {
            printf(" %d, ", select_card[i]);
        }
    }
    printf(" ]\n Which card do you want to choose? ");
    scanf_s("%d", &choose);

    for (int n = 0; n < players + 1; n++)
    {
        if (select_card[n] > 0 & select_card[n + 1] > 0)
        {
            printf("You can select nobility-card. [");
            for (int i = 0; i < 5; i++)
            {
                if (select_card[i] != 0)
                {
                    printf(" %d ", select_card[i]);
                }
            }
            printf(" ]\n Which card do you want to choose? ");
            scanf_s("%d", &choose);
        }
    }

    _gameplayers[turn][6] = _gameplayers[turn][6] + setnob[choose].score;
    _card_discount[turn][5]++;
    return choose;
}

int check_score(int* _gameplayers[][7], int players, int turn)
{
    // 매턴마다 플레이어가 15점이상 모았는지 확인후 있으면 그 바퀴를 마지막으로 게임 종료(마지막 바퀴인걸 출력해줌, 만약 같은 점수가 있을시 카드 개수가 더 작은 사람이 승리)
    if (_gameplayers[turn][6] >= 15)
    {
        printf("Player%d's score is %d.\n This is last turn\n", turn, _gameplayers[turn][6]);
        return 1;
    }
    else
    {
        return 0;
    }
}

void print_map(int players, int gameplayers[][7], Card* blue, Card* orange, Card* green, Card* nob, int* totaltok, int* emtycard)
{
    // 매 턴마다 카드 세팅 상황을 시각화해줌   
    printf("-------------귀족카드-----------------\n");
    for (int n = 0; n < players + 1; n++)
    {
        printf("     *    |");
    }
    printf("\n");
    for (int n = 0; n < players + 1; n++)
    {
        printf("  점수 %d  |", nob[n].score);
    }
    printf("\n");
    for (int n = 0; n < players + 1; n++)
    {
        printf("흰파빨갈초|");
    }
    printf("\n");
    for (int n = 0; n < players + 1; n++)
    {
        printf("%d %d %d %d %d |", nob[n].needtok_white, nob[n].needtok_blue, nob[n].needtok_red, nob[n].needtok_brown, nob[n].needtok_green);
    }
    printf("\n");
    printf("-------------개발카드(초록)-----------------\n");
    printf("남은 초록 |");
    int card_number = 1;
    for (int n = 0; n < 4; n++)
    {
        printf("  (%2d)-%s   |", card_number++, green[n].card_type);
    }
    printf("\n");
    printf(" %2d장     |", emtycard[2]);
    for (int n = 0; n < 4; n++)
    {
        printf("  점수 %d  |", green[n].score);
    }
    printf("\n");
    printf("          ");
    for (int n = 0; n < 4; n++)
    {
        printf("|");
        printf("흰파빨갈초");
    }
    printf("|");
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("%d %d %d %d %d |", green[n].needtok_white, green[n].needtok_blue, green[n].needtok_red, green[n].needtok_brown, green[n].needtok_green);
    }
    printf("\n");

    printf("-------------개발카드(주황)-----------------\n");
    printf("남은 주황 |");
    for (int n = 0; n < 4; n++)
    {
        printf("  (%2d)-%s   |", card_number++, orange[n].card_type);
    }
    printf("\n");
    printf(" %2d장     |", emtycard[1]);
    for (int n = 0; n < 4; n++)
    {
        printf("  점수 %d  |", orange[n].score);
    }
    printf("\n");
    printf("          ");
    for (int n = 0; n < 4; n++)
    {
        printf("|");
        printf("흰파빨갈초");
    }
    printf("|");
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("%d %d %d %d %d |", orange[n].needtok_white, orange[n].needtok_blue, orange[n].needtok_red, orange[n].needtok_brown, orange[n].needtok_green);
    }
    printf("\n");

    printf("-------------개발카드(파랑)-----------------\n");
    printf("남은 파랑 |");
    for (int n = 0; n < 4; n++)
    {
        printf("  (%2d)-%s   |", card_number++, blue[n].card_type);
    }
    printf("\n");
    printf(" %2d장     |", emtycard[0]);
    for (int n = 0; n < 4; n++)
    {
        printf("  점수 %d  |", blue[n].score);
    }
    printf("\n");
    printf("          ");
    for (int n = 0; n < 4; n++)
    {
        printf("|");
        printf("흰파빨갈초");
    }
    printf("|");
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("%d %d %d %d %d |", blue[n].needtok_white, blue[n].needtok_blue, blue[n].needtok_red, blue[n].needtok_brown, blue[n].needtok_green);
    }
    printf("\n");

    printf("-------------남은 토큰-----------------\n");
    printf("흰(%d개) 갈(%d개) 빨(%d개) 파(%d개) 초(%d개)\n", totaltok[0], totaltok[1], totaltok[2], totaltok[3], totaltok[4]);

    printf("------------플레이어 상황-----------------\n");
    for (int n = 0; n < players; n++)
    {
        printf("  -player%d- |", n);
    }
    printf("\n");
    for (int n = 0; n < players; n++)
    {
        printf("  점수: %2d  |", gameplayers[n][6]);
    }
    printf("\n");
    for (int n = 0; n < players; n++)
    {
        printf("흰파빨갈초골|");
    }
    printf("\n");
    for (int n = 0; n < players; n++)
    {
        printf("%d %d %d %d %d %d |", gameplayers[n][0], gameplayers[n][1], gameplayers[n][2], gameplayers[n][3], gameplayers[n][4], gameplayers[n][5]);
    }
    printf("\n");


}
int put_card(Card* blue, Card* orange, Card* green, Card* mixblue, Card* mixorange, Card* mixgreen, int choice)   // 개발카드를 사면 그자리에 새로운 개발카드를 깔아주는 함수
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
    Card blue[40] = {
       {"brown",0,1,1,1,1,0},{"white",0,0,0,2,1,0},{"white",0,3,1,0,1,0},{"white",0,0,3,0,0,0},{"white",0,0,1,1,1,2},
       {"red",1,4,0,0,0,0},{"blue",0,1,0,2,0,2},{"green",0,1,1,1,2,0},{"red",0,1,0,1,3,0},{"blue",0,0,1,1,0,3},
       {"blue",0,1,0,1,1,1},{"blue",0,0,0,0,2,2},{"brown",1,0,4,0,0,0},{"brown",0,2,2,1,0,0},{"brown",0,0,1,0,0,1},
       {"blue",0,0,0,0,3,0},{"red",0,2,1,0,1,1},{"green",0,1,1,1,1,0},{"white",0,0,2,0,2,0},{"brown",0,0,0,3,1,1},
       {"brown",0,1,2,1,0,1},{"green",0,1,3,0,0,1},{"green",0,2,1,0,0,0},{"blue",0,1,0,2,1,1},{"red",0,2,0,0,2,1},
       {"red",0,2,0,2,0,0},{"brown",0,0,0,1,0,2},{"brown",0,2,0,0,0,2},{"red",0,0,2,0,0,1},{"white",1,0,0,0,0,4},
       {"blue",0,1,0,0,2,0},{"blue",1,0,0,4,0,0},{"green",0,0,0,3,0,0},{"green",0,0,1,2,2,0},{"red",0,1,1,0,1,1},
       {"white",0,0,2,0,1,2},{"white",0,0,1,1,1,1},{"red",0,3,0,0,0,0},{"green",0,0,2,2,0,0},{"green",1,0,0,0,4,0} };          // 입력 넣어야 될 카드들
    Card orange[30] = { 0 };
    //                 TYPE  S  W  B  R  Br G   
    Card nob[10] = { { "\0", 3, 0, 3, 3, 0, 3 },
                     { "\0", 3, 3, 0, 3, 3, 0 },
                     { "\0", 3, 3, 3, 0, 0, 3 },
                     { "\0", 3, 0, 0, 3, 3, 3 },
                     { "\0", 3, 3, 3, 0, 3, 0 },
                     { "\0", 3, 0, 0, 4, 0, 4 },
                     { "\0", 3, 0, 4, 0, 0, 4 },
                     { "\0", 3, 4, 4, 0, 0, 0 },
                     { "\0", 3, 0, 0, 4, 4, 0 },
                     { "\0", 3, 4, 0, 0, 4, 0 },
    };
    //                    TYPE   S  W  B  R  Br G
    Card green[20] = { { "brown", 3, 3, 3, 3, 0, 5 },
                       { "brown", 4, 0, 0, 7, 0, 0 },
                       { "brown", 4, 0, 0, 6, 3, 3 },
                       { "brown", 5, 0, 0, 7, 3, 0 },
                       { "blue", 3, 3, 0, 3, 5, 3 },
                       { "blue", 4, 7, 0, 0, 0, 0 },
                       { "blue", 4, 6, 3, 0, 3, 0 } ,
                       { "blue", 5, 7, 3, 0, 0, 0 },
                       { "green", 3, 5, 3, 3, 3, 0 },
                       { "green", 4, 3, 6, 0, 0, 3 },
                       { "green", 4, 0, 7, 0, 0, 0 },
                       { "green", 5, 0, 7, 0, 0, 3 },
                       { "red", 3, 3, 5, 0, 3, 3 },
                       { "red", 4, 0, 0, 0, 0, 7 },
                       { "red", 4, 0, 3, 3, 0, 6 },
                       { "red", 5, 0, 0, 3, 0, 7 },
                       { "white", 3, 0, 3, 5, 3, 3 },
                       { "white", 4, 0, 0, 0, 7, 0 },
                       { "white", 4, 3, 0, 3, 6, 0 },
                       { "white", 5, 3, 0, 0, 7, 0 },
    };
 

    int players, choice;
    int gameplayers[4][7] = { 0 };  //최대 게임 인원수와 보석(6개),점수를 나타낸 2차원 배열
    int card_discount[4][6] = { 0 };  // 플레이어별 카드(개발,귀족)로 인한 할인 
    int totaltok[6] = { 0,0,0,0,0,999 };  // 게임에 깔려져 있는 남은 토큰 개수
    int tok = { 0 };                    // 인원수에 따라 각 토큰 개수를 나타내는 변수
    int emtycard[3] = { 36,26,16 };      // 게임에 깔려져 있는 남은 카드 개수

    Card mixblue[40] = { 0 };            // 카드를 섞어서 배열
    Card mixorange[30] = { 0 };
    Card mixgreen[20] = { 0 };
    Card mixnob[10] = { 0 };


    printf("SPLENDER\n");

    for(;;)
    {
        printf("몇 명에서 하실 건가요?(2~4인용 게임): ");
        scanf_s("%d", &players);
        if (players == 1)
            printf("최소 플레이어는 2명입니다.\n");


        if (players == 2)
        {
            tok = 4;             // 인원수에 따라 토큰 개수를 정함
            break;
        }
        else if (players == 3)
        {
            tok = 5;
            break;
        }
        else
        {
            tok = 7;
            break;
        }
    }
    for (int n = 0; n < 5; n++)
        totaltok[n] = tok;

    srand(time(NULL));

    //랜덤으로 카드배열을 함 
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
        int check[30] = { 0 };
        while (1) {
            int k = rand() % 30;
            if (check[k] == 0) {
                mixorange[n] = orange[k];
                check[k] = 1;
                break;
            }
        }
    }
    for (int n = 0; n < 20; n++)
    {
        int check[20] = { 0 };
        while (1) {
            int k = rand() % 20;
            if (check[k] == 0) {
                mixgreen[n] = green[k];
                check[k] = 1;
                break;
            }
        }
    }
    for (int n = 0; n < 10; n++)
    {
        int check[10] = { 0 };
        while (1) {
            int k = rand() % 10;
            if (check[k] == 0) {
                mixnob[n] = nob[k];
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

    // 랜덤으로 배열한 카드중 게임에 펼칠 카드 4개를 나타내는 배열
    Card setblue[4] = { mixblue[0],mixblue[1],mixblue[2],mixblue[3] };
    Card setorange[4] = { mixorange[0],mixorange[1],mixorange[2],mixorange[3] };
    Card setgreen[4] = { mixgreen[0],mixgreen[1],mixgreen[2],mixgreen[3] };
    Card setnob[5] = { mixnob[0],mixnob[1],mixnob[2],mixnob[3],mixnob[4] };
    int com_card[5] = { 0 }; // 점수가 같을 때 개발 카드 개수 비교

    while (1)              /* 게임이 끝날때까지 턴이 반복*/
    {
        for (int n = 0; n < players; n++)
        {
            print_map(players, gameplayers, setblue, setorange, setgreen, setnob, totaltok, emtycard);   // 매턴마다 게임판을 보여줌
            printf("----------------player%d turn----------------\n", n);
            printf("*선택*\n1.서로 다른 색깔의 보석 토큰 3개 가져오기\n2.같은 색깔의 보석 토큰 2개 가져오기\n3.개발 카드 구매하기\n4.개발 카드 예약하기\n");
            scanf_s("%d", &choice);              // 플레이어가 1~4중에서 선택을함
            switch (choice)
            {
            case 1:
                choice1(gameplayers, totaltok, n);
                break;
            case 2:
                choice2(gameplayers, totaltok, n);
                break;
            case 3:
            {
                int number = choice3(gameplayers[players], card_discount[players]);      // 개발 카드 산 번호를 return 한다
                int changecard = put_card(blue, orange, green, mixblue, mixorange, mixgreen, number);  // 그 번호에  새로운 카드를 넣어주고, 무슨 종류의 카드인지 번호로 return한다. 
                emtycard[changecard]--;                                                     // 번호를 받아 그 색깔의 남은 카드를 하나 줄인다.
                break;
            }

            case 4:
                choice4(gameplayers[players]);
                break;
            }
            rule(gameplayers, card_discount, players, n, setnob);      // 매턴마다 룰을 적용시킨다.
            if (check_score(gameplayers, players, n) == 1)             // 마지막 턴일 때!!!!
            {
                while (n <= players)
                {
                    print_map(players, gameplayers, setblue, setorange, setgreen, setnob, totaltok, emtycard);   // 매턴마다 게임판을 보여줌
                    printf("----------------player%d turn----------------\n", n);
                    printf("*선택*\n1.서로 다른 색깔의 보석 토큰 3개 가져오기\n2.같은 색깔의 보석 토큰 2개 가져오기\n3.개발 카드 구매하기\n4.개발 카드 예약하기\n");
                    scanf_s("%d", &choice);              // 플레이어가 1~4중에서 선택을함
                    switch (choice)
                    {
                    case 1:
                        choice1(gameplayers, totaltok, n);
                        break;
                    case 2:
                        choice2(gameplayers, totaltok, n);
                        break;
                    case 3:
                    {
                        int number = choice3(gameplayers[players], card_discount[players]);      // 개발 카드 산 번호를 return 한다
                        int changecard = put_card(blue, orange, green, mixblue, mixorange, mixgreen, number);  // 그 번호에  새로운 카드를 넣어주고, 무슨 종류의 카드인지 번호로 return한다. 
                        emtycard[changecard]--;                                                     // 번호를 받아 그 색깔의 남은 카드를 하나 줄인다.
                        break;
                    }

                    case 4:
                        choice4(gameplayers[players]);
                        break;
                    }
                    int i = 0;
                    n++;
                }
                break;
            }
        }
        break;
        for (int n = 0; n < 5; n++)
        {
            printf(" player%d : %d \n", n + 1, gameplayers[n][6]);
            int* max = gameplayers + (n * 7) + 6;
            if (max < gameplayers[n + 1][6])
            {
                max = gameplayers[n + 1][6];
            }
            else if (max == gameplayers[n + 1][6])
            {
                for (int i = 0; i < 5; i++)
                {
                    com_card[n] += card_discount[n][i];
                    com_card[n + 1] += card_discount[n + 1][i];
                }
                if (com_card[n] > com_card[n + 1])
                {
                    max = gameplayers[n][6];
                }
                else if (com_card[n] < com_card[n + 1])
                {
                    max = gameplayers[n + 1][6];
                }
            }
        }
    }
}