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

typedef struct card_nob {////����ī�� ����ü//////
    int score;
    int needcard_white;
    int needcard_blue;
    int needcard_red;
    int needcard_brown;
    int needcard_green;
}Card_nob;


int choice1(int gameplayers[][7], int* totaltok, int turn)  // ���� �ٸ� ������ ���� 3�� ��������
{
    // ���� ��ū�� �� 10������ ����, ������ 4���̻� �����־�� 2�� ������ �� ����
}
int choice2(int gameplayers[][7], int* totaltok, int turn) // ���� ������ ���� ��ū 2�� ��������
{
    // ���� ��ū�� �� 10������ ����, ������ 4���̻� �����־�� 2�� ������ �� ����
}
int choice3(int gameplayers[][7], int card_discount[][5], Card* blue, Card* orange, Card* green, int turn, int* totaltok, Card keepcard[][20]) // ���� ī�� �����ϱ�
{
}
int choice4(int gameplayers[][7], int turn, Card keepcard[][20], Card* blue, Card* orange, Card* green, int* totaltok) // ����ī�� �����ϱ�(with Ȳ����ū)
{
    // ���� ī�带 ������ �� ������, ���� ���Ÿ� ����ϸ� �ش�ī�带 ������ ����
    // Ȳ����ū�� �Բ� �����´�
}
int rule(int gameplayers[][7], int card_discount[][5], int user_have_nob[], int players, int turn, Card_nob* setnob) ////�ٲ�
{
    // ���� ī�� �����̵Ǹ� ���� ī�带 ���� ( ���� �������� ������ �� �� �ְ� ���� and �����湮�� �ѹ��� ����)
    int condition = 0;
    int select_card[5] = { 0 }; // �� �� �ִ� ���� ī�尡 ���� ���� ��� �� �� �ֵ��� ��ȣ ����
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
    // ���ϸ��� �÷��̾ 15���̻� ��Ҵ��� Ȯ���� ������ �� ������ ���������� ���� ����(������ �����ΰ� �������, ���� ���� ������ ������ ī�� ������ �� ���� ����� �¸�)
    if (gameplayers[turn][6] >= 1)
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
        printf("%d %d %d %d %d |", nob[n].needcard_white, nob[n].needcard_blue, nob[n].needcard_red, nob[n].needcard_brown, nob[n].needcard_green);
    }
    printf("\n");
    printf("-------------����ī��(�ʷ�)-----------------                       ---------------------�տ� �ִ� ī��-------------------\n");
    printf("���� �ʷ� |");
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
    printf(" %2d��     |", emtycard[2]);
    for (int n = 0; n < 4; n++)
    {
        printf("  ���� %d  |", green[n].score);
    }
    printf("                |");
    for (int n = 0; n < 20; n++)
    {
        if (keepcard[0][n].score != 10 && keepcard[0][n].score != -1)
            printf("  ���� %d  |", keepcard[turn][n].score);
    }
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("���Ļ�����|");
    }
    printf("                |");
    for (int n = 0; n < 20; n++)
    {
        if (keepcard[0][n].score != 10 && keepcard[0][n].score != -1)
            printf("���Ļ�����|");
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


    printf("-------------����ī��(��Ȳ)-----------------\n");
    printf("���� ��Ȳ |");
    for (int n = 0; n < 4; n++)
    {
        printf("(%2d)-%5s|", card_number++, orange[n].card_type);
    }
    printf("\n");
    printf(" %2d��     |", emtycard[1]);
    for (int n = 0; n < 4; n++)
    {
        printf("  ���� %d  |", orange[n].score);
    }
    printf("\n");
    printf("          |");
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
        printf("(%2d)-%5s|", card_number++, blue[n].card_type);
    }
    printf("\n");
    printf(" %2d��     |", emtycard[0]);
    for (int n = 0; n < 4; n++)
    {
        printf("  ���� %d  |", blue[n].score);
    }
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("���Ļ�����|");
    }
    printf("\n");
    printf("          |");
    for (int n = 0; n < 4; n++)
    {
        printf("%d %d %d %d %d |", blue[n].needtok_white, blue[n].needtok_blue, blue[n].needtok_red, blue[n].needtok_brown, blue[n].needtok_green);
    }
    printf("\n");

    printf("-------------------���� ��ū--------------------------\n");
    printf("��(%d��) ��(%d��) ��(%d��) ��(%d��) ��(%d��) Ȳ(%d��)\n", totaltok[0], totaltok[1], totaltok[2], totaltok[3], totaltok[4], totaltok[5]);

    printf("------------�÷��̾� ��Ȳ-----------------\n");
    for (int n = 0; n < players; n++)
    {
        printf("  -player%d- |", n + 1);
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
    printf("=>���� ��ū");
    printf("\n");
    for (int n = 0; n < players; n++)
    {
        printf("%d %d %d %d %d %d |", gameplayers[n][0], gameplayers[n][1], gameplayers[n][2], gameplayers[n][3], gameplayers[n][4], gameplayers[n][5]);
    }
    printf("\n");
    for (int n = 0; n < players; n++)
    {
        printf("���Ļ�����  |");
    }
    printf("=>���� ��ū");
    printf("\n");
    for (int n = 0; n < players; n++)
    {
        printf("%d %d %d %d %d   |", card_discount[n][0], card_discount[n][1], card_discount[n][2], card_discount[n][3], card_discount[n][4]);
    }
    printf("\n");


}
int put_card(Card* blue, Card* orange, Card* green, Card* mixblue, Card* mixorange, Card* mixgreen, int choice)   // ����ī�带 ��� ���ڸ��� ���ο� ����ī�带 ����ִ� �Լ�
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
    //typedef struct card {                   // ī�� ����ü
    //char card_type[10];
    //int score;                   //gameplayers[][6]
    //int needtok_white;           //gameplayers[][0]
    //int needtok_blue;            //gameplayers[][1]
    //int needtok_red;             //gameplayers[][2]
    //int needtok_brown;           //gameplayers[][3]
    //int needtok_green;           //gameplayers[][4]
    //}Card; ���� ��� �Ķ��� ������ ���� �ʷϻ�
    Card blue[40] = {
       {"brown",0,1,1,1,1,0},{"white",0,0,0,2,1,0},{"white",0,3,1,0,1,0},{"white",0,0,3,0,0,0},{"white",0,0,1,1,1,2},
       {"red",1,4,0,0,0,0},{"blue",0,1,0,2,0,2},{"green",0,1,1,1,2,0},{"red",0,1,0,1,3,0},{"blue",0,0,1,1,0,3},
       {"blue",0,1,0,1,1,1},{"blue",0,0,0,0,2,2},{"brown",1,0,4,0,0,0},{"brown",0,2,2,1,0,0},{"brown",0,0,1,0,0,1},
       {"blue",0,0,0,0,3,0},{"red",0,2,1,0,1,1},{"green",0,1,1,1,1,0},{"white",0,0,2,0,2,0},{"brown",0,0,0,3,1,1},
       {"brown",0,1,2,1,0,1},{"green",0,1,3,0,0,1},{"green",0,2,1,0,0,0},{"blue",0,1,0,2,1,1},{"red",0,2,0,0,2,1},
       {"red",0,2,0,2,0,0},{"brown",0,0,0,1,0,2},{"brown",0,2,0,0,0,2},{"red",0,0,2,0,0,1},{"white",1,0,0,0,0,4},
       {"blue",0,1,0,0,2,0},{"blue",1,0,0,4,0,0},{"green",0,0,0,3,0,0},{"green",0,0,1,2,2,0},{"red",0,1,1,0,1,1},
       {"white",0,0,2,0,1,2},{"white",0,0,1,1,1,1},{"red",0,3,0,0,0,0},{"green",0,0,2,2,0,0},{"green",1,0,0,0,4,0} };          // �Է� �־�� �� ī���
    Card orange[30] = { 0 };
    Card green[20] = { 0 };
    Card_nob nob[10] = { 0 };


    srand(time(NULL));
    int players, choice;
    int gameplayers[4][7] = { 0 };  //�ִ� ���� �ο����� ����(6��),������ ��Ÿ�� 2���� �迭
    int card_discount[4][5] = { 0 };  // �÷��̾ ī��(����,����)�� ���� ���� 
    int totaltok[6] = { 0,0,0,0,0,5 };  // ���ӿ� ����� �ִ� ���� ��ū ����
    int tok = { 0 };                    // �ο����� ���� �� ��ū ������ ��Ÿ���� ����
    int emtycard[3] = { 36,26,16 };      // ���ӿ� ����� �ִ� ���� ī�� ����
    int user_have_nob[5] = { 0 }; /////�߰�///////
    int checking = 0;


    Card mixblue[40] = { 0 };            // ī�带 ��� �迭
    Card mixorange[30] = { 0 };
    Card mixgreen[20] = { 0 };
    Card_nob mixnob[10] = { 0 };

    Card keepcard[4][20] = { 0 };       // 4�� ���̽������� ������ ī��
    for (int n = 0; n < 4; n++)
        for (int n1 = 0; n1 < 20; n1++)
            keepcard[n][n1].score = -1;

    printf("SPLENDER\n");
    printf("�� ���� �Ͻ� �ǰ���?(2~4�ο� ����)");
    scanf_s("%d", &players);

    if (players == 2) tok = 20;             // �ο����� ���� ��ū ������ ����
    else if (players == 3) tok = 5;
    else tok = 7;
    for (int n = 0; n < 5; n++)
        totaltok[n] = tok;

    //�������� ī��迭�� �� 
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


    // �������� �迭�� ī���� ���ӿ� ��ĥ ī�� 4���� ��Ÿ���� �迭
    Card setblue[4] = { mixblue[0],mixblue[1],mixblue[2],mixblue[3] };
    Card setorange[4] = { mixorange[0],mixorange[1],mixorange[2],mixorange[3] };
    Card setgreen[4] = { mixgreen[0],mixgreen[1],mixgreen[2],mixgreen[3] };
    Card_nob setnob[5] = { mixnob[0],mixnob[1],mixnob[2],mixnob[3],mixnob[4] };
    int check_break = 0;

    while (1)              // ������ ���������� ���� �ݺ���
    {
        for (int n = 0; n < players; n++)
        {
            print_map(players, gameplayers, setblue, setorange, setgreen, setnob, totaltok, emtycard, card_discount, keepcard, n);   // ���ϸ��� �������� ������
            printf("----------------player%d turn----------------\n", n + 1);
            printf("*����*\n1.���� �ٸ� ������ ���� ��ū 3�� ��������\n2.���� ������ ���� ��ū 2�� ��������\n3.���� ī�� �����ϱ�\n4.���� ī�� �����ϱ�\n");
            scanf_s("%d", &choice);              // �÷��̾ 1~4�߿��� ��������
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
                int number = choice3(gameplayers, card_discount, setblue, setorange, setgreen, n, totaltok, keepcard);      // ���� ī�� �� ��ȣ�� return �Ѵ�
                int changecard = put_card(setblue, setorange, setgreen, mixblue, mixorange, mixgreen, number);  // �� ��ȣ��  ���ο� ī�带 �־��ְ�, ���� ������ ī������ ��ȣ�� return�Ѵ�. 
                emtycard[changecard]--;                                                     // ��ȣ�� �޾� �� ������ ���� ī�带 �ϳ� ���δ�.
                break;
            }

            case 4:
            {
                int number = choice4(gameplayers, n, keepcard, setblue, setorange, setgreen, totaltok);      // ���� ī�� �� ��ȣ�� return �Ѵ�
                int changecard = put_card(setblue, setorange, setgreen, mixblue, mixorange, mixgreen, number);  // �� ��ȣ��  ���ο� ī�带 �־��ְ�, ���� ������ ī������ ��ȣ�� return�Ѵ�. 
                emtycard[changecard]--;                                                     // ��ȣ�� �޾� �� ������ ���� ī�带 �ϳ� ���δ�.
                break;
            }
            }
            rule(gameplayers, card_discount, user_have_nob, players, n, setnob); //////�ٲ�///////
            if (check_score(gameplayers, n) == 1)
            {
                while (n + 1 < players)
                {
                    int a = n + 1;
                    print_map(players, gameplayers, setblue, setorange, setgreen, setnob, totaltok, emtycard, card_discount, keepcard, a);   // ���ϸ��� �������� ������
                    printf("----------------player%d turn----------------\n", n + 2);
                    printf("*����*\n1.���� �ٸ� ������ ���� ��ū 3�� ��������\n2.���� ������ ���� ��ū 2�� ��������\n3.���� ī�� �����ϱ�\n4.���� ī�� �����ϱ�\n");
                    scanf_s("%d", &choice);              // �÷��̾ 1~4�߿��� ��������
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
                        int number = choice3(gameplayers, card_discount, setblue, setorange, setgreen, a, totaltok, keepcard);      // ���� ī�� �� ��ȣ�� return �Ѵ�
                        int changecard = put_card(setblue, setorange, setgreen, mixblue, mixorange, mixgreen, number);  // �� ��ȣ��  ���ο� ī�带 �־��ְ�, ���� ������ ī������ ��ȣ�� return�Ѵ�. 
                        emtycard[changecard]--;                                                     // ��ȣ�� �޾� �� ������ ���� ī�带 �ϳ� ���δ�.
                        break;
                    }

                    case 4:
                    {
                        int number = choice4(gameplayers, a, keepcard, setblue, setorange, setgreen, totaltok);      // ���� ī�� �� ��ȣ�� return �Ѵ�
                        int changecard = put_card(setblue, setorange, setgreen, mixblue, mixorange, mixgreen, number);  // �� ��ȣ��  ���ο� ī�带 �־��ְ�, ���� ������ ī������ ��ȣ�� return�Ѵ�. 
                        emtycard[changecard]--;                                                     // ��ȣ�� �޾� �� ������ ���� ī�带 �ϳ� ���δ�.
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
            int com_card[5] = { 0 }; // ������ ���� �� ���� ī�� ���� ��
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