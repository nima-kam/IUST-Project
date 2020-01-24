#include<iostream>
#include<conio.h>
#include<string>
#include <SFML/Graphics.hpp>
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
			f[i].setPosition(-100, -100);

	for (int i = 0; i < 32; i++)
		if (f[i].getPosition() == oldpos)
			f[i].setPosition(newpos);
}

int asb(std::string str)
{
	Vector2f oldpos = barkhord(str[0], str[1]);
	Vector2f newpos = barkhord(str[4], str[5]);
	if (newpos.x == size + oldpos.x&&newpos.y == oldpos.y - 2 * size)
		return 1;
	if (newpos.x == oldpos.x + 2 * size&&newpos.y == oldpos.y - size)
		return 1;
	if (newpos.x == oldpos.x + 2 * size&&newpos.y == oldpos.y + size)
		return 1;
	if (newpos.x == oldpos.x + size&&newpos.y == oldpos.y + 2 * size)
		return 1;
	if (newpos.x == oldpos.x - size&&newpos.y == oldpos.y + 2 * size)
		return 1;
	if (newpos.x == oldpos.x - 2 * size&&newpos.y == oldpos.y + size)
		return 1;
	if (newpos.x == oldpos.x - 2 * size&&newpos.y == oldpos.y - size)
		return 1;
	if (newpos.x == oldpos.x - size&&newpos.y == oldpos.y - 2 * size)
		return 1;

	return 0;
}

int rook(std::string str,std::string position[])
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
		positionx[x] = vectorPosition[x].x/size;
	}
	
	int positiony[32];
	for (int y = 0; y < 32; y++)
	{
		positiony[y] = vectorPosition[y].y/size;
	}

	int NazdikXMosbat;//نزدیک ترین مهره به رخ در محور ایکس از سمت مثبت
	int NazdikXManfi;//نزدیک به رخ در محور ایکس از سمت منفی
	int NazdikYMosbat;//نزدیک به رخ در محور ایگرگ از سمت مثبت
	int NazdikYManfi;//نزدیک به رخ در محور ایگرگ از سمت منفی
	int positionxrook=oldpos.x/size;
	int positionyrook = oldpos.y / size;

	int i=0;
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
	}OribChapMosbat = 7;
	for (i = 0; i < 32; i++)
	{
		if (positionx[i] - positionxfil > 0 && positiony[i] - positionyfil > 0)
		{
			if (abs(positionx[i] - positionxfil) == abs(positiony[i] - positionyfil))
			{
				if (positionx[i] - positionxfil > OribChapMosbat)
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

int main()
{
	RenderWindow window(VideoMode(453, 453), "chess");

	Texture t1,t2;
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
				if(e.key.code==Mouse::Left)
					for(int i=0;i<32;i++)
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
					move(str);
					if (n == 1 || n == 6 || n == 25 || n == 30)
					{
						int a=asb(str);
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

					std::string position[32];
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