#include <iostream>
#include <random>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <vector>

std::string shapes[7];

//AREA SETTINGS
int playfield_width = 18;
int playfield_height = 18;
unsigned char *playfield = nullptr;
unsigned char *screen = nullptr;

//ROTATION FUNCTION
int rotate(int piece_x, int piece_y, int rotation){
	int piece_index = 0;
    // rotation = 0 degrees
    if (rotation % 4 == 0){
		piece_index = piece_y * 4 + piece_x;
    }
    // rotation = 90 degrees
    else if (rotation % 4 == 1){
		piece_index = 12 + piece_y - (piece_x * 4);
    }
    // rotation = 180 degrees
    else if (rotation % 4 == 2){
		piece_index = 15 - (piece_y * 4) - piece_x;
    }
    // rotation = 270 degrees
    else if (rotation % 4 == 3){
		piece_index = 3 - piece_y + (piece_x * 4);
    }
	return piece_index;
}
//COLLISION CHECK FUNCTION
bool check_for_no_collision(int piece, int rotation_a, int piece_a, int piece_b)
{
	for (int piece_x = 0; piece_x < 4; piece_x++){
		for (int piece_y = 0; piece_y < 4; piece_y++){
			int piece_index = rotate(piece_x, piece_y, rotation_a);
			int field_index = (piece_b + piece_y) * playfield_width + (piece_a + piece_x);
			if (piece_a + piece_x >= 0 && piece_a + piece_x < playfield_width)
			{
				if (piece_b + piece_y >= 0 && piece_b + piece_y < playfield_height)
				{
					if (shapes[piece][piece_index] != '0' && screen[field_index] != 0){
						return false;
                    }
				}
			}
		}
    }
	return true;
}
int current_piece;
int current_rotation;
int current_x;
int current_y;
//DISPLAY
auto print_screen() {
    //APPLY PIECE
        for (int piece_x = 0; piece_x < 4; piece_x++){
            for (int piece_y = 0; piece_y < 4; piece_y++){
			    if (shapes[current_piece][rotate(piece_x, piece_y, current_rotation)] != '0'){
			        playfield[(current_y + piece_y)*playfield_width + (current_x + piece_x)] = current_piece + 1;
                }
            }
        }
    //PRINT
        for(int i = 0; i < playfield_width*playfield_height; i++){
            if(i % playfield_width == playfield_width - 1){
                printw("#\n");
            }
            else{
                if(screen[i] == 9){
                    printw("#");
                }
                else if(playfield[i] == 1){
                    printw("1");
                }
                else if(playfield[i] == 2){
                    printw("2");
                }
                else if(playfield[i] == 3){
                    printw("3");
                }
                else if(playfield[i] == 4){
                    printw("4");
                }
                else if(playfield[i] == 5){
                    printw("5");
                }
                else if(playfield[i] == 6){
                    printw("6");
                }
                else if(playfield[i] == 7){
                    printw("7");
                }
                else if(playfield[i] == 8){
                    printw("=");
                }
                else{
                printw(" ");
                }
            }
        }
}
int main() {
    
    initscr();
    refresh();
    noecho();
    nodelay(stdscr, true);

//SHAPES
    //shape I
    shapes[0].append("0100");
    shapes[0].append("0100");
    shapes[0].append("0100");
    shapes[0].append("0100");
    //shape L
    shapes[1].append("0100");
    shapes[1].append("0100");
    shapes[1].append("0110");
    shapes[1].append("0000");
    //shape J
    shapes[2].append("0100");
    shapes[2].append("0100");
    shapes[2].append("1100");
    shapes[2].append("0000");
    //shape T
    shapes[3].append("0100");
    shapes[3].append("1100");
    shapes[3].append("0100");
    shapes[3].append("0000");
    //shape S
    shapes[4].append("1000");
    shapes[4].append("1100");
    shapes[4].append("0100");
    shapes[4].append("0000");
    //shape Z
    shapes[5].append("0100");
    shapes[5].append("1100");
    shapes[5].append("1000");
    shapes[5].append("0000");
    //shape O
    shapes[6].append("1100");
    shapes[6].append("1100");
    shapes[6].append("0000");
    shapes[6].append("0000");

//PLAYFIELD
    playfield = new unsigned char[playfield_width*playfield_height];
    for(int i = 0; i < playfield_height; i++){
        for(int j = 0; j < playfield_width; j++){
            if(j == 0){
                playfield[i*playfield_width + j] = 9;
            }
            else if(i == playfield_height - 1){
                playfield[i*playfield_width + j] = 9;
            }
            else if(j == playfield_width -1){
                playfield[i*playfield_width + j] = 9;
            }
            else{
                playfield[i*playfield_width + j] = 0;
            }
        }
    }
    screen = new unsigned char[playfield_width*playfield_height];
    for(int i = 0; i < playfield_height; i++){
        for(int j = 0; j < playfield_width; j++){
            if(j == 0){
                screen[i*playfield_width + j] = 9;
            }
            else if(i == playfield_height - 1){
                screen[i*playfield_width + j] = 9;
            }
            else if(j == playfield_width -1){
                screen[i*playfield_width + j] = 9;
            }
            else{
                screen[i*playfield_width + j] = 0;
            }
        }
    }
//check
current_piece = 0;
current_rotation = 0;
current_x = playfield_width / 2;
current_y = 0;
//TIMING
int game_difficulty = 20;
int game_speed = 0; 
bool gravity = false;
int piece_count = 0;
int score = 0;
std::vector<int> current_lines;

//FIRST SCREEN
clear();
printw("%d", game_speed);
printw(": just began\n");
printw("                Your score: %d\n", score);
print_screen();
//GAME LOOP
    bool game_over = false;
    while (game_over == false) {
//TIMING
        if (game_speed == game_difficulty) {
            gravity = true;
            game_speed = 0; 
        }
//CONTROLS
        
        wchar_t control = getch();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        if (control == 66) {
            clear();
            printw("%d", game_speed);
            printw(": key down\n");
            printw("                Your score: %d\n", score);
            if (check_for_no_collision(current_piece, current_rotation, current_x, current_y + 1) == true) {
                current_y = current_y + 1;
                print_screen();
            }
            else {
                print_screen();
            }
        }
        else if (control == 67) {
            clear();
            printw("%d", game_speed);
            printw(": key right\n");
            printw("                Your score: %d\n", score);
            if (check_for_no_collision(current_piece, current_rotation, current_x + 1, current_y) == true) {
                current_x = current_x + 1;
                print_screen();
            }
            else {
                print_screen();
            }
        }
        else if (control == 68) {
            clear();
            printw("%d", game_speed);
            printw(": key left\n");
            printw("                Your score: %d\n", score);
            if (check_for_no_collision(current_piece, current_rotation, current_x - 1, current_y) == true) {
                current_x = current_x - 1;
                print_screen();
            }
            else {
                print_screen();
            }
        }
        else if (control == 65) {
            clear();
            printw("%d", game_speed);
            printw(": rotation key\n");
            printw("                Your score: %d\n", score);
            if (check_for_no_collision(current_piece, current_rotation + 1, current_x, current_y) == true) {
                current_rotation = current_rotation + 1;
                print_screen();
            }
            else {
                print_screen();
            }
        }
        else if (gravity == true) {
            if (check_for_no_collision(current_piece, current_rotation, current_x, current_y + 1) == true) {
                current_y = current_y + 1;
                clear();
                printw("%d", game_speed);
                printw(": gravity\n");
                printw("                Your score: %d\n", score);
                print_screen();
            }
            else {
            //NEW SCREEN
                for (int piece_x = 0; piece_x < 4; piece_x++){
                    for (int piece_y = 0; piece_y < 4; piece_y++){
			            if (shapes[current_piece][rotate(piece_x, piece_y, current_rotation)] != '0'){
			                screen[(current_y + piece_y)*playfield_width + (current_x + piece_x)] = current_piece + 1;
                        }
                    }
                }
            //FULL LINES
                for (int piece_y = 0; piece_y < 4; piece_y++) {
                    bool full_line = true;
                    if (current_y + piece_y < playfield_height - 1) {
                        for (int piece_x = 1; piece_x < playfield_width - 1; piece_x++) {
                            if (screen[(current_y + piece_y) * playfield_width + piece_x] == 0) {
                                full_line = false;
                            }
                        }
                        if (full_line == true) {
                            for (int piece_x = 1; piece_x < playfield_width - 1; piece_x++) {
                                screen[(current_y + piece_y) * playfield_width + piece_x] = 8;
                            }
                            current_lines.push_back(current_y + piece_y);
                        }
                    }
                }
//SCORE
                score = score + 25;
                if (current_lines.empty() == false)
                    score = score + (current_lines.size() * current_lines.size() * 25);
//choose new piece - check
                std::random_device rd;
                std::uniform_int_distribution<int> d7 (0, 6);
                current_piece = d7(rd);
                current_rotation = 0;
                current_x = playfield_width / 2;
                current_y = 0;
                if (check_for_no_collision(current_piece, current_rotation, current_x, current_y) == false) {
                    game_over = true;
                }
//CLEAR PLAYFIELD
                for(int i = 0; i < playfield_height; i++){
                    for(int j = 0; j < playfield_width; j++){
                        playfield[i*playfield_width + j] = screen[i*playfield_width + j];
                    }
                }
//REMOVE FULL LINES
                if (current_lines.empty() == false) {
                    for (auto current_line : current_lines) {
                        for (int piece_x = 1; piece_x < playfield_width - 1; piece_x++) {
                            for (int piece_y = current_line; piece_y > 0; piece_y--) {
                                screen[piece_y * playfield_width + piece_x] = screen[(piece_y - 1) * playfield_width + piece_x];
                            }
                            screen[piece_x] = 0;
                        }
                    }
                }
                
                game_speed = 0;
                piece_count++;
                if (piece_count % 15 == 0) {
                    if (game_difficulty > 5) {
                        game_difficulty--;
                    }
                }
                clear();
                if (current_lines.empty() == false) {
                    for (auto current_line : current_lines) {
                        printw("%d ", current_line);
                    }
                    printw(":deleting lines\n");
                    printw("                Your score: %d\n", score);
                }
                else {
                    printw("%d: new piece\n", game_speed);
                printw("                Your score: %d\n", score);
                }
                print_screen();
                current_lines.clear();
            }
            gravity = false;
        }
//CLEAR PLAYFIELD
        for(int i = 0; i < playfield_height; i++){
            for(int j = 0; j < playfield_width; j++){
                playfield[i*playfield_width + j] = screen[i*playfield_width + j];
            }
        }
        game_speed++;
    }
    endwin();
    system("clear");
    std::cout << "Game over! Your score was: " << score << "\n";
    return 0;
}
