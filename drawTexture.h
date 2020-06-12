#ifndef DRAW_TEXTURE_H
#define DRAW_TEXTURE_H

#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <vector>


// Draws a face with the texture at position i in current texture
void drawFaceWithTexture(int i, GLfloat face[], GLenum mode, std::vector<GLuint> textures, int current_texture){
  glBindTexture(GL_TEXTURE_2D, textures[(i + current_texture) % textures.size()]);
  glBegin(mode);
  int j = i * 12;
  glTexCoord2f(0.0f, 0.0f); glVertex3f(face[6+j], face[7+j], face[8+j]);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(face[9+j], face[10+j], face[11+j]);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(face[0+j], face[1+j], face[2+j]);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(face[3+j], face[4+j], face[5+j]);
  glEnd();
}

// Creates points and calls the draw function to show them
void drawWithTexture(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength, GLenum mode, std::vector<GLuint> textures, int current_texture){
  // Face
  GLfloat faceWidthLength = edgeLength * 5.0f; // y
  GLfloat faceHeigthLength = edgeLength * 10.0f; // x
  // Body
  GLfloat bodyWidthLength = edgeLength * 5.0f; // y
  GLfloat bodyHeigthLength = edgeLength  * 20.0f; // z
  // Shell
  GLfloat shellWidthLength = faceHeigthLength * 0.9f; // x
  GLfloat shellHeigthLength = edgeLength * 20.0f; // y
  GLfloat shellDepthLength = bodyHeigthLength * 0.9f; // z
  // Shell Draw
  // Eye Length
  GLfloat eyeLengthWidthLength = faceHeigthLength * 0.4f; // x
  GLfloat eyeLengthHeigthLength = edgeLength * 10.0f; // y
  GLfloat eyeLengthDepthLength = bodyHeigthLength - edgeLength; // z
  // Eye
  GLfloat eyeWidthLength = faceHeigthLength * 0.2f; // x
  GLfloat eyeHeigthLength = edgeLength * 10.0f; // y
  GLfloat eyeDepthLength = bodyHeigthLength - (edgeLength * 3.0f); // z

  GLfloat vertices[] = {
      // Face ////////////////////////////////////
      // front face
      centerPosX - faceHeigthLength, centerPosY + faceWidthLength, centerPosZ + bodyHeigthLength, // top left
      centerPosX + faceHeigthLength, centerPosY + faceWidthLength, centerPosZ + bodyHeigthLength, // top right
      centerPosX + faceHeigthLength, centerPosY - faceWidthLength, centerPosZ + bodyHeigthLength, // bottom right
      centerPosX - faceHeigthLength, centerPosY - faceWidthLength, centerPosZ + bodyHeigthLength, // bottom left
      // back face
      centerPosX - faceHeigthLength, centerPosY + faceWidthLength, centerPosZ - bodyHeigthLength, // top left
      centerPosX + faceHeigthLength, centerPosY + faceWidthLength, centerPosZ - bodyHeigthLength, // top right
      centerPosX + faceHeigthLength, centerPosY - faceWidthLength, centerPosZ - bodyHeigthLength, // bottom right
      centerPosX - faceHeigthLength, centerPosY - faceWidthLength, centerPosZ - bodyHeigthLength, // bottom left

      // Body ////////////////////////////////////////
      // left face
      centerPosX - faceHeigthLength, centerPosY + bodyWidthLength, centerPosZ + bodyHeigthLength, // top left
      centerPosX - faceHeigthLength, centerPosY + bodyWidthLength, centerPosZ - bodyHeigthLength, // top right
      centerPosX - faceHeigthLength, centerPosY - bodyWidthLength, centerPosZ - bodyHeigthLength, // bottom right
      centerPosX - faceHeigthLength, centerPosY - bodyWidthLength, centerPosZ + bodyHeigthLength, // bottom left

      // right face
      centerPosX + faceHeigthLength, centerPosY + bodyWidthLength, centerPosZ + bodyHeigthLength, // top left
      centerPosX + faceHeigthLength, centerPosY + bodyWidthLength, centerPosZ - bodyHeigthLength, // top right
      centerPosX + faceHeigthLength, centerPosY - bodyWidthLength, centerPosZ - bodyHeigthLength, // bottom right
      centerPosX + faceHeigthLength, centerPosY - bodyWidthLength, centerPosZ + bodyHeigthLength, // bottom left

      // top face
      centerPosX - faceHeigthLength, centerPosY + bodyWidthLength, centerPosZ + bodyHeigthLength, // top left
      centerPosX - faceHeigthLength, centerPosY + bodyWidthLength, centerPosZ - bodyHeigthLength, // top right
      centerPosX + faceHeigthLength, centerPosY + bodyWidthLength, centerPosZ - bodyHeigthLength, // bottom right
      centerPosX + faceHeigthLength, centerPosY + bodyWidthLength, centerPosZ + bodyHeigthLength, // bottom left

      // bottom face
      centerPosX - faceHeigthLength, centerPosY - bodyWidthLength, centerPosZ + bodyHeigthLength, // top left
      centerPosX - faceHeigthLength, centerPosY - bodyWidthLength, centerPosZ - bodyHeigthLength, // top right
      centerPosX + faceHeigthLength, centerPosY - bodyWidthLength, centerPosZ - bodyHeigthLength, // bottom right
      centerPosX + faceHeigthLength, centerPosY - bodyWidthLength, centerPosZ + bodyHeigthLength,  // bottom left

      // Shell/////////////////////////////////////////////
      // Front face
      centerPosX - shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ + (shellDepthLength * .18f), // top left
      centerPosX + shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ + (shellDepthLength * .18f), // top right
      centerPosX + shellWidthLength, centerPosY + faceWidthLength, centerPosZ + (shellDepthLength * .18f), // bottom right
      centerPosX - shellWidthLength, centerPosY + faceWidthLength, centerPosZ + (shellDepthLength * .18f), // bottom left

      // Back face
      centerPosX - shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ - shellDepthLength, // top left
      centerPosX + shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ - shellDepthLength, // top right
      centerPosX + shellWidthLength, centerPosY + faceWidthLength, centerPosZ - shellDepthLength, // bottom right
      centerPosX - shellWidthLength, centerPosY + faceWidthLength, centerPosZ - shellDepthLength, // bottom left

      // top face
      centerPosX - shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ - shellDepthLength, // top left back
      centerPosX + shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ - shellDepthLength, // top right back
      centerPosX + shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ + (shellDepthLength * .18f), // top right front
      centerPosX - shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ + (shellDepthLength * .18f), // top left front

      // Right side
      centerPosX - shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ - shellDepthLength, // top left back
      centerPosX - shellWidthLength, centerPosY + faceWidthLength, centerPosZ - shellDepthLength, // bottom left back
      centerPosX - shellWidthLength, centerPosY + faceWidthLength, centerPosZ + (shellDepthLength * .18f), // bottom left front
      centerPosX - shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ + (shellDepthLength * .18f), // top left front

      // left side
      centerPosX + shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ - shellDepthLength, // top right
      centerPosX + shellWidthLength, centerPosY + faceWidthLength, centerPosZ - shellDepthLength, // bottom right
      centerPosX + shellWidthLength, centerPosY + faceWidthLength, centerPosZ + (shellDepthLength * .18f), // bottom right
      centerPosX + shellWidthLength, centerPosY + faceWidthLength + shellHeigthLength, centerPosZ + (shellDepthLength * .18f), // top right


      // Shell Draw /////////////////////////

      // Eye Length /////////////////////////
      // Left //
      // front face
      centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top left
      centerPosX - eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top right
      centerPosX - eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // bottom right
      centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // bottom left

      // back face
      centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top left
      centerPosX - eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top right
      centerPosX - eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // bottom right
      centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // bottom left

      // right side
      centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top left
      centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // bottom left
      centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // bottom left
      centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top left

      // left side
      centerPosX - eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top right
      centerPosX - eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // bottom right
      centerPosX - eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // bottom right
      centerPosX - eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top right


      // Right //
      // front face
      centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top left
      centerPosX + eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top right
      centerPosX + eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // bottom right
      centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // bottom left

      // back face
      centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top left
      centerPosX + eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top right
      centerPosX + eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // bottom right
      centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // bottom left

      // right side
      centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top left
      centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // bottom left
      centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // bottom left
      centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top left

      // Left side
      centerPosX + eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top right
      centerPosX + eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // bottom right
      centerPosX + eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // bottom right
      centerPosX + eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top right


      // Eye /////////////////////////
      // Left //
      // front face
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top left
      centerPosX - eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top right
      centerPosX - eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // bottom right
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // bottom left

      // back face
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // top left
      centerPosX - eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // top right
      centerPosX - eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + eyeDepthLength, // bottom right
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + eyeHeigthLength, centerPosZ + eyeDepthLength, // bottom left

      // top face
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top left
      centerPosX - eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top right
      centerPosX - eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // bottom right
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // bottom left

      // bottom face
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // top left
      centerPosX - eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // top right
      centerPosX - eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + eyeDepthLength, // bottom right
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + eyeHeigthLength, centerPosZ + eyeDepthLength, // bottom left

      // left face
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top left
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // bottom left
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top left
      centerPosX - (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // bottom left

      //right face
      centerPosX - eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top right
      centerPosX - eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // bottom right
      centerPosX - eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + eyeDepthLength, // bottom right
      centerPosX - eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // top right

      // Right //
      // front face
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top left
      centerPosX + eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top right
      centerPosX + eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // bottom right
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // bottom left

      // back face
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // top left
      centerPosX + eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // top right
      centerPosX + eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + eyeDepthLength, // bottom right
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + eyeHeigthLength, centerPosZ + eyeDepthLength, // bottom left

      // top face
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top left
      centerPosX + eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top right
      centerPosX + eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // bottom right
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // bottom left

      // bottom face
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // top left
      centerPosX + eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // top right
      centerPosX + eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + eyeDepthLength, // bottom right
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + eyeHeigthLength, centerPosZ + eyeDepthLength, // bottom left

      // left face
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength + 0.1f, // top left
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength + 0.1f, // bottom left
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength + 0.1f, // top left
      centerPosX + (eyeWidthLength * 4.0f), centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength + 0.1f, // bottom left

      //right face
      centerPosX + eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + bodyHeigthLength, // top right
      centerPosX + eyeWidthLength, centerPosY + (eyeHeigthLength * 2.0f), centerPosZ + eyeDepthLength, // bottom right
      centerPosX + eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + eyeDepthLength, // bottom right
      centerPosX + eyeWidthLength, centerPosY + eyeHeigthLength, centerPosZ + bodyHeigthLength, // top right

  };
  for(unsigned int i = 0; i < (sizeof(vertices)/sizeof(*vertices)) / 12; i++){
    drawFaceWithTexture(i, vertices, mode, textures, current_texture);
  }
}

#endif
