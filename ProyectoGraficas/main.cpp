// primitives_glu_main.cpp
// Cilindro
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <iostream>
#include <list>
#include <cmath>
using namespace std;

// Tamao de la ventana
GLint width = 900;
GLint height = 800;

// Parmetros de la cmara virtual
//Modificar este para poder cambair la cantidad de sillas
//Las sillas son por lado es decir si se pone 4 son 4 silas de un lado mas las 4 del otro harian 8
//Esfera solid

//Editor de colores
float color1 = 0;
float color2 = 0;
float color3 = 1;


//Main Window
int mainWindow;

//Button Window
//Linea 1
int sphereWindow;
int coneWindow;
//Linea 2
int cubeWindow;
int boxWindow;
//Linea 3
int tousWindow;
int tetraWindow;
//Linea 4
int octaWindow;
int dodeWindow;
//Linea 5
int icosWindow;
int teaWindow;
//Linea 6
int cylWindow;
int discWindow;
//Linea 7
int pointWindow;
int lineWindow;
//Linea 8
int trianWindow;
int quadWindow;
//Linea 9
int pyraWindow;


//Items
int itemOrder[500];
//Escalar
GLfloat scale[500];

//Rotan
GLfloat rotate_y[500];
GLfloat rotate_x[500];

//Transladan
GLfloat panX[500];
GLfloat panY[500];
GLfloat zoomZ[500];

//Current Value
int current = 0;
//Latest Value
int latest = 1;
//Variable que modifica
static int value = 0;

GLint mouseButton = 0;
GLboolean mouseRotate = false;
GLboolean mouseZoom = false;
GLboolean mousePan = false;
GLint xClick = 0;
GLint yClick = 0;
GLint xAux = 0;
GLint yAux = 0;



// Funcin que inicializa el Contexto OpenGL y la geometra de la escena
void init() {
    glClearColor(0, 0, 0, 0);
    glColor3f(1.f, 1.f, 1.f);
}

// Funcin que se invoca cada vez que se redimensiona la ventana
void resize(GLint w, GLint h)
{
    if (h == 0)
    {
        h = 1;
    }
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25.f, (float)width / height, 0.1f, 1000.f);  // Transf. de Proyeccin en Perspectiva
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);        // Transf. de Viewport (mapeo al rea de dibujo)
}

void resizeButtons(GLint w, GLint h)
{
    if (h == 0)
    {
        h = 1;
    }
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25.f, (float)width / height, 0.1f, 30.f);  // Transf. de Proyeccin en Perspectiva
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);        // Transf. de Viewport (mapeo al rea de dibujo)
}

// Geometra sistema coordenado
void geomCoordSys(GLfloat size)
{
    // Eje X (Rojo)
    glColor3f(1., 0., 0.);
    glBegin(GL_LINES);
    glVertex3f(0., 0., 0.);
    glVertex3f(size, 0., 0.);
    glEnd();
    
    // Eje Y (Verde))
    glColor3f(0., 1., 0.);
    glBegin(GL_LINES);
    glVertex3f(0., 0., 0.);
    glVertex3f(0., size, 0.);
    glEnd();
    
    // Eje Z (Azul)
    glColor3f(0., 0., 1.);
    glBegin(GL_LINES);
    glVertex3f(0., 0., 0.);
    glVertex3f(0., 0., size);
    glEnd();
    glColor3f(1., 1., 1.);
}

/////////////////////////////
/*LAS GEOM PARA LOS BOTONES*/
/////////////////////////////
//Wired Sphere
void renderWiredSphereButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value] + 2, scale[value] + 2, scale[value] + 2);
    glScaled(.1, .1, .1);
    glutWireSphere(.5, 10, 10);
    glPopMatrix();
    glutSwapBuffers();
}

//Wired Cone
void renderWiredConeButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value] + 2, scale[value] + 2, scale[value] + 2);
    glScaled(.025, .025, .025);
    glRotated(80, -1.0, 0.0, 0.0);
    glutWireCone(1,2.0, 10, 10);
    glPopMatrix();
    glutSwapBuffers();
}




//Wired Cubo
void renderWiredCubeButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.1, .1, .1);
    glutWireCube(1);
    glPopMatrix();
    glutSwapBuffers();
}

//Wired Torus
void renderWiredTousButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.05, .05, .05);
    glutWireTorus(0.8,1.6,10,10);
    glPopMatrix();
    glutSwapBuffers();
}

//Wired Tetahedro
void renderWiredTetrahedronButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.1, .1, .1);
    glutWireTetrahedron();
    glPopMatrix();
    glutSwapBuffers();
}

//Wired Octahedro
void renderWiredOctahedronButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.1, .1, .1);
    glutWireOctahedron();
    glPopMatrix();
    glutSwapBuffers();
}
//Wired Dodecahedro
void renderWiredDodecahedronButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.05, .05, .05);
    glutWireDodecahedron();
    glPopMatrix();
    glutSwapBuffers();
}

//Wired Icosahedro
void renderWiredIcosahedronButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.05, .05, .05);
    glutWireIcosahedron();
    glPopMatrix();
    glutSwapBuffers();
}

//Wired Teapod
void renderWiredTeapodButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.1, .1, .1);
    glutWireTeapot(1);
    glPopMatrix();
    glutSwapBuffers();
}

//Cylinder
void renderWiredCylinderButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glRotated(80, -1.0, 0.0, 0.0);
    glScaled(.1, .1, .1);
    glTranslatef(0.f, 0.f, -.7f);
    gluCylinder(gluNewQuadric(), .6, .6, 5, 10, 10);
    glPopMatrix();
    glutSwapBuffers();
}

//Disc
void renderWiredDiskButton(int value) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.1, .1, .1);
    gluDisk(gluNewQuadric(), .0, .6, 10, 1);
    glPopMatrix();
    glutSwapBuffers();
}

//Point
void renderWiredPointButton(int value) {
    float size = .5f;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glLineWidth(1000);
    
    glBegin(GL_POINTS);
    glVertex3f(0.f,0.f, 0.f);
    glEnd();
    glScaled(10, 10, 10);
    glPopMatrix();
    glutSwapBuffers();
    
}

//Line
void renderWiredLineButton(int value) {
    float size = .5f;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.1, .1, .1);
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(10, 0, 0);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    
}


//Triangle
void renderWiredTriangleButton(int value) {
    float size = .5f;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.1, .1, .1);
    glBegin(GL_TRIANGLES);
    glVertex3f(-size, -size, 0.f);
    glVertex3f(size, -size, 0.f);
    glVertex3f(size, size, 0.f);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    
}
//Quad
void renderWiredQuadButton(int value) {
    float size = .5f;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.1, .1, .1);
    glBegin(GL_TRIANGLES);
    glVertex3f(-size, -size, 0.f);
    glVertex3f(size, -size, 0.f);
    glVertex3f(size, size, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-size, -size, 0.f);
    glVertex3f(size, size, 0.f);
    glVertex3f(-size, size, 0.f);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    
}

//Pyramid
void renderWiredPyramidButton(int value) {
    float size = .5f;
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPushMatrix();
    glColor3f(color1, color2, color3);
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScaled(.1, .1, .1);
    glPushMatrix();
    glTranslatef(0.f, -.5f, .0f);
    glPushMatrix();
    glPopMatrix();
    glBegin(GL_TRIANGLES);//frente
    glVertex3f(-0.5f, 0.f, 0.5f);
    glVertex3f(0.5f, 0.f, 0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);//derecha
    glVertex3f(0.5f, 0.f, 0.5f);
    glVertex3f(0.5f, 0.f, -0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);//atras
    glVertex3f(0.5f, 0.f, -0.5f);
    glVertex3f(-0.5f, 0.f, -0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);//izquierda
    glVertex3f(-0.5f, 0.f, -0.5f);
    glVertex3f(-0.5f, 0.f, 0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();

    
}



///////////////////////////
/*TODOS LAS GEOM NORMALES*/
///////////////////////////

//Esfera solida
void renderSolidSphere(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutSolidSphere(1, 25, 25);
    glPopMatrix();
}
//Esfera wired
void renderWiredSphere(int value, bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutWireSphere(1, 25, 25);
    glPopMatrix();
}

//Cono solido
void renderSolidCone(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glRotated(80, -1.0, 0.0, 0.0);
    glutSolidCone(2,3.0, 50, 50);
    glPopMatrix();

}

//Cono wired
void renderWiredCone(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glRotated(80, -1.0, 0.0, 0.0);
    glutWireCone(2,3.0, 50, 50);
    glPopMatrix();
}


//Cubo Solid
void renderSolidCube(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutSolidCube(2);
    glPopMatrix();
}
//Cubo wired
void renderWiredCube(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutWireCube(2);
    glPopMatrix();

    
}

//Toroide solido
void renderSolidTorus(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutSolidTorus(0.8,1.6,100,100);
    glPopMatrix();
}

//Toroide wired
void renderWiredTorus(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutWireTorus(0.8,1.6,100,100);
    glPopMatrix();
}

//Tetahedro solido
void renderSolidTetrahedron(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutSolidTetrahedron();
    glPopMatrix();
}

//Tetahedro wired
void renderWiredTetrahedron(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutWireTetrahedron();
    glPopMatrix();
}



//Octahedro solido
void renderSolidOctahedron(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutSolidOctahedron();
    glPopMatrix();
    
}

//Octahedro wired
void renderWiredOctahedron(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutWireOctahedron();
    glPopMatrix();
}

//Dodecahedro solid
void renderSolidDodecahedron(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutSolidDodecahedron();
    glPopMatrix();
}
//Dodecahedro wired
void renderWiredDodecahedron(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutWireDodecahedron();
    glPopMatrix();
}

//Icosahedro solid
void renderSolidIcosahedron(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutSolidIcosahedron();
    glPopMatrix();
}

//Icosahedro wired
void renderWiredIcosahedron(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutWireIcosahedron();
    glPopMatrix();
}


//Tetera solid
void renderSolidTeapod(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutSolidTeapot(1);
    glPopMatrix();
}

//Tetera wired
void renderWiredTeapod(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glutWireTeapot(1);
    glPopMatrix();
}

//Cilindro solid
void renderSolidCylinder(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glRotated(80, -1.0, 0.0, 0.0);
    gluCylinder(gluNewQuadric(), .6, .6, 5, 10, 10);
    glPopMatrix();
}

//Cilindro wire
void renderWiredCylinder(int value,bool color){
    renderSolidCylinder(value,color);
}

//Disco wire
void renderWiredDisk(int value,bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    gluDisk(gluNewQuadric(), .0, .6, 10, 1);
    glPopMatrix();
}

//Disco solido
void renderSolidDisk(int value,bool color){
    renderWiredDisk(value,color);
}

//Point wired
void renderWiredPoint(int value, bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glBegin(GL_POINTS);
    glVertex3f(0.f,0.f, 0.f);
    glEnd();
    glScaled(10, 10, 10);
    glPopMatrix();
    glPopMatrix();
}

//Point wired
void renderSolidPoint(int value, bool color){
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glBegin(GL_POINTS);
    glVertex3f(0.f,0.f, 0.f);
    glEnd();
    glScaled(10, 10, 10);
    glPopMatrix();
    glPopMatrix();
}

//Linea solida
void renderSolidLine(int value,bool color){
    float size = 1/2.f;
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(10, 0, 0);
    glEnd();
    glPopMatrix();}

//Linea wired
void renderWireLine(int value, bool color){
    renderSolidLine(value, color);
}


//Triangulo linea
void renderWireTriangle(int value,bool color){
    float size = 1/2.f;
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glBegin(GL_TRIANGLES);
    glVertex3f(-size, -size, 0.f);
    glVertex3f(size, -size, 0.f);
    glVertex3f(size, size, 0.f);
    glEnd();
    glPopMatrix();
}

//Triangulo solido
void renderSolidTriangle(int value,bool color){
    float size = 1/2.f;
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glBegin(GL_TRIANGLES);
    glVertex3f(-size, -size, 0.f);
    glVertex3f(size, -size, 0.f);
    glVertex3f(size, size, 0.f);
    glEnd();
    glPopMatrix();
}

//Geometria Quad solida
void enderSolidQuad(int value, bool color){
    float size = 1/2.f;
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glBegin(GL_TRIANGLES);
    glVertex3f(-size, -size, 0.f);
    glVertex3f(size, -size, 0.f);
    glVertex3f(size, size, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-size, -size, 0.f);
    glVertex3f(size, size, 0.f);
    glVertex3f(-size, size, 0.f);
    glEnd();
}
//Geometria Quad wired
void renderWiredQuad(int value, bool color){
    float size = 1/2.f;
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glBegin(GL_TRIANGLES);
    glVertex3f(-size, -size, 0.f);
    glVertex3f(size, -size, 0.f);
    glVertex3f(size, size, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-size, -size, 0.f);
    glVertex3f(size, size, 0.f);
    glVertex3f(-size, size, 0.f);
    glEnd();
}

//Geometria Pyramid wired
void renderWiredPyramid(int value, bool color){
    float size = 1/2.f;
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);
    glPushMatrix();
    glPopMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5f, 0.f, 0.5f);
    glVertex3f(0.5f, 0.f, 0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5f, 0.f, 0.5f);
    glVertex3f(0.5f, 0.f, -0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5f, 0.f, -0.5f);
    glVertex3f(-0.5f, 0.f, -0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5f, 0.f, -0.5f);
    glVertex3f(-0.5f, 0.f, 0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glPopMatrix();
    
    glPopMatrix();
    glEnd();
}

//Geometria Pyramid wired
void renderSolidPyramid(int value, bool color){
    float size = 1/2.f;
    if (color) {
        glColor3f(0, 1, 1);
    }
    else {
        glColor3f(color1, color2, color3);
    }
    glPolygonMode(GL_FRONT, GL_FILL);
    glPushMatrix();
    glTranslatef(panX[value], panY[value], zoomZ[value] - 0.5f);
    glRotatef(rotate_x[value], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[value], 0.0, 1.0, 0.0);
    glScalef(scale[value]+2, scale[value] + 2, scale[value] + 2);glPopMatrix();
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5f, 0.f, 0.5f);
    glVertex3f(0.5f, 0.f, 0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5f, 0.f, 0.5f);
    glVertex3f(0.5f, 0.f, -0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5f, 0.f, -0.5f);
    glVertex3f(-0.5f, 0.f, -0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5f, 0.f, -0.5f);
    glVertex3f(-0.5f, 0.f, 0.5f);
    glVertex3f(0.f, 1.0f, 0.f);
    glEnd();
    glPopMatrix();
    
    glPopMatrix();
    glEnd();
}

//Estos son los displays ligados a cada unas de las nuevas ventanas
void displaySphereButton() {
    renderWiredSphereButton(0);
}
void displayConeButton() {
    renderWiredConeButton(0);
}
void displayCubeButton() {
    renderWiredCubeButton(0);
}
void displayTousButton() {
    renderWiredTousButton(0);
}
void displayTetraButton() {
    renderWiredTetrahedronButton(0);
}
void displayOctaButton() {
    renderWiredOctahedronButton(0);
}
void displayDodeButton() {
    renderWiredDodecahedronButton(0);
}
void displayIcosaButton() {
    renderWiredIcosahedronButton(0);
}
void displayTeaButton() {
    renderWiredTeapodButton(0);
}
void displayCylinButton() {
    renderWiredCylinderButton(0);
}
void displayDiskButton() {
    renderWiredDiskButton(0);
}
void displayPointButton() {
    renderWiredPointButton(0);
}
void displayLineButton() {
    renderWiredLineButton(0);
}
void displayTriangleButton() {
    renderWiredTriangleButton(0);
}
void displayQuadButton() {
    renderWiredQuadButton(0);
}
void displayPyramidButton() {
    renderWiredPyramidButton(0);
}


// Funcin que se invoca cada vez que se dibuja
void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(panX[0], panY[0], zoomZ[0]);
    glRotatef(rotate_x[0], 1.0, 0.0, 0.0);
    glRotatef(rotate_y[0], 0.0, 1.0, 0.0);
    geomCoordSys(2.f);
    bool activo = false;
    //Aqui recorremos el arreglo de figuras para crearlas
    for (size_t i = 0; i < latest; i+=2) {
        if (itemOrder[i] == 1) {
            if (current == i) {
                activo = true;
                renderWiredSphere(i, activo);
                activo = false;
            }
            else{
                renderWiredSphere(i, activo);
            }
        }
        else if (itemOrder[i] == 2) {
            if (current == i) {
                activo = true;
                renderWiredCone(i, activo);
                activo = false;
            }
            else{
                renderWiredCone(i, activo);
            }
        }
        else if (itemOrder[i] == 3) {
            if (current == i) {
                activo = true;
                renderWiredCube(i, activo);
                activo = false;
            }
            else{
                renderWiredCube(i, activo);
            }
        }
        else if (itemOrder[i] == 4) {
            if (current == i) {
                activo = true;
                renderWiredCube(i, activo);
                activo = false;
            }
            else{
                renderWiredCube(i, activo);
            }
        }
        else if (itemOrder[i] == 5) {
            if (current == i) {
                activo = true;
                renderWiredTorus(i, activo);
                activo = false;
            }
            else{
                renderWiredTorus(i, activo);
            }
        }
        else if (itemOrder[i] == 6) {
            if (current == i) {
                activo = true;
                renderWiredTetrahedron(i, activo);
                activo = false;
            }
            else{
                renderWiredTetrahedron(i, activo);
            }
        }
        else if (itemOrder[i] == 7) {
            if (current == i) {
                activo = true;
                renderWiredOctahedron(i, activo);
                activo = false;
            }
            else{
                renderWiredOctahedron(i, activo);
            }
        }
        else if (itemOrder[i] == 8) {
            if (current == i) {
                activo = true;
                renderWiredDodecahedron(i, activo);
                activo = false;
            }
            else{
                renderWiredDodecahedron(i, activo);
            }
        }
        else if (itemOrder[i] == 9) {
            if (current == i) {
                activo = true;
                renderWiredIcosahedron(i, activo);
                activo = false;
            }
            else{
                renderWiredIcosahedron(i, activo);
            }
        }
        else if (itemOrder[i] == 10) {
            if (current == i) {
                activo = true;
                renderWiredTeapod(i, activo);
                activo = false;
            }
            else{
                renderWiredTeapod(i, activo);
            }
        }
        else if (itemOrder[i] == 11) {
            if (current == i) {
                activo = true;
                renderWiredCylinder(i, activo);
                activo = false;
            }
            else{
                renderWiredCylinder(i, activo);
            }
        }
        else if (itemOrder[i] == 12) {
            if (current == i) {
                activo = true;
                renderWiredDisk(i, activo);
                activo = false;
            }
            else{
                renderWiredDisk(i, activo);
            }
        }
        else if (itemOrder[i] == 13) {
            if (current == i) {
                activo = true;
                renderWiredPoint(i, activo);
                activo = false;
            }
            else{
                renderWiredPoint(i, activo);
            }
        }
        else if (itemOrder[i] == 14) {
            if (current == i) {
                activo = true;
                renderWireLine(i, activo);
                activo = false;
            }
            else{
                renderWireLine(i, activo);
            }
        }
        else if (itemOrder[i] == 15) {
            if (current == i) {
                activo = true;
                renderWireTriangle(i, activo);
                activo = false;
            }
            else{
                renderWireTriangle(i, activo);
            }
        }
        else if (itemOrder[i] == 16) {
            if (current == i) {
                activo = true;
                renderWiredQuad(i, activo);
                activo = false;
            }
            else{
                renderWiredQuad(i, activo);
            }
        }
        else if (itemOrder[i] == 17) {
            if (current == i) {
                activo = true;
                renderWiredPyramid(i, activo);
                activo = false;
            }
            else{
                renderWiredPyramid(i, activo);
            }
        }else if (itemOrder[i] == 100) {
            if (current == i) {
                activo = true;
                renderSolidSphere(i, activo);
                activo = false;
            }
            else{
                renderSolidSphere(i, activo);
            }
        }else if (itemOrder[i] ==200) {
            if (current == i) {
                activo = true;
                renderSolidCone(i, activo);
                activo = false;
            }
            else{
                renderSolidCone(i, activo);
            }
        }else if (itemOrder[i] == 300) {
            if (current == i) {
                activo = true;
                renderSolidCube(i, activo);
                activo = false;
            }
            else{
                renderSolidCube(i, activo);
            }
        }else if (itemOrder[i] == 400) {
            if (current == i) {
                activo = true;
                renderSolidCube(i, activo);
                activo = false;
            }
            else{
                renderSolidCube(i, activo);
            }
        }else if (itemOrder[i] == 500) {
            if (current == i) {
                activo = true;
                renderSolidTorus(i, activo);
                activo = false;
            }
            else{
                renderSolidTorus(i, activo);
            }
        }else if (itemOrder[i] == 600) {
            if (current == i) {
                activo = true;
                renderSolidTetrahedron(i, activo);
                activo = false;
            }
            else{
                renderSolidTetrahedron(i, activo);
            }
        }else if (itemOrder[i] == 700) {
            if (current == i) {
                activo = true;
                renderSolidOctahedron(i, activo);
                activo = false;
            }
            else{
                renderSolidOctahedron(i, activo);
            }
        }else if (itemOrder[i] == 800) {
            if (current == i) {
                activo = true;
                renderSolidDodecahedron(i, activo);
                activo = false;
            }
            else{
                renderSolidDodecahedron(i, activo);
            }
        }else if (itemOrder[i] == 900) {
            if (current == i) {
                activo = true;
                renderSolidIcosahedron(i, activo);
                activo = false;
            }
            else{
                renderSolidIcosahedron(i, activo);
            }
        }else if (itemOrder[i] == 1000) {
            if (current == i) {
                activo = true;
                renderSolidTeapod(i, activo);
                activo = false;
            }
            else{
                renderSolidTeapod(i, activo);
            }
        }else if (itemOrder[i] == 1100) {
            if (current == i) {
                activo = true;
                renderSolidCylinder(i, activo);
                activo = false;
            }
            else{
                renderSolidCylinder(i, activo);
            }
        }else if (itemOrder[i] == 1200) {
            if (current == i) {
                activo = true;
                renderSolidDisk(i, activo);
                activo = false;
            }
            else{
                renderSolidDisk(i, activo);
            }
        }else if (itemOrder[i] == 1300) {
            if (current == i) {
                activo = true;
                renderSolidPoint(i, activo);
                activo = false;
            }
            else{
                renderSolidPoint(i, activo);
            }
        }else if (itemOrder[i] == 1400) {
            if (current == i) {
                activo = true;
                renderSolidLine(i, activo);
                activo = false;
            }
            else{
                renderSolidLine(i, activo);
            }
        }else if (itemOrder[i] == 1500) {
            if (current == i) {
                activo = true;
                renderSolidTriangle(i, activo);
                activo = false;
            }
            else{
                renderSolidTriangle(i, activo);
            }
        }else if (itemOrder[i] == 1600) {
            if (current == i) {
                activo = true;
                enderSolidQuad(i, activo);
                activo = false;
            }
            else{
                enderSolidQuad(i, activo);
            }
        }else if (itemOrder[i] == 1700) {
            if (current == i) {
                activo = true;
                renderSolidPyramid(i, activo);
                activo = false;
            }
            else{
                renderSolidPyramid(i, activo);
            }
        }
        
        
    }
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    mouseButton = button;
    mouseRotate = false;
    mouseZoom = false;
    mousePan = false;
    xClick = x;
    yClick = y;
    if (button == GLUT_RIGHT_BUTTON)
    {
        mouseZoom = true;
        xAux = zoomZ[current];
    }
    else if (button == GLUT_MIDDLE_BUTTON)
    {
        mousePan = true;
        xAux = panX[current];
        yAux = panY[current];
    }
}

//Las funciones que se encargan de que cuando le damos click izquierdo a la ventana
//Esta funcion crea la instancia correspondiente

//Esta es la esfera
void sphereMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 1;
        latest++;
    }
}
//Esta es del cono
void coneMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 2;
        latest++;
    }
}
//Esta es la del cubo
void cubeMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 3;
        latest++;
    }
}
//Esta es la de la caja
/*void cubeMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 4;
        latest++;
    }
}*/
//Esta es la del Toroide
void tousMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 5;
        latest++;
    }
}
//Esta es la del Tetrahedro
void tetraMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 6;
        latest++;
    }
}
//Esta es la del Octahedro
void octaMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 7;
        latest++;
    }
}
//Esta es la del Dodecahedro
void dodeMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 8;
        latest++;
    }
}
//Esta es la del Icosahedro
void icosaMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 9;
        latest++;
    }
}
//Esta es la del Tetera
void teaMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 10;
        latest++;
    }
}
//Esta es la del Cilindro
void ciliMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 11;
        latest++;
    }
}
//Esta es la del Disco
void diskMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 12;
        latest++;
    }
}

//Esta es la del punto
void pointMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 13;
        latest++;
    }
}
//Esta es la de la linea
void lineMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 14;
        latest++;
    }
}
//Esta es la del Triangulo
void triangleMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 15;
        latest++;
    }
}
//Esta es la del Cuadrado
void quadMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 16;
        latest++;
    }
}
//Esta es la de la Piramide
void pyradMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        itemOrder[latest] = 17;
        latest++;
    }
}




//Traslada
//Con el boton del centro del mouse y con el boton derecho
void mouseMotion(int x, int y)
{
    if (mouseZoom == true)
    {
        if (mouseButton == GLUT_RIGHT_BUTTON)
        {
            zoomZ[current] = ((x - xClick) / 10.0) + xAux;
        }
    }
    else if (mousePan == true)
    {
        if (mouseButton == GLUT_MIDDLE_BUTTON)
        {
            panX[current] = ((x - xClick) / 63.0) + xAux;
            panY[current] = ((y - yClick) / (-63.0)) + yAux;
        }
    }
    glutPostRedisplay();
}



//Esta funcion se encarga de rotar y escalar
//Rota con las flechas
//Escala con F1 y F2
//////////////
//IMPORTANTE//
//////////////
//Para cambiar de figura, se usa F3 y F4
//De esta manera elegimos que figura queremos modificar
void rotateKeys(int key, int x, int y) {
    
    //  Flecha derecha: aumentar rotación 5 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y[current] += 5;
    
    //  Flecha izquierda: disminuir rotación 5 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y[current] -= 5;
    
    else if (key == GLUT_KEY_UP)
        rotate_x[current] += 5;
    
    else if (key == GLUT_KEY_DOWN)
        rotate_x[current] -= 5;
    
    else if (key == GLUT_KEY_F1)
        scale[current] += 0.2;
    
    else if (key == GLUT_KEY_F2)
        scale[current] -= 0.2;
    
    else if (key == GLUT_KEY_F3){
        current+=2;
        cout<< current<< endl;
    }
    else if (key == GLUT_KEY_F4){
        current-=2;
    }
    
    //  Flecha derecha: aumentar rotación 5 grados
    else if (key == GLUT_KEY_F5) {
        current = 0;
        for (size_t i = 1; i < latest; i++) {
            //Items
            itemOrder[i] = 0;
            //Escalar
            scale[i] = 0;
            
            //Rotan
            rotate_y[i] = 0;
            rotate_x[i] = 0;
            
            //Transladan
            panX[i] = 0;
            panY[i] = 0;
            zoomZ[i] = 0;
        }
        latest = 1;
        value = 0;
    }
    else if (key == GLUT_KEY_F6){
        if (itemOrder[current] < 100) {
            itemOrder[current] *= 100;
        }
    }
    else if (key == GLUT_KEY_F7) {
        if (itemOrder[current] > 99) {
            itemOrder[current] /= 100;
        }
    }
    glutPostRedisplay();
    
}

int main(GLint argc, GLchar **argv)
{
    // 1. Se crea una ventana y un contexto OpenGL usando GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    mainWindow = glutCreateWindow("Primitivas de OpenGL");
    
    
    
    // 1.2 Se definen las funciones callback para el manejo de eventos
    glutReshapeFunc(resize);
    glutDisplayFunc(render);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutSpecialFunc(rotateKeys);
    

    // 3. Se inicializa el contexto de OpenGL y la geometra de la escena
    init();
    
    
    ////////////////////////
    //AQUI INICIAN BOTONES//
    ////////////////////////
    
    //Esfera
    //Se crea la ventana, parametros es mainWindow, pos de inicio en x, posicion de inicio en y, ancho y largo
    sphereWindow = glutCreateSubWindow(mainWindow, 10, 10, width - (width*0.9), height - (height*0.9));
    //Es un resize pero para los botones
    glutReshapeFunc(resizeButtons);
    //La funcion del mouse asignada, como es cubo le asignamos la del cubo
    glutMouseFunc(sphereMouseClick);
    //Display cube button es una funcion que despliega el cubo
    glutDisplayFunc(displaySphereButton);
    init();
    
    
    //Se crea la ventana, parametros es mainWindow, pos de inicio en x, posicion de inicio en y, ancho y largo
    coneWindow = glutCreateSubWindow(mainWindow, width - (width*0.9) + 12, 10, width - (width*0.9), height - (height*0.9));
    //Es un resize pero para los botones
    glutReshapeFunc(resizeButtons);
    //La funcion del mouse asignada, como es Tetrahedro le asignamos la del Tetrahedro
    glutMouseFunc(coneMouseClick);
    //Display Tetahedro button es una funcion que despliega el Tetrahedro
    glutDisplayFunc(displayConeButton);
    init();
    
    
    cubeWindow = glutCreateSubWindow(mainWindow, 10, height - (height*0.9) + 12, width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(cubeMouseClick);
    glutDisplayFunc(displayCubeButton);
    init();
    
    boxWindow = glutCreateSubWindow(mainWindow, width - (width*0.9) + 12, height - (height*0.9) + 12, width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(cubeMouseClick);
    glutDisplayFunc(displayCubeButton);
    init();
    
    tousWindow = glutCreateSubWindow(mainWindow, 10, 2*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(tousMouseClick);
    glutDisplayFunc(displayTousButton);
    init();
    
    tetraWindow = glutCreateSubWindow(mainWindow, width - (width*0.9) + 12,  2*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(tetraMouseClick);
    glutDisplayFunc(displayTetraButton);
    init();
    
    octaWindow = glutCreateSubWindow(mainWindow, 10,  3*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(octaMouseClick);
    glutDisplayFunc(displayOctaButton);
    init();

    dodeWindow = glutCreateSubWindow(mainWindow, width - (width*0.9) + 12,  3*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(dodeMouseClick);
    glutDisplayFunc(displayDodeButton);
    init();
    
    icosWindow = glutCreateSubWindow(mainWindow, 10,  4*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(icosaMouseClick);
    glutDisplayFunc(displayIcosaButton);
    init();
    
    teaWindow = glutCreateSubWindow(mainWindow, width - (width*0.9) + 12,  4*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(teaMouseClick);
    glutDisplayFunc(displayTeaButton);
    init();
    
    cylWindow = glutCreateSubWindow(mainWindow, 10,  5*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(ciliMouseClick);
    glutDisplayFunc(displayCylinButton);
    init();
    
    discWindow = glutCreateSubWindow(mainWindow, width - (width*0.9) + 12,  5*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(diskMouseClick);
    glutDisplayFunc(displayDiskButton);
    init();
    
    pointWindow = glutCreateSubWindow(mainWindow, 10,  6*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(pointMouseClick);
    glutDisplayFunc(displayPointButton);
    init();
    
    lineWindow = glutCreateSubWindow(mainWindow, width - (width*0.9) + 12,  6*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(lineMouseClick);
    glutDisplayFunc(displayLineButton);
    init();
    
    trianWindow = glutCreateSubWindow(mainWindow, 10,  7*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(triangleMouseClick);
    glutDisplayFunc(displayTriangleButton);
    init();
    
    quadWindow = glutCreateSubWindow(mainWindow, width - (width*0.9) + 12,  7*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(quadMouseClick);
    glutDisplayFunc(displayQuadButton);
    init();
    
    pyraWindow = glutCreateSubWindow(mainWindow, 2*(width - (width*0.9) + 12),  7*(height - (height*0.9) + 12), width - (width*0.9), height - (height*0.9));
    glutReshapeFunc(resizeButtons);
    glutMouseFunc(pyradMouseClick);
    glutDisplayFunc(displayPyramidButton);
    init();
    
    
    // 4. Se inicia el ciclo de escucha de eventos
    glutMainLoop();
    return 0;
}
