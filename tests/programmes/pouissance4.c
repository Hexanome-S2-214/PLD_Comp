#include <stdio.h>


int print_wrong_input(){
    putchar('W');
    putchar('r');
    putchar('o');
    putchar('n');
    putchar('g');
    putchar(' ');
    putchar('I');
    putchar('n');
    putchar('p');
    putchar('u');
    putchar('t');
    putchar('\n');
}

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

int print_game_won(int player){
    char p = 'A' + player;
    putchar('P');
    putchar('l');
    putchar('a');
    putchar('y');
    putchar('e');
    putchar('r');
    putchar(' ');
    putchar(p);
    putchar(' ');
    putchar('W');
    putchar('o');
    putchar('n');
    putchar('\n');
}

int print_full_board(){
    putchar('B');
    putchar('o');
    putchar('a');
    putchar('r');
    putchar('d');
    putchar(' ');
    putchar('i');
    putchar('s');
    putchar(' ');
    putchar('f');
    putchar('u');
    putchar('l');
    putchar('l');
    putchar('\n');
}

int main(){
    int number_rows = 6;
    int number_columns = 7;
    int player = 0;
    int empty_slots = 9;
    char player_symbol[2];
    int correct_input;
    int keep_going = 1;
    char game_won = 0;
    char symbol;

    char board[9];
    board[0] = ' ';
    board[1] = ' ';
    board[3] = ' ';
    board[2] = ' ';
    board[4] = ' ';
    board[5] = ' ';
    board[6] = ' ';
    board[7] = ' ';
    board[8] = ' ';

    int x;
    int y;
    while(keep_going==1){
        correct_input = 1;
        putchar('B');
        putchar('O');
        putchar('A');
        putchar('R');
        putchar('D');
        putchar(':');
        putchar('\n');
        putchar('+');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('+');
        putchar('\n');
        putchar('|');
        puchar(' ');
        putchar(board[0]);
        puchar(' ');
        putchar('|');
        puchar(' ');
        putchar(board[1]);
        puchar(' ');
        putchar('|');
        puchar(' ');
        putchar(board[2]);
        puchar(' ');
        putchar('|');
        putchar('\n');
        putchar('+');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('+');
        putchar('\n');
        putchar('|');
        puchar(' ');
        putchar(board[3]);
        puchar(' ');
        putchar('|');
        puchar(' ');
        putchar(board[4]);
        puchar(' ');
        putchar('|');
        puchar(' ');
        putchar(board[5]);
        puchar(' ');
        putchar('|');
        putchar('\n');
        putchar('+');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('+');
        putchar('\n');
        putchar('|');
        puchar(' ');
        putchar(board[6]);
        puchar(' ');
        putchar('|');
        puchar(' ');
        putchar(board[7]);
        puchar(' ');
        putchar('|');
        puchar(' ');
        putchar(board[8]);
        puchar(' ');
        putchar('|');
        putchar('\n');
        putchar('+');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('+');
        putchar('\n');

        print_player_turn(player);
        x = getchar();
        y = getchar();
        getchar();

        if(x - '0' < 0 || x - '0' > 2 ){
            print_wrong_input();
            correct_input = 0;
        }
        if(y - '0' < 0 || y - '0' > 2){
            print_wrong_input();
            correct_input = 0;
        }
        if(correct_input == 1){
            empty_slots = empty_slots - 1;
            if(x == '0'){
                if(y == '0'){
                    if(player == 0){
                        symbol = 'X';
                        board[0] = symbol;
                    } else {
                        symbol = 'Y';
                        board[0] = symbol;
                    }
                    if(board[1] == symbol && board[2] == symbol){
                        game_won = symbol;
                    }
                    if(board[3] == symbol && board[6] == symbol){
                        game_won = symbol;
                    }
                    if(board[4] == symbol && board[8] == symbol){
                        game_won = symbol;
                    }
                }
                if(y == '1'){
                    if(player == 0){
                        symbol = 'X';
                        board[1] = symbol;
                    } else {
                        symbol = 'Y';
                        board[1] = symbol;
                    } 
                    if(board[0] == symbol && board[2] == symbol){
                        game_won = symbol;
                    }
                    if(board[4] == symbol && board[7] == symbol){
                        game_won = symbol;
                    }
                }
                if (y == '2'){
                    if(player == 0){
                        symbol = 'X';
                        board[2] = symbol;
                    } else {
                        symbol = 'Y';
                        board[2] = symbol;
                    }
                    if(board[0] == symbol && board[1] == symbol){
                        game_won = symbol;
                    }
                    if(board[5] == symbol && board[8] == symbol){
                        game_won = symbol;
                    }
                    if(board[4] == symbol && board[6] == symbol){
                        game_won = symbol;
                    }
                }
            }  
            if(x == '1'){
                if(y == '0'){
                    if(player == 0){
                        symbol = 'X';
                        board[3] = symbol;
                    } else {
                        symbol = 'Y';
                        board[3] = symbol;
                    } 
                    if(board[4] == symbol && board[5] == symbol){
                        game_won = symbol;
                    }
                    if(board[0] == symbol && board[6] == symbol){
                        game_won = symbol;
                    }
                }
                if(y == '1'){
                    if(player == 0){
                        symbol = 'X';
                        board[4] = symbol;
                    } else {
                        symbol = 'Y';
                        board[4] = symbol;
                    }
                    if(board[3] == symbol && board[5] == symbol){
                        game_won = symbol;
                    }
                    if(board[1] == symbol && board[7] == symbol){
                        game_won = symbol;
                    }
                    if(board[0] == symbol && board[8] == symbol){
                        game_won = symbol;
                    }
                    if(board[2] == symbol && board[6] == symbol){
                        game_won = symbol;
                    }
                }
                if (y == '2'){
                    if(player == 0){
                        symbol = 'X';
                        board[5] = symbol;
                    } else {
                        symbol = 'Y';
                        board[5] = symbol;
                    } 
                    if(board[3] == symbol && board[4] == symbol){
                        game_won = symbol;
                    }
                    if(board[2] == symbol && board[8] == symbol){
                        game_won = symbol;
                    }
               }
            }
            if(x == '2'){
                if(y == '0'){
                    if(player == 0){
                        symbol = 'X';
                        board[6] = symbol;
                    } else {
                        symbol = 'Y';
                        board[6] = symbol;
                    } 
                    if(board[7] == symbol && board[8] == symbol){
                        game_won = symbol;
                    }
                    if(board[0] == symbol && board[3] == symbol){
                        game_won = symbol;
                    }
                    if(board[4] == symbol && board[2] == symbol){
                        game_won = symbol;
                    }
                } 
                if(y == '1'){
                    if(player == 0){
                        symbol = 'X';
                        board[7] = symbol;
                    } else {
                        symbol = 'Y';
                        board[7] = symbol;
                    } 
                    if(board[6] == symbol && board[8] == symbol){
                        game_won = symbol;
                    }
                    if(board[1] == symbol && board[4] == symbol){
                        game_won = symbol;
                    }
                } 
                if (y == '2'){
                    if(player == 0){
                        symbol = 'X';
                        board[8] = symbol;
                    } else {
                        symbol = 'Y';
                        board[8] = symbol;
                    } 
                    if(board[6] == symbol && board[7] == symbol){
                        game_won = symbol;
                    }
                    if(board[2] == symbol && board[5] == symbol){
                        game_won = symbol;
                    }
                }

            }
            if(game_won != 0){
                keep_going = 0;
                print_game_won(game_won - 'A');
            }
            if(empty_slots == 0 && game_won == 0){
                keep_going = 0;
                print_full_board();
            }
            player = (player + 1) % 2;
        }

    }
    return 0;
}