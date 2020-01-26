#include<iostream>



//#include<conio.h>



#include<string>



#include <SFML/Graphics.hpp>

#include<SFML/Audio.hpp>



#include <time.h>



using namespace sf;







int size = 56;







Sprite f[32];







int board[8][8] =



{



	-1,-2,-3,-4,-5,-3,-2,-1,



	-6,-6,-6,-6,-6,-6,-6,-6,



	0, 0, 0, 0, 0, 0, 0, 0,



	0, 0, 0, 0, 0, 0, 0, 0,



	0, 0, 0, 0, 0, 0, 0, 0,



	0, 0, 0, 0, 0, 0, 0, 0,



	6, 6, 6, 6, 6, 6, 6, 6,



	1, 2, 3, 4, 5, 3, 2, 1



};











void loadposition()



{



	int k = 0;



	for (int i = 0; i < 8; i++)



		for (int j = 0; j < 8; j++)



		{



			int n = board[i][j];



			if (!n) continue;



			int x = abs(n) - 1;



			int y = n > 0 ? 1 : 0;



			f[k].setTextureRect(IntRect(size*x, size*y, size, size));



			f[k].setPosition(size*j, size*i);



			k++;



		}



}







std::string tochessnote(Vector2f p)



{



	std::string s = "";



	s += char(p.x / size + 97);



	s += char(7 - p.y / size + 49);



	return s;



}











Vector2f barkhord(char a, char b)



{



	int x = int(a) - 97;



	int y = 7 - int(b) + 49;



	return Vector2f(x*size, y*size);



}







void move(std::string str)



{



	Vector2f oldpos = barkhord(str[0], str[1]);



	Vector2f newpos = barkhord(str[4], str[5]);







	for (int i = 0; i < 32; i++)



		if (f[i].getPosition() == newpos)



			f[i].setPosition(-5000, -5000);







	for (int i = 0; i < 32; i++)



		if (f[i].getPosition() == oldpos)



			f[i].setPosition(newpos);



}







int asb(std::string str, std::string position[], int n)



{



	Vector2f oldpos = barkhord(str[0], str[1]);



	Vector2f newpos = barkhord(str[4], str[5]);



	Vector2f vectorPosition[32];



	for (int i = 0; i < 32; i++)



	{



		vectorPosition[i] = barkhord(position[i][0], position[i][1]);



	}







	int positionx[32];



	for (int x = 0; x < 32; x++)



	{



		positionx[x] = vectorPosition[x].x / size;



	}







	int positiony[32];



	for (int y = 0; y < 32; y++)



	{



		positiony[y] = vectorPosition[y].y / size;



	}



	int positionxasb = newpos.x / size;

	int positionyasb = newpos.y / size;



	if (n == 25 || n == 30)

	{

		if (newpos.x == size + oldpos.x&&newpos.y == oldpos.y - 2 * size)

		{

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}



			return 1;

		}

		if (newpos.x == oldpos.x + 2 * size&&newpos.y == oldpos.y - size)

		{

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}



		if (newpos.x == oldpos.x + 2 * size&&newpos.y == oldpos.y + size)

		{

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}



		if (newpos.x == oldpos.x + size&&newpos.y == oldpos.y + 2 * size)

		{

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}

		if (newpos.x == oldpos.x - size&&newpos.y == oldpos.y + 2 * size)

		{

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}



		if (newpos.x == oldpos.x - 2 * size&&newpos.y == oldpos.y + size)

		{

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}

		if (newpos.x == oldpos.x - 2 * size&&newpos.y == oldpos.y - size)

		{

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}

		if (newpos.x == oldpos.x - size&&newpos.y == oldpos.y - 2 * size)

		{

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb + 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 2 && positiony[4] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[4] == positionxasb - 1 && positiony[4] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}

	}

	if (n == 1 || n == 6)

	{

		if (newpos.x == size + oldpos.x&&newpos.y == oldpos.y - 2 * size)

		{

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}



			return 1;

		}

		if (newpos.x == oldpos.x + 2 * size&&newpos.y == oldpos.y - size)

		{

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}



		if (newpos.x == oldpos.x + 2 * size&&newpos.y == oldpos.y + size)

		{

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}



		if (newpos.x == oldpos.x + size&&newpos.y == oldpos.y + 2 * size)

		{

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}

		if (newpos.x == oldpos.x - size&&newpos.y == oldpos.y + 2 * size)

		{

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}



		if (newpos.x == oldpos.x - 2 * size&&newpos.y == oldpos.y + size)

		{

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}

		if (newpos.x == oldpos.x - 2 * size&&newpos.y == oldpos.y - size)

		{

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}

		if (newpos.x == oldpos.x - size&&newpos.y == oldpos.y - 2 * size)

		{

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb + 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb + 2)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb + 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 2 && positiony[28] == positionyasb - 1)

			{

				std::cout << "KISH.................................................";

			}

			if (positionx[28] == positionxasb - 1 && positiony[28] == positionyasb - 2)

			{

				std::cout << "KISH.................................................";

			}

			return 1;

		}

	}















	return 0;



}







int rook(std::string str, std::string position[],int m)



{



	Vector2f oldpos = barkhord(str[0], str[1]);



	Vector2f newpos = barkhord(str[4], str[5]);







	/*for (int i = 0; i < 32; i++)



	{



	std::cout << position[i] << "\n";



	}*/







	Vector2f vectorPosition[32];



	for (int i = 0; i < 32; i++)



	{



		vectorPosition[i] = barkhord(position[i][0], position[i][1]);



	}







	int positionx[32];



	for (int x = 0; x < 32; x++)



	{



		positionx[x] = vectorPosition[x].x / size;



	}







	int positiony[32];



	for (int y = 0; y < 32; y++)



	{



		positiony[y] = vectorPosition[y].y / size;



	}







	int NazdikXMosbat;//نزدیک ترین مهره به رخ در محور ایکس از سمت مثبت



	int NazdikXManfi;//نزدیک به رخ در محور ایکس از سمت منفی



	int NazdikYMosbat;//نزدیک به رخ در محور ایگرگ از سمت مثبت



	int NazdikYManfi;//نزدیک به رخ در محور ایگرگ از سمت منفی



	int positionxrook = oldpos.x / size;



	int positionyrook = oldpos.y / size;



	if (m == 0 || m == 7)
	{
		int i = 0;


		NazdikXMosbat = 7;



		for (i = 0; i < 32; i++)



		{



			if (positionx[i] > positionxrook && (positiony[i] == positionyrook))



			{



				if (positionx[i] - positionxrook < NazdikXMosbat)



				{



					NazdikXMosbat = positionx[i] - positionxrook;






				}



			}



		}



		NazdikXManfi = -7;



		for (i = 0; i < 32; i++)



		{



			if (positionx[i] < positionxrook&&positiony[i] == positionyrook)



			{



				if (positionx[i] - positionxrook > NazdikXManfi)



				{



					NazdikXManfi = positionx[i] - positionxrook;



				}



			}



		}



		NazdikYMosbat = 7;



		for (i = 0; i < 32; i++)



		{



			if (positiony[i] > positionyrook&&positionx[i] == positionxrook)



			{



				if (positiony[i] - positionyrook < NazdikYMosbat)



				{



					NazdikYMosbat = positiony[i] - positionyrook;



				}



			}



		}



		NazdikYManfi = -7;



		for (i = 0; i < 32; i++)



		{



			if (positiony[i] < positionyrook&&positionx[i] == positionxrook)



			{



				if (positiony[i] - positionyrook > NazdikYManfi)



				{



					NazdikYManfi = positiony[i] - positionyrook;



				}



			}



		}







		for (i = NazdikXManfi; i <= NazdikXMosbat; i++)



		{



			if (newpos.x == oldpos.x + i*size&&newpos.y == oldpos.y)



			{



				return 1;



			}



		}







		int j;



		for (j = NazdikYManfi; j <= NazdikYMosbat; j++)



		{



			if (newpos.y == oldpos.y + j*size&&newpos.x == oldpos.x)



			{



				return 1;



			}



		}
	}
	if (m == 24 || m == 31)
	{
		int i = 0;



		NazdikXMosbat = 7;



		for (i = 0; i < 32; i++)



		{



			if (positionx[i] > positionxrook && (positiony[i] == positionyrook))



			{



				if (positionx[i] - positionxrook < NazdikXMosbat)



				{



					NazdikXMosbat = positionx[i] - positionxrook;







				}



			}



		}



		NazdikXManfi = -7;



		for (i = 0; i < 32; i++)



		{



			if (positionx[i] < positionxrook&&positiony[i] == positionyrook)



			{



				if (positionx[i] - positionxrook > NazdikXManfi)



				{



					NazdikXManfi = positionx[i] - positionxrook;



				}



			}



		}



		NazdikYMosbat = 7;



		for (i = 0; i < 32; i++)



		{



			if (positiony[i] > positionyrook&&positionx[i] == positionxrook)



			{



				if (positiony[i] - positionyrook < NazdikYMosbat)



				{



					NazdikYMosbat = positiony[i] - positionyrook;



				}



			}



		}



		NazdikYManfi = -7;



		for (i = 0; i < 32; i++)



		{



			if (positiony[i] < positionyrook&&positionx[i] == positionxrook)



			{



				if (positiony[i] - positionyrook > NazdikYManfi)



				{



					NazdikYManfi = positiony[i] - positionyrook;



				}



			}



		}







		for (i = NazdikXManfi; i <= NazdikXMosbat; i++)



		{



			if (newpos.x == oldpos.x + i*size&&newpos.y == oldpos.y)



			{



				return 1;



			}



		}







		int j;



		for (j = NazdikYManfi; j <= NazdikYMosbat; j++)



		{



			if (newpos.y == oldpos.y + j*size&&newpos.x == oldpos.x)



			{



				return 1;



			}



		}
	}



	







	return 0;



	/*for (int i = 1; i <= 7; i++)



	{



	if (( newpos.x == oldpos.x + i*size || newpos.x == oldpos.x - i*size) && newpos.y == oldpos.y)



	{



	return 1;



	}



	if ((newpos.y == oldpos.y + i*size || newpos.y == oldpos.y - i*size) && newpos.x == oldpos.x)



	{



	return 1;



	}



	}



	return 0;*/



}







int fil(std::string str, std::string position[])



{



	Vector2f oldpos = barkhord(str[0], str[1]);



	Vector2f newpos = barkhord(str[4], str[5]);







	Vector2f vectorPosition[32];



	for (int i = 0; i < 32; i++)



	{



		vectorPosition[i] = barkhord(position[i][0], position[i][1]);



	}







	int positionx[32];



	for (int x = 0; x < 32; x++)



	{



		positionx[x] = vectorPosition[x].x / size;



	}







	int positiony[32];



	for (int y = 0; y < 32; y++)



	{



		positiony[y] = vectorPosition[y].y / size;



	}







	int positionxfil = oldpos.x / size;



	int positionyfil = oldpos.y / size;







	int OribRastMosbat;



	int OribRastManfi;



	int OribChapMosbat;



	int OribChapManfi;







	int i = 0;



	OribRastMosbat = 7;



	for (i = 0; i < 32; i++)



	{



		if (positionx[i] - positionxfil > 0 && positiony[i] - positionyfil < 0)



		{



			if (abs(positionx[i] - positionxfil) == abs(positiony[i] - positionyfil))



			{



				if (positionx[i] - positionxfil < OribRastMosbat)



				{



					OribRastMosbat = positionx[i] - positionxfil;



				}



			}



		}



	}



	OribRastManfi = -7;



	for (i = 0; i < 32; i++)



	{



		if (positionx[i] - positionxfil < 0 && positiony[i] - positionyfil > 0)



		{



			if (abs(positionx[i] - positionxfil) == abs(positiony[i] - positionyfil))



			{



				if (positionx[i] - positionxfil > OribRastManfi)



				{



					OribRastManfi = positionx[i] - positionxfil;



				}



			}



		}



	}



	OribChapMosbat = 7;



	for (i = 0; i < 32; i++)



	{



		if (positionx[i] - positionxfil > 0 && positiony[i] - positionyfil > 0)



		{



			if (abs(positionx[i] - positionxfil) == abs(positiony[i] - positionyfil))



			{



				if (positionx[i] - positionxfil < OribChapMosbat)



				{



					OribChapMosbat = positionx[i] - positionxfil;



				}



			}



		}



	}



	OribChapManfi = -7;



	for (i = 0; i < 32; i++)



	{



		if (positionx[i] - positionxfil < 0 && positiony[i] - positionyfil < 0)



		{



			if (abs(positionx[i] - positionxfil) == abs(positiony[i] - positionyfil))



			{



				if (positionx[i] - positionxfil > OribChapManfi)



				{



					OribChapManfi = positionx[i] - positionxfil;



				}



			}



		}



	}



	for (i = OribRastManfi; i <= OribRastMosbat; i++)



	{



		if (newpos.x == oldpos.x + i*size&&newpos.y == oldpos.y - i*size)



		{



			return 1;



		}



	}



	for (i = OribChapManfi; i <= OribChapMosbat; i++)



	{



		if (newpos.x == oldpos.x + i*size&&newpos.y == oldpos.y + i*size)



		{



			return 1;



		}



	}



	return 0;



}







int vazir(std::string str, std::string position[])



{



	Vector2f oldpos = barkhord(str[0], str[1]);



	Vector2f newpos = barkhord(str[4], str[5]);







	Vector2f vectorPosition[32];



	for (int i = 0; i < 32; i++)



	{



		vectorPosition[i] = barkhord(position[i][0], position[i][1]);



	}







	int positionx[32];



	for (int x = 0; x < 32; x++)



	{



		positionx[x] = vectorPosition[x].x / size;



	}







	int positiony[32];



	for (int y = 0; y < 32; y++)



	{



		positiony[y] = vectorPosition[y].y / size;



	}







	int positionxvazir = oldpos.x / size;



	int positionyvazir = oldpos.y / size;







	int OribRastMosbat;



	int OribRastManfi;



	int OribChapMosbat;



	int OribChapManfi;



	int NazdikXMosbat;//نزدیک ترین مهره به رخ در محور ایکس از سمت مثبت



	int NazdikXManfi;//نزدیک به رخ در محور ایکس از سمت منفی



	int NazdikYMosbat;//نزدیک به رخ در محور ایگرگ از سمت مثبت



	int NazdikYManfi;//نزدیک به رخ در محور ایگرگ از سمت منفی







	int i = 0;



	OribRastMosbat = 7;



	for (i = 0; i < 32; i++)



	{



		if (positionx[i] - positionxvazir > 0 && positiony[i] - positionyvazir < 0)



		{



			if (abs(positionx[i] - positionxvazir) == abs(positiony[i] - positionyvazir))



			{



				if (positionx[i] - positionxvazir < OribRastMosbat)



				{



					OribRastMosbat = positionx[i] - positionxvazir;



				}



			}



		}



	}



	OribRastManfi = -7;



	for (i = 0; i < 32; i++)



	{



		if (positionx[i] - positionxvazir < 0 && positiony[i] - positionyvazir > 0)



		{



			if (abs(positionx[i] - positionxvazir) == abs(positiony[i] - positionyvazir))



			{



				if (positionx[i] - positionxvazir > OribRastManfi)



				{



					OribRastManfi = positionx[i] - positionxvazir;



				}



			}



		}



	}OribChapMosbat = 7;



	for (i = 0; i < 32; i++)



	{



		if (positionx[i] - positionxvazir > 0 && positiony[i] - positionyvazir > 0)



		{



			if (abs(positionx[i] - positionxvazir) == abs(positiony[i] - positionyvazir))



			{



				if (positionx[i] - positionxvazir < OribChapMosbat)



				{



					OribChapMosbat = positionx[i] - positionxvazir;



				}



			}



		}



	}



	OribChapManfi = -7;



	for (i = 0; i < 32; i++)



	{



		if (positionx[i] - positionxvazir < 0 && positiony[i] - positionyvazir < 0)



		{



			if (abs(positionx[i] - positionxvazir) == abs(positiony[i] - positionyvazir))



			{



				if (positionx[i] - positionxvazir > OribChapManfi)



				{



					OribChapManfi = positionx[i] - positionxvazir;



				}



			}



		}



	}



	NazdikXMosbat = 7;



	for (i = 0; i < 32; i++)



	{



		if (positionx[i] > positionxvazir && (positiony[i] == positionyvazir))



		{



			if (positionx[i] - positionxvazir < NazdikXMosbat)



			{



				NazdikXMosbat = positionx[i] - positionxvazir;







			}



		}



	}



	NazdikXManfi = -7;



	for (i = 0; i < 32; i++)



	{



		if (positionx[i] < positionxvazir&&positiony[i] == positionyvazir)



		{



			if (positionx[i] - positionxvazir > NazdikXManfi)



			{



				NazdikXManfi = positionx[i] - positionxvazir;



			}



		}



	}



	NazdikYMosbat = 7;



	for (i = 0; i < 32; i++)



	{



		if (positiony[i] > positionyvazir&&positionx[i] == positionxvazir)



		{



			if (positiony[i] - positionyvazir < NazdikYMosbat)



			{



				NazdikYMosbat = positiony[i] - positionyvazir;



			}



		}



	}



	NazdikYManfi = -7;



	for (i = 0; i < 32; i++)



	{



		if (positiony[i] < positionyvazir&&positionx[i] == positionxvazir)



		{



			if (positiony[i] - positionyvazir > NazdikYManfi)



			{



				NazdikYManfi = positiony[i] - positionyvazir;



			}



		}



	}



	for (i = OribRastManfi; i <= OribRastMosbat; i++)



	{



		if (newpos.x == oldpos.x + i*size&&newpos.y == oldpos.y - i*size)



		{



			return 1;



		}



	}



	for (i = OribChapManfi; i <= OribChapMosbat; i++)



	{



		if (newpos.x == oldpos.x + i*size&&newpos.y == oldpos.y + i*size)



		{



			return 1;



		}



	}



	for (i = NazdikXManfi; i <= NazdikXMosbat; i++)



	{



		if (newpos.x == oldpos.x + i*size&&newpos.y == oldpos.y)



		{



			return 1;



		}



	}







	int j;



	for (j = NazdikYManfi; j <= NazdikYMosbat; j++)



	{



		if (newpos.y == oldpos.y + j*size&&newpos.x == oldpos.x)



		{



			return 1;



		}



	}



	return 0;



}







int king(std::string str, std::string position[], int n)



{



	Vector2f oldpos = barkhord(str[0], str[1]);



	Vector2f newpos = barkhord(str[4], str[5]);







	Vector2f vectorPosition[32];



	for (int i = 0; i < 32; i++)



	{



		vectorPosition[i] = barkhord(position[i][0], position[i][1]);



	}







	int positionx[32];



	for (int x = 0; x < 32; x++)



	{



		positionx[x] = vectorPosition[x].x / size;



	}







	int positiony[32];



	for (int y = 0; y < 32; y++)



	{



		positiony[y] = vectorPosition[y].y / size;



	}







	int positionxKing = oldpos.x / size;



	int positionyKing = oldpos.y / size;



	int positionxNewKing = newpos.x / size;



	int positionyNewKing = newpos.y / size;







	/*int Chap = 1;



	int Rast = 1;



	int Bala = 1;



	int Paen = 1;



	int BalaRast = 1;



	int BalaChap = 1;



	int PaenRast = 1;



	int PaenChap = 1;



	int i;







	/*for (i = 0; i < 32; i++)



	{



	if (positionx[i] == positionxKing + 1 && positiony[i] == positionyKing)



	Rast = 0;



	if (positionx[i] == positionxKing + 1 && positiony[i] == positionyKing - 1)



	BalaRast = 0;



	if (positionx[i] == positionxKing     && positiony[i] == positionyKing - 1)



	Bala = 0;



	if (positionx[i] == positionxKing - 1 && positiony[i] == positionyKing - 1)



	BalaChap = 0;



	if (positionx[i] == positionxKing - 1 && positiony[i] == positionyKing)



	Chap = 0;



	if (positionx[i] == positionxKing - 1 && positiony[i] == positionyKing + 1)



	PaenChap = 0;



	if (positionx[i] == positionxKing     && positiony[i] == positionyKing + 1)



	Paen = 0;



	if (positionx[i] == positionxKing + 1 && positiony[i] == positionyKing + 1)



	PaenRast = 0;



	}*/



	for (int i = 0; i < 32; i++)

	{

		if (n == 28)

		{

			if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13 || i == 14 || i == 15)

			{

				if (i == 0 || i == 7 || i == 24 || i == 31)

				{

					if (positionxNewKing == positionx[i])

					{

						for (int j = 0; j < 32; j++)

						{

							if (positiony[i] < positiony[j] && positiony[j] < positionyNewKing || positionyNewKing<positiony[j] && positiony[j]<positiony[i])

							{

								goto l1;

							}

							else

							{



							}

						}

						return 0;

					}

				l1:

					if (positionyNewKing == positiony[i])

					{

						for (int j = 0; j < 32; j++)

						{

							if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing || positionxNewKing<positionx[j] && positionx[j]<positionx[i])

							{

								goto l2;

							}

							else

							{



							}

						}

						return 0;

					}



				}

			l2:

				if (i == 1 || i == 6 || i == 25 || i == 30)

				{

					if (positionxNewKing == positionx[i] + 1 && positionyNewKing == positiony[i] - 2)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] + 2 && positionyNewKing == positiony[i] - 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] + 2 && positionyNewKing == positiony[i] + 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] + 1 && positionyNewKing == positiony[i] + 2)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] - 1 && positionyNewKing == positiony[i] + 2)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] - 2 && positionyNewKing == positiony[i] + 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] - 2 && positionyNewKing == positiony[i] - 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] - 1 && positionyNewKing == positiony[i] - 2)

					{

						return 0;

					}

				}

				if (i == 2 || i == 5 || i == 26 || i == 29)

				{

					if (positionx[i] - positionxNewKing>0 && positiony[i] - positionyNewKing>0)

						if (positionx[i] - positionxNewKing == positiony[i] - positionyNewKing) {



							for (int j = 0; j < 32; j++)

							{

								if (positionx[i] - positionx[j]>0 && positiony[i] - positiony[j]>0)

									if (positionx[i] - positionx[j] == positiony[i] - positiony[j])

									{

										if (positionxNewKing < positionx[j] && positionx[j] < positionx[i])

										{

											goto l3;

										}

										else {



										}

									}

							}

							return 0;

						}

				l3:



					if (positionx[i] - positionxNewKing>0 && positionyNewKing - positiony[i]>0)

						if (positionx[i] - positionxNewKing == positionyNewKing - positiony[i])

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[i] - positionx[j]>0 && positiony[j] - positiony[i]>0)

									if (positionx[i] - positionx[j] == positiony[j] - positiony[i])

									{

										if (positionxNewKing < positionx[j] && positionx[j] < positionx[i])

										{

											goto l4;

										}

										else {



										}

									}

							}

							return 0;

						}

				l4:

					if (positionxNewKing - positionx[i]>0 && positionyNewKing - positiony[i])

						if (positionxNewKing - positionx[i] == positionyNewKing - positiony[i])

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[j] - positionx[i]>0 && positiony[j] - positiony[i]>0)

									if (positionx[j] - positionx[i] == positiony[j] - positiony[i])

									{

										if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing)

										{

											goto l5;

										}

										else {



										}

									}

							}

							return 0;

						}

				l5:

					if (positionxNewKing - positionx[i]>0 && positiony[i] - positionyNewKing>0)

						if (positionxNewKing - positionx[i] == positiony[i] - positionyNewKing)

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[j] - positionx[i]>0 && positiony[i] - positiony[j]>0)

									if (positionx[j] - positionx[i] == positiony[i] - positiony[j]>0)

									{

										if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing)

										{

											goto l6;

										}

										else {



										}

									}

							}

							return 0;

						}



				}

			l6:

				if (i == 3 || i == 27)

				{

					if (positionxNewKing == positionx[i])

					{

						for (int j = 0; j < 32; j++)

						{

							if (positiony[i] < positiony[j] && positiony[j] < positionyNewKing || positionyNewKing<positiony[j] && positiony[j]<positiony[i])

							{

								goto l7;

							}

							else

							{



							}

						}

						return 0;

					}

				l7:

					if (positionyNewKing == positiony[i])

					{

						for (int j = 0; j < 32; j++)

						{

							if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing || positionxNewKing<positionx[j] && positionx[j]<positionx[i])

							{

								goto l8;

							}

							else

							{



							}

						}

						return 0;

					}

				l8:

					if (positionx[i] - positionxNewKing>0 && positiony[i] - positionyNewKing>0)

						if (positionx[i] - positionxNewKing == positiony[i] - positionyNewKing) {



							for (int j = 0; j < 32; j++)

							{

								if (positionx[i] - positionx[j]>0 && positiony[i] - positiony[j]>0)

									if (positionx[i] - positionx[j] == positiony[i] - positiony[j])

									{

										if (positionxNewKing < positionx[j] && positionx[j] < positionx[i])

										{

											goto l9;

										}

										else {



										}

									}

							}

							return 0;

						}

				l9:



					if (positionx[i] - positionxNewKing>0 && positionyNewKing - positiony[i]>0)

						if (positionx[i] - positionxNewKing == positionyNewKing - positiony[i])

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[i] - positionx[j]>0 && positiony[j] - positiony[i]>0)

									if (positionx[i] - positionx[j] == positiony[j] - positiony[i])

									{

										if (positionxNewKing < positionx[j] && positionx[j] < positionx[i])

										{

											goto l10;

										}

										else {



										}

									}

							}

							return 0;

						}

				l10:

					if (positionxNewKing - positionx[i]>0 && positionyNewKing - positiony[i])

						if (positionxNewKing - positionx[i] == positionyNewKing - positiony[i])

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[j] - positionx[i]>0 && positiony[j] - positiony[i]>0)

									if (positionx[j] - positionx[i] == positiony[j] - positiony[i])

									{

										if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing)

										{

											goto l11;

										}

										else {



										}

									}

							}

							return 0;

						}

				l11:

					if (positionxNewKing - positionx[i]>0 && positiony[i] - positionyNewKing>0)

						if (positionxNewKing - positionx[i] == positiony[i] - positionyNewKing)

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[j] - positionx[i]>0 && positiony[i] - positiony[j]>0)

									if (positionx[j] - positionx[i] == positiony[i] - positiony[j]>0)

									{

										if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing)

										{

											goto l12;

										}

										else {



										}

									}

							}

							return 0;

						}



				}

			l12:

				if (i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13 || i == 14 || i == 15)

				{

					if (positionxNewKing == positionx[i] - 1 && positionyNewKing == positiony[i] + 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] + 1 && positionyNewKing == positiony[i] + 1)

					{

						return 0;

					}

				}

				if (i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 22 || i == 23)

				{

					if (positionxNewKing == positionx[i] - 1 && positionyNewKing == positiony[i] - 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] + 1 && positionyNewKing == positiony[i] - 1)

					{

						return 0;

					}

				}

			}

		}

		if (n == 4)

		{

			if (i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 22 || i == 23 || i == 24 || i == 25 || i == 26 || i == 27 || i == 28 || i == 29 || i == 30 || i == 31)

			{

				if (i == 0 || i == 7 || i == 24 || i == 31)

				{

					if (positionxNewKing == positionx[i])

					{

						for (int j = 0; j < 32; j++)

						{

							if (positiony[i] < positiony[j] && positiony[j] < positionyNewKing || positionyNewKing<positiony[j] && positiony[j]<positiony[i])

							{

								goto l13;

							}

							else

							{



							}

						}

						return 0;

					}

				l13:

					if (positionyNewKing == positiony[i])

					{

						for (int j = 0; j < 32; j++)

						{

							if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing || positionxNewKing<positionx[j] && positionx[j]<positionx[i])

							{

								goto l14;

							}

							else

							{



							}

						}

						return 0;

					}



				}

			l14:

				if (i == 1 || i == 6 || i == 25 || i == 30)

				{

					if (positionxNewKing == positionx[i] + 1 && positionyNewKing == positiony[i] - 2)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] + 2 && positionyNewKing == positiony[i] - 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] + 2 && positionyNewKing == positiony[i] + 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] + 1 && positionyNewKing == positiony[i] + 2)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] - 1 && positionyNewKing == positiony[i] + 2)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] - 2 && positionyNewKing == positiony[i] + 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] - 2 && positionyNewKing == positiony[i] - 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] - 1 && positionyNewKing == positiony[i] - 2)

					{

						return 0;

					}

				}

				if (i == 2 || i == 5 || i == 26 || i == 29)

				{

					if (positionx[i] - positionxNewKing>0 && positiony[i] - positionyNewKing>0)

						if (positionx[i] - positionxNewKing == positiony[i] - positionyNewKing) {



							for (int j = 0; j < 32; j++)

							{

								if (positionx[i] - positionx[j]>0 && positiony[i] - positiony[j]>0)

									if (positionx[i] - positionx[j] == positiony[i] - positiony[j])

									{

										if (positionxNewKing < positionx[j] && positionx[j] < positionx[i])

										{

											goto l15;

										}

										else {



										}

									}

							}

							return 0;

						}

				l15:



					if (positionx[i] - positionxNewKing>0 && positionyNewKing - positiony[i]>0)

						if (positionx[i] - positionxNewKing == positionyNewKing - positiony[i])

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[i] - positionx[j]>0 && positiony[j] - positiony[i]>0)

									if (positionx[i] - positionx[j] == positiony[j] - positiony[i])

									{

										if (positionxNewKing < positionx[j] && positionx[j] < positionx[i])

										{

											goto l16;

										}

										else {



										}

									}

							}

							return 0;

						}

				l16:

					if (positionxNewKing - positionx[i]>0 && positionyNewKing - positiony[i])

						if (positionxNewKing - positionx[i] == positionyNewKing - positiony[i])

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[j] - positionx[i]>0 && positiony[j] - positiony[i]>0)

									if (positionx[j] - positionx[i] == positiony[j] - positiony[i])

									{

										if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing)

										{

											goto l17;

										}

										else {



										}

									}

							}

							return 0;

						}

				l17:

					if (positionxNewKing - positionx[i]>0 && positiony[i] - positionyNewKing>0)

						if (positionxNewKing - positionx[i] == positiony[i] - positionyNewKing)

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[j] - positionx[i]>0 && positiony[i] - positiony[j]>0)

									if (positionx[j] - positionx[i] == positiony[i] - positiony[j]>0)

									{

										if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing)

										{

											goto l18;

										}

										else {



										}

									}

							}

							return 0;

						}



				}

			l18:

				if (i == 3 || i == 27)

				{

					if (positionxNewKing == positionx[i])

					{

						for (int j = 0; j < 32; j++)

						{

							if (positiony[i] < positiony[j] && positiony[j] < positionyNewKing || positionyNewKing<positiony[j] && positiony[j]<positiony[i])

							{

								goto l19;

							}

							else

							{



							}

						}

						return 0;

					}

				l19:

					if (positionyNewKing == positiony[i])

					{

						for (int j = 0; j < 32; j++)

						{

							if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing || positionxNewKing<positionx[j] && positionx[j]<positionx[i])

							{

								goto l20;

							}

							else

							{



							}

						}

						return 0;

					}

				l20:

					if (positionx[i] - positionxNewKing>0 && positiony[i] - positionyNewKing>0)

						if (positionx[i] - positionxNewKing == positiony[i] - positionyNewKing) {



							for (int j = 0; j < 32; j++)

							{

								if (positionx[i] - positionx[j]>0 && positiony[i] - positiony[j]>0)

									if (positionx[i] - positionx[j] == positiony[i] - positiony[j])

									{

										if (positionxNewKing < positionx[j] && positionx[j] < positionx[i])

										{

											goto l21;

										}

										else {



										}

									}

							}

							return 0;

						}

				l21:



					if (positionx[i] - positionxNewKing>0 && positionyNewKing - positiony[i]>0)

						if (positionx[i] - positionxNewKing == positionyNewKing - positiony[i])

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[i] - positionx[j]>0 && positiony[j] - positiony[i]>0)

									if (positionx[i] - positionx[j] == positiony[j] - positiony[i])

									{

										if (positionxNewKing < positionx[j] && positionx[j] < positionx[i])

										{

											goto l22;

										}

										else {



										}

									}

							}

							return 0;

						}

				l22:

					if (positionxNewKing - positionx[i]>0 && positionyNewKing - positiony[i])

						if (positionxNewKing - positionx[i] == positionyNewKing - positiony[i])

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[j] - positionx[i]>0 && positiony[j] - positiony[i]>0)

									if (positionx[j] - positionx[i] == positiony[j] - positiony[i])

									{

										if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing)

										{

											goto l23;

										}

										else {



										}

									}

							}

							return 0;

						}

				l23:

					if (positionxNewKing - positionx[i]>0 && positiony[i] - positionyNewKing>0)

						if (positionxNewKing - positionx[i] == positiony[i] - positionyNewKing)

						{

							for (int j = 0; j < 32; j++)

							{

								if (positionx[j] - positionx[i]>0 && positiony[i] - positiony[j]>0)

									if (positionx[j] - positionx[i] == positiony[i] - positiony[j]>0)

									{

										if (positionx[i] < positionx[j] && positionx[j] < positionxNewKing)

										{

											goto l24;

										}

										else {



										}

									}

							}

							return 0;

						}



				}

			l24:

				if (i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13 || i == 14 || i == 15)

				{

					if (positionxNewKing == positionx[i] - 1 && positionyNewKing == positiony[i] + 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] + 1 && positionyNewKing == positiony[i] + 1)

					{

						return 0;

					}

				}

				if (i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 22 || i == 23)

				{

					if (positionxNewKing == positionx[i] - 1 && positionyNewKing == positiony[i] - 1)

					{

						return 0;

					}

					if (positionxNewKing == positionx[i] + 1 && positionyNewKing == positiony[i] - 1)

					{

						return 0;

					}

				}

			}

		}



	}













	if (newpos.x == oldpos.x + 1 * size&&newpos.y == oldpos.y + 0 * size)



		return 1;



	if (newpos.x == oldpos.x + 1 * size&&newpos.y == oldpos.y - 1 * size)



		return 1;



	if (newpos.x == oldpos.x + 0 * size&&newpos.y == oldpos.y - 1 * size)



		return 1;



	if (newpos.x == oldpos.x - 1 * size&&newpos.y == oldpos.y - 1 * size)



		return 1;



	if (newpos.x == oldpos.x - 1 * size&&newpos.y == oldpos.y + 0 * size)



		return 1;



	if (newpos.x == oldpos.x - 1 * size&&newpos.y == oldpos.y + 1 * size)



		return 1;



	if (newpos.x == oldpos.x + 0 * size&&newpos.y == oldpos.y + 1 * size)



		return 1;



	if (newpos.x == oldpos.x + 1 * size&&newpos.y == oldpos.y + 1 * size)



		return 1;











	return 0;



}



int sarbaz(std::string str, std::string position[], int whiteOrBlack)



//if pawn is black put 0 and if it is white put 1.



{



	Vector2f oldpos = barkhord(str[0], str[1]);



	Vector2f newpos = barkhord(str[4], str[5]);







	Vector2f vectorPosition[32];



	int positionxpawn = oldpos.x / size;



	int positionypawn = oldpos.y / size;







	for (int i = 0; i < 32; i++)



	{



		vectorPosition[i] = barkhord(position[i][0], position[i][1]);



	}







	int positionx[32];



	for (int i = 0; i < 32; i++)



	{



		positionx[i] = vectorPosition[i].x / size;



	}







	int positiony[32];



	for (int i = 0; i < 32; i++)



	{



		positiony[i] = vectorPosition[i].y / size;



	}







	int nearelement = 3;//range of movment of pawn







	for (int i = 0; i < 32; i++)



	{



		if (whiteOrBlack)



		{



			if ((positionx[i] == positionxpawn) && (positiony[i]>positionypawn))



			{



				if ((positiony[i] - positionypawn)< nearelement)



				{



					nearelement == (positiony[i] - positionypawn);



				}















			}



		}//for white pawn



		else



		{



			if ((positionx[i] == positionxpawn) && (positiony[i] < positionypawn))



			{



				if ((positionypawn - positiony[i]) < nearelement)



				{



					nearelement == (positiony[i] - positionypawn);



				}



			}







		}//for black pawn







	}



	if (whiteOrBlack == 0)



	{



		if (positionypawn != 1)//if it is not in its initial place



		{



			if (nearelement > 2) nearelement = 2;



		}



		int newx = newpos.x / size;



		int newy = newpos.y / size;







		if ((newx - positionxpawn) == 1 || (newx - positionxpawn) == -1)// if hit possible



		{



			if (newy - positionypawn == 1)



			{



				for (int i = 0; i < 32; i++)



				{



					if (positionx[i] == newx && positiony[i] == newy)



					{



						return 1;



					}







				}







			}











		}



		if ((nearelement > newy - positionypawn) && (newy - positionypawn > 0))



		{



			if (newx == positionxpawn)



			{



				return 1;



			}







		}











	}



	else



	{



		int newx = newpos.x / size;



		int newy = newpos.y / size;







		if (newx - positionxpawn == 1 || newx - positionxpawn == -1)// if hit is possible



		{



			if (newy - positionypawn == -1)



			{



				for (int i = 0; i < 32; i++)



				{



					if (positionx[i] == newx && positiony[i] == newy)



					{



						return 1;



					}







				}







			}











		}



		if (positionypawn != 6)//if it is not in its initial place



		{



			if (nearelement > 2) nearelement = 2;



		}







		if ((nearelement > -((newpos.y / size) - positionypawn)) && ((newpos.y / size) - positionypawn < 0))



		{



			if ((newpos.x / size) == positionxpawn)



			{



				return 1;



			}







		}







	}



	return 0;























}















int main()



{

	//start page. 



	RenderWindow start(VideoMode(501, 503), "chess start menu");



	Texture background, starticon, axe, armor, setting;



	setting.setSmooth(true);



	starticon.setSmooth(true);



	axe.loadFromFile("images/axe.png");



	armor.loadFromFile("images/armor.png");



	background.loadFromFile("images/woodenbackground[1].jpg");



	starticon.loadFromFile("images/horse.png");



	Sprite back(background);



	back.setScale(0.5, 0.5);



	Sprite iconstart(starticon);//start icon



	iconstart.setPosition(100, 272);



	Sprite axeiconr(axe);//axes in the background.



	axeiconr.setScale(1, 0.81);



	axeiconr.rotate(40);



	axeiconr.setPosition(235, 30);



	Sprite axeiconl(axe);



	axeiconl.rotate(-40);



	axeiconl.setScale(1, 0.80);



	axeiconl.setPosition(8, 87);



	Sprite armorI(armor);//armor in background



	armorI.setPosition(310, 120);



	Vector2f startposition = iconstart.getPosition();//start icon position.



	SoundBuffer press;



	press.loadFromFile("audio/start pressed.wav");



	Sound spress(press);



	Font h;//loading font.



	h.loadFromFile("font/Hey Milenia Demo.otf");



	Text queen(" queen ", h, 40);//set a text.



	Text rookh("rook", h, 40);



	Text knight("knight ", h, 40);



	Text bishop("bishop", h, 40);



	int isclose = 0;



	while (start.isOpen())

	{

		start.setFramerateLimit(60);



		Vector2i pos = Mouse::getPosition(start);//position of mouse



		if (pos.x - startposition.x>0 && pos.x - startposition.x<100)//if mouse was on start icon.

		{

			if ((pos.y - startposition.y) > 0 && (pos.y - startposition.y) < 100)

			{



				iconstart.setScale(1.1, 1.1);

			}



			else

			{

				iconstart.setScale(1, 1);

			}





		}

		else

		{



			iconstart.setScale(1, 1);

		}



		Event state;

		while (start.pollEvent(state))

		{







			switch (state.type)

			{

			case Event::Closed:

				//RenderWindow exitQ(VideoMode(200,100)," exit ");



				isclose = 1;



				start.close();



				break;



			case Event::MouseButtonPressed:

				if (state.key.code == Mouse::Left)

				{



					if (pos.x - startposition.x>0 && pos.x - startposition.x<100)

					{

						if ((pos.y - startposition.y) > 0 && (pos.y - startposition.y) < 100)

						{

							spress.Sound::play();



							start.close();

						}



					}



				}

				break;



			default:



				break;

			}



		}

		start.clear(Color::Black);



		start.draw(back);



		start.draw(iconstart);



		start.draw(axeiconr);



		start.draw(axeiconl);



		start.draw(armorI);



		//start.draw(t);

		start.display();



	}



	// game window 



	RenderWindow window(VideoMode(453, 453), "chess");



	SoundBuffer footstep, wrong;



	footstep.loadFromFile("audio/footsteps.wav");



	wrong.loadFromFile("audio/wrongmove.wav");



	Sound FAILURE;



	Sound movement;



	FAILURE.setBuffer(wrong);



	movement.setBuffer(footstep);



	// movement.Sound::play();//for playing a sound



	Texture t1, t2;



	t1.loadFromFile("images/figures.png");



	t2.loadFromFile("images/board0.png");



	Sprite s(t1);



	Sprite sboard(t2);







	for (int i = 0; i < 32; i++)



		f[i].setTexture(t1);







	loadposition();







	bool isMove = false;



	float dx = 0, dy = 0;



	Vector2f oldpos, newpos;



	std::string str;



	int n = 0;







	while (window.isOpen())



	{



		Vector2i pos = Mouse::getPosition(window);







		/*std::string position[32];



		for (int y = 0; y < 32; y++)



		{



		Vector2f mogeiat = f[y].getPosition();



		position[y] = tochessnote(mogeiat);



		}



		/*for (int y = 0; y < 32; y++)



		{



		std::cout << position[y] << "\n";



		}*/







		Event e;



		while (window.pollEvent(e))



		{



			if (e.type == Event::Closed)



				window.close();















			if (e.type == Event::MouseButtonPressed)



				if (e.key.code == Mouse::Left)



					for (int i = 0; i<32; i++)



						if (f[i].getGlobalBounds().contains(pos.x, pos.y))



						{



							isMove = true; n = i;



							dx = pos.x - f[i].getPosition().x;



							dy = pos.y - f[i].getPosition().y;



							oldpos = f[i].getPosition();



							//std::cout << i<<"\n";



						}



			if (e.type == Event::MouseButtonReleased)



				if (e.key.code == Mouse::Left)



				{



					isMove = false;



					Vector2f p = f[n].getPosition() + Vector2f(size / 2, size / 2);



					newpos = Vector2f(size*int(p.x / size), size*int(p.y / size));



					str = tochessnote(oldpos) + "->" + tochessnote(newpos);







					static int CounterOfMovement = 1;



					if (CounterOfMovement % 2 == 1)

					{

						if (n == 16 || n == 17 || n == 18 || n == 19 || n == 20 || n == 21 || n == 22 || n == 23 || n == 24 || n == 25 || n == 26 || n == 27 || n == 28 || n == 29 || n == 30 || n == 31)

						{



							std::string position[32];//برای موقعیت یابی مهره ها که چئن بدرد اسب نمیخورد از اینحا کدش رو زدم



							for (int y = 0; y < 32; y++)



							{



								Vector2f mogeiat = f[y].getPosition();



								position[y] = tochessnote(mogeiat);



							}



							if (n == 1 || n == 6 || n == 25 || n == 30)



							{



								int a = asb(str, position, n);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else {



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}











							if (n == 0 || n == 7 || n == 24 || n == 31)



							{



								int a = rook(str, position,n);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else



								{



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}



							if (n == 2 || n == 5 || n == 26 || n == 29)



							{



								int a = fil(str, position);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else



								{



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}



							if (n == 3 || n == 27)



							{



								int a = vazir(str, position);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);





									CounterOfMovement++;

								}



								else {



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}



							if (n == 28 || n == 4)



							{



								int a = king(str, position, 28);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else {



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}



							if (n == 16 || n == 17 || n == 18 || n == 19 || n == 20 || n == 21 || n == 22 || n == 23)



							{



								int a = sarbaz(str, position, 1);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else



								{



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}



							if (n == 8 || n == 9 || n == 10 || n == 11 || n == 12 || n == 13 || n == 14 || n == 15)



							{



								int a = sarbaz(str, position, 0);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else



								{



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}







							}







						}

						else {

							std::cout << "Wrong Move\n";



							f[n].setPosition(oldpos);



						}

					}



					else

					{

						if (n == 0 || n == 1 || n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 10 || n == 11 || n == 12 || n == 13 || n == 14 || n == 15)

						{



							std::string position[32];//برای موقعیت یابی مهره ها که چئن بدرد اسب نمیخورد از اینحا کدش رو زدم



							for (int y = 0; y < 32; y++)



							{



								Vector2f mogeiat = f[y].getPosition();



								position[y] = tochessnote(mogeiat);



							}





							if (n == 1 || n == 6 || n == 25 || n == 30)



							{



								int a = asb(str, position, n);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else {



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}











							if (n == 0 || n == 7 || n == 24 || n == 31)



							{



								int a = rook(str, position,n);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else



								{



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}



							if (n == 2 || n == 5 || n == 26 || n == 29)



							{



								int a = fil(str, position);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else



								{



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}



							if (n == 3 || n == 27)



							{



								int a = vazir(str, position);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else {



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}



							if (n == 28 || n == 4)



							{



								int a = king(str, position, 4);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else {



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}



							if (n == 16 || n == 17 || n == 18 || n == 19 || n == 20 || n == 21 || n == 22 || n == 23)



							{



								int a = sarbaz(str, position, 1);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else



								{



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}



							}



							if (n == 8 || n == 9 || n == 10 || n == 11 || n == 12 || n == 13 || n == 14 || n == 15)



							{



								int a = sarbaz(str, position, 0);



								if (a == 1)



								{



									std::cout << str << "\n";



									move(str);



									f[n].setPosition(newpos);



									CounterOfMovement++;



								}



								else



								{



									std::cout << "Wrong Move\n";



									f[n].setPosition(oldpos);



								}







							}







						}

						else {



							std::cout << "Wrong Move\n";



							f[n].setPosition(oldpos);

						}

					}
					std::string position[32];//برای موقعیت یابی مهره ها که چئن بدرد اسب نمیخورد از اینحا کدش رو زدم



					for (int y = 0; y < 32; y++)



					{



						Vector2f mogeiat = f[y].getPosition();



						position[y] = tochessnote(mogeiat);



					}

					Vector2f vectorPosition[32];



					for (int i = 0; i < 32; i++)



					{



						vectorPosition[i] = barkhord(position[i][0], position[i][1]);



					}







					int positionx[32];



					for (int x = 0; x < 32; x++)



					{



						positionx[x] = vectorPosition[x].x / size;



					}







					int positiony[32];



					for (int y = 0; y < 32; y++)



					{



						positiony[y] = vectorPosition[y].y / size;



					}


					for (int i = 0; i < 32; i++)
					{
						if (i == 0 || i == 7)
						{
							if (positionx[i] == positionx[28])
							{
								if (positiony[i] - positiony[28] > 0)
								{
									for (int j = 0; j < 32; j++)
									{
										if (positiony[i] - positiony[j] > 0&&positionx[j]==positionx[28])
										{
											if (positiony[i] - positiony[28] <= positiony[i] - positiony[j])
											{
												std::cout << "KISH...........................................";
											}
										}
									}
								}
							}
						}
						if (i == 0 || i == 7)
						{
							if (positionx[i] == positionx[28])
							{
								if (positiony[i] - positiony[28] < 0)
								{
									for (int j = 0; j < 32; j++)
									{
										if (positiony[i] - positiony[j] < 0&&positionx[j]==positionx[28])
										{
											if (abs(positiony[i] - positiony[28]) <=abs( positiony[i] - positiony[j]))
											{
												std::cout << "KISH...........................................";
											}
										}
									}
								}
							}
						}

						if (i == 0 || i == 7)
						{
							if (positiony[i] == positiony[28])
							{
								if (positionx[i] - positionx[28] > 0)
								{
									for (int j = 0; j < 32; j++)
									{
										if (positionx[i] - positionx[j] > 0&&positiony[j]==positiony[28])
										{
											if (abs(positionx[i] - positionx[28]) <=abs( positionx[i] - positionx[j]))
											{
												std::cout << "KISH...........................................";
											}
										}
									}
								}
							}
						}
						if (i == 0 || i == 7)
						{
							if (positiony[i] == positiony[28])
							{
								if (positionx[i] - positionx[28] < 0)
								{
									for (int j = 0; j < 32; j++)
									{
										if (positionx[i] - positionx[j] < 0&&positiony[i]==positiony[j])
										{
											if (abs(positionx[i] - positionx[28]) <abs( positionx[i] - positionx[j]))
											{
												std::cout << "KISH...........................................";
											}
										}
									}
								}
							}
						}
						
						if (i == 24 || i == 31)
						{
							if (positionx[i] == positionx[4])
							{
								if (positiony[i] - positiony[4] > 0)
								{
									for (int j = 0; j < 32; j++)
									{
										if (positiony[i] - positiony[j] > 0 && positionx[j] == positionx[4])
										{
											if (positiony[i] - positiony[4] <= positiony[i] - positiony[j])
											{
												std::cout << "KISH...........................................";
											}
										}
									}
								}
							}
						}
						if (i == 24 || i == 31)
						{
							if (positionx[i] == positionx[4])
							{
								if (positiony[i] - positiony[4] < 0)
								{
									for (int j = 0; j < 32; j++)
									{
										if (positiony[i] - positiony[j] < 0 && positionx[j] == positionx[4])
										{
											if (abs(positiony[i] - positiony[28]) <= abs(positiony[i] - positiony[j]))
											{
												std::cout << "KISH...........................................";
											}
										}
									}
								}
							}
						}

						if (i == 24 || i == 31)
						{
							if (positiony[i] == positiony[4])
							{
								if (positionx[i] - positionx[4] > 0)
								{
									for (int j = 0; j < 32; j++)
									{
										if (positionx[i] - positionx[j] > 0 && positiony[j] == positiony[4])
										{
											if (abs(positionx[i] - positionx[4]) <= abs(positionx[i] - positionx[j]))
											{
												std::cout << "KISH...........................................";
											}
										}
									}
								}
							}
						}
						if (i == 24 || i == 31)
						{
							if (positiony[i] == positiony[4])
							{
								if (positionx[i] - positionx[4] < 0)
								{
									for (int j = 0; j < 32; j++)
									{
										if (positionx[i] - positionx[j] < 0 && positiony[i] == positiony[j])
										{
											if (abs(positionx[i] - positionx[4]) <abs(positionx[i] - positionx[j]))
											{
												std::cout << "KISH...........................................";
											}
										}
									}
								}
							}
						}
						
					}
					
					/*if (n == 1 || n == 6 || n == 25 || n == 30)



					{



					int a = asb(str);



					if (a == 1)



					{



					std::cout << str << "\n";



					f[n].setPosition(newpos);



					}



					else {



					std::cout << "Wrong Move\n";



					f[n].setPosition(oldpos);



					}



					}







					std::string position[32];//برای موقعیت یابی مهره ها که چئن بدرد اسب نمیخورد از اینحا کدش رو زدم



					for (int y = 0; y < 32; y++)



					{



					Vector2f mogeiat = f[y].getPosition();



					position[y] = tochessnote(mogeiat);



					}



					if (n == 0 || n == 7 || n == 24 || n == 31)



					{



					int a = rook(str, position);



					if (a == 1)



					{



					std::cout << str << "\n";



					f[n].setPosition(newpos);



					}



					else



					{



					std::cout << "Wrong Move\n";



					f[n].setPosition(oldpos);



					}



					}



					if (n == 2 || n == 5 || n == 26 || n == 29)



					{



					int a = fil(str, position);



					if (a == 1)



					{



					std::cout << str << "\n";



					f[n].setPosition(newpos);



					}



					else



					{



					std::cout << "Wrong Move\n";



					f[n].setPosition(oldpos);



					}



					}



					if (n == 3 || n == 27)



					{



					int a = vazir(str, position);



					if (a == 1)



					{



					std::cout << str << "\n";



					f[n].setPosition(newpos);



					}



					else {



					std::cout << "Wrong Move\n";



					f[n].setPosition(oldpos);



					}



					}



					if (n == 28 || n == 4)



					{



					int a = king(str, position);



					if (a == 1)



					{



					std::cout << str << "\n";



					f[n].setPosition(newpos);



					}



					else {



					std::cout << "Wrong Move\n";



					f[n].setPosition(oldpos);



					}



					}



					if (n == 16 || n == 17 || n == 18 || n == 19 || n == 20 || n == 21 || n == 22 || n == 23)



					{



					int a = sarbaz(str, position, 1);



					if (a == 1)



					{



					std::cout << str << "\n";



					f[n].setPosition(newpos);



					}



					else



					{



					std::cout << "Wrong Move\n";



					f[n].setPosition(oldpos);



					}



					}



					if (n == 8 || n == 9 || n == 10 || n == 11 || n == 12 || n == 13 || n == 14 || n == 15)



					{



					int a = sarbaz(str, position, 0);



					if (a == 1)



					{



					std::cout << str << "\n";



					f[n].setPosition(newpos);



					}



					else



					{



					std::cout << "Wrong Move\n";



					f[n].setPosition(oldpos);



					}







					}*/











					//std::cout << str << "\n";



					//f[n].setPosition(newpos);



				}







		}



		if (isMove) f[n].setPosition(pos.x - dx, pos.y - dy);







		window.clear();



		window.draw(sboard);



		for (int i = 0; i < 32; i++)



			window.draw(f[i]);



		window.display();



	}



	return 0;



}