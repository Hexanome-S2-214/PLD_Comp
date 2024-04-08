#include <stdio.h>

int print_wrong_input(){
    char word[12] = {'W', 'r', 'o', 'n', 'g', ' ', 'I', 'n', 'p', 'u', 't', '\n'};
    int i = 0;
    while(i < 12){
        char chr = word[i];
        putchar(chr);
        i = i + 1;
    }
}

int print_player_turn(int player_turn){
    char word[10] = {'P', 'l', 'a', 'y', 'e', 'r', ' ', '0', ':', '\n'};
    int i = 0;
    while(i < 10){
        char chr = word[i];
        if(chr != '0'){
            putchar(chr);
        } else {
            if(player_turn == 0){
                putchar('X');
            } else {
                putchar('Y');
            }
        }
        i = i + 1;
    }
    return 0;
}

int print_game_won(int player){
    char p = 'A' + player;
    char word[14] = {'P', 'l', 'a', 'y', 'e', 'r', ' ' , '0', ' ', 'W', 'O', 'N', '!', '\n'};
    int i = 0;
    while(i < 14){
        char chr = word[i];
        if(chr != '0'){
            putchar(chr);
        } else {
            putchar(p);
        }
        i = i + 1;
    }
}

int print_full_board(){
    char word[21] = {'B', 'o', 'a', 'r', 'd', ' ', 'i', 's', ' ', 'f', 'u', 'l', 'l', ',',  ' ', 'D', 'R', 'A', 'W', '!', '\n'};
    int i = 0;
    while(i < 21){
        char chr = word[i];
        putchar(chr);
        i = i + 1;
    }
    
}

int main(){
    int number_rows = 6;
    int number_columns = 7;
    char player = 'X';
    int empty_slots = 9;
    int correct_input;
    int keep_going = 1;
    char game_won = 0;
    int valid_move;

    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    int x;
    int y;
    while(keep_going==1){
        correct_input = 1;
        valid_move = 1;
        char board_string[125] = {'B', 'O', 'A', 'R', 'D', ':', '\n', ' ', ' ', ' ', '0', ' ', ' ', ' ', '1', ' ', ' ', ' ', '2', '\n', ' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '\n', '0', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', '\n', ' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '\n', '1', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', '\n', ' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '\n', '2', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', '\n', ' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '\n'};
        int i = 0;
        int board_i = 0;
        while(i < 125){
            char chr = board_string[i];
            if(chr == 7){
                chr = board[board_i];
                board_i = board_i + 1;
            }
            putchar(chr);
            i = i + 1;
        }

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
            if(x == '0'){
                if(y == '0'){
                    if(board[0] == ' '){
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
                    } else {
                        valid_move = 0;
                    }
                }
                if(y == '1'){
                    if(board[1] == ' '){
                        board[1] = player;
                        if(board[0] == player && board[2] == player){
                            game_won = player;
                        }
                        if(board[4] == player && board[7] == player){
                            game_won = player;
                        }
                    } else {
                        valid_move = 0;
                    }
                }
                if (y == '2'){
                    if(board[2] == ' '){
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
                    } else {
                        valid_move = 0;
                    }
                }
            }  
            if(x == '1'){
                if(y == '0'){
                    if(board[3] == ' '){
                        board[3] = player;
                        if(board[4] == player && board[5] == player){
                            game_won = player;
                        }
                        if(board[0] == player && board[6] == player){
                            game_won = player;
                        }
                    } else {
                        valid_move = 0;
                    }
                }
                if(y == '1'){
                    if(board[4] == ' '){
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
                    } else {
                        valid_move = 0;
                    }
                }
                if (y == '2'){
                    if(board[5] == ' '){
                        board[5] = player;
                        if(board[3] == player && board[4] == player){
                            game_won = player;
                        }
                        if(board[2] == player && board[8] == player){
                            game_won = player;
                        }
                    } else {
                        valid_move = 0;
                    }
               }
            }
            if(x == '2'){
                if(y == '0'){
                    if(board[6] == ' '){
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
                    } else {
                        valid_move = 0;
                    }
                } 
                if(y == '1'){
                    if(board[7] == ' '){
                        board[7] = player;
                        if(board[6] == player && board[8] == player){
                            game_won = player;
                        }
                        if(board[1] == player && board[4] == player){
                            game_won = player;
                        }
                    } else {
                        valid_move = 0;
                    }
                } 
                if (y == '2'){
                    if(board[8] == ' '){
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
                    } else {
                        valid_move = 0;
                    }
                }
            }
            if(valid_move == 1){
                empty_slots = empty_slots - 1;
            }
            if(game_won != 0){
                keep_going = 0;
                print_game_won(game_won - 'A');
            }
            if(empty_slots == 0 && game_won == 0){
                keep_going = 0;
                print_full_board();
            }
            if(valid_move == 1){
                if(player == 'X'){
                    player = 'O';
                } else {
                    player = 'X';
                }
            }
        }
    }

        char board_string[131] = {'F', 'I', 'N', 'A', 'L', ' ', 'B', 'O', 'A', 'R', 'D', ':', '\n', ' ', ' ', ' ', '0', ' ', ' ', ' ', '1', ' ', ' ', ' ', '2', '\n', ' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '\n', '0', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', '\n', ' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '\n', '1', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', '\n', ' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '\n', '2', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', ' ', '7', ' ', '|', '\n', ' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+', '\n'};
        int i = 0;
        int board_i = 0;
        while(i < 131){
            char chr = board_string[i];
            if(chr == 7){
                chr = board[board_i];
                board_i = board_i + 1;
            }
            putchar(chr);
            i = i + 1;
        }

    return 0;
}