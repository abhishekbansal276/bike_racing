#include <graphics.h>
#include <cstdlib>
#include <string>
#include <time.h>
#include<math.h>
#include<iostream>
//#include <charconv>
#include<windows.h>

using namespace std;
int track = -300;
    int page = 0;
    int cx = 0, ms = 10;
    int m1x,m2x,m1y,m2y;

    int b = 0, o = 0;
    int random = 355 + (rand() % 51);
    int treel = 700 + (rand() % 201);
    int treer = 100 + (rand() % 201);
    int treel1 = 700 + (rand() % 201);
    int treer1 = 100 + (rand() % 201);
    int z = 0;
    float j=0.1;
    int number = 0;
    int ecarspeed=0;
    char num_char[1000 + sizeof(char)]={"0"};
    int level=20;
    int ecolor=4;

int dis(int mid1x, int mid1y,int mid2x,int mid2y)  // distance between enemy and bike
    {

        int s=0;
        s=sqrt(pow((mid2x-mid1x),2)+pow((mid2y-mid1y),2));
        return s;

    }
void enemycar()   //enemy car
{


        setcolor(RED);
        setfillstyle(1, ecolor);
        rectangle(random, 100+b+z+j, random+100, 200+b+z+j);
        floodfill(random + 1, 101 + b + z+j, RED);

        setcolor(YELLOW);
        setfillstyle(1, YELLOW);
        rectangle(random+15,210+b+z+j,random+35,200+b+z+j);
        floodfill(random + 16, 201 + b + z+j, YELLOW);

        setcolor(YELLOW);
        setfillstyle(1, YELLOW);
        rectangle(random+65,210+b+z+j,random+85,200+b+z+j);
        floodfill(random + 76, 201 + b + z+j, YELLOW);

        setcolor(BROWN);
        setfillstyle(1,BLACK);
        rectangle(random-10,105+b+z+j,random,135+b+z+j);
        floodfill(random-10+1,106+b+z+j,BROWN);

         setcolor(BROWN);
        setfillstyle(1,BLACK);
        rectangle(random+100,105+b+z+j,random+110,135+b+z+j);
        floodfill(random+101,106+b+z+j,BROWN);

        setcolor(BROWN);
        setfillstyle(1,BLACK);
        rectangle(random-10,155+b+z+j,random,185+b+z+j);
        floodfill(random-10+1,156+b+z+j,BROWN);

         setcolor(BROWN);
        setfillstyle(1,BLACK);
        rectangle(random+100,155+b+z+j,random+110,185+b+z+j);
        floodfill(random+101,156+b+z+j,BROWN);

        setcolor(BROWN);
        setfillstyle(1,LIGHTRED);
        rectangle(random+10,90+b+z+j,random+90,100+b+z+j);
        floodfill(random+11,91+b+z+j,BROWN);




        m2x=(random+random+100)/2;
        m2y=((2*(b+z+j))+300)/2;
}


int main()

{


m1x=m2x=m1y=m2y=0;

    //backgroung
    initwindow(1000, 1000,"BIKE GAME");

    int life = 4;
    srand(time(NULL));

    while (life > 0)
    {


        setactivepage(page);
        setvisualpage(1 - page);
        to_chars(num_char, num_char + 1000, number);
        to_string(number);
        b = b + 20;
        o = o + 20;
        delay(100 - z);

        cleardevice();

        setcolor(6);
        rectangle(0, 0, 1000, 1000);
        setfillstyle(1,GREEN);
        floodfill(1, 1, 6);
        //road

        setcolor(WHITE);
        rectangle(350, -1, 650, 1000);
        setfillstyle(11, LIGHTGRAY);
        floodfill(351, 0, WHITE);
        //line on road
        for (int i = 0; i < 1000; i += 99)
        {
            rectangle(490, -150 + i + track, 520, -100 + i + track);
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(491, -149 + track + i, WHITE);
        }

        track += 40;
        if (track > 100)
            track = 0;



        //for life and points
        settextstyle(6, 0, 2);
        outtextxy(5, 10, "LIFE : ");
        outtextxy(5, 40, "POINTS : ");


        for (int i = 100; i <= 160 - ((4 - life) * 20); i += 20)
        {
            setfillstyle(8, WHITE);
            circle(i, 20, 8);
            floodfill(i + 1, 21, WHITE);
            setfillstyle(8, WHITE);
        }
        outtextxy(150, 40, num_char);

        //controls
        if (GetAsyncKeyState(VK_LEFT))
            cx -= ms;
        if (GetAsyncKeyState(VK_RIGHT))
            cx += ms;

        settextstyle(8,0,1);
        setcolor(YELLOW);
        outtextxy(800, 10, "WE CHALLENGE YOU");
        outtextxy(740, 40, "YOU CAN NOT SCORE MORE ");
        outtextxy(800,60,"THAN 220 POINTS");

//bike body
        setcolor(YELLOW);
        setfillstyle(1, YELLOW);
        rectangle(450 + cx, 678, 470 + cx, 695);
        floodfill(451 + cx, 679, YELLOW);


        m1x=((470+cx)+(450+cx))/2;
        m1y=((695+678)/2);

                setcolor(BROWN);
        setfillstyle(1, BLACK);
        ellipse(460+cx,760,0,360,11,8);
        floodfill(461 + cx, 761, BROWN);

        setcolor(RED);
        setfillstyle(1, RED);
        rectangle(445 + cx, 700, 475 + cx, 760);
        floodfill(446 + cx, 701, RED);
        setcolor(BLACK);
        setfillstyle(1, BROWN);
        ellipse(460+cx,730,0,360,14,27);
        floodfill(461 + cx, 731, BLACK);

        setcolor(RED);
        setfillstyle(1, BLACK);
        rectangle(435 + cx, 695, 485 + cx, 700);
        floodfill(446 + cx, 696, RED);




        //ye jagaha hai
        enemycar();



//roadside trees
        setcolor(LIGHTGREEN);
        setfillstyle(11, LIGHTGREEN);

        circle(treel, -100 + b + z + 150, 50);
        floodfill(treel + 1, -99 + b + z + 150, LIGHTGREEN);

        circle(treer, -100 + b + z, 50);
        floodfill(treer + 1, -99 + b + z, LIGHTGREEN);

        if ((b + treel + z) >= 800)
        {
            setcolor(LIGHTGREEN);
            setfillstyle(11, LIGHTGREEN);
            circle(treel1, -200 + o + z, 50);
            floodfill(treel1 + 1, -199 + o + z, LIGHTGREEN);
            circle(treer1, -300 + o + z, 50);
            floodfill(treer1 + 1, -299 + o + z, LIGHTGREEN);
        }

        if (o >= 1050)
        {
            o = 0;

            treel1 = 750 + (rand() % 201);
            treer1 = 50 + (rand() % 201);
        }

        if (b >= 950)
        {


            number=number+5;
            b = 0;
            random = 360 + (rand() % 190);
            //random= (rand() %
           //(630 - 360 + 1)) + 360;
            treel = 700 + (rand() % 201);
            treer = 100 + (rand() % 201);
            z + 10;
            j=0;
        }

        //accident hua ya nahi bike ka ye dekh raha hu
        if((dis(m1x,m1y,m2x,m2y))<50)
        {

            cout<<dis(m1x,m1y,m2x,m2y)<<"\n";
            life--;

            if(life>0)
            {
                {
                        setvisualpage(1-1-page);
                        settextstyle(10, 0, 4);
                        outtextxy(250,350, "!!BE CAREFUL NEXT TIME!!");
                        delay(1000);
                    }

                delay(1000);
                if((470+cx)<=500)
                   cx=cx+100;
                else if(500<(450+cx))
                    cx=cx-100;

            }

            else
                {
                    setvisualpage(1-1-page);
                    setcolor(YELLOW);
                    settextstyle(10, 0, 4);
                    outtextxy(360,350, " !!GAME OVER!! ");
                    cout<<"\a";
                    delay(10000);

                }



        }

        if (cx <= (-105) || cx >= 175)
        {
            life--;

            if(life>0)
            {
                delay(1000);
                if(cx>175)
               {
                            cx=cx-100;

            setcolor(YELLOW);
            settextstyle(10, 0, 4);
            outtextxy(250,350, "!!BE CAREFUL NEXT TIME!!");
            setvisualpage(1-1-page);

            }
                else if(cx<(-105))
               {
                cx=cx+100;
                    setvisualpage(1-1-page);
            setcolor(YELLOW);
            settextstyle(10, 0, 4);
            outtextxy(250,350, "!!BE CAREFUL NEXT TIME!!");
            delay(1000);
            }

            }
            else{
                    setvisualpage(1-1-page);

             setcolor(YELLOW);
             settextstyle(10, 0, 4);
             outtextxy(360,350, " !!GAME OVER!! ");
             cout<<"\a";
             delay(10000);



            }

        }


            setcolor(YELLOW);
            settextstyle(10,1,3);
            outtextxy(30,300,"* AIML PROJECT *");
            if(number>=level)
            {
                level=level+5;

                ecarspeed=1.5+ecarspeed;
                cout<<ecarspeed<<"\n";


            }
             j=j+ecarspeed;
                cout<<j<<"\n";

        page = 1 - page;
    }




    getch();
}
