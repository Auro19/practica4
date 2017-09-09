
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Meneses Cornejo Kevin Osmar				******//
//*************	Reyes Aragon Aurora						******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0;
float transY = 0.0;
float angle = 0.0;
int screenW = 0.0;
int screenH = 0.0;



void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			//glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		glTranslatef(0.0f, 0.0f, transZ);
		glTranslatef(transX, 0.0f, 0.0);
		glTranslatef(0.0f, transY, 0.0);
		glRotatef(angle*50, 0.0, 1.0, 0.0);
		//Poner Código Aquí.
		//glRotatef(transZ, 0.0, 0.0, 0.5); //Rotacion, se coloca el angulo en el que se quiere rotar, al agregar el transZ gira sobre su propio eje
		//glScalef(1.0, 4.0, 3.0); // Para escalar el objeto 
		/*
		glTranslatef(1.0, 0.0, 0.0); 
		glPushMatrix();  //aisla 
			
			glScalef(1.0, 4.0, 3.0);
			glTranslatef(-2.0, 0.0, 0.0); //Mover para colocar otro prisma 
			prisma();
		glPopMatrix();
		glRotatef(50*transZ, 0.0, 0.0, 0.5);
		glScalef(1.0, 4.0, 3.0);

		
		prisma();
		*/

		//monito
		glPushMatrix();
		//cabeza
			glPushMatrix();
			glColor3f(0.0, 1.0, 0.0);
			prisma(); //0,0,0
		glPopMatrix();	

		//Cuello
			glPushMatrix();
				glTranslatef(0.0, -0.75, 0);
				glScalef(0.5,0.5,1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//torso
		glPushMatrix();
			glTranslatef(0.0, -2.5, 0.0);
			glScalef(3.0,3.0,1.0);
			glColor3f(0.0, 0.0, 1.0);
			prisma();
		glPopMatrix();

		//brazo derecho
		glPushMatrix();
		glTranslatef(-3.0, -1.5, 0.0);
		glScalef(3.0, 1.0, 1.0);
		glColor3f(0.0, 0.0, 1.0);
		prisma();
		glPopMatrix();

		//mano derecho
		glPushMatrix();
		glTranslatef(-5.5, -1.5, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(1.0, 0.0, 1.0);
		prisma();
		glPopMatrix();

		// mano derecho
		glPushMatrix();
		glTranslatef(5.5, -1.5, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(1.0, 0.0, 1.0);
		prisma();
		glPopMatrix();

		//brazo izquierdo
		glPushMatrix();
		glTranslatef(3.0, -1.5, 0.0);
		glScalef(3.0, 1.0, 1.0);
		glColor3f(0.0, 0.0, 1.0);
		prisma();
		glPopMatrix();

		//pierna derecha
		glPushMatrix();
		glTranslatef(-1.0, -7.5, 0.0);
		glScalef(1.0, 7.0, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		prisma();
		glPopMatrix();

		//pierna izquierda
		glPushMatrix();
		glTranslatef(1.0, -7.5, 0.0);
		glScalef(1.0, 7.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		//pata derecha
		glPushMatrix();
		glTranslatef(1.5, -12.5, 0.0);
		glScalef(3.0, 3.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		//pata izquierda
		glPushMatrix();
		glTranslatef(-1.5, -12.5, 0.0);
		glScalef(3.0, 3.0, 1.0);
		glColor3f(0.0, 1.0, 0.0);
		prisma();
		glPopMatrix();


		
									
  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
	case 'r':
	case 'R':
		angle += 0.3f;
		break;
	case 'f':
	case 'F':
		angle -= 0.3f;
		break;
	case 'q':
	case 'Q':
		transZ += 0.3f;
		break;
	case 'e':
	case 'E':
		transZ -= 0.3f;
		break;
		case 'w':
		case 'W':
			transY +=0.3f;
			break;
		case 's':
		case 'S':
			transY -= 0.3f;
			break;
		case 'a':
		case 'A':
			transX -= 0.3f;
			
			break;
		case 'd':
		case 'D':
			transX -= 0.3f;
	
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}