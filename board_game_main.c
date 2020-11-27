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

typedef struct card_nob {////귀족카드 구조체//////
    int score;
    int needcard_white;
    int needcard_blue;
    int needcard_red;
    int needcard_brown;
    int needcard_green;
}Card_nob;


int choice1(int gameplayers[][7], int* totaltok, int turn)  // 서로 다른 색깔의 보석 3개 가져오기
{
    char taketok1[6];//고르는 토큰 변수1
    char taketok2[6];//고르는 토큰 변수2
    char taketok3[6];//고르는 토큰 변수3
 
    printf("가져올 서로 다른 토큰 3개를 입력해주십시오.\n");
    scanf_s("%s", taketok1, 6);
    scanf_s("%s", taketok2, 6);
    scanf_s("%s", taketok3, 6);
    //중복하면 재귀함수를 활용하여 함수를 다시 불러옴
    if (strcmp(taketok1,taketok2)==0||strcmp(taketok1,taketok3)==0||strcmp(taketok2,taketok3)==0)
    {
        printf("\n똑같은 색깔의 보석은 가져갈 수 없습니다.\n\n");
        return choice1(gameplayers, totaltok, turn);
    }
    //해당하는 토큰을 플레이어에게 전달
    if (strcmp(taketok1,"white")==0||strcmp(taketok2,"white")==0|| strcmp(taketok3, "white") == 0)
    {
        totaltok[0]--;
        gameplayers[turn][0]++;
    }
    if (strcmp(taketok1, "blue") == 0 || strcmp(taketok2, "blue") == 0 || strcmp(taketok3, "blue") == 0)
    {
        totaltok[1]--;
        gameplayers[turn][1]++;
    }
    if (strcmp(taketok1, "red") == 0 || strcmp(taketok2, "red") == 0 || strcmp(taketok3, "red") == 0)
    {
        totaltok[2]--;
        gameplayers[turn][2]++;
    }
    if (strcmp(taketok1, "brown") == 0 || strcmp(taketok2, "brown") == 0 || strcmp(taketok3, "brown") == 0)
    {
        totaltok[3]--;
        gameplayers[turn][3]++;
    }
    if (strcmp(taketok1, "green") == 0 || strcmp(taketok2, "green") == 0 || strcmp(taketok3, "green") == 0)
    {
        totaltok[4]--;
        gameplayers[turn][4]++;
    }
    return 0;
}
int choice2(int gameplayers[][7], int* totaltok, int turn) // 같은 색깔의 보석 토큰 2개 가져오기
{
    char taketok[6] = { NULL };//토큰변수
    
    printf("4개 이상의 토큰만 2개를 가져올 수 있습니다.");
    scanf_s("%s", taketok,6);
    //3개 이하의 토큰을 고르면 재귀함수를 활용하여 함수를 다시불러옴
    if (totaltok[0] < 4 && strcmp(taketok,"white")==0)
    {
        printf("4개 이상의 토큰을 고르십시오.\n\n");
        return choice2(gameplayers, totaltok, turn);
    }
    if (totaltok[1] < 4 && strcmp(taketok, "blue") == 0)
    {
        printf("4개 이상의 토큰을 고르십시오.\n\n");
        return choice2(gameplayers, totaltok, turn);
    }
    if (totaltok[2] < 4 && strcmp(taketok, "red") == 0)
    {
        printf("4개 이상의 토큰을 고르십시오.\n\n");
        return choice2(gameplayers, totaltok, turn);
    }
    if (totaltok[3] < 4 && strcmp(taketok, "brown") == 0)
    {
        printf("4개 이상의 토큰을 고르십시오.\n\n");
        return choice2(gameplayers, totaltok, turn);
    }
    if (totaltok[4] < 4 && strcmp(taketok, "green") == 0)
    {
        printf("4개 이상의 토큰을 고르십시오.\n\n");
        return choice2(gameplayers, totaltok, turn);
    }
    //해당하는 토큰2개를 플레이어에게 전달
    if (strcmp(taketok, "white") == 0)
    {
        totaltok[0] -= 2;
        gameplayers[turn][0] += 2;
    }
    else if (strcmp(taketok, "blue") == 0)
    {
        totaltok[1] -= 2;
        gameplayers[turn][1] += 2;
    }
    else if (strcmp(taketok, "red") == 0)
    {
        totaltok[2] -= 2;
        gameplayers[turn][2] += 2;
    }
    else if (strcmp(taketok, "brown") == 0)
    {
        totaltok[3] -= 2;
        gameplayers[turn][3] += 2;
    }
    else if (strcmp(taketok, "green") == 0)
    {
        totaltok[4] -= 2;
        gameplayers[turn][4] += 2;
    }
    return 0;
    // 보석 토큰은 총 10개까지 보유, 색깔이 4개이상 남아있어야 2개 가져올 수 있음
}
int choice3(int gameplayers[][7], int card_discount[][5], Card* blue, Card* orange, Card* green, int turn, int* totaltok, Card keepcard[][20]) // 개발 카드 구매하기
{
    // 개발 카드에 표시된 만큼 토큰을 지불하여 카드를 구입한다
    // 개발 카드에 제공하는 보석만큼 할인
    int choice = 0;                // 매번 선택을 할때 받는 변수이다
    int lack[5] = { 0 };         // 각 토큰마다 부족한 양을 알기위한 배열이다
    int sumlack;                // 부족한 토큰의 합을 구하는 변수이다
    char colar[5][6] = { "white","blue","red","brown","green" };        // 사는 카드에 할인해주는 토큰의 색과 비교하기 위한 2차원 문자열 배열이다
    int check = 0;                 // 손에 들고있는 카드가 있나 확인해주는 함수이다
    for (int n = 0; n < 20; n++)          // 플레이어의 손에 있는 카드가 있나 스캔한다
    {
        if (keepcard[0][n].score != -1)   // 카드가 있을경우 check변수를 올려준다
            check++;
    }
    if (check > 0)             // check 변수가 양수일 경우 어디 있는 카드를 살 것인지 선택권을 준다
    {
        while (1) {                           // 1,2중에 선택을 받아 카드를 구매할 수있게 해주는 무한반복문 
            printf("어떤 카드를 구매하시겠습니까? 1. 손에 있는 카드 2. 깔려 있는 카드\n");
            scanf_s("%d", &choice);
            if (choice == 1 || choice == 2)         // 1,2 이외에 다른 숫자를 입력하면 다시 입력하게 해주는 if문
                break;
            printf("잘못 입력하셨습니다\n");
        }
    }
    if (choice == 1)               // 만약 손에 있는 카드를 사겠다고 결정을 했을 때
    {
        int n1;
        while (1)             // 살 수 있는 카드를 고를 때 까지 반복되는 무한 반복문
        {
            int count = 0;    // 손에 있는 카드가 몇개인지 새기 위한 변수
            sumlack = 0;      // 부족한 토큰의 합
            printf("몇 번째 카드를 구입하시겠습니까? (0 : back)");
            scanf_s("%d", &choice);
            if (choice == 0)                                    // 다시 선택 창으로 돌아 갈 때
            {
                return -1;
            }
            for (n1 = 0; n1 < 20; n1++)  // 손에 카드가 있는지 스캔한다
            {
                if (keepcard[0][n1].score != -1)  // 있으면 카운트를 증가시킨다
                    count++;
                if (count == choice) // 카운트랑 내가 고른 숫자랑 같아질 경우 반복문을 나간다
                    break;
            }


            lack[0] = (keepcard[turn][n1].needtok_white - card_discount[turn][0]) - gameplayers[turn][0];  // 그 위치에있는 손의 카드의 정보를 받아 그 카드를 살 때 각각 부족한 토큰을 구한다(황금토큰 사용을 위해)
            lack[1] = (keepcard[turn][n1].needtok_blue - card_discount[turn][1]) - gameplayers[turn][1];
            lack[2] = (keepcard[turn][n1].needtok_red - card_discount[turn][2]) - gameplayers[turn][2];
            lack[3] = (keepcard[turn][n1].needtok_brown - card_discount[turn][3]) - gameplayers[turn][3];
            lack[4] = (keepcard[turn][n1].needtok_green - card_discount[turn][4]) - gameplayers[turn][4];

            for (int n = 0; n < 5; n++)  // 부족한 토큰 들의 합을 구한다
                if (lack[n] > 0)              // 음수(토큰+할인이 더 큼)면 굳이 포함시킬 필요가 없으므로 양수만 더해준다
                    sumlack += lack[n];

            if (sumlack <= gameplayers[turn][5])  // 부족한 토큰의 합이 플레이어의 황금토큰보다 적으면 반복문에서 나간다.
                break;
        }

        if (keepcard[turn][n1].needtok_white > 0 && keepcard[turn][n1].needtok_white > card_discount[turn][0]) {            // 사기위해 필요한 토큰의 색이 양수이고, 필요토큰보다 할인토큰이 적을 때 플레이어 토큰은 쓴만큼 지불, 토탈 토큰은 쓴만큼 추가되는 if문이다 
            gameplayers[turn][0] -= (keepcard[turn][n1].needtok_white - card_discount[turn][0]);
            totaltok[0] += keepcard[turn][n1].needtok_white - card_discount[turn][0];
        }
        if (keepcard[turn][n1].needtok_blue > 0 && keepcard[turn][n1].needtok_blue - card_discount[turn][1]) {
            gameplayers[turn][1] -= (keepcard[turn][n1].needtok_blue - card_discount[turn][1]);
            totaltok[1] += keepcard[turn][n1].needtok_blue - card_discount[turn][1];
        }
        if (keepcard[turn][n1].needtok_red > 0 && keepcard[turn][n1].needtok_red - card_discount[turn][2]) {
            gameplayers[turn][2] -= (keepcard[turn][n1].needtok_red - card_discount[turn][2]);
            totaltok[2] += keepcard[turn][n1].needtok_red - card_discount[turn][2];
        }
        if (keepcard[turn][n1].needtok_brown > 0 && keepcard[turn][n1].needtok_brown - card_discount[turn][3]) {
            gameplayers[turn][3] -= (keepcard[turn][n1].needtok_brown - card_discount[turn][3]);
            totaltok[3] += keepcard[turn][n1].needtok_brown - card_discount[turn][3];
        }
        if (keepcard[turn][n1].needtok_green > 0 && keepcard[turn][n1].needtok_green - card_discount[turn][4]) {
            gameplayers[turn][4] -= (keepcard[turn][n1].needtok_green - card_discount[turn][4]);
            totaltok[4] += keepcard[turn][n1].needtok_green - card_discount[turn][4];
        }

        for (int n = 0; n < 5; n++)            // 골드 토큰을 써서 음수가 된 토큰을 원상복귀 해주기 위해 음수가 된 토큰이 0이 될때까지 쓴 골드 토큰만큼 골드토큰을 1씩 빼주고 음수가된 색의 토큰은 1씩 더해주는 반복문이다
        {
            while (gameplayers[turn][n] < 0)
            {
                if (gameplayers[turn][n] == 0)
                    break;
                gameplayers[turn][n]++;
                totaltok[n]--;
                totaltok[5]++;
            }
        }

        gameplayers[turn][5] -= sumlack;        // 부족한 토큰 개수만큼 플레이어의 골드 토큰을 빼준다.

        for (int n = 0; n < 5; n++) {                    // 카드에 종류에 따른 플레이어의 할인을 1증가시켜주고 카드 점수만큼 점수를 올려준다
            if (strcmp(keepcard[turn][n1].card_type, colar[n]) == 0) {
                card_discount[turn][n]++;
                gameplayers[turn][6] += keepcard[turn][n1].score;
            }
        }
        keepcard[turn][n1].score = -1;           // 이제 손에 없기 때문에 맵에서 사라지게 하기위해 점수를 -1로 만들어준다
        return 0;
    }

    else {
        while (1)
        {
            sumlack = 0;
            printf("구입할 개발카드의 숫자를 입력하시오(0 : back)");
            scanf_s("%d", &choice);
            if (choice == 0)                                    // 다시 선택 창으로 돌아 갈 때
            {
                return -1;
            }
            else if (0 < choice && choice < 5) {                  // 무슨 색의 개발카드냐에 따라 나뉘어서 부족한 토큰의 개수를 구한다
                lack[0] = (green[choice - 1].needtok_white - card_discount[turn][0]) - gameplayers[turn][0];
                lack[1] = (green[choice - 1].needtok_blue - card_discount[turn][1]) - gameplayers[turn][1];
                lack[2] = (green[choice - 1].needtok_red - card_discount[turn][2]) - gameplayers[turn][2];
                lack[3] = (green[choice - 1].needtok_brown - card_discount[turn][3]) - gameplayers[turn][3];
                lack[4] = (green[choice - 1].needtok_green - card_discount[turn][4]) - gameplayers[turn][4];
            }
            else if (4 < choice && choice < 9) {
                lack[0] = (orange[choice - 5].needtok_white - card_discount[turn][0]) - gameplayers[turn][0];
                lack[1] = (orange[choice - 5].needtok_blue - card_discount[turn][1]) - gameplayers[turn][1];
                lack[2] = (orange[choice - 5].needtok_red - card_discount[turn][2]) - gameplayers[turn][2];
                lack[3] = (orange[choice - 5].needtok_brown - card_discount[turn][3]) - gameplayers[turn][3];
                lack[4] = (orange[choice - 5].needtok_green - card_discount[turn][4]) - gameplayers[turn][4];
            }
            else {
                lack[0] = (blue[choice - 9].needtok_white - card_discount[turn][0]) - gameplayers[turn][0];
                lack[1] = (blue[choice - 9].needtok_blue - card_discount[turn][1]) - gameplayers[turn][1];
                lack[2] = (blue[choice - 9].needtok_red - card_discount[turn][2]) - gameplayers[turn][2];
                lack[3] = (blue[choice - 9].needtok_brown - card_discount[turn][3]) - gameplayers[turn][3];
                lack[4] = (blue[choice - 9].needtok_green - card_discount[turn][4]) - gameplayers[turn][4];
            }
            for (int n = 0; n < 5; n++)                // 부족한 토큰의 개수의 합
                if (lack[n] > 0)                      // 음수면 남는 것이기에 양수만 더해준다
                    sumlack += lack[n];

            if (sumlack <= gameplayers[turn][5])            // 골드 토큰이 부족한 토큰의 합보다 작지않으면 무한반복문에서 나간다 
                break;
        }

        if (0 < choice && choice < 5 && green[choice - 1].needtok_white > card_discount[turn][0]) {                    // 사기위해 필요한 토큰의 색이 양수이고, 필요토큰보다 할인토큰이 적을 때 플레이어 토큰은 쓴만큼 지불, 토탈 토큰은 쓴만큼 추가되는 if문이다 
            if (green[choice - 1].needtok_white > 0) {
                gameplayers[turn][0] -= (green[choice - 1].needtok_white - card_discount[turn][0]);
                totaltok[0] += green[choice - 1].needtok_white - card_discount[turn][0];
            }
            if (green[choice - 1].needtok_blue > 0 && green[choice - 1].needtok_blue > card_discount[turn][1]) {
                gameplayers[turn][1] -= (green[choice - 1].needtok_blue - card_discount[turn][1]);
                totaltok[1] += green[choice - 1].needtok_blue - card_discount[turn][1];
            }
            if (green[choice - 1].needtok_red > 0 && green[choice - 1].needtok_red > card_discount[turn][2]) {
                gameplayers[turn][2] -= (green[choice - 1].needtok_red - card_discount[turn][2]);
                totaltok[2] += green[choice - 1].needtok_red - card_discount[turn][2];
            }
            if (green[choice - 1].needtok_brown > 0 && green[choice - 1].needtok_brown > card_discount[turn][3]) {
                gameplayers[turn][3] -= (green[choice - 1].needtok_brown - card_discount[turn][3]);
                totaltok[3] += green[choice - 1].needtok_brown - card_discount[turn][3];
            }
            if (green[choice - 1].needtok_green > 0 && green[choice - 1].needtok_green > card_discount[turn][4]) {
                gameplayers[turn][4] -= (green[choice - 1].needtok_green - card_discount[turn][4]);
                totaltok[4] += green[choice - 1].needtok_green - card_discount[turn][4];
            }
        }
        else if (4 < choice && choice < 9) {
            if (orange[choice - 5].needtok_white > 0 && orange[choice - 5].needtok_white > card_discount[turn][0]) {
                gameplayers[turn][0] -= (orange[choice - 5].needtok_white - card_discount[turn][0]);
                totaltok[0] += orange[choice - 5].needtok_white - card_discount[turn][0];
            }
            if (orange[choice - 5].needtok_blue > 0 && orange[choice - 5].needtok_blue > card_discount[turn][1]) {
                gameplayers[turn][1] -= (orange[choice - 5].needtok_blue - card_discount[turn][1]);
                totaltok[1] += orange[choice - 5].needtok_blue - card_discount[turn][1];
            }
            if (orange[choice - 5].needtok_red > 0 && orange[choice - 5].needtok_red > card_discount[turn][2]) {
                gameplayers[turn][2] -= (orange[choice - 5].needtok_red - card_discount[turn][2]);
                totaltok[2] += orange[choice - 5].needtok_red - card_discount[turn][2];
            }
            if (orange[choice - 5].needtok_brown > 0 && orange[choice - 5].needtok_brown > card_discount[turn][3]) {
                gameplayers[turn][3] -= (orange[choice - 5].needtok_brown - card_discount[turn][3]);
                totaltok[3] += orange[choice - 5].needtok_brown - card_discount[turn][3];
            }
            if (orange[choice - 5].needtok_green > 0 && orange[choice - 5].needtok_green > card_discount[turn][4]) {
                gameplayers[turn][4] -= (orange[choice - 5].needtok_green - card_discount[turn][4]);
                totaltok[4] += orange[choice - 5].needtok_green - card_discount[turn][4];
            }
        }
        else {
            if (blue[choice - 9].needtok_white > 0 && blue[choice - 9].needtok_white > card_discount[turn][0]) {
                gameplayers[turn][0] -= (blue[choice - 9].needtok_white - card_discount[turn][0]);
                totaltok[0] += blue[choice - 9].needtok_white - card_discount[turn][0];
            }
            if (blue[choice - 9].needtok_blue > 0 && blue[choice - 9].needtok_blue > card_discount[turn][1]) {
                gameplayers[turn][1] -= (blue[choice - 9].needtok_blue - card_discount[turn][1]);
                totaltok[1] += blue[choice - 9].needtok_blue - card_discount[turn][1];
            }
            if (blue[choice - 9].needtok_red > 0 && blue[choice - 9].needtok_red > card_discount[turn][2]) {
                gameplayers[turn][2] -= (blue[choice - 9].needtok_red - card_discount[turn][2]);
                totaltok[2] += blue[choice - 9].needtok_red - card_discount[turn][2];
            }
            if (blue[choice - 9].needtok_brown > 0 && blue[choice - 9].needtok_brown > card_discount[turn][3]) {
                gameplayers[turn][3] -= (blue[choice - 9].needtok_brown - card_discount[turn][3]);
                totaltok[3] += blue[choice - 9].needtok_brown - card_discount[turn][3];
            }
            if (blue[choice - 9].needtok_green > 0 && blue[choice - 9].needtok_green > card_discount[turn][4]) {
                gameplayers[turn][4] -= (blue[choice - 9].needtok_green - card_discount[turn][4]);
                totaltok[4] += blue[choice - 9].needtok_green - card_discount[turn][4];
            }
        }



        for (int n = 0; n < 5; n++)                    // 골드 토큰을 써서 음수가 된 토큰을 원상복귀 해주기 위해 음수가 된 토큰이 0이 될때까지 쓴 골드 토큰만큼 골드토큰을 1씩 빼주고 음수가된 색의 토큰은 1씩 더해주는 반복문이다
        {
            while (gameplayers[turn][n] < 0)
            {
                if (gameplayers[turn][n] == 0)
                    break;
                gameplayers[turn][n]++;
                totaltok[n]--;
                totaltok[5]++;
            }
        }

        gameplayers[turn][5] -= sumlack;                  // 부족한 토큰 개수만큼 플레이어의 골드 토큰을 빼준다.
        if (0 < choice && choice < 5) {                       // 카드에 종류에 따른 플레이어의 할인을 1증가시켜주고 카드 점수만큼 점수를 올려준다
            for (int n = 0; n < 5; n++) {
                if (strcmp(green[choice - 1].card_type, colar[n]) == 0) {
                    card_discount[turn][n]++;
                    gameplayers[turn][6] += green[choice - 1].score;
                }
            }
        }
        else if (4 < choice && choice < 9) {
            for (int n = 0; n < 5; n++) {
                if (strcmp(orange[choice - 5].card_type, colar[n]) == 0) {
                    card_discount[turn][n]++;
                    gameplayers[turn][6] += orange[choice - 5].score;
                }
            }
        }
        else {
            for (int n = 0; n < 5; n++) {
                if (strcmp(blue[choice - 9].card_type, colar[n]) == 0) {
                    card_discount[turn][n]++;
                    gameplayers[turn][6] += blue[choice - 9].score;
                }
            }
        }
    }

    return choice;
}
int choice4(int gameplayers[][7], int turn, Card keepcard[][20], Card* blue, Card* orange, Card* green, int* totaltok) // 개발카드 예약하기(with 황금토큰)
{
    // 개발 카드를 구매할 수 없지만, 추후 구매를 희망하면 해당카드를 가져와 보관
    // 황금토큰도 함께 가져온다
    int choice = 0;
    static int n[4] = { 0 };

    printf("예약할 개발카드의 숫자를 입력하시오(0 : back) ");
    scanf_s("%d", &choice);
    if (choice == 0)                                                      // 다시 선택창으로 돌아가는 if문이다
    {
        return -1;
    }
    else if (0 < choice && choice < 5) {                                         // 카드를 보관함
        keepcard[turn][n[turn]++] = green[choice - 1];
    }
    else if (4 < choice && choice < 9) {
        keepcard[turn][n[turn]++] = orange[choice - 5];
    }
    else {
        keepcard[turn][n[turn]++] = blue[choice - 9];
    }
    if (totaltok[5] > 0) {                                         //골드 토큰이 있을때 골드 토큰을 추가로 받음
        gameplayers[turn][5]++;
        totaltok[5]--;
    }

    return choice;                                        // 선택한 개발 카드의 번호를 반환한다
}
int rule(int gameplayers[][7], int card_discount[][5], int user_have_nob[], int players, int turn, Card_nob* setnob) ////바뀜
{
    // 귀족 카드 조건이되면 귀족 카드를 얻음 ( 만약 여러개면 선택을 할 수 있게 해줌 and 귀족방문는 한번만 가능)
    int condition = 0;
    int select_card[5] = { 0 }; // 고를 수 있는 귀족 카드가 여러 개일 경우 고를 수 있도록 번호 제공
    int choose = 0;
    if (user_have_nob[turn] == 1)
    {
        printf("You already have nobility-card. \n");
        return -1;
    }
    else {
        for (int n = 0; n < players + 1; n++)
        {
            if (card_discount[turn][0] >= setnob[n].needcard_white)
                condition++;
            if (card_discount[turn][1] >= setnob[n].needcard_blue)
                condition++;
            if (card_discount[turn][2] >= setnob[n].needcard_red)
                condition++;
            if (card_discount[turn][3] >= setnob[n].needcard_brown)
                condition++;
            if (card_discount[turn][4] >= setnob[n].needcard_green)
                condition++;
            if (condition == 5)
            {
                select_card[n] = n + 1;
                printf("You can select nobility-card. [");
            }
            else
            {
                return -1;
            }
        }

        for (int n = 0; n < players + 1; n++)
        {
            if (select_card[n] != 0)
            {
                printf(" %d ", select_card[n]);
            }
        }
        printf(" ]\n Which card do you want to choose? ");
        scanf_s("%d", &choose);

        gameplayers[turn][6] = gameplayers[turn][6] + setnob[choose].score;
        user_have_nob[turn]++;
        return choose;
    }
}
int check_score(int gameplayers[][7], int turn)
{
    // 매턴마다 플레이어가 15점이상 모았는지 확인후 있으면 그 바퀴를 마지막으로 게임 종료(마지막 바퀴인걸 출력해줌, 만약 같은 점수가 있을시 카드 개수가 더 작은 사람이 승리)
    if (gameplayers[turn][6] >= 15)
    {
        printf("\n\n\nPlayer%d's score is %d.\n This is last turn\n\n\n", turn + 1, gameplayers[turn][6]);
        return 1;
    }
    else
    {
        return 0;
    }
}


void print_map(int players, int gameplayers[][7], Card* blue, Card* orange, Card* green, Card_nob* nob, int* totaltok, int* emtycard, int card_discount[][5], Card keepcard[][20], int turn)
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
        printf("  점수 %d  |", nob[players].score);
    }
    printf("\n");
    for (int n = 0; n < players + 1; n++)
    {
        printf("흰파빨갈초|");
    }
    printf("\n");
    for (int n = 0; n < players + 1; n++)
    {
        printf("%d %d %d %d %d |", nob[n].needcard_white, nob[n].needcard_blue, nob[n].needcard_red, nob[n].needcard_brown, nob[n].needcard_green);
    }
    printf("\n");
    printf("-------------개발카드(초록)-----------------                       ---------------------손에 있는 카드-------------------\n");
    printf("남은 초록 |");
    int card_number = 1;
    int keep_number = 1;
    for (int n = 0; n < 4; n++)
    {
        printf("(%2d)-%5s|", card_number++, green[n].card_type);
    }
    printf("         player%d|", turn + 1);
    for (int n = 0; n < 20; n++)
    {
        if (keepcard[0][n].score != 10 && keepcard[0][n].score != -1)
            printf("(%2d)-%5s|", keep_number++, keepcard[turn][n].card_type);
    }
    printf("\n");
    printf(" %2d장     |", emtycard[2]);
    for (int n = 0; n < 4; n++)
    {
        printf("  점수 %d  |", green[n].score);
    }
    printf("                |");
    for (int n = 0; n < 20; n++)
    {
        if (keepcard[0][n].score != 10 && keepcard[0][n].score != -1)
            printf("  점수 %d  |", keepcard[turn][n].score);
    }
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("흰파빨갈초|");
    }
    printf("                |");
    for (int n = 0; n < 20; n++)
    {
        if (keepcard[0][n].score != 10 && keepcard[0][n].score != -1)
            printf("흰파빨갈초|");
    }
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("%d %d %d %d %d |", green[n].needtok_white, green[n].needtok_blue, green[n].needtok_red, green[n].needtok_brown, green[n].needtok_green);
    }
    printf("                |");

    for (int n = 0; n < 20; n++) {
        if (keepcard[0][n].score != 10 && keepcard[0][n].score != -1)
            printf("%d %d %d %d %d |", keepcard[turn][n].needtok_white, keepcard[turn][n].needtok_blue, keepcard[turn][n].needtok_red, keepcard[turn][n].needtok_brown, keepcard[turn][n].needtok_green);
    }

    printf("\n");


    printf("-------------개발카드(주황)-----------------\n");
    printf("남은 주황 |");
    for (int n = 0; n < 4; n++)
    {
        printf("(%2d)-%5s|", card_number++, orange[n].card_type);
    }
    printf("\n");
    printf(" %2d장     |", emtycard[1]);
    for (int n = 0; n < 4; n++)
    {
        printf("  점수 %d  |", orange[n].score);
    }
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("흰파빨갈초|");
    }
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
        printf("(%2d)-%5s|", card_number++, blue[n].card_type);
    }
    printf("\n");
    printf(" %2d장     |", emtycard[0]);
    for (int n = 0; n < 4; n++)
    {
        printf("  점수 %d  |", blue[n].score);
    }
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("흰파빨갈초|");
    }
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("%d %d %d %d %d |", blue[n].needtok_white, blue[n].needtok_blue, blue[n].needtok_red, blue[n].needtok_brown, blue[n].needtok_green);
    }
    printf("\n");

    printf("-------------------남은 토큰--------------------------\n");
    printf("흰(%d개) 파(%d개) 빨(%d개) 갈(%d개) 초(%d개) 황(%d개)\n", totaltok[0], totaltok[1], totaltok[2], totaltok[3], totaltok[4], totaltok[5]);

    printf("------------플레이어 상황-----------------\n");
    for (int n = 0; n < players; n++)
    {
        printf("  -player%d- |", n + 1);
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
    printf("=>보유 토큰");
    printf("\n");
    for (int n = 0; n < players; n++)
    {
        printf("%d %d %d %d %d %d |", gameplayers[n][0], gameplayers[n][1], gameplayers[n][2], gameplayers[n][3], gameplayers[n][4], gameplayers[n][5]);
    }
    printf("\n");
    for (int n = 0; n < players; n++)
    {
        printf("흰파빨갈초  |");
    }
    printf("=>할인 토큰");
    printf("\n");
    for (int n = 0; n < players; n++)
    {
        printf("%d %d %d %d %d   |", card_discount[n][0], card_discount[n][1], card_discount[n][2], card_discount[n][3], card_discount[n][4]);
    }
    printf("\n");


}
int put_card(Card* blue, Card* orange, Card* green, Card* mixblue, Card* mixorange, Card* mixgreen, int choice)   // 개발카드를 사면 그자리에 새로운 개발카드를 깔아주는 함수
{
    static blue_count = 4;
    static orange_count = 4;
    static green_count = 4;
    if (0 < choice && choice < 5) {
        green[choice - 1] = mixgreen[green_count++];
        return 2;
    }
    else if (4 < choice && choice < 9) {
        orange[choice - 5] = mixorange[orange_count++];
        return 1;
    }
    else {
        blue[choice - 9] = mixblue[blue_count++];
        return 0;
    }

}

int main(void)
{
    //typedef struct card {                   // 카드 구조체
    //char card_type[10];
    //int score;                   //gameplayers[][6]
    //int needtok_white;           //gameplayers[][0]
    //int needtok_blue;            //gameplayers[][1]
    //int needtok_red;             //gameplayers[][2]
    //int needtok_brown;           //gameplayers[][3]
    //int needtok_green;           //gameplayers[][4]
    //}Card; 점수 흰색 파란색 빨간색 갈색 초록색
    Card blue[40] = {
       {"brown",0,1,1,1,1,0},{"white",0,0,0,2,1,0},{"white",0,3,1,0,1,0},{"white",0,0,3,0,0,0},{"white",0,0,1,1,1,2},
       {"red",1,4,0,0,0,0},{"blue",0,1,0,2,0,2},{"green",0,1,1,1,2,0},{"red",0,1,0,1,3,0},{"blue",0,0,1,1,0,3},
       {"blue",0,1,0,1,1,1},{"blue",0,0,0,0,2,2},{"brown",1,0,4,0,0,0},{"brown",0,2,2,1,0,0},{"brown",0,0,1,0,0,1},
       {"blue",0,0,0,0,3,0},{"red",0,2,1,0,1,1},{"green",0,1,1,1,1,0},{"white",0,0,2,0,2,0},{"brown",0,0,0,3,1,1},
       {"brown",0,1,2,1,0,1},{"green",0,1,3,0,0,1},{"green",0,2,1,0,0,0},{"blue",0,1,0,2,1,1},{"red",0,2,0,0,2,1},
       {"red",0,2,0,2,0,0},{"brown",0,0,0,1,0,2},{"brown",0,2,0,0,0,2},{"red",0,0,2,0,0,1},{"white",1,0,0,0,0,4},
       {"blue",0,1,0,0,2,0},{"blue",1,0,0,4,0,0},{"green",0,0,0,3,0,0},{"green",0,0,1,2,2,0},{"red",0,1,1,0,1,1},
       {"white",0,0,2,0,1,2},{"white",0,0,1,1,1,1},{"red",0,3,0,0,0,0},{"green",0,0,2,2,0,0},{"green",1,0,0,0,4,0} };          // 입력 넣어야 될 카드들
    Card orange[30] =
    {
        {"red",2,1,0,1,1,3},{"brown",2,1,0,2,1,1},{"white",3,2,1,2,1,0},{"red",2,0,1,0,3,1},{"green",1,2,1,0,0,1},
        {"blue",4,3,0,2,1,0},{"brown",3,0,0,4,0,1},{"green",4,0,0,1,4,1},{"red",2,1,0,0,2,2},{"white",4,0,4,0,1,2},
        {"red",2,1,0,1,1,3},{"green",2,0,1,1,0,3},{"white",4,0,0,5,0,0},{"blue",3,1,0,0,4,0},{"brown",2,0,3,0,0,1},
        {"blue",3,3,3,0,0,1},{"red",4,0,0,4,2,0},{"brown",3,0,0,0,0,5},{"blue",4,0,4,4,0,0},{"green",2,0,3,0,2,1},
        {"white",2,3,0,0,0,2},{"red",2,0,3,0,3,1},{"blue",2,1,2,1,1,3},{"white",5,0,2,0,5,1},{"blue",3,0,1,1,3,2},
        {"green",4,3,0,0,4,0},{"brown",2,0,3,4,0,0},{"white",3,0,4,0,2,1},{"brown",3,2,5,1,0,0},{"green",4,0,0,5,0,2}
    };
    Card green[20] = {
       {"white",3,0,3,5,3,3},{"green",4,3,6,0,0,3},{"white",4,3,0,3,6,0},{"blue",5,7,3,0,0,0},{"white",5,3,0,0,7,0},
       {"green",4,0,7,0,0,0},{"red",4,0,0,0,0,7},{"blue",4,7,0,0,0,0},{"blue",3,3,0,3,5,3},{"brown",4,0,0,3,6,3},
       {"brown",3,3,3,3,0,5},{"blue",4,6,3,0,3,0},{"green",3,5,3,3,3,0},{"red",3,3,5,0,3,3},{"brown",5,0,0,7,3,0},
       {"white",4,0,0,0,7,0},{"red",4,0,3,3,0,6},{"green",5,0,7,0,0,3},{"brown",4,0,7,0,0,0},{"red",5,0,0,3,0,7}
    };
    Card_nob nob[10] = {
      {3,0,0,4,0,4},{3,4,4,0,0,0},{3,0,0,4,4,0},{3,4,0,0,4,0},{3,0,4,0,0,4},
      {3,3,0,3,3,0},{3,0,0,3,3,3},{3,3,3,0,0,3},{3,0,3,3,0,3},{3,3,3,0,3,0}
    };


    srand(time(NULL));
    int players, choice;
    int gameplayers[4][7] = { 0 };  //최대 게임 인원수와 보석(6개),점수를 나타낸 2차원 배열
    int card_discount[4][5] = { 0 };  // 플레이어별 카드(개발,귀족)로 인한 할인 
    int totaltok[6] = { 0,0,0,0,0,5 };  // 게임에 깔려져 있는 남은 토큰 개수
    int tok = { 0 };                    // 인원수에 따라 각 토큰 개수를 나타내는 변수
    int emtycard[3] = { 36,26,16 };      // 게임에 깔려져 있는 남은 카드 개수
    int user_have_nob[5] = { 0 }; /////추가///////
    int checking = 0;


    Card mixblue[40] = { 0 };            // 카드를 섞어서 배열
    Card mixorange[30] = { 0 };
    Card mixgreen[20] = { 0 };
    Card_nob mixnob[10] = { 0 };

    Card keepcard[4][20] = { 0 };       // 4번 초이스로인한 보관한 카드
    for (int n = 0; n < 4; n++)
        for (int n1 = 0; n1 < 20; n1++)
            keepcard[n][n1].score = -1;

    printf("SPLENDER\n");
    printf("몇 명에서 하실 건가요?(2~4인용 게임)");
    scanf_s("%d", &players);

    if (players == 2) tok = 20;             // 인원수에 따라 토큰 개수를 정함
    else if (players == 3) tok = 5;
    else tok = 7;
    for (int n = 0; n < 5; n++)
        totaltok[n] = tok;

    //랜덤으로 카드배열을 함 
    int check0[40] = { 0 };
    for (int n = 0; n < 40; n++)
    {
        while (1) {
            int k = rand() % 40;
            if (check0[k] == 0) {
                mixblue[n] = blue[k];
                check0[k] = 1;
                break;
            }
        }
    }
    int check1[30] = { 0 };
    for (int n = 0; n < 30; n++)
    {
        while (1) {
            int k = rand() % 30;
            if (check1[k] == 0) {
                mixorange[n] = orange[k];
                check1[k] = 1;
                break;
            }
        }
    }
    int check2[20] = { 0 };
    for (int n = 0; n < 20; n++)
    {
        while (1) {
            int k = rand() % 20;
            if (check2[k] == 0) {
                mixgreen[n] = green[k];
                check2[k] = 1;
                break;
            }
        }
    }
    int check3[10] = { 0 };
    for (int n = 0; n < 10; n++)
    {
        while (1) {
            int k = rand() % 10;
            if (check3[k] == 0) {
                mixnob[n] = nob[k];
                check3[k] = 1;
                break;
            }
        }
    }


    // 랜덤으로 배열한 카드중 게임에 펼칠 카드 4개를 나타내는 배열
    Card setblue[4] = { mixblue[0],mixblue[1],mixblue[2],mixblue[3] };
    Card setorange[4] = { mixorange[0],mixorange[1],mixorange[2],mixorange[3] };
    Card setgreen[4] = { mixgreen[0],mixgreen[1],mixgreen[2],mixgreen[3] };
    Card_nob setnob[5] = { mixnob[0],mixnob[1],mixnob[2],mixnob[3],mixnob[4] };
    int check_break = 0;

    while (1)              // 게임이 끝날때까지 턴이 반복
    {
        for (int n = 0; n < players; n++)
        {
            print_map(players, gameplayers, setblue, setorange, setgreen, setnob, totaltok, emtycard, card_discount, keepcard, n);   // 매턴마다 게임판을 보여줌
            printf("----------------player%d turn----------------\n", n + 1);
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
                int number = choice3(gameplayers, card_discount, setblue, setorange, setgreen, n, totaltok, keepcard);      // 개발 카드 산 번호를 return 한다
                int changecard = put_card(setblue, setorange, setgreen, mixblue, mixorange, mixgreen, number);  // 그 번호에  새로운 카드를 넣어주고, 무슨 종류의 카드인지 번호로 return한다. 
                emtycard[changecard]--;                                                     // 번호를 받아 그 색깔의 남은 카드를 하나 줄인다.
                break;
            }

            case 4:
            {
                int number = choice4(gameplayers, n, keepcard, setblue, setorange, setgreen, totaltok);      // 개발 카드 산 번호를 return 한다
                int changecard = put_card(setblue, setorange, setgreen, mixblue, mixorange, mixgreen, number);  // 그 번호에  새로운 카드를 넣어주고, 무슨 종류의 카드인지 번호로 return한다. 
                emtycard[changecard]--;                                                     // 번호를 받아 그 색깔의 남은 카드를 하나 줄인다.
                break;
            }
            }
            rule(gameplayers, card_discount, user_have_nob, players, n, setnob); //////바뀜///////
            if (check_score(gameplayers, n) == 1)
            {
                while (n + 1 < players)
                {
                    int a = n + 1;
                    print_map(players, gameplayers, setblue, setorange, setgreen, setnob, totaltok, emtycard, card_discount, keepcard, a);   // 매턴마다 게임판을 보여줌
                    printf("----------------player%d turn----------------\n", n + 2);
                    printf("*선택*\n1.서로 다른 색깔의 보석 토큰 3개 가져오기\n2.같은 색깔의 보석 토큰 2개 가져오기\n3.개발 카드 구매하기\n4.개발 카드 예약하기\n");
                    scanf_s("%d", &choice);              // 플레이어가 1~4중에서 선택을함
                    switch (choice)
                    {
                    case 1:
                        choice1(gameplayers, totaltok, a);
                        break;
                    case 2:
                        choice2(gameplayers, totaltok, a);
                        break;
                    case 3:
                    {
                        int number = choice3(gameplayers, card_discount, setblue, setorange, setgreen, a, totaltok, keepcard);      // 개발 카드 산 번호를 return 한다
                        int changecard = put_card(setblue, setorange, setgreen, mixblue, mixorange, mixgreen, number);  // 그 번호에  새로운 카드를 넣어주고, 무슨 종류의 카드인지 번호로 return한다. 
                        emtycard[changecard]--;                                                     // 번호를 받아 그 색깔의 남은 카드를 하나 줄인다.
                        break;
                    }

                    case 4:
                    {
                        int number = choice4(gameplayers, a, keepcard, setblue, setorange, setgreen, totaltok);      // 개발 카드 산 번호를 return 한다
                        int changecard = put_card(setblue, setorange, setgreen, mixblue, mixorange, mixgreen, number);  // 그 번호에  새로운 카드를 넣어주고, 무슨 종류의 카드인지 번호로 return한다. 
                        emtycard[changecard]--;                                                     // 번호를 받아 그 색깔의 남은 카드를 하나 줄인다.
                        break;
                    }
                    }
                    rule(gameplayers, card_discount, user_have_nob, players, a, setnob);
                    n++;
                }
                check_break = 1;
                break;
            }
        }
        if (check_break == 1)
        {
            break;
        }
    }

    for (int n = 0; n < players; n++)
    {
        printf(" player%d : %d \n", n + 1, gameplayers[n][6]);
    }
    int max = gameplayers[0][6];
    int max_player = 0;
    for (int n = 0; n < 3; n++)
    {
        if (max < gameplayers[n + 1][6])
        {
            max = gameplayers[n + 1][6];
            max_player = n + 1;
        }
        else if (max == gameplayers[n + 1][6])
        {
            int com_card[5] = { 0 }; // 점수가 같을 때 개발 카드 개수 비교
            for (int i = 0; i < 5; i++)
            {
                com_card[n] += card_discount[n][i];
                com_card[n + 1] += card_discount[n + 1][i];
            }
            if (com_card[n] > com_card[n + 1])
            {
                max = gameplayers[n][6];
                max_player = n;
            }
            else if (com_card[n] < com_card[n + 1])
            {
                max = gameplayers[n + 1][6];
                max_player = n + 1;
            }
        }
    }
    printf(" winner is %d \n", max_player + 1);
}