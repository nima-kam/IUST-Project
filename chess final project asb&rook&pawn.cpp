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
Vector2f blackpawnplace =f[8].getPosition();//a black pawn initial place
Vector2f whitepawnplace =f[16].getPosition();//a white pawn initial place

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
		if (newpos.x== (f[i].getPosition().x)&&newpos.y==f[i].getPosition().y)
			f[i].setPosition(-100, -100);

	for (int i = 0; i < 32; i++)
		if ( oldpos.x== f[i].getPosition().x && oldpos.y== f[i].getPosition().y )
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
	int positionxrook= oldpos.x / size;
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
		if (positionx[i] < positionxrook && positiony[i] == positionyrook)
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
int sarbaz(std::string str,std::string position[],int whiteOrBlack)
//if pawn is black put 0 and if it is white put 1.
{
	Vector2f oldpos = barkhord(str[0], str[1]);
	Vector2f newpos = barkhord(str[4], str[5]);

	Vector2f vectorPosition[32];
	int positionxpawn= oldpos.x / size;
	int positionypawn = oldpos.y / size;

	for (int i = 0; i < 32; i++)
	{
		vectorPosition[i] = barkhord(position[i][0], position[i][1]);
	}

	int positionx[32];
	for (int i = 0; i < 32; i++)
	{
		positionx[i] = vectorPosition[i].x/size;
	}
	
	int positiony[32];
	for (int i = 0; i < 32; i++)
	{
		positiony[i] = vectorPosition[i].y/size;
	}

	int nearelement=3;//range of movment of pawn

	for (int i = 0; i < 32; i++)
	{
		if(whiteOrBlack)
		{
			if ((positionx[i]==positionxpawn)&&(positiony[i]>positionypawn))
			{
				if ((positiony[i]-positionypawn)< nearelement)
				{
					nearelement == (positiony[i]-positionypawn);
				}

		

			}
		}//for white pawn
		else
		{
			if ((positionx[i]==positionxpawn) && (positiony[i] < positionypawn))
			{
				if ((positionypawn-positiony[i]) < nearelement)
				{
					nearelement == (positiony[i]-positionypawn);
				}
			}

		}//for black pawn
		
	}
	if(whiteOrBlack==0)
	{	
		if(positionypawn!=1 )//if it is not in its initial place
		{
			if(nearelement > 2) nearelement=2;
		}
		int newx =newpos.x/size;
		int newy =newpos.y/size;

		if((newx-positionxpawn)== 1 || (newx-positionxpawn)==-1)// if hit possible
		{
			if (newy-positionypawn==1)
			{
				for (int i = 0; i < 32; i++)
				{
					if (positionx[i]==newx && positiony[i]==newy)
					{
						return 1;
					}
					
				}
				
			}
				

		}
		if( (nearelement > newy-positionypawn) && (newy-positionypawn > 0))
		{
			if(newx == positionxpawn  )
			{
				return 1;
			}
			
		}
		

	}
	else
	{
		int newx = newpos.x/size;
		int newy = newpos.y/size;
		
		if(newx-positionxpawn== 1 || newx-positionxpawn==-1)// if hit is possible
		{
			if (newy-positionypawn == -1)
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
		if(positionypawn!=6)//if it is not in its initial place
		{
			if(nearelement > 2) nearelement=2;
		}
		
		if( (nearelement > -((newpos.y/size)-positionypawn)) && ((newpos.y/size)-positionypawn < 0))
		{
			if((newpos.x/size) == positionxpawn  )
			{
				return 1;
			}
			
		}
		
	}
	return 0;
	




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

					std::string position[32];//position of all elements
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
					if(n==16||n==17||n==18||n==19||n==20||n==21||n==22||n==23)
					{
						int a = sarbaz(str, position,1);
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
					if(n==8||n==9||n==10||n==11||n==12||n==13||n==14||n==15)
					{
						int a = sarbaz(str, position,0);
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