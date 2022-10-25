#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace sf;
bool pause = false;
float times = 0;
bool pressedEnter = false;

RenderWindow window;


int menu() {
	Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, aboutTexture, helpTexture, menuBackground, iozicTexture1, iozicTexture2, iozicTexture3, iozicTexture4;
	iozicTexture1.loadFromFile("Photo/dik3KamE.png");
	iozicTexture2.loadFromFile("Photo/10.png");
	iozicTexture3.loadFromFile("Photo/30nqxvl0.png");
	iozicTexture4.loadFromFile("Photo/sticker_vk_shunya_019.png");

	menuTexture1.loadFromFile("Photo/start GAME.png");
	menuTexture2.loadFromFile("Photo/about.png");
	menuTexture3.loadFromFile("Photo/hELP.png");
	menuTexture4.loadFromFile("Photo/exit.png");

	aboutTexture.loadFromFile("Photo/Aboute.jpg");
	helpTexture.loadFromFile("Photo/ХЕЛЬП.jpg");

	menuBackground.loadFromFile("Photo/IOZIKFON.jpg");

	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), about(aboutTexture), help(helpTexture), menuBg(menuBackground), iozic1(iozicTexture1), iozic2(iozicTexture2), iozic3(iozicTexture3), iozic4(iozicTexture4);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(80, 30+100);
	menu2.setPosition(100, 190 + 100);
	menu3.setPosition(100, 330 +100);
	menu4.setPosition(100, 470 + 100);
	menuBg.setPosition(0, 0);


	iozic1.setPosition(400, 30 + 100);
	iozic2.setPosition(400, 190 + 100);
	iozic3.setPosition(400, 330 + 100);
	iozic4.setPosition(400, 470 + 100);


	////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		Event event;

		while (window.pollEvent(event))

		{

			if (event.type == Event::Closed)


				window.close();

		}

		menuNum = 0;
		window.clear(Color(129, 181, 221));
		if (IntRect(80, 30 + 100, 300, 100).contains(Mouse::getPosition(window))) { menuNum = 1; }
		if (IntRect(100, 190 + 100, 300, 100).contains(Mouse::getPosition(window))) { menuNum = 2; }
		if (IntRect(100, 330 + 100, 300, 100).contains(Mouse::getPosition(window))) { menuNum = 3; }
		if (IntRect(100, 470 + 100, 300, 100).contains(Mouse::getPosition(window))) { menuNum = 4; }
		if (Mouse::isButtonPressed(Mouse::Left))

		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.draw(help); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 4) { window.close(); isMenu = false;
			}
		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.display();
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




}


float offsetX = 0, offsetY = 0;//перемотка карты или скролинг(смещение)

int ground = 1080;
const int H = 145;
const int W = 44;



std::string TileMap[H] = {
"   9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999",
"   9                                                                                                                                            9",
"   9                                                                                                                                            9",
"   9                                                                                                                                            9",
"   9                                                                                                                                            9",
"   9                                                                                                                                            9",
"   9                                                                                                                                            9",
"   9                                                                                                                                            9",
"   9                                                                                                                                     O   I  9",
"   9                                                                                                                            V  O QQQQQQQQQQQ9",
"   9                                                                                                                           WWWWW QQQQQQQQQQQ9",
"   9                                                                                                                                 QQQQQQQQQQQ9",
"   9                                                                                                                 O  VV           QQQQQQQQQQQ9",
"   9                                                                                                              WWWWWWWW           QQQQQQQQQQQ9",
"   9                                                                                                                                 QQQQQQQQQQQ9",
"   9                                                                                               VVV                               QQQQQQQQQQQ9",
"   9                                                                                              WWWWW                              QQQQQQQQQQQ9",
"   9                                                                                                                                 QQQQQQQQQQQ9",
"   9                                                                                                      VVV                        QQQQQQQQQQQ9",
"   9                                                                                                     WWWWW                       QQQQQQQQQQQ9",
"   9                                                                     VV                                                          QQQQQQQQQQQ9",
"   9                                                                V   WWWW                      VVV                                QQQQQQQQQQQ9",
"   9                                                            V   W                 VV         WWWWW                               QQQQQQQQQQQ9",
"   9                                                        V   W               V    WWWW   VV                                       QQQQQQQQQQQ9",//S-КАМНИ
"   9                                                    V   W                  WWW         WWWW                                      QQQQQQQQQQQ9",//E-ЛАВА
"   9                            Q                   V   W                                                                            QQQQQQQQQQQ9",//M ; D -ВОДА
"   9               V           QQ   V               W                                                                                QQQQQQQQQQQ9",//Y-КОЛЮЧКА
"   9             WWWWW        QQQ  WWW                                                                                               QQQQQQQQQQQ9",//I-МОНЕТКА
"   T                         QQQQ              O                                                                                     QQQQQQQQQQQ9",//V-Яблочко
"   9                        QQQQQ          QQQQQQQQQQQQQQQQQQQQQQ                                                                    QQQQQQQQQQQ9",//O-МУХОМОР
"   9         QQ  O V V V   QQQQQQMMMMMMMMMMMMQQQQQQQQQQQQQQQQQQQQ                                                                    QQQQQQQQQQQ9",//Q-ЯЩИКИ
"BBBBBBBBBBBBBBBBBBBBBBBBEEESSSSSSDDDDDDDDDDDDSSSSSSSSSSSSSSSSSSSSYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYQQQQQQQQQQQ9",//W-ПОЛОЧКИ 
"PPPPPPPPPPPPPPPPPPPPPPPPEEESSSSSSDDDDDDDDDDDDSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSP9",
"SSSSSSSSSSSSSSSSSSSSSSSEEEEESSSSSDDDDDDDDDDDDSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS9",
"SSSSSSSSSSSSSSSSSSSSSSEEEEEEESSSSDDDDDDDDDDDDSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS9",
"SSSSSSSSSSSSSSSSSSSSSEEEEEEEEESSSDDDDDDDDDDDDSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS9",
"SSSSSSSSSSSSSSSSSSSSEEEEEEEEESSSSDDDDDDDDDDDDSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS9",//B-ТРАВА
"EEEEEEEEEEEEEEEEEEEEEEEEEEESSSSSSSSSSSSSSSSSSSSSSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE9",
"EEEEEEEEEEEEEEEEEEEEEEEEESSSSSSSSSSSSSSSSSSSSSSSSSEEEEESSSSSSSSSSSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE9",
"EEEEEEEEEEEEEEEEEEEEEEEEEEEESSSSSSSSSSSSSSSSSSSSSSEEEEESSSSSSSSSSSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE9",
"EEEEEEEEEEEEEEEEEEEEEEEEEEEESSSSSSSSSSSSSSSSSSSSSSEEEEESSSSSSSSSSSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE9",
"EEEEEEEEEEEEEEEEEEEEEEEEEEEESSSSSSSSSSSSSSSSSSSSSSEEEEESSSSSSSSSSSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE9",
"EEEEEEEEEEEEEEEEEEEEEEEEEEEESSSSSSSSSSSSSSSSSSSSSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE9",//P-ЗЕМЛЯ
};


class PLAYER {


public:

	PLAYER(String F, int X, int Y, float W, float H) {

		playerScore = 0;
		adren = 0;
		winy = 0.0;
		win = false;
		adrenalin = false;
		life = true;
	}
	int  playerScore = 0;//новая переменная, хранящая очки игрока



	float dx, dy;//Скорость
	FloatRect rect;// Координаты, ширина , высота.
	bool  onGround;// Переменная говорит на земле мы или нет
	Sprite sprite;
	float currentFrame, health = 100;// Текущий кадр для анимации
	bool life = true;
	bool adrenalin = false;
	bool win = false;

	float adren = 0;
	float winy = 0.0;

	PLAYER(Texture &image)
	{



		sprite.setTexture(image);


		rect = FloatRect(7 * 32, 9 * 32, 54, 45);

		dx = dy = 0.1;
		currentFrame = 1;
	}

	void update(float time)

	{
		rect.left += dx * time;// ось x

		Collision(0);////////////

		if (!onGround) dy = dy + 0.0005*time;// Если мы не на земле то падаем с ускорениес 0.0005
		rect.top += dy * time;// Прибавляем это к координате у _______________ ось y
		onGround = false;

		Collision(1);////////////

		if (rect.top > ground) { rect.top = ground; dy = 0; onGround = true; }

		currentFrame += 0.005*time;
		if (currentFrame > 3) currentFrame -= 3;//3 кадров
		if (dx > 0) sprite.setTextureRect(IntRect(65 * int(currentFrame), 10, 54, 45));
		if (dx < 0) sprite.setTextureRect(IntRect(65 * int(currentFrame) + 54, 10, -54, 45));// Отзеркалили картинку


		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
		dx = 0;
		if (health <= 0) {
			life = false;
		}
		if (adren >= 26) { adrenalin = true; }
		if (winy >= 1000) { win = true; }


	}
	void Collision(int kvak)//либо то либо то
		//проходимся в цикле по плиткам
		// A S N - пустые
	{
		for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
			for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
			{
				if (TileMap[i][j] == 'Q')

				{
					if ((dx > 0) && (kvak == 0)) rect.left = j * 32 - rect.width;//  rect.left -x ???? rect.width ширина ёжика
					if ((dx < 0) && (kvak == 0)) rect.left = j * 32 + 32;

					if ((dy > 0) && (kvak == 1)) { rect.top = i * 32 - rect.height;  onGround = true; }// координата выше высоты ежика
					if ((dy < 0) && (kvak == 1)) { rect.top = i * 32 + 32; }
				}

				if (TileMap[i][j] == 'T')

				{
					if ((dx > 0) && (kvak == 0)) rect.left = j * 32 - rect.width;
					if ((dx < 0) && (kvak == 0)) rect.left = j * 32 + rect.width;

					if ((dy > 0) && (kvak == 1)) { rect.top = i * 32 - rect.height;  onGround = true; }
					if ((dy < 0) && (kvak == 1)) { rect.top = i * 32 + rect.height; }

				}

				if (TileMap[i][j] == '9')

				{
					if ((dx > 0) && (kvak == 0)) rect.left = j * 32 - rect.width;
					if ((dx < 0) && (kvak == 0)) rect.left = j * 32 + 32;

					if ((dy > 0) && (kvak == 1)) { rect.top = i * 32 - rect.height;  onGround = true; }
					if ((dy < 0) && (kvak == 1)) { rect.top = i * 32 + 32; }
				}
				if (TileMap[i][j] == 'W')

				{

					if ((dx > 0) && (kvak == 0)) rect.left = j * 32 - rect.width;
					if ((dx < 0) && (kvak == 0)) rect.left = j * 32 + 32;

					if ((dy > 0) && (kvak == 1)) { rect.top = i * 32 - rect.height;  onGround = true; }
					if ((dy < 0) && (kvak == 1)) { rect.top = i * 32 + 32; }
				}
				if (TileMap[i][j] == 'B')

				{
					if ((dx > 0) && (kvak == 0)) rect.left = j * 32 - rect.width;
					if ((dx < 0) && (kvak == 0)) rect.left = j * 32 + 32;

					if ((dy > 0) && (kvak == 1)) { rect.top = i * 32 - rect.height; onGround = true; }
					if ((dy < 0) && (kvak == 1)) { rect.top = i * 32 + 32; }
				}

				if (TileMap[i][j] == 'O')
				{
					health = health - 50;
					TileMap[i][j] = 'N';//МУХОМОР
				}

				if (TileMap[i][j] == 'V') {
					adren = adren + 1;
					playerScore++;
					TileMap[i][j] = 'A';//ЯБЛОКО
				}
				if (TileMap[i][j] == 'D') {

					health = 0;

				}
				if (TileMap[i][j] == 'E') {
					health = 0;


					if ((dx > 0) && (kvak == 0)) rect.left = j * 32 - rect.width;
					if ((dx < 0) && (kvak == 0)) rect.left = j * 32 + 32;

					if ((dy > 0) && (kvak == 1)) { rect.top = i * 32 - rect.height; onGround = true; }
					if ((dy < 0) && (kvak == 1)) { rect.top = i * 32 + 32; }
				}
				if (TileMap[i][j] == 'Y') {
					health = 0;


					if ((dx > 0) && (kvak == 0)) rect.left = j * 32 - rect.width;
					if ((dx < 0) && (kvak == 0)) rect.left = j * 32 + 32;

					if ((dy > 0) && (kvak == 1)) { rect.top = i * 32 - rect.height; onGround = true; }
					if ((dy < 0) && (kvak == 1)) { rect.top = i * 32 + 32; }//dir взаимодействует с Collision
				}

				//++++++++++++++++++++++++++++++++++++++++++++++++
				if (TileMap[i][j] == 'I') {
					winy = winy + 1000;
					//***************************************
					TileMap[i][j] = 'L';//МОНЕТКА
				}

				//++++++++++++++++++++++++++++++++++++++++++++++++
			}
		if (!life)  sprite.setTextureRect(IntRect(52, 103, 48, 39));


	}

};


////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////MENU////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


bool startMenu() {

	menu();//вызов меню
	return 0;
}

bool startGame() {

	Font font;//шрифт 
	font.loadFromFile("Photo/480.ttf");//передаем нашему шрифту файл шрифта
	Text text(" ", font, 70);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setStyle(sf::Text::Bold);//жирный  текст
	text.setFillColor(sf::Color::Yellow);


	//menu(window);//вызов меню

	Texture tile;

	tile.loadFromFile("Photo/Tiles for map.png");

	Sprite s_tile;

	s_tile.setTexture(tile);

	Texture t;// Создалем текстуру
	PLAYER p(t);
	t.loadFromFile("Photo/iozik.png"); //Загружаем картинку из файла

	float currentFrame = 0;

	Clock clock;

	RectangleShape rectangle(Vector2f(32, 32));


	Texture   fonTexture;

	fonTexture.loadFromFile("Photo/untitled.png");

	Sprite  fon(fonTexture);
	bool pause = false;
	float times = 0;
	bool pressedEnter = false;


	while (window.isOpen())
	{
		window.draw(fon);
		if (Keyboard::isKeyPressed(Keyboard::Enter)) {
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {


			for (int i = 0; i < W; i++)
				for (int j = 0; j < H; j++)
				{

					if (TileMap[i][j] == 'N') { TileMap[i][j] = 'O'; }

					if (TileMap[i][j] == 'A') {
						TileMap[i][j] = 'V';
					}

					if (TileMap[i][j] == 'L') {
						TileMap[i][j] = 'I';
					}

				}
			offsetX = 0; offsetY = 0;
			startGame();
		}

		if (Keyboard::isKeyPressed(Keyboard::Space)) {

			if (!pressedEnter) {
				pressedEnter = true;

				

				pause ? pause = false : pause = true;
			
			}


		}
		else  pressedEnter = false;
		float time = clock.getElapsedTime().asMicroseconds();
		if (!pause) {

			if (p.life) {

				if (p.win == false) {
					times += clock.getElapsedTime().asMilliseconds() / 1000.F;
				}



				if (times >= 50) { p.life = false; }
			}

		}
		if (pause) {
		
			text.setString("Пауза");//задаем строку тексту и вызываем 
			text.setPosition(410, 250);//задаем позицию текста, центр камеры

			window.draw(text);//рисую этот текст

		}

		clock.restart().asMilliseconds();

		std::cout << p.winy << std::endl;

		time = time / 900;

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//////////////////////////////////////////////////////////////////////////////////////УПРАВЛЕНИЕ ИГРОКОМ !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		if (!p.win && !pause) {



			if (p.life) {
				if (Keyboard::isKeyPressed(Keyboard::Left))//Если мы нажимаем на клавишу лево
				{
					p.dx = -0.1;
				}
				if (Keyboard::isKeyPressed(Keyboard::Right))//Если мы нажимаем на клавишу право 
				{
					p.dx = 0.1;
				}
				if (p.adrenalin) {
					if (Keyboard::isKeyPressed(Keyboard::Up))//Если мы нажимаем на клавишу верх
					{
						if (p.onGround) { p.dy = -0.50; }// Если мы на земле то только тогда мы сможем прыгнуть
					}
				}
				else {
					if (Keyboard::isKeyPressed(Keyboard::Up))//Если мы нажимаем на клавишу верх
					{
						if (p.onGround) { p.dy = -0.35; }// Если мы на земле то только тогда мы сможем прыгнуть
					}
				}

			}
		}

		//..............................................................................................................................................................................................
		//..............................................................................................................................................................................................
		//..............................................................................................................................................................................................

		if (!pause) p.update(time);


		//Привязываем камеру к игроку
		if (p.rect.left > 1300 / 2) offsetX = p.rect.left - 1300 / 2;
		if (p.rect.top > 800 / 1.6)offsetY = p.rect.top - 800 / 1.6;




		for (int i = 0; i < W; i++)
			for (int j = 0; j < H; j++)
			{
				if (TileMap[i][j] == 'T')  s_tile.setTextureRect(IntRect(339, 75, 120, 115));// ДОМИК

				if (TileMap[i][j] == 'Q')  s_tile.setTextureRect(IntRect(154, 681, 32, 32));

				if (TileMap[i][j] == 'M')  s_tile.setTextureRect(IntRect(203, 564, 32, 32));
				if (TileMap[i][j] == 'D')  s_tile.setTextureRect(IntRect(242, 564, 32, 32));
				if (TileMap[i][j] == 'W')  s_tile.setTextureRect(IntRect(186, 294, 32, 32));
				if (TileMap[i][j] == 'Y')  s_tile.setTextureRect(IntRect(86, 361, 35, 35));

				if (TileMap[i][j] == 'B')  s_tile.setTextureRect(IntRect(186, 425, 32, 32));

				if (TileMap[i][j] == 'O')  s_tile.setTextureRect(IntRect(69, 700, 55, 35));

				if (TileMap[i][j] == 'V')  s_tile.setTextureRect(IntRect(80, 734, 30, 25));

				if (TileMap[i][j] == 'P')  s_tile.setTextureRect(IntRect(37, 566, 32, 32));

				if (TileMap[i][j] == 'H')  s_tile.setTextureRect(IntRect(159, 719, 15, 15));
				if (TileMap[i][j] == 'E')  s_tile.setTextureRect(IntRect(210, 160, 32, 32));

				if (TileMap[i][j] == 'S')  s_tile.setTextureRect(IntRect(337, 510, 32, 32));

				if (TileMap[i][j] == 'q')  s_tile.setTextureRect(IntRect(103, 166, 32, 32));
				if (TileMap[i][j] == 'I')  s_tile.setTextureRect(IntRect(95, 626, 22, 16));
				if (TileMap[i][j] == ' ') continue;

				if (TileMap[i][j] == 'A') continue;
				if (TileMap[i][j] == 'L') continue;
				if (TileMap[i][j] == 'N') continue;

				if (TileMap[i][j] == '9') continue;



				s_tile.setPosition(j * 32 - offsetX, i * 32 - offsetY);
				window.draw(s_tile);

			}


		if (p.life) {
			std::ostringstream playerScoreString;    // объявили переменную
			playerScoreString << p.playerScore;		//занесли в нее число очков
			text.setString("Собрано яблок:" + playerScoreString.str());//задаем строку тексту и вызываем 
			text.setPosition(20, 20);//задаем позицию текста, центр камеры
			window.draw(text);//рисую этот текст
		}

		else {
			std::ostringstream playerScoreString;    // объявили переменную

			text.setString("Игра окончена");//задаем строку тексту и вызываем 
			text.setPosition(410, 250);//задаем позицию текста, центр камеры

			window.draw(text);//рисую этот текст

		}

		if (p.win) {
			text.setString("Победа!");//задаем строку тексту и вызываем 
			text.setPosition(410, 250);//задаем позицию текста, центр камеры

			window.draw(text);//рисую этот текст
		}
		std::ostringstream playerHealthString, gameTimeString;    // объявили переменную здоровья и времени
		playerHealthString << p.health; gameTimeString << (int)times;		//формируем строку
		text.setString("Здоровье: " + playerHealthString.str() + "\nВремя игры: " + gameTimeString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()
		text.setPosition(20, 90);//задаем позицию текста, отступая от центра камеры
		window.draw(text);//рисую этот текст

		window.draw(p.sprite);
		window.display();
	}

}

int main()

{
	window.create(VideoMode(1300, 800), "SFML TestAPP!");
	window.setFramerateLimit(60);
	startMenu();
	startGame();

	return 0;

}