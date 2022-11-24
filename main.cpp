#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<stdlib.h>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
void display();
void reshape(int w, int h);
void timer(int);
void keyboard(unsigned char key, int x, int y);
//float variable for moving first plane
float step=0;
//float variable for moving second plane
float step2=0;
float angle=0.0;
void init(){
glClearColor(1.0,1.0,1.0,1.0);
}
void keyboard(unsigned char key, int x, int y)
{
    //Move the First plane to black hole
    //click w first to move plane then if the first plane disappear click e
    switch(key){
    case 'w':step+=0.2;
    break;
    //Move the Second plane to black hole
    case 'e':step2+=0.2;
    break;
    //Full screen mood
    case 'f':glutFullScreen();
    break;
    //exit the whole program
    case 'q':exit(0);
    break;
    }
}
int main(int argc,char**argv){
//main function to render the whole program
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);
    glutCreateWindow("Noor hossam gabre 20102405/Nada salah 19200334");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();
}


void display(){
glClear(GL_COLOR_BUFFER_BIT);
int n =0;
int g =0;
int k =0;
glLoadIdentity();
//building the background
glBegin(GL_QUADS);
glColor3f(0.043,0.153,0.157);
glVertex3f(-10,10,0);
glVertex3f(10,10,0);
glVertex3f(10,-20,0);
glVertex3f(-10,-20,0);
glEnd();
//for loop for building the stars in the backgrounds
for(int i =0;i<200;i++){
//random values for give random locations for stars
    n= rand() % 19 + (-9);
    g= rand() % 19 + (-9);
    k =(rand() % 10) + 10;
    glBegin(GL_POLYGON);
    float theta;
    glColor3f(1.0,1.0,1.0);
    for(int i = 0;i<360;i++){
        theta =i*3.142/180;
        glVertex2f(g+cos(theta)/k,n+sin(theta)/k);
    }
     glEnd();
}
//end of for
//building mars planet
glBegin(GL_POLYGON);
glColor3f(0.757,0.345,0.125);
float theta;
 for(int i = 0;i<360;i++){
    theta =i*3.142/180;
    glVertex2f(-15+30*cos(theta),-15+15*sin(theta));
}
glEnd();
//second (small)  plane building
glBegin(GL_QUADS);
glColor3f(1,1,1);
glVertex2f(3.5+step2-25,5);
glVertex2f(4+step2-25, 5);
glVertex2f(4+step2-25, 5.5);
glVertex2f(3.5+step2-25, 5.5);
glEnd();
glBegin(GL_TRIANGLES);
glColor3f(1,1,1);
glVertex2f(4+step2-25, 5);
glVertex2f(4+step2-25, 5.5);
glVertex2f(4.3+step2-25,5.3);
glEnd();
glBegin(GL_QUADS);
glColor3f(1,0,0);
glVertex2f(3.5+step2-25,6);
glVertex2f(3.7+step2-25, 6);
glVertex2f(3.9+step2-25, 5.5);
glVertex2f(3.5+step2-25, 5.5);
glEnd();
glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f(4+step2-25, 5);
glVertex2f(4+step2-25, 5.5);
glEnd();
//end of (small)  plane building
//first black hole build
glBegin(GL_POLYGON);
glColor3f(0.663,0.706,0.58);
float theta3;
 for(int i = 0;i<360;i++){
    theta3 =i*3.142/180;
    glVertex2f(9+2*cos(theta3),5+3.4*sin(theta3));
}
glEnd();
glBegin(GL_POLYGON);
 glColor3f(0,0,0);
 for(int i = 0;i<360;i++){
        theta3 =i*3.142/180;
        glVertex2f(9+1.4*cos(theta3),5+2.8*sin(theta3));
}
 glEnd();
//end of first black hole build
// build first building
glBegin(GL_QUADS);
glColor3f(0.749,0.749,0.749);
glVertex2f(1.0, 5);
glVertex2f(-1.0, 5);
glVertex2f(-1.0, -4);
glVertex2f(1, -4);
glEnd();
glBegin(GL_TRIANGLES);
glColor3f(1.,0.478,0.478);
glVertex2f(1.0, 5);
glVertex2f(-1.0, 5);
glVertex2f(0, 7);
glEnd();
// end of build first building
// build second building
glBegin(GL_QUADS);
glColor3f(0.855,0.969,0.651);
glVertex2f(4, 5);
glVertex2f(2, 5);
glVertex2f(2, -5);
glVertex2f(4, -5);
glEnd();
glBegin(GL_TRIANGLES);
glColor3f(0.78,0.,0.224);
glVertex2f(4, 5);
glVertex2f(2, 5);
glVertex2f(3, 7);
glEnd();
//end of build second building
// build third building
glBegin(GL_QUADS);
glColor3f(0.706,0.,0.835);
glVertex2f(-4, 3);
glVertex2f(-2.5, 3);
glVertex2f(-2.5, -5);
glVertex2f(-4, -5);
glEnd();
glBegin(GL_TRIANGLES);
glColor3f(1.,0.608,0.);
glVertex2f(-4, 3);
glVertex2f(-2.5, 3);
glVertex2f(-3.3, 4.5);
glEnd();
// end of build third building
//  build first  plane
glColor3f(1,1,1);
glBegin(GL_QUADS);
glColor3f(1,1,1);
glVertex2f(3+step,5);
glVertex2f(5+step, 5);
glVertex2f(5+step, 6);
glVertex2f(3+step, 6);
glEnd();
glBegin(GL_TRIANGLES);
glColor3f(1,1,1);
glVertex2f(5+step, 5);
glVertex2f(5+step, 6);
glVertex2f(6+step, 5.5);
glEnd();
glBegin(GL_QUADS);
glColor3f(1,0,0);
glVertex2f(3+step,7);
glVertex2f(3.2+step, 7);
glVertex2f(3.8+step, 6);
glVertex2f(3+step, 6);
glEnd();

glBegin(GL_LINES);
glColor3f(0,0,0);
glVertex2f(5+step, 5);
glVertex2f(5+step, 6);
glEnd();
// end of  build first  plane
// build second black hole
glBegin(GL_POLYGON);
glColor3f(0.663,0.706,0.58);
for(int i = 0;i<360;i++){
    theta3 =i*3.142/180;
    glVertex2f(-9.8+cos(theta3)/2.4,5.5+sin(theta3)/1.2);
}
glEnd();
glBegin(GL_POLYGON);
glColor3f(0,0,0);
 for(int i = 0;i<360;i++){
    theta3 =i*3.142/180;
    glVertex2f(-9.8+cos(theta3)/3,5.5+sin(theta3)/1.8);
}
glEnd();
//end of  build second black hole
//build the rotate earth
glRotatef(angle,-7.5,8,0);
glBegin(GL_POLYGON);
glColor3f(0.,0.533,0.902);
float theta2;
for(int i = 0;i<360;i++){
    theta2 =i*3.142/180;
    glVertex2f(-7+cos(theta2)/1.5,8+sin(theta2));
}
glEnd();
//build continents of earth
glBegin(GL_QUADS);
glColor3f(0.,0.882,0.078);
glVertex2f(-7,8);
glVertex2f(-6.8, 8);
glVertex2f(-6.8, 7.7);
glVertex2f(-7, 7.7);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.,0.882,0.078);
glVertex2f(-7.5,8.5);
glVertex2f(-7.3, 8.5);
glVertex2f(-7.3, 8.3);
glVertex2f(-7.5, 8.3);
glEnd();
//end of build continents of earth
//end of build the rotate earth
glFlush();
}


void reshape(int w, int h){
glViewport(0,0,(GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glPushMatrix();
glLoadIdentity();
gluOrtho2D(-10,10,-10,10);
glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
//animation of stars and the planet rotation
glutPostRedisplay();
glutTimerFunc(10000/50,timer,0);
angle+=0.8*10;
if(angle>360){
    angle = angle-360.0;
}
}
