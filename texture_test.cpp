#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include "SOIL.h"
#include <vector>
#include "drawTexture.h"
#include "drawColor.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
std::vector<GLuint> textures;
std::vector<std::string> texture_names;
unsigned int current_texture = 0;
std::vector<GLuint> backgrounds;
std::vector<std::string> background_names;
unsigned int current_background = 0;
bool show_background = true;
bool show_menu = true;
GLfloat resize = 200.0f;
GLfloat halfScreenWidth = SCREEN_WIDTH / resize / 2;
GLfloat halfScreenHeight = SCREEN_HEIGHT / resize / 2;
GLfloat halfScreenDepth = -500 / resize;
GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;
GLfloat moveX = SCREEN_WIDTH/2;
GLfloat moveY = SCREEN_HEIGHT/2;
GLfloat moveZ = SCREEN_WIDTH/2;
GLfloat edgeLength = 10.0f / resize;
GLenum mode = GL_QUADS;
GLenum fill_mode = GL_FILL;
bool draw_texture = true;
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
std::string modeMessage = "Texture";
std::string drawModeMessage = "Quads";
std::string colorModeMessage = "Fill";
GLfloat last_message_position = 0.0f;
int last_x = 0;
int last_y = 0;
GLuint cesar;
GLuint chelo;
GLuint ali;
GLuint piolin;


void resizeFunc(int height, int width) {
    const float ar = (float) width / (float) height;
    glViewport(0, 10, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 90.0);
    //gluLookAt(0, 2, 0, -1, 1, -3, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
// Loads a texture into the textures vector
void LoadTexture(char texture_name[]){
  textures.emplace_back(SOIL_load_OGL_texture
  (
      texture_name,
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
      SOIL_FLAG_COMPRESS_TO_DXT
  ));
}
// Loads a background into the background vector
void LoadBackground(char background_name[]){
  backgrounds.emplace_back(SOIL_load_OGL_texture
  (
      background_name,
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
      SOIL_FLAG_COMPRESS_TO_DXT
  ));
}
// Prints received text and moves cursor to write the next text
void writeInfo(std::string s){
  glRasterPos2f(0.0f, last_message_position);
  last_message_position += 0.25;
  for (unsigned int i = 0; i < s.length(); i++) {
    glutBitmapCharacter(font, s[i]);
  }
}
// Prints menu
void printMessages(){
  if(!draw_texture) writeInfo("Color mode: " + colorModeMessage + " (Z)");
  writeInfo("Draw mode: " + drawModeMessage + " (X, C, V, B)");
  if(draw_texture) writeInfo("Current texture: " + texture_names[current_texture] + " (E)");
  writeInfo("Mode: " + modeMessage + " (Q)");
  writeInfo("Move XYZ axis with (W, A, S, D, J, K)");
  writeInfo("Make bigger with (M) or mouse wheel");
  writeInfo("Make smaller with (N) or mouse wheel");
  writeInfo("Current background: " + background_names[current_background] + " (T)");
  writeInfo("Toggle background with (R)");
  writeInfo("Rotate with arrow keys or with mouse drag");
}
// Draws Cesars photo
void drawCesar(){
  glBindTexture(GL_TEXTURE_2D, cesar);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 3.0f, -10.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 7.0f, -10.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 7.0f, -10.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(4.0f, 3.0f, -10.0f);
  glEnd();
}
// Draws Chelos photo
void drawChelo(){
  glBindTexture(GL_TEXTURE_2D, chelo);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, 3.0f, 4.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 7.0f, 4.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(8.0f, 7.0f, 4.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(8.0f, 3.0f, 4.0f);
  glEnd();
}
// Draws Alis photo
void drawAli(){
  glBindTexture(GL_TEXTURE_2D, ali);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(12.0f, 3.0f, -4.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(12.0f, 7.0f, -4.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(12.0f, 7.0f, 0.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(12.0f, 3.0f, 0.0f);
  glEnd();
}
// Draws piolin
void drawPiolin(){
  glBindTexture(GL_TEXTURE_2D, piolin);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 3.0f, -4.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(-5.0f, 7.0f, -4.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(-5.0f, 7.0f, 0.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 3.0f, 0.0f);
  glEnd();
}
// Draws background
void drawBackground(){
  glBindTexture(GL_TEXTURE_2D, backgrounds[current_background*6]);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(40.0f, -40.0f, 40.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, -40.0f, -40.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(-40.0f, -40.0f, -40.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, -40.0f, 40.0f);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, backgrounds[current_background*6+1]);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0f, -40.0f, -40.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, -40.0f, -40.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(40.0f, 40.0f, -40.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, 40.0f, -40.0f);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, backgrounds[current_background*6+2]);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0f, -40.0f, 40.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, -40.0f, 40.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(40.0f, 40.0f, 40.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, 40.0f, 40.0f);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, backgrounds[current_background*6+3]);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0f, -40.0f, -40.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(-40.0f, -40.0f, 40.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(-40.0f, 40.0f, 40.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, 40.0f, -40.0f);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, backgrounds[current_background*6+4]);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(40.0f, -40.0f, -40.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, -40.0f, 40.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(40.0f, 40.0f, 40.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(40.0f, 40.0f, -40.0f);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, backgrounds[current_background*6+5]);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(40.0f, 40.0f, 40.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, 40.0f, -40.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(-40.0f, 40.0f, -40.0f);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, 40.0f, 40.0f);
  glEnd();
}
// Shows menu if needed, draws texture or colors based on input, and shows background if needed
static void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-2.0f,-2.0f,-5.0f);
    last_message_position = 0.0f;
    if(show_menu) printMessages();
    glTranslatef(halfScreenWidth, halfScreenHeight, halfScreenDepth);
    glRotatef(rotationX, 1, 0, 0);
    glRotatef(rotationY, 0, 1, 0);
    glTranslatef(-halfScreenWidth, -halfScreenHeight, -halfScreenDepth);
    if(draw_texture){
      drawWithTexture(halfScreenWidth, halfScreenHeight, halfScreenDepth,
        edgeLength, mode, textures, current_texture * 31);
    } else {
      drawWithColor(halfScreenWidth, halfScreenHeight, halfScreenDepth,
        edgeLength, mode, fill_mode);
    }
    drawCesar();
    drawChelo();
    drawAli();
    drawPiolin();
    if(show_background) drawBackground();
    glutSwapBuffers();
    glutPostRedisplay();
}
// Drag rotation function
void dragFunc(int x, int y){
  rotationX += (y - last_y) / 4.0f;
  rotationY += (x - last_x) / 4.0f;
  last_x = x;
  last_y = y;
}
// Wheel scrolling function
void mouseFunc(int button, int state, int x, int y)
{
  if (button == 3) {
     edgeLength -= 1 / resize;
  }	else if(button == 4){
    edgeLength += 1 / resize;
  }
  last_x = x;
  last_y = y;
}
// Works with user input
void keyPressed (unsigned char key, int x, int y) {
  const GLfloat moveSpeed = 10 / resize;
  switch (key)
  {
      case 'H':
      case 'h':
      show_menu = !show_menu;
      break;
      case 'R':
      case 'r':
      show_background = !show_background;
      break;
      case 'T':
      case 't':
      current_background = (current_background + 1) % background_names.size();
      break;
      case 'q':
      case 'Q':
      draw_texture = !draw_texture;
      modeMessage = draw_texture ? "Texture" : "Color";
      fill_mode = GL_FILL;
      break;
      case 'e':
      case 'E':
      current_texture = (current_texture + 1) % texture_names.size();
      break;
      case 'w':
      case 'W':
      halfScreenHeight = moveSpeed + halfScreenHeight;
      break;
      case 's':
      case 'S':
      halfScreenHeight = halfScreenHeight - moveSpeed;
      break;
      case 'd':
      case 'D':
      halfScreenWidth = moveSpeed + halfScreenWidth;
      break;
      case 'j':
      case 'J':
      halfScreenDepth += moveSpeed;
      break;
      case 'k':
      case 'K':
      halfScreenDepth -= moveSpeed;
      break;
      case 'a':
      case 'A':
      halfScreenWidth = halfScreenWidth - moveSpeed;
      break;
      case 'n':
      case 'N':
      edgeLength -= 1 / resize;
      break;
      case 'm':
      case 'M':
      edgeLength += 1 / resize;
      break;
      case 'x':
      case 'X':
      mode = GL_POINTS;
      drawModeMessage = "Points";
      break;
      case 'c':
      case 'C':
      mode = GL_LINES;
      drawModeMessage = "Lines";
      break;
      case 'v':
      case 'V':
      mode = GL_TRIANGLES;
      drawModeMessage = "Triangles";
      break;
      case 'b':
      case 'B':
      mode = GL_QUADS;
      drawModeMessage = "Quads";
      break;
      case 'z':
      case 'Z':
      if(fill_mode == GL_FILL){
          fill_mode = GL_LINE;
      } else {
          fill_mode = GL_FILL;
      }
      break;
  }
}
// Manages special keys input
void specialKeyPressed (int key, int x, int y) {
  const GLfloat rotationSpeed = 10;
  switch (key)
  {
      case GLUT_KEY_UP:
      rotationX -= rotationSpeed;
      break;
      case GLUT_KEY_DOWN:
      rotationX += rotationSpeed;
      break;
      case GLUT_KEY_RIGHT:
      rotationY += rotationSpeed;
      break;
      case GLUT_KEY_LEFT:
      rotationY -= rotationSpeed;
      break;
  }
}
// Loads all textures needed
void InitTextures(){
  /* Face order:
      // face front face
      // face back face
      // body left face
      // body right face
      // body top face
      // body bottom face
      // shell front face
      // shell back face
      // shell top face
      // shell right face
      // shell left face
      // eye length front face
      // eye length back face
      // eye length right face
      // eye length left face
      // eye length front face
      // eye length back face
      // eye length right face
      // eye length left face
      // eye front face
      // eye back face
      // eye top face
      // eye bottom face
      // eye left face
      // eye right face
      // eye front face
      // eye back face
      // eye top face
      // eye bottom face
      // eye left face
      // eye right face
  */
  char* gary_texture_files[31] = {
    (char*)"./Texturas/gary/mouth.png", // face front face
    (char*)"./Texturas/gary/body.png", // face back face
    (char*)"./Texturas/gary/body.png", // body left face
    (char*)"./Texturas/gary/body.png", // body right face
    (char*)"./Texturas/gary/skin.png", // body top face
    (char*)"./Texturas/gary/bottom_skin.png", // body bottom face
    (char*)"./Texturas/gary/shell2.png", // shell front face
    (char*)"./Texturas/gary/shell2.png", // shell back face
    (char*)"./Texturas/gary/shell2.png", // shell top face
    (char*)"./Texturas/gary/shell.png", // shell right face
    (char*)"./Texturas/gary/shell.png", // shell left face
    (char*)"./Texturas/gary/skin.png", // eye length front face
    (char*)"./Texturas/gary/skin.png", // eye length back face
    (char*)"./Texturas/gary/skin.png", // eye length right face
    (char*)"./Texturas/gary/skin.png", // eye length left face
    (char*)"./Texturas/gary/skin.png", // eye length front face
    (char*)"./Texturas/gary/skin.png", // eye length back face
    (char*)"./Texturas/gary/skin.png", // eye length right face
    (char*)"./Texturas/gary/skin.png", // eye length left face
    (char*)"./Texturas/gary/eye.png", // eye front face
    (char*)"./Texturas/gary/eye2.png", // eye back face
    (char*)"./Texturas/gary/eye2.png", // eye top face
    (char*)"./Texturas/gary/eye2.png", // eye bottom face
    (char*)"./Texturas/gary/eye2.png", // eye left face
    (char*)"./Texturas/gary/eye2.png", // eye right face
    (char*)"./Texturas/gary/eye.png", // eye front face
    (char*)"./Texturas/gary/eye2.png", // eye back face
    (char*)"./Texturas/gary/eye2.png", // eye top face
    (char*)"./Texturas/gary/eye2.png", // eye bottom face
    (char*)"./Texturas/gary/eye2.png", // eye left face
    (char*)"./Texturas/gary/eye2.png", // eye right face
  };
  texture_names.emplace_back("Gary");
  for(int i = 0; i < 31; i++){
    LoadTexture(gary_texture_files[i]);
  }
  char* real_texture_files[31] = {
    (char*)"./Texturas/real/mouth.png", // face front face
    (char*)"./Texturas/real/skin.png", // face back face
    (char*)"./Texturas/real/skin.png", // body left face
    (char*)"./Texturas/real/skin.png", // body right face
    (char*)"./Texturas/real/skin.png", // body top face
    (char*)"./Texturas/real/skin.png", // body bottom face
    (char*)"./Texturas/real/Sides.png", // shell front face
    (char*)"./Texturas/real/Sides.png", // shell back face
    (char*)"./Texturas/real/Sides.png", // shell top face
    (char*)"./Texturas/real/Caparazon1.png", // shell right face
    (char*)"./Texturas/real/Caparazon2.png", // shell left face
    (char*)"./Texturas/real/skin.png", // eye length front face
    (char*)"./Texturas/real/skin.png", // eye length back face
    (char*)"./Texturas/real/skin.png", // eye length right face
    (char*)"./Texturas/real/skin.png", // eye length left face
    (char*)"./Texturas/real/skin.png", // eye length front face
    (char*)"./Texturas/real/skin.png", // eye length back face
    (char*)"./Texturas/real/skin.png", // eye length right face
    (char*)"./Texturas/real/skin.png", // eye length left face
    (char*)"./Texturas/real/Eye.png", // eye front face
    (char*)"./Texturas/real/skin.png", // eye back face
    (char*)"./Texturas/real/skin.png", // eye top face
    (char*)"./Texturas/real/skin.png", // eye bottom face
    (char*)"./Texturas/real/skin.png", // eye left face
    (char*)"./Texturas/real/skin.png", // eye right face
    (char*)"./Texturas/real/Eye.png", // eye front face
    (char*)"./Texturas/real/skin.png", // eye back face
    (char*)"./Texturas/real/skin.png", // eye top face
    (char*)"./Texturas/real/skin.png", // eye bottom face
    (char*)"./Texturas/real/skin.png", // eye left face
    (char*)"./Texturas/real/skin.png", // eye right face
  };
  texture_names.emplace_back("Real");
  for(int i = 0; i < 31; i++){
    LoadTexture(real_texture_files[i]);
  }
  char* crossy_road_texture_files[31] = {
    (char*)"./Texturas/CrossyRoad/mouth.png", // face front face
    (char*)"./Texturas/CrossyRoad/skin.png", // face back face
    (char*)"./Texturas/CrossyRoad/skin.png", // body left face
    (char*)"./Texturas/CrossyRoad/skin.png", // body right face
    (char*)"./Texturas/CrossyRoad/skin.png", // body top face
    (char*)"./Texturas/CrossyRoad/skin.png", // body bottom face
    (char*)"./Texturas/CrossyRoad/sidescapa.png", // shell front face
    (char*)"./Texturas/CrossyRoad/sidescapa.png", // shell back face
    (char*)"./Texturas/CrossyRoad/sidescapa.png", // shell top face
    (char*)"./Texturas/CrossyRoad/capa.png", // shell right face
    (char*)"./Texturas/CrossyRoad/capa2.png", // shell left face
    (char*)"./Texturas/CrossyRoad/skin.png", // eye length front face
    (char*)"./Texturas/CrossyRoad/skin.png", // eye length back face
    (char*)"./Texturas/CrossyRoad/skin.png", // eye length right face
    (char*)"./Texturas/CrossyRoad/skin.png", // eye length left face
    (char*)"./Texturas/CrossyRoad/skin.png", // eye length front face
    (char*)"./Texturas/CrossyRoad/skin.png", // eye length back face
    (char*)"./Texturas/CrossyRoad/skin.png", // eye length right face
    (char*)"./Texturas/CrossyRoad/skin.png", // eye length left face
    (char*)"./Texturas/CrossyRoad/Eye.png", // eye front face
    (char*)"./Texturas/CrossyRoad/eyeside.png", // eye back face
    (char*)"./Texturas/CrossyRoad/eyetop.png", // eye top face
    (char*)"./Texturas/CrossyRoad/skin.png", // eye bottom face
    (char*)"./Texturas/CrossyRoad/eyeside.png", // eye left face
    (char*)"./Texturas/CrossyRoad/eyeside.png", // eye right face
    (char*)"./Texturas/CrossyRoad/Eye.png", // eye front face
    (char*)"./Texturas/CrossyRoad/eyeside.png", // eye back face
    (char*)"./Texturas/CrossyRoad/eyetop.png", // eye top face
    (char*)"./Texturas/CrossyRoad/skin.png", // eye bottom face
    (char*)"./Texturas/CrossyRoad/eyeside.png", // eye left face
    (char*)"./Texturas/CrossyRoad/eyeside.png", // eye right face
  };
  texture_names.emplace_back("Crossy Road");
  for(int i = 0; i < 31; i++){
    LoadTexture(crossy_road_texture_files[i]);
  }
  char* real_forest_background_files[6] = {
    (char*)"./backgrounds/real_forest/floor.png",
    (char*)"./backgrounds/real_forest/side.png",
    (char*)"./backgrounds/real_forest/side.png",
    (char*)"./backgrounds/real_forest/side.png",
    (char*)"./backgrounds/real_forest/side.png",
    (char*)"./backgrounds/real_forest/top.png"
  };
  background_names.emplace_back("Real forest");
  for(int i = 0; i < 6; i++){
    LoadBackground(real_forest_background_files[i]);
  }
  char* cartoon_forest_background_files[6] = {
    (char*)"./backgrounds/cartoon_forest/floor.png",
    (char*)"./backgrounds/cartoon_forest/side.png",
    (char*)"./backgrounds/cartoon_forest/side.png",
    (char*)"./backgrounds/cartoon_forest/side.png",
    (char*)"./backgrounds/cartoon_forest/side.png",
    (char*)"./backgrounds/cartoon_forest/top.png"
  };
  background_names.emplace_back("Cartoon forest");
  for(int i = 0; i < 6; i++){
    LoadBackground(cartoon_forest_background_files[i]);
  }
  char* naruto_vs_sasuke_background_files[6] = {
    (char*)"./backgrounds/naruto vs sasuke/konoha.png",
    (char*)"./backgrounds/naruto vs sasuke/naruto_vs_sasuke1.png",
    (char*)"./backgrounds/naruto vs sasuke/naruto_vs_sasuke2.png",
    (char*)"./backgrounds/naruto vs sasuke/naruto_vs_sasuke3.png",
    (char*)"./backgrounds/naruto vs sasuke/naruto_vs_sasuke4.png",
    (char*)"./backgrounds/naruto vs sasuke/jiraya.png"
  };
  background_names.emplace_back("Naruto vs Sasuke Linkin Park");
  for(int i = 0; i < 6; i++){
    LoadBackground(naruto_vs_sasuke_background_files[i]);
  }
  char* white_background_files[6] = {
    (char*)"./backgrounds/white/white.png",
    (char*)"./backgrounds/white/white.png",
    (char*)"./backgrounds/white/white.png",
    (char*)"./backgrounds/white/white.png",
    (char*)"./backgrounds/white/white.png",
    (char*)"./backgrounds/white/white.png"
  };
  background_names.emplace_back("White background");
  for(int i = 0; i < 6; i++){
    LoadBackground(white_background_files[i]);
  }
  cesar = SOIL_load_OGL_texture
  (
      "cesar.jpeg",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
      SOIL_FLAG_COMPRESS_TO_DXT
  );
  chelo = SOIL_load_OGL_texture
  (
      "chelo.jpeg",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
      SOIL_FLAG_COMPRESS_TO_DXT
  );
  ali = SOIL_load_OGL_texture
  (
      "ali.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
      SOIL_FLAG_COMPRESS_TO_DXT
  );
  piolin = SOIL_load_OGL_texture
  (
      "kevin.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
      SOIL_FLAG_COMPRESS_TO_DXT
  );
}
int main(int argc, char **argv)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Snail");
    glutReshapeFunc(resizeFunc);
    InitTextures();
    glutDisplayFunc(Draw);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(specialKeyPressed);
    glutMouseFunc(mouseFunc);
    glutMotionFunc(dragFunc);
    /////////////////////////////////////
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutMainLoop();
}
