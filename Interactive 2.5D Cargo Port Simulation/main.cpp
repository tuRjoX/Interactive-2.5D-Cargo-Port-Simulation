#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "custom.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

bool isRaining = false;
const int numDrops = 300;
float rainX[numDrops];
float rainY[numDrops];
float moveXh = 0.0f;
float moveY = 0.0f;
float movecY = 0.0f;
float movecX = 0.0f;
float moveShip = 0.0f;
float moveShip3 = -43.0f;
float shipSpeed = 0.02;
float speed = 0.05f;
float truckX = 0.0f;
float stringY = 0.0f;
float cloudX = 0.0f;
bool pick = false;
bool release  = false;
bool ship_start = false;
bool ship_start2 = false;
bool ship_start3 = false;
bool train_start2 = false;
bool trainMovedOnce = false;
bool truckStart = false;
bool isDayScene = true;
bool trainSoundPlayed = false;
int currentDisplay = 1;
bool showRestartMessage = false;

void set_color(string col){
    if(isDayScene  == true ){
        // Scenario 1
        //Road
        if(col == "Emperor")glColor3ub(85,74,75);
        else if(col == "Scorpion")glColor3ub(110,99,100);
        else if(col == "Black")glColor3ub(0,0,0);
        else if(col == "Thunder")glColor3ub(23, 20, 21);

        // Warehouse
        else if(col == "Tango")glColor3ub(238,126,32);
        else if(col =="Hawaiian Tan" )glColor3ub(165,86,20);
        else if(col =="warehouse1" )glColor3ub(165,86,20);
        else if(col =="Hairy Heath" )glColor3ub(103,45,19);
        else if(col =="Tango_Dark")glColor3ub(71,38,10);
        else if(col =="White")glColor3ub(255,255,255);
        else if(col =="Old Copper")glColor3ub(119,63,50);
        else if(col =="Firefly")glColor3ub(9,22,28);
        else if(col =="Maroon")glColor3ub(71,13,33);
        else if(col =="Jazzberry")glColor3ub(156,15,72);
        else if(col =="Neon")glColor3ub(174, 214, 241);
        else if(col =="LNeon")glColor3ub(214, 234, 248);

        // ocean
        else if(col == "1")glColor3ub(18,153,201);
        else if(col == "2")glColor3ub(49,196,218);
        else if(col == "3")glColor3ub(91,244,225);
        else if(col == "4")glColor3ub(100,230,230);

        //ship
        else if(col == "window")glColor3ub(255,194,113);
        else if(col == "ship_side")glColor3ub(0,38,84);
        else if(col == "ship_side1")glColor3ub(243, 156, 18);
        else if(col == "chimney")glColor3ub(125,2,30);
        else if(col == "ship_window")glColor3ub(0, 150, 136 );
        else if(col == "Ship_Border")glColor3ub(169, 50, 38);
        else if(col == "Off white")glColor3ub(153, 163, 164);
        else if(col == "ship_body")glColor3ub(97, 106, 107);
        else if(col == "ship_body2")glColor3ub(178, 186, 187);
        else if(col == "Top_floor")glColor3ub(224, 224, 224);
        else if(col == "Railing")glColor3ub(214, 219, 223);

        // sky
        else if(col == "skyL")glColor3ub(128,201,242);
        else if(col == "skyM")glColor3ub(0,172,246);
        else if(col == "skyD")glColor3ub(0,112,214);

        // Crane Bg
        else if(col == "BcraneLeg")glColor3ub(31, 97, 141);
        else if(col == "Fuel Yellow")glColor3ub(232,178,37);
        else if(col == "BcraneRoom")glColor3ub(138,18,32 );
        else if(col == "BcraneContainer")glColor3ub(194,113,74);

        // Cargo ship
        else if(col == "Cship_floor")glColor3ub( 219,99,75);
        else if(col == "Cship_shadow")glColor3ub(201,86,66);
        else if(col == "Crail")glColor3ub(180,71,61);
        else if(col == "Japonica")glColor3ub(215,116,89);

       // Lights
        else if(col == "Red light")glColor3ub(44, 62, 80);
        else if(col == "cloud")glColor3ub(255,255,255);

        // Scenario 2
        else if(col == "sky") glColor3ub (176, 225, 255);
        else if(col == "skyCU") glColor3ub (13, 163, 222 );
        else if(col == "skyCD") glColor3ub (0,89,191);
        else if(col == "waterCU") glColor3ub (18, 146, 173);
        else if(col == "waterCD") glColor3ub (75, 117, 232 );
        else if(col == "buildingglass") glColor3ub (122, 194, 244);
        else if(col == "bulidingcolor") glColor3ub (120,79,87);
        else if(col == "buildingShadow") glColor3ub (166, 212, 246);
        else if(col == "twintower") glColor3ub (100, 136, 160);
        else if(col == "brick") glColor3ub (175, 44, 35);
        else if(col == "midBuilding") glColor3ub (251,154,127);
        else if(col == "frontBuilding") glColor3ub (116,142,161);
        else if(col == "trainGlass") glColor3ub (146, 168, 175);
        else if(col == "background") glColor3ub (215, 216, 215);
        else if(col == "trainwindow") glColor3ub (37, 150, 190);
        else if(col == "traindoor") glColor3ub (124,57,85);
        else if(col == "bridgerailc") glColor3ub (100, 96, 92 );
        else if(col == "SunC") glColor3ub (255,187,68);
        else if(col == "DewC") glColor3ub (236,247,248);
    } else if(isDayScene == false ) {

        // _________________________NIGHT______________________________________________________________________________________

        // Road
        if(col == "Emperor")glColor3ub(43,37,38);
        else if(col == "Scorpion")glColor3ub(51,44,45);
        else if(col == "Black")glColor3ub(0,0,0);
        else if(col == "Thunder")glColor3ub(33,	29	,30);

        // Warehouse
        else if(col == "Tango")glColor3ub(167,88,22);
        else if(col == "Hawaiian Tan" )glColor3ub(132,69,16);
        else if(col == "warehouse1" )glColor3ub(167,88,22);
        else if(col == "Hairy Heath" )glColor3ub(72,31,13);
        else if(col == "Tango_Dark")glColor3ub(50,27,7);
        else if(col == "White")glColor3ub(229, 231, 233);
        else if(col == "Old Copper")glColor3ub(89, 57, 36);
        else if(col == "Firefly")glColor3ub(9,22,28);
        else if(col == "Maroon")glColor3ub(61, 12, 17);
        else if(col == "Jazzberry")glColor3ub(93, 6, 53);

        // neon
        else if(col == "Neon")glColor3ub(133, 146, 158);
        else if(col == "LNeon")glColor3ub(174, 182, 191);

        // ocean
        else if(col == "1")glColor3ub(14, 122, 161);
        else if(col == "2")glColor3ub(34, 137, 153);
        else if(col == "3")glColor3ub(64, 156, 158);
        else if(col == "4")glColor3ub(80, 184, 184);

        // ship
        else if(col == "window")glColor3ub(249, 231, 159);
        else if(col == "ship_side")glColor3ub(46, 64, 83);
        else if(col == "ship_side1")glColor3ub(185, 119, 14);
        else if(col == "chimney")glColor3ub(50,1,12);
        else if(col == "ship_window")glColor3ub(244, 208, 63);
        else if(col == "Ship_Border")glColor3ub(100, 30, 22);
        else if(col == "Off white")glColor3ub(112, 123, 124);
        else if(col == "ship_body")glColor3ub(66, 73, 73);
        else if(col == "ship_body2")glColor3ub(153, 163, 164);
        else if(col == "Top_floor")glColor3ub(215, 219, 221);
        else if(col == "Railing")glColor3ub(166, 172, 175);

        // sky
        else if(col == "skyL")glColor3ub(121,135,174);
        else if(col == "skyM")glColor3ub(8,27,68);
        else if(col == "skyD")glColor3ub(9,16,35);

        // Crane Bg
        else if(col == "BcraneLeg")glColor3ub(52, 73, 94);
        else if(col == "Fuel Yellow")glColor3ub(186, 143, 29);
        else if(col == "BcraneRoom")glColor3ub(125,54,49);
        else if(col == "BcraneContainer")glColor3ub(175, 102, 67);

        // Cargo ship
        else if(col == "Cship_floor")glColor3ub(131,59,45);
        else if(col == "Cship_shadow")glColor3ub(131,59,45);
        else if(col == "Crail")glColor3ub(144,57,49);
        else if(col == "Japonica")glColor3ub(172, 93, 71);

       // Lights
        else if(col == "Red light")glColor3ub(231, 76, 60);
        else if(col == "cloud")glColor3ub(128, 139, 150);

        // Scenario 2
        else if(col == "night") glColor3ub (84,85,87);
        else if(col == "skyCU") glColor3ub (68,97,115);
        else if(col == "skyCD") glColor3ub (2,24,38);
        else if(col == "white") glColor3ub (91, 157, 169);
        else if(col == "bulidingcolor") glColor3ub (96, 63, 70);
        else if(col == "buildingglass") glColor3ub (255, 228, 9);
        else if(col == "buildingShadow") glColor3ub (116, 148, 172);
        else if(col == "twintower") glColor3ub (100, 136, 160);
        else if(col == "cloud") glColor3ub (79, 132, 150);
        else if(col == "lightBuilding") glColor3ub (116, 148, 172);
        else if(col == "midBuilding") glColor3ub (201, 123, 102);
        else if(col == "frontBuilding") glColor3ub (93, 114, 129);
        else if(col == "trainGlass") glColor3ub (65, 117, 139);
        else if(col == "traindoor") glColor3ub (112, 51, 77);
        else if(col == "trainwindow") glColor3ub (251, 232, 35);
        else if(col == "bridgerailc") glColor3ub (100, 96, 92 );
        else if(col == "nightTwindow") glColor3ub (253, 242, 133);
        else if(col == "nightstars") glColor3ub (247,248,243);
        else if(col == "MoonD") glColor3ub (255,255,255);
        else if(col == "DewC") glColor3ub (236,247,248);
    }
}

void streetlight(){

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(0.25,11.25);
    glVertex2f(0.25,10.75);
    glVertex2f(0.5,10.75);
    glVertex2f(0.5,11.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Red light");
    glVertex2f(0.25,11.5);
    glVertex2f(0.25,11.25);
    glVertex2f(0.5,11.25);
    glVertex2f(0.5,11.5);
    glEnd();
}

void More_StreetLight(){

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(0,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(5,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(10,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(15,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(20,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(25,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(30,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(35,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(40,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(45,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(50,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(55,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(60,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(65 ,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(70,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(75 ,16.1,0);
    streetlight();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4,0.4,1);
    glTranslatef(80,16.1,0);
    streetlight();
    glPopMatrix();
}

void rainUpdate(int value) {
    if (isRaining) {
        for (int i = 0; i < numDrops; ++i) {
            rainY[i] -= 0.5f;
            if (rainY[i] < -25) {
                rainY[i] = 30;
                rainX[i] = (rand() % 82) - 41;
            }
        }
        glutPostRedisplay();
    }
    glutTimerFunc(30, rainUpdate, 0);
}

void drawRain() {
    if (!isRaining) return;

    glColor3ub(173, 216, 230);
    glBegin(GL_LINES);
    for (int i = 0; i < numDrops; ++i) {
        glVertex2f(rainX[i], rainY[i]);
        glVertex2f(rainX[i], rainY[i] - 1.5f);
    }
    glEnd();
}

void circle(float radius, float cX, float cY,int rC, int gC, int bC){
   glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(rC,gC,bC);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
    glEnd();
}

void sky_1(){

    glBegin(GL_POLYGON);

    set_color("skyL");
    glVertex2f(0,0);
    glVertex2f(32,0);
    set_color("skyM");
    glVertex2f(32,15);
    glVertex2f(0,15);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("skyM");
    glVertex2f(0,15);
    glVertex2f(32,15);
    set_color("skyD");
    glVertex2f(32,18);
    glVertex2f(0,18);
    glEnd();
}

void Window_wh_1(){

    glBegin(GL_POLYGON);
    set_color("window");
    glVertex2f(23.50,5.75);
    glVertex2f(23.50,5.25);
    glVertex2f(24,5.25);
    glVertex2f(24,5.75);
    glEnd();
}

void Adjust_Window(){

    // Big red building
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-16.5,20.51,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-14.5,20.51,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-12.5,20.51,0);
    Window_wh_1();
    glPopMatrix();

    // small building
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-21,18,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-19,18,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-17,18,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-15,18,0);
    Window_wh_1();
    glPopMatrix();

    // 2nd row
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-21,16.75,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-19,16.75,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-17,16.75,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(-15,16.75,0);
    Window_wh_1();
    glPopMatrix();

    // Right building small

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(29.5,17.70,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(31.5,17.70,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(33.5,17.70,0);
    Window_wh_1();
    glPopMatrix();

    //2nd row
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(29.5,16.5,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(31.5,16.5,0);
    Window_wh_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(33.5,16.5,0);
    Window_wh_1();
    glPopMatrix();
}

void Building_1(){
    // Back
    glBegin(GL_POLYGON);
    set_color("Jazzberry");
    glVertex2f(3,13.5);
    glVertex2f(3,10.75);
    glVertex2f(6.25,10.75);
    glVertex2f(6.25,13.5);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Maroon");
    glVertex2f(6.25,13.5);
    glVertex2f(6.25,10.75);
    glVertex2f(7,10.75);
    glVertex2f(7,13.5);
    glEnd();

    // Front
    glBegin(GL_POLYGON);
    set_color("Tango");
    glVertex2f(1,12.25);
    glVertex2f(1,10.75);
    glVertex2f(4.75,10.75);
    glVertex2f(4.75,12.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Hairy Heath");
    glVertex2f(4.75,12.25);
    glVertex2f(4.75,10.75);
    glVertex2f(6,10.75);
    glVertex2f(6,12.25);

    glEnd();
}

void CraneBg_1(){
    // Leg Left
    glBegin(GL_POLYGON);
    set_color("BcraneLeg");
    glVertex2f(-1.50,-2.00);
    glVertex2f(-1.50,-1.50);
    glVertex2f(-0.25,0.50);
    glVertex2f(-0.25,-0.50);
    glVertex2f(-1.00,-1.50);
    glVertex2f(-1.00,-2.00);
    glVertex2f(-1.50,-2.00);
    glEnd();

    // Right Leg
    glBegin(GL_POLYGON);
    set_color("BcraneLeg");
    glVertex2f(2.00,-2.00);
    glVertex2f(2.00,-1.50);
    glVertex2f(0.75,0.50);
    glVertex2f(0.75,-0.50);
    glVertex2f(1.50,-1.50);
    glVertex2f(1.50,-2.00);
    glVertex2f(2.00,-2.00);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(81, 90, 90 );
    // glColor3ub(0,0,0 );
    glVertex2f(1.50,-2.00);
    glVertex2f(2.50,-2.00);
    glVertex2f(2.50,-2.25);
    glVertex2f(1.50,-2.25);
    glVertex2f(1.50,-2.00);
    glEnd();

    // Body line
    glBegin(GL_LINES);
    set_color("BcraneLeg");
    glVertex2f(-0.25,-0.50);
    glVertex2f(0.75,-0.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("BcraneLeg");
    glVertex2f(-0.25,0.39);
    glVertex2f(-0.25,0.50);
    glVertex2f(0.75,0.50);
    glVertex2f(0.75,0.39);
    glVertex2f(-0.25,0.39);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("BcraneLeg");
    glVertex2f(-0.82,-1.25);
    glVertex2f(1.32,-1.25);
    glVertex2f(1.50,-1.50);
    glVertex2f(-1.00,-1.50);
    glVertex2f(-0.82,-1.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Fuel Yellow");
    glVertex2f(-1.75,0.50);
    glVertex2f(-1.75,0.75);
    glVertex2f(-0.75,0.75);
    glVertex2f(0.75,0.50);
    glVertex2f(-1.75,0.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Fuel Yellow");
    glVertex2f(-0.75,0.50);
    glVertex2f(-0.75,0.75);
    glVertex2f(1.25,0.75);
    glVertex2f(1.25,0.50);
    glVertex2f(-0.75,0.50);
    glEnd();

    glBegin(GL_POLYGON);
    //  glColor3ub(238, 226, 34  );//Y
    set_color("Fuel Yellow");
    glVertex2f(0.0,0.75);
    glVertex2f(0.25,0.75);
    glVertex2f(0.25,1.50);
    glVertex2f(0.0,1.66);
    glVertex2f(0.0,0.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("BcraneRoom");
    glVertex2f(-1.75,0.75);
    glVertex2f(-1.75,1.75);
    glVertex2f(0.0,1.75);
    glVertex2f(0.0,0.75);
    glVertex2f(-1.75,0.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("window");
    glVertex2f(-1.50,1.00);
    glVertex2f(-1.50,1.50);
    glVertex2f(-1.00,1.50);
    glVertex2f(-1.00,1.00);
    glVertex2f(-1.50,1.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Fuel Yellow");
    glVertex2f(-1.00,1.75);
    glVertex2f(-1.25,2.00);
    glVertex2f(-1.25,2.50);
    glVertex2f(-0.16,1.75);
    glVertex2f(1.00,1.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97, 106, 107 );//J-1
    glVertex2f(-1.75,2.00);
    glVertex2f(-1.75,2.50);
    glVertex2f(-1.25,2.50);
    glVertex2f(-1.25,2.00);
    glVertex2f(-1.75,2.00);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97, 106, 107 );//J-2
    glVertex2f(-1.75,2.50);
    glVertex2f(-1.75,3.00);
    glVertex2f(-1.25,3.00);
    glVertex2f(-1.25,2.50);
    glVertex2f(-1.75,2.50);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(44, 62, 80 );
    glVertex2f(-1.75,2.50);
    glVertex2f(-1.25,2.50);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(251, 236, 1 );//Pull-1 //236, 223, 27
    set_color("Fuel Yellow");
    glVertex2f(-1.25,2.25);
    glVertex2f(-1.25,2.50);
    glVertex2f(1.25,4.00);
    glVertex2f(1.25,3.75);
    glVertex2f(-1.25,2.25);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(251, 236, 1 );//Pull-2-Y
    set_color("Fuel Yellow");
    glVertex2f(1.25,4.00);
    glVertex2f(3.25,2.00);
    glVertex2f(3.25,1.75);
    glVertex2f(1.25,3.75);
    glVertex2f(1.25,4.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Fuel Yellow");
   // glColor3ub(251, 236, 1 );//Pull-3-Y
    glVertex2f(0.00,3.25);
    glVertex2f(3.25,2.00);
    glVertex2f(3.25,1.75);
    glVertex2f(0.00,3.00);
    glVertex2f(0.00,3.25);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(251, 236, 1 );//Pull-4-Y
    set_color("Fuel Yellow");
    glVertex2f(0.25,0.75);
    glVertex2f(1.75,2.50);
    glVertex2f(1.75,2.25);
    glVertex2f(0.50,0.75);
    glVertex2f(0.25,0.75);
    glEnd();

    // Rope
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.02,1.75);
    glVertex2f(3.02,0.50);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.49,1.75);
    glVertex2f(3.49,0.50);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.00,0.50);
    glVertex2f(3.25,-0.25);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.50,0.50);
    glVertex2f(3.25,-0.25);
    glEnd();

    //
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.25,-0.25);
    glVertex2f(2.25,-0.75);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.25,-0.25);
    glVertex2f(2.75,-0.75);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.25,-0.25);
    glVertex2f(4.00,-0.75);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(27, 38, 49);
    glVertex2f(3.25,-0.25);
    glVertex2f(4.50,-0.75);
    glEnd();

    //Container
    glBegin(GL_POLYGON);
    set_color("BcraneContainer");
    glVertex2f(2.25,-0.75);
    glVertex2f(4.50,-0.75);
    glVertex2f(4.50,-1.50);
    glVertex2f(2.25,-1.50);
    glVertex2f(2.25,-0.75);
    glEnd();

    circle(0.232,3.25,1.75,151, 149, 128);
    circle(0.232,3.25,0.50,151, 149, 128);
}

void Adjust_craneBg(){
    // CraneBg_1
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(.5,.5,1);
    glTranslatef(48,23.51,0);
    CraneBg_1();
    glPopMatrix();

}

void WareHouse_1(){
    glBegin(GL_POLYGON);
    set_color("Jazzberry");
    glVertex2f(26,12.5);
    glVertex2f(26,11.25);
    glVertex2f(29,11.25);
    glVertex2f(29,12.5);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Maroon");
    glVertex2f(29,12.5);
    glVertex2f(29,11.25);
    glVertex2f(30.5,11.25);
    glVertex2f(30.5,12.5);
    glEnd();
}

void Adjust_WareHouse1(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(0,-.5,0);
    WareHouse_1();
    glPopMatrix();
}

void Houses_1(){
    glBegin(GL_POLYGON);
    set_color("Neon");
    glVertex2f(28,13);
    glVertex2f(28,10.75);
    glVertex2f(32,10.75);
    glVertex2f(32,13);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("LNeon");
    glVertex2f(30.5,14.75);
    glVertex2f(30.5,13);
    glVertex2f(32.5,13);
    glVertex2f(32.5,14.75);
    glEnd();
}

void Houses_2(string color){
    glBegin(GL_POLYGON);
    set_color(color);
    glVertex2f(1,12.25);
    glVertex2f(1,10.75);
    glVertex2f(4.75,10.75);
    glVertex2f(4.75,12.25);
    glEnd();
}

void Adjust_Houses_2(){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.3,1.3,1);
    glTranslatef(-1,-2.47,0);
    Houses_2("Neon");
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.5,.8,1);
    glTranslatef(2,2.47,0);
    Houses_2("LNeon");
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.3,1.3,1);
    glTranslatef(10.5,-2.47,0);
    Houses_2("LNeon");
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(12,0,0);
    Houses_2("Neon");
    glPopMatrix();
}

void Sea_border_1(){
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(0,10);
    glVertex2f(32,10);
    glVertex2f(32,10.35);
    glVertex2f(0,10.35);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Scorpion");
    glVertex2f(0,10.35);
    glVertex2f(32,10.35);
    glVertex2f(32,10.75);
    glVertex2f(0,10.75);
    glEnd();
}

void Sea_1(){
    //  top to bottom
    //1
    glBegin(GL_POLYGON);
    set_color("1");
    glVertex2f(0,10);
    glVertex2f(0,5);
    glVertex2f(32,5);
    glVertex2f(32,10);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    set_color("2");
    glVertex2f(0,9);
    glVertex2f(0,5);
    glVertex2f(32,5);
    glVertex2f(32,7.5);
    glVertex2f(27,8);
    glVertex2f(19.25,8.50);
    glVertex2f(12.50,7.75);
    glVertex2f(5,8);
    glEnd();

    //3
    glBegin(GL_POLYGON);
    set_color("3");
    glVertex2f(0,7);
    glVertex2f(0,5);
    glVertex2f(32,5);
    glVertex2f(32,6.25);
    glVertex2f(20,7.0);
    glEnd();

    // 4
    glBegin(GL_POLYGON);
    set_color("4");
    glVertex2f(0,5);
    glVertex2f(0,0);
    glVertex2f(2,0);
    glVertex2f(7,5);
    glEnd();

    // light color
    int r = 235, g = 245, b =  251;
    designSeaLine(6,2,3.59,3.59, r,g,b);
    designSeaLine(6,2,2.59, 3.10,r,g,b);
    designSeaLine(6,2,  5.20, 4.2,r,g,b);
    designSeaLine2(3,1,  1,5.12, r,g,b);
    designSeaLine2(3,1, 6.8,9.7, r,g,b);
    designSeaLine2(5,0.8,  0.6,12.12, r,g,b);
}

void Cloud(float radius, float cX, float cY){

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            set_color("cloud");
            float pi=3.1416;
            float A=(i*2*pi)/400;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
    glEnd();

}

void CloudSet() {
    float spacing = 45.0f;

    for (int i = 0; i < 2; ++i) {
        float offset = cloudX + i * spacing;

        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(offset + 1, 12, 0);
        Cloud(1, 6.5, 14);
        Cloud(1, 8, 14);
        Cloud(1, 9.5, 14);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(offset + 12, 14, 0);
        Cloud(1, 6.5, 14);
        Cloud(1, 8, 14);
        Cloud(1, 9.5, 14);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(offset + 24, 10, 0);
        Cloud(1, 6.5, 14);
        Cloud(1, 8, 14);
        Cloud(1, 9.5, 14);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.6, 0.6, 1);
        glTranslatef(offset + 36, 12, 0);
        Cloud(1, 6.5, 14);
        Cloud(1, 8, 14);
        Cloud(1, 9.5, 14);
        glPopMatrix();
    }
}

void background_1(){
    sky_1();
    Adjust_Houses_2();
    Adjust_craneBg();
    Houses_1();
    Sea_1();
    Sea_border_1();
    Adjust_WareHouse1() ;
    Building_1();
    Adjust_Window();
    CloudSet();
    More_StreetLight();
}

void road_design(){
    //1
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(30.0,2);
    glVertex2f(30.0,0);
    glVertex2f(32.0,0);
    glVertex2f(32.0,3.5);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(26,2);
    glVertex2f(26.0,0);
    glVertex2f(30.0,0);
    glVertex2f(30.0,2);
    glEnd();

    //3
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(24,1.25);
    glVertex2f(24.0,0);
    glVertex2f(26.0,0);
    glVertex2f(26.0,2);
    glEnd();

    //4
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(20.25,1);
    glVertex2f(20.25,0);
    glVertex2f(24,0);
    glVertex2f(24,1.25);
    glEnd();

    //5
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(16,1.75);
    glVertex2f(16,0);
    glVertex2f(20.25,0);
    glVertex2f(20.25,1);
    glEnd();

    //6
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(14,1.75);
    glVertex2f(14,0);
    glVertex2f(16,0);
    glVertex2f(16,1.75);
    glEnd();

    //7
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(10,1.25);
    glVertex2f(10,0);
    glVertex2f(14,0);
    glVertex2f(14,1.75);
    glEnd();

    //8
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(7,2.25);
    glVertex2f(7,0);
    glVertex2f(10,0);
    glVertex2f(10,1.25);
    glEnd();

    //9
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(6.25,3.25);
    glVertex2f(6.25,0);
    glVertex2f(7,0);
    glVertex2f(7,2.25);
    glEnd();

    //10
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(6.25,3.25);
    glVertex2f(4.25,0);
    glVertex2f(6.25,0);
    glEnd();

    //11
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(7,4.75);
    glVertex2f(2.50 ,0);
    glVertex2f(4.5 ,0);
    glEnd();
}

void Road_1(){
    glBegin(GL_POLYGON);
    set_color("Scorpion");
    glVertex2f(2.0,0);
    glVertex2f(32.0,0);
    glVertex2f(32.0,5.0);
    glVertex2f(7.0,5.0);
    glEnd();

    // border side
    glBegin(GL_POLYGON);
    set_color("Thunder");
    glVertex2f(2.0,0);
    glVertex2f(2.5,0.0);
    glVertex2f(2.5,0.0);
    glVertex2f(7.25,5.0);
    glVertex2f(7.0,5.0);
    glEnd();

    // bordertop
    glBegin(GL_POLYGON);
    set_color("Thunder");
    glVertex2f(7.0,5.0);
    glVertex2f(32.0,5.0);
    glVertex2f(32.0,5.25);
    glVertex2f(7.0,5.25);
    glEnd();

    road_design();
}

void containerModel_1(){
    //container 1
    glBegin(GL_POLYGON);
    glColor3ub(245, 176, 65);
    glVertex2f(1,11);
    glVertex2f(4,11);
    glVertex2f(4,12);
    glVertex2f(1,12);
    glEnd();

    // top 1
    glBegin(GL_POLYGON);
    glColor3ub(250, 215, 160);
    glVertex2f(1,12);
    glVertex2f(1.25,12);
    glVertex2f(1.25,12.25);
    glEnd();

    // container 2
    glBegin(GL_POLYGON);
    glColor3ub(46, 134, 193);
    glVertex2f(4,11);
    glVertex2f(6,11);
    glVertex2f(6,12);
    glVertex2f(4,12);
    glEnd();

    // container 3
    glBegin(GL_POLYGON);
    glColor3ub(25, 111, 61);
    glVertex2f(6,11);
    glVertex2f(7,11);
    glVertex2f(7,12);
    glVertex2f(6,12);
    glEnd();

    // side 3
    glBegin(GL_POLYGON);
    glColor3ub(30, 132, 73);
    glVertex2f(7,12);
    glVertex2f(7,11);
    glVertex2f(7.25,11.25);
    glVertex2f(7.25,12.25);
    glEnd();

    // top 3
    glBegin(GL_POLYGON);
    glColor3ub(34, 153, 84);
    glVertex2f(6.25,12);
    glVertex2f(7.0,12);
    glVertex2f(7.25,12.25);
    glVertex2f(6.50,12.25);
    glEnd();

    // container 4
    glBegin(GL_POLYGON);
    glColor3ub(231, 76, 60);
    glVertex2f(1.25,12);
    glVertex2f(3,12);
    glVertex2f(3,13);
    glVertex2f(1.25,13);
    glEnd();

    // top 4
    glBegin(GL_POLYGON);
    glColor3ub(236, 112, 99);
    glVertex2f(1.25,13);
    glVertex2f(3,13);
    glVertex2f(3.25,13.25);
    glVertex2f(1.50,13.25);
    glEnd();

    // container 5
    glBegin(GL_POLYGON);
    glColor3ub(212, 172, 13);
    glVertex2f(3,12);
    glVertex2f(5,12);
    glVertex2f(5,13);
    glVertex2f(3,13);
    glEnd();

    // top 5
    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(3,13);
    glVertex2f(5,13);
    glVertex2f(5.25,13.25);
    glVertex2f(3.25,13.25);
    glEnd();

    // container 6
    glBegin(GL_POLYGON);
    glColor3ub(36, 113, 163);
    glVertex2f(5,12);
    glVertex2f(6.25,12);
    glVertex2f(6.25,13);
    glVertex2f(5,13);
    glEnd();

    // 3d side 6
    glBegin(GL_POLYGON);
    glColor3ub(41, 128, 185);
    glVertex2f(6.25,12);
    glVertex2f(6.5,12.25);
    glVertex2f(6.5,13.25);
    glVertex2f(6.25,13);
    glEnd();

    // 3d top 6
    glBegin(GL_POLYGON);
    glColor3ub(84, 153, 199);
    glVertex2f(5,13);
    glVertex2f(6.25,13);
    glVertex2f(6.50,13.25);
    glVertex2f(5.25,13.25);
    glEnd();

    // container 1
    designSeaLine2(1.65,0.8, 1.6 ,15,  248, 196, 113);
    designSeaLine2(1,0.3, 1.8 , 38,  243, 156, 18);
    designSeaLine2(1,0.3, 2.6 , 37.5,  156, 100, 12);
    designSeaLine2(1,0.3, 2.9 , 38.7,  156, 100, 12);

    design3(0.3,0.5,  4.52, 23.13, 0,0,0,0, 156, 100, 12);
    design3(0.3,0.5,  6.52, 23.13, 0,0,0,0, 156, 100, 12);
    design3(0.3,0.5,  9.52, 23.13, 0,0,0,0, 156, 100, 12);
    design3(0.3,0.5,  11.52, 23.13, 0,0,0,0, 156, 100, 12);

    // container 2
    design3(0.3,0.5, 14.52, 23.0, 0,0,0,0, 174, 214, 241);
    design3(0.3,0.5, 15.52, 23.0, 0,0,0,0, 133, 193, 233);
    design3(0.3,0.5, 16.52, 23.0, 0,0,0,0, 36, 113, 163);
    design3(0.3,0.5, 17.52, 23.0, 0,0,0,0, 31, 97, 141);
    design3(0.3,0.5, 18.52, 23.0, 0,0,0,0, 26, 82, 118);

    designSeaLine2(1,0.3, 4.9 , 37.2,  0,0,0);
    designSeaLine2(1,0.3, 4.9 , 38.7,  52, 152, 219);
    designSeaLine2(1,0.3, 4.9 , 40,  21, 67, 96);

   // container 3
   design3(0.3,0.5, 22.52, 23.0, 0,0,0,0, 40, 180, 99);
   design3(0.3,0.5, 22.52, 23.0, 0,0,0,0, 40, 180, 99);
   design3(0.3,0.5, 23.52, 23.0, 0,0,0,0, 11, 83, 69);
   design3(0.3,0.5, 24.0, 23.18, 0,0,0,0, 46, 204, 113);

    // container 4
    design3(0.3,0.5,  4.52, 25.13, 0,0,0,0, 245, 183, 177);
    design3(0.3,0.5,  5.32, 25.13, 0,0,0,0, 203, 67, 53);
    design3(0.3,0.5,  6.32, 25.13, 0,0,0,0, 176, 58, 46);
    design3(0.3,0.5,  7.32, 25.13, 0,0,0,0, 148, 49, 38);
    design3(0.3,0.5,  8.32, 25.13, 0,0,0,0, 148, 49, 38);
    design3(0.3,0.5,  9.32, 25.13, 0,0,0,0, 148, 49, 38);
    designSeaLine2(1,0.3, 2.2 , 40.7,  169, 50, 38);
    designSeaLine2(1,0.3, 2.2 , 42.7,  169, 50, 38);
    designSeaLine2(1,0.3, 2.3 , 43.96,  100, 30, 22);

    // Contain 5
    designSeaLine2(1,0.3, 3.9 , 41.6,  244, 208, 63);
    designSeaLine2(1,0.3, 3.9 , 42.6,  183, 149, 11);
    designSeaLine2(1,0.3, 4.0 , 43.96,  249, 231, 159);

    design3(0.3,0.5,  11.32, 25.13, 0,0,0,0, 247, 220, 111);
    design3(0.3,0.5,  12.32, 25.13, 0,0,0,0, 183, 149, 11);
    design3(0.3,0.5,  14.32, 25.13, 0,0,0,0, 154, 125, 10);

    // container 6
    designSeaLine2(0.6,0.3, 9.5 , 42.6,  21, 67, 96);
    designSeaLine2(0.6,0.3, 9.5 , 41.6,  21, 67, 96);
    designSeaLine2(0.6,0.3, 9.5 , 42.3,  26, 82, 118);
    designSeaLine2(0.6,0.3, 9.5 , 41.3,  26, 82, 118);
    designSeaLine2(0.6,0.3, 9.65 ,44.1,  26, 82, 118);
}

void container_shadow(){

    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(7.25,5);
    glVertex2f(7.25,3.5);
    glVertex2f(9.50,3.50);
    glVertex2f(9.50,3.75);
    glVertex2f(10.25,3.75);
    glVertex2f(10.25,4);
    glVertex2f(10.75,4);
    glVertex2f(10.75,5);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(11.5,5);
    glVertex2f(11.5,3.5);
    glVertex2f(15.25,3.75);
    glVertex2f(15.25,4.25);
    glVertex2f(17.75,4.25);
    glVertex2f(17.75,5);
    glEnd();

    // arm shadow right
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(11.75,3);
    glVertex2f(11.5,2.75);
    glVertex2f(16,2.25);
    glVertex2f(16,2.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(12.75,3.75);
    glVertex2f(12.5,3.5);
    glVertex2f(15.5,3);
    glVertex2f(15.5,3.5);

    glEnd();
}

void Container_2(){
    container_shadow(); // Right  to left
    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(14,-5,0);
    containerModel_1();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(14,-5,0);
    containerModel_1();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7,0.7,1);
    glTranslatef(9.5,-4,0);
    containerModel_1();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5,0.5,1);
    glTranslatef(13,-3,0);
    containerModel_1();
    glPopMatrix();
}

void Container_3(){
    // Front side
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.8,0.8,1);
    glTranslatef(14,-10,0);
    containerModel_1();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(12.5,-11.5,0);
    containerModel_1();
    glPopMatrix();
}

void Container_4(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(movecX,movecY,0.0f);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(23, 107, 135);
    glVertex2f(1.50, 3.0);
    glVertex2f(1.50, 2.0);
    glVertex2f(3.0, 2.0);
    glVertex2f(3.0, 3.0);
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glColor3ub(100, 204, 197);
    glVertex2f(1.50, 3.0);
    glVertex2f(3.0, 3.0);
    glVertex2f(3.25, 3.25);
    glVertex2f(1.75,3.25);
    glEnd();

    // side
    glBegin(GL_POLYGON);
    glColor3ub(4, 54, 74);
    glVertex2f(3, 3.0);
    glVertex2f(3, 2.0);
    glVertex2f(3.25, 2.25);
    glVertex2f(3.25, 3.25);
    glEnd();

    // shade
    glBegin(GL_POLYGON);
    glColor3ub(66, 125, 157);
    glVertex2f(1.50, 3.0);
    glVertex2f(1.50, 2.0);
    glVertex2f(3.0, 2.00);
    glVertex2f(2, 2.50);
    glEnd();

    glPopMatrix();
}

void container5(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,3,1);
    glTranslatef(4,-10.25,0);
    containerModel_1();
    glPopMatrix();
}

void ship_shades(){
    // left shade
    glBegin(GL_POLYGON);
    set_color("Cship_shadow");
    glVertex2f(0,1.15);
    glVertex2f(0,0);
    glVertex2f(1.50,2);
    glVertex2f(3.50,3.15);
    glVertex2f(3,3.15);
    glEnd();

    //right shade
    glBegin(GL_POLYGON);
    set_color("Cship_shadow");
    glVertex2f(0.75,0);
    glVertex2f(1.50,0);
    glVertex2f(4.25,2.75);
    glEnd();

     //head design shaded
    glBegin(GL_POLYGON);
    set_color("Cship_shadow");
    glVertex2f(5.25,4.0);
    glVertex2f(4.75,5.0);
    glVertex2f(4.25,5.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Cship_shadow");
    glVertex2f(4.25,5.0);
    glVertex2f(3.25,4.0);
    glVertex2f(4.75,5.0);
    glEnd();
}

void Ship_1(){

    // ship floor
    glBegin(GL_POLYGON);
    set_color("Cship_floor");
    glVertex2f(0.0,0.0);
    glVertex2f(2.0,0.0);
    glVertex2f(5.0,3.0);
    glVertex2f(3.0,3.25);
    glVertex2f(0.0,1.25);
    glEnd();

    // right side
    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(5.0,3.0);
    glVertex2f(5.25,4.0);
    glVertex2f(4.75,3.50);
    glVertex2f(4.75,2.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(4.50,2.50);
    glVertex2f(4.75,2.75);
    glVertex2f(4.75,3.25);
    glEnd();

    //ship head
    glBegin(GL_POLYGON);
    set_color("Cship_floor");
    glVertex2f(5.25,4.0);
    glVertex2f(4.75,5.0);
    glVertex2f(4.25,5.0);
    glVertex2f(3.25,4.0);
    glEnd();

    // stairs like top
    glBegin(GL_POLYGON);
    set_color("Crail");
    glVertex2f(3.25,4.0);
    glVertex2f(3.25,3.75);
    glVertex2f(5.0,3.75);
    glVertex2f(5.25,4.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Japonica");
    glVertex2f(3.25,3.75);
    glVertex2f(3.0,3.50);
    glVertex2f(4.75,3.50);
    glVertex2f(5.0,3.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Crail");
    glVertex2f(3.0,3.50);
    glVertex2f(3.0,3.25);
    glVertex2f(4.75,3.25);
    glVertex2f(4.75,3.50);
    glEnd();

    // gap fill up
    glBegin(GL_POLYGON);
    set_color("Cship_floor");
    glVertex2f(3.0,3.25);
    glVertex2f(4.50,2.50);
    glVertex2f(4.75,3.25);
    glEnd();

    // left side wall
    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(0.0,2.00);
    glVertex2f(0.0,1.25);
    glVertex2f(3.0,3.25);
    glVertex2f(3.0,3.50);
    glVertex2f(3.25,3.75);
    glVertex2f(3.25,4.00);
    glEnd();

    // right side wall
    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(1.50,0);
    glVertex2f(2.0,0);
    glVertex2f(4.50,2.50);
    glVertex2f(4.50,3.00);
    glEnd();

    // border right side
    glBegin(GL_POLYGON);
    set_color("Ship_Border");
    glVertex2f(1.85,0);
    glVertex2f(2.0,0);
    glVertex2f(4.50,2.50);
    glVertex2f(4.50,2.65);
    glEnd();

    ship_shades();
}

void Light_1(){

	glBegin(GL_POLYGON);
    set_color("Red light");
    glVertex2f(1,3);
    glVertex2f(1,1);
    glVertex2f(2,1);
    glVertex2f(2,3);
    glEnd();
}

void Adjust_light(){
    // top
    glPushMatrix();
    glScalef(.1,.1,0);
    glTranslatef(53,160.25,0);
    Light_1();
    glPopMatrix();

    //roof
    glPushMatrix();
    glScalef(.1,.1,0);
    glTranslatef(65,145.35,0);
    Light_1();
    glPopMatrix();
}

void Ship_2(){
    container5();
	glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(-12.0,7.0);
    glVertex2f(-1.0,7.0);
    glVertex2f(1.50,3.25);
    glVertex2f(3.00,3.25);
    glVertex2f(3.0,-1.0);
    glVertex2f(-12.0,-1.0);
    glVertex2f(-12.0,7.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(3.0,3.25);
    glVertex2f(36.75,3.25);
    glVertex2f(36.75,-1.0);
    glVertex2f(3.0,-1.0);
    glVertex2f(3.0,3.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(36.75,3.25);
    glVertex2f(38.0,6.0);
    glVertex2f(44.0,6.0);
    glVertex2f(40.0,-1.00);
    glVertex2f(36.75,-1.00);
    glVertex2f(36.75,3.25);
    glEnd();

    // bottom border
    glBegin(GL_POLYGON);
    set_color("Ship_Border");
    glVertex2f(-12.0,-1.0);
    glVertex2f(40.0,-1.0);
    glVertex2f(39.0,-2.00);
    glVertex2f(-11.0,-2.0);
    glVertex2f(-12.0,-1.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(-12.0,6.0);
    glVertex2f(-2.50,6.0);
    glVertex2f(-2.50,5.50);
    glVertex2f(-12.0,5.50);
    glVertex2f(-12.0,6.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(-2.50,6.0);
    glVertex2f(-2.00,6.0);
    glVertex2f(0.50,2.50);
    glVertex2f(0.25,2.00);
    glVertex2f(-2.25,5.50);
    glVertex2f(-2.50,5.50);
    glVertex2f(-2.50,6.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(0.50,2.50);
    glVertex2f(3.00,2.50);
    glVertex2f(3.0,2.0);
    glVertex2f(0.25,2.00);
    glVertex2f(0.5,2.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(0.50,2.50);
    glVertex2f(37.50,2.50);
    glVertex2f(38.0,2.0);
    glVertex2f(0.25,2.00);
    glVertex2f(0.5,2.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(37.50,2.50);
    glVertex2f(38.75,5.50);
    glVertex2f(39.25,5.0);
    glVertex2f(38.0,2.00);
    glVertex2f(37.50,2.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(38.75,5.50);
    glVertex2f(43.75,5.50);
    glVertex2f(43.45,4.99);
    glVertex2f(39.25,5.00);
    glVertex2f(38.75,5.50);
    glEnd();

    glBegin(GL_POLYGON);//white
    set_color("Firefly");
    glVertex2f(-11.50,7.00);
    glVertex2f(-11.50,8.75);
    glVertex2f(-6.75,8.75);
    glVertex2f(-6.75,7.00);
    glVertex2f(-11.50,7.00);
    glEnd();
    glBegin(GL_POLYGON); //white
    set_color("chimney");
    glVertex2f(-11.00,8.75);
    glVertex2f(-9.25,16.25);
    glVertex2f(-6.75,16.25);
    glVertex2f(-6.75,8.75);
    glVertex2f(-11.00,8.75);
    glEnd();
    glBegin(GL_POLYGON);
   // glColor3ub(5, 156, 65); //green
    set_color("Firefly");
    glVertex2f(-9.50,15.25);
    glVertex2f(-6.75,15.25);
    glVertex2f(-6.75,15.00);
    glVertex2f(-9.55,15.00);
    glVertex2f(-9.50,15.25);
    glEnd();
    glBegin(GL_POLYGON);
   // glColor3ub(5, 156, 65); //green
    set_color("Firefly");
    glVertex2f(-9.96,13.25);
    glVertex2f(-6.75,13.25);
    glVertex2f(-6.75,13.00);
    glVertex2f(-10.00,13.00);
    glVertex2f(-9.96,13.25);
    glEnd();
    glBegin(GL_POLYGON);
   // glColor3ub(232, 239, 16); //yellow
    set_color("White");
    glVertex2f(-9.55,15.00);
    glVertex2f(-6.75,15.00);
    glVertex2f(-6.75,13.25);
    glVertex2f(-9.96,13.25);
    glVertex2f(-9.55,15.00);
    glEnd();

    glBegin(GL_POLYGON);//ash chimney duck 1
    glColor3ub(97, 106, 107);
    glVertex2f(-8.00,16.25);
    glVertex2f(-8.00,17.25);
    glVertex2f(-8.50,17.75);
    glVertex2f(-8.25,18.25);
    glVertex2f(-7.50,17.50);
    glVertex2f(-7.25,17.00);
    glVertex2f(-7.00,16.75);
    glVertex2f(-7.00,16.25);
    glVertex2f(-8.00,16.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body");// off-white
    glVertex2f(-6.00,7.00);
    glVertex2f(-6.00,13.00);
    glVertex2f(-1.00,13.00);
    glVertex2f(-1.00,7.00);
    glVertex2f(-6.00,7.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Off white"); // off-white
    glVertex2f(-1.00,11.75);
    glVertex2f(4.00,11.75);
    glVertex2f(4.00,3.25);
    glVertex2f(1.50,3.25);
    glVertex2f(-1.00,7.00);
    glVertex2f(-1.00,11.75);
    glEnd();

    // Minor details
    glBegin(GL_POLYGON);
    glColor3ub(229, 232, 232);
    glVertex2f(-1.00,13.00);
    glVertex2f(3.00,13.00);
    glVertex2f(3.00,11.75);
    glVertex2f(-1.00,11.75);
    glVertex2f(-1.00,13.00);
    glEnd();

    //T
    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(3.00,11.75);
    glVertex2f(3.00,13.00);
    glVertex2f(4.00,13.00);
    glVertex2f(4.00,11.75);
    glVertex2f(3.00,11.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(4.00,10.75);
    glVertex2f(4.00,13.00);
    glVertex2f(9.50,13.00);
    glVertex2f(9.50,10.75);
    glVertex2f(4.00,10.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(9.50,11.50);
    glVertex2f(9.50,13.00);
    glVertex2f(11.50,13.00);
    glVertex2f(11.50,11.50);
    glVertex2f(9.50,11.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(4.00,9.00);
    glVertex2f(4.00,10.75);
    glVertex2f(9.50,10.75);
    glVertex2f(9.50,9.00);
    glVertex2f(4.00,9.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(4.00,3.25);
    glVertex2f(4.00,9.00);
    glVertex2f(9.50,9.00);
    glVertex2f(9.50,3.25);
    glVertex2f(4.00,3.25);
    glEnd();

    // Railing
    glBegin(GL_POLYGON);
    set_color("Railing");
    glVertex2f(-5.75,13.00);
    glVertex2f(-5.75,14.50);
    glVertex2f(12.50,14.50);
    glVertex2f(11.50,13.00);
    glVertex2f(-5.75,13.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("chimney"); // chimney 2
    glVertex2f(-5.50,14.50);
    glVertex2f(-3.50,14.50);
    glVertex2f(-3.50,15.25);
    glVertex2f(-5.25,15.25);
    glVertex2f(-5.50,14.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("chimney");  // chimney 2
    glVertex2f(-5.22,15.50);
    glVertex2f(-5.00,16.25);
    glVertex2f(-3.50,16.25);
    glVertex2f(-3.50,15.50);
    glVertex2f(-5.22,15.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Firefly"); //yellow // chimney 2
    glVertex2f(-5.22,15.50);
    glVertex2f(-3.50,15.50);
    glVertex2f(-3.50,15.25);
    glVertex2f(-5.29,15.25);
    glVertex2f(-5.22,15.50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(81, 90, 90); // chimney duck 2
    glVertex2f(-4.50,16.25);
    glVertex2f(-4.50,17.00);
    glVertex2f(-5.00,17.50);
    glVertex2f(-4.75,18.00);
    glVertex2f(-4.00,17.25);
    glVertex2f(-3.75,16.75);
    glVertex2f(-3.75,16.25);
    glVertex2f(-4.50,16.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Top_floor"); // building
    glVertex2f(-3.00,14.50);
    glVertex2f(-3.00,16.00);
    glVertex2f(10.85,15.99);
    glVertex2f(10.00,14.50);
    glVertex2f(-3.00,14.50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(93, 64, 55 );
    glVertex2f(-3.00,16.00);
    glVertex2f(-3.00,16.25);
    glVertex2f(11.00,16.25);
    glVertex2f(10.85,15.99);
    glVertex2f(-3.00,16.00);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(0, 150, 136 );//green-Cw-1
    set_color("ship_window");
    glVertex2f(-2.50,15.50);
    glVertex2f(-0.50,15.50);
    glVertex2f(-0.50,15.00);
    glVertex2f(-2.50,15.00);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(0, 150, 136 );//green-CW-2
    set_color("ship_window");
    glVertex2f(0.50,15.00);
    glVertex2f(0.50,15.50);
    glVertex2f(2.00,15.50);
    glVertex2f(2.00,15.00);
    glVertex2f(0.50,15.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-CW-3
    glVertex2f(4.00,15.25);
    glVertex2f(3.75,15.75);
    glVertex2f(4.75,15.75);
    glVertex2f(4.75,15.25);
    glVertex2f(4.00,15.25);
    glEnd();

    glBegin(GL_POLYGON);    //green-CW-4
    set_color("ship_window");
    glVertex2f(5.50,15.25);
    glVertex2f(5.50,15.75);
    glVertex2f(6.75,15.75);
    glVertex2f(6.75,15.25);
    glVertex2f(5.50,15.25);
    glEnd();
    glBegin(GL_POLYGON);

    set_color("ship_window");    //green-CW-5
    glVertex2f(7.50,15.25);
    glVertex2f(7.50,15.75);
    glVertex2f(9.00,15.75);
    glVertex2f(9.00,15.25);
    glVertex2f(7.50,15.25);
    glEnd();
    glBegin(GL_POLYGON);

    //green-CW-6'
    set_color("ship_window");
    glVertex2f(9.50,15.25);
    glVertex2f(9.50,15.75);
    glVertex2f(10.50,15.75);
    glVertex2f(10.00,15.25);
    glVertex2f(9.50,15.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189);//stand-W
    glVertex2f(3.50,16.25);
    glVertex2f(3.50,18.50);
    glVertex2f(4.50,18.50);
    glVertex2f(4.50,16.25);
    glVertex2f(3.50,16.25);
    glEnd();
    glBegin(GL_POLYGON);//Gray
    glColor3ub(158, 158, 158);
    glVertex2f(3.50,18.50);
    glVertex2f(3.50,18.75);
    glVertex2f(5.50,18.75);
    glVertex2f(5.50,18.50);
    glVertex2f(3.50,18.50);
    glEnd();

    glBegin(GL_POLYGON);//W
    glColor3ub(189, 189, 189);
    glVertex2f(3.75,18.75);
    glVertex2f(3.75,21.25);
    glVertex2f(4.50,21.25);
    glVertex2f(4.50,18.75);
    glVertex2f(3.75,18.75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(158, 158, 158);//Gray
    glVertex2f(3.25,21.25);
    glVertex2f(3.25,21.75);
    glVertex2f(6.25,21.75);
    glVertex2f(6.25,21.25);
    glVertex2f(3.25,21.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189);//W
    glVertex2f(3.75,21.75);
    glVertex2f(3.75,26.00);
    glVertex2f(4.50,26.00);
    glVertex2f(4.50,21.75);
    glVertex2f(3.75,21.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(158, 158, 158);//Gray-CM TOP

    glVertex2f(3.75,26.00);
    glVertex2f(3.25,26.50);
    glVertex2f(5.00,26.50);
    glVertex2f(4.50,26.00);
    glVertex2f(3.75,26.00);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(158, 158, 158);//Gray-CM
    glVertex2f(3.75,26.50);
    glVertex2f(3.25,27.00);
    glVertex2f(5.00,27.00);
    glVertex2f(4.50,26.50);
    glVertex2f(3.75,26.50);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(247, 8, 8 );//Flag-Red
    set_color("Maroon");
    glVertex2f(3.75,24.50);
    glVertex2f(1.75,24.50);
    glVertex2f(1.75,25.50);
    glVertex2f(3.75,25.50);
    glVertex2f(3.75,24.50);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(0, 150, 136 );//green-W-1
    set_color("ship_window");
    glVertex2f(-5.50,11.75);
    glVertex2f(-5.00,11.75);
    glVertex2f(-5.00,12.25);
    glVertex2f(-5.50,12.25);
    glVertex2f(-5.50,11.75);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(0, 150, 136 );//green-W-2
    set_color("ship_window");
    glVertex2f(-2.75,11.75);
    glVertex2f(-2.25,11.75);
    glVertex2f(-2.25,12.25);
    glVertex2f(-2.75,12.25);
    glVertex2f(-2.75,11.75);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(0, 150, 136 );//green-W-3
    set_color("ship_window");
    glVertex2f(-4.75,9.50);
    glVertex2f(-4.25,9.50);
    glVertex2f(-4.25,10.00);
    glVertex2f(-4.75,10.00);
    glVertex2f(-4.75,9.50);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(0, 150, 136 );//green-W-4
    set_color("ship_window");
    glVertex2f(-1.75,9.50);
    glVertex2f(-1.25,9.50);
    glVertex2f(-1.25,10.00);
    glVertex2f(-1.75,10.00);
    glVertex2f(-1.75,9.50);
    glEnd();

    glBegin(GL_POLYGON);
  //  glColor3ub(0, 150, 136 );//green-W-5
    set_color("ship_window");
    glVertex2f(-5.50,7.25);
    glVertex2f(-5.00,7.25);
    glVertex2f(-5.00,7.75);
    glVertex2f(-5.50,7.75);
    glVertex2f(-5.50,7.25);
    glEnd();

    glBegin(GL_POLYGON);
    //  glColor3ub(0, 150, 136 );//green-W-6
    set_color("ship_window");
    glVertex2f(-3.50,7.25);
    glVertex2f(-3.00,7.25);
    glVertex2f(-3.00,7.75);
    glVertex2f(-3.50,7.75);
    glVertex2f(-3.50,7.25);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(0, 150, 136 );//green-W-7
    set_color("ship_window");
    glVertex2f(-1.75,7.25);
    glVertex2f(-1.25,7.25);
    glVertex2f(-1.25,7.75);
    glVertex2f(-1.75,7.75);
    glVertex2f(-1.75,7.25);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(0, 150, 136 );//green-W-8
     set_color("ship_window");
    glVertex2f(0.50,9.50);
    glVertex2f(1.25,9.50);
    glVertex2f(1.25,10.00);
    glVertex2f(0.50,10.00);
    glVertex2f(0.50,9.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");
    glVertex2f(2.75,9.50);
    glVertex2f(3.25,9.50);
    glVertex2f(3.25,10.00);
    glVertex2f(2.75,10.00);
    glVertex2f(2.75,9.50);
    glEnd();
    glBegin(GL_POLYGON);
     set_color("ship_window");//green-W-10
    glVertex2f(0.75,7.25);
    glVertex2f(1.25,7.25);
    glVertex2f(1.25,7.75);
    glVertex2f(0.75,7.75);
    glVertex2f(0.75,7.25);
    glEnd();
    glBegin(GL_POLYGON);
     set_color("ship_window");//green-W-11
    glVertex2f(2.75,7.25);
    glVertex2f(3.25,7.25);
    glVertex2f(3.25,7.75);
    glVertex2f(2.75,7.75);
    glVertex2f(2.75,7.25);
    glEnd();
    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-12
    glVertex2f(4.25,12.00);
    glVertex2f(4.75,12.00);
    glVertex2f(4.75,12.50);
    glVertex2f(4.25,12.50);
    glVertex2f(4.25,12.00);
    glEnd();
    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-13
    glVertex2f(5.75,12.00);
    glVertex2f(7.25,12.00);
    glVertex2f(7.25,12.50);
    glVertex2f(5.75,12.50);
    glVertex2f(7.75,12.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-14
    glVertex2f(8.25,12.00);
    glVertex2f(8.75,12.00);
    glVertex2f(8.75,12.50);
    glVertex2f(8.25,12.50);
    glVertex2f(8.25,12.00);
    glEnd();

    glBegin(GL_POLYGON);
     set_color("ship_window");//green-W-15
    glVertex2f(4.50,9.50);
    glVertex2f(5.50,9.50);
    glVertex2f(5.50,10.00);
    glVertex2f(4.50,10.00);
    glVertex2f(4.50,9.50);
    glEnd();

    glBegin(GL_POLYGON);
     set_color("ship_window");//green-W-16
    glVertex2f(6.75,9.50);
    glVertex2f(8.00,9.50);
    glVertex2f(8.00,10.00);
    glVertex2f(6.75,10.00);
    glVertex2f(6.75,9.50);
    glEnd();

    glBegin(GL_POLYGON);
     set_color("ship_window");//green-W-17
    glVertex2f(8.50,9.50);
    glVertex2f(9.25,9.50);
    glVertex2f(9.25,10.00);
    glVertex2f(8.50,10.00);
    glVertex2f(8.50,9.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-18
    glVertex2f(5.25,7.25);
    glVertex2f(5.75,7.25);
    glVertex2f(5.75,7.75);
    glVertex2f(5.25,7.75);
    glVertex2f(5.25,7.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-19
    glVertex2f(6.50,7.25);
    glVertex2f(7.00,7.25);
    glVertex2f(7.00,7.75);
    glVertex2f(6.50,7.75);
    glVertex2f(6.50,7.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-20
    glVertex2f(7.75,7.25);
    glVertex2f(8.25,7.25);
    glVertex2f(8.25,7.75);
    glVertex2f(7.75,7.75);
    glVertex2f(7.75,7.25);
    glEnd();

    // floor lines
    glBegin(GL_POLYGON);
    glColor3ub(208, 211, 212);
    glVertex2f(-6.00,10.75);
    glVertex2f(-6.00,11.00);
    glVertex2f(9.50,11.00);
    glVertex2f(9.50,10.75);
    glVertex2f(-6.00,10.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(208, 211, 212);
    glVertex2f(-6.00,8.75);
    glVertex2f(-6.00,9.00);
    glVertex2f(9.50,9.00);
    glVertex2f(9.50,8.75);
    glVertex2f(-6.00,8.75);
    glEnd();
}

void Adjust_ship(){
    glPushMatrix();
    glScalef(0.26,0.27,1);
    glTranslatef(15,38,0);
    Ship_2();
    glPopMatrix();
    Adjust_light();
}

void Magnet(){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(moveXh,moveY,0.0f);

    circle(0.25, 2, 6,241, 196, 15);
    circle(0.15, 2, 6,255, 255,255 );
    circle(0.25, 2.75, 6,241, 196, 15 );
    circle(0.15, 2.75, 6,255,255,255 );

    // Lines inside circle:
    glBegin(GL_LINES);
    glLineWidth(2);
    glColor3ub(123, 36, 28);
    glVertex2f(1.75,6);
    glVertex2f(2.25,6);

    glVertex2f(2.0,6.25);
    glVertex2f(2.0,5.75);

    glVertex2f(2.5,6);
    glVertex2f(3.0,6);

    glVertex2f(2.75,6.25);
    glVertex2f(2.75,5.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(1.50,5.75);
    glVertex2f(1.50,5.50);
    glVertex2f(3.25,5.50);
    glVertex2f(3.25,5.75);
    glEnd();

    // design
    glBegin(GL_POLYGON);
    glColor3ub(243, 156, 18);
    glVertex2f(1.50,5.75);
    glVertex2f(1.50,5.50);
    glVertex2f(1.55,5.54);
    glVertex2f(2.93,5.63);
    glVertex2f(1.57,5.68);
    glEnd();

    glPopMatrix();
}

void LineString(){
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glLineWidth(5);
    glVertex2f(2.50,7.0);
    glVertex2f(2.0,6.25 + stringY);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glLineWidth(5);
    glVertex2f(2.50,7.0);
    glVertex2f(2.75,6.25 + stringY);
    glEnd();
}

void hook(){
    circle(.5,2.5,7,128, 139, 150);
    circle(.25,2.5,7,171, 178, 185);
    LineString();

    //1
    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(1.75,7.75);
    glVertex2f(1.75,6.75);
    glVertex2f(2.0,6.50);
    glVertex2f(2.0,7.75);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(2.75,8.50);
    glVertex2f(2.75,7.25);
    glVertex2f(3.0,7.25);
    glVertex2f(3.0,8.50);
    glEnd();

    //3
    glBegin(GL_POLYGON);
    glColor3ub(212, 172, 13);
    glVertex2f(2,7.25);
    glVertex2f(2,6.50);
    glVertex2f(3.0,7.25);
    glVertex2f(3.0,7.75);
    glEnd();

    //4
    glBegin(GL_POLYGON);
    glColor3ub(244, 208, 63);
    glVertex2f(2,7.25);
    glVertex2f(3.0,7.75);
    glVertex2f(2.75,7.75);
    glVertex2f(2.0,7.40);
    glEnd();

    //5
    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(2.75,8.50);
    glVertex2f(2.75,8.25);
    glVertex2f(3.0,8.25);
    glVertex2f(3.0,8.50);
    glEnd();

    design1(0.9,0.9,3.1,8.4,30,0,0,0,246, 221, 204);
    design1(0.5,0.9,3.84,8.47,30,0,0,0,252, 243, 207);
}

void Crane1Design(){
    design2(0.7,1,16.32,3.73,00,0,0,0,192, 57, 43);
    design3(1,1,11.32,6.73,00,0,0,0,236, 112, 99);
    design3(1.1,2.3,5.32,2.3,00,0,0,0,241, 148, 138);
}

void Crane1(){

    // arm 1
    glBegin(GL_POLYGON);
    glColor3ub(169, 50, 38);
    glVertex2f(5.5,2.75);
    glVertex2f(6.25,2.75);
    glVertex2f(6.25,8.25);
    glVertex2f(5.5,8.25);
    glEnd();

    // 3d like effect
    glBegin(GL_POLYGON);
    glColor3ub(123, 36, 28);
    glVertex2f(6.25,2.75);
    glVertex2f(6.50,3.0);
    glVertex2f(6.50,8.0);
    glVertex2f(6.25,8.0);
    glEnd();

    // arm 2
    glBegin(GL_POLYGON);
    glColor3ub(169, 50, 38 );
    glVertex2f(10.75,2.75);
    glVertex2f(11.5,2.75);
    glVertex2f(11.5,8.25);
    glVertex2f(10.75,8.25);
    glEnd();

    // 3d like effect
    glBegin(GL_POLYGON);
    glColor3ub(123, 36, 28);
    glVertex2f(11.5,2.75);
    glVertex2f(11.75,3.0);
    glVertex2f(11.75,8.0);
    glVertex2f(11.5,8.0);
    glEnd();

    // Bar
    glBegin(GL_POLYGON);
    glColor3ub(214, 137, 16);
    glVertex2f(1.5,8.0);
    glVertex2f(15.0,8.0);
    glVertex2f(15.50,8.25);
    glVertex2f(2.0,8.25);
    glEnd();

    // 3d effect width bar
    glBegin(GL_POLYGON);
    glColor3ub(185, 119, 14);
    glVertex2f(1.5,7.75);
    glVertex2f(15.0,7.75);
    glVertex2f(15.0,8.0);
    glVertex2f(1.50,8.0);
    glEnd();

    // 3d effect side bar
    glBegin(GL_POLYGON);
    glColor3ub(185, 119, 14);
    glVertex2f(15.0,7.75);
    glVertex2f(15.50,8.0);
    glVertex2f(15.50,8.25);
    glVertex2f(15.0,8.0);
    glEnd();
}

void Crane2(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.0,0.75,0);
    Crane1();
    glPopMatrix();
}

void Wh_door(){
    glBegin(GL_POLYGON);
    set_color("Hawaiian Tan");
    glVertex2f(21,3.25);
    glVertex2f(21,2.5);
    glVertex2f(22.50,2.5);
    glVertex2f(22.50,3.25);
    glEnd();

    // shadow
    glBegin(GL_POLYGON);
    set_color("Hairy Heath");
    glVertex2f(21,3.25);
    glVertex2f(21,2.5);
    glVertex2f(22.50,2.5);
    glVertex2f(21.50,2.75);
    glEnd();

    // window
    //float a = 0.50;
    glBegin(GL_POLYGON);
    set_color("window");
    glVertex2f(21.50,5.75);
    glVertex2f(21.50,5.25);
    glVertex2f(22,5.25);
    glVertex2f(22,5.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("window");
    glVertex2f(22.50,5.75);
    glVertex2f(22.50,5.25);
    glVertex2f(23,5.25);
    glVertex2f(23,5.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("window");
    glVertex2f(23.50,5.75);
    glVertex2f(23.50,5.25);
    glVertex2f(24,5.25);
    glVertex2f(24,5.75);
    glEnd();
}

void Warehouse_shadow(){
        glBegin(GL_LINES);
        glLineWidth(4);
        set_color("Hairy Heathy");
        glVertex2f(26.0, 6.75);
        glVertex2f(26.0, 4.0);
        glEnd();

        glBegin(GL_POLYGON);
        set_color("warehouse1");
        glVertex2f(26.0, 4.0);
        glVertex2f(29.0, 4.0);
        glVertex2f(29.0, 5.25);
        glVertex2f(27.25, 5.25);
        glVertex2f(27.25, 6.75);
        glVertex2f(26.0, 6.75);
        glEnd();
}

void Warehouse_2(){
    // 1
    glBegin(GL_POLYGON);
    set_color("Tango");
    glVertex2f(20.25,4);
    glVertex2f(20.25,2.25);
    glVertex2f(23.25,2.25);
    glVertex2f(23.25,4.0);
    glEnd();

    // border top 1
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(20,4);
    glVertex2f(23.25,4.0);
    glVertex2f(23.25,4.25);
    glVertex2f(20.0,4.25);
    glEnd();

    // border bottom 1
    glBegin(GL_POLYGON);
    set_color("Tango_Dark");
    glVertex2f(20.25,2.50);
    glVertex2f(20.25,2.25);
    glVertex2f(23.25,2.25);
    glVertex2f(23.25,2.50);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    set_color("Hawaiian Tan");
    glVertex2f(23.25,4.0);
    glVertex2f(23.25,2.25);
    glVertex2f(24.50,3.0);
    glVertex2f(24.50,4.75);
    glEnd();

    // border top 2
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(23.25,4.25);
    glVertex2f(23.25,4.0);
    glVertex2f(24.50,4.75);
    glVertex2f(24.50,5.0);
    glEnd();

    //3
    glBegin(GL_POLYGON);
    set_color("Tango");
    glVertex2f(21.25,6.0);
    glVertex2f(21.25,5.0);
    glVertex2f(24.50,5.0);
    glVertex2f(24.50,6.0);
    glEnd();

    // 3d side
    glBegin(GL_POLYGON);
    set_color("Hawaiian Tan");
    glVertex2f(24.50,6.25);
    glVertex2f(24.50,3.0);
    glVertex2f(26,3.75);
    glVertex2f(26,7);
    glEnd();

    // border top
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(20.75,6.25);
    glVertex2f(20.75,6.00);
    glVertex2f(24.50,6.0);
    glVertex2f(24.50,6.25);
    glEnd();

    // top side border
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(24.50,6.25);
    glVertex2f(24.50,6.0);
    glVertex2f(26,6.75);
    glVertex2f(26,7);
    glEnd();

    // new 4
    glBegin(GL_POLYGON);
    set_color("Tango");
    glVertex2f(26,7);
    glVertex2f(26,3.75);
    glVertex2f(30.50,3.75);
    glVertex2f(30.50,7);
    glEnd();

    // border bottom
    glBegin(GL_POLYGON);
    set_color("Tango_Dark");
    glVertex2f(26,4);
    glVertex2f(26,3.75);
    glVertex2f(30.50,3.75);
    glVertex2f(30.50,4);
    glEnd();

    // top
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(26,7);
    glVertex2f(26,6.75);
    glVertex2f(30.50,6.75);
    glVertex2f(30.50,7);
    glEnd();

    // border bottom 2 & 3
    glBegin(GL_POLYGON);
    set_color("Tango_Dark");
    glVertex2f(23.25,2.50);
    glVertex2f(23.25,2.25);
    glVertex2f(26,3.75);
    glVertex2f(26,4);
    glEnd();

    // new 4 3d effect side
    glBegin(GL_POLYGON);
    set_color("Hairy Heath");
    glVertex2f(30.50,7);
    glVertex2f(30.50,3.75);
    glVertex2f(31,4);
    glVertex2f(31,6.75);
    glEnd();

    // bottom border
    glBegin(GL_POLYGON);
    set_color("Tango_Dark");
    glVertex2f(30.50,4);
    glVertex2f(30.50,3.75);
    glVertex2f(31,4);
    glVertex2f(31,4.25);
    glEnd();

    // top border
    glBegin(GL_POLYGON);
    set_color("White");
    glVertex2f(30.50,7);
    glVertex2f(30.50,6.75);
    glVertex2f(31,6.50);
    glVertex2f(31,6.75);
    glEnd();

    // yard
    glBegin(GL_POLYGON);
    set_color("Emperor");
    glVertex2f(23.25,2.25);
    glVertex2f(30.50,3.75);
    glVertex2f(26,3.75);
    glEnd();

    // roof 1
    glBegin(GL_POLYGON);
    glColor3ub(20, 90, 50);
    glVertex2f(21.25,5.0);
    glVertex2f(20.0,4.25);
    glColor3ub(25, 111, 61);
    glVertex2f(23.25,4.25);
    glColor3ub(30, 132, 73);
    glVertex2f(24.50,5.0);
    glEnd();

    // roof 2
    glBegin(GL_POLYGON);
    glColor3ub(20, 90, 50);
    glVertex2f(20.75,6.25);
    glColor3ub(25, 111, 61);
    glVertex2f(24.50,6.25);
    glColor3ub(30, 132, 73);
    glVertex2f(26.0,7.0);
    glColor3ub(34, 153, 84);
    glVertex2f(22.0,7.0);
    glEnd();

    Wh_door();
    Warehouse_shadow();

    // dark to light
   // glColor3ub(20, 90, 50);
   // glColor3ub(25, 111, 61);
   // glColor3ub(30, 132, 73);
   // glColor3ub(34, 153, 84);
}

void Truck_1(){

    //Object: Truck
    // Back site of the truck
	glBegin(GL_POLYGON);
    glColor3ub(46, 134, 193 );
    // glColor3ub(33, 97, 140);
    glVertex2f(-9.75,-3.75);
    glVertex2f(-9.75,-0.50);
    glVertex2f(-4.00,-0.50);
    glVertex2f(-4.00,-3.75);
    glVertex2f(-9.75,-3.75);
    glEnd();

    glBegin(GL_POLYGON);
    // glColor3ub(20, 148, 242 );
    glColor3ub(0,125,218);
    glVertex2f(-9.50,-1.50);
    glVertex2f(-9.50,-0.75);
    glVertex2f(-4.25,-0.75);
    glVertex2f(-4.25,-1.50);
    glVertex2f(-9.50,-1.50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(48, 183, 229);
    glColor3ub(3,168,224);
    glVertex2f(-9.50,-2.50);
    glVertex2f(-9.50,-1.50);
    glVertex2f(-4.25,-1.50);
    glVertex2f(-4.25,-2.50);
    glVertex2f(-9.50,-2.50);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(38, 176, 183);
    glColor3ub(0,125,218);
    glVertex2f(-9.50,-2.50);
    glVertex2f(-9.50,-2.50);
    glVertex2f(-4.25,-2.50);
    glVertex2f(-4.25,-3.50);
    glVertex2f(-9.50,-3.50);
    glEnd();

    //Front side of the Truck
    glBegin(GL_POLYGON);
    glColor3ub(27, 38, 49);
    glVertex2f(-4.00,-1.75);
    glVertex2f(-3.75,-1.75);
    glVertex2f(-3.75,-4.25);
    glVertex2f(-4.00,-4.25);
    glVertex2f(-4.00,-1.75);
    glEnd();

    glBegin(GL_POLYGON);
  //  glColor3ub( 241, 196, 15);// Yellow-1
    glColor3ub(0,92,188);
    glVertex2f(-3.75,-3.00);
    glVertex2f(-3.75,-1.50);
    glVertex2f(-1.75,-1.50);
    glVertex2f(-1.00,-2.75);
    glVertex2f(-1.00,-3.00);
    glVertex2f(-3.75,-3.00);
    glEnd();
    glBegin(GL_POLYGON);
  //  glColor3ub( 241, 196, 15);// Yellow-2
    glColor3ub(0,92,188);
    glVertex2f(-3.75,-4.25);
    glVertex2f(-3.75,-3.00);
    glVertex2f(-2.75,-3.00);
    glVertex2f(-2.75,-3.25);
    glVertex2f(-3.25,-3.50);
    glVertex2f(-3.50,-3.75);
    glVertex2f(-3.50,-4.25);
    glVertex2f(-3.75,-4.25);
    glEnd();
    glBegin(GL_POLYGON);
    //glColor3ub( 241, 196, 15);// Yellow-3
    glColor3ub(0,92,188);
    glVertex2f(-2.75,-3.00);
    glVertex2f(-1.00,-3.00);
    glVertex2f(-1.00,-4.00);
    glVertex2f(-2.00,-4.00);
    glVertex2f(-2.00,-3.75);
    glVertex2f(-2.25,-3.50);
    glVertex2f(-2.75,-3.25);
    glVertex2f(-2.75,-3.00);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 38, 49);
    glVertex2f(-2.00,-4.25);
    glVertex2f(-2.00,-4.00);
    glVertex2f(-1.00,-4.00);
    glVertex2f(-1.00,-4.25);
    glVertex2f(-2.00,-4.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(234, 236, 238); //Light
    glVertex2f(-1.25,-3.50);
    glVertex2f(-1.25,-3.25);
    glVertex2f(-1.00,-3.25);
    glVertex2f(-1.00,-3.50);
    glVertex2f(-1.25,-3.50);
    glEnd();

    //Under container
    glBegin(GL_POLYGON);
    glColor3ub(93, 109, 126);
    glVertex2f(-4.75,-4.00);
    glVertex2f(-4.75,-3.75);
    glVertex2f(-4.00,-3.75);
    glVertex2f(-4.00,-4.00);
    glVertex2f(-4.75,-4.00);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80 );
    glVertex2f(-7.50,-3.75);
    glVertex2f(-4.75,-3.75);
    glVertex2f(-4.75,-4.25);
    glVertex2f(-7.25,-4.25);
    glVertex2f(-7.25,-4.00);
    glVertex2f(-7.50,-3.75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);//1
    glVertex2f(-7.00,-3.75);
    glVertex2f(-6.50,-3.75);
    glVertex2f(-6.50,-4.00);
    glVertex2f(-7.00,-4.00);
    glVertex2f(-7.00,-3.75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);//2
    glVertex2f(-6.25,-4.00);
    glVertex2f(-6.25,-3.75);
    glVertex2f(-5.00,-3.75);
    glVertex2f(-5.00,-4.00);
    glVertex2f(-6.25,-4.00);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(229, 35, 29);// red
    glVertex2f(-9.50,-4.25);
    glVertex2f(-9.50,-3.75);
    glVertex2f(-9.25,-3.75);
    glVertex2f(-9.25,-4.25);
    glVertex2f(-9.50,-4.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(93, 109, 126);
    glVertex2f(-9.25,-4.25);
    glVertex2f(-9.25,-3.75);
    glVertex2f(-8.75,-3.75);
    glVertex2f(-8.75,-4.25);
    glVertex2f(-9.25,-4.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80 );
    glVertex2f(-8.75,-4.00);
    glVertex2f(-8.75,-3.75);
    glVertex2f(-8.50,-3.75);
    glVertex2f(-8.75,-4.00);
    glEnd();

    // Truck window
     glBegin(GL_POLYGON);
    glColor3ub(213, 216, 220 );
    glVertex2f(-3.25,-2.50);
    glVertex2f(-3.25,-1.75);
    glVertex2f(-2.00,-1.75);
    glVertex2f(-1.25,-2.75);
    glVertex2f(-3.25,-2.50);
    glEnd();

    circle(0.59,-2.75,-4.00,28, 40, 51 ); //front big
    circle(0.33,-2.75,-4.00,128,139,150);// front small
    circle(0.59,-8.00,-4.00,28,40,51);// back big
    circle(0.33,-8.00,-4.00,128, 139, 150);//back small
}

void Adjust_Truck(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.5,0.5,1);
    glTranslatef(50+truckX,5,0);
    Truck_1();
    glPopMatrix();
}

void background_2(){

    Road_1();
    Warehouse_2();
    Ship_1();
    Container_2();
    Crane2();
    Container_4();
    Container_3();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(moveXh,0.0f,0.0f);
    hook();
    glPopMatrix();

    Magnet();
    Crane1();
    Crane1Design();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(moveShip,0.0f,0.0f);
    Adjust_ship();
    glPopMatrix();

    Adjust_Truck();
}

void display1() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    background_1();
    background_2();

    drawRain();
    glutSwapBuffers();
    glFlush();
}

void Cranekeyboard(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            if(moveY <= 0){
                moveY += speed ;
                stringY += speed ;
                if(pick == true){
                    if(movecY <= 2.5){
                        movecY += speed ;
                    }
                }
            }
            break;

        case GLUT_KEY_DOWN:
             if(moveY >= -2.5){
                moveY -= speed ;
                stringY -= speed ;

                if(movecY > 0 && pick == true){
                    movecY -=speed ;
                }
            }
            break;

        case GLUT_KEY_LEFT:
             if(moveY >= 0 && moveXh >= 0){

                    moveXh -= speed ;
                    if(pick == true){
                        movecX -= speed ;
                    }
                }
            break;

        case GLUT_KEY_RIGHT:
                if(moveY >= 0 && moveXh <= 12.5){
                    moveXh += speed ;
                    if(pick == true){
                        movecX += speed ;
                    }
                }
            break;
    }
    glutPostRedisplay();
}

void shipAnimation(int value) {

    if(ship_start == true){
     moveShip += shipSpeed;
      if(moveShip  > 31.5f  ){
            moveShip = 31.5;
            ship_start2 = true;
            train_start2 = true;
            currentDisplay = 2;
       }
    }else{
            moveShip = moveShip;
    }
    glutPostRedisplay();
    glutTimerFunc(20, shipAnimation, 0);
}

void CloudMovement(int value) {
    cloudX -= 0.02;
    // Reset when one full set has passed
    if (cloudX <= -45.0f) {
        cloudX = 0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(20, CloudMovement, 0);
}

void truckMovement(int value){
    if(truckStart == true){
        truckX += 0.05;
        if(truckX >= 35){
            truckX = 50;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20,truckMovement, 0);
}

//----------------------------------------------------Start of Scenario 2-----------------------------------------------------------------------------

float Ship_position = -105;
float Ship_speed = 0.18;
float Dew_position= -10;
float Dew_speed=0.006;
float cloud_position= -10;
float cloud_speed=0.01;
float train_position = -70;
float train_speed=0.15;

void Sun(){
    if(isDayScene==true)
    {
        glPushMatrix();
        glScalef(7,6,1);
        glTranslatef(2,4.9,0);
        glBegin(GL_POLYGON);
        for(int i=0; i<200; i++)
        {
            set_color("SunC");
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.85;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
    }
}

void Moon(){
    if (isDayScene==false){
    glPushMatrix();
    glScalef(4,4,1);
    glTranslatef(-6,6,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        set_color("MoonD");
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.85;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
    }
}

void Dew(){
    glBegin(GL_POLYGON);// Buildings
	set_color("DewC"); // Yellow
	glVertex2f(8.0f, -6.50f);
	glVertex2f(8.0f, -6.75f);
	glVertex2f(9.0f, -7.25f);
	glVertex2f(10.75f, -7.50f);
	glVertex2f(12.50f, -7.25f);
	glVertex2f(13.25f, -6.75f);
	glVertex2f(10.50f, -6.25f);
	glVertex2f(8.50f, -6.25f);
	glVertex2f(12.50f, -7.25f);
	glEnd();
}

void adjust_dew(){

    glPushMatrix();
    glScalef(5,0.5,0);
    glTranslatef(-5,-12,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(5,0.5,0);
    glTranslatef(-3,-25,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(5,0.5,0);
    glTranslatef(-17,-25,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(5,0.5,0);
    glTranslatef(-10,-29,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(3,0.3,0);
    glTranslatef(-12,-8.6,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(3,0.3,0);
    glTranslatef(-19,-8,0);
    Dew();
    glPopMatrix();

    //
    glPushMatrix();
    glScalef(1,0.3,0);
    glTranslatef(-10,10,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2,0.3,0);
    glTranslatef(-17,8,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2,0.3,0);
    glTranslatef(-32,9,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2,0.3,0);
    glTranslatef(0,10,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2,0.3,0);
    glTranslatef(6,8,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(2,0.3,0);
    glTranslatef(-2,-3,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(2,0.3,0);
    glTranslatef(6,-6,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(3,0.3,0);
    glTranslatef(-28,-6,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(3,0.3,0);
    glTranslatef(-35,-12,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(6,0.5,0);
    glTranslatef(-10,-16,0);
    Dew();
    glPopMatrix();

    glPushMatrix();
    glScalef(6,0.5,0);
    glTranslatef(-15,-12,0);
    Dew();
    glPopMatrix();
}

void Full_Dew(){
    adjust_dew();
}

void Animation_dew(){
    glPushMatrix();
    glTranslatef(Dew_position,0,0);
    Full_Dew();
    glPopMatrix();
}

void buildingwindow(float Sx, float Sy, float Tx, float Ty){
    glPushMatrix();
    glScalef(Sx, Sy,1);
    glTranslatef(Tx,Ty,0);
    glBegin(GL_QUADS);
    set_color("buildingglass");
    glVertex3f(-5.0f, 3.0f, 0.0f);
    glVertex3f(5.0f, 3.0f, 0.0f);
    glVertex3f(5.0f, 5.0f, 0.0f);
    glVertex3f(-5.0f, 5.0f, 0.0f);
    glEnd();
    glPopMatrix();

}

void stars(){
    if (isDayScene==false){
    glBegin(GL_POINTS);
	set_color("nightstars");
	glVertex2f(35.0f, 20.0f);
	glEnd();
    }
}

void adjust_stars(){
    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(130,90,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(90,110,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(20,115,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(37,100,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(50,85,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(70,100,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(60,60,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(110,100,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(100,70,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(140,100,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(80,82,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(10,82,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(0,95,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(160,110,0);
    stars();
    glPopMatrix();

    // Left stars
    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-30,90,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-50,120,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-45,70,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-55,95,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-90,80,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-140,95,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-110,120,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-180,115,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-130,75,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-150,125,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-170,70,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-190,85,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-210,100,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-230,110,0);
    stars();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glTranslatef(-225,70,0);
    stars();
    glPopMatrix();
}

void buildingwindowtwo(float Sx, float Sy, float Tx, float Ty){
    glPushMatrix();
    glScalef(Sx, Sy,1);
    glTranslatef(Tx,Ty,0);
    glBegin(GL_QUADS);
    set_color("buildingglass");
    glVertex3f(1.0f, 2.0f, 0.0f);
    glVertex3f(2.0f, 2.0f, 0.0f);
    glVertex3f(2.0f, 4.0f, 0.0f);
    glVertex3f(1.0f, 4.0f, 0.0f);
    glEnd();
    glPopMatrix();
}

void twintowerwindow(float Sx, float Sy, float Tx, float Ty){
    glPushMatrix();
    glScalef(Sx, Sy,1);
    glTranslatef(Tx,Ty,0);
    glBegin(GL_QUADS);
    set_color("buildingglass");
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(3.0f, 1.0f, 0.0f);
    glVertex3f(3.0f, 2.0f, 0.0f);
    glVertex3f(1.0f, 2.0f, 0.0f);
    glEnd();
    glPopMatrix();
}

void bridgeBrike(float Sx, float Sy, float Tx, float Ty){
    glPushMatrix();
    glScalef(Sx, Sy,1);
    glTranslatef(Tx,Ty,0);
    glBegin(GL_QUADS);
    set_color("brick");
    glVertex3f(1.0f, 0.50f, 0.0f);
    glVertex3f(2.0f, 0.50f, 0.0f);
    glVertex3f(2.0f, 0.75f, 0.0f);
    glVertex3f(1.0f, 0.75f, 0.0f);
    glEnd();
    glPopMatrix();
}

void bridgenut(float Sx, float Sy, float Tx, float Ty){
    glPushMatrix();
    glScalef(Sx, Sy,1);
    glTranslatef(Tx,Ty,0);
    glBegin(GL_QUADS);
    set_color("brick");
    glVertex3f(1.0f, 0.25f, 0.0f);
    glVertex3f(1.25f, 0.25f, 0.0f);
    glVertex3f(1.25f, 0.50f, 0.0f);
    glVertex3f(1.0f, 0.50f, 0.0f);
    glEnd();
    glPopMatrix();
}

void drawBuilding(){
    glBegin(GL_POLYGON);            // Buildings
	set_color("bulidingcolor"); // Yellow
	glVertex2f(40.0f, 3.0f);
	glVertex2f(40.0f, 11.0f);
	glVertex2f(36.0f, 11.0f);
	glVertex2f(36.0f, 3.0f);
	glEnd();

    buildingwindow(0.3,0.2,127,50);
    buildingwindow(0.3,0.2,127,45);
    buildingwindow(0.3,0.2,127,40);
    buildingwindow(0.3,0.2,127,35);
    buildingwindow(0.3,0.2,127,30);
    buildingwindow(0.3,0.2,127,25);
    buildingwindow(0.3,0.2,127,20);

	glBegin(GL_POLYGON);            // Buildings
	set_color("frontBuilding"); // Yellow
	glVertex2f(34.0f, 3.0f);
	glVertex2f(34.0f, 14.0f);
	glVertex2f(29.0f, 14.0f);
	glVertex2f(29.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,60,10);
    buildingwindowtwo(0.5,0.5,62,10);
    buildingwindowtwo(0.5,0.5,60,14);
    buildingwindowtwo(0.5,0.5,62,14);
    buildingwindowtwo(0.5,0.5,60,18);
    buildingwindowtwo(0.5,0.5,62,18);
	glBegin(GL_POLYGON);            // Buildings
	set_color("midBuilding"); // Yellow
	glVertex2f(36.0f, 3.0f);
	glVertex2f(36.0f, 8.0f);
	glVertex2f(32.0f, 8.0f);
	glVertex2f(32.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,114,35);
    buildingwindow(0.3,0.2,114,30);
    buildingwindow(0.3,0.2,114,25);
    buildingwindow(0.3,0.2,114,20);
    buildingwindow(0.3,0.2,114,15);
    // Render now
    //upore sob right side ar building
	glBegin(GL_POLYGON);            // Buildings
	set_color("bulidingcolor"); // Yellow
	glVertex2f(28.0f, 3.0f);
	glVertex2f(28.0f, 11.0f);
	glVertex2f(23.0f, 11.0f);
	glVertex2f(23.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,83,45);
    buildingwindow(0.3,0.2,83,40);
    buildingwindow(0.3,0.2,83,35);
    buildingwindow(0.3,0.2,83,30);
    buildingwindow(0.3,0.2,83,25);
    buildingwindow(0.3,0.2,83,20);
    buildingwindow(0.3,0.2,83,15);
	glBegin(GL_POLYGON);            // Buildings
	set_color("midBuilding"); // Yellow
	glVertex2f(30.0f, 3.0f);
	glVertex2f(30.0f, 9.0f);
	glVertex2f(26.0f, 9.0f);
	glVertex2f(26.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,93,35);
    buildingwindow(0.3,0.2,93,30);
    buildingwindow(0.3,0.2,93,25);
    buildingwindow(0.3,0.2,93,20);
    buildingwindow(0.3,0.2,93,15);
    //right 2nd
    glBegin(GL_POLYGON);            // Buildings
	set_color("bulidingcolor"); // Yellow
	glVertex2f(23.0f, 3.0f);
	glVertex2f(23.0f, 10.0f);
	glVertex2f(18.0f, 10.0f);
	glVertex2f(18.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,39,10);
    buildingwindowtwo(0.5,0.5,41,14);
    buildingwindowtwo(0.5,0.5,41,6);
	glBegin(GL_POLYGON);            // Buildings
	set_color("frontBuilding"); // Yellow
	glVertex2f(19.0f, 3.0f);
	glVertex2f(19.0f, 9.0f);
	glVertex2f(14.0f, 9.0f);
	glVertex2f(14.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,55,35);
    buildingwindow(0.3,0.2,55,30);
    buildingwindow(0.3,0.2,55,25);
    buildingwindow(0.3,0.2,55,20);
    buildingwindow(0.3,0.2,55,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("bulidingcolor"); // Yellow
	glVertex2f(14.0f, 3.0f);
	glVertex2f(14.0f, 12.0f);
	glVertex2f(9.0f, 12.0f);
	glVertex2f(9.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,39,45);
    buildingwindow(0.3,0.2,39,40);
    buildingwindow(0.3,0.2,39,35);
    buildingwindow(0.3,0.2,39,30);
    buildingwindow(0.3,0.2,39,25);
    buildingwindow(0.3,0.2,39,20);
    buildingwindow(0.3,0.2,39,15);
    glBegin(GL_POLYGON);            // Buildings
	set_color("frontBuilding"); // Yellow
	glVertex2f(10.0f, 3.0f);
	glVertex2f(10.0f, 11.0f);
	glVertex2f(5.0f, 11.0f);
	glVertex2f(5.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,15,10);
    buildingwindowtwo(0.5,0.5,15,14);
    buildingwindowtwo(0.5,0.5,15,6);
    buildingwindowtwo(0.5,0.5,13,10);
    buildingwindowtwo(0.5,0.5,13,14);
    buildingwindowtwo(0.5,0.5,13,6);
    buildingwindowtwo(0.5,0.5,11,10);
    buildingwindowtwo(0.5,0.5,11,14);
    buildingwindowtwo(0.5,0.5,11,6);

// NEW BUILDINGS

    glBegin(GL_POLYGON);            // Buildings
	set_color("bulidingcolor"); // Yellow
	glVertex2f(-40.0f, 3.0f);
	glVertex2f(-40.0f, 11.0f);
	glVertex2f(-36.0f, 11.0f);
	glVertex2f(-36.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,-127,50);
    buildingwindow(0.3,0.2,-127,45);
    buildingwindow(0.3,0.2,-127,40);
    buildingwindow(0.3,0.2,-127,35);
    buildingwindow(0.3,0.2,-127,30);
    buildingwindow(0.3,0.2,-127,25);
    buildingwindow(0.3,0.2,-127,20);

	glBegin(GL_POLYGON);            // Buildings
	set_color("frontBuilding"); // Yellow
	set_color("frontBuilding"); // Yellow
	glVertex2f(-34.0f, 3.0f);
	glVertex2f(-34.0f, 13.0f);
	glVertex2f(-29.0f, 13.0f);
	glVertex2f(-29.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,-65,10);
    buildingwindowtwo(0.5,0.5,-62,10);
    buildingwindowtwo(0.5,0.5,-65,14);
    buildingwindowtwo(0.5,0.5,-62,14);
    buildingwindowtwo(0.5,0.5,-65,18);
    buildingwindowtwo(0.5,0.5,-62,18);

//left bildig 1st
    glBegin(GL_POLYGON);            // Buildings
	set_color("bulidingcolor"); // Yellow
	glVertex2f(-36.0f, 3.0f);
	glVertex2f(-36.0f, 8.0f);
	glVertex2f(-32.0f, 8.0f);
	glVertex2f(-32.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,-114,35);
    buildingwindow(0.3,0.2,-114,30);
    buildingwindow(0.3,0.2,-114,25);
    buildingwindow(0.3,0.2,-114,20);
    buildingwindow(0.3,0.2,-114,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("bulidingcolor"); // Yellow
	glVertex2f(-28.0f, 3.0f);
	glVertex2f(-28.0f, 11.0f);
	glVertex2f(-23.0f, 11.0f);
	glVertex2f(-23.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,-83,45);
    buildingwindow(0.3,0.2,-83,40);
    buildingwindow(0.3,0.2,-83,35);
    buildingwindow(0.3,0.2,-83,30);
    buildingwindow(0.3,0.2,-83,25);
    buildingwindow(0.3,0.2,-83,20);
    buildingwindow(0.3,0.2,-83,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("bulidingcolor");// Yellow
	glVertex2f(-30.0f, 3.0f);
	glVertex2f(-30.0f, 9.0f);
	glVertex2f(-26.0f, 9.0f);
	glVertex2f(-26.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,-93,35);
    buildingwindow(0.3,0.2,-93,30);
    buildingwindow(0.3,0.2,-93,25);
    buildingwindow(0.3,0.2,-93,20);
    buildingwindow(0.3,0.2,-93,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("midBuilding"); // Yellow
	glVertex2f(-23.0f, 3.0f);
	glVertex2f(-23.0f, 10.0f);
	glVertex2f(-18.0f, 10.0f);
	glVertex2f(-18.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,-43,10);
    buildingwindowtwo(0.5,0.5,-41,14);
    buildingwindowtwo(0.5,0.5,-41,6);

	glBegin(GL_POLYGON);            // Buildings
	set_color("bulidingcolor"); // Yellow
	glVertex2f(-19.0f, 3.0f);
	glVertex2f(-19.0f, 9.0f);
	glVertex2f(-14.0f, 9.0f);
	glVertex2f(-14.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,-55,35);
    buildingwindow(0.3,0.2,-55,30);
    buildingwindow(0.3,0.2,-55,25);
    buildingwindow(0.3,0.2,-55,20);
    buildingwindow(0.3,0.2,-55,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("midBuilding");// Yellow
	glVertex2f(-14.0f, 3.0f);
	glVertex2f(-14.0f, 12.0f);
	glVertex2f(-9.0f, 12.0f);
	glVertex2f(-9.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,-25,10);
    buildingwindowtwo(0.5,0.5,-25,14);
    buildingwindowtwo(0.5,0.5,-25,6);
    buildingwindowtwo(0.5,0.5,-23,10);
    buildingwindowtwo(0.5,0.5,-23,14);
    buildingwindowtwo(0.5,0.5,-23,6);
    buildingwindowtwo(0.5,0.5,-21,10);
    buildingwindowtwo(0.5,0.5,-21,14);
    buildingwindowtwo(0.5,0.5,-21,6);
}

void drawBuildingL(){
     glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(40.0f, 3.0f);
	glVertex2f(40.0f, 11.0f);
	glVertex2f(36.0f, 11.0f);
	glVertex2f(36.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,127,50);
    buildingwindow(0.3,0.2,127,45);
    buildingwindow(0.3,0.2,127,40);
    buildingwindow(0.3,0.2,127,35);
    buildingwindow(0.3,0.2,127,30);
    buildingwindow(0.3,0.2,127,25);
    buildingwindow(0.3,0.2,127,20);

	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(34.0f, 3.0f);
	glVertex2f(34.0f, 14.0f);
	glVertex2f(29.0f, 14.0f);
	glVertex2f(29.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,60,10);
    buildingwindowtwo(0.5,0.5,62,10);
    buildingwindowtwo(0.5,0.5,60,14);
    buildingwindowtwo(0.5,0.5,62,14);
    buildingwindowtwo(0.5,0.5,60,18);
    buildingwindowtwo(0.5,0.5,62,18);
	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(36.0f, 3.0f);
	glVertex2f(36.0f, 8.0f);
	glVertex2f(32.0f, 8.0f);
	glVertex2f(32.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,114,35);
    buildingwindow(0.3,0.2,114,30);
    buildingwindow(0.3,0.2,114,25);
    buildingwindow(0.3,0.2,114,20);
    buildingwindow(0.3,0.2,114,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(28.0f, 3.0f);
	glVertex2f(28.0f, 11.0f);
	glVertex2f(23.0f, 11.0f);
	glVertex2f(23.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,83,45);
    buildingwindow(0.3,0.2,83,40);
    buildingwindow(0.3,0.2,83,35);
    buildingwindow(0.3,0.2,83,30);
    buildingwindow(0.3,0.2,83,25);
    buildingwindow(0.3,0.2,83,20);
    buildingwindow(0.3,0.2,83,15);
	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(30.0f, 3.0f);
	glVertex2f(30.0f, 9.0f);
	glVertex2f(26.0f, 9.0f);
	glVertex2f(26.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,93,35);
    buildingwindow(0.3,0.2,93,30);
    buildingwindow(0.3,0.2,93,25);
    buildingwindow(0.3,0.2,93,20);
    buildingwindow(0.3,0.2,93,15);
//right 2nd
    glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(23.0f, 3.0f);
	glVertex2f(23.0f, 10.0f);
	glVertex2f(18.0f, 10.0f);
	glVertex2f(18.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,39,10);
    buildingwindowtwo(0.5,0.5,41,14);
    buildingwindowtwo(0.5,0.5,41,6);
	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(19.0f, 3.0f);
	glVertex2f(19.0f, 9.0f);
	glVertex2f(14.0f, 9.0f);
	glVertex2f(14.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,55,35);
    buildingwindow(0.3,0.2,55,30);
    buildingwindow(0.3,0.2,55,25);
    buildingwindow(0.3,0.2,55,20);
    buildingwindow(0.3,0.2,55,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(14.0f, 3.0f);
	glVertex2f(14.0f, 12.0f);
	glVertex2f(9.0f, 12.0f);
	glVertex2f(9.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,39,45);
    buildingwindow(0.3,0.2,39,40);
    buildingwindow(0.3,0.2,39,35);
    buildingwindow(0.3,0.2,39,30);
    buildingwindow(0.3,0.2,39,25);
    buildingwindow(0.3,0.2,39,20);
    buildingwindow(0.3,0.2,39,15);
    glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(10.0f, 3.0f);
	glVertex2f(10.0f, 11.0f);
	glVertex2f(5.0f, 11.0f);
	glVertex2f(5.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,15,10);
    buildingwindowtwo(0.5,0.5,15,14);
    buildingwindowtwo(0.5,0.5,15,6);
    buildingwindowtwo(0.5,0.5,13,10);
    buildingwindowtwo(0.5,0.5,13,14);
    buildingwindowtwo(0.5,0.5,13,6);
    buildingwindowtwo(0.5,0.5,11,10);
    buildingwindowtwo(0.5,0.5,11,14);
    buildingwindowtwo(0.5,0.5,11,6);

// NEW BUILDINGS
    glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(-40.0f, 3.0f);
	glVertex2f(-40.0f, 11.0f);
	glVertex2f(-36.0f, 11.0f);
	glVertex2f(-36.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,-127,50);
    buildingwindow(0.3,0.2,-127,45);
    buildingwindow(0.3,0.2,-127,40);
    buildingwindow(0.3,0.2,-127,35);
    buildingwindow(0.3,0.2,-127,30);
    buildingwindow(0.3,0.2,-127,25);
    buildingwindow(0.3,0.2,-127,20);

	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(-34.0f, 3.0f);
	glVertex2f(-34.0f, 13.0f);
	glVertex2f(-29.0f, 13.0f);
	glVertex2f(-29.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,-65,10);
    buildingwindowtwo(0.5,0.5,-62,10);
    buildingwindowtwo(0.5,0.5,-65,14);
    buildingwindowtwo(0.5,0.5,-62,14);
    buildingwindowtwo(0.5,0.5,-65,18);
    buildingwindowtwo(0.5,0.5,-62,18);

//left bildig 1st
    glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(-36.0f, 3.0f);
	glVertex2f(-36.0f, 8.0f);
	glVertex2f(-32.0f, 8.0f);
	glVertex2f(-32.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,-114,35);
    buildingwindow(0.3,0.2,-114,30);
    buildingwindow(0.3,0.2,-114,25);
    buildingwindow(0.3,0.2,-114,20);
    buildingwindow(0.3,0.2,-114,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow");// Yellow
	glVertex2f(-28.0f, 3.0f);
	glVertex2f(-28.0f, 11.0f);
	glVertex2f(-23.0f, 11.0f);
	glVertex2f(-23.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,-83,45);
    buildingwindow(0.3,0.2,-83,40);
    buildingwindow(0.3,0.2,-83,35);
    buildingwindow(0.3,0.2,-83,30);
    buildingwindow(0.3,0.2,-83,25);
    buildingwindow(0.3,0.2,-83,20);
    buildingwindow(0.3,0.2,-83,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(-30.0f, 3.0f);
	glVertex2f(-30.0f, 9.0f);
	glVertex2f(-26.0f, 9.0f);
	glVertex2f(-26.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,-93,35);
    buildingwindow(0.3,0.2,-93,30);
    buildingwindow(0.3,0.2,-93,25);
    buildingwindow(0.3,0.2,-93,20);
    buildingwindow(0.3,0.2,-93,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(-23.0f, 3.0f);
	glVertex2f(-23.0f, 10.0f);
	glVertex2f(-18.0f, 10.0f);
	glVertex2f(-18.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,-43,10);
    buildingwindowtwo(0.5,0.5,-41,14);
    buildingwindowtwo(0.5,0.5,-41,6);

	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(-19.0f, 3.0f);
	glVertex2f(-19.0f, 9.0f);
	glVertex2f(-14.0f, 9.0f);
	glVertex2f(-14.0f, 3.0f);
	glEnd();
    buildingwindow(0.3,0.2,-55,35);
    buildingwindow(0.3,0.2,-55,30);
    buildingwindow(0.3,0.2,-55,25);
    buildingwindow(0.3,0.2,-55,20);
    buildingwindow(0.3,0.2,-55,15);

	glBegin(GL_POLYGON);            // Buildings
	set_color("buildingShadow"); // Yellow
	glVertex2f(-14.0f, 3.0f);
	glVertex2f(-14.0f, 12.0f);
	glVertex2f(-9.0f, 12.0f);
	glVertex2f(-9.0f, 3.0f);
	glEnd();
    buildingwindowtwo(0.5,0.5,-25,10);
    buildingwindowtwo(0.5,0.5,-25,14);
    buildingwindowtwo(0.5,0.5,-25,6);
    buildingwindowtwo(0.5,0.5,-23,10);
    buildingwindowtwo(0.5,0.5,-23,14);
    buildingwindowtwo(0.5,0.5,-23,6);
    buildingwindowtwo(0.5,0.5,-21,10);
    buildingwindowtwo(0.5,0.5,-21,14);
    buildingwindowtwo(0.5,0.5,-21,6);
}

void drawWater(){
	glBegin(GL_POLYGON);
	//set_color("waterCU")
	glColor3ub(18, 146, 173);//uporer color
	glVertex2f(-41.0f, -8.0f);
	glVertex2f(41.0f, -8.0f);
	glVertex2f(41.0f, 3.0f);
	glVertex2f(-41.0f, 3.0f);
	glEnd();

	glBegin(GL_POLYGON);
	//set_color("waterCD")
	glColor3ub(89,207,230);//nicher color
	glVertex2f(-41.0f, -25.0f);
	glVertex2f(41.0f, -25.0f);
    glColor3ub(18,146,173);//uporer color
	glVertex2f(41.0f, 3.0f);
	glVertex2f(-41.0f, 3.0f);
	glEnd();
}

void drawWaterNight(){
    if (isDayScene == false){

    glBegin(GL_POLYGON);
    //set_color("waterCU")
    glColor3ub(89,207,230);//uporer color
    glVertex2f(-41.0f, -8.0f);
    glVertex2f(41.0f, -8.0f);
    glVertex2f(41.0f, 3.0f);
    glVertex2f(-41.0f, 3.0f);
    glEnd();

    glBegin(GL_POLYGON);
    //set_color("waterCD")
    glColor3ub(18, 146, 173);//nicher color
    glVertex2f(-41.0f, -25.0f);
    glVertex2f(41.0f, -25.0f);
    glColor3ub(18,146,173);//uporer color
    glVertex2f(41.0f, 3.0f);
    glVertex2f(-41.0f, 3.0f);
    glEnd();
    }
}

void skybackground(){
    glBegin(GL_POLYGON);
    set_color("skyCU");
    glVertex2f(-41.0,0.0);
    glVertex2f(41.0,0.0);
    set_color("skyCD");
    glVertex2f(41.0,30);
    glVertex2f(-41.0,30.0);
    glEnd();
}

void BridgeBox(){
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,-5,0);
    glColor3ub (142, 44, 33);
    glBegin(GL_QUADS);
    glVertex2f(4,0);
    glVertex2f(6,0);
    glVertex2f(6,5);
    glVertex2f(4,5);
    glEnd();
    bridgeBrike(1,1,3,0);
    bridgeBrike(1,1,3,1.5);
    bridgeBrike(1,1,4,1);
    bridgeBrike(1,1,4,2);

    glBegin(GL_QUADS);
    glColor3ub (104,104,104);
    glVertex2f(4,0);
    glColor3ub(47,171,196);
    glVertex2f(7,-4);
    glColor3ub(47,171,196);
    glVertex2f(9,-4);
    glColor3ub (104,104,104);
    glVertex2f(6,0);
    glEnd();

    glColor3ub (66, 56, 54);
    glBegin(GL_QUADS);
    glVertex2f(3,5);
    glVertex2f(7,5);
    glVertex2f(7,6);
    glVertex2f(3,6);
    glEnd();
    glColor3ub (50, 40, 39);
    glBegin(GL_QUADS);
    glVertex2f(2,6);
    glVertex2f(8,6);
    glVertex2f(8,7);
    glVertex2f(2,7);
    glEnd();
	glPopMatrix();

}

void BridgeBoxNight(){
    if (isDayScene == false){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1,-5,0);
    glColor3ub (142, 44, 33);
    glBegin(GL_QUADS);
    glVertex2f(4,0);
    glVertex2f(6,0);
    glVertex2f(6,5);
    glVertex2f(4,5);
    glEnd();
    bridgeBrike(1,1,3,0);
    bridgeBrike(1,1,3,1.5);
    bridgeBrike(1,1,4,1);
    bridgeBrike(1,1,4,2);

    glBegin(GL_QUADS);
    glColor3ub (104,104,104);
    glVertex2f(4,0);
    glColor3ub(18,146,173);
    glVertex2f(7,-4);
    glColor3ub(18,146,173);
    glVertex2f(9,-4);
    glColor3ub (104,104,104);
    glVertex2f(6,0);
    glEnd();

    glColor3ub (66, 56, 54);
    glBegin(GL_QUADS);
    glVertex2f(3,5);
    glVertex2f(7,5);
    glVertex2f(7,6);
    glVertex2f(3,6);
    glEnd();
    glColor3ub (50, 40, 39);
    glBegin(GL_QUADS);
    glVertex2f(2,6);
    glVertex2f(8,6);
    glVertex2f(8,7);
    glVertex2f(2,7);
    glEnd();
    glPopMatrix();
    }
}

void temp(int x){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,0,0);
    BridgeBox();
    BridgeBoxNight();
    glPopMatrix();
}

void bridge(){
    temp(-40);
    temp(-20);
    temp(0);
    temp(20);
    temp(35);
}

void tempbuild(){
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1,1.5,0);
    drawBuildingL();
    glPopMatrix();
}

void twintower(){
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
	glTranslatef(-7,3,0);
	glBegin(GL_POLYGON);
	set_color("twintower"); // Yellow
	glVertex2f(-2.50, 0.0f);
	glVertex2f(2.50, 0.0f);
	glVertex2f(2.50f, 10.0f);
	glVertex2f(-2.50f, 10.0f);
	glEnd();
    twintowerwindow(0.5,0.5,-1,16);
    twintowerwindow(0.5,0.5,-4,16);
    twintowerwindow(0.5,0.5,1.75,16);
    twintowerwindow(0.5,0.5,-1,14);
    twintowerwindow(0.5,0.5,-4,14);
    twintowerwindow(0.5,0.5,1.75,14);
    twintowerwindow(0.5,0.5,-1,12);
    twintowerwindow(0.5,0.5,-4,12);
    twintowerwindow(0.5,0.5,1.75,12);
    twintowerwindow(0.5,0.5,-1,10);
    twintowerwindow(0.5,0.5,-4,10);
    twintowerwindow(0.5,0.5,1.75,10);
    twintowerwindow(0.5,0.5,1.75,8);
    twintowerwindow(0.5,0.5,-1,8);
    twintowerwindow(0.5,0.5,-4,8);
    twintowerwindow(0.5,0.5,1.75,6);
    twintowerwindow(0.5,0.5,-1,6);
    twintowerwindow(0.5,0.5,-4,6);
    twintowerwindow(0.5,0.5,1.75,4);
    twintowerwindow(0.5,0.5,-1,4);
    twintowerwindow(0.5,0.5,-4,4);
    twintowerwindow(0.5,0.5,1.75,2);
    twintowerwindow(0.5,0.5,-1,2);
    twintowerwindow(0.5,0.5,-4,2);
	glBegin(GL_POLYGON);
	set_color("twintower"); // Yellow
	glVertex2f(-2.00, 10.0f);
	glVertex2f(2.00, 10.0f);
	glVertex2f(2.00f, 16.0f);
	glVertex2f(-2.00f, 16.0f);
	glEnd();
    twintowerwindow(0.5,0.5,-1.50,18);
    twintowerwindow(0.5,0.5,-4,18);
    twintowerwindow(0.5,0.5,1,18);
    twintowerwindow(0.5,0.5,-1.50,20);
    twintowerwindow(0.5,0.5,-4,20);
    twintowerwindow(0.5,0.5,1,20);
    twintowerwindow(0.5,0.5,-1.50,22);
    twintowerwindow(0.5,0.5,-4,22);
    twintowerwindow(0.5,0.5,1,22);
    twintowerwindow(0.5,0.5,-1.50,24);
    twintowerwindow(0.5,0.5,-4,24);
    twintowerwindow(0.5,0.5,1,24);
    twintowerwindow(0.5,0.5,-1.50,26);
    twintowerwindow(0.5,0.5,-4,26);
    twintowerwindow(0.5,0.5,1,26);
    twintowerwindow(0.5,0.5,-1.50,28);
    twintowerwindow(0.5,0.5,-4,28);
    twintowerwindow(0.5,0.5,1,28);
    twintowerwindow(0.5,0.5,-1.50,30);
    twintowerwindow(0.5,0.5,-4,30);
    twintowerwindow(0.5,0.5,1,30);

	glBegin(GL_POLYGON);
    set_color("twintower"); // Yellow
	glVertex2f(-1.50, 16.0f);
	glVertex2f(1.50, 16.0f);
	glVertex2f(1.50f, 23.0f);
	glVertex2f(-1.50f, 23.0f);
	glEnd();
    twintowerwindow(0.5,0.5,-1.50,32);
    twintowerwindow(0.5,0.5,-4,32);
    twintowerwindow(0.5,0.5,-1.50,34);
    twintowerwindow(0.5,0.5,-4,34);
    twintowerwindow(0.5,0.5,-1.50,36);
    twintowerwindow(0.5,0.5,-4,36);
    twintowerwindow(0.5,0.5,-1.50,38);
    twintowerwindow(0.5,0.5,-4,38);
    twintowerwindow(0.5,0.5,-1.50,40);
    twintowerwindow(0.5,0.5,-4,40);
    twintowerwindow(0.5,0.5,-1.50,42);
    twintowerwindow(0.5,0.5,-4,42);
    twintowerwindow(0.5,0.5,-1.50,44);
    twintowerwindow(0.5,0.5,-4,44);
	glBegin(GL_POLYGON);
	set_color("twintower");// Yellow
	glVertex2f(-1.00, 23.0f);
	glVertex2f(1.00, 23.0f);
	glVertex2f(1.00f, 26.0f);
	glVertex2f(-1.00f, 26.0f);
	glEnd();
    twintowerwindow(0.5,0.5,-1.50,46);
    twintowerwindow(0.5,0.5,-1.50,48);
    twintowerwindow(0.5,0.5,-1.50,50);
	glBegin(GL_POLYGON);
	set_color("twintower"); // Yellow
	glVertex2f(2.50, 5.0f);
	glVertex2f(12.5f, 5.0f);
	glVertex2f(12.5f, 6.0f);
	glVertex2f(2.50, 6.0f);
	glEnd();
    buildingwindow(0.3,0.2,16,22);
    buildingwindow(0.3,0.2,16,23);
    glBegin(GL_POLYGON);
	set_color("twintower"); // Yellow
	glVertex2f(2.50, 6.0f);
	glVertex2f(12.5f, 6.0f);
	glVertex2f(12.5f, 8.0f);
	glVertex2f(2.50, 8.0f);
	glEnd();
    buildingwindow(0.3,0.2,16,35);
    buildingwindow(0.3,0.2,16,34);
	glPopMatrix();


	int x=10;
    int y=20;
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
	glTranslatef(-7,3,0);
	glBegin(GL_POLYGON);
	set_color("twintower"); // Yellow
	glVertex2f(-2.50+x, 0.0f);
	glVertex2f(2.50+x, 0.0f);
	glVertex2f(2.50f+x, 10.0f);
	glVertex2f(-2.50f+x, 10.0f);
	glEnd();
     twintowerwindow(0.5,0.5,-1.5+y,16);
    twintowerwindow(0.5,0.5,-5+y,16);
    twintowerwindow(0.5,0.5,1.3+y,16);
    twintowerwindow(0.5,0.5,-1.5+y,14);
    twintowerwindow(0.5,0.5,-5+y,14);
    twintowerwindow(0.5,0.5,1.3+y,14);
    twintowerwindow(0.5,0.5,-1.5+y,12);
    twintowerwindow(0.5,0.5,-5+y,12);
    twintowerwindow(0.5,0.5,1.3+y,12);
    twintowerwindow(0.5,0.5,-1.5+y,10);
    twintowerwindow(0.5,0.5,-5+y,10);
    twintowerwindow(0.5,0.5,1.3+y,10);
    twintowerwindow(0.5,0.5,1.3+y,8);
    twintowerwindow(0.5,0.5,-1.5+y,8);
    twintowerwindow(0.5,0.5,-5+y,8);
    twintowerwindow(0.5,0.5,1.3+y,6);
    twintowerwindow(0.5,0.5,-1.5+y,6);
    twintowerwindow(0.5,0.5,-5+y,6);
    twintowerwindow(0.5,0.5,1.3+y,4);
    twintowerwindow(0.5,0.5,-1.5+y,4);
    twintowerwindow(0.5,0.5,-5+y,4);
    twintowerwindow(0.5,0.5,1.3+y,2);
    twintowerwindow(0.5,0.5,-1.5+y,2);
    twintowerwindow(0.5,0.5,-5+y,2);
	glBegin(GL_POLYGON);
	set_color("twintower");// Yellow
	glVertex2f(-2.00+x, 10.0f);
	glVertex2f(2.00+x, 10.0f);
	glVertex2f(2.00f+x, 16.0f);
	glVertex2f(-2.00f+x, 16.0f);
	glEnd();
    twintowerwindow(0.5,0.5,-1.50+y,18);
    twintowerwindow(0.5,0.5,-4+y,18);
    twintowerwindow(0.5,0.5,1+y,18);
    twintowerwindow(0.5,0.5,-1.50+y,20);
    twintowerwindow(0.5,0.5,-4+y,20);
    twintowerwindow(0.5,0.5,1+y,20);
    twintowerwindow(0.5,0.5,-1.50+y,22);
    twintowerwindow(0.5,0.5,-4+y,22);
    twintowerwindow(0.5,0.5,1+y,22);
    twintowerwindow(0.5,0.5,-1.50+y,24);
    twintowerwindow(0.5,0.5,-4+y,24);
    twintowerwindow(0.5,0.5,1+y,24);
    twintowerwindow(0.5,0.5,-1.50+y,26);
    twintowerwindow(0.5,0.5,-4+y,26);
    twintowerwindow(0.5,0.5,1+y,26);
    twintowerwindow(0.5,0.5,-1.50+y,28);
    twintowerwindow(0.5,0.5,-4+y,28);
    twintowerwindow(0.5,0.5,1+y,28);
    twintowerwindow(0.5,0.5,-1.50+y,30);
    twintowerwindow(0.5,0.5,-4+y,30);
    twintowerwindow(0.5,0.5,1+y,30);
	glBegin(GL_POLYGON);
	set_color("twintower");// Yellow
	glVertex2f(-1.50+x, 16.0f);
	glVertex2f(1.50+x, 16.0f);
	glVertex2f(1.50f+x, 23.0f);
	glVertex2f(-1.50f+x, 23.0f);
	glEnd();
    twintowerwindow(0.5,0.5,-1.50+y,32);
    twintowerwindow(0.5,0.5,-4+y,32);
    twintowerwindow(0.5,0.5,-1.50+y,34);
    twintowerwindow(0.5,0.5,-4+y,34);
    twintowerwindow(0.5,0.5,-1.50+y,36);
    twintowerwindow(0.5,0.5,-4+y,36);
    twintowerwindow(0.5,0.5,-1.50+y,38);
    twintowerwindow(0.5,0.5,-4+y,38);
    twintowerwindow(0.5,0.5,-1.50+y,40);
    twintowerwindow(0.5,0.5,-4+y,40);
    twintowerwindow(0.5,0.5,-1.50+y,42);
    twintowerwindow(0.5,0.5,-4+y,42);
    twintowerwindow(0.5,0.5,-1.50+y,44);
    twintowerwindow(0.5,0.5,-4+y,44);
	glBegin(GL_POLYGON);
	set_color("twintower");// Yellow
	glVertex2f(-1.00+x, 23.0f);
	glVertex2f(1.00+x, 23.0f);
	glVertex2f(1.00f+x, 26.0f);
	glVertex2f(-1.00f+x, 26.0f);
	glEnd();
    twintowerwindow(0.5,0.5,-1.50+y,46);
    twintowerwindow(0.5,0.5,-1.50+y,48);
    twintowerwindow(0.5,0.5,-1.50+y,50);
	glPopMatrix();
}

void trainLine(){
	glBegin(GL_POLYGON);
	glColor3ub(82, 71, 67); // Yellow
	glVertex2f(-41.0f, 0.0f);
	glVertex2f(41.0f, 0.0f);
	glVertex2f(41.0f, -1.00f);
	glVertex2f(-41.0f, -1.0f);
	glEnd();
}

void tempTrainLine(){
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0,3,0);
    trainLine();
    glPopMatrix();
}

void BridgeRaling(){
    glBegin(GL_POLYGON);
	glColor3ub(2, 42, 50); // Yellow
	glVertex2f(-4.0f, 7.0f);
	glVertex2f(-7.0f, 7.0f);
	glVertex2f(-7.0f, 8.0f);
	glVertex2f(-4.0f, 8.0f);
	glEnd();
    glBegin(GL_POLYGON);
	glColor3ub(2, 42, 50); // Yellow
	glVertex2f(-5.0f, 0.0f);
	glVertex2f(-5.0f, 7.0f);
	glVertex2f(-6.0f, 7.0f);
	glVertex2f(-6.0f, 0.0f);
	glEnd();

    int x=4;
	glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(127, 18, 18);
    glVertex2f(-5.0f, 7.0f);
	glVertex2f(0.0f+x, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(127, 18, 18);
    glVertex2f(-5.0f, 5.0f);
	glVertex2f(-1.0f+x, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-5.0f, 4.0f);
	glVertex2f(-1.50f+x, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-5.0f, 2.0f);
	glVertex2f(-2.0f+x, 0.0f);
    glEnd();
    int y=-4;
	glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-6.0f, 7.0f);
	glVertex2f(-10.0f+y, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-6.0f, 5.0f);
	glVertex2f(-9.50f+y, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-6.0f, 4.0f);
	glVertex2f(-9.0f+y, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(20);
    glColor3ub(125, 14, 14);
    glVertex2f(-6.0f, 2.0f);
	glVertex2f(-8.0f+y, 0.0f);
    glEnd();
}

void tempRail(int x){
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,2,0);
    BridgeRaling();
    glPopMatrix();
}

void tempRailing(){
	tempRail(40);
	tempRail(20);
    tempRail(0);
	tempRail(-20);
	tempRail(-40);

}

void drawTrainrail(){
	glBegin(GL_POLYGON);
	glColor3ub(52, 52, 52 ); // Yellow
	glVertex2f(-41.0f, 2.0f);
	glVertex2f(41.0f, 2.0f);
	glVertex2f(41.0f, 4.50f);
	glVertex2f(-41.0f, 4.50f);
	glEnd();
}

void traindoor(){
    glBegin(GL_POLYGON);
	set_color("traindoor");
	glVertex2f(3.0f, 4.0f);
	glVertex2f(5.0f, 4.0f);
	glVertex2f(5.0f, 6.0f);
	glVertex2f(3.0f, 6.0f);
	glEnd();
}

void adjustdoor(){
    //middle door
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,1.4,1);
    glTranslatef(11.50,-2,0);
    traindoor();
    glPopMatrix();

    //front door
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,1.4,1);
    glTranslatef(25.50,-2,0);
    traindoor();
    glPopMatrix();

    //back door
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,1.4,1);
    glTranslatef(-3.50,-2,0);
    traindoor();
    glPopMatrix();
}

void windowstrain(){
	glBegin(GL_POLYGON);
	set_color("trainwindow");
	glVertex2f(3.0f, 4.0f);
	glVertex2f(5.0f, 4.0f);
	glVertex2f(5.0f, 6.0f);
	glVertex2f(3.0f, 6.0f);
	glEnd();
}

void adjustwindow(){
    //middle boggy
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(2,3,0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(5,3,0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(8,3,0);
    windowstrain();
    glPopMatrix();

    //front boggy
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(16.50,3,0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(19.50,3,0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(22.50,3,0);
    windowstrain();
    glPopMatrix();

    //back boggy
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(-7,3,0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(-10,3,0);
    windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(-13,3,0);
    windowstrain();
    glPopMatrix();
}

void reflect_windowstrain(){
    if (isDayScene==false){
	glBegin(GL_POLYGON);
	set_color("nightTwindow");
	glVertex2f(3.0f, 4.0f);
	glVertex2f(5.0f, 4.0f);
	glVertex2f(5.0f, 6.0f);
	glVertex2f(3.0f, 6.0f);
	glEnd();
    }
}

void reflectwindow_night(){
    if (isDayScene==false){
     //middle boggy
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(2,-15,0);
    reflect_windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(5,-15,0);
    reflect_windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(8,-15,0);
    reflect_windowstrain();
    glPopMatrix();

    //front boggy
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(16.50,-15,0);
    reflect_windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(19.50,-15,0);
    reflect_windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(22.50,-15,0);
    reflect_windowstrain();
    glPopMatrix();

    //back boggy
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(-7,-15,0);
    reflect_windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(-10,-15,0);
    reflect_windowstrain();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.6,0.6,1);
    glTranslatef(-13,-15,0);
    reflect_windowstrain();
    glPopMatrix();
    }
}

void drawTrain(){
    glBegin(GL_POLYGON);
	glColor3ub(227,223,209); // Yellow
	glVertex2f(2.0f, 0.75f+2);
	glVertex2f(10.50f, 0.75f+2);
	glVertex2f(11.0f, 4.0f+2);
	glVertex2f(10.50f, 4.50f+2);
	glVertex2f(2.50f, 4.50f+2);
	glVertex2f(2.0f, 4.0f+2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(191,171,151); // Yellow
	glVertex2f(2.0f-9, 0.75f+2);
	glVertex2f(11.0f-9, 0.75f+2);
	glVertex2f(11.0f-9, 4.0f+2);
	glVertex2f(10.50f-9, 4.50f+2);
	glVertex2f(2.50f-9, 4.50f+2);
	glVertex2f(2.0f-9, 4.0f+2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(214,214,222); // Yellow
	glVertex2f(10.50f, 0.75f+2);
	glVertex2f(22.50f, 0.75f+2);
	glVertex2f(21.0f, 3.50f+2);
	glVertex2f(19.0f, 4.50f+2);
	glVertex2f(11.50f, 4.50f+2);
	glVertex2f(11.0f, 4.0f+2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(199,129,104); // Yellow
	glVertex2f(-7.0f, 2.75f);
	glVertex2f(21.25f, 2.75f);
	glVertex2f(21.0f, 3.60f);
	glVertex2f(-7.0f, 3.60f);
	glEnd();

	//windows
	glBegin(GL_POLYGON);
	glColor3ub(46,68,86); // Yellow
	glVertex2f(19.0f, 4.0f);
	glVertex2f(20.25f, 4.0f);
	glVertex2f(20.25f, 5.0f);
	glVertex2f(20.0f, 5.50f);
	glVertex2f(19.0f, 6.0f);
	glEnd();

	adjustwindow();
	adjustdoor();
}

void railline2(){
    glBegin(GL_POLYGON);
	glColor3ub(142,141,140); // Yellow
	glVertex2f(-41.0f, 2.0f);
	glVertex2f(41.0f, 2.0f);
	glVertex2f(41.0f, 2.75f);
	glVertex2f(-41.0f, 2.75f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(142,141,140); // Yellow
	glVertex2f(-41.0f, 2.0f+2);
	glVertex2f(41.0f, 2.0f+2);
	glVertex2f(41.0f, 2.75f+2);
	glVertex2f(-41.0f, 2.75f+2);
	glEnd();
}

void bridgerail(){
	glBegin(GL_POLYGON);
	set_color("bridgerailc");
	glVertex2f(-6.0f, -5.0f);
	glVertex2f(-4.25f, -2.50f);
	glVertex2f(-5.0f, -2.0f);
	glVertex2f(-7.0f, -5.0f);
	glEnd();

	glBegin(GL_POLYGON);
	set_color("bridgerailc");
	glVertex2f(-4.25f, -2.50f);
	glVertex2f(0.0f, -1.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-5.0f, -2.0f);
	glEnd();

	glBegin(GL_POLYGON);
	set_color("bridgerailc");
	glVertex2f(0.0f, -1.0f);
	glVertex2f(4.25f, -2.50f);
	glVertex2f(5.0f, -2.0f);
	glVertex2f(0.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	set_color("bridgerailc");
	glVertex2f(4.25f, -2.50f);
	glVertex2f(6.0f, -5.0f);
	glVertex2f(7.0f, -5.0f);
	glVertex2f(5.0f, -2.0f);
	glEnd();
}

void adjustbridge(){
    //middle
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.499,0.8,1);
    glTranslatef(-2.7,0,0);
    bridgerail();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.499,0.8,1);
    glTranslatef(-16.0,0,0);
    bridgerail();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.499,0.8,1);
    glTranslatef(-29.3,0,0);
    bridgerail();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.499,0.8,1);
    glTranslatef(10.7,0,0);
    bridgerail();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.499,0.8,1);
    glTranslatef(23.9,0,0);
    bridgerail();
    glPopMatrix();
}

void container6(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(3,3,1);
    glTranslatef(4,-10.25,0);
    containerModel_1();
    glPopMatrix();
}

void ship(){
    container6();
	glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(-12.0,7.0);
    glVertex2f(-1.0,7.0);
    glVertex2f(1.50,3.25);
    glVertex2f(3.00,3.25);
    glVertex2f(3.0,-1.0);
    glVertex2f(-12.0,-1.0);
    glVertex2f(-12.0,7.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(3.0,3.25);
    glVertex2f(36.75,3.25);
    glVertex2f(36.75,-1.0);
    glVertex2f(3.0,-1.0);
    glVertex2f(3.0,3.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side");
    glVertex2f(36.75,3.25);
    glVertex2f(38.0,6.0);
    glVertex2f(44.0,6.0);
    glVertex2f(40.0,-1.00);
    glVertex2f(36.75,-1.00);
    glVertex2f(36.75,3.25);
    glEnd();

    // bottom border
    glBegin(GL_POLYGON);
    set_color("Ship_Border");
    glVertex2f(-12.0,-1.0);
    glVertex2f(40.0,-1.0);
    glVertex2f(39.0,-2.00);
    glVertex2f(-11.0,-2.0);
    glVertex2f(-12.0,-1.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(-12.0,6.0);
    glVertex2f(-2.50,6.0);
    glVertex2f(-2.50,5.50);
    glVertex2f(-12.0,5.50);
    glVertex2f(-12.0,6.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(-2.50,6.0);
    glVertex2f(-2.00,6.0);
    glVertex2f(0.50,2.50);
    glVertex2f(0.25,2.00);
    glVertex2f(-2.25,5.50);
    glVertex2f(-2.50,5.50);
    glVertex2f(-2.50,6.0);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(0.50,2.50);
    glVertex2f(3.00,2.50);
    glVertex2f(3.0,2.0);
    glVertex2f(0.25,2.00);
    glVertex2f(0.5,2.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(0.50,2.50);
    glVertex2f(37.50,2.50);
    glVertex2f(38.0,2.0);
    glVertex2f(0.25,2.00);
    glVertex2f(0.5,2.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(37.50,2.50);
    glVertex2f(38.75,5.50);
    glVertex2f(39.25,5.0);
    glVertex2f(38.0,2.00);
    glVertex2f(37.50,2.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_side1");//yellow
    glVertex2f(38.75,5.50);
    glVertex2f(43.75,5.50);
    glVertex2f(43.45,4.99);
    glVertex2f(39.25,5.00);
    glVertex2f(38.75,5.50);
    glEnd();

    glBegin(GL_POLYGON);//white
    set_color("Firefly");
    glVertex2f(-11.50,7.00);
    glVertex2f(-11.50,8.75);
    glVertex2f(-6.75,8.75);
    glVertex2f(-6.75,7.00);
    glVertex2f(-11.50,7.00);
    glEnd();
    glBegin(GL_POLYGON); //white
    set_color("chimney");
    glVertex2f(-11.00,8.75);
    glVertex2f(-9.25,16.25);
    glVertex2f(-6.75,16.25);
    glVertex2f(-6.75,8.75);
    glVertex2f(-11.00,8.75);
    glEnd();
    glBegin(GL_POLYGON);
   // glColor3ub(5, 156, 65); //green
    set_color("Firefly");
    glVertex2f(-9.50,15.25);
    glVertex2f(-6.75,15.25);
    glVertex2f(-6.75,15.00);
    glVertex2f(-9.55,15.00);
    glVertex2f(-9.50,15.25);
    glEnd();
    glBegin(GL_POLYGON);
   // glColor3ub(5, 156, 65); //green
    set_color("Firefly");
    glVertex2f(-9.96,13.25);
    glVertex2f(-6.75,13.25);
    glVertex2f(-6.75,13.00);
    glVertex2f(-10.00,13.00);
    glVertex2f(-9.96,13.25);
    glEnd();
    glBegin(GL_POLYGON);
   // glColor3ub(232, 239, 16); //yellow
    set_color("White");
    glVertex2f(-9.55,15.00);
    glVertex2f(-6.75,15.00);
    glVertex2f(-6.75,13.25);
    glVertex2f(-9.96,13.25);
    glVertex2f(-9.55,15.00);
    glEnd();

    glBegin(GL_POLYGON);//ash chimney duck 1
    glColor3ub(97, 106, 107);
    glVertex2f(-8.00,16.25);
    glVertex2f(-8.00,17.25);
    glVertex2f(-8.50,17.75);
    glVertex2f(-8.25,18.25);
    glVertex2f(-7.50,17.50);
    glVertex2f(-7.25,17.00);
    glVertex2f(-7.00,16.75);
    glVertex2f(-7.00,16.25);
    glVertex2f(-8.00,16.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body");// off-white
    glVertex2f(-6.00,7.00);
    glVertex2f(-6.00,13.00);
    glVertex2f(-1.00,13.00);
    glVertex2f(-1.00,7.00);
    glVertex2f(-6.00,7.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Off white"); // off-white
    glVertex2f(-1.00,11.75);
    glVertex2f(4.00,11.75);
    glVertex2f(4.00,3.25);
    glVertex2f(1.50,3.25);
    glVertex2f(-1.00,7.00);
    glVertex2f(-1.00,11.75);
    glEnd();

    // Minor details
    glBegin(GL_POLYGON);
    glColor3ub(229, 232, 232);
    glVertex2f(-1.00,13.00);
    glVertex2f(3.00,13.00);
    glVertex2f(3.00,11.75);
    glVertex2f(-1.00,11.75);
    glVertex2f(-1.00,13.00);
    glEnd();

    //T
    glBegin(GL_POLYGON);
    glColor3ub(178, 186, 187);
    glVertex2f(3.00,11.75);
    glVertex2f(3.00,13.00);
    glVertex2f(4.00,13.00);
    glVertex2f(4.00,11.75);
    glVertex2f(3.00,11.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(4.00,10.75);
    glVertex2f(4.00,13.00);
    glVertex2f(9.50,13.00);
    glVertex2f(9.50,10.75);
    glVertex2f(4.00,10.75);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(9.50,11.50);
    glVertex2f(9.50,13.00);
    glVertex2f(11.50,13.00);
    glVertex2f(11.50,11.50);
    glVertex2f(9.50,11.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(4.00,9.00);
    glVertex2f(4.00,10.75);
    glVertex2f(9.50,10.75);
    glVertex2f(9.50,9.00);
    glVertex2f(4.00,9.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_body2");
    glVertex2f(4.00,3.25);
    glVertex2f(4.00,9.00);
    glVertex2f(9.50,9.00);
    glVertex2f(9.50,3.25);
    glVertex2f(4.00,3.25);
    glEnd();

    // Railing
    glBegin(GL_POLYGON);
    set_color("Railing");
    glVertex2f(-5.75,13.00);
    glVertex2f(-5.75,14.50);
    glVertex2f(12.50,14.50);
    glVertex2f(11.50,13.00);
    glVertex2f(-5.75,13.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("chimney"); // chimney 2
    glVertex2f(-5.50,14.50);
    glVertex2f(-3.50,14.50);
    glVertex2f(-3.50,15.25);
    glVertex2f(-5.25,15.25);
    glVertex2f(-5.50,14.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("chimney");  // chimney 2
    glVertex2f(-5.22,15.50);
    glVertex2f(-5.00,16.25);
    glVertex2f(-3.50,16.25);
    glVertex2f(-3.50,15.50);
    glVertex2f(-5.22,15.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Firefly"); //yellow // chimney 2
    glVertex2f(-5.22,15.50);
    glVertex2f(-3.50,15.50);
    glVertex2f(-3.50,15.25);
    glVertex2f(-5.29,15.25);
    glVertex2f(-5.22,15.50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(81, 90, 90); // chimney duck 2
    glVertex2f(-4.50,16.25);
    glVertex2f(-4.50,17.00);
    glVertex2f(-5.00,17.50);
    glVertex2f(-4.75,18.00);
    glVertex2f(-4.00,17.25);
    glVertex2f(-3.75,16.75);
    glVertex2f(-3.75,16.25);
    glVertex2f(-4.50,16.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("Top_floor"); // building
    glVertex2f(-3.00,14.50);
    glVertex2f(-3.00,16.00);
    glVertex2f(10.85,15.99);
    glVertex2f(10.00,14.50);
    glVertex2f(-3.00,14.50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(93, 64, 55 );
    glVertex2f(-3.00,16.00);
    glVertex2f(-3.00,16.25);
    glVertex2f(11.00,16.25);
    glVertex2f(10.85,15.99);
    glVertex2f(-3.00,16.00);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(0, 150, 136 );//green-Cw-1
    set_color("ship_window");
    glVertex2f(-2.50,15.50);
    glVertex2f(-0.50,15.50);
    glVertex2f(-0.50,15.00);
    glVertex2f(-2.50,15.00);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(0, 150, 136 );//green-CW-2
    set_color("ship_window");
    glVertex2f(0.50,15.00);
    glVertex2f(0.50,15.50);
    glVertex2f(2.00,15.50);
    glVertex2f(2.00,15.00);
    glVertex2f(0.50,15.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-CW-3
    glVertex2f(4.00,15.25);
    glVertex2f(3.75,15.75);
    glVertex2f(4.75,15.75);
    glVertex2f(4.75,15.25);
    glVertex2f(4.00,15.25);
    glEnd();

    glBegin(GL_POLYGON);    //green-CW-4
    set_color("ship_window");
    glVertex2f(5.50,15.25);
    glVertex2f(5.50,15.75);
    glVertex2f(6.75,15.75);
    glVertex2f(6.75,15.25);
    glVertex2f(5.50,15.25);
    glEnd();
    glBegin(GL_POLYGON);

    set_color("ship_window");    //green-CW-5
    glVertex2f(7.50,15.25);
    glVertex2f(7.50,15.75);
    glVertex2f(9.00,15.75);
    glVertex2f(9.00,15.25);
    glVertex2f(7.50,15.25);
    glEnd();
    glBegin(GL_POLYGON);

    //green-CW-6'
    set_color("ship_window");
    glVertex2f(9.50,15.25);
    glVertex2f(9.50,15.75);
    glVertex2f(10.50,15.75);
    glVertex2f(10.00,15.25);
    glVertex2f(9.50,15.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189);//stand-W
    glVertex2f(3.50,16.25);
    glVertex2f(3.50,18.50);
    glVertex2f(4.50,18.50);
    glVertex2f(4.50,16.25);
    glVertex2f(3.50,16.25);
    glEnd();
    glBegin(GL_POLYGON);//Gray
    glColor3ub(158, 158, 158);
    glVertex2f(3.50,18.50);
    glVertex2f(3.50,18.75);
    glVertex2f(5.50,18.75);
    glVertex2f(5.50,18.50);
    glVertex2f(3.50,18.50);
    glEnd();

    glBegin(GL_POLYGON);//W
    glColor3ub(189, 189, 189);
    glVertex2f(3.75,18.75);
    glVertex2f(3.75,21.25);
    glVertex2f(4.50,21.25);
    glVertex2f(4.50,18.75);
    glVertex2f(3.75,18.75);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(158, 158, 158);//Gray
    glVertex2f(3.25,21.25);
    glVertex2f(3.25,21.75);
    glVertex2f(6.25,21.75);
    glVertex2f(6.25,21.25);
    glVertex2f(3.25,21.25);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 189, 189);//W
    glVertex2f(3.75,21.75);
    glVertex2f(3.75,26.00);
    glVertex2f(4.50,26.00);
    glVertex2f(4.50,21.75);
    glVertex2f(3.75,21.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(158, 158, 158);//Gray-CM TOP

    glVertex2f(3.75,26.00);
    glVertex2f(3.25,26.50);
    glVertex2f(5.00,26.50);
    glVertex2f(4.50,26.00);
    glVertex2f(3.75,26.00);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(158, 158, 158);//Gray-CM
    glVertex2f(3.75,26.50);
    glVertex2f(3.25,27.00);
    glVertex2f(5.00,27.00);
    glVertex2f(4.50,26.50);
    glVertex2f(3.75,26.50);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(247, 8, 8 );//Flag-Red
    set_color("Maroon");
    glVertex2f(3.75,24.50);
    glVertex2f(1.75,24.50);
    glVertex2f(1.75,25.50);
    glVertex2f(3.75,25.50);
    glVertex2f(3.75,24.50);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(0, 150, 136 );//green-W-1
    set_color("ship_window");
    glVertex2f(-5.50,11.75);
    glVertex2f(-5.00,11.75);
    glVertex2f(-5.00,12.25);
    glVertex2f(-5.50,12.25);
    glVertex2f(-5.50,11.75);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(0, 150, 136 );//green-W-2
    set_color("ship_window");
    glVertex2f(-2.75,11.75);
    glVertex2f(-2.25,11.75);
    glVertex2f(-2.25,12.25);
    glVertex2f(-2.75,12.25);
    glVertex2f(-2.75,11.75);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(0, 150, 136 );//green-W-3
    set_color("ship_window");
    glVertex2f(-4.75,9.50);
    glVertex2f(-4.25,9.50);
    glVertex2f(-4.25,10.00);
    glVertex2f(-4.75,10.00);
    glVertex2f(-4.75,9.50);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(0, 150, 136 );//green-W-4
    set_color("ship_window");
    glVertex2f(-1.75,9.50);
    glVertex2f(-1.25,9.50);
    glVertex2f(-1.25,10.00);
    glVertex2f(-1.75,10.00);
    glVertex2f(-1.75,9.50);
    glEnd();

    glBegin(GL_POLYGON);
  //  glColor3ub(0, 150, 136 );//green-W-5
    set_color("ship_window");
    glVertex2f(-5.50,7.25);
    glVertex2f(-5.00,7.25);
    glVertex2f(-5.00,7.75);
    glVertex2f(-5.50,7.75);
    glVertex2f(-5.50,7.25);
    glEnd();

    glBegin(GL_POLYGON);
  //  glColor3ub(0, 150, 136 );//green-W-6
     set_color("ship_window");
    glVertex2f(-3.50,7.25);
    glVertex2f(-3.00,7.25);
    glVertex2f(-3.00,7.75);
    glVertex2f(-3.50,7.75);
    glVertex2f(-3.50,7.25);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(0, 150, 136 );//green-W-7
    set_color("ship_window");
    glVertex2f(-1.75,7.25);
    glVertex2f(-1.25,7.25);
    glVertex2f(-1.25,7.75);
    glVertex2f(-1.75,7.75);
    glVertex2f(-1.75,7.25);
    glEnd();

    glBegin(GL_POLYGON);
   // glColor3ub(0, 150, 136 );//green-W-8
     set_color("ship_window");
    glVertex2f(0.50,9.50);
    glVertex2f(1.25,9.50);
    glVertex2f(1.25,10.00);
    glVertex2f(0.50,10.00);
    glVertex2f(0.50,9.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");
    glVertex2f(2.75,9.50);
    glVertex2f(3.25,9.50);
    glVertex2f(3.25,10.00);
    glVertex2f(2.75,10.00);
    glVertex2f(2.75,9.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-10
    glVertex2f(0.75,7.25);
    glVertex2f(1.25,7.25);
    glVertex2f(1.25,7.75);
    glVertex2f(0.75,7.75);
    glVertex2f(0.75,7.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-11
    glVertex2f(2.75,7.25);
    glVertex2f(3.25,7.25);
    glVertex2f(3.25,7.75);
    glVertex2f(2.75,7.75);
    glVertex2f(2.75,7.25);
    glEnd();
    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-12
    glVertex2f(4.25,12.00);
    glVertex2f(4.75,12.00);
    glVertex2f(4.75,12.50);
    glVertex2f(4.25,12.50);
    glVertex2f(4.25,12.00);
    glEnd();
    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-13
    glVertex2f(5.75,12.00);
    glVertex2f(7.25,12.00);
    glVertex2f(7.25,12.50);
    glVertex2f(5.75,12.50);
    glVertex2f(7.75,12.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-14
    glVertex2f(8.25,12.00);
    glVertex2f(8.75,12.00);
    glVertex2f(8.75,12.50);
    glVertex2f(8.25,12.50);
    glVertex2f(8.25,12.00);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-15
    glVertex2f(4.50,9.50);
    glVertex2f(5.50,9.50);
    glVertex2f(5.50,10.00);
    glVertex2f(4.50,10.00);
    glVertex2f(4.50,9.50);
    glEnd();

    glBegin(GL_POLYGON);
     set_color("ship_window");//green-W-16
    glVertex2f(6.75,9.50);
    glVertex2f(8.00,9.50);
    glVertex2f(8.00,10.00);
    glVertex2f(6.75,10.00);
    glVertex2f(6.75,9.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-17
    glVertex2f(8.50,9.50);
    glVertex2f(9.25,9.50);
    glVertex2f(9.25,10.00);
    glVertex2f(8.50,10.00);
    glVertex2f(8.50,9.50);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-18
    glVertex2f(5.25,7.25);
    glVertex2f(5.75,7.25);
    glVertex2f(5.75,7.75);
    glVertex2f(5.25,7.75);
    glVertex2f(5.25,7.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-19
    glVertex2f(6.50,7.25);
    glVertex2f(7.00,7.25);
    glVertex2f(7.00,7.75);
    glVertex2f(6.50,7.75);
    glVertex2f(6.50,7.25);
    glEnd();

    glBegin(GL_POLYGON);
    set_color("ship_window");//green-W-20
    glVertex2f(7.75,7.25);
    glVertex2f(8.25,7.25);
    glVertex2f(8.25,7.75);
    glVertex2f(7.75,7.75);
    glVertex2f(7.75,7.25);
    glEnd();

    // floor lines
    glBegin(GL_POLYGON);
    glColor3ub(208, 211, 212);
    glVertex2f(-6.00,10.75);
    glVertex2f(-6.00,11.00);
    glVertex2f(9.50,11.00);
    glVertex2f(9.50,10.75);
    glVertex2f(-6.00,10.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(208, 211, 212);
    glVertex2f(-6.00,8.75);
    glVertex2f(-6.00,9.00);
    glVertex2f(9.50,9.00);
    glVertex2f(9.50,8.75);
    glVertex2f(-6.00,8.75);
    glEnd();
}

void AdjustShip(){
    glPushMatrix();
    glScalef(0.70,0.90,1);
    glTranslatef(Ship_position,-20,0);
    ship();
    glPopMatrix();
}

void drawCircle(float radius, float cX, float cY){
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++){
            glColor3ub(194,214,246);
            float pi=3.1416;
            float A=(i*2*pi)/400;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
            glEnd();
}

void cloud(){
    drawCircle(4,20,25);
    drawCircle(4,15,25);
    drawCircle(4,11,25);
    drawCircle(4,-20,20);
    drawCircle(4,-15,20);
    drawCircle(4,-11,20);

    //
    drawCircle(4,70,30);
    drawCircle(4,65,30);
    drawCircle(4,61,30);
    drawCircle(4,90,22);
    drawCircle(4,85,22);
    drawCircle(4,81,22);

    //
    drawCircle(4,-60,25);
    drawCircle(4,-55,25);
    drawCircle(4,-51,25);
    drawCircle(4,-80,20);
    drawCircle(4,-75,20);
    drawCircle(4,-71,20);

    //
    drawCircle(4,-110,30);
    drawCircle(4,-105,30);
    drawCircle(4,-101,30);
    drawCircle(4,-130,27);
    drawCircle(4,-125,27);
    drawCircle(4,-121,27);
}

void adjust_cloud(){
    glPushMatrix();
    glScalef(0.50,0.60,1);
    glTranslatef(-40,12,0);
    cloud();
    glPopMatrix();
}

void Full_cloud(){
    adjust_cloud();
}

void Animation_cloud(){
    glPushMatrix();
    glTranslatef(cloud_position,0,0);
    Full_cloud();
    glPopMatrix();
}

void Full_train(){
    traindoor();
    adjustdoor();
    windowstrain();
    adjustwindow();
    reflectwindow_night();
    reflect_windowstrain();
    drawTrain();

}

void Animation_train(){
    glPushMatrix();
    glTranslatef(train_position,0,0);
    Full_train();
    glPopMatrix();
}

void update(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,update,0);

    if(cloud_position >= +80) cloud_position = -70;
    cloud_position += cloud_speed;

    if(Dew_position >= +80) Dew_position = -90;
    Dew_position += Dew_speed;

}

void shipAnimation2(int value) {

    if(ship_start2 == true){
        Ship_position += Ship_speed;
    if(Ship_position  > 74 ){
            Ship_position = 74;
            ship_start3 = true;
            currentDisplay = 3;
       }
    }else{
            Ship_position = Ship_position;
    }
    if(train_start2 == true && !trainMovedOnce){
     train_position += train_speed;
      if(train_position  > 50 ){
            train_position = -70;
            train_start2 = false;
            trainMovedOnce = true;
            showRestartMessage = true;
       }
    }else{
            train_position = train_position;
    }
    glutPostRedisplay();
    glutTimerFunc(20, shipAnimation2, 0);
}

void display2() {
    glClear(GL_COLOR_BUFFER_BIT);
    skybackground();
    drawWater();
    drawWaterNight();
    twintower();
    tempbuild();
    drawBuilding();
    adjust_stars();
    Animation_dew();
    adjustbridge();
    bridge();
    drawTrainrail();
    railline2();
    Animation_train();
    tempTrainLine();
    tempRailing();
    AdjustShip();
    Moon();
    Sun();
    Animation_cloud();
    if (showRestartMessage) {
    glColor3ub(255, 255, 255); // white text
    glRasterPos2f(-10.0f, -15.0f); // position in world coords
    const char* message = "Press Space Bar to Restart The Simulation";
    for (int i = 0; message[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
        }
}
    drawRain();
    glFlush();
    glutSwapBuffers();
}

//----------------------------------------------------------End of Scenario 2 ------------------------------------------------------------------

void playShipSound() {
    mciSendString("close ship", NULL, 0, NULL);
    mciSendString("open \"D:\\\\AIUB\\\\8th Semester\\\\Final Term\\\\COMPUTER GRAPHICS\\\\Project\\\\Interactive 2.5D Cargo Port Simulation\\\\music\\\\Ship.wav\" type waveaudio alias ship", NULL, 0, NULL);
    mciSendString("play ship", NULL, 0, NULL);
}
void playTruckSound() {
    mciSendString("close truck", NULL, 0, NULL);
    mciSendString("open \"D:\\\\AIUB\\\\8th Semester\\\\Final Term\\\\COMPUTER GRAPHICS\\\\Project\\\\Interactive 2.5D Cargo Port Simulation\\\\music\\\\Truck.wav\" type waveaudio alias truck", NULL, 0, NULL);
    mciSendString("play truck", NULL, 0, NULL);
}
void playTrainSound() {
    mciSendString("close train", NULL, 0, NULL);
    mciSendString("open \"D:\\\\AIUB\\\\8th Semester\\\\Final Term\\\\COMPUTER GRAPHICS\\\\Project\\\\Interactive 2.5D Cargo Port Simulation\\\\music\\\\Train.wav\" type waveaudio alias train", NULL, 0, NULL);
    mciSendString("play train", NULL, 0, NULL);
}
void playRainSound() {
    mciSendString("close rain", NULL, 0, NULL);
    mciSendString("open \"D:\\AIUB\\8th Semester\\Final Term\\COMPUTER GRAPHICS\\Project\\Interactive 2.5D Cargo Port Simulation\\music\\Rain.wav\" type waveaudio alias rain", NULL, 0, NULL);
    mciSendString("play rain", NULL, 0, NULL);
}
void stopRainSound() {
    mciSendString("stop rain", NULL, 0, NULL);
    mciSendString("close rain", NULL, 0, NULL);
}

void keyboard_raf(unsigned char key, int x, int y){
    switch (key) {
        case 'm':
        case 'M':
            isDayScene=true;
            break;
        case 'n':
        case 'N':
            isDayScene=false;
            break;
        case 'p':
        case 'P':
                if(moveY <= -2.5){
                    if(moveXh == movecX){
                        pick = true;
                    }
                }
        break;
        case 'b':
        case 'B':
            isRaining = !isRaining;
            if (isRaining) {
                playRainSound();
            } else {
                stopRainSound();
            }
            break;

        case 'r':
                    if(movecY <= 0.5){
                        pick = false;
                    }
        break;
        case 'w':
        case 'W':
                    ship_start = true;
                    playShipSound();
                    //PlaySound(TEXT("D:\\AIUB\\8th Semester\\Final Term\\COMPUTER GRAPHICS\\ProjectMain\\music\\Ship.wav"), NULL, SND_ASYNC | SND_FILENAME);
        break;

        case 'q':
        case 'Q':
                    ship_start = false;
                    PlaySound(NULL, 0, 0);
        break;
        case 't':
        case 'T':
                    truckStart = true;
                    playTruckSound();
                    //PlaySound(TEXT("D:\\AIUB\\8th Semester\\Final Term\\COMPUTER GRAPHICS\\ProjectMain\\music\\Truck.wav"), NULL, SND_ASYNC | SND_FILENAME);
        break;

        case 'y':
        case 'Y':
                    truckStart = false;
                    PlaySound(NULL, 0, 0);
        break;
        case 32: // SPACE key
            // Reset scene
            currentDisplay = 1;
            // Reset positions
            moveXh = 0.0f;
            moveY = 0.0f;
            movecY = 0.0f;
            movecX = 0.0f;
            moveShip = 0.0f;
            moveShip3 = -43.0f;
            truckX = 0.0f;
            stringY = 0.0f;
            cloudX = 0.0f;
            Ship_position = -70.0f;
            train_position = -70.0f;
            // Reset speeds (optional if they change mid-sim)
            shipSpeed = 0.02f;
            speed = 0.05f;
            // Reset state flags
            pick = false;
            release = false;
            ship_start = false;
            ship_start2 = false;
            ship_start3 = false;
            train_start2 = false;
            truckStart = false;
            trainSoundPlayed = false;
            showRestartMessage = false;
            isRaining = false;
            PlaySound(NULL, 0, 0);
            mciSendString("stop truck", NULL, 0, NULL);
            mciSendString("close truck", NULL, 0, NULL);
            mciSendString("stop ship", NULL, 0, NULL);
            mciSendString("close ship", NULL, 0, NULL);
            mciSendString("stop rain", NULL, 0, NULL);
            mciSendString("close rain", NULL, 0, NULL);
            mciSendString("stop train", NULL, 0, NULL);
            mciSendString("close train", NULL, 0, NULL);
            break;
        case 27:
            exit(0);
        break;
    }
    glutPostRedisplay();
}

void display() {
    if (currentDisplay == 1) {
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0,32,0,18);
        display1();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glutSwapBuffers();
    }
    else if (currentDisplay == 2) {
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-41,41,-25,30);
        display2();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glutSwapBuffers();

        if (!trainSoundPlayed) {
            playTrainSound();
            //PlaySound(TEXT("D:\\AIUB\\8th Semester\\Final Term\\COMPUTER GRAPHICS\\ProjectMain\\music\\Train.wav"), NULL, SND_ASYNC | SND_FILENAME);
            trainSoundPlayed = true;
        }
    }
}


void showInfoScreen() {
    SetConsoleOutputCP(CP_UTF8);
    // Credits
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("║                  All Rights Reserved by                     ║\n");
    printf("╠═════════════════════════════════════════════════════════════╣\n");
    printf("║ %-20s │ %-12s │ %-21s ║\n", "NAME", "ID", "CONTRIBUTION");
    printf("╠═════════════════════════════════════════════════════════════╣\n");
    printf("║ %-20s │ %-12s │ %-21s ║\n", "Ayesha Khatun", "22-49442-3", "Scenario 1");
    printf("║ %-20s │ %-12s │ %-21s ║\n", "Turjo Das Dip", "22-48558-3", "Scenario 1");
    printf("║ %-20s │ %-12s │ %-21s ║\n", "Shammi Akter Rimi", "22-49232-3", "Scenario 2");
    printf("║ %-20s │ %-12s │ %-21s ║\n", "Ahanaf Tanvir Shovon", "22-49221-3", "Scenario 2");
    printf("╚═════════════════════════════════════════════════════════════╝\n\n");
    // User Control Guide
    printf("╔═════════════════════════════════════════════════════════════╗\n");
    printf("║                    USER CONTROL GUIDE                       ║\n");
    printf("╠═════════════════════════════════════════════════════════════╣\n");
    printf("║ w : Start the ship in scenario 1                            ║\n");
    printf("║ q : Stop the ship in scenario 1                             ║\n");
    printf("║ t : Start the truck in scenario 1                           ║\n");
    printf("║ y : Stop the truck in scenario 1                            ║\n");
    printf("║ ↑ : Move up    (crane hook block)                           ║\n");
    printf("║ ↓ : Move down  (crane hook block)                           ║\n");
    printf("║ → : Move right (crane hook block)                           ║\n");
    printf("║ ← : Move left  (crane hook block)                           ║\n");
    printf("║ p : Pick container when hook is above it                    ║\n");
    printf("║ r : Release container at ground                             ║\n");
    printf("║ n : Switch to day scenario                                  ║\n");
    printf("║ m : Switch to night scenario                                ║\n");
    printf("║ b : Toggle rain effect                                      ║\n");
    printf("║ SpaceBar : Reset the simulation                             ║\n");
    printf("║ ESC : Exit the simulation                                   ║\n");
    printf("╚═════════════════════════════════════════════════════════════╝\n");
}

int main(int argc, char** argv) {
    showInfoScreen();
    glutInit(&argc, argv);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("Interactive 2.5D Cargo Port Simulation");
    glutFullScreen();
    CloudMovement(0);
    glutDisplayFunc(display);
    glutSpecialFunc(Cranekeyboard);
    glutTimerFunc(20, shipAnimation,0);
    glutTimerFunc(20, CloudMovement, 0);
    glutTimerFunc(20, truckMovement, 0);
    glutTimerFunc(20, shipAnimation2, 0);
    // Scenario 2
    glutTimerFunc(0,update,0);
    glutKeyboardFunc(keyboard_raf);
    srand(time(0));
        for (int i = 0; i < numDrops; ++i) {
            rainX[i] = (rand() % 82) - 41;  // X between -41 to 41
            rainY[i] = (rand() % 55) - 25;  // Y between -25 to 30
        }
    glutTimerFunc(10, rainUpdate, 0);  // Start rain update loop
    glutMainLoop();
    return 0;
}
