#include <stdio.h>


int print_player_turn(int player_turn){
    putchar('P');
    putchar('l');
    putchar('a');
    putchar('y');
    putchar('e');
    putchar('r');
    putchar(' ');
    if(player_turn == 0){
        putchar('0');
    } else {
        putchar('1');
    }
    putchar(':');
    putchar('\n');
    return 0;
}

int main(){
    int number_rows = 6;
    int number_columns = 7;
    int player_turn = 0;

    char board[42];
    board[0] = '-1';
    board[1] = '-1';
    board[3] = '-1';
    board[2] = '-1';
    board[4] = '-1';
    board[5] = '-1';
    board[6] = '-1';
    board[7] = '-1';
    board[8] = '-1';
    board[9] = '-1';
    board[10] = '-1';
    board[11] = '-1';
    board[12] = '-1';
    board[13] = '-1';
    board[14] = '-1';
    board[15] = '-1';
    board[16] = '-1';
    board[17] = '-1';
    board[18] = '-1';
    board[19] = '-1';
    board[20] = '-1';
    board[21] = '-1';
    board[22] = '-1';
    board[23] = '-1';
    board[24] = '-1';
    board[25] = '-1';
    board[26] = '-1';
    board[27] = '-1';
    board[28] = '-1';
    board[29] = '-1';
    board[30] = '-1';
    board[31] = '-1';
    board[32] = '-1';
    board[33] = '-1';
    board[34] = '-1';
    board[35] = '-1';
    board[36] = '-1';
    board[37] = '-1';
    board[38] = '-1';
    board[39] = '-1';
    board[40] = '-1';
    board[41] = '-1';

    int move;
    while(1==1){
        putchar('B');
        putchar('O');
        putchar('A');
        putchar('R');
        putchar('D');
        putchar(':');
        putchar('\n');

        putchar(board[0]);
        putchar(board[1]);
        putchar(board[2]);
        putchar(board[3]);
        putchar(board[4]);
        putchar(board[5]);
        putchar(board[6]);
        putchar('\n');
        putchar(board[7]);
        putchar(board[8]);
        putchar(board[9]);
        putchar(board[10]);
        putchar(board[11]);
        putchar(board[12]);
        putchar(board[13]);
        putchar('\n');
        putchar(board[14]);
        putchar(board[15]);
        putchar(board[16]);
        putchar(board[17]);
        putchar(board[18]);
        putchar(board[19]);
        putchar(board[20]);
        putchar('\n');
        putchar(board[21]);
        putchar(board[22]);
        putchar(board[23]);
        putchar(board[24]);
        putchar(board[25]);
        putchar(board[26]);
        putchar(board[27]);
        putchar('\n');
        putchar(board[28]);
        putchar(board[29]);
        putchar(board[30]);
        putchar(board[31]);
        putchar(board[32]);
        putchar(board[33]);
        putchar(board[34]);
        putchar('\n');
        putchar(board[35]);
        putchar(board[36]);
        putchar(board[37]);
        putchar(board[38]);
        putchar(board[39]);
        putchar(board[40]);
        putchar(board[41]);
        putchar('\n');

        print_player_turn(player_turn);
        move = getchar();
        int column = move - '0';

        if(board[column * 7 * 6] == 0){
            board[column * 7 * 6] = player_turn;
        } else if(board[column * 7 * 5] == 0){
            board[column * 7 * 5] = player_turn;
        } else if(board[column * 7 * 4] == 0){
            board[column * 7 * 4] = player_turn;
        } else if(board[column * 7 * 3] == 0){
            board[column * 7 * 3] = player_turn;
        } else if(board[column * 7 * 2] == 0){
            board[column * 7 * 2] = player_turn;
        } else if(board[column * 7 * 1] == 0){
            board[column * 7 * 1] = player_turn;
        } else if(board[column] == 0){
            board[column] = player_turn;
        }

        player_turn = player_turn + 1 % 2;
    }
    return 0;
}