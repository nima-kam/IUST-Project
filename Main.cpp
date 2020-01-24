#include<iostream>
//#include<conio.h>
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


std::string tochessnote(Vector2f p)
{
	std::string s = "";
	s += char(p.x / size + 97);
	s += char(7 - p.y / size + 49);
	return s;
}

void loadposition()
{
	int k = 0;
	for(int i=0;i<8;i++)
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


int main()
{
	RenderWindow window(VideoMode(453, 453), "chess");

	Texture t1,t2;
	t1.loadFromFile("image/figures.png");
	t2.loadFromFile("image/board0.png");

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
					}
			if (e.type == Event::MouseButtonReleased)
				if (e.key.code == Mouse::Left)
				{
					isMove = false;
					Vector2f p = f[n].getPosition() + Vector2f(size / 2, size / 2);
					newpos = Vector2f(size*int(p.x / size), size*int(p.y / size));
					str = tochessnote(oldpos) + "->" + tochessnote(newpos);
					move(str);
					std::cout << str << "\n";
					f[n].setPosition(newpos);
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