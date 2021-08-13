#include<stdio.h>
void game();
void menu();

int main(){
	menu();
}

void menu(){
	puts("Welcome to TIC TAC JEMPOL");
	puts("1. Start Game");
	puts("2. Exit Game");
	puts("");
	int choice;
	printf("Number of Choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			game();
			break;
		case 2:
			break;
	}
}

void game(){
	int winner = 0, count = 0;
        int data[9], index, sign, player, flag, i, k, j;

        for (i = 0; i < 9; i++)
                data[i] = ' ';

        while (count < 9) {
                flag = 0;
                printf("\n\n");
                printf("  %c | %c  | %c  \n", data[0], data[1], data[2]);
                printf("----+----+----\n");
                printf("  %c | %c  | %c  \n", data[3], data[4], data[5]);
                printf("----+----+----\n");
                printf("  %c | %c  | %c  \n", data[6], data[7], data[8]);
                if (count % 2 == 0) {
                        sign = 'X';
                        player = 1;
                } else {
                        sign = 'O';
                        player = 2;
                }
                printf("Move for player%d(1-9):", player);
                scanf("%d", &index);
                if (index < 1 || index > 9) {
                        printf("Allowed index is 1 to 9!!\n");
                        continue;
                }
                if (data[index - 1] == 'X' || data[index - 1] == 'Y') {
                        printf("Position Already occupied!!\n");
                        continue;
                }
                data[index - 1] = sign;
                count++;

                for (i = 0; i < 9; i++) {
                        if (i % 3 == 0)
                                flag = 0;

                        if (data[i] == sign)
                                flag++;

                        if (flag == 3) {
                                winner = 1;
                                goto win;
                        }
                }

                flag = 0;
                for (i = 0; i < 3; i++) {
                        for (k = i; k <= i + 6; k = k + 3) {
                                if (data[k] == sign)
                                        flag++;
                        }
                        if (flag == 3) {
                                winner = 1;
                                goto win;
                        }
                        flag = 0;
                }
                if ((data[0] == sign && data[4] == sign && data[8] == sign) ||
                        (data[2] == sign && data[4] == sign && data[6] ==  sign)) {
                        winner = 1;
                        goto win;
                }
        }
  win:
        printf("\n\n");
        printf("  %c | %c  | %c  \n", data[0], data[1], data[2]);
        printf("----+----+----\n");
        printf("  %c | %c  | %c  \n", data[3], data[4], data[5]);
        printf("----+----+----\n");
        printf("  %c | %c  | %c  \n\n", data[6], data[7], data[8]);
        if (winner) {
                printf("Player %d is the winner. Congrats!!\n", player);
        } else {
                printf("Match draw.. Best of luck for both\n");
        }
        puts("");
        puts("Do you want to play again?");
		puts("1. Yes");
		puts("2. No");
		puts("");
		int choice;
		printf("Number of Choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				game();
				break;
			case 2:
				break;
		}
}
