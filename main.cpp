#include <cstdio>
#include <stdio.h>
#include <conio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>



GLfloat car1 = 0.0f;
GLfloat car2 = 0.0f;
GLfloat bird = 0.0f;

GLfloat corona=0.0f;
GLfloat corona2=0.0f;
GLfloat corona3=0.0f;
GLfloat corona4=0.0f;
GLfloat corona5=0.0f;
GLfloat corona6=0.0f;


GLfloat trainBlocks = 0.0f;

GLfloat speed = 0.01f;
float _run3 = 0.0;
GLfloat cloud1 = .0f;
GLfloat cloud2 = .0f;
bool day = true;
GLfloat sunset = .0f;
float _ang_tri = 0.0;




//tunnel
void circle(GLfloat X,GLfloat Y,GLfloat R,GLubyte r,GLubyte g,GLubyte b)
{
    int i;

    GLfloat x=X;
    GLfloat y=Y;
    GLfloat radius =R;
    int triangleAmount = 50;


    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r,g,b);

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(

            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}
///////////////CIRCLE FOR TRAIN WHEEL/////////////////
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 100; //
    float PI=3.1416;


    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); //
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

////////////////CIRCLE FOR TRAIN WHEEL END///////////////
//////////////////////////////////
void drawCloud(GLfloat x, GLfloat y, GLfloat radius, int rr, int gg, int bb)
{
    int i;
    int triangleAmount = 1000;
    GLfloat twicePi = 2.0f * 3.14;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(rr,gg,bb);

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(

            x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

///////////////////////////////////



void update(int value)
{

    if(car1 > 1.4f)
    {
        car1 = 0.0f;
        glutPostRedisplay();


    }
    else
    {
        car1 += speed;
        glutPostRedisplay();
    }

////////////////////////////////
    if(cloud1 > 1.1f)
    {
        cloud1 = -1.7f;
        glutPostRedisplay();
    }
    else
    {
        cloud1 += .0050f;
        glutPostRedisplay();
    }
    if(cloud2 > 1.7f)
    {
        cloud2 = -0.50f;
        glutPostRedisplay();
    }
    else
    {
        cloud2 += .0030f;
        glutPostRedisplay();
    }

    if(sunset < -.342f)
    {
        sunset = +0.40f;
        //sunset = +0.0f;
        if(day == true)
        {
            day = false;
        }
        else
        {
            day = true;
        }
        glutPostRedisplay();
    }
    else
    {
        sunset -= .0010f;
        glutPostRedisplay();
        //cout << sunset << endl;
    }

//////////////////////////////////////TRAIN MOVEMENT//////////////////////////
    if (trainBlocks>2.0)
    {

        trainBlocks=-0.84f;
    }
    trainBlocks+=speed;
    glutPostRedisplay();
/////////////////////////////////////////TRAIN MOVEMENT END////////////////////
/////////////////////////CAR 2 MOVEMENT////////////////////////////////////
    if (car2<-1.2)
    {

        car2=1.635f;
    }
    car2-=speed;
    glutPostRedisplay();
/////////////////////////CAR 2 MOVEMENT END///////////////////////////////
//////////////////////////////BIRD MOVEMENT/////////////////////////////////
    if (bird>1.2)
    {

        bird=-1.2f;
    }
    bird+=speed;
    glutPostRedisplay();
/////////////////////////////BIRD MOVEMENT END//////////////////////////////

/////////////////////////CORONA VIRUS MOVEMENT/////////////////////////////
    if (corona>2.0)//CORONA
    {

        corona=-0.84f;
    }
    corona+=speed;
    glutPostRedisplay();

    if (corona2>2.0)//CORONA 2
    {

        corona2=-0.84f;
    }
    corona2+=speed+0.01;
    glutPostRedisplay();

    if (corona3>2.0)//CORONA 3
    {

        corona3=-0.84f;
    }
    corona3+=speed+0.013;
    glutPostRedisplay();

    if (corona4>2.0)//CORONA 4
    {

        corona4=-0.84f;
    }
    corona4+=speed+0.012;
    glutPostRedisplay();

    if (corona5>2.0)//CORONA 5
    {

        corona5=-0.84f;
    }
    corona5+=speed+0.018;
    glutPostRedisplay();

    if (corona6>2.0)//CORONA 6
    {

        corona6=-0.84f;
    }
    corona6+=speed+0.015;
    glutPostRedisplay();
//////////////////////////CORONA VIRUS MOVEMENT END////////////////////////
///////////////////////////////////////////////////////////////////////////

    glutTimerFunc(40, update, 0);
}


void init()
{
    glClearColor(1.0f, 1.f, 1.f,1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}


void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            //speed += 0.1f;
            printf("clicked at (%d, %d)\n", x, y);
        }
    }

    glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'a':
        speed = 0.0f;
        break;
    case 'w':
        speed += 0.1f;
        break;
    case 'c':
        //speed += 0.1f;
        if(day == true)
        {
            day = false;
        }
        else
        {
            day = true;
        }
        break;


        glutPostRedisplay();


    }
}




/////////////////////////////////////////////////
void weather()
{
    //dayyyyyyyyyyyyyyyyyyy
    //////////////////
    //////////////
    if(day == true)
    {
        glPushMatrix();
        //sky
        glBegin(GL_QUADS);
        glColor3ub(126,192,238);
        glVertex2f(-1.0, 0.6);
        glVertex2f(1, 0.6);
        glVertex2f(1, 1);
        glVertex2f(-1.0, 1);
        glEnd();
        //sun
        glTranslatef(0,sunset,0);
        circle(0.65,0.82,0.12,255,255,51);

        glPopMatrix();

//////////////////////////////////////////////////////////////////
        ////cloud1
        glPushMatrix();
        glTranslatef(cloud1,0,0);
        //cloud(-0.65,-0.82,0.12,255,1,1);
        //cloud1
        drawCloud(0.60,0.85,.050,246,246,246);
        drawCloud(0.60,0.83,.055,246,246,246);
        drawCloud(0.64,0.85,.055,246,246,246);
        drawCloud(0.56,0.80,.055,246,246,246);
        //glPopMatrix();
        glPopMatrix();
        ////cloud2
        glPushMatrix();
        glTranslatef(cloud2,0,0);
        //cloud(-0.65,-0.82,0.12,255,1,1);
        //cloud1
        drawCloud(-0.60,0.83,.050,246,246,246);
        drawCloud(-0.60,0.78,.055,246,246,246);
        drawCloud(-0.64,0.80,.055,246,246,246);
        drawCloud(-0.56,0.80,.055,246,246,246);

        //glPopMatrix();
        glPopMatrix();


///////////////////////////////////////////////////////////////////

    }
    else
    {
        //night////////////////////
        //////////////////////
        ////////////////
        glPushMatrix();
        //sky
        glBegin(GL_QUADS);
        glColor3ub(43, 47, 119);
        glVertex2f(-1.0, 0.6);
        glVertex2f(1, 0.6);
        glVertex2f(1, 1);
        glVertex2f(-1.0, 1);
        glEnd();
//#################STARS START HERE##########################################################
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.10, 0.90);
        glVertex2f(0.10, 0.91);
        glVertex2f(0.11, 0.91);
        glVertex2f(0.11, 0.90);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.20, 0.95);
        glVertex2f(0.20, 0.96);
        glVertex2f(0.21, 0.96);
        glVertex2f(0.21, 0.95);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.30, 0.80);
        glVertex2f(0.30, 0.81);
        glVertex2f(0.31, 0.81);
        glVertex2f(0.31, 0.80);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.40, 0.75);
        glVertex2f(0.40, 0.76);
        glVertex2f(0.41, 0.76);
        glVertex2f(0.41, 0.75);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.50, 0.85);
        glVertex2f(0.50, 0.86);
        glVertex2f(0.51, 0.86);
        glVertex2f(0.51, 0.85);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.60, 0.90);
        glVertex2f(0.60, 0.91);
        glVertex2f(0.61, 0.91);
        glVertex2f(0.61, 0.90);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.70, 0.80);
        glVertex2f(0.70, 0.81);
        glVertex2f(0.71, 0.81);
        glVertex2f(0.71, 0.80);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0.80, 0.65);
        glVertex2f(0.80, 0.66);
        glVertex2f(0.81, 0.66);
        glVertex2f(0.81, 0.65);
        glEnd();
//#########################STAR REVERSE#################################################
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.10, 0.90);
        glVertex2f(-0.10, 0.91);
        glVertex2f(-0.11, 0.91);
        glVertex2f(-0.11, 0.90);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.20, 0.95);
        glVertex2f(-0.20, 0.96);
        glVertex2f(-0.21, 0.96);
        glVertex2f(-0.21, 0.95);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.30, 0.80);
        glVertex2f(-0.30, 0.81);
        glVertex2f(-0.31, 0.81);
        glVertex2f(-0.31, 0.80);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.40, 0.75);
        glVertex2f(-0.40, 0.76);
        glVertex2f(-0.41, 0.76);
        glVertex2f(-0.41, 0.75);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.50, 0.85);
        glVertex2f(-0.50, 0.86);
        glVertex2f(-0.51, 0.86);
        glVertex2f(-0.51, 0.85);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.60, 0.90);
        glVertex2f(-0.60, 0.91);
        glVertex2f(-0.61, 0.91);
        glVertex2f(-0.61, 0.90);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.70, 0.80);
        glVertex2f(-0.70, 0.81);
        glVertex2f(-0.71, 0.81);
        glVertex2f(-0.71, 0.80);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(-0.80, 0.65);
        glVertex2f(-0.80, 0.66);
        glVertex2f(-0.81, 0.66);
        glVertex2f(-0.81, 0.65);
        glEnd();
//#################STARS END HERE##########################################################
        glTranslatef(0,sunset,0);

        circle(0.65,0.82,0.08,204, 204, 204);//moon
        glColor3ub(43, 47, 119);
        drawFilledCircle(0.67, 0.83, 0.065);// crescent moon

        glPopMatrix();



//////////////////////////////////////////////////////////////////
        ////cloud1
        glPushMatrix();
        glTranslatef(cloud1,0,0);
        //cloud(-0.65,-0.82,0.12,255,1,1);
        //cloud1
        drawCloud(0.60,0.85,.050, 127, 127, 127);
        drawCloud(0.60,0.83,.055, 127, 127, 127);
        drawCloud(0.64,0.85,.055, 127, 127, 127);
        drawCloud(0.56,0.80,.055, 127, 127, 127);
        //glPopMatrix();
        glPopMatrix();

        ////cloud2
        glPushMatrix();
        glTranslatef(cloud2,0,0);
        //cloud(-0.65,-0.82,0.12,255,1,1);
        //cloud1
        drawCloud(-0.60,0.83,.050, 127, 127, 127);
        drawCloud(-0.60,0.78,.055, 127, 127, 127);
        drawCloud(-0.64,0.80,.055, 127, 127, 127);
        drawCloud(-0.56,0.80,.055, 127, 127, 127);
        glPopMatrix();
        ///////////

    }
}
void nightLight()
{
    if(day == true)
    {

    }
    else
    {

////////////////car 1 light start///////////////////////////////

        glPushMatrix();
        glTranslatef(0.0f,car1,0.0f);//glTranslatef(0.0f,car1,0.0f);
        glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(-0.06, -0.7);
        glVertex2f(-0.10, -0.5);
        glVertex2f(0.0, -0.5);
        glVertex2f(-0.02, -0.7);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(0.06, -0.7);
        glVertex2f(0.10, -0.5);
        glVertex2f(0.0, -0.5);
        glVertex2f(0.02, -0.7);
        glEnd();
        glPopMatrix();

////////////////car 1 light end/////////////////////////////////
///////////////////car 2 light start//////////////////////////////////
        glPushMatrix();
        glTranslatef(car2,0.0f,0.0f);

        glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(0.10, -0.15);
        glVertex2f(0.10, -0.12);
        glVertex2f(-0.10, -0.08);
        glVertex2f(-0.10, -0.20);
        glEnd();
        glPopMatrix();
////////////////////car 2 light end//////////////////////////////////////

    }
}

void TrainHeadLight()
{
    if(day == true)
    {

    }
    else
    {
        /////////////////train light start///////////////////////////////////
        glPushMatrix();
        glTranslatef(trainBlocks,0.0f,0.0f);

        glBegin(GL_QUADS);
        glColor3ub(255,255,255);
        glVertex2f(-0.27, -0.85);
        glVertex2f(-0.25, -0.85);
        glVertex2f(0.10, -0.75);
        glVertex2f(0.10, -0.90);
        glEnd();
        glPopMatrix();
/////////////////train light end/////////////////////////////////////
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
//////////////////////////////
    weather();

//////////////////////////////

//tunnel
    circle(0.0,0.6,0.2,0,0,0);



//road
    glBegin(GL_QUADS);
    glColor3ub(40,43,42);
    glVertex2f( -1.0, -1.0);
    glVertex2f(  1.0, -1.0);
    glVertex2f(1.0, 0.6);
    glVertex2f(-1.0, 0.6);
    glEnd();

    nightLight();

    glBegin(GL_QUADS);//left bottom grass field
    glColor3ub(255,170,85);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f( -0.2, -1.0f);
    glVertex2f( -0.2,  -0.35);
    glVertex2f(-1.0,  -0.35);
    glEnd();


    glBegin(GL_QUADS);//building 1
    glColor3ub(135,135,135);
    glVertex2f(-0.8f, -0.65f);
    glVertex2f( -0.55, -0.65f);
    glVertex2f( -0.55,  -0.45);
    glVertex2f(-0.8,  -0.45);
    glEnd();

    glBegin(GL_QUADS);//building 1//window 1
    glColor3ub(255,255,255);
    glVertex2f(-0.75, -0.50f);
    glVertex2f( -0.71, -0.50f);
    glVertex2f( -0.71,  -0.55);
    glVertex2f(-0.75,  -0.55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,50,50);//building 1 door
    glVertex2f(-0.69, -0.65f);
    glVertex2f( -0.65, -0.65f);
    glVertex2f( -0.65,  -0.55);
    glVertex2f(-0.69,  -0.55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(50,50,50);//building 1 roof
    glVertex2f(-0.85, -0.45);
    glVertex2f( -0.50, -0.45);
    glVertex2f( -0.675,  -0.35);
    glEnd();


    glBegin(GL_QUADS);//right bottom grass field
    glColor3ub(170,170,0);
    glVertex2f( 1.0, -1.0);
    glVertex2f( 0.2, -1.0);
    glVertex2f( 0.2, -0.35);
    glVertex2f( 1.0, -0.35);
    glEnd();





    glBegin(GL_QUADS);////left upper
    glColor3ub(170,170,0);
    glVertex2f(-1.0, 0.6);
    glVertex2f( -0.2,0.6);
    glVertex2f(-0.2, 0.1);
    glVertex2f(-1.0, 0.1);
    glEnd();



    glBegin(GL_QUADS);//right upper grass field
    glColor3ub(255,170,85);
    glVertex2f(1.0, 0.6);
    glVertex2f( 0.2, 0.6);
    glVertex2f(0.2, 0.1);
    glVertex2f(1.0, 0.1);
    glEnd();


    //building 2
    glBegin(GL_QUADS);
    glColor3ub(170,85,0);
    glVertex2f(0.8f, 0.45);
    glVertex2f( 0.55, 0.45f);
    glVertex2f( 0.55,  0.25);
    glVertex2f(0.8,  0.25);
    glEnd();

    glBegin(GL_QUADS);//window 2
    glColor3ub(255,255,255);
    glVertex2f(0.75, 0.35f);
    glVertex2f(0.71, 0.35f);
    glVertex2f( 0.71,  0.40);
    glVertex2f(0.75,  0.40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85,0,0);
    glVertex2f(0.69, 0.25f);
    glVertex2f( 0.65, 0.25f);
    glVertex2f( 0.65,  0.35);
    glVertex2f(0.69,  0.35);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(85,0,0);
    glVertex2f(0.85, 0.45);
    glVertex2f( 0.50, 0.45);
    glVertex2f( 0.675,  0.55);
    glEnd();




//road light
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-0.24, 0.1);
    glVertex2f(-0.26, 0.1);
    glVertex2f(-0.26, 0.2);
    glVertex2f(-0.24, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-0.22, 0.2);
    glVertex2f(-0.28, 0.2);
    glVertex2f(-0.28, 0.4);
    glVertex2f(-0.22, 0.4);
    glEnd();

    circle(-.25,0.37,-0.021,204,0,0);
    circle(-.25,0.31,-0.021,204,102,0);
    circle(-.25,0.25,-0.021,0,204,0);


    //------------------------------
    //zebra cross bottom
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.15, -0.5);
    glVertex2f( -0.1, -0.5);
    glVertex2f(-0.1, -0.35);
    glVertex2f(-0.15, -0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.05, -0.5);
    glVertex2f( 0.00, -0.5);
    glVertex2f( 0.00, -0.35);
    glVertex2f(-0.05, -0.35);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f( 0.05, -0.5);
    glVertex2f( 0.10, -0.5);
    glVertex2f( 0.10, -0.35);
    glVertex2f( 0.05, -0.35);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f( 0.15, -0.5);
    glVertex2f( 0.20, -0.5);
    glVertex2f( 0.20, -0.35);
    glVertex2f( 0.15, -0.35);
    glEnd();




    //zebra cross top
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.15, 0.25);
    glVertex2f(0.1, 0.25);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.15, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.05, 0.25);
    glVertex2f( -0.00, 0.25);
    glVertex2f( -0.00, 0.1);
    glVertex2f(0.05, 0.1);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f( -0.05, 0.25);
    glVertex2f( -0.10, 0.25);
    glVertex2f( -0.10, 0.1);
    glVertex2f( -0.05, 0.1);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f( -0.15, 0.25);
    glVertex2f( -0.20, 0.25);
    glVertex2f( -0.20, 0.1);
    glVertex2f( -0.15, 0.1);
    glEnd();


    //zebra left
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.35, -0.30);
    glVertex2f(-0.20, -0.30);
    glVertex2f(-0.20, -0.25);
    glVertex2f(-0.35, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.35, -0.20);
    glVertex2f(-0.20, -0.20);
    glVertex2f(-0.20, -0.15);
    glVertex2f(-0.35, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.35, -0.10);
    glVertex2f(-0.20, -0.10);
    glVertex2f(-0.20, -0.05);
    glVertex2f(-0.35, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.35, -0.0);
    glVertex2f(-0.20, -0.0);
    glVertex2f(-0.20, 0.05);
    glVertex2f(-0.35, 0.05);
    glEnd();


//zebra right

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.35, -0.30);
    glVertex2f(0.20, -0.30);
    glVertex2f(0.20, -0.25);
    glVertex2f(0.35, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.35, -0.20);
    glVertex2f(0.20, -0.20);
    glVertex2f(0.20, -0.15);
    glVertex2f(0.35, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.35, -0.10);
    glVertex2f(0.20, -0.10);
    glVertex2f(0.20, -0.05);
    glVertex2f(0.35, -0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.35, -0.0);
    glVertex2f(0.20, -0.0);
    glVertex2f(0.20, 0.05);
    glVertex2f(0.35, 0.05);
    glEnd();





//##########################ROAD DIVIDER START##################################################
    glBegin(GL_QUADS); //ROAD DIVIDER BOTTOM
    glColor3ub(255,204,0);
    glVertex2f(-0.01f, -0.8f);
    glVertex2f(0.01f, -0.8f);
    glVertex2f(0.01f, -0.6f);
    glVertex2f(-0.01f, -0.6f);
    glEnd();

    glBegin(GL_QUADS);//ROAD DIVIDER top
    glColor3ub(255,204,0);
    glVertex2f(-0.01f, 0.5f);
    glVertex2f(0.01f, 0.5f);
    glVertex2f(0.01f, 0.3f);
    glVertex2f(-0.01f, 0.3f);
    glEnd();

    glBegin(GL_QUADS);//ROAD DIVIDER left 1#############################
    glColor3ub(255,204,0);
    glVertex2f(-0.95f,-0.14f);
    glVertex2f(-0.95f,-0.12f);
    glVertex2f(-0.75f,-0.12f);
    glVertex2f(-0.75f,-0.14f);
    glEnd();

    glBegin(GL_QUADS);//ROAD DIVIDER left 2#############################
    glColor3ub(255,204,0);
    glVertex2f(-0.60f,-0.14f);
    glVertex2f(-0.60f,-0.12f);
    glVertex2f(-0.40f,-0.12f);
    glVertex2f(-0.40f,-0.14f);
    glEnd();

//#################################################################################
    glBegin(GL_QUADS);//ROAD DIVIDER right 1#############################
    glColor3ub(255,204,0);
    glVertex2f(0.95f,-0.14f);
    glVertex2f(0.95f,-0.12f);
    glVertex2f(0.75f,-0.12f);
    glVertex2f(0.75f,-0.14f);
    glEnd();

    glBegin(GL_QUADS);//ROAD DIVIDER right 2#############################
    glColor3ub(255,204,0);
    glVertex2f(0.60f,-0.14f);
    glVertex2f(0.60f,-0.12f);
    glVertex2f(0.40f,-0.12f);
    glVertex2f(0.40f,-0.14f);
    glEnd();

    glPopMatrix();
//#############################ROAD DIVIDER END#######################################################



//car 1
    glPushMatrix();

    glTranslatef(0.0f,car1,0.0f);//glTranslatef(0.0f,car1,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(85,0,255);
    glVertex2f(-0.08, -1.0);
    glVertex2f(0.08, -1.0);
    glVertex2f(0.08, -0.7);
    glVertex2f(-0.08, -0.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.07, -0.98);
    glVertex2f(0.07, -0.98);
    glVertex2f(0.06, -0.95);
    glVertex2f(-0.06, -0.95);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.07, -0.80);
    glVertex2f(0.07, -0.80);
    glVertex2f(0.06, -0.87);
    glVertex2f(-0.06, -0.87);
    glEnd();

    glPopMatrix();


////############### X AND Y GRID FINDER #################################################################################################
 /*   glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);
    glEnd();

    glPopMatrix();
*/
////############### X AND Y GRID FINDER END ##################################################################################################

////////////////////////////////CAR 2 START//////////////////////////////////////
    glPushMatrix();
    glTranslatef(car2,0.0f,0.0f);//glTranslatef(car2,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);////CAR 2 BODY//////
    glVertex2f(0.10, -0.17);
    glVertex2f(0.10, -0.10);
    glVertex2f(0.37, -0.10);
    glVertex2f(0.37, -0.17);
    glEnd();

    glBegin(GL_QUADS);////CAR 2 TOP ROOF//////
    glVertex2f(0.14, -0.10);
    glVertex2f(0.20, -0.040);
    glVertex2f(0.27, -0.040);
    glVertex2f(0.33, -0.10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204,204,204);////CAR 2 WINDOW 1 //////
    glVertex2f(0.16, -0.10);
    glVertex2f(0.21, -0.046);
    glVertex2f(0.23, -0.046);
    glVertex2f(0.23, -0.10);

    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.24, -0.10);
    glVertex2f(0.24, -0.046);
    glVertex2f(0.26, -0.046);////CAR 2 WINDOW 2 //////
    glVertex2f(0.31, -0.10);
    glEnd();

    glColor3ub(0,0,0);
    drawFilledCircle(0.15, -0.17, 0.03);//car 2//wheel 1
    drawFilledCircle(0.31, -0.17, 0.03);//car 2//wheel 2

    glColor3ub(170,170,255);
    drawFilledCircle(0.15, -0.17, 0.02);//car 2//rim wheel 1
    drawFilledCircle(0.31, -0.17, 0.02);//car 2//rim wheel 2

    glPopMatrix();
////////////////////////////////CAR 2 END////////////////////////////////////////

//######################################TREES STARTS HERE################################################
    glPushMatrix();
    glColor3ub(85,255,0);
    drawFilledCircle(-0.45, -0.50, 0.07);//tree bot left
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(-0.45,-0.50);
    glVertex2f(-0.47,-0.63);
    glVertex2f(-0.43,-0.63);
    glEnd();

    glColor3ub(170,255,0);
    drawFilledCircle(-0.35, -0.50, 0.08);//tree bot left2
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(-0.35,-0.50);
    glVertex2f(-0.37,-0.65);
    glVertex2f(-0.33,-0.65);
    glEnd();
//################################################################
    glColor3ub(85,255,0);
    drawFilledCircle(0.35, -0.50, 0.08);//tree bot right
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(0.35,-0.50);
    glVertex2f(0.37,-0.65);
    glVertex2f(0.33,-0.65);
    glEnd();

    glColor3ub(170,255,0);
    drawFilledCircle(0.50, -0.60, 0.06);//tree bot right2
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(0.50,-0.60);
    glVertex2f(0.48,-0.75);
    glVertex2f(0.52,-0.75);
    glEnd();

    glColor3ub(170,255,0);
    drawFilledCircle(0.70, -0.50, 0.08);//tree bot right3
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(0.70,-0.50);
    glVertex2f(0.67,-0.65);
    glVertex2f(0.73,-0.65);
    glEnd();

    glColor3ub(85,255,0);
    drawFilledCircle(0.90, -0.60, 0.06);//tree bot right4
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(0.90,-0.60);
    glVertex2f(0.88,-0.75);
    glVertex2f(0.92,-0.75);
    glEnd();
//#################################################################
    glColor3ub(85,255,0);
    drawFilledCircle(0.45, 0.50, 0.07);//tree top right
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(0.45,0.50);
    glVertex2f(0.43,0.35);
    glVertex2f(0.47,0.35);
    glEnd();

    glColor3ub(170,255,0);
    drawFilledCircle(0.35, 0.50, 0.08);//tree top right2
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(0.35,0.50);
    glVertex2f(0.37,0.32);
    glVertex2f(0.33,0.32);
    glEnd();
//##########################################################
    glColor3ub(85,255,0);
    drawFilledCircle(-0.35, 0.50, 0.08);//tree top left
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(-0.35,0.50);
    glVertex2f(-0.37,0.35);
    glVertex2f(-0.33,0.35);
    glEnd();

    glColor3ub(170,255,0);
    drawFilledCircle(-0.50, 0.60, 0.06);//tree top left2
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(-0.50,0.60);
    glVertex2f(-0.48,0.45);
    glVertex2f(-0.52,0.45);
    glEnd();

    glColor3ub(170,255,0);
    drawFilledCircle(-0.70, 0.50, 0.08);//tree top left3
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(-0.70,0.50);
    glVertex2f(-0.67,0.35);
    glVertex2f(-0.73,0.35);
    glEnd();

    glColor3ub(85,255,0);
    drawFilledCircle(-0.90, 0.60, 0.06);//tree top left4
    glBegin(GL_TRIANGLES);
    glColor3ub(170,85,0);
    glVertex2f(-0.90,0.60);
    glVertex2f(-0.88,0.45);
    glVertex2f(-0.92,0.45);
    glEnd();

    glPopMatrix();
//#####################################TREES END HERE####################################################
//////////////////BIRD START/////////////////////////////////////////
    glPushMatrix();
    glTranslatef(bird,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(33,33,33);
    glVertex2f(0.10,0.88);
    glVertex2f(0.10,0.91);
    glVertex2f(0.15,0.91);
    glVertex2f(0.15,0.88);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.08,0.83);
    glVertex2f(0.08,0.87);
    glVertex2f(0.10,0.91 );
    glVertex2f(0.10,0.88 );
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.15,0.88);
    glVertex2f(0.15,0.91);
    glVertex2f(0.17,0.87);
    glVertex2f(0.17,0.85);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.17,0.85);
    glVertex2f(0.17,0.87);
    glVertex2f(0.18,0.91);
    glVertex2f(0.18,0.88);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.18,0.88);
    glVertex2f(0.18,0.91);
    glVertex2f(0.22,0.91);
    glVertex2f(0.22,0.88);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.22,0.88);
    glVertex2f(0.22,0.91);
    glVertex2f(0.236,0.88);
    glVertex2f(0.225,0.82);
    glEnd();



    glPopMatrix();
//////////////////BIRD END////////////////////////////////////////////
/////////////////////TRAIN LINE/////////###################################################################################
    glPushMatrix();

    glTranslatef(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(222,222,222);/////////////train line
    glVertex2f(-1, -0.95);
    glVertex2f(-1, -0.93);
    glVertex2f(1, -0.93);
    glVertex2f(1, -0.95);
    glEnd();

    glBegin(GL_LINES);////////TRAIN LINE STRIP////////
    glColor3ub(0,0,0);
    glVertex2f(-0.98,-0.93);
    glVertex2f(-0.98,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.90,-0.93);
    glVertex2f(-0.90,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.80,-0.93);
    glVertex2f(-0.80,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.70,-0.93);
    glVertex2f(-0.70,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.60,-0.93);
    glVertex2f(-0.60,-0.95);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-0.50,-0.93);
    glVertex2f(-0.50,-0.95);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-0.40,-0.93);
    glVertex2f(-0.40,-0.95);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-0.30,-0.93);
    glVertex2f(-0.30,-0.95);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-0.20,-0.93);
    glVertex2f(-0.20,-0.95);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-0.10,-0.93);
    glVertex2f(-0.10,-0.95);
    glEnd();
//////////////////////////////ZERO LINE////////////////////
    glBegin(GL_LINES);
    glVertex2f(0.0,-0.93);
    glVertex2f(0.0,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.10,-0.93);
    glVertex2f(0.10,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.20,-0.93);
    glVertex2f(0.20,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.30,-0.93);
    glVertex2f(0.30,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.40,-0.93);
    glVertex2f(0.40,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.50,-0.93);
    glVertex2f(0.50,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.60,-0.93);
    glVertex2f(0.60,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.70,-0.93);
    glVertex2f(0.70,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.80,-0.93);
    glVertex2f(0.80,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.90,-0.93);
    glVertex2f(0.90,-0.95);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.98,-0.93);
    glVertex2f(0.98,-0.95);
    glEnd();


    glPopMatrix();

/////////////////////TRAIN LINE END///#####################################################################################
/////////////////////TRAIN Block 1///#####################################################################################
    glPushMatrix();

    glTranslatef(trainBlocks,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(222,222,222);/////////////train block 1
    glVertex2f(-0.95, -0.90);
    glVertex2f(-0.95, -0.75);
    glVertex2f(-0.75, -0.75);
    glVertex2f(-0.75, -0.90);
    glEnd();

    glColor3ub(0,0,0);/////////////train block 1//window 1
    glBegin(GL_QUADS);
    glVertex2f(-0.92, -0.83);
    glVertex2f(-0.92, -0.77);
    glVertex2f(-0.87, -0.77);
    glVertex2f(-0.87, -0.83);
    glEnd();

    glColor3ub(0,0,0);/////////////train block 1//window 2
    glBegin(GL_QUADS);
    glVertex2f(-0.83, -0.83);
    glVertex2f(-0.83, -0.77);
    glVertex2f(-0.78, -0.77);
    glVertex2f(-0.78, -0.83);
    glEnd();


    drawFilledCircle(-0.92, -0.91, 0.02);//train block 1//wheel 1
    drawFilledCircle(-0.79, -0.91, 0.02);//train block 1//wheel 2



    // glPopMatrix();
/////////////////////TRAIN Block 1 END///#####################################################################################
/////////////////////TRAIN Block 2///#####################################################################################
    // glPushMatrix();

    // glTranslatef(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(222,222,222);/////////////train block 2
    glVertex2f(-0.73, -0.90);
    glVertex2f(-0.73, -0.75);
    glVertex2f(-0.53, -0.75);
    glVertex2f(-0.53, -0.90);
    glEnd();

    glColor3ub(0,0,0);/////////////train block 2//window 1
    glBegin(GL_QUADS);
    glVertex2f(-0.70, -0.83);
    glVertex2f(-0.70, -0.77);
    glVertex2f(-0.65, -0.77);
    glVertex2f(-0.65, -0.83);
    glEnd();

    glColor3ub(0,0,0);/////////////train block 2//window 2
    glBegin(GL_QUADS);
    glVertex2f(-0.62, -0.83);
    glVertex2f(-0.62, -0.77);
    glVertex2f(-0.57, -0.77);
    glVertex2f(-0.57, -0.83);
    glEnd();

    drawFilledCircle(-0.70, -0.91, 0.02);//train block 2//wheel 1
    drawFilledCircle(-0.57, -0.91, 0.02);//train block 2 //wheel 2


    //  glPopMatrix();
/////////////////////TRAIN Block 2 END///#####################################################################################
/////////////////////TRAIN Block Engine///#####################################################################################
    //  glPushMatrix();

    //  glTranslatef(0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(222,222,222);/////////////train engine
    glVertex2f(-0.51, -0.90);
    glVertex2f(-0.51, -0.75);
    glVertex2f(-0.35, -0.75);
    glVertex2f(-0.20, -0.90);
    glEnd();

    glColor3ub(0,0,0);/////////////train engine //window 1
    glBegin(GL_QUADS);
    glVertex2f(-0.49, -0.83);
    glVertex2f(-0.49, -0.77);
    glVertex2f(-0.44, -0.77);
    glVertex2f(-0.44, -0.83);
    glEnd();

    glColor3ub(0,0,0);/////////////train engine //window 2
    glBegin(GL_QUADS);
    glVertex2f(-0.42, -0.83);
    glVertex2f(-0.42, -0.77);
    glVertex2f(-0.33, -0.77);
    glVertex2f(-0.27, -0.83);
    glEnd();

    drawFilledCircle(-0.48, -0.91, 0.02);//engine block //wheel 1
    drawFilledCircle(-0.44, -0.91, 0.02);//engine block //wheel 2

    drawFilledCircle(-0.29, -0.91, 0.02);//engine block //wheel 3
    drawFilledCircle(-0.25, -0.91, 0.02);//engine block  //wheel 4

    glPopMatrix();
    TrainHeadLight();
/////////////////////TRAIN Block Engine END///#####################################################################################



//###################CORONA START###########################################################################
    glPushMatrix();
    glTranslatef(corona,0.0f,0.0f);

    glColor3ub(255,0,0);//triangle color TOP
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.05);
    glVertex2f(-0.02, 0.07);
    glVertex2f(0.02, 0.07);
    glEnd();

    glColor3ub(255,0,0);//triangle color BOT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, -0.05);
    glVertex2f(-0.02, -0.07);
    glVertex2f(0.02, -0.07);
    glEnd();

    glColor3ub(255,0,0);//triangle color LEFT
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.05, 0.0);
    glVertex2f(-0.07, -0.03);
    glVertex2f(-0.07, 0.03);
    glEnd();

    glColor3ub(255,0,0);//triangle color RIGHT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.05, 0.0);
    glVertex2f(0.07, -0.03);
    glVertex2f(0.07, 0.03);
    glEnd();

    glColor3ub(204,204,204);//circle color
    drawFilledCircle(0.0, 0.0, 0.05);
    glPopMatrix();

//##############################Covid19(2) ####################################
    glPushMatrix();
    glTranslatef(corona2,0.0f,0.0f);
    glColor3ub(255,0,0);//triangle color TOP
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.25);
    glVertex2f(-0.022, 0.27);
    glVertex2f(0.022, 0.27);
    glEnd();

    glColor3ub(255,0,0);//triangle color BOT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.15);
    glVertex2f(-0.022, 0.13);
    glVertex2f(0.022, 0.13);
    glEnd();

    glColor3ub(255,0,0);//triangle color LEFT
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.05, 0.20);
    glVertex2f(-0.07, 0.22);
    glVertex2f(-0.07, 0.18);
    glEnd();

    glColor3ub(255,0,0);//triangle color RIGHT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.05, 0.20);
    glVertex2f(0.07, 0.22);
    glVertex2f(0.07, 0.18);
    glEnd();

    glColor3ub(204,204,204);//circle color
    drawFilledCircle(0.0, 0.20, 0.05);
    glPopMatrix();
//##############################Covid19(3) ####################################
    glPushMatrix();
    glTranslatef(corona3,0.0f,0.0f);
    glColor3ub(255,0,0);//triangle color TOP
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.45);
    glVertex2f(-0.022, 0.47);
    glVertex2f(0.022, 0.47);
    glEnd();

    glColor3ub(255,0,0);//triangle color BOT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.35);
    glVertex2f(-0.022, 0.33);
    glVertex2f(0.022, 0.33);
    glEnd();

    glColor3ub(255,0,0);//triangle color LEFT
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.05, 0.40);
    glVertex2f(-0.07, 0.42);
    glVertex2f(-0.07, 0.38);
    glEnd();

    glColor3ub(255,0,0);//triangle color RIGHT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.05, 0.40);
    glVertex2f(0.07, 0.42);
    glVertex2f(0.07, 0.38);
    glEnd();

    glColor3ub(204,204,204);//circle color
    drawFilledCircle(0.0, 0.40, 0.05);
    glPopMatrix();
//##############################Covid19(4)- ####################################
    glPushMatrix();
    glTranslatef(corona4,0.0f,0.0f);
    glColor3ub(255,0,0);//triangle color TOP
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, -0.25);
    glVertex2f(-0.022, -0.27);
    glVertex2f(0.022, -0.27);
    glEnd();

    glColor3ub(255,0,0);//triangle color BOT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, -0.15);
    glVertex2f(-0.022, -0.13);
    glVertex2f(0.022, -0.13);
    glEnd();

    glColor3ub(255,0,0);//triangle color LEFT
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.05,- 0.20);
    glVertex2f(-0.07,- 0.22);
    glVertex2f(-0.07,- 0.18);
    glEnd();

    glColor3ub(255,0,0);//triangle color RIGHT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.05, -0.20);
    glVertex2f(0.07, -0.22);
    glVertex2f(0.07, -0.18);
    glEnd();

    glColor3ub(204,204,204);//circle color
    drawFilledCircle(0.0, -0.20, 0.05);
    glPopMatrix();
//##############################Covid19(5)- ####################################
    glPushMatrix();
    glTranslatef(corona5,0.0f,0.0f);
    glColor3ub(255,0,0);//triangle color TOP
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, -0.45);
    glVertex2f(-0.022, -0.47);
    glVertex2f(0.022, -0.47);
    glEnd();

    glColor3ub(255,0,0);//triangle color BOT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, -0.35);
    glVertex2f(-0.022, -0.33);
    glVertex2f(0.022, -0.33);
    glEnd();

    glColor3ub(255,0,0);//triangle color LEFT
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.05, -0.40);
    glVertex2f(-0.07, -0.42);
    glVertex2f(-0.07, -0.38);
    glEnd();

    glColor3ub(255,0,0);//triangle color RIGHT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.05, -0.40);
    glVertex2f(0.07, -0.42);
    glVertex2f(0.07, -0.38);
    glEnd();

    glColor3ub(204,204,204);//circle color
    drawFilledCircle(0.0, -0.40, 0.05);
    glPopMatrix();

//##############################Covid19(6)- ####################################
    glPushMatrix();
    glTranslatef(corona6,0.0f,0.0f);
    glColor3ub(255,0,0);//triangle color TOP
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, -0.65);
    glVertex2f(-0.022, -0.67);
    glVertex2f(0.022, -0.67);
    glEnd();

    glColor3ub(255,0,0);//triangle color BOT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, -0.55);
    glVertex2f(-0.022, -0.53);
    glVertex2f(0.022, -0.53);
    glEnd();

    glColor3ub(255,0,0);//triangle color LEFT
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.05, -0.60);
    glVertex2f(-0.07, -0.62);
    glVertex2f(-0.07, -0.58);
    glEnd();

    glColor3ub(255,0,0);//triangle color RIGHT
    glBegin(GL_TRIANGLES);
    glVertex2f(0.05, -0.60);
    glVertex2f(0.07, -0.62);
    glVertex2f(0.07, -0.58);
    glEnd();

    glColor3ub(204,204,204);//circle color
    drawFilledCircle(0.0, -0.60, 0.05);

    glPopMatrix();
//####################CORONA END####################################################################################


    glFlush();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(750, 650);
    glutInitWindowPosition(400, 60);
    glutCreateWindow("Corona View");
    glutDisplayFunc(display);
    init();
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    //sndPlaySound("Background.wav",SND_ASYNC|SND_LOOP);
    sndPlaySound("WelcomeSound.wav",SND_ASYNC);//WELCOME SOUND
    sndPlaySound("StreetSound.wav",SND_ASYNC);//STREET SOUND
    // PlaySound("WelcomeSound.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //PlaySound(TEXT("WelcomeSound.wav"),NULL, SND_SYNC);
    glutTimerFunc(1000, update, 0);


    glutMainLoop();
    return 0;
}
