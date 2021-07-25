#include <graphics.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>
#include <iostream>
#include <charconv>
#include <windows.h>
#include <fstream>

using namespace std;

int track = -300;       //White line speed
int page = 0;           //Next page create
int cx = 0, ms = 10;    //MS- Shift 10 px in left right //CX- Update according to MS
int m1x, m2x, m1y, m2y; //Mid points //M1 bike headlight //M2 enemy car

int b = 0;

int random = 355 + (rand() % 51);

int z = 0;                                  // To maintain the speed of car and road with every new page/window
float j = 0.1;                              // To increase speed of enemy car after a certain score/level
int number = 0;                             // Score
int ecarspeed = 0;                          // To maintain speed of enemy car after increase in speed
char num_char[1000 + sizeof(char)] = {"0"}; // To update score on graphics window
int level = 20;                             // Level according to points. It will update according to points and according to this speed of enemy car increase
int flag = 0;

char num_score[1000 + sizeof(char)] = {"0"};

int dis(int mid1x, int mid1y, int mid2x, int mid2y) // Distance between enemy and bike
{
    int s = 0;
    s = sqrt(pow((mid2x - mid1x), 2) + pow((mid2y - mid1y), 2));
    return s;
}

void enemycar() // Enemy car body
{
    setcolor(RED);
    setfillstyle(1, 4);
    rectangle(random, 100 + b + z + j, random + 100, 200 + b + z + j);
    floodfill(random + 1, 101 + b + z + j, RED);

    setcolor(YELLOW);
    setfillstyle(1, YELLOW);
    rectangle(random + 15, 210 + b + z + j, random + 35, 200 + b + z + j);
    floodfill(random + 16, 201 + b + z + j, YELLOW);

    setcolor(YELLOW);
    setfillstyle(1, YELLOW);
    rectangle(random + 65, 210 + b + z + j, random + 85, 200 + b + z + j);
    floodfill(random + 76, 201 + b + z + j, YELLOW);

    setcolor(BROWN);
    setfillstyle(1, BLACK);
    rectangle(random - 10, 105 + b + z + j, random, 135 + b + z + j);
    floodfill(random - 10 + 1, 106 + b + z + j, BROWN);

    setcolor(BROWN);
    setfillstyle(1, BLACK);
    rectangle(random + 100, 105 + b + z + j, random + 110, 135 + b + z + j);
    floodfill(random + 101, 106 + b + z + j, BROWN);

    setcolor(BROWN);
    setfillstyle(1, BLACK);
    rectangle(random - 10, 155 + b + z + j, random, 185 + b + z + j);
    floodfill(random - 10 + 1, 156 + b + z + j, BROWN);

    setcolor(BROWN);
    setfillstyle(1, BLACK);
    rectangle(random + 100, 155 + b + z + j, random + 110, 185 + b + z + j);
    floodfill(random + 101, 156 + b + z + j, BROWN);

    setcolor(BROWN);
    setfillstyle(1, LIGHTRED);
    rectangle(random + 10, 90 + b + z + j, random + 90, 100 + b + z + j);
    floodfill(random + 11, 91 + b + z + j, BROWN);

    m2x = (random + random + 100) / 2;
    m2y = ((2 * (b + z + j)) + 300) / 2;
}

int main()

{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    srand(time(NULL)); // To avoid generating same random value

    fstream high;

    int temp;

    string name;
    cout << "Enter Your Name: ";
    cin >> name;

label:

    high.open("highscore.txt", ios::out | ios::in);

    high >> temp;

    high.close();

    track = -300;

    page = 0;
    cx = 0, ms = 10;
    m1x, m2x, m1y, m2y;

    b = 0; //o = 0;
    random = 355 + (rand() % 51);

    z = 0;
    j = 0.1;
    number = 0;
    ecarspeed = 0;

    char num_char[1000 + sizeof(char)] = {"0"};
    level = 20;
    flag = 0;

    SetConsoleTextAttribute(h, 10);
    cout << "Press 1 to Start." << endl;

    SetConsoleTextAttribute(h, 11);
    cout << "Press 2 for Instruction" << endl;

    SetConsoleTextAttribute(h, 4);
    cout << "Press 0 to exit." << endl;

    SetConsoleTextAttribute(h, 7);
    cin >> flag;

    if (flag == 1)

    {

        m1x = m2x = m1y = m2y = 0;

        initwindow(1000, 1000, "BIKE GAME"); // Graphics black window (1000 x 1000)

        int life = 4;

        while (life > 0)
        {

            setactivepage(page);     // Current page
            setvisualpage(1 - page); // Next coming page  // To avoid flickering

            std::to_chars(num_char, num_char + 1000, number); // To convert score in string

            b = b + 20;
            //o = o + 20;
            delay(100 - z);

            cleardevice();

            setcolor(6);
            rectangle(0, 0, 1000, 1000); // Green background (1000 X 1000)
            setfillstyle(1, GREEN);
            floodfill(1, 1, 6);

            // Road black backgroung

            setcolor(WHITE);
            rectangle(350, -1, 650, 1000);
            setfillstyle(11, LIGHTGRAY);
            floodfill(351, 0, WHITE);

            // Line on road (White)

            for (int i = 0; i < 1000; i += 99)
            {
                rectangle(490, -150 + i + track, 520, -100 + i + track);
                setfillstyle(SOLID_FILL, WHITE);
                floodfill(491, -149 + track + i, WHITE);
            }

            track += 40; // To shift white lines 40 px ahead

            // Trees (Left)

            for (int i = 0; i < 1000; i += 200)
            {
                line(105 + 175, 200 + i - 105 + track, 105 + 175, 290 + i - 105 + track);
                line(145 + 175, 200 + i - 105 + track, 145 + 175, 290 + i - 105 + track);
                line(105 + 175, 290 + i - 105 + track, 145 + 175, 290 + i - 105 + track);

                line(75 + 175, 200 + i - 105 + track, 175 + 175, 200 + i - 105 + track);
                line(75 + 175, 200 + i - 105 + track, 100 + 175, 170 + i - 105 + track);
                line(175 + 175, 200 + i - 105 + track, 150 + 175, 170 + i - 105 + track);
                line(100 + 175, 170 + i - 105 + track, 80 + 175, 170 + i - 105 + track);
                line(150 + 175, 170 + i - 105 + track, 170 + 175, 170 + i - 105 + track);
                line(80 + 175, 170 + i - 105 + track, 105 + 175, 140 + i - 105 + track);
                line(170 + 175, 170 + i - 105 + track, 145 + 175, 140 + i - 105 + track);
                line(105 + 175, 140 + i - 105 + track, 90 + 175, 140 + i - 105 + track);
                line(145 + 175, 140 + i - 105 + track, 160 + 175, 140 + i - 105 + track);
                line(90 + 175, 140 + i - 105 + track, 125 + 175, 105 + i - 105 + track);
                line(160 + 175, 140 + i - 105 + track, 125 + 175, 105 + i - 105 + track);
                setfillstyle(1, 6);
                floodfill(115 + 175, 210 + i - 105 + track, WHITE);

                setfillstyle(1, 10);
                floodfill(100 + 175, 150 + i - 105 + track, WHITE);

                setfillstyle(1, 10);
                floodfill(105 + 175, 150 + i - 105 + track, WHITE);
            }

            // Trees (Right)

            for (int i = 0; i < 1000; i += 200)
            {
                line(105 + 575, 200 + i - 105 + track, 105 + 575, 290 + i - 105 + track);
                line(145 + 575, 200 + i - 105 + track, 145 + 575, 290 + i - 105 + track);
                line(105 + 575, 290 + i - 105 + track, 145 + 575, 290 + i - 105 + track);

                line(75 + 575, 200 + i - 105 + track, 175 + 575, 200 + i - 105 + track);
                line(75 + 575, 200 + i - 105 + track, 100 + 575, 170 + i - 105 + track);
                line(175 + 575, 200 + i - 105 + track, 150 + 575, 170 + i - 105 + track);
                line(100 + 575, 170 + i - 105 + track, 80 + 575, 170 + i - 105 + track);
                line(150 + 575, 170 + i - 105 + track, 170 + 575, 170 + i - 105 + track);
                line(80 + 575, 170 + i - 105 + track, 105 + 575, 140 + i - 105 + track);
                line(170 + 575, 170 + i - 105 + track, 145 + 575, 140 + i - 105 + track);
                line(105 + 575, 140 + i - 105 + track, 90 + 575, 140 + i - 105 + track);
                line(145 + 575, 140 + i - 105 + track, 160 + 575, 140 + i - 105 + track);
                line(90 + 575, 140 + i - 105 + track, 125 + 575, 105 + i - 105 + track);
                line(160 + 575, 140 + i - 105 + track, 125 + 575, 105 + i - 105 + track);
                setfillstyle(1, 6);
                floodfill(115 + 575, 210 + i - 105 + track, WHITE);

                setfillstyle(1, 10);
                floodfill(100 + 575, 150 + i - 105 + track, WHITE);

                setfillstyle(1, 10);
                floodfill(105 + 575, 150 + i - 105 + track, WHITE);
            }

            if (track > 100)
                track = 0;

            // For life and points (To print life on graphics window)

            settextstyle(6, 0, 2);
            outtextxy(5, 10, "LIFE : ");
            outtextxy(5, 40, "POINTS : ");

            // To update life circles

            for (int i = 100; i <= 160 - ((4 - life) * 20); i += 20)
            {
                setfillstyle(8, WHITE);
                circle(i, 20, 8);
                floodfill(i + 1, 21, WHITE);
                setfillstyle(8, WHITE);
            }
            outtextxy(150, 40, num_char);

            // Controls

            if (GetAsyncKeyState(VK_LEFT))
                cx -= ms;
            if (GetAsyncKeyState(VK_RIGHT))
                cx += ms;

            settextstyle(8, 0, 1);
            setcolor(YELLOW);
            outtextxy(685, 10, "WE CHALLENGE YOU YOU CAN NOT ");
            outtextxy(710, 30, "SCORE MORE THAN 220 POINTS");

            outtextxy(780, 70, "Highest Score : ");

            std::to_chars(num_score, num_score + 1000, temp);
            outtextxy(950, 70, num_score);

            // Bike body

            setcolor(YELLOW);
            setfillstyle(1, YELLOW);
            rectangle(450 + cx, 678, 470 + cx, 695);
            floodfill(451 + cx, 679, YELLOW);

            m1x = ((470 + cx) + (450 + cx)) / 2;
            m1y = ((695 + 678) / 2);

            setcolor(BROWN);
            setfillstyle(1, BLACK);
            ellipse(460 + cx, 760, 0, 360, 11, 8);
            floodfill(461 + cx, 761, BROWN);

            setcolor(RED);
            setfillstyle(1, RED);
            rectangle(445 + cx, 700, 475 + cx, 760);
            floodfill(446 + cx, 701, RED);
            setcolor(BLACK);
            setfillstyle(1, BROWN);
            ellipse(460 + cx, 730, 0, 360, 14, 27);
            floodfill(461 + cx, 731, BLACK);

            setcolor(RED);
            setfillstyle(1, BLACK);
            rectangle(435 + cx, 695, 485 + cx, 700);
            floodfill(446 + cx, 696, RED);

            enemycar();

            if (b >= 950)
            {
                number = number + 5;
                b = 0;
                random = 360 + (rand() % 190);
                z + 10;
                j = 0;
            }

            // Checking if accident happens

            if ((dis(m1x, m1y, m2x, m2y)) < 50) // Enemy car accident
            {
                life--; // If accident happens 1 life decreases

                if (life > 0)
                {
                    {
                        setvisualpage(1 - 1 - page); // To display Be careful message on already created page
                        settextstyle(10, 0, 4);
                        outtextxy(250, 350, "!!BE CAREFUL NEXT TIME!!");
                        delay(1000);
                    }

                    delay(1000);
                    if ((470 + cx) <= 500)
                        cx = cx + 100;
                    else if (500 < (450 + cx))
                        cx = cx - 100;
                }

                else
                {
                    setvisualpage(1 - 1 - page); // To display game over message on already created page
                    setcolor(YELLOW);
                    settextstyle(10, 0, 4);
                    outtextxy(360, 350, " !!GAME OVER!! ");
                    outtextxy(450, 650, num_char);
                    cout << "\a";
                    delay(100);

                    if (temp <= number)
                    {
                        high.open("highscore.txt", ios::out | ios::trunc);
                        high << number;
                        high.close();
                    }

                    closegraph();

                    cout << "Do you want to play again (0 for no , 1 for yes) : ";
                    int a;
                    cin >> a;

                    if (a == 1)
                        goto label;

                    else
                    {
                        exit(0);
                    }
                }
            }

            if (cx <= (-105) || cx >= 175) // Road side accident
            {
                life--;

                if (life > 0)
                {
                    delay(1000);
                    if (cx > 175)
                    {
                        cx = cx - 100;

                        setcolor(YELLOW);
                        settextstyle(10, 0, 4);
                        outtextxy(250, 350, "!!BE CAREFUL NEXT TIME!!");
                        setvisualpage(1 - 1 - page);
                    }
                    else if (cx < (-105))
                    {
                        cx = cx + 100;
                        setvisualpage(1 - 1 - page);
                        setcolor(YELLOW);
                        settextstyle(10, 0, 4);
                        outtextxy(250, 350, "!!BE CAREFUL NEXT TIME!!");
                        delay(1000);
                    }
                }

                else
                {
                    setvisualpage(1 - 1 - page);

                    setcolor(YELLOW);
                    settextstyle(10, 0, 4);
                    outtextxy(360, 350, " !!GAME OVER!! ");
                    outtextxy(450, 650, num_char);
                    cout << "\a";
                    delay(100);

                    if (temp <= number)
                    {
                        high.open("highscore.txt", ios::out | ios::trunc);
                        high << number;
                        high.close();
                    }

                    closegraph();

                    cout << "Do you want to play again (0 for no , 1 for yes) : ";
                    int a;
                    cin >> a;

                    if (a == 1)
                        goto label;

                    else
                    {
                        exit(0);
                    }
                }
            }

            setcolor(YELLOW);
            settextstyle(10, 1, 3);
            outtextxy(30, 300, "* AIML PROJECT *");
            if (number >= level)
            {
                level = level + 5;

                ecarspeed = 1.5 + ecarspeed;
            }
            j = j + ecarspeed;

            page = 1 - page;
        }

        getch();
    }
    else if (flag == 2)
    {
        cout << endl
             << endl;
        cout << "\t\t\t\t\tInstructions" << endl;
        cout << endl
             << endl;
        cout << "This is a bike racing game in which you must avoid obstacles while earning points for each obstacle avoided. You have four lives in total, and at the end of the game, it will tell your score as well as the name and score of the highest scorer." << endl;
        cout << "As the bike advances, it gets more and more points, increasing the speed of the obstacles." << endl;
        cout << endl;
        cout << endl;
        cout << "-------------------------------------Controls -----------------------------------" << endl;
        cout << "To move bike to left press left arrow key( <- ) ." << endl;
        cout << "To move bike to right press right arrow key( -> ) ." << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << endl
             << endl
             << endl;
        cout << "Going back to menu in 5 seconds..." << endl;
        delay(5000);
        goto label;
    }

    return 0;
}
