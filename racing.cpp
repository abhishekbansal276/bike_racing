#include<graphics.h>
#include<cstdlib>
#include<string>
#include<time.h>

/*void ecar(int a,int b, int c)
{int i=0;
   while(true)
    {
        i=i+5;
        rectangle(355+a,-150+b+i,405+a,-100+b+i);
    setfillstyle(SOLID_FILL,c);
        floodfill(356+a,-149+b+i,WHITE);
        if(i>800)
            break;

    }

}*/
using namespace std;
int main()

{

    int track=-300;
int page=0;
int cx=0,ms=10;
int b=0,o=0;
int random = 400+(rand()%201);
int treel = 700+(rand()%201);
int treer = 100+(rand()%201);
int treel1 = 700+(rand()%201);
int treer1 = 100+(rand()%201);
int z=0;


//backgroung
    initwindow(1000,1000,"AMAN");
    while(true)

    {
srand(time(NULL));

        setactivepage(page);
        setvisualpage(1-page);
    b=b+20;
    o=o+20;
        delay(100-z);
        cleardevice();
    setcolor(6);
    rectangle(0,0,1000,1000);
    setfillstyle(1,6);
    floodfill(1,1,6);
//road


    setcolor(WHITE);
    rectangle(350,-1,650,1000);
    setfillstyle(11,8);
    floodfill(351,0,WHITE);
//line on road
    for(int i=0;i<1000;i+=99)
    {
        rectangle(490,-150+i+track,520,-100+i+track);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(491,-149+track+i,WHITE);
    }



    track+=40;
    if(track>100)
        track=0;

//ecar(1,2,3);

//for life and points
settextstyle(6,0,2);
outtextxy(5,10,"LIFE : ");
outtextxy(5,40,"POINTS : ");
setfillstyle(8,WHITE);
circle(100,20,8);
floodfill(101,21,WHITE);
setfillstyle(8,WHITE);

circle(120,20,8);
floodfill(121,21,WHITE);
setfillstyle(8,WHITE);

circle(140,20,8);
floodfill(141,21,WHITE);
setfillstyle(8,WHITE);

circle(160,20,8);
floodfill(161,21,WHITE);

outtextxy(150,40,"0");

//controls
if(GetAsyncKeyState(VK_LEFT))
    cx-=ms;
if(GetAsyncKeyState(VK_RIGHT))
    cx+=ms;

//bike body
setcolor(YELLOW);
setfillstyle(1,YELLOW);
rectangle(450+cx,678,470+cx,695);
floodfill(451+cx,679,YELLOW);

setcolor(RED);
setfillstyle(1,RED);
rectangle(445+cx,700,475+cx,760);
floodfill(446+cx,701,RED);

setcolor(WHITE);
setfillstyle(1,BLACK);
rectangle(440+cx,695,480+cx,700);
floodfill(441+cx,696,WHITE);


if(cx<=(-105)||cx>=175)
{
  outtextxy(500,550," SORRY ");


  delay(1000);




}

        setcolor(DARKGRAY);
        setfillstyle(1,DARKGRAY);
        circle(random,100+b+z,50);
        floodfill(random+1,101+b+z,DARKGRAY);
        setcolor(GREEN);
        setfillstyle(9,GREEN);
        circle(treel,-100+b+z+150,50);
        floodfill(treel+1,-99+b+z+150,GREEN);
        circle(treer,-100+b+z,50);
        floodfill(treer+1,-99+b+z,GREEN);

        if((b+treel+z)>=800)
        {
           setcolor(GREEN);
        setfillstyle(9,GREEN);
        circle(treel1,-200+o+z,50);
        floodfill(treel1+1,-199+o+z,GREEN);
        circle(treer1,-300+o+z,50);
        floodfill(treer1+1,-299+o+z,GREEN);
        }

        if(o>=1050)
        {
           o=0;

           treel1 = 750+(rand()%201);
          treer1 = 50+(rand()%201);
        }

        if(b>=950)
         {
          b=0;
          random = 400+(rand()%201);
          treel = 700+(rand()%201);
          treer = 100+(rand()%201);
          z+10;

         }
         if(((random)==(440+cx)||(random)==(480+cx))&&(695<=(100+b+z)<=700))
{
   outtextxy(500,550," **GAME OVER** ");
   delay(1000);
   getch();

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



page=1-page;
    }

    getch();
}
