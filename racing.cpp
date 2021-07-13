#include <graphics.h>
#include <cstdlib>
#include <string>
#include <time.h>
#include<math.h>
#include<iostream>

using namespace std;
int dis(int mid1x, int mid1y,int mid2x,int mid2y)
    {
        int s=0;
        s=sqrt(pow((mid2x-mid1x),2)+pow((mid2y-mid1y),2));
        return s;

    }

int main()

{

    int track = -300;
    int page = 0;
    int cx = 0, ms = 10;
    int m1x,m2x,m1y,m2y;
    m1x=m2x=m1y=m2y=0;
    int b = 0, o = 0;
    int random = 355 + (rand() % 51);
    int treel = 700 + (rand() % 201);
    int treer = 100 + (rand() % 201);
    int treel1 = 700 + (rand() % 201);
    int treer1 = 100 + (rand() % 201);
    int z = 0;


    //backgroung
    initwindow(1000, 1000,"CAR GAME");
    int life = 4;
    while (life > 0)
    {
        srand(time(NULL));

        setactivepage(page);
        setvisualpage(1 - page);
        b = b + 20;
        o = o + 20;
        delay(100 - z);
        cleardevice();
        setcolor(6);
        rectangle(0, 0, 1000, 1000);
        setfillstyle(1, 6);
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
        outtextxy(150, 40, "0");

        //controls
        if (GetAsyncKeyState(VK_LEFT))
            cx -= ms;
        if (GetAsyncKeyState(VK_RIGHT))
            cx += ms;

//bike body
        setcolor(YELLOW);
        setfillstyle(1, YELLOW);
        rectangle(450 + cx, 678, 470 + cx, 695);
        floodfill(451 + cx, 679, YELLOW);
        m1x=((470+cx)+(450+cx))/2;
        m1y=((695+678)/2);
        setcolor(RED);
        setfillstyle(1, RED);
        rectangle(445 + cx, 700, 475 + cx, 760);
        floodfill(446 + cx, 701, RED);

        setcolor(WHITE);
        setfillstyle(1, BLACK);
        rectangle(440 + cx, 695, 480 + cx, 700);
        floodfill(441 + cx, 696, WHITE);

        if (cx <= (-105) || cx >= 175)
        {
            life--;

            if(life!=0)
            {
                delay(1000);
                if(cx>175)
                cx=cx-100;
                else if(cx<(-105))
                    cx=cx+100;
                    {setvisualpage(1-1-page);
            setcolor(YELLOW);
            settextstyle(10, 0, 4);
            outtextxy(150,350, "*!!INSURANCE ABHI BAAKI HAI MERE DOST!!*");
            delay(1000);
            }

            }
            else{
            setvisualpage(1-1-page);
             setcolor(YELLOW);
             settextstyle(10, 0, 4);
             outtextxy(150,350, " *****MUBAARAAK HO AAP HAAR GAYE***** ");
             delay(10000);


            }

        }
//enemy car
        setcolor(RED);
        setfillstyle(1, RED);
        rectangle(random, 100+b+z, random+100, 200+b+z);
        floodfill(random + 1, 101 + b + z, RED);

        setcolor(YELLOW);
        setfillstyle(1, YELLOW);
        rectangle(random+15,210+b+z,random+35,200+b+z);
        floodfill(random + 16, 201 + b + z, YELLOW);

        setcolor(YELLOW);
        setfillstyle(1, YELLOW);
        rectangle(random+65,210+b+z,random+85,200+b+z);
        floodfill(random + 76, 201 + b + z, YELLOW);

        setcolor(BROWN);
        setfillstyle(1,BLACK);
        rectangle(random-10,105+b+z,random,135+b+z);
        floodfill(random-10+1,106+b+z,BROWN);

         setcolor(BROWN);
        setfillstyle(1,BLACK);
        rectangle(random+100,105+b+z,random+110,135+b+z);
        floodfill(random+101,106+b+z,BROWN);

        setcolor(BROWN);
        setfillstyle(1,BLACK);
        rectangle(random-10,155+b+z,random,185+b+z);
        floodfill(random-10+1,156+b+z,BROWN);

         setcolor(BROWN);
        setfillstyle(1,BLACK);
        rectangle(random+100,155+b+z,random+110,185+b+z);
        floodfill(random+101,156+b+z,BROWN);

       // setcolor(dark)

        m2x=(random+random+100)/2;
        m2y=((2*(b+z))+300)/2;

//roadside trees
        setcolor(GREEN);
        setfillstyle(9, GREEN);

        circle(treel, -100 + b + z + 150, 50);
        floodfill(treel + 1, -99 + b + z + 150, GREEN);

        circle(treer, -100 + b + z, 50);
        floodfill(treer + 1, -99 + b + z, GREEN);

        if ((b + treel + z) >= 800)
        {
            setcolor(GREEN);
            setfillstyle(9, GREEN);
            circle(treel1, -200 + o + z, 50);
            floodfill(treel1 + 1, -199 + o + z, GREEN);
            circle(treer1, -300 + o + z, 50);
            floodfill(treer1 + 1, -299 + o + z, GREEN);
        }

        if (o >= 1050)
        {
            o = 0;

            treel1 = 750 + (rand() % 201);
            treer1 = 50 + (rand() % 201);
        }

        if (b >= 950)
        {
            b = 0;
            random = 360 + (rand() % 170);
            treel = 700 + (rand() % 201);
            treer = 100 + (rand() % 201);
            z + 10;
        }

        //accident hua ya nahi bike ka ye dekh raha hu
        if((dis(m1x,m1y,m2x,m2y))<50)
        {
            cout<<dis(m1x,m1y,m2x,m2y)<<"\n";
            life--;

            if(life!=0)//insurance hai kya
            {
                {
                        setvisualpage(1-1-page);
                        settextstyle(10, 0, 4);
                        outtextxy(150,350, "*!!INSURANCE ABHI BAAKI HAI MERE DOST!!*");
                        delay(1000);
                    }

                delay(1000);
                if(random<(450+cx))
                   cx=cx+100;
                else if((470+cx)<(random+100))
                    cx=cx-100;

            }

            else
                {
                    setvisualpage(1-1-page);
                    setcolor(YELLOW);
                    settextstyle(10, 0, 4);
                    outtextxy(150,350, " *****MUBAARAAK HO AAP HAAR GAYE***** ");
                    delay(10000);
                }



        }

        /*int firstbushx=(rand()%150)+50;
            int firstbushy=(rand()%150)+500;
            setcolor(GREEN);
            circle(firstbushx,firstbushy+track,50);
            setfillstyle(1,GREEN);
            floodfill(firstbushx+1,firstbushy+1+track,GREEN);
            int secondbushx=(rand()%150)+50;
            int secondbushy=(rand()%150)+500;
            setcolor(GREEN);
            circle(secondbushx,secondbushy+track,50);
            setfillstyle(1,GREEN);
            floodfill(secondbushx+1,secondbushy+1+track,GREEN);*/
            setcolor(YELLOW);
            settextstyle(10,VERT_DIR,3);
            outtextxy(30,300,"* AAS GAMES *");

        page = 1 - page;
    }




    getch();
}

