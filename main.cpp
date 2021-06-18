#include<bits/stdc++.h>
#define ll long long
#include<GL/gl.h>
#include<windows.h>
#include <GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include "BmpLoader.h"
using namespace std;
ll normal=1,zoom=0,e1=0,e2,e3,e4,e5,e6,e7,snow=0,sunny=1,zoomp=0,zoomm=0;
ll c1=1,temp0=0,temp1=0,temp2=0,temp4=0,score=0, inst=1,scoreinst=0,easy=0,easy2=0,easy3=0,medium=0,hard=0,arrowgame=0,gungame=0,temp3=8,t1=0,t2=0,t3=0,t4=0,t5=0,t6=0,tt1=0,tt2=0,tt3=0,tt4=0,tt5=0,tt6=0;
double windowHeight=1100, windowWidth=800;
GLfloat tartheta=0.0,theta =0.0,theta2 =0.0;
GLfloat angle = 0.0, axis_x=0.0, axis_y=0.0, minute= 0.0, hour=0.0,second=0.0;
GLboolean Rotate = false, uRotate=false, fan_rotate = true, cRotate= true,gunshot=false,trigger=false,ghura=true,arrowshot=false,schpt=false;
GLfloat eye_x = 0.0, eye_y = 21.0, eye_z = -68.0, look_x = -7.0, look_y = -9.0, look_z = -1.0, x1=70.0, x2=70.0, x3=70.0, x4=70.0, x5=70.0,x6=70.0,xx1=-110.0, xx2=-110.0, xx3=-110.0, xx4=-110.0, xx5=-110.0,xx6=-110.0;
GLfloat gz=-58,az=-48,triggercount=0.0,triggery=0.0,sx=-40,ux=0,cx=0;
GLfloat ina=az,xin=0.0,yin=0.0,gulix=.3,guliy=.3,guliz=.4,xxx=0,inz=gz;

const double PI = 3.14159265389;
int anglex= 0, angley = 0, anglez = 0;
int window;
int wired=0;
int animat = 0;
const int L=23;
const int dgre=3;
int ncpt=L+1;
int clikd=0;
const int nt = 40;
const int ntheta = 20;

double fan_speed = 0.0;
float spt_cutoff = 50;
bool light_1_on=true;
bool light_2_on=true;
bool light_3_on=true;
bool light_spot_on=false;
bool light_spot2_on=false;
bool light_1=false;
bool light_2=false;
bool light_3=false;
bool light_spot=true;
bool light_spot2=true;
bool diffuse_1_on=true;
bool specular_1_on=true;
bool ambient_1_on=true;
bool diffuse_2_on=true;
bool specular_2_on=true;
bool ambient_2_on=true;
bool diffuse_spot_on=true;
bool specular_spot_on=true;
bool ambient_spot_on=true;

enum textureid
{
    wall = 1,
    sidewall1 = 2,
    ceilbmp=3,
    field=4,
    target=5,ten=6,nine=7,eight=8,seven=9,six=10,five=11,uten=12,
    swall=13,
    sfield=14,
    sceilbmp=15
};
float deltaAngle = 0.0f;
float deltaAngle2 = 0.0f;
int xOrigin = -1;
int yOrigin = -1;
GLfloat ctrlpoints[L+1][3] =
{
    {9.3, 0.0, 0.0},
    {9.0, 0.0, 0.0},
    {8.9, 0.1, 0.0},
    {8.9, 0.1, 0.0},
    {8.8, 0.3, 0.0},
    {8.5, 0.5, 0.0},
    {8.0,4.5,0.0},
    {7.0,4.5,0.0},
    {5.0,1.0,0.0},
    {4.5,.5,0.0},
    {4.5,.5,0.0},
    {4.0,1.0,0.0},
    {2.0,4.5,0.0},
    {1.0,4.5,0.0},
    {0.5, 0.5, 0.0},
    {0.3, 0.3, 0.0},
    {0.1, 0.1, 0.0},
    {0.1, 0.1, 0.0},
    {0.1, 0.1, 0.0},
    {0.0, 0.0, 0.0},
    {-0.1, -0.1, 0.0},
    {-0.1, -0.2, 0.0},
    {-0.1, -0.2, 0.0},
    {-0.1, -0.3, 0.0}
};

GLfloat ctrlpoints2[L+1][3] =
{
    { 0.0, 0.0, 0.0},
    { 7.0, 3.0, 0.0},
    {0.0,4.0,0.0},
    {10.0,4.0,0.0},
    {7.0,0.0,0.0},
    {10.0,-4.0,0.0},
    {0.0,-4.0,0.0},
    { 7.0, -3.0, 0.0},
    { 5.0, -3.0, 0.0},
    {0.0, 0.0, 0.0}
};
double ex=0, ey=0, ez=15, lx=0,ly=0,lz=0, hx=0,hy=1,hz=0;

float wcsClkDn[3],wcsClkUp[3];

class point1
{
public:
    point1()
    {
        x=0;
        y=0;
    }
    int x;
    int y;
} clkpt[2];
int flag=0;
GLint viewport[4];
GLdouble modelview[16];
GLdouble projection[16];


void scsToWcs(float sx,float sy, float wcsv[3] );
void processMouse(int button, int state, int x, int y);
void scsToWcs(float sx,float sy, float wcsv[3] )
{

    GLfloat winX, winY, winZ;
    GLdouble worldX, worldY, worldZ;

    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );

    winX = sx;
    winY = (float)viewport[3] - (float)sy;
    winZ = 0;


    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);
    wcsv[0]=worldX;
    wcsv[1]=worldY;
    wcsv[2]=worldZ;


}


long long nCr(int n, int r)
{
    if(r > n / 2) r = n - r;
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}


void BezierCurve ( double t,  float xy[2])
{
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=L; i++)
    {
        int ncr=nCr(L,i);
        double oneMinusTpow=pow(1-t,double(L-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*ctrlpoints[i][0];
        y+=coef*ctrlpoints[i][1];

    }
    xy[0] = float(x);
    xy[1] = float(y);


}
void BezierCurve2 ( double t,  float xy[2])
{
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=L; i++)
    {
        int ncr=nCr(L,i);
        double oneMinusTpow=pow(1-t,double(L-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*ctrlpoints2[i][0];
        y+=coef*ctrlpoints2[i][1];

    }
    xy[0] = float(x);
    xy[1] = float(y);


}


void setNormal(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(-Nx,-Ny,-Nz);
}
void matColor(float kdr, float kdg, float kdb,  float shiny, int frnt_Back, float ambFactor=.5, float specFactor=.5)
{

    const GLfloat mat_ambient[]    = { kdr*ambFactor, kdg*ambFactor, kdb*ambFactor, 1.0f };
    const GLfloat mat_diffuse[]    = { kdr, kdg, kdb, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f*specFactor, 1.0f*specFactor, 1.0f*specFactor, 1.0f };
    const GLfloat high_shininess[] = { shiny };
    if(frnt_Back==0)
    {
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    }
    else if(frnt_Back==1)
    {
        glMaterialfv(GL_BACK, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_BACK, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_BACK, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_BACK, GL_SHININESS, high_shininess);
    }
    else if(frnt_Back==2)
    {
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess);
    }

}
void bowBezier()
{
    int i, j;
    float x, y, z, r;
    float x1, y1, z1, r1;
    float theta;

    const float startx = 0, endx = ctrlpoints[L][0];

    const float dx = (endx - startx) / nt;
    const float dtheta = 2*PI / ntheta;

    float t=0;
    float dt=1.0/nt;
    float xy[2];
    BezierCurve( t,  xy);
    x = xy[0];
    r = xy[1];

    float p1x,p1y,p1z,p2x,p2y,p2z;
    for ( i = 0; i < nt; ++i )
    {
        theta = 0;
        t+=dt;
        BezierCurve( t,  xy);
        x1 = xy[0];
        r1 = xy[1];


        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= 1; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;
            z = r * sina;
            z1 = r1 * sina;



            glVertex3f (x, y, z);

            if(j>0)
            {
                setNormal(p1x,p1y,p1z,p2x,p2y,p2z,x, y, z);
            }
            else
            {
                p1x=x;
                p1y=y;
                p1z=z;
                p2x=x1;
                p2y=y1;
                p2z=z1;

            }

            glVertex3f (x1, y1, z1);


        }
        glEnd();
        x = x1;
        r = r1;
    }

}
void belunBezier2()
{
    int i, j;
    float x, y, z, r;
    float x1, y1, z1, r1;
    float theta;

    const float startx = 0, endx = ctrlpoints2[L][0];

    const float dx = (endx - startx) / nt;
    const float dtheta = 2*PI / ntheta;

    float t=0;
    float dt=1.0/nt;
    float xy[2];
    BezierCurve2( t,  xy);
    x = xy[0];
    r = xy[1];

    float p1x,p1y,p1z,p2x,p2y,p2z;
    for ( i = 0; i < nt; ++i )
    {
        theta = 0;
        t+=dt;
        BezierCurve2( t,  xy);
        x1 = xy[0];
        r1 = xy[1];


        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= 8; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;
            z = r * sina;
            z1 = r1 * sina;


            glColor3f(1,1,1);
            glVertex3f (x, y, z);

            if(j>0)
            {
                setNormal(p1x,p1y,p1z,p2x,p2y,p2z,x, y, z);
            }
            else
            {
                p1x=x;
                p1y=y;
                p1z=z;
                p2x=x1;
                p2y=y1;
                p2z=z1;

            }
            glColor3f(1,1,1);
            glVertex3f (x1, y1, z1);


        }
        glEnd();
        x = x1;
        r = r1;
    }

}
void showControlPoints()
{
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for (int i = 0; i <=L; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();
}
void showControlPoints2()
{
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for (int i = 0; i <=L; i++)
        glVertex3fv(&ctrlpoints2[i][0]);
    glEnd();
}

void scoredisplay (int posx, int posy, int posz, int space_char, int scorevar)
{
    int j=0,p,k;
    //matColor(0.802, 0.200, 0.100,20,0,1,1);
    //matColor(0.0,0.5,0.8,20,1,1,1);
    GLvoid *font_style1 = GLUT_BITMAP_TIMES_ROMAN_24;
    glRasterPos3f ((posx+60),posy, posz);
    glutBitmapCharacter(font_style1,'S');
    glRasterPos3f ((posx+60-space_char),posy, posz);
    glutBitmapCharacter(font_style1,'C');
    glRasterPos3f ((posx+60-2*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'O');
    glRasterPos3f ((posx+60-3*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'R');
    glRasterPos3f ((posx+60-4*space_char),posy, posz);
    glutBitmapCharacter(font_style1,'E');
    glRasterPos3f ((posx+60-5*space_char),posy, posz);
    glutBitmapCharacter(font_style1,':');

    p = scorevar;
    j = 0;
    k = 0;
    while(p > 9)
    {
        k = p % 10;
        glRasterPos3f ((posx+(j*space_char)),posy, posz);
        glutBitmapCharacter(font_style1,48+k);
        j++;
        p /= 10;
    }
    glRasterPos3f ((posx+(j*space_char)), posy, posz);
    glutBitmapCharacter(font_style1,48+p);

}
void scoredisplayinstant (int posx, int posy, int posz, int space_char, int scorevar,int inst)
{
    if(inst)
    {
        int j=0,p,k;

        GLvoid *font_style1 = GLUT_BITMAP_TIMES_ROMAN_24;
        glRasterPos3f ((posx+32),posy, posz);
        glutBitmapCharacter(font_style1,'H');
        glRasterPos3f ((posx+32-space_char),posy, posz);
        glutBitmapCharacter(font_style1,'I');
        glRasterPos3f ((posx+32-2*space_char),posy, posz);
        glutBitmapCharacter(font_style1,'T');
        glRasterPos3f ((posx+32-3*space_char),posy, posz);
        glutBitmapCharacter(font_style1,'S');
        glRasterPos3f ((posx+32-4*space_char),posy, posz);
        glutBitmapCharacter(font_style1,':');

        p = scorevar;
        j = 0;
        k = 0;
        while(p > 9)
        {
            k = p % 10;
            glRasterPos3f ((posx+(j*space_char)),posy, posz);
            glutBitmapCharacter(font_style1,48+k);
            j++;
            p /= 10;
        }
        glRasterPos3f ((posx+(j*space_char)), posy, posz);
        glutBitmapCharacter(font_style1,48+p);
    }

}
void dischar (int posx, int posy, int posz, int space_char, string ss)
{
    if(inst)
    {
        int j=0,p,k;
        //matColor(0.0, 0.0500, 0.100,20,0,1,1);
        //matColor(0.0,0.5,0.8,20,1,1,1);
        char ch1=ss[0],ch2=ss[1],ch3=ss[2],ch4=ss[3],ch5=ss[4],ch6=ss[5],ch7=ss[6];
        GLvoid *font_style1 = GLUT_BITMAP_TIMES_ROMAN_24;
        glRasterPos3f ((posx+21),posy, posz);
        glutBitmapCharacter(font_style1,ch1);
        glRasterPos3f ((posx+21-space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch2);
        glRasterPos3f ((posx+21-2*space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch3);
        glRasterPos3f ((posx+21-3*space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch4);
        glRasterPos3f ((posx+21-4*space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch5);
        glRasterPos3f ((posx+21-5*space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch6);
        glRasterPos3f ((posx+21-6*space_char),posy, posz);
        glutBitmapCharacter(font_style1,ch7);
    }

}
void mouseMove(int x, int y)
{
    if (xOrigin >= 0 && yOrigin>=0)
    {
        deltaAngle = (x - xOrigin) * 0.05f;
        deltaAngle2 = (y - yOrigin) * 0.05f;
        look_x=deltaAngle;
        look_y=deltaAngle2;
    }
}

void mouseButton(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON)
    {
        if(state ==GLUT_DOUBLE)
        {
            eye_z-=10.0;
            look_z-=10.0;
        }
        else if (state == GLUT_DOWN)
        {
            if(flag!=1)
            {
                flag=1;
                clkpt[0].x=x;
                clkpt[0].y=y;
            }
            if((x>=238 && x<=286) && (y>=408 && y<=423))
            {
                gungame=1;
                arrowgame=0;
                score=0;
                scoreinst=0;
            }
            else if((x>=351 && x<=388) && (y>=401 && y<=416))
            {
                arrowgame=1;
                gungame=0;
                score=0;
                scoreinst=0;
            }
            else if((x>=61 && x<=156) && (y>=492 && y<=532))
            {
                easy=1;
                easy2=0;
                easy3=0;
                medium=0;
                hard=0;
                score=0;
                scoreinst=0;
            }
            else if((x>=191 && x<=268) && (y>=483 && y<=520))
            {
                easy=0;
                easy2=1;
                easy3=0;
                medium=0;
                hard=0;
                score=0;
                scoreinst=0;
            }
            else if((x>=337 && x<=393) && (y>=470 && y<=504))
            {
                easy=0;
                easy2=0;
                easy3=1;
                medium=0;
                hard=0;
                score=0;
                scoreinst=0;
            }
            else if((x>=479 && x<=514) && (y>=461 && y<=493))
            {
                easy=0;
                easy2=0;
                easy3=0;
                medium=1;
                hard=0;
                score=0;
                scoreinst=0;
            }
            else if((x>=609 && x<=650) && (y>=450 && y<=480))
            {
                easy=0;
                easy2=0;
                easy3=0;
                medium=0;
                hard=1;
                score=0;
                scoreinst=0;
            }
            else if((x>=802 && x<=856) && (y>=435 && y<=458))
            {
                sunny=1;
                snow=0;
                score=0;
                scoreinst=0;
            }
            else if((x>=922 && x<=982) && (y>=422 && y<=448))
            {
                sunny=0;
                snow=1;
                score=0;
                scoreinst=0;
            }
            else
            {
                triggercount+=1.0;
                //cout<<triggercount<<endl;
                if(triggercount>=5.0)
                {
                    trigger=true;
                    triggercount=0.0;
                }
                gunshot=true;
                arrowshot=true;
            }

            //cout<<"\nD: "<<x<<" "<<y<<" wcs: "<<wcsClkDn[0]<<" "<<wcsClkDn[1];
        }
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_UP)
        {
            xOrigin = -1;
            yOrigin=-1;
        }
        else
        {
            xOrigin = x;
            yOrigin= y;

        }
    }
    else if (button == GLUT_MIDDLE_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            trigger=true;
            triggercount=0.0;
        }
    }
}

static GLfloat v_Cube[8][3] =
{
    {0.0, 0.0, 0.0},
    {2.0, 0.0, 0.0},
    {0.0, 2.0, 0.0},
    {0.0, 0.0, 2.0},
    {2.0, 2.0, 0.0},
    {0.0, 2.0, 2.0},
    {2.0, 0.0, 2.0},
    {2.0, 2.0, 2.0}
};

static GLubyte quadIndices[6][4] =
{
    {1, 4, 7, 6},
    {7, 4, 2, 5},
    {3, 5, 2, 0},
    {3, 6, 7, 5},
    {0, 2, 4, 1},
    {1, 6, 3, 0}
};

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}
void cube(GLfloat r, GLfloat g, GLfloat b)
{
    GLfloat no_mat[] = {0, 0, 0, 1.0};
    GLfloat mat_ambient[] = {r,g,b,1.0};
    GLfloat mat_diffuse[] = {r,g,b,1.0};
    GLfloat mat_specular[] = {r,g,b,1.0};
    GLfloat mat_shininess[] = {60};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_Cube[quadIndices[i][0]][0], v_Cube[quadIndices[i][0]][1], v_Cube[quadIndices[i][0]][2],
                    v_Cube[quadIndices[i][1]][0], v_Cube[quadIndices[i][1]][1], v_Cube[quadIndices[i][1]][2],
                    v_Cube[quadIndices[i][2]][0], v_Cube[quadIndices[i][2]][1], v_Cube[quadIndices[i][2]][2]);

        glVertex3fv(&v_Cube[quadIndices[i][0]][0]);
        glTexCoord2f(1,0);
        glVertex3fv(&v_Cube[quadIndices[i][1]][0]);
        glTexCoord2f(0,0);
        glVertex3fv(&v_Cube[quadIndices[i][2]][0]);
        glTexCoord2f(0,1);
        glVertex3fv(&v_Cube[quadIndices[i][3]][0]);
        glTexCoord2f(1,1);
    }
    glEnd();
}

class node
{
public:
    GLint x, y, z;
    node(GLint x, GLint y, GLint z) :
        x(x), y(y), z(z) {}
};

void triangle(node a, node b, node c,  GLfloat p,GLfloat r, GLfloat g, GLfloat bl)
{
    GLfloat no_mat[] = {0, 0, 0, 1.0};
    GLfloat mat_ambient[] = {r,g,bl,1.0};
    GLfloat mat_diffuse[] = {r,g,bl,1.0};
    GLfloat mat_specular[] = {r,g,bl,1.0};
    GLfloat mat_shininess[] = {60};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glBegin(GL_TRIANGLES);
    glVertex3f(a.x, a.y, a.z);
    glTexCoord2f(0,.01);
    glVertex3f(b.x, b.y, b.z);
    glTexCoord2f(0,0);
    glVertex3f(c.x, c.y, c.z);
    glTexCoord2f(.01,.01);

    glVertex3f(a.x, a.y, a.z+p);
    glTexCoord2f(0,1);
    glVertex3f(b.x, b.y, b.z+p);
    glTexCoord2f(0,0);
    glVertex3f(c.x, c.y, c.z+p);
    glTexCoord2f(.5,.5);
    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(a.x, a.y, a.z);
    glVertex3f(a.x, a.y, a.z+p);
    glVertex3f(b.x, b.y, b.z+p);
    glVertex3f(b.x, b.y, b.z);

    glVertex3f(a.x, a.y, a.z);
    glVertex3f(a.x, a.y, a.z+p);
    glVertex3f(c.x, c.y, c.z+p);
    glVertex3f(c.x, c.y, c.z);

    glVertex3f(b.x, b.y, b.z);
    glVertex3f(c.x, c.y, c.z);
    glVertex3f(c.x, c.y, c.z+p);
    glVertex3f(b.x, b.y, b.z+p);

    glEnd();
}
void triangle2(node a, node b, node c,  GLfloat p,GLfloat r, GLfloat g, GLfloat bl)
{
    GLfloat no_mat[] = {0, 0, 0, 1.0};
    GLfloat mat_ambient[] = {r,g,bl,1.0};
    GLfloat mat_diffuse[] = {r,g,bl,1.0};
    GLfloat mat_specular[] = {r,g,bl,1.0};
    GLfloat mat_shininess[] = {60};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x, b.y, b.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x, c.y, c.z);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x+p, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x+p, b.y, b.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x+p, c.y, c.z);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x+p, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x+p, b.y, b.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x, b.y, b.z);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(a.x+p, a.y, a.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x+p, c.y, c.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x, c.y, c.z);

    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x, b.y, b.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x, c.y, c.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(c.x+p, c.y, c.z);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(b.x+p, b.y, b.z);

    glEnd();
}

void circle(GLfloat radius, GLfloat p=1)
{
    double prevX=0, prevY=radius, prevZ=0, newX, newY, newZ;
    double steps = 100;
    double angle = (2 * PI) / steps;

    for(ll i = 1; i <= steps; ++i)
    {

        newX = radius * sin(i * angle);
        newY = radius * cos(i * angle);
        newZ = 0;

        triangle(node(0,0,0), node(prevX, prevY, prevZ), node(newX, newY, newZ), p,1,1,1);

        prevX = newX;
        prevY = newY;
    }
}

void drawTarget()
{
    glPushMatrix();
    glScalef(20, 3, 1);
    cube(0, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(27, 5,-5);
    circle(15, 1);
    glPopMatrix();
}

void floor()
{

    glPushMatrix();
    glScalef(150,1,100);
    glTranslatef(-1,-1,-1);
    cube(1,1,1);
    glPopMatrix();

}
void ceil()
{
    glPushMatrix();
    glScalef(155,1,100);
    glTranslatef(-1,-1,-1);
    cube(1,1,1);
    glPopMatrix();
}

void back_wall()
{
    glPushMatrix();
    glScalef(150, 80, 1);
    glTranslatef(-1,-1,-1);
    cube(1,1,1);
    glPopMatrix();
}

void side_wall()
{
    glPushMatrix();
    glScalef(1, 80, 100);
    glTranslatef(-1,-1,-1);
    cube(1,1,1);
    glPopMatrix();
}

void gun()
{

    glPushMatrix();
    //trigger
    glTranslatef(0,triggery,0);
    glScalef(0.5,1.4,.2);
    cube(0.043, 0.043, 0.035);
    glPopMatrix();

    //nol
    glPushMatrix();
    glTranslatef(0,3.8,2.3);
    glScalef(0.5,.3,1.4);

    cube(0.098, 0.098, 0.098);
    glPopMatrix();

    //body
    glPushMatrix();

    glTranslatef(0,2.8,-1.1);
    glScalef(0.5,.8,1.7);

    cube(0.098, 0.098, 0.098);
    glPopMatrix();

}
void light1()
{
    GLfloat l_no[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat l_amb[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat l_dif[] = {1.0,1.0,1.0,1.0};
    GLfloat l_spec[] = {1.0,1.0,1.0,1.0};
    GLfloat l_pos[] = {0.0,20.0,0.0,1.0};
    glEnable(GL_LIGHT0);
    if(diffuse_1_on && light_1_on)
    {
        glLightfv(GL_LIGHT0, GL_DIFFUSE, l_dif);
    }
    else
    {
        glLightfv(GL_LIGHT0, GL_DIFFUSE, l_no);
    }
    if(specular_1_on && light_1_on)
    {
        glLightfv(GL_LIGHT0, GL_SPECULAR, l_spec);
    }
    else
    {
        glLightfv(GL_LIGHT0, GL_SPECULAR, l_no);
    }
    if(ambient_1_on && light_1_on)
    {
        glLightfv(GL_LIGHT0, GL_AMBIENT, l_amb);
    }
    else
    {
        glLightfv(GL_LIGHT0, GL_AMBIENT, l_no);
    }
    glLightfv(GL_LIGHT0, GL_POSITION, l_pos);
}
void light2()
{
    GLfloat l_no[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat l_amb[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat l_dif[] = {1.0,1.0,1.0,1.0};
    GLfloat l_spec[] = {1.0,1.0,1.0,1.0};
    GLfloat l_pos[] = {0.0,20.0,0.0,1.0};
    glEnable(GL_LIGHT1);
    if(diffuse_2_on && light_2_on)
    {
        glLightfv(GL_LIGHT1, GL_DIFFUSE, l_dif);
    }
    else
    {
        glLightfv(GL_LIGHT1, GL_DIFFUSE, l_no);
    }
    if(specular_2_on && light_2_on)
    {
        glLightfv(GL_LIGHT1, GL_SPECULAR, l_spec);
    }
    else
    {
        glLightfv(GL_LIGHT1, GL_SPECULAR, l_no);
    }
    if(ambient_2_on && light_2_on)
    {
        glLightfv(GL_LIGHT1, GL_AMBIENT, l_amb);
    }
    else
    {
        glLightfv(GL_LIGHT1, GL_AMBIENT, l_no);
    }
    glLightfv(GL_LIGHT1, GL_POSITION, l_pos);
}
void light3()
{
    GLfloat l_no[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat l_amb[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat l_dif[] = {1.0,1.0,1.0,1.0};
    GLfloat l_spec[] = {1.0,1.0,1.0,1.0};
    GLfloat l_pos[] = {0.0,20.0,0.0,1.0};
    glEnable(GL_LIGHT2);
    if(light_3_on)
    {
        glLightfv(GL_LIGHT2, GL_DIFFUSE, l_dif);
        glLightfv(GL_LIGHT2, GL_SPECULAR, l_spec);
        glLightfv(GL_LIGHT2, GL_AMBIENT, l_amb);
    }
    else
    {
        glLightfv(GL_LIGHT2, GL_AMBIENT, l_no);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, l_no);
        glLightfv(GL_LIGHT2, GL_SPECULAR, l_no);
    }
    glLightfv(GL_LIGHT2, GL_POSITION, l_pos);
}
void spotlight()
{
    GLfloat l_no[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat l_amb[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat l_dif[] = {1.0,1.0,1.0,1.0};
    GLfloat l_spec[] = {1.0,1.0,1.0,1.0};
    GLfloat l_pos[] = {0.0,20.0,0.0,1.0};
    glEnable(GL_LIGHT3);
    if(diffuse_spot_on && light_spot_on)
    {
        glLightfv(GL_LIGHT3, GL_DIFFUSE, l_dif);
    }
    else
    {
        glLightfv(GL_LIGHT3, GL_DIFFUSE, l_no);
    }
    if(specular_spot_on && light_spot_on)
    {
        glLightfv(GL_LIGHT3, GL_SPECULAR, l_spec);
    }
    else
    {
        glLightfv(GL_LIGHT3, GL_SPECULAR, l_no);
    }
    if(ambient_spot_on && light_spot_on)
    {
        glLightfv(GL_LIGHT3, GL_AMBIENT, l_amb);
    }
    else
    {
        glLightfv(GL_LIGHT3, GL_AMBIENT, l_no);
    }
    glLightfv(GL_LIGHT3, GL_POSITION, l_pos);

    GLfloat l_spt[] = {0,-1,0,1};
    GLfloat spt_ct[] = {spt_cutoff};
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT3, GL_SPOT_CUTOFF, spt_ct);
}
void spotlightarrow()
{
    GLfloat l_no[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat l_amb[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat l_dif[] = {1.0,1.0,1.0,1.0};
    GLfloat l_spec[] = {1.0,1.0,1.0,1.0};
    GLfloat l_pos[] = {0.0,20.0,0.0,1.0};
    glEnable(GL_LIGHT4);
    if(light_spot2_on)
    {
        glLightfv(GL_LIGHT4, GL_DIFFUSE, l_dif);
        glLightfv(GL_LIGHT4, GL_SPECULAR, l_spec);
        glLightfv(GL_LIGHT4, GL_AMBIENT, l_amb);
    }
    else
    {
        glLightfv(GL_LIGHT4, GL_AMBIENT, l_no);
        glLightfv(GL_LIGHT4, GL_DIFFUSE, l_no);
        glLightfv(GL_LIGHT4, GL_SPECULAR, l_no);
    }
    glLightfv(GL_LIGHT4, GL_POSITION, l_pos);

    GLfloat l_spt[] = {0,0,.8,1};
    GLfloat spt_ct[] = {40};
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT4, GL_SPOT_CUTOFF, spt_ct);
}
void arrowf()
{
    glPushMatrix();
    triangle2(node(0,0,0), node(0, 5, 0), node(0, 2.5, 4.2),.5,0,0,0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.002,1.29,-18);
    triangle2(node(0,0,0), node(0, 3, 0), node(0, 1.5, 4), .5,0, 0, 0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,2.4,-16);
    glScalef(.3,.3,8.5);
    cube(0,0,0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,1.8,3.2);
    spotlightarrow();
    glPopMatrix();
    glPopMatrix();
}
void targetline()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, ten);
    glTranslatef(5,0,-.5);
    glScalef(3,3,3);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, nine);
    glTranslatef(20,0,-.5);
    glScalef(3,3,3);
    cube(1,1,0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, eight);
    glTranslatef(35,0,-.5);
    glScalef(3,3,3);
    cube(1,0,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, seven);
    glTranslatef(50,0,-.5);
    glScalef(3,3,3);
    cube(0,1,0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, six);
    glTranslatef(65,0,-.5);
    glScalef(3,3,3);
    cube(0,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, five);
    glTranslatef(80,0,-.5);
    glScalef(3,3,3);
    cube(0,0,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPushMatrix();
    glScalef(47,3,.5);
    cube(0.545, 0.271, 0.075);
    glPopMatrix();
    glPopMatrix();
}
void arrowbow()
{
    glPushMatrix();

    glRotatef( anglex, 1.0, 0.0, 0.0);
    glRotatef( angley, 0.0, 1.0, 0.0);
    glRotatef( anglez, 0.0, 0.0, 1.0);

    glRotatef( 90, 0.0, 0.0, 1.0);
    glTranslated(-3.5,0,0);
    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );

    matColor(0.502, 0.000, 0.00,20,0,1,1);
    //matColor(0.0,0.5,0.8,20,1,1,1);


    bowBezier();
    if(schpt)
    {
        matColor(0.0,0.0,0.1,20,0,1,1);
        showControlPoints();
    }

    glPopMatrix();
}
void targetcircle()
{
    glPushMatrix();
    glRotatef(tartheta,0,0,1);
    glTranslatef(0,0,55);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, target);
    drawTarget();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, target);
    glTranslatef(0,6,0);
    glRotatef(180,0,0,1);
    drawTarget();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //targetstand
    glPushMatrix();
    glTranslatef(-3,-51,57);
    glScalef(3,25.5,3);
    cube(0.545, 0.271, 0.075);
    glPopMatrix();
}
void targetcircleup()
{
    glPushMatrix();
    glTranslatef(ux,40,0);
    glPushMatrix();
    glPushMatrix();
    glTranslatef(0,0,55);
    glRotatef(-90,0,0,1);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, target);
    drawTarget();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(35,0,55);
    glRotatef(-90,0,0,1);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, target);
    drawTarget();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-35,0,55);
    glRotatef(-90,0,0,1);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, target);
    drawTarget();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-70,0,55);
    glRotatef(-90,0,0,1);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, target);
    drawTarget();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}
void drawStrokeText(char* str,int x,int y,int z)
{
    char *c;
    glPushMatrix();
    glTranslatef(x, y,z);
    glRotatef(180,0,0,1);
    glRotatef(180,1,0,0);
    glScalef(.044f,.044f,0.008f);

    for (c=str; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}
void targetboxmove()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, ten);
    glTranslatef(x1,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, nine);
    glTranslatef(x2,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, eight);
    glTranslatef(x3,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, seven);
    glTranslatef(x4,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, six);
    glTranslatef(x5,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, five);
    glTranslatef(x6,11,25);
    glScalef(5,3.5,.5);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
void belun(float r, float g, float b)
{
    glPushMatrix();
    glPushMatrix();
    matColor(r,g,b,20,0,1,1);
    glRotatef(90,0,0,1);
    glScalef(3,4,.1);
    belunBezier2();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-10,0);
    glScalef(.2,8,.2);
    cube(0,0,0);
    glPopMatrix();
    glPopMatrix();
    if(schpt)
    {
        matColor(0.0,0.0,0.1,20,0,1,1);
        showControlPoints2();
    }
}
void targetbelunmove()
{
    glPushMatrix();
    glPushMatrix();
    glTranslatef(xx1,11,25);
    belun(.5,0,0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(xx2,11,25);
    belun(0,.5,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xx3,11,25);
    belun(0,0,.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xx4,11,25);
    belun(.5,0.5,0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(xx5,11,25);
    belun(.5,0,.5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(xx6,11,25);
    belun(0,0.5,0.5);
    glPopMatrix();
    glPopMatrix();
}

void alllights()
{
    glPushMatrix();
    glTranslatef(-70,20,0);
    light1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-140,24,-15);
    glScalef(1.0,2.0,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();

    //light2
    glPushMatrix();
    glTranslatef(70,20,0);
    light2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(82,24,30);
    glScalef(1.0,2.0,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();

    //light3
    glPushMatrix();
    glTranslatef(5,0,55);
    light3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,105);
    glScalef(1.0,2.0,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();

    //light3
    glPushMatrix();
    glTranslatef(0,0,55);
    light3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,105);
    glScalef(1.0,2.0,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();

    //spot light
    glPushMatrix();
    glTranslatef(0,46,40);
    spotlight();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40,26,-20);
    spotlight();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,34,105);
    glScalef(1.0,1.5,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
}
void display(void)
{
    //scoreinst=0;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(-7,7,-7,7, 3, 300);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eye_x,eye_y,eye_z, look_x,look_y,look_z, 0,1,0);
    glViewport(0, 0, windowHeight, windowWidth);
    glRotatef(angle, axis_x, axis_y,0.0);



    if(easy)
    {
        //targets up circle
        glPushMatrix();
        targetcircleup();
        glPopMatrix();
        glPushMatrix();
        glRotatef(-7,0,1,0);
        glPushMatrix();
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("Red:10",90,15,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("White(in):9",77,7,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("Blue:8",65,-1,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("White(out):7",54,-9,5);
        glPopMatrix();
        glPopMatrix();


    }
    if(easy2)
    {
        glPushMatrix();
        targetboxmove();
        glPopMatrix();
    }
    if(easy3)
    {
        glPushMatrix();
        glTranslatef(0,-11,10);
        targetbelunmove();
        glPopMatrix();
        glPushMatrix();
        glRotatef(-7,0,1,0);
        glPushMatrix();
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("Red:10",90,27,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("Green:9",76,20,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("Blue:8",65,13,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("Brown:7",54,6,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("Violet:6",45,-1,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("Cyan:5",38,-8,5);
        glPopMatrix();
        glPopMatrix();
    }
    if (medium)
    {
        //targets on number boxes
        glPushMatrix();
        glTranslatef(sx,11,15);
        targetline();
        glPopMatrix();
    }
    if(hard)
    {
        //target
        glPushMatrix();
        targetcircle();
        glPopMatrix();
        glPushMatrix();
        glRotatef(-7,0,1,0);
        glPushMatrix();
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("Red:10",90,15,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("White(in):9",77,7,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("Blue:8",65,-1,5);
        matColor(1.000, 0.000, 0.000,20,0,1,1);
        glScalef(1.2,1,.1);
        drawStrokeText("White(out):7",54,-9,5);
        glPopMatrix();
        glPopMatrix();
    }
    if(arrowgame)
    {
        //Arrow
        glPushMatrix();
        glTranslatef(-23.1,11,az);
        arrowf();
        glPopMatrix();

        //bow
        glPushMatrix();
        glTranslatef(-24.1,9,-64);
        glScalef(4,4,4);
        //glRotatef(-40,0,0,1);
        glRotatef(46,0,1,0);
        glRotatef(15,1,0,0);
        arrowbow();
        glPopMatrix();
    }
    if(gungame)
    {
        //gun
        glPushMatrix();
        glTranslatef(-23,9.8,-62);
        //glRotatef(theta,0,1,0);
        glRotatef(theta2,0,0,1);
        gun();
        glPopMatrix();


        //guli
        glPushMatrix();
        glTranslatef(-22.7,13.52,gz);
        glPushMatrix();
        glScalef(gulix,guliy,guliz);
        cube(0,0,0);
        glPushMatrix();
        glTranslatef(0,1.8,3.2);
        spotlightarrow();
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();

    }

    //ceil
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, e1);
    glTranslatef(0,75,30);
    ceil();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //back wall
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, e2);
    glTranslatef(0,20,110);
    back_wall();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //side wall
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, e3);
    glTranslatef(-160,20,30);
    side_wall();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //side wall
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, e3);
    glTranslatef(115,20,30);
    side_wall();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //field
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, e5);
    glTranslatef(0,-50,10);
    floor();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //lights
    glPushMatrix();
    alllights();
    glPopMatrix();

    glPushMatrix();
    matColor(0.0, 0.0500, 0.100,20,0,1,1);
    dischar(37,-16,-45,2,"Basic  ");
    glPushMatrix();
    glTranslatef(46,-15.8,-52);
    glScalef(2,.01,2);
    cube(0,.8,.2);
    glPopMatrix();
    matColor(0.0, 0.0500, 0.100,20,0,1,1);
    dischar(24,-16,-45,3,"Easy   ");
    glPushMatrix();
    glTranslatef(34,-15.8,-52);
    glScalef(2,.01,2);
    cube(0,.2,.9);
    glPopMatrix();
    matColor(0.0, 0.0500, 0.100,20,0,1,1);
    dischar(10,-16,-45,3,"Normal  ");
    glPushMatrix();
    glTranslatef(19,-15.8,-52);
    glScalef(2,.01,2);
    cube(.6,.7,0);
    glPopMatrix();
    matColor(0.0, 0.0500, 0.100,20,0,1,1);
    dischar(-10,-16,-45,3,"Hard  ");
    glPushMatrix();
    glTranslatef(3,-15.8,-52);
    glScalef(2,.01,2);
    cube(0,.5,.5);
    glPopMatrix();
    matColor(0.0, 0.0500, 0.100,20,0,1,1);
    dischar(-26,-16,-45,3,"Extreme");
    glPushMatrix();
    glTranslatef(-15,-15.8,-52);
    glScalef(2,.01,2);
    cube(.8,.1,0);
    glPopMatrix();
    matColor(0.05, 0.100, 0.0500,20,0,1,1);
    dischar(-58,-16,-45,4,"Sunny  ");
    glPushMatrix();
    glTranslatef(-46,-15.8,-52);
    glScalef(2,.01,2);
    cube(0,.1,.8);
    glPopMatrix();
    matColor(0.05, 0.100, 0.0500,20,0,1,1);
    dischar(-83,-16,-45,5,"Snowy  ");
    glPushMatrix();
    glTranslatef(-68,-15.8,-52);
    glScalef(2,.01,2);
    cube(1,1,0);
    glPopMatrix();
    matColor(0.08, 0.0500, 0.100,20,0,1,1);
    dischar(38,-16,-26,4,"Gun    ");
    glPushMatrix();
    glTranslatef(46,-15.8,-35);
    glScalef(2,.01,2);
    cube(.7,.4,.3);
    glPopMatrix();
    matColor(0.08, 0.0500, 0.100,20,0,1,1);
    dischar(22,-16,-26,4,"Arrow  ");
    glPushMatrix();
    glTranslatef(28,-15.8,-35);
    glScalef(2,.01,2);
    cube(.1,.6,.4);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,34,90);
    glScalef(1.0,1.5,1.0);
    cube(0.5, 0.5, 0.5);
    glPopMatrix();
    glPushMatrix();
    matColor(0.802, 0.200, 0.100,20,0,1,1);
    scoredisplay(-53,35,0,7,score);
    glPopMatrix();
    glPushMatrix();
    matColor(0.000, 0.000, 0.804,20,0,1,1);
    scoredisplayinstant(42,35,0,6,scoreinst,inst);
    glPopMatrix();


    if(easy==0 && hard==0 && easy2==0 && easy3==0 && medium==0 && gungame==0 && arrowgame==0)
    {
        glPushMatrix();
        matColor(0.502, 0.000, 0.000,20,0,1,1);
        dischar(-8.5,21.5,-45,2,"SHOOTING");
        matColor(0.502, 0.000, 0.000,20,0,1,1);
        dischar(-22.5,21.5,-45,2,"G       ");
        matColor(0.502, 0.000, 0.000,20,0,1,1);
        dischar(-28.5,21.5,-45,3,"GAME   ");
        glTranslatef(cx,0,0);
        glPushMatrix();
        matColor(0.000, 0.392, 0.000,20,0,1,1);
        dischar(-11,14.5,-45,2,"Select ");
        matColor(0.000, 0.392, 0.000,20,0,1,1);
        dischar(-24,14.5,-45,2,"Levels ");
        glPopMatrix();
        glPopMatrix();
    }

    glFlush();
    glutSwapBuffers();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'k':
        eye_y--;
        look_y--;
        break;
    case 'i':
        eye_y++;
        look_y++;
        break;

    case 'l':
        eye_x--;
        look_x--;
        break;
    case 'j':
        eye_x++;
        look_x++;
        break;
    case '7':
        look_y++;
        break;
    case '8':
        look_y--;
        break;
    case '9':
        look_x++;
        break;
    case '0':
        look_x--;
        break;
    case 'r':
        Rotate = !Rotate;
        axis_x=0.0;
        axis_y=1.0;
        break;
    case 't':
        Rotate=!Rotate;
        axis_x=0.0;
        axis_y=-1.0;
        break;
    case 'u':
        uRotate = !uRotate;
        axis_x=1.0;
        axis_y=0.0;
        break;
    case 'X':
        zoomp=!zoomp;
        break;
    case '+':
        eye_z++;
        look_z++;
        break;
    case '-':
        eye_z--;
        look_z--;
        break;
    case '1':
        light_1=!light_1;
        break;
    case '!':
        light_3=!light_3;
        break;
    case '2':
        light_2=!light_2;
        break;
    case '3':
        light_spot=!light_spot;
        break;
    case '@':
        light_spot2=!light_spot2;
        break;
    case 'v':
        spt_cutoff++;
        break;
    case 'b':
        spt_cutoff--;
        break;
    case 'e':
        diffuse_1_on=!diffuse_1_on;
        break;
    case 'w':
        specular_1_on=!specular_1_on;
        break;
    case 'q':
        ambient_1_on=!ambient_1_on;
        break;
    case 'd':
        diffuse_2_on=!diffuse_2_on;
        break;
    case 's':
        specular_2_on=!specular_2_on;
        break;
    case 'a':
        ambient_2_on=!ambient_2_on;
        break;
    case 'c':
        diffuse_spot_on=!diffuse_spot_on;
        break;
    case 'x':
        specular_spot_on=!specular_spot_on;
        break;
    case 'z':
        ambient_spot_on=!ambient_spot_on;
        break;
    case 'm':
        triggercount+=1.0;
        //cout<<triggercount<<endl;
        if(triggercount>=5.0)
        {
            trigger=true;
            triggercount=0.0;
        }
        gunshot=true;
        break;
    case 'B':
        easy=1;
        easy2=0;
        easy3=0;
        hard=0;
        medium=0;
        score=0;
        break;
    case 'R':
        hard=1;
        easy=0;
        easy2=0;
        easy3=0;
        medium=0;
        score=0;
        break;
    case 'H':
        hard=0;
        medium=1;
        easy=0;
        easy2=0;
        easy3=0;
        score=0;
        break;
    case 'E':
        hard=0;
        medium=0;
        easy=0;
        easy2=1;
        easy3=0;
        score=0;
        break;
    case 'M':
        hard=0;
        medium=0;
        easy=0;
        easy2=0;
        easy3=1;
        score=0;
        break;
    case 'G':
        gungame=1;
        arrowgame=0;
        score=0;
        break;
    case 'A':
        arrowgame=1;
        gungame=0;
        score=0;
        break;
    case 'P':
        schpt=!schpt;
        break;
    case 'Z':
        zoom=1;
        normal=0;
        break;
    case 'N':
        zoom=0;
        normal=1;
        break;
    case 'S':
        sunny=1;
        snow=0;
        break;
    case 'W':
        sunny=0;
        snow=1;
        break;
    case 27:
        exit(1);
    }
}

void animate()
{
    if(snow)
    {
        e1=swall;
        e2=sfield;
        e3=sfield;
        e4=sfield;
        e5=sceilbmp;
        if(light_1)
            light_1_on=0;
        else
            light_1_on=1;
        if(light_2)
            light_2_on=0;
        else
            light_2_on=1;
        if(light_spot)
            light_spot_on=0;
        else
            light_spot_on=1;
        if(light_spot2)
            light_spot2_on=0;
        else
            light_spot2_on=1;
        light_3_on=0;

    }
    if(sunny)
    {
        e1=ceilbmp;
        e2=wall;
        e3=sidewall1;
        e4=sidewall1;
        e5=field;
        if(light_1)
            light_1_on=0;
        else
            light_1_on=1;
        if(light_2)
            light_2_on=0;
        else
            light_2_on=1;
        if(light_spot)
            light_spot_on=0;
        else
            light_spot_on=1;
        if(light_spot2)
            light_spot2_on=0;
        else
            light_spot2_on=1;
        if(light_3)
            light_3_on=0;
        else
            light_3_on=1;
    }
    if(normal)
    {
        if(zoomp==0)
            eye_x = 0.0, eye_y = 21.0, eye_z = -68.0, look_x = -7.0, look_y = -9.0, look_z = -1.0;
    }
    if(zoom)
    {
        if(arrowgame)
            eye_x=-23.0,eye_y=20.0,eye_z=-57.0, look_x=-19.0,look_y=-2.0,look_z=-23.0;
        if(gungame)
            eye_x=-23.0,eye_y=19.0,eye_z=-60.0, look_x=-19.0,look_y=-2.0,look_z=-23.0;
    }
    if(arrowshot)
    {
        az+=.6;
        if(az>=80)
            arrowshot=false;
    }
    else
    {
        az=ina;
    }
    if(arrowgame && easy2)
    {
        if(az<=25 && az>=24.5)
        {
            if(x1>=-32 && x1<=-22)
            {
                score+=10;
                scoreinst=10;
            }
            else if(x2>=-32 && x2<=-22)
            {
                score+=9;
                scoreinst=9;
            }
            else if(x3>=-32 && x3<=-22)
            {
                score+=8;
                scoreinst=8;
            }
            else if(x4>=-32 && x4<=-22)
            {
                score+=7;
                scoreinst=7;
            }
            else if(x5>=-32 && x5<=-22)
            {
                score+=6;
                scoreinst=6;
            }
            else if(x6>=-32 && x6<=-22)
            {
                score+=5;
                scoreinst=5;
            }
            else
                scoreinst=0;
            //cout<<sx<<endl;
            Sleep(1000);
        }
    }
    if(arrowgame && easy3)
    {
        if(az<=25 && az>=24.5)
        {
            if(xx1>=-34 && xx1<=-16)
            {
                score+=10;
                scoreinst=10;
            }
            else if(xx2>=-34 && xx2<=-16)
            {
                score+=9;
                scoreinst=9;
            }
            else if(xx3>=-34 && xx3<=-16)
            {
                score+=8;
                scoreinst=8;
            }
            else if(xx4>=-34 && xx4<=-16)
            {
                score+=7;
                scoreinst=7;
            }
            else if(xx5>=-34 && xx5<=-16)
            {
                score+=6;
                scoreinst=6;
            }
            else if(xx6>=-34 && xx6<=-16)
            {
                score+=5;
                scoreinst=5;
            }
            else
                scoreinst=0;
            //cout<<sx<<endl;
            Sleep(1000);
        }
    }
    if(arrowgame && medium)
    {
        if(az<=25 && az>=24.5)
        {
            if(sx<=-28.1 && sx>=-34.1)
            {
                score+=10;
                scoreinst=10;
            }
            else if(sx<=-43.1 && sx>=-49.1)
            {
                score+=9;
                scoreinst=9;
            }
            else if(sx<=-58.1 && sx>=-64.1)
            {
                score+=8;
                scoreinst=8;
            }
            else if(sx<=-73.1 && sx>=-79.1)
            {
                score+=7;
                scoreinst=7;
            }
            else if(sx<=-88.1 && sx>=-94.1)
            {
                score+=6;
                scoreinst=6;
            }
            else if(sx<=-103.1 && sx>=-109.1)
            {
                score+=5;
                scoreinst=5;
            }
            else
                scoreinst=0;
            //cout<<sx<<endl;
            Sleep(1000);
        }
    }
    if(arrowgame && hard)
    {
        if(az>=46 && az <=46.6)
        {
            GLfloat ff=tartheta;
            if(ff>=326 && ff<=340)
            {
                score+=10;
                scoreinst=10;
            }
            else if((ff >340 && ff<=348) ||(ff<326 && ff>=318))
            {
                score+=9;
                scoreinst=9;
            }
            else if((ff>348 && ff<=355) ||(ff<318 && ff>=311))
            {
                score+=8;
                scoreinst=8;
            }
            else if((ff>355 && ff<=3) ||(ff<311 && ff>=305))
            {
                score+=7;
                scoreinst=7;
            }
            else if(ff>=(326-192) && ff<=(340-192))
            {
                score+=10;
                scoreinst=10;
            }
            else if((ff>(340-192) && ff<=(348-192)) ||(ff<(326-192) && ff>=(318-192)))
            {
                score+=9;
                scoreinst=9;
            }
            else if((ff>(348-192) && ff<=(355-192)) ||(ff<(318-192) && ff>=(311-192)))
            {
                score+=8;
                scoreinst=8;
            }
            else if((ff>(355-192) && ff<=(363-192)) ||(ff<(311-192) && ff>=(305-192)))
            {
                score+=7;
                scoreinst=7;
            }
            else
                scoreinst=0;
            //cout<<ff<<endl;
            Sleep(1000);
        }
    }
    if(trigger && gungame)
    {
        if(c1)
        {
            triggery-=.05;
            if(triggery<=-4.1)
            {
                c1=0;
            }
        }
        else
        {
            triggery+=.05;
            if(triggery>=0)
            {
                trigger=false;
                c1=1;
            }
        }
    }
    if(gunshot)
    {
        gz+=.5;
        if(gz>=80)
            gunshot=false;
    }
    else
    {
        gz=inz;
    }
    if(gungame && easy2)
    {
        if(gz<=16 && gz>=15.6)
        {
            if(x1>=-34 && x1<=-24)
            {
                score+=10;
                scoreinst=10;
            }
            else if(x2>=-34 && x2<=-24)
            {
                score+=9;
                scoreinst=9;
            }
            else if(x3>=-34 && x3<=-24)
            {
                score+=8;
                scoreinst=8;
            }
            else if(x4>=-34 && x4<=-24)
            {
                score+=7;
                scoreinst=7;
            }
            else if(x5>=-34 && x5<=-24)
            {
                score+=6;
                scoreinst=6;
            }
            else if(x6>=-34 && x6<=-24)
            {
                score+=5;
                scoreinst=5;
            }
            else
                scoreinst=0;
            //cout<<sx<<endl;
            Sleep(1000);
        }
    }
    if(gungame && easy3)
    {
        if(gz<=16 && gz>=15.6)
        {
            if(xx1>=-36 && xx1<=-18)
            {
                score+=10;
                scoreinst=10;
            }
            else if(xx2>=-36  && xx2<=-18)
            {
                score+=9;
                scoreinst=9;
            }
            else if(xx3>=-36 && xx3<=-18)
            {
                score+=8;
                scoreinst=8;
            }
            else if(xx4>=-36 && xx4<=-18)
            {
                score+=7;
                scoreinst=7;
            }
            else if(xx5>=-36 && xx5<=-18)
            {
                score+=6;
                scoreinst=6;
            }
            else if(xx6>=-36 && xx6<=-18)
            {
                score+=5;
                scoreinst=5;
            }
            else
                scoreinst=0;
            //cout<<sx<<endl;
            Sleep(1000);
        }
    }
    if(gungame && hard)
    {
        if(gz>=46 && gz <=46.4)
        {
            GLfloat ff=tartheta;
            if(ff>=326 && ff<=340)
            {
                score+=10;
                scoreinst=10;
            }
            else if((ff >340 && ff<=348) ||(ff<326 && ff>=318))
            {
                score+=9;
                scoreinst=9;
            }
            else if((ff>348 && ff<=355) ||(ff<318 && ff>=311))
            {
                score+=8;
                scoreinst=8;
            }
            else if((ff>355 && ff<=3) ||(ff<311 && ff>=305))
            {
                score+=7;
                scoreinst=7;
            }
            else if(ff>=(326-192) && ff<=(340-192))
            {
                score+=10;
                scoreinst=10;
            }
            else if((ff>(340-192) && ff<=(348-192)) ||(ff<(326-192) && ff>=(318-192)))
            {
                score+=9;
                scoreinst=9;
            }
            else if((ff>(348-192) && ff<=(355-192)) ||(ff<(318-192) && ff>=(311-192)))
            {
                score+=8;
                scoreinst=8;
            }
            else if((ff>(355-192) && ff<=(363-192)) ||(ff<(311-192) && ff>=(305-192)))
            {
                score+=7;
                scoreinst=7;
            }
            else
                scoreinst=0;
            //cout<<ff<<endl;
            Sleep(1000);
        }
    }
    if(arrowgame && easy)
    {
        if(az>=46 && az <=46.6)
        {
            GLfloat ff=tartheta;
            if((ux>=4 && ux<11) || (ux>=39 && ux<46) || (ux>=-31 && ux<-24) || (ux>=-66 && ux<-59))
            {
                score+=10;
                scoreinst=10;
            }
            else if((ux>=1 && ux<4) || (ux>=11 && ux<14) || (ux>=36 && ux<39) || (ux>=46 && ux<49) || (ux>=-34 && ux<-31) || (ux>=-24 && ux<-21) || (ux>=-69 && ux<-66) || (ux>=-59 && ux<-56))
            {
                score+=9;
                scoreinst=9;
            }
            else if((ux>=-2 && ux<1) || (ux>=14 && ux<17) || (ux>=33 && ux<36) || (ux>=49 && ux<52)|| (ux>=-37 && ux<-34) || (ux>=-21 && ux<-18) || (ux>=-72 && ux<-69) || (ux>=-56 && ux<-53))
            {
                score+=8;
                scoreinst=8;
            }
            else if((ux>=-6 && ux<-2) || (ux>=17 && ux<21) || (ux>=29 && ux<33) || (ux>=52 && ux<56)|| (ux>=-41 && ux<-37) || (ux>=-18 && ux<-14) || (ux>=-76 && ux<-72) || (ux>=-53 && ux<-49))
            {
                score+=7;
                scoreinst=7;
            }
            else
                scoreinst=0;
            //cout<<ff<<endl;
            Sleep(1000);
        }
    }
    if(gungame && easy)
    {
        if(az>=46-temp3 && az <=46.6-temp3)
        {
            GLfloat ff=tartheta;
            if((ux>=4-temp3 && ux<11-temp3) || (ux>=39-temp3 && ux<46-temp3) || (ux>=-31-temp3 && ux<-24-temp3) || (ux>=-66-temp3 && ux<-59-temp3))
            {
                score+=10;
                scoreinst=10;
            }
            else if((ux>=1-temp3 && ux<4-temp3) || (ux>=11-temp3 && ux<14-temp3) || (ux>=36-temp3 && ux<39-temp3) || (ux>=46-temp3 && ux<49-temp3) || (ux>=-34-temp3 && ux<-31-temp3) || (ux>=-24-temp3 && ux<-21-temp3) || (ux>=-69-temp3 && ux<-66-temp3) || (ux>=-59-temp3 && ux<-56-temp3))
            {
                score+=9;
                scoreinst=9;
            }
            else if((ux>=-2-temp3 && ux<1-temp3) || (ux>=14-temp3 && ux<17-temp3) || (ux>=33-temp3 && ux<36-temp3) || (ux>=49-temp3 && ux<52-temp3)|| (ux>=-37-temp3 && ux<-34-temp3) || (ux>=-21-temp3 && ux<-18-temp3) || (ux>=-72-temp3 && ux<-69-temp3) || (ux>=-56-temp3 && ux<-53-temp3))
            {
                score+=8;
                scoreinst=8;
            }
            else if((ux>=-6-temp3 && ux<-2-temp3) || (ux>=17-temp3 && ux<21-temp3) || (ux>=29-temp3 && ux<33-temp3) || (ux>=52-temp3 && ux<56-temp3)|| (ux>=-41-temp3 && ux<-37-temp3) || (ux>=-18-temp3 && ux<-14-temp3) || (ux>=-76-temp3 && ux<-72-temp3) || (ux>=-53-temp3 && ux<-49-temp3))
            {
                score+=7;
                scoreinst=7;
            }
            else
                scoreinst=0;
            //cout<<ff<<endl;
            Sleep(1000);
        }
    }
    if(gungame && medium)
    {
        if(gz<=10 && gz>=9.7)
        {
            if(sx<=-28.1 && sx>=-34.1)
            {
                score+=10;
                scoreinst=10;
            }
            else if(sx<=-43.1 && sx>=-49.1)
            {
                score+=9;
                scoreinst=9;
            }
            else if(sx<=-58.1 && sx>=-64.1)
            {
                score+=8;
                scoreinst=8;
            }
            else if(sx<=-73.1 && sx>=-79.1)
            {
                score+=7;
                scoreinst=7;
            }
            else if(sx<=-88.1 && sx>=-94.1)
            {
                score+=6;
                scoreinst=6;
            }
            else if(sx<=-103.1 && sx>=-109.1)
            {
                score+=5;
                scoreinst=5;
            }
            else
                scoreinst=0;
            //cout<<sx<<endl;
            Sleep(1000);
        }
    }
    if(easy2)
    {
        x1-=.1;
        if(x1<=40 || t1)
        {
            x2-=.1;
        }
        if(x2<=40 ||t2)
        {
            x3-=.1;
        }
        if(x3<=40 ||t3)
        {
            x4-=.1;
        }
        if(x4<=40 ||t4)
        {
            x5-=.1;
        }
        if(x5<=40 ||t5)
        {
            x6-=.1;
        }
        if(x2<=-110)
        {
            x2=70;
            t2=1;
        }
        if(x3<=-110)
        {
            x3=70;
            t3=1;
        }
        if(x4<=-110)
        {
            x4=70;
            t4=1;
        }
        if(x5<=-110)
        {
            x5=70;
            t5=1;
        }
        if(x6<=-110)
        {
            x6=70;
        }
        if(x1<=-110)
        {
            x1=70;
            t1=1;
        }
    }
    else
    {
        x1=70.0;
        x2=70.0;
        x3=70.0;
        x4=70.0;
        x5=70.0;
        x6=70.0;
        t1=0,t2=0,t3=0,t4=0,t5=0;
    }
    if(easy3)
    {
        xx1+=.2;
        if(xx1>=-80 || tt1)
        {
            xx2+=.2;
        }
        if(xx2>=-80 ||tt2)
        {
            xx3+=.2;
        }
        if(xx3>=-80 ||tt3)
        {
            xx4+=.2;
        }
        if(xx4>=-80 ||tt4)
        {
            xx5+=.2;
        }
        if(xx5>=-80 ||tt5)
        {
            xx6+=.2;
        }
        if(xx2>=70)
        {
            xx2=-110;
            tt2=1;
        }
        if(xx3>=70)
        {
            xx3=-110;
            tt3=1;
        }
        if(xx4>=70)
        {
            xx4=-110;
            tt4=1;
        }
        if(xx5>=70)
        {
            xx5=-110;
            tt5=1;
        }
        if(xx6>=70)
        {
            xx6=-110;
        }
        if(xx1>=70)
        {
            xx1=-110;
            tt1=1;
        }
    }
    else
    {
        xx1=-110.0, xx2=-110.0, xx3=-110.0, xx4=-110.0, xx5=-110.0,xx6=-110.0;
        tt1=0,tt2=0,tt3=0,tt4=0,tt5=0;
    }

    if (Rotate == true)
    {
        angle += 0.05;
        if(angle > 360.0)
            angle =0.0;
    }
    if (uRotate == true)
    {
        angle += 0.05;
        if(angle > 360.0)
            angle =0.0;
    }
    if(temp0)
        sx+=.18;
    else
        sx-=.18;
    if(sx<-115)
    {
        sx+=.18;
        temp0=1;
    }
    else if(sx>-15)
    {
        sx-=.18;
        temp0=0;
    }
    if(temp1)
        ux+=.1;
    else
        ux-=.1;
    if(ux<-60)
    {
        ux+=.1;
        temp1=1;
    }
    else if(ux>60)
    {
        ux-=.1;
        temp1=0;
    }
    if(temp4)
        cx+=.03;
    else
        cx-=.03;
    if(cx<-6)
    {
        cx+=.03;
        temp4=1;
    }
    else if(cx>6)
    {
        cx-=.03;
        temp4=0;
    }
    tartheta+=1.5;
    if(tartheta>=360)
        tartheta =0.0;
    xxx+=1;

    glutPostRedisplay();
}
void LoadTexture(const char*filename, GLuint s)
{
    glGenTextures(1, &s);
    glBindTexture(GL_TEXTURE_2D, s);
    glPixelStorei(GL_UNPACK_ALIGNMENT, s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}

int main (int argc, char **argv)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    cout<<"Press + to Zoom in and - to Zoom out"<<endl;
    cout<<endl;
    cout<<"Press r to rotate clockwise and r again to stop rotating"<<endl;
    cout<<endl;
    cout<<"Press t to rotate anticlockwise and t again to stop rotating"<<endl;
    cout<<endl;
    cout<<"Press u to rotate upside down and u again to stop rotating"<<endl;
    cout<<endl;
    cout<<"Press 1 to turn off the light1(right) and 1 again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press 2 to turn off the light2(left) and 2 again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press ! to turn off the light3(back) and ! again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press 3 to turn off the spotlight(up) and 3 again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press e to turn off the diffuse light of light1(right) and e again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press w to turn off the specular light of light1(right) and w again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press q to turn off the ambient light of light1(right) and q again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press d to turn off the diffuse light of light2(left) and d again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press s to turn off the specular light of light2(left) and s again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press a to turn off the ambient light of light2(left) and a again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press c to turn off the diffuse light of spotlight(up) and c again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press x to turn off the specular light of spotlight(up) and x again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press z to turn off the ambient light of spotlight(up) and z again to turn it on"<<endl;
    cout<<endl;
    cout<<"Press v to increase the angle of the cutoff of the spot light and b to decrease it"<<endl;
    cout<<endl;
    cout<<"Press G to turn on the gun game mode"<<endl;
    cout<<endl;
    cout<<"Press A to turn on the arrow game mode"<<endl;
    cout<<endl;
    cout<<"Press B to turn on the basic mode"<<endl;
    cout<<endl;
    cout<<"Press E to turn on the Easy mode"<<endl;
    cout<<endl;
    cout<<"Press N to turn on the Normal mode"<<endl;
    cout<<endl;
    cout<<"Press H to turn on the Hard mode"<<endl;
    cout<<endl;
    cout<<"Press W to turn on the Extreme mode"<<endl;
    cout<<endl;
    cout<<"Press S to turn on the sunny game weather mode"<<endl;
    cout<<endl;
    cout<<"Press W to turn on the winter game weather mode"<<endl;
    cout<<endl;
    cout<<"Click left button of mouse to fire"<<endl;
    cout<<endl;
    cout<<"Click middle button of mouse to reload"<<endl;
    cout<<endl;
    cout<<"Click and hold right button of mouse to change the view form"<<endl;
    cout<<endl;
    cout<<"Press P to see the control points of the curves "<<endl;
    cout<<endl;
    cout<<"Press X to go for editing the view mode"<<endl;
    cout<<endl;
    cout<<"Press N to play with normal viewing mode"<<endl;
    cout<<endl;
    cout<<"Press Z to play with zoom viewing mode"<<endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("1607066");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );

    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\wall.bmp",wall);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\side.bmp",sidewall1);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\ceil3.bmp",ceilbmp);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\floor.bmp",field);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\target2.bmp",target);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\10.bmp",ten);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\9.bmp",nine);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\8.bmp",eight);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\7.bmp",seven);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\6.bmp",six);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\5.bmp",five);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\ten.bmp",uten);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\sceil.bmp",sceilbmp);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\swall.bmp",swall);
    LoadTexture("D:\\E\\4-2\\Graphics lab\\Graphics project\\sfloor.bmp",sfield);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}
