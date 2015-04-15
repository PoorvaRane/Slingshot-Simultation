#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <math.h>
#include<limits.h>
#include<unistd.h>
#include<time.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<vector>
#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define PI 3.14159265
#define degree (PI/180.0f)
GLdouble window_width,window_height;
GLdouble width=1200, height=800;
double angle=0.0,angle1=0.0;
double seg_len;
int wd,game_state=1;
float x1,x2,x3,x4;
float Y1,y2,y3,y4;
int win = 0,counter =0;
int cx1 = 435, cx2= 865, cx3= 650;
int flagc=0;
int X=70; int Y0=70; 		
int Y=0;
int V=100;
float Vx,Vy;
int t=789.0;
int t1=0;
int cy1;
int cy2;
int cy3;
float theta=45.0;
int right_arrow=0,left_arrow=0,up_arrow=0,down_arrow=0;
int flag = 0;
int numOfFills[1281][801];
int hit1 = 0, hit2 =0, hit3 =0;
int score = 0;
int flagb1 = 0, flagb2=0;
float dist;
int c = 0;

void Timer(int iUnused)
{
    glutTimerFunc(10,Timer,iUnused);
    glutPostRedisplay();

}

void setPixel(int x, int y)
{
    
    glVertex2i(x,y);
    numOfFills[x][y]++;
    glFlush();
    
}

float distance(int x1,int y1, int x2, int y2)
{
	int x = x1-x2;
	int y = y1-y2;
	float d = (float)pow(x,2) + (float)pow(y,2);
	float ans = sqrt(d);
	
	return ans;
}

int hitcheck=0;
int hf1=0,hf2=0,hf3=0;
void check()
{
	int i,j;
    if(hit1!=3)
    {
	for(i=400;i<=470;i++)
	for(j=window_height-t+50;j>=window_height-t;j--)
	{
		cy1 = window_height - t + 25;
		if(distance(cx1,cy1,X,Y) <= 51)
		{
		
 	    hitcheck=1;
		hf1=1;
		score+=2;

		}
		numOfFills[i][j]=0;
	}
    if(hf1==1) {	
		hit1+=1;
 		hf1=0;
}
    }
    if(hit2!=3)
    {
	for(i=615;i<=685;i++)
	for(j=window_height-t1+50;j>=window_height-t1;j--)
	{
 		cy3 = window_height - t1 + 25;
		if(distance(cx3,cy3,X,Y) <= 51)
		{
		hf2= 1;
		hitcheck=1;
		score+=6;
		
		}
		numOfFills[i][j]=0;
	}
    if(hf2==1)
		 {
			hit2+=1;
			hf2=0; 
 	 }
    }
    if(hit3!=3)
    {
	for(i=830;i<=900;i++)
	for(j=window_height-t+50;j>=window_height-t;j--)
	{
		cy2 = window_height - t + 25;
		if(distance(cx2,cy2,X,Y) <= 51)
		{
		hf3= 1;
		hitcheck=1;
		score+=10;
		}
		numOfFills[i][j]=0;
	}
    if(hf3==1)
    {
		hit3+=1; 
		hf3=0;
	   
 	}
    }
    glFlush();
}

void drawCircle1(int xc, int yc, int r)
{
  int x=0;
  int y=r;
  int h = 1-r; 
  glColor3f(0.0,0.0,0.0);
  glPushMatrix();
  glBegin(GL_POINTS);
  while(x<=y)
  {
	    setPixel(xc+x,yc+y);
		setPixel(xc+x,yc-y);
		setPixel(xc+y,yc+x);
		setPixel(xc+y,yc-x);
	    setPixel(xc-x,yc+y);
	    setPixel(xc-y,yc+x);
	    setPixel(xc-x,yc-y);
	    setPixel(xc-y,yc-x);

    	if(h<0)
    	{
    	  h = h+(2*x)+3;
    	}
    	else
    	{
    	  h = h+(2*x)-(2*y)+5;
    	  y = y-1;
    	}
    	x = x+1;
  }

  glEnd();
     glPopMatrix();
    glFlush();

}

void drawCircle(int xc, int yc, int r)
{
  int x=0;
  int y=r;
  int h = 1-r; 
  glColor3f(0.85,0.0,0.0);
  glPushMatrix();
  glBegin(GL_POLYGON);
  while(x<=y)
  {
	    setPixel(xc+x,yc+y);
		setPixel(xc+x,yc-y);
		setPixel(xc+y,yc+x);
		setPixel(xc+y,yc-x);
	    setPixel(xc-x,yc+y);
	    setPixel(xc-y,yc+x);
	    setPixel(xc-x,yc-y);
	    setPixel(xc-y,yc-x);

    	if(h<0)
    	{
    	  h = h+(2*x)+3;
    	}
    	else
    	{
    	  h = h+(2*x)-(2*y)+5;
    	  y = y-1;
    	}
    	x = x+1;
  }

    glEnd();
    glPopMatrix();
    glFlush();
}


void drawBasket(int t, int num, int colour)
{
        if(colour==1)
        glColor3f(1.0,1.0,1.0);
        else if(colour==2)
        glColor3f(0.0,0.85,0.0);
	else if(colour==3)
        glColor3f(0.0,0.0,1.0);	

        glLineWidth(8);
	int x1=400,x2=470,x3=830,x4=900,x5=615,x6=685;

    glPushMatrix();
    if(num==1)
    {
      	glBegin(GL_LINES);
	    setPixel(x1,window_height -t);
	    setPixel(x2,window_height - t);
	    setPixel(x2,window_height -t + 50);
	    setPixel(x1,window_height - t + 50);
	    setPixel(x2,window_height - t);
	    setPixel(x2,window_height -t + 50);
	    setPixel(x1,window_height - t);
	    setPixel(x1,window_height -t + 50);
	    glEnd();
    }

    if(num==2)
    {
	    glBegin(GL_LINES);
	    setPixel(x5,window_height -t1);
	    setPixel(x6,window_height - t1);
	    setPixel(x6,window_height -t1 + 50);
	    setPixel(x5,window_height - t1 +50);
	    setPixel(x6,window_height - t1);
	    setPixel(x6,window_height -t1 + 50);
	    setPixel(x5,window_height - t1);
	    setPixel(x5,window_height -t1 + 50);
	glEnd();
    }

    if(num==3)
    {
	    glBegin(GL_LINES);
	    setPixel(x3,window_height -t);
	    setPixel(x4,window_height - t);
	    setPixel(x4,window_height -t + 50);
	    setPixel(x3,window_height - t + 50);
	    setPixel(x4,window_height - t);
	    setPixel(x4,window_height -t + 50);
	    setPixel(x3,window_height - t);
	    setPixel(x3,window_height -t + 50);
	    glEnd();
    }
    glPopMatrix();
    glFlush();
}

void draw_string(std::string str)
{
    for(unsigned int i=0;i<str.length();i++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *(str.begin()+i));
    }
   
}

void draw_intro()
{
	glLineWidth(10);
	glColor3f(0.0,0.35,0.0);
	glBegin(GL_LINES);
	    setPixel(180,40);
	    setPixel(320,40);
	    setPixel(320,120);
	    setPixel(180,120);
	    setPixel(320,40);
	    setPixel(320,120);
	    setPixel(180,40);
	    setPixel(180,120);
	 glEnd();
}

void draw_start_menu()
{
	angle = (double)((int)angle % 360);
	angle = angle + 1.0;

    glPushMatrix();
    glTranslatef(width/2.0-250,height/2.0-160,0);
    glColor3f(0.0,0.8,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(500,0);
        glVertex2f(500,320);
        glVertex2f(0,320);
    glEnd();
    glLineWidth(3);
    glColor3f(0.3,0.7,0.5);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0,0);
        glVertex2f(500,0);
        glVertex2f(500,320);
        glVertex2f(0,320);
    glEnd();
    glLineWidth(3);
        glPushMatrix();
        glTranslatef(100,250,0);
        glScalef(0.4,0.4,0);
	
        glColor3f(255.0/255.0,0/255.0,0/255.0);

        draw_string("PROJECTILE");
		
        glPopMatrix();

        glPushMatrix();
        glTranslatef(125,180,0);
        
        glColor3f(1,0/255.0,255.0/255.0);
		if((int)angle % 30 == 0) counter +=1;
		if(counter%2==0)
	        glScalef(0.3,0.3,0);
		else 
			glScalef(0.15,0.15,0);
        draw_string("Press Space");
        glPopMatrix();
		draw_intro();

		glPushMatrix();
            glLineWidth(2);
			glTranslatef(220,80,0);
            glColor3f(91/255.0,161/255.0,247/255.0);
			glRotatef(-angle,0.0,0.0,1.0);
			drawCircle(15,25,8);
 		glPopMatrix();

		glPushMatrix();
            glLineWidth(2);
			glTranslatef(270,80,0);
            glColor3f(91/255.0,161/255.0,247/255.0);
			glRotatef(angle,0.0,0.0,1.0);
			drawCircle(15,25,8);
 		glPopMatrix();
		
        glPopMatrix();
		glPopMatrix();
		glFlush();
}



void draw_objects()
{
	X++;
	glColor3f(1.0,0.0,0.0);
    glPushMatrix();
	int i=X;
	Y= Y0+ (int)(i* tan(theta*degree) - 9.8*i*i/(V*V*cos(theta*degree)*cos(theta*degree)) );
    drawCircle(i,Y,8);
	glPopMatrix();
	glFlush();
}

void creators()
{
	printf("\nThank You for Playing!\n\nBy:\nPoorva Rane\nBalaji Bala\nDeepthi M Hegde\nNidhi Sridhar\nShruti Hegde\n\n");
	exit(0);
}

void keyboard(unsigned char key, int x, int y)
{



    switch(key)
    {
        case 's' : V-=1;
                   break;

        case 'w' : V+=1;
                   break;

        case 'd' : theta+=1;
                   break;

        case 'a' : theta-=1;
                   break;

	  	case ' ' : flag ++;
		           break;
		
		case 'q' : creators();
				   break;

    }

}


void init()
{
    window_width=1280.0;
    window_height=800.0;
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void reshape(int w,int h)
{
    window_width=(GLdouble)w;
    window_height=(GLdouble)h;
    glViewport(0,0,(GLsizei)window_width,(GLsizei)window_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,window_width,0.0,window_height);

}

void draw_obstacles()
{
    glPushMatrix();

    if(hit1==0) drawBasket(t,1,1);
    if(hit2==0) drawBasket(t,2,1);
    if(hit3==0) drawBasket(t,3,1);

	 if(hit1 == 1)
		{
			
			drawBasket(t,1,2);
			drawCircle(435,window_height - t + 16,8);
		}
	 if(hit2 == 1)
		{
			drawBasket(t,2,2);
			drawCircle(650,window_height - t1 +16,8);
		}
     if(hit3 == 1)
		{
			drawBasket(t,3,2);
			drawCircle(865,window_height - t +16,8);
		}
	if(hit1 == 2)
		{
			
			drawBasket(t,1,3);
			drawCircle(435,window_height - t + 16,8);
		}
	 if(hit2 == 2)
		{
			drawBasket(t,2,3);
			drawCircle(650,window_height - t1 +16,8);
		}
     if(hit3 == 2)
		{
			drawBasket(t,3,3);
			drawCircle(865,window_height - t +16,8);
		}
    glPopMatrix();
	
	int x1=10, x2=70, y1=10, y2=37, x3=34,x4=46,y3=37,y4=62;
	glPushMatrix();	
	
	glLineWidth(10);
	glColor3f(0.64,0.16,0.16);
	glBegin(GL_POLYGON);
	    setPixel(x1,y1);
	    setPixel(x2,y1);
	    setPixel(x2,y2);
	    setPixel(x1,y2);
	    setPixel(x2,y1);
	    setPixel(x2,y2);
	    setPixel(x1,y1);
	    setPixel(x1,y2);
	 glEnd();

	glLineWidth(10);
	glColor3f(0.64,0.16,0.16);
	glBegin(GL_POLYGON);
	    setPixel(x3,y3);
	    setPixel(x4,y3);
	    setPixel(x4,y4);
	    setPixel(x3,y4);
	    setPixel(x4,y3);
	    setPixel(x4,y4);
	    setPixel(x3,y3);
	    setPixel(x3,y4);
	 glEnd();
    drawCircle(12.5,5,5);
	drawCircle(32.5,5,5);
	drawCircle(22.5,5,5);
    drawCircle(42.5,5,5);
	drawCircle(52.5,5,5);
    drawCircle(62.5,5,5);
	glPopMatrix();
	
    glFlush();

}

void maindisp()
{
    glClearColor(0, 0, 0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(game_state == 1)
    {
        draw_start_menu();
    }

    glFlush();
    glutSwapBuffers();
}

void draw_score(int score)
{
    int tempsc = score;
    int stk[20],sp=0;

    while(tempsc>0)
    {
        stk[sp++] = (tempsc%10);
        tempsc /= 10;
    }
    sp--;
    while(sp>=0)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, stk[sp--]+'0');
    }
    if(score == 0) glutStrokeCharacter(GLUT_STROKE_ROMAN, '0');
}

void draw_score_table()
{
    angle1 = (double)((int)angle1 % 360);
	angle1 = angle1 + 1.0;
	
	glClearColor(0, 0, 0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(width/2.0-250,height/2.0-160,0);
    glColor3f(0.0,0.8,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(500,0);
        glVertex2f(500,320);
        glVertex2f(0,320);
    glEnd();
    glLineWidth(3);
    glColor3f(0.3,0.7,0.5);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0,0);
        glVertex2f(500,0);
        glVertex2f(500,320);
        glVertex2f(0,320);
    glEnd();
    glLineWidth(6);
        glPushMatrix();
        glTranslatef(100,250,0);
        glScalef(0.4,0.4,0);
        glColor3f(255.0/255.0,0/255.0,0/255.0);
		if(win==1)
        	draw_string("YOU WON :D");
		else if(win==0)
			draw_string("You Lost :/");
        glPopMatrix();

        glPushMatrix();
        glTranslatef(180,180,0);
        glScalef(0.25,0.25,0);
        glColor3f(1,179/255.0,85/255.0);
        draw_score(score);
        glPopMatrix();

        glPushMatrix();
            glLineWidth(2);
            glColor3f(91/255.0,161/255.0,247/255.0);

        glPopMatrix();
    
	draw_intro();

		glPushMatrix();
            glLineWidth(2);
			glTranslatef(220,80,0);
            glColor3f(91/255.0,161/255.0,247/255.0);
			glRotatef(-angle1,0.0,0.0,1.0);
			drawCircle(15,25,8);
 		glPopMatrix();

		glPushMatrix();
            glLineWidth(2);
			glTranslatef(270,80,0);
            glColor3f(91/255.0,161/255.0,247/255.0);
			glRotatef(angle1,0.0,0.0,1.0);
			drawCircle(15,25,8);
 		glPopMatrix();	


        glLineWidth(2);
            glLineWidth(2);

        glPopMatrix();

    glPopMatrix();
glFlush();
    glutSwapBuffers();
}


void display() 
{
    static int ballcount=1;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.5,0.0);

     if(game_state == 1 && flag==0)
    {
        maindisp();
    }

	if(game_state == 2 && flag>0)
    {
        draw_score_table();
    }

  else if(flag)
   {
    if(X>1280||X<0||Y>=800||Y<0) 
	{
		game_state = 2;		
	}
    glPushMatrix();
    if(flag>1) 
	{
	    if(hit1==3&&hit2==3&&hit3==3) 
		{
		win = 1;
		draw_score_table();
	}

		draw_objects();
        draw_obstacles();
		check();

		if(hitcheck==1)
        {
            
            X=70;
            Y0=70;
            ballcount++;
            hitcheck=0;
        }
		if(t==50)
	
			flagb1 = 1;
		}

		if(t1==730)
		{
			flagb2 = 1;
		}

		if(flagb2==0)
		{
			t1++;
		}

		if(flagb2==1)
		{
			t1--;
		}

		if(t1==0)
		{
			flagb2 = 0;
		}

		if(t==750)
		{
			flagb1 = 0;
		}

		if(flagb1==0)
		{
			t--;
		}

		if(flagb1==1)
		{
			t++;
		}

	}
	else
	{
		drawCircle(X,Y,8);
        draw_obstacles();
    }
    glFlush();
    glPopMatrix();

  
}

int main (int argc,char *argv[])
{
    init();
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize((int)window_width, (int)window_height);

    wd=glutCreateWindow("Projectile Game");

    glutReshapeFunc(reshape);

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);
    Timer(0);
    glutMainLoop();

    printf("\n");
    return 0;
}
