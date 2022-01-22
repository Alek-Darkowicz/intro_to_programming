#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <termios.h>
#define STDIN_FILENO 0
std::string shapes[7];

//PLAYFIELD SETTINGS
int playfield_width = 12;
int playfield_height = 18;
unsigned char *playfield = nullptr;


//ROTATION FUNCTION
int rotate(int piece_x, int piece_y, int rotation){
	int piece_index = 0;
    // rotation = 0 degrees
    if (rotation == 0){
		piece_index = piece_y * 4 + piece_x;
    }
    // rotation = 90 degrees
    else if (rotation == 1){
		piece_index = 12 + piece_y - (piece_x * 4);
    }
    // rotation = 180 degrees
    else if (rotation == 2){
		piece_index = 15 - (piece_y * 4) - piece_x;
    }
    // rotation = 270 degrees
    else if (rotation == 3){
		piece_index = 3 - piece_y + (piece_x * 4);
    }
	return piece_index;
}

//COLLISION CHECK FUNCTION
bool check_for_collision(int piece, int rotation_a, int piece_a, int piece_b)
{
	// All Field cells >0 are occupied
	for (int piece_x = 0; piece_x < 4; piece_x++){
		for (int piece_y = 0; piece_y < 4; piece_y++){
			// Get index into piece
			int piece_index = rotate(piece_x, piece_y, rotation_a);

			// Get index into field
			int field_index = (piece_b + piece_y) * playfield_width + (piece_a + piece_x);

			// Check that test is in bounds. Note out of bounds does
			// not necessarily mean a fail, as the long vertical piece
			// can have cells that lie outside the boundary, so we'll
			// just ignore them
			if (piece_a + piece_x >= 0 && piece_a + piece_x < playfield_width)
			{
				if (piece_b + piece_y >= 0 && piece_b + piece_y < playfield_height)
				{
					// In Bounds so do collision check
					if (shapes[piece][piece_index] != '0' && playfield[field_index] != 0){
						return true; // fail on first hit
                    }
				}
			}
		}
    }

	return false;
}

int main()
{
// Black magic to prevent Linux from buffering keystrokes.
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

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

//check
int current_piece = 2;
int current_rotation = 0;
int current_x = playfield_width / 2;
int current_y = 0;

//LOOP
    int gameover = 0;
    while (gameover == 0){
//TIMING
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

//CODE




//COUT
        for(int i = 0; i < playfield_width*playfield_height; i++){
            if(i % playfield_width == 11){
                std::cout << "#\n";
            }
            else{
                if(playfield[i] == 9){
                    std::cout << "#";
                }
                else if(playfield[i] > 0 and playfield[i] < 8){
                    std::cout << "Z";
                }
                else{
                std::cout << " ";
                }
            }
        }
//INPUT
// Once the buffering is turned off, the rest is simple.
    std::cout << "Enter a character: ";
    char c,d,e;
    std::cin >> c;
    std::cin >> d;
    std::cin >> e;
    std::cout << "\nYour character was ";
// Using 3 char type, Cause up down right left consist with 3 character
    if ((c==27)&&(d=91)) {
        if (e==65) { std::cout << "UP\n";}
        if (e==66) { std::cout << "DOWN\n";}
        if (e==67) { std::cout << "RIGHT\n";}
        if (e==68) { std::cout << "LEFT\n";}
    }

        system("clear");
        break;
    }
//current piece
    for (int piece_x = 0; piece_x < 4; piece_x++){
        for (int piece_y = 0; piece_y < 4; piece_y++){
			if (shapes[current_piece][rotate(piece_x, piece_y, current_rotation)] != '0'){
                std::cout << "current_y: "<< current_y  << " current_x: " << current_x << " piece_y: " << piece_y << " piece_x: " << piece_x << " piece: " << current_piece << " rot: " << current_rotation <<"\n";
			    playfield[(current_y + piece_y)*playfield_width + (current_x + piece_x)] = current_piece;
                std::cout << "SPOT: " << (current_y + piece_y)*playfield_width + (current_x + piece_x) << "\n";
            }
        }
    }

    for(int i = 0; i < playfield_width*playfield_height; i++){
            if(i % playfield_width == 11){
                std::cout << "#\n";
            }
            else{
                if(playfield[i] == 9){
                    std::cout << "#";
                }
                else if(playfield[i] > 0 and playfield[i] < 8){
                    std::cout << "Z";
                }
                else{
                std::cout << " ";
                }
            }
        }

    
    for(int i = 0; i < 7; i++){
         std::cout << "\n";
         std::cout << shapes[i];
    }
    return 0;
}
