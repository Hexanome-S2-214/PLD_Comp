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
        putchar('X');
    } else {
        putchar('Y');
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
    char player = 'X';
    int empty_slots = 9;
    int correct_input;
    int keep_going = 1;
    char game_won = 0;

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
        putchar(' ');
        putchar(' ');
        putchar(' ');
        putchar('0');
        putchar(' ');
        putchar(' ');
        putchar(' ');
        putchar('1');
        putchar(' ');
        putchar(' ');
        putchar(' ');
        putchar('2');
        putchar('\n');
        putchar(' ');
        putchar('+');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('+');
        putchar('\n');
        putchar('0');
        putchar('|');
        putchar(' ');
        putchar(board[0]);
        putchar(' ');
        putchar('|');
        putchar(' ');
        putchar(board[1]);
        putchar(' ');
        putchar('|');
        putchar(' ');
        putchar(board[2]);
        putchar(' ');
        putchar('|');
        putchar('\n');
        putchar(' ');
        putchar('+');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('+');
        putchar('\n');
        putchar('1');
        putchar('|');
        putchar(' ');
        putchar(board[3]);
        putchar(' ');
        putchar('|');
        putchar(' ');
        putchar(board[4]);
        putchar(' ');
        putchar('|');
        putchar(' ');
        putchar(board[5]);
        putchar(' ');
        putchar('|');
        putchar('\n');
        putchar(' ');
        putchar('+');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('+');
        putchar('\n');
        putchar('2');
        putchar('|');
        putchar(' ');
        putchar(board[6]);
        putchar(' ');
        putchar('|');
        putchar(' ');
        putchar(board[7]);
        putchar(' ');
        putchar('|');
        putchar(' ');
        putchar(board[8]);
        putchar(' ');
        putchar('|');
        putchar('\n');
        putchar(' ');
        putchar('+');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('-');
        putchar('+');
        putchar('\n');

        print_player_turn(player - 'X');
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
                    board[0] = player;
                    if(board[1] == player && board[2] == player){
                        game_won = player;
                    }
                    if(board[3] == player && board[6] == player){
                        game_won = player;
                    }
                    if(board[4] == player && board[8] == player){
                        game_won = player;
                    }
                }
                if(y == '1'){
                    board[1] = player;
                    if(board[0] == player && board[2] == player){
                        game_won = player;
                    }
                    if(board[4] == player && board[7] == player){
                        game_won = player;
                    }
                }
                if (y == '2'){
                    board[2] = player;
                    if(board[0] == player && board[1] == player){
                        game_won = player;
                    }
                    if(board[5] == player && board[8] == player){
                        game_won = player;
                    }
                    if(board[4] == player && board[6] == player){
                        game_won = player;
                    }
                }
            }  
            if(x == '1'){
                if(y == '0'){
                    board[3] = player;
                    if(board[4] == player && board[5] == player){
                        game_won = player;
                    }
                    if(board[0] == player && board[6] == player){
                        game_won = player;
                    }
                }
                if(y == '1'){
                    board[4] = player;
                    if(board[3] == player && board[5] == player){
                        game_won = player;
                    }
                    if(board[1] == player && board[7] == player){
                        game_won = player;
                    }
                    if(board[0] == player && board[8] == player){
                        game_won = player;
                    }
                    if(board[2] == player && board[6] == player){
                        game_won = player;
                    }
                }
                if (y == '2'){
                    board[5] = player;
                    if(board[3] == player && board[4] == player){
                        game_won = player;
                    }
                    if(board[2] == player && board[8] == player){
                        game_won = player;
                    }
               }
            }
            if(x == '2'){
                if(y == '0'){
                    board[6] = player;
                    if(board[7] == player && board[8] == player){
                        game_won = player;
                    }
                    if(board[0] == player && board[3] == player){
                        game_won = player;
                    }
                    if(board[4] == player && board[2] == player){
                        game_won = player;
                    }
                } 
                if(y == '1'){
                    board[7] = player;
                    if(board[6] == player && board[8] == player){
                        game_won = player;
                    }
                    if(board[1] == player && board[4] == player){
                        game_won = player;
                    }
                } 
                if (y == '2'){
                    board[8] = player;
                    if(board[6] == player && board[7] == player){
                        game_won = player;
                    }
                    if(board[2] == player && board[5] == player){
                        game_won = player;
                    }
                    if(board[0] == player && board[4] == player){
                        game_won = player;
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
            if(player == 'X'){
                player = 'O';
            } else {
                player = 'X';
            }
        }
    }
    putchar('\n');
    putchar('\n');
    putchar('\n');
    putchar('F');
    putchar('I');
    putchar('N');
    putchar('A');
    putchar('L');
    putchar(' ');
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
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('+');
    putchar('\n');
    putchar('|');
    putchar(' ');
    putchar(board[0]);
    putchar(' ');
    putchar('|');
    putchar(' ');
    putchar(board[1]);
    putchar(' ');
    putchar('|');
    putchar(' ');
    putchar(board[2]);
    putchar(' ');
    putchar('|');
    putchar('\n');
    putchar('+');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('+');
    putchar('\n');
    putchar('|');
    putchar(' ');
    putchar(board[3]);
    putchar(' ');
    putchar('|');
    putchar(' ');
    putchar(board[4]);
    putchar(' ');
    putchar('|');
    putchar(' ');
    putchar(board[5]);
    putchar(' ');
    putchar('|');
    putchar('\n');
    putchar('+');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('+');
    putchar('\n');
    putchar('|');
    putchar(' ');
    putchar(board[6]);
    putchar(' ');
    putchar('|');
    putchar(' ');
    putchar(board[7]);
    putchar(' ');
    putchar('|');
    putchar(' ');
    putchar(board[8]);
    putchar(' ');
    putchar('|');
    putchar('\n');
    putchar('+');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('+');
    putchar('\n');
    return 0;
}