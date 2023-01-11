//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include <fstream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

int Player_car_x=5;
int Player_car_y=5;
float* Player_car_color=colors[RED];

int Player_2_car_x=485;
int Player_2_car_y=725;
float* Player_2_car_color=colors[YELLOW];

int first_Opponent_x=425;
int first_Opponent_y=725;
float* first_Opponent_color=colors[YELLOW];

int second_Opponent_x=245;
int second_Opponent_y=185;
float* second_Opponent_color=colors[MISTY_ROSE];

int menu=0;
int mode;
int game_level=1;
int vehicle_1,vehicle_2;
string First_player_name, Second_player_name;
int game_score=0, player_2_score=0;

int hit=0;
int fire=0;
int ball_x, ball_2_x;
int ball_y, ball_2_y;

void Set_Opponent_1(int x, int y)
{
	first_Opponent_x=x;
	first_Opponent_y=y;
}

void Set_Opponent_2(int x, int y)
{
	second_Opponent_x=x;
	second_Opponent_y=y;
}
void Set_player()
{
	Player_car_x=5;
	Player_car_y=5;
}
void Set_player_2()
{
	Player_2_car_x=485;
	Player_2_car_y=725;
}

void Set_small_ball(int x, int y)
{
	ball_x=x;
	ball_y=y;
}

void Set_palyer_2_ball(int x, int y)
{
	ball_2_x=x;
	ball_2_y=y;
}


class High_score
{
public:
	High_score()
	{

	}

	void Write_file()
	{
		ofstream myfile;
		myfile.open("Score.txt");
		myfile << game_score << endl;
		cout << "Score stored in file" << endl;
		myfile.close();
	}
};

class Mode
{
private:

public:
	Mode()
	{

	}

	void Input()
	{
		cout << "Press 1 for '1 Player mode'" << endl;
		cout << "Press 2 for '2 Player mode'" << endl;
		cout << "Enter your choice= ";
		cin >> mode;
		if(mode==1)
		{
			cout << "Enter Player 1 name= ";
			cin >> First_player_name;
			cout << "Press 1 for Tank" << endl;
			cout << "Press 2 for Helipocter" << endl;
			cout << "Press 3 for Fighter Plane" << endl;
			cout << "Enter your choice= ";
			cin >> vehicle_1;
		}
		else if(mode==2)
		{
			cout << "Enter Player 1 name= ";
			cin >> First_player_name;
			cout << "Enter Player 2 name= ";
			cin >> Second_player_name;
			cout << "Press 1 for Tank" << endl;
			cout << "Press 2 for Helipocter" << endl;
			cout << "Press 3 for Fighter Plane" << endl;
			cout << "Enter Player 1 choice= ";
			cin >> vehicle_1;
			cout << "Enter Player 2 choice= ";
			cin >> vehicle_2;
		}
	}
};

class Menu
{
private:

public:
	Menu()
	{

	}

	void Display()
	{
		DrawString(200, 600, "Press 1 for Play", colors[MISTY_ROSE]);
		DrawString(200, 550, "Press 2 for High Score", colors[MISTY_ROSE]);
		DrawString(200, 500, "Press 3 for Instructions", colors[MISTY_ROSE]);
		DrawString(200, 450, "Press 4 for Credit", colors[MISTY_ROSE]);
		DrawString(200, 400, "Set your Game controls on terminal", colors[MISTY_ROSE]);
	}

	void Draw_small_ball(int x, int y)
	{
		DrawRectangle(x+20, y+60, 10, 10, colors[MISTY_ROSE]);
	}
};

class Arena
{
private:

public:
	Arena()
	{

	}

	void Display()
	{
		DrawString( 50, 800, "Score= "+ std::to_string(game_score), colors[MISTY_ROSE]);
		DrawString( 500, 800, "Hit= "+ std::to_string(hit), colors[MISTY_ROSE]);
		DrawString( 800, 800, "Level= "+ std::to_string(game_level), colors[MISTY_ROSE]);
	}

	void Display_Tank(int x, int y, float* color)
	{
		DrawRoundRect(x,y,50,30,color,5);
		DrawRoundRect(x+20,y+30,10,25,color,3);
	}

	void Display_helicopter(int x, int y, float* color)
	{
		DrawRoundRect(x,y,25,25,color,7);
		DrawRoundRect(x+10,y+25,5,15,color,4);
		DrawRoundRect(x+25,y+10,20,5,color,4);
	}

	void Display_plane(int x, int y, float* color)
	{
		DrawRectangle(x+20,y,10,50,color);
		DrawRectangle(x,y+20,50,10,color);
		DrawRectangle(x,y+20,10,23,color);
		DrawRectangle(x+40,y+20,10,23,color);
	}
};

class Game_level
{
private:
	int block_1_x=180;
	int block_1_y=480;
	float* block_1_color=colors[DARK_GRAY];
	int block_2_x=120;
	int block_2_y=600;
	float *block_2_color=colors[RED];
public:
	Game_level()
	{

	}

	void Level_1_blocks()
	{
		int x=0;
		int y=0;
		for(int i=0; i<25; i++)
		{
			DrawRectangle(block_1_x+x, block_1_y+y, 60, 60, block_1_color);
			if(i<2)
			{
				y+=60;
			}
			else if(i>1 && i<5)
			{
				x+=60;
			}
			else if(i==5)
			{
				block_1_x=600;
				block_1_y=600;
				x=0;y=0;
			}
			else if(i>5 && i<9)
			{
				x+=60;
			}
			else if(i>8 && i<11)
			{
				y-=60;
			}
			else if(i==11)
			{
				block_1_x=180;
				block_1_y=240;
				x=0;y=0;
			}
			else if(i>11 && i<14)
			{
				y-=60;
			}
			else if(i>14 && i<18)
			{
				x+=60;
			}
			else if(i==18)
			{
				block_1_x=600;
				block_1_y=120;
				x=0;y=0;
			}
			else if(i>18 && i<22)
			{
				x+=60;
			}
			else if(i>21 && i<25)
			{
				y+=60;
			}
		}
		DrawRectangle(420, 300, 180, 180, block_1_color);
	}

	void Level_2_blocks()
	{
		DrawRectangle(block_2_x, block_2_y, 240, 60, block_2_color);
		DrawRectangle(block_2_x, (block_2_y/2)+60, 240, 60, block_2_color);
		DrawRectangle(block_2_x, (block_2_y/3)-80, 240, 60, block_2_color);
		DrawRectangle(block_2_x+420, (block_2_y/2)-60, 60, 300, block_2_color);
		DrawRectangle(block_2_x+660, (block_2_y/2)+120, 60, 180, block_2_color);
		DrawRectangle(block_2_x+720, (block_2_y/2)+120, 60, 60, block_2_color);
		DrawRectangle(block_2_x+720, block_2_y/2, 60, 120, block_2_color);
	}

	void Level_3_blocks()
	{
		DrawRectangle(120, 660, 120, 60, colors[BLACKO]);
		DrawRectangle(540, 660, 120, 60, colors[BLACKO]);
		DrawRectangle(840, 480, 60, 240, colors[BLACKO]);
		DrawRectangle(240, 420, 120, 120, colors[BLACKO]);
		DrawRectangle(660, 420, 120, 120, colors[BLACKO]);
		DrawRectangle(300, 180, 240, 60, colors[BLACKO]);
		DrawRectangle(480, 240, 240, 60, colors[BLACKO]);
		DrawRectangle(60, 60, 120, 120, colors[BLACKO]);
		DrawRectangle(840, 60, 120, 120, colors[BLACKO]);
	}

	void Level_1_checks(int x, int y)
	{
		//For Bottom left blocks
		if((x>=130 && x<=420) && (y>=70 && y<=180))
		{
			Set_player();
		}
		else if((x>=130 && x<=240) && (y>=180 && y<=300))
		{
			Set_player();
		}
		//For Up left blocks
		if((x>=130 && x<=240) && (y>=430 && y<=550))
		{
			Set_player();
		}
		else if((x>=130 && x<=420) && (y>=550 && y<=660))
		{
			Set_player();
		}
		//For Up right blocks
		if((x>=550 && x<=840) && (y>=550 && y<=660))
		{
			Set_player();
		}
		else if((x>=730 && x<=840) && (y>=430 && y<=560))
		{
			Set_player();
		}
		//For bottom right blocks
		if((x>=550 && x<=840) && (y>=70 && y<=180))
		{
			Set_player();
		}
		else if((x>=730 && x<=840) && (y>=180 && y<=300))
		{
			Set_player();
		}
		if((x>=370 && x<=600) && (y>=250 && y<=480))
		{
			Set_player();
		}
	}

	void Player_2_Level_1_checks(int x, int y)
	{
		//For Bottom left blocks
		if((x>=130 && x<=420) && (y>=70 && y<=180))
		{
			Set_player_2();
		}
		else if((x>=130 && x<=240) && (y>=180 && y<=300))
		{
			Set_player_2();
		}
		//For Up left blocks
		if((x>=130 && x<=240) && (y>=430 && y<=550))
		{
			Set_player_2();
		}
		else if((x>=130 && x<=420) && (y>=550 && y<=660))
		{
			Set_player_2();
		}
		//For Up right blocks
		if((x>=550 && x<=840) && (y>=550 && y<=660))
		{
			Set_player_2();
		}
		else if((x>=730 && x<=840) && (y>=430 && y<=560))
		{
			Set_player_2();
		}
		//For bottom right blocks
		if((x>=550 && x<=840) && (y>=70 && y<=180))
		{
			Set_player_2();
		}
		else if((x>=730 && x<=840) && (y>=180 && y<=300))
		{
			Set_player_2();
		}
		if((x>=370 && x<=600) && (y>=250 && y<=480))
		{
			Set_player_2();
		}
	}

	void Level_2_checks(int x, int y)
	{
		if((x>=70 && x<=360) && (y>=70 && y<=180))
		{
			Set_player();
		}

		if((x>=70 && x<=360) && (y>=310 && y<=420))
		{
			Set_player();
		}

		if((x>=70 && x<=360) && (y>=550 && y<=660))
		{
			Set_player();
		}

		if((x>=490 && x<=600) && (y>=190 && y<=540))
		{
			Set_player();
		}

		if((x>=730 && x<=840) && (y>=370 && y<=600))
		{
			Set_player();
		}

		if((x>=790 && x<=900) && (y>=250 && y<=480))
		{
			Set_player();
		}
	}

	void Player_2_Level_2_checks(int x, int y)
	{
		if((x>=70 && x<=360) && (y>=70 && y<=180))
		{
			Set_player_2();
		}

		if((x>=70 && x<=360) && (y>=310 && y<=420))
		{
			Set_player_2();
		}

		if((x>=70 && x<=360) && (y>=550 && y<=660))
		{
			Set_player_2();
		}

		if((x>=490 && x<=600) && (y>=190 && y<=540))
		{
			Set_player_2();
		}

		if((x>=730 && x<=840) && (y>=370 && y<=600))
		{
			Set_player_2();
		}

		if((x>=790 && x<=900) && (y>=250 && y<=480))
		{
			Set_player_2();
		}
	}

	void Opponent_Level_2_checks(int x, int y)
	{
		if(x==245 && y==305)
		{
			Set_Opponent_1(245,425);
		}
		if(x==485 && y==485)
		{
			Set_Opponent_1(605,485);
		}
		if(x==605 && y==305)
		{
			Set_Opponent_1(5,245);
		}
		if(x==305 && y==185)
		{
			Set_Opponent_1(305,425);
		}
		if(x==65 && y==5)
		{
			Set_Opponent_1(65,65);
		}
		if(x==125 && y==65)
		{
			Set_Opponent_1(245,185);
		}
	}

	void Opponent_2_Level_2_checks(int x, int y)
	{
		if(x==245 && y==305)
		{
			Set_Opponent_2(245,425);
		}
		if(x==305 && y==185)
		{
			Set_Opponent_2(305,425);
		}
		if(x==485 && y==485)
		{
			Set_Opponent_2(605,485);
		}
		if(x==605 && y==305)
		{
			Set_Opponent_2(5,245);
		}
		if(x==65 && y==5)
		{
			Set_Opponent_2(65,65);
		}
		if(x==125 && y==65)
		{
			Set_Opponent_2(245,185);
		}
	}

	void Level_3_checks(int x, int y)
	{
		if((x>=10 && x<=180) && (y>=10 && y<=180))
		{
			Set_player();
		}
		if((x>=190 && x<=360) && (y>=370 && y<=540))
		{
			Set_player();
		}
		if((x>=70 && x<=240) && (y>=610 && y<=720))
		{
			Set_player();
		}
		if((x>=490 && x<=660) && (y>=610 && y<=720))
		{
			Set_player();
		}
		if((x>=610 && x<=780) && (y>=370 && y<=540))
		{
			Set_player();
		}
		if((x>=430 && x<=720) && (y>=190 && y<=300))
		{
			Set_player();
		}
		if((x>=250 && x<=540) && (y>=130 && y<=240))
		{
			Set_player();
		}
		if((x>=790 && x<=960) && (y>=10 && y<=180))
		{
			Set_player();
		}
		if((x>=790 && x<=900) && (y>=430 && y<=720))
		{
			Set_player();
		}
	}

	void Player_2_Level_3_checks(int x, int y)
	{
		if((x>=10 && x<=180) && (y>=10 && y<=180))
		{
			Set_player_2();
		}
		if((x>=190 && x<=360) && (y>=370 && y<=540))
		{
			Set_player_2();
		}
		if((x>=70 && x<=240) && (y>=610 && y<=720))
		{
			Set_player_2();
		}
		if((x>=490 && x<=660) && (y>=610 && y<=720))
		{
			Set_player_2();
		}
		if((x>=610 && x<=780) && (y>=370 && y<=540))
		{
			Set_player_2();
		}
		if((x>=430 && x<=720) && (y>=190 && y<=300))
		{
			Set_player_2();
		}
		if((x>=250 && x<=540) && (y>=130 && y<=240))
		{
			Set_player_2();
		}
		if((x>=790 && x<=960) && (y>=10 && y<=180))
		{
			Set_player_2();
		}
		if((x>=790 && x<=900) && (y>=430 && y<=720))
		{
			Set_player_2();
		}
	}

	void Opponent_Level_3_checks(int x, int y)
	{
		if(x==65 && y==5)
		{
			Set_Opponent_1(65,185);
		}
		if(x==65 && y==665)
		{
			Set_Opponent_1(245,665);
		}
		if(x==485 && y==665)
		{
			Set_Opponent_1(665,665);
		}
		if(x==785 && y==665)
		{
			Set_Opponent_1(905,665);
		}
		if(x==905 && y==185	)
		{
			Set_Opponent_1(785,65);
		}
		if(x==185 && y==65)
		{
			Set_Opponent_1(245,185);
		}
		if(x==245 && y==365)
		{
			Set_Opponent_1(245,545);
		}
		if(x==725 && y==545)
		{
			Set_Opponent_1(725,365);
		}
		if(x==545 && y==185)
		{
			Set_Opponent_1(365,5);
		}
	}

	void Opponent_2_Level_3_checks(int x, int y)
	{
		if(x==65 && y==5)
		{
			Set_Opponent_2(65,185);
		}
		if(x==65 && y==665)
		{
			Set_Opponent_2(245,665);
		}
		if(x==485 && y==665)
		{
			Set_Opponent_2(665,665);
		}
		if(x==785 && y==665)
		{
			Set_Opponent_2(905,665);
		}
		if(x==905 && y==185	)
		{
			Set_Opponent_2(785,65);
		}
		if(x==185 && y==65)
		{
			Set_Opponent_2(245,185);
		}
		if(x==245 && y==365)
		{
			Set_Opponent_2(245,545);
		}
		if(x==725 && y==545)
		{
			Set_Opponent_2(725,365);
		}
		if(x==545 && y==185)
		{
			Set_Opponent_2(5,365);
		}
	}
};

class Bot_movement
{
private:

public:
	Bot_movement()
	{

	}

	void First_track_move(int x, int y)
	{
		if((x==5) && (y>=5 && y<725))
		{
			first_Opponent_y+=10;
		}
		else if((y==725) && (x>=5 && x<960))
		{
			first_Opponent_x+=10;
		}
		else if((x==965) && (y>5 && y<=725))
		{
			first_Opponent_y-=10;
		}
		else if((y==5) && (x>5 && x<=965))
		{
			first_Opponent_x-=10;
		}
	}

	void first_track_move(int x, int y)
	{
		if((x==5) && (y>=5 && y<725))
		{
			second_Opponent_y+=10;
		}
		else if((y==725) && (x>=5 && x<960))
		{
			second_Opponent_x+=10;
		}
		else if((x==965) && (y>5 && y<=725))
		{
			second_Opponent_y-=10;
		}
		else if((y==5) && (x>5 && x<=965))
		{
			second_Opponent_x-=10;
		}
	}

	void Second_track_move(int x, int y)
	{
		if((x==65) && (y>=65 && y<665))
		{
			first_Opponent_y+=10;
		}
		else if((y==665) && (x>=65 && x<900))
		{
			first_Opponent_x+=10;
		}
		else if((x==905) && (y>65 && y<=665))
		{
			first_Opponent_y-=10;
		}
		else if((y==65) && (x>65 && x<=905))
		{
			first_Opponent_x-=10;
		}
	}

	void second_track_move(int x, int y)
	{
		if((x==65) && (y>=65 && y<665))
		{
			second_Opponent_y+=10;
		}
		else if((y==665) && (x>=65 && x<900))
		{
			second_Opponent_x+=10;
		}
		else if((x==905) && (y>65 && y<=665))
		{
			second_Opponent_y-=10;
		}
		else if((y==65) && (x>65 && x<=905))
		{
			second_Opponent_x-=10;
		}
	}

	void Third_track_move(int x, int y)
	{
		if((x==245) && (y>=185 && y<545))
		{
			first_Opponent_y+=10;
		}
		else if((y==545) && (x>=245 && x<725))
		{
			first_Opponent_x+=10;
		}
		else if((x==725) && (y>185 && y<=545))
		{
			first_Opponent_y-=10;
		}
		else if((y==185) && (x>245 && x<=725))
		{
			first_Opponent_x-=10;
		}
	}

	void third_track_move(int x, int y)
	{
		if((x==245) && (y>=185 && y<545))
		{
			second_Opponent_y+=10;
		}
		else if((y==545) && (x>=245 && x<725))
		{
			second_Opponent_x+=10;
		}
		else if((x==725) && (y>185 && y<=545))
		{
			second_Opponent_y-=10;
		}
		else if((y==185) && (x>245 && x<=725))
		{
			second_Opponent_x-=10;
		}
	}

	void Fourth_track_move(int x, int y)
	{
		if((x==305) && (y>=245 && y<485))
		{
			first_Opponent_y+=10;
		}
		else if((y==485) && (x>=305 && x<665))
		{
			first_Opponent_x+=10;
		}
		else if((x==665) && (y>305 && y<=485))
		{
			first_Opponent_y-=10;
		}
		else if((y==305) && (x>365 && x<=665))
		{
			first_Opponent_x-=10;
		}
	}

	void fourth_track_move(int x, int y)
	{
		if((x==305) && (y>=245 && y<485))
		{
			second_Opponent_y+=10;
		}
		else if((y==485) && (x>=305 && x<665))
		{
			second_Opponent_x+=10;
		}
		else if((x==665) && (y>305 && y<=485))
		{
			second_Opponent_y-=10;
		}
		else if((y==305) && (x>365 && x<=665))
		{
			second_Opponent_x-=10;
		}
	}

	void Fifth_track_move(int x, int y)
	{
		if((x==305) && (y>=305 && y<425))
		{
			first_Opponent_y+=10;
		}
		else if((y==425) && (x>=305 && x<665))
		{
			first_Opponent_x+=10;
		}
		else if((x==665) && (y>305 && y<=425))
		{
			first_Opponent_y-=10;
		}
		else if((y==305) && (x>305 && x<=665))
		{
			first_Opponent_x-=10;
		}
	}

	void Level_1_move(int x, int y)
	{
		if(x==65 && y==5)
		{
			Set_Opponent_1(65,65);
		}
		if(x==125 && y==65)
		{
			Set_Opponent_1(245,185);
		}
		if(x==305 && y==185)
		{
			Set_Opponent_1(305,245);
		}
		if(x==605 && y==305)
		{
			Set_Opponent_1(5,305);
		}
	}

	void player_ball_collide(int x, int y)
	{
		if((ball_x+40>=x && ball_x<=x+40))
		{
			if((ball_y+40>=y && ball_y<=y))
			{
				fire=0;
				game_score++;
			}
		}
	}

	void player_2_ball_collide(int x, int y)
	{
		if((ball_2_x+40>=x && ball_2_x<=x+40))
		{
			if((ball_2_y+40>=y && ball_2_y<=y))
			{
				fire=0;
				player_2_score++;
			}
		}
	}

	void First_Opponent_move()
	{
		First_track_move(first_Opponent_x, first_Opponent_y);
		Second_track_move(first_Opponent_x, first_Opponent_y);
		Third_track_move(first_Opponent_x, first_Opponent_y);
		Fourth_track_move(first_Opponent_x, first_Opponent_y);
	}

	void Second_Opponent_move()
	{
		third_track_move(second_Opponent_x, second_Opponent_y);
		fourth_track_move(second_Opponent_x, second_Opponent_y);
		first_track_move(second_Opponent_x, second_Opponent_y);
		second_track_move(second_Opponent_x, second_Opponent_y);
	}

	void Small_ball_move()
	{
		if(fire==1)
		{
			if(ball_y<705)
			{
				ball_y+=10;
			}
			if((ball_x>=5 && ball_x<=965) && ball_y==705)
			{
				fire=0;
			}
		}
		else if(fire==2)
		{
			if(ball_x<985)
			{
				ball_x+=10;
			}
			if((ball_x==985) && (ball_y>=-30 && ball_y<=690))
			{
				fire=0;
			}
		}
		else if(fire==3)
		{
			if(ball_x>-15)
			{
				ball_x-=10;
			}
			if((ball_x==-15) && (ball_y>=-30 && ball_y<=690))
			{
				fire=0;
			}
		}
		else if(fire==4)
		{
			if(ball_y>-45)
			{
				ball_y-=10;
			}
			if((ball_y==-50) && (ball_x>=5 && ball_y<=965))
			{
				fire=0;
			}
		}
	}

	void Player_2_ball_move()
	{
		if(fire==5)
		{
			if(ball_2_y<705)
			{
				ball_2_y+=10;
			}
			if((ball_2_x>=5 && ball_2_x<=965) && ball_2_y==705)
			{
				fire=0;
			}
		}
		else if(fire==6)
		{
			if(ball_2_x<985)
			{
				ball_2_x+=10;
			}
			if((ball_2_x==985) && (ball_2_y>=-30 && ball_2_y<=690))
			{
				fire=0;
			}
		}
		else if(fire==7)
		{
			if(ball_2_x>-15)
			{
				ball_2_x-=10;
			}
			if((ball_2_x==-15) && (ball_2_y>=-30 && ball_2_y<=690))
			{
				fire=0;
			}
		}
		else if(fire==8)
		{
			if(ball_2_y>-45)
			{
				ball_2_y-=10;
			}
			if((ball_2_y==-50) && (ball_2_x>=5 && ball_2_y<=965))
			{
				fire=0;
			}
		}
	}
};
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


int xI = 400, yI = 400;

void drawCar() {
	DrawSquare(xI, yI, 20, colors[WHITE]);
	glutPostRedisplay();
}


bool flag = true;
void moveCar() {

	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)

			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}

bool Collission_check(int x, int y)
{
	if((Player_car_x+40>=x && Player_car_x<=x+40))// && (Player_car_y+50>=y && Player_car_y<=y+50))
	{
		if((Player_car_y+40>=y && Player_car_y<=y+30))
		{
			return true;
		}
	}
	return false;
}

bool Player_2_Collission_check(int x, int y)
{
	if((Player_2_car_x+40>=x && Player_2_car_x<=x+40))// && (Player_car_y+50>=y && Player_car_y<=y+50))
	{
		if((Player_2_car_y+40>=y && Player_2_car_y<=y+30))
		{
			return true;
		}
	}
	return false;
}



/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	Arena a;
	Game_level g;
	Bot_movement b;
	Menu m;
	if(menu==0)
	{
		m.Display();
	}
	if(menu==1)
	{
		if(mode==1)
		{
			if(vehicle_1==1)
			{
				a.Display_Tank(Player_car_x, Player_car_y, Player_car_color);
			}
			else if(vehicle_1==2)
			{
				a.Display_helicopter(Player_car_x, Player_car_y, Player_car_color);
			}
			else if(vehicle_1==3)
			{
				a.Display_plane(Player_car_x, Player_car_y, Player_car_color);
			}
			if(game_level==1)
			{
				a.Display();
				a.Display_Tank(first_Opponent_x, first_Opponent_y, first_Opponent_color);
				g.Level_1_blocks();
				g.Level_1_checks(Player_car_x, Player_car_y);
				b.Level_1_move(first_Opponent_x, first_Opponent_y);
				if(fire>=1 && fire<=4)
				{
					m.Draw_small_ball(ball_x, ball_y);
					b.player_ball_collide(first_Opponent_x, first_Opponent_y);
				}
			}
			else if(game_level==2)
			{
				a.Display();
				a.Display_Tank(first_Opponent_x, first_Opponent_y, first_Opponent_color);
				a.Display_helicopter(second_Opponent_x, second_Opponent_y, second_Opponent_color);
				g.Level_2_blocks();
				g.Level_2_checks(Player_car_x, Player_car_y);
				g.Opponent_Level_2_checks(first_Opponent_x, first_Opponent_y);
				g.Opponent_2_Level_2_checks(second_Opponent_x, second_Opponent_y);
				if(fire>=1 && fire<=4)
				{
					m.Draw_small_ball(ball_x, ball_y);
					b.player_ball_collide(first_Opponent_x, first_Opponent_y);
					b.player_ball_collide(second_Opponent_x, second_Opponent_y);
				}
			}
			else if(game_level==3)
			{
				a.Display();
				a.Display_Tank(first_Opponent_x, first_Opponent_y, first_Opponent_color);
				a.Display_helicopter(second_Opponent_x, second_Opponent_y, second_Opponent_color);
				g.Level_3_blocks();
				g.Level_3_checks(Player_car_x, Player_car_y);
				g.Opponent_Level_3_checks(first_Opponent_x, first_Opponent_y);
				g.Opponent_2_Level_3_checks(second_Opponent_x, second_Opponent_y);
				if(fire>=1 && fire<=4)
				{
					m.Draw_small_ball(ball_x, ball_y);
					b.player_ball_collide(first_Opponent_x, first_Opponent_y);
					b.player_ball_collide(second_Opponent_x, second_Opponent_y);
				}
			}
		}
		else if(mode==2)
		{
			DrawString( 200, 800, "Player 2 score= "+ std::to_string(player_2_score), colors[MISTY_ROSE]);
			if(vehicle_1==1)
			{
				a.Display_Tank(Player_car_x, Player_car_y, Player_car_color);
			}
			else if(vehicle_1==2)
			{
				a.Display_helicopter(Player_car_x, Player_car_y, Player_car_color);
			}
			else if(vehicle_1==3)
			{
				a.Display_plane(Player_2_car_x, Player_2_car_y, Player_2_car_color);
			}
			if(vehicle_2==1)
			{
				a.Display_Tank(Player_2_car_x, Player_2_car_y, Player_2_car_color);
			}
			else if(vehicle_2==2)
			{
				a.Display_helicopter(Player_2_car_x, Player_2_car_y, Player_2_car_color);
			}
			else if(vehicle_2==3)
			{
				a.Display_plane(Player_2_car_x, Player_2_car_y, Player_2_car_color);
			}
			if(game_level==1)
			{
				a.Display();
				g.Level_1_blocks();
				g.Level_1_checks(Player_car_x, Player_car_y);
				g.Player_2_Level_1_checks(Player_2_car_x, Player_2_car_y);
				if(fire>=1 && fire<=4)
				{
					m.Draw_small_ball(ball_x, ball_y);
					b.player_ball_collide(Player_2_car_x, Player_2_car_y);
				}
				if(fire>=5 && fire<=8)
				{
					m.Draw_small_ball(ball_2_x, ball_2_y);
					b.player_2_ball_collide(Player_car_x, Player_car_y);
				}
			}
			// else if(game_level==2)
			// {
			// 	a.Display();
			// 	g.Level_2_blocks();
			// 	g.Level_2_checks(Player_car_x, Player_car_y);
			// 	g.Player_2_Level_2_checks(Player_2_car_x, Player_2_car_y);
			// 	if(fire>=1 && fire<=4)
			// 	{
			// 		m.Draw_small_ball(ball_x, ball_y);
			// 		b.player_ball_collide(Player_2_car_x, Player_2_car_y);
			// 	}
			// 	if(fire>=5 && fire<=8)
			// 	{
			// 		m.Draw_small_ball(ball_x, ball_y);
			// 		b.player_2_ball_collide(Player_car_x, Player_car_y);
			// 	}
			// }
			// else if(game_level==3)
			// {
			// 	a.Display();
			// 	g.Level_3_blocks();
			// 	g.Level_3_checks(Player_car_x, Player_car_y);
			// 	g.Player_2_Level_3_checks(Player_2_car_x, Player_2_car_y);
			// 	if(fire>=1 && fire<=4)
			// 	{
			// 		m.Draw_small_ball(ball_x, ball_y);
			// 		b.player_ball_collide(Player_2_car_x, Player_2_car_y);
			// 	}
			// 	if(fire>=5 && fire<=8)
			// 	{
			// 		m.Draw_small_ball(ball_x, ball_y);
			// 		b.player_2_ball_collide(Player_car_x, Player_car_y);
			// 	}
			// }
		}
	}

	if(menu==2)
	{
		DrawString( 200, 600, "High score= "+ std::to_string(game_score), colors[MISTY_ROSE]);
	}
	if(menu==3)
	{
		DrawString( 70, 700, "Player 2 Controls", colors[MISTY_ROSE]);
		DrawString( 50, 650, "1. Press E for Player UP", colors[MISTY_ROSE]);
		DrawString( 50, 600, "2. Press S for Player Left", colors[MISTY_ROSE]);
		DrawString( 50, 550, "3. Press F for Player Right", colors[MISTY_ROSE]);
		DrawString( 50, 500, "4. Press X for Player Down", colors[MISTY_ROSE]);
		DrawString( 570, 700, "Player 2 Shooting", colors[MISTY_ROSE]);
		DrawString( 550, 650, "1. Press Q for Player UP Shot", colors[MISTY_ROSE]);
		DrawString( 550, 600, "2. Press R for Player Left Shot", colors[MISTY_ROSE]);
		DrawString( 550, 550, "3. Press W for Player Right Shot", colors[MISTY_ROSE]);
		DrawString( 550, 500, "4. Press T for Player Down shot", colors[MISTY_ROSE]);
		DrawString( 330, 400, "Player 1 Shooting", colors[MISTY_ROSE]);
		DrawString( 300, 350, "1. Press U for Player UP Shot", colors[MISTY_ROSE]);
		DrawString( 300, 300, "2. Press I for Player Left Shot", colors[MISTY_ROSE]);
		DrawString( 300, 250, "3. Press O for Player Right Shot", colors[MISTY_ROSE]);
		DrawString( 300, 200, "4. Press P for Player Down shot", colors[MISTY_ROSE]);

	}
	if(menu==4)
	{
		DrawString( 200, 600, "Credit=200", colors[MISTY_ROSE]);
	}

	if(mode==1)
	{
		if(Collission_check(first_Opponent_x, first_Opponent_y))
		{
			Set_player();
			Set_Opponent_1(425,725);
			hit++;
		}

		if(Collission_check(second_Opponent_x, second_Opponent_y))
		{
			Set_player();
			Set_Opponent_2(245,185);
			hit++;
		}
	}


	if(mode==2)
	{
		if(Collission_check(Player_2_car_x, Player_2_car_y))
		{
			Set_player();
			Set_player_2();
			//hit++;
		}
	}



	if(game_score==10)
	{
		game_level++;
		game_score=0;
	}
	High_score h;

	if(game_level==4)
	{
		DrawString( 450, 400, "You Win", colors[RED]);
		menu=0;
		h.Write_file();
		//game_score=0;
	}

	if(hit==10)
	{
		DrawString( 450, 400, "You Lose", colors[RED]);
		menu=0;
		h.Write_file();
	}

	//a.Display_helicopter(helicopter_x, helicopter_y);
	//a.Display_plane(plane_x, plane_y);
	//Red Square
	// DrawSquare(400, 20, 40, colors[RED]);
	//
	// //Green Square
	// DrawSquare( 250 , 250 ,20,colors[GREEN]);
	//
	// //Display Score
	// DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//
	// // Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	// DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] );
	//
	//
	//
	// //DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	// DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );
	//
	// DrawCircle(50,670,10,colors[RED]);
	// DrawCircle(70,670,10,colors[RED]);
	// DrawCircle(90,670,10,colors[RED]);
	// DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	// DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);
	// DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	// DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	// DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	//
	// drawCar();
	glutSwapBuffers(); // do not modify this line..

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if(Player_car_x>5)
		{
			Player_car_x-=10;
		}

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
				if(Player_car_x<965)
				{
					Player_car_x+=10;
				}
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
				if(Player_car_y<725)
				{
					Player_car_y += 10;
				}
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
				if(Player_car_y>5)
				{
					Player_car_y -= 10;
				}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	if(key=='1')
	{
		menu=1;
	}
	if(key=='2')
	{
		menu=2;
	}
	if(key=='3')
	{
		menu=3;
	}
	if(key=='4')
	{
		menu=4;
	}


	if(key=='s' || key=='S')
	{
		if(Player_2_car_x>5)
		{
			Player_2_car_x-=10;
		}
	}

	if(key=='f' || key=='F')
	{
		if(Player_2_car_x<965)
		{
			Player_2_car_x+=10;
		}
	}

	if(key=='e' || key=='E')
	{
		if(Player_2_car_y<725)
		{
			Player_2_car_y += 10;
		}
	}

	if(key=='x' || key=='X')
	{
		if(Player_2_car_y>5)
		{
			Player_2_car_y -= 10;
		}
	}

	if(key=='u' || key=='U')
	{
		Set_small_ball(Player_car_x, Player_car_y);
		fire=1;
	}

	if(key=='i' || key=='I')
	{
		Set_small_ball(Player_car_x+30, Player_car_y-35);
		fire=2;
	}

	if(key=='o' || key=='O')
	{
		Set_small_ball(Player_car_x-10, Player_car_y-35);
		fire=3;
	}

	if(key=='p' || key=='P')
	{
		Set_small_ball(Player_car_x, Player_car_y-65);
		fire=4;
	}

	if(mode==2)
	{
		if(key=='q' || key=='Q')
		{
			Set_palyer_2_ball(Player_2_car_x, Player_2_car_y-20);
			fire=5;
		}

		if(key=='w' || key=='W')
		{
			Set_palyer_2_ball(Player_2_car_x, Player_2_car_y-20);
			fire=6;
		}

		if(key=='r' || key=='R')
		{
			Set_palyer_2_ball(Player_2_car_x, Player_2_car_y-20);
			fire=7;
		}

		if(key=='t' || key=='T')
		{
			Set_palyer_2_ball(Player_2_car_x, Player_2_car_y-20);
			fire=8;
		}
	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	Bot_movement b;
	// if(mode==1)
	// {
	if(menu==1)
	{
		if(mode==1)
		{
			b.First_Opponent_move();
			b.Second_Opponent_move();
		}
		if(fire>=1 && fire<=4)
		{
			b.Small_ball_move();
		}
		if(fire>=5 && fire<=8)
		{
			b.Player_2_ball_move();
		}
		glutPostRedisplay();
	}


	// }

	 // b.First_track_move(first_Opponent_x, first_Opponent_y);
	 // if(first_Opponent_x==65 && first_Opponent_y==5)
	 // {
		//  first_Opponent_x=65;
		//  first_Opponent_y=65;
		//  //b.Second_track_move(first_Opponent_x, first_Opponent_y);
	 // }
	 // b.Second_track_move(first_Opponent_x, first_Opponent_y);
	 // if(first_Opponent_x==65 && first_Opponent_y==65)
	 // {
		//  first_Opponent_x=245;
		//  first_Opponent_y=185;
	 // }
	 // b.Third_track_move(first_Opponent_x, first_Opponent_y);
	 // if(first_Opponent_x==305 && first_Opponent_y==185)
	 // {
		//  first_Opponent_x=305;
		//  first_Opponent_y=245;
	 // }
	 // b.Fourth_track_move(first_Opponent_x, first_Opponent_y);
	 // if(first_Opponent_x==305 && first_Opponent_y==245)
	 // {
		//  first_Opponent_x=305;
		//  first_Opponent_y=305;
	 // }
	 //b.Fifth_track_move(first_Opponent_x, first_Opponent_y);
	 // if(first_Opponent_x==305 && first_Opponent_y==305)
	 // {
		//  first_Opponent_x=425;
		//  first_Opponent_y=725;
	 // }


	// implement your functionality here
//	moveCar();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(3000.0/FPS, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	Mode m;
	m.Input();

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Naveed Ahmad"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0/FPS, Timer, 0);

	// glutMouseFunc(MouseClicked);
	// glutPassiveMotionFunc(MouseMoved); // Mouse
	// glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
