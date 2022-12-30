//firstly you have to choose between 1 and 2 in cmd window to choose your mood in program
//noor hossam gabre
//20102405
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<mmsystem.h>
#include<windows.h>
using namespace std;
GLfloat T = 0.2; //for The Explosion effect
GLfloat XMove = -2;//for moving car
GLfloat YMove = 2.8;//for moving mateor
//camera postions
GLfloat Cx  =-2;
GLfloat Cy  =2;
GLfloat Cz  =4;
// end of camera postions
int choose =0;// the first choose
float fly = 0;//fly rocket
//light constant
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
//The full animation of the code
void Distroy(){
    XMove = XMove+0.0008; //move car
    if(choose==2){
            //if choose  =2 move mateor and rocket
         YMove = YMove-0.0009;
                  fly = fly + 0.0001;
    //if meteor touch base
    if(XMove>0){
            //stop car
        XMove = XMove-0.0008;
                fly = fly + 0.001;

        YMove  =-1;
    //Explosion effect
        T = T+0.0005;
    }
    }
    else{
            //no Explosion effect in 1
        if(choose==1){
         YMove = YMove-0.001;
    if(XMove>0){
        XMove = XMove-0.001;

    }
    }
    }


    glutPostRedisplay();
}
void MyInit(){
    glClearColor(0,0.07,0.05,1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Perspective Projection
    glFrustum(-1 , 1 , -1 , 1 , 2 , 10);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1,0,0);
}
//build faces of cube
void Face(GLfloat A[] , GLfloat B[],GLfloat C[],GLfloat D[]){

 glBegin(GL_POLYGON);
        glVertex3fv(A);
        glVertex3fv(B);
        glVertex3fv(C);
        glVertex3fv(D);
    glEnd();
}
//build the whole cube as a house
void DrawHouse(GLfloat V0[],GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[],GLfloat V5[],GLfloat V6[],GLfloat V7[]){
    glColor3f(1,0,0);
    Face(V0 , V1 ,  V2 , V3);
    glColor3f(0,1,0);
    Face(V4 , V5 ,  V6 , V7);
    glColor3f(0,0,1);
    Face(V0 , V3 ,  V7 , V4);
    glColor3f(1,0,1);
    Face(V1 , V2 ,  V6 , V5);
     glColor3f(1,1,0);
    Face(V0 , V1 ,  V5 , V4);
     glColor3f(0,1,1);
    Face(V3 , V2 ,  V6 , V7);
}
//build some attachments of house like roof
void DrawHouseAttach(){
 glTranslatef(0.01,0.5,0);
    glPushMatrix();
    glColor3f(1,0.5,0);
    glRotatef(-90,1,0,0);
    glutSolidCone(0.7,0.6,16,8);
    glPopMatrix();
     glTranslatef(0.2,0.45,0);
    glPushMatrix();
    glScalef(1,3,1);
    glutSolidCube(.1);
    glPopMatrix();

}
//build the base of the env
void DrawBase(){
    glTranslatef(0,-1.93,0);
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.2f);
    glScalef(20,3,50);
    glutSolidCube(.3);
    glPopMatrix();
}
//build the rocket
void Rocket(){
    glTranslatef(-0.3,2+fly,-3);
    glPushMatrix();
    glColor3f(1,0.5,0);
    glRotatef(-90,1,0,0);
    glutSolidCone(0.2,0.6,16,8);//front
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.2,0);
    glColor3f(0.3,0.5,0.8);
    glutSolidSphere(.3 , 20 , 4);//middle
    glPopMatrix();
   glPushMatrix();
    glTranslatef(0,-0.4,0);
    glColor3f(0.3,0.5,0.8);
    glutSolidSphere(.3 , 20 , 4);//middle
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.6,0);
    glColor3f(0.3,0.5,0.8);
    glutSolidSphere(.3 , 20 , 4);//middle
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.8,0);
    glColor3f(0.3,0.5,0.8);
    glutSolidSphere(.3 , 20 , 4);//middle
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-1,0);
    glColor3f(0.3,0.5,0.8);
    glutSolidSphere(.3 , 20 , 4);//middle
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-1.2,0);
    glColor3f(0.3,0.5,0.8);
    glutSolidSphere(.3 , 20 , 4);//middle
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-1.4,0);
    glColor3f(0.3,0.5,0);
    glRotatef(-90,1,0,0);
    glutSolidCone(0.4,0.8,16,8);//end
    glPopMatrix();
}
//build car
void DrawCar(){
    //body of car
    glTranslatef(XMove,0.8,1.1);
    glPushMatrix();
    glColor3f(1,0.7,0.8);
    glScalef(2,.5,1);
    glutSolidCube(.5);
    glTranslatef(0,0.3,0);
    glColor3f(0.5,0.7,0.8);
    glScalef(1.1,.9,1);
    glutSolidCube(.4);
    glPopMatrix();
    glTranslatef(0,0,.25);
    glPushMatrix();
    glTranslatef(-.4,-.2,0);
    glutSolidTorus(.05,.1,8,8);       // wheel
    glTranslatef(.8,0,0);
    glutSolidTorus(.05,.1,8,8);       // wheel
    glPopMatrix();
    glTranslatef(0,0,-.5);
    glPushMatrix();
    glTranslatef(-.4,-.2,0);
    glutSolidTorus(.05,.1,8,8);       // wheel
    glTranslatef(.8,0,0);
    glutSolidTorus(.05,.1,8,8);       // wheel
    glPopMatrix();
}
//Drawmeteor
void Drawmeteor(){
    glPushMatrix();
    glColor3f(1,0.4,0);
    //if choose =2 meteor move in y axix
    if(choose ==2){
            glTranslatef(-1,YMove,-1.1);
    }
    else{
        //if choose =1 meteor move in x axix
        glTranslatef(YMove,2.8,-1.1);
    }
    glutSolidSphere(T , 100 , 100);
    glPopMatrix();
}
void thanks(){
    //just a word appear in the window if choose  = 1 with mapping Characters
     glColor3f(1.0,1.0,0.0);
 glRasterPos2f(1,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
 glColor3f(1.0,1.0,0.0);
 glRasterPos2f(1.5,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
  glColor3f(1.0,1.0,0.0);
 glRasterPos2f(2,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'s');
  glColor3f(1.0,1.0,0.0);
 glRasterPos2f(2.5,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'p');
  glColor3f(1.0,1.0,0.0);
 glRasterPos2f(3,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
  glColor3f(1.0,1.0,0.0);
 glRasterPos2f(3.5,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'c');
glRasterPos2f(4,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'t');
}
void See(){
        //just a word appear in the window if choose  = 2
     glColor3f(1.0,1.0,0.0);
 glRasterPos2f(1,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
 glColor3f(1.0,1.0,0.0);
 glRasterPos2f(1.5,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
  glColor3f(1.0,1.0,0.0);
 glRasterPos2f(2,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
  glColor3f(1.0,1.0,0.0);
 glRasterPos2f(2.5,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
  glColor3f(1.0,1.0,0.0);
 glRasterPos2f(3,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
  glColor3f(1.0,1.0,0.0);
 glRasterPos2f(3.5,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'n');
glRasterPos2f(4,2);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'d');
}
//DrawPyramid
void DrawPyramid(float  x  ,float y , float z){
    glTranslatef(x, y, z);
    glBegin(GL_TRIANGLES);
      // Front
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);

      // Back
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);

      // Left
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();
}

//main function of draw
void Draw(){
     glColor3f(0.0,1.0,0.0);
    //main matrix to build cube
    GLfloat V[8][3] = {
    {
        -0.5 , 0.5 , 0.5
    },
    {
        0.5 , 0.5 , 0.5
    },
    {
        0.5 , -0.5 , 0.5
    },
    {
        -0.5 , -0.5 , 0.5
    },
    {
        -0.5 , 0.5 , -0.5
    },
    {
        0.5 , 0.5 , -0.5
    },
    {
        0.5 , -0.5 , -0.5
    },
    {
        -0.5 , -0.5 , -0.5
    }
    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //camera look
    gluLookAt(Cx , Cy , Cz , 0 , 0 , 0 , 0 , 1 , 0);
    if(choose ==1){
        //appear respect in window if choose  = 1
        thanks();
    }
    else{
        //appear See end in window if choose  = 2
        See();
    }
    //build house1
    glPushMatrix();
    glTranslatef(-2,-1.1,-0.6);
    DrawHouse(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);
    DrawHouseAttach();
    glPopMatrix();
    //build house2
    glPushMatrix();
    glTranslatef(1,-1.1,-0.6);
    DrawHouse(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);
    DrawHouseAttach();
    glPopMatrix();
    //build house3
    glPushMatrix();
    glTranslatef(1,-1.1,2.5);
    DrawHouse(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);
    DrawHouseAttach();
    glPopMatrix();
    //build house4
    glPushMatrix();
    glTranslatef(-2,-1.1,2.5);
    DrawHouse(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);
    DrawHouseAttach();
    glPopMatrix();
    DrawBase();
    //build pyramids
    glPushMatrix();
    DrawPyramid(-1.5f, 1.5f, -6.0f);
    DrawPyramid(2.7, 0, 0);
    glPopMatrix();
    //appear the body of the rocket if choose  = 2
    if(choose ==2){
            glPushMatrix();
            Rocket();
            glPopMatrix();
    }
    //draw car
    DrawCar();
    //Draw meteor
    Drawmeteor();
    glutSwapBuffers();
}
void Key(unsigned char ch ,  int x , int y){
    //inputs of control camera
    switch(ch){
        case 'x' : Cx-=0.5;
        break;
        case 'X' : Cx+=0.5;
        break;
         case 'y' : Cy-=0.5;
        break;
        case 'Y' : Cy+=0.5;
        break;
         case 'z' : Cz-=0.5;
        break;
        case 'Z' : Cz+=0.5;
        break;
    }
    glutPostRedisplay();
}
static void reshape(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int C  ,  char *V[]){
    glutInitWindowPosition(0,0);
	glutInitWindowSize(1366,720);
    glutInit(&C,V);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutCreateWindow("Noor hossam ahmed bassiony gabre 20102405");
    // choose your mode between 1 and 2
    cout<<"Hello There \n you can find to scenarios \n 1-is to save the earth 2- is to destroy it : ";
    cin>>choose;
    MyInit();
    glutIdleFunc(Distroy);
    glutDisplayFunc(Draw);
    glutKeyboardFunc(Key);
    glutReshapeFunc(reshape);
        //playing respect sound if choose =1
    sndPlaySound("res.wav" , SND_ASYNC);
    if(choose ==2){
                //playing Explosion sound if choose =2
            sndPlaySound("effect.wav" , SND_ASYNC);
    }

    glutMainLoop();
    return 0;
}
