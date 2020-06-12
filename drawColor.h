#ifndef DRAW_COLOR_H
#define DRAW_COLOR_H

#include <GL/glut.h>
#include <iostream>
#include <cstdlib>

// Draws all points with the received parameters
void drawFaceWithColor(GLfloat face[], GLfloat color[], unsigned int size, GLenum mode){
  glVertexPointer(3, GL_FLOAT, 0, face);
  glColorPointer(3, GL_FLOAT, 0, color);
  glDrawArrays(mode, 0, size);
}

// Calculate points and draws them with the function using the received parameters
void drawWithColor(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength, GLenum mode, GLenum fill_mode)
{
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
    // Mouth
    GLfloat mouthWidthLength = faceHeigthLength * 0.6f; // x
//    GLfloat mouthHeigthLength = edgeLength * 10.0f; // y
    GLfloat mouthDepthLength = bodyHeigthLength + 0.1f; // z
    // Pupil
    GLfloat pupilWidthLength = faceHeigthLength * 0.6f; // x
//    GLfloat pupilHeigthLength = edgeLength * 10.0f; // y
    GLfloat pupilDepthLength = bodyHeigthLength + 0.1f; // z

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

        // bottom face
        centerPosX - shellWidthLength, centerPosY + faceWidthLength, centerPosZ - shellDepthLength, // top left back
        centerPosX + shellWidthLength, centerPosY + faceWidthLength, centerPosZ - shellDepthLength, // top right back
        centerPosX + shellWidthLength, centerPosY + faceWidthLength, centerPosZ + (shellDepthLength * .18f), // top right front
        centerPosX - shellWidthLength, centerPosY + faceWidthLength, centerPosZ + (shellDepthLength * .18f), // top left front

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

        // top face
        centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top left
        centerPosX - eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top right
        centerPosX - eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top right
        centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top left

        // bottom face
        centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // top left
        centerPosX - eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // top right
        centerPosX - eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top right
        centerPosX - eyeLengthWidthLength - (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top left

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

        // top face
        centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top left
        centerPosX + eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength, // top right
        centerPosX + eyeLengthWidthLength, centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top right
        centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + eyeLengthHeigthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top left

        // bottom face
        centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // top left
        centerPosX + eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength, // top right
        centerPosX + eyeLengthWidthLength, centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top right
        centerPosX + eyeLengthWidthLength + (faceHeigthLength * 0.2f), centerPosY + faceWidthLength, centerPosZ + eyeLengthDepthLength - edgeLength, // top left

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

        // Mouth /////////////////////////
        // front face
        centerPosX - mouthWidthLength, centerPosY + (faceWidthLength * 0.6f), centerPosZ + mouthDepthLength, // top left
        centerPosX + mouthWidthLength, centerPosY + (faceWidthLength * 0.6f), centerPosZ + mouthDepthLength, // top right
        centerPosX + mouthWidthLength, centerPosY - (faceWidthLength * 0.4f), centerPosZ + mouthDepthLength, // bottom right
        centerPosX - mouthWidthLength, centerPosY - (faceWidthLength * 0.4f), centerPosZ + mouthDepthLength, // bottom left

        // Pupil /////////////////////////
        // Left //
        // front face
        centerPosX - pupilWidthLength, centerPosY + (faceWidthLength * 3.5f), centerPosZ + pupilDepthLength, // top left
        centerPosX - (faceHeigthLength * 0.4f), centerPosY + (faceWidthLength * 3.5f), centerPosZ + pupilDepthLength, // top right
        centerPosX - (faceHeigthLength * 0.4f), centerPosY + (faceWidthLength * 2.5f), centerPosZ + pupilDepthLength, // bottom right
        centerPosX - pupilWidthLength, centerPosY + (faceWidthLength * 2.5f), centerPosZ + pupilDepthLength, // bottom left
        // Right //
        // front face
        centerPosX + pupilWidthLength, centerPosY + (faceWidthLength * 3.5f), centerPosZ + pupilDepthLength, // top left
        centerPosX + (faceHeigthLength * 0.4f), centerPosY + (faceWidthLength * 3.5f), centerPosZ + pupilDepthLength, // top right
        centerPosX + (faceHeigthLength * 0.4f), centerPosY + (faceWidthLength * 2.5f), centerPosZ + pupilDepthLength, // bottom right
        centerPosX + pupilWidthLength, centerPosY + (faceWidthLength * 2.5f), centerPosZ + pupilDepthLength, // bottom left

    };


    GLfloat color[] = {
        0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216,  // front face
        0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216,  // back face
        // body
        0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216,  // back face
        0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216,  // back face
        0.88627451, 0.850980392, 0.71372549, 0.88627451, 0.850980392, 0.71372549, 0.88627451, 0.850980392, 0.71372549, 0.88627451, 0.850980392, 0.71372549,  // back face
        0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216, 0.862745098, 0.823529412, 0.698039216,  // back face
        // shell
        0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843,  // front face
        0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843,  // back face
        0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, // top face
        0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, // bottom face
        0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, // bottom face
        0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, 0.4, 0.239215686, 0.219607843, // bottom face
        // eye length
        // left
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, // front face
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078,  // back face
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078,  // top face
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078,  // bottom face
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078,  // bottom face
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078,  // bottom face
        // right
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, // front face
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078,  // back face
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078,  // top face
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078,  // bottom face
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078,  // bottom face
        0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078, 0.823529412, 0.819607843, 0.690196078,  // bottom face
        // eye
        // left
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // front face
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // back face
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // top face
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // bottom face
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // bottom face
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // bottom face
        // right
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // front face
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // back face
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // top face
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // top face
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // top face
        0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, 0.984313725, // bottom face
        // Mouth
        0.905882353, 0.341176471, 0.258823529, 0.905882353, 0.341176471, 0.258823529, 0.905882353, 0.341176471, 0.258823529, 0.905882353, 0.341176471, 0.258823529,
        // Pupil
        // left
        0.349019608, 0.192156863, 0.184313725, 0.349019608, 0.192156863, 0.184313725, 0.349019608, 0.192156863, 0.184313725, 0.349019608, 0.192156863, 0.184313725,
        // right
        0.349019608, 0.192156863, 0.184313725, 0.349019608, 0.192156863, 0.184313725, 0.349019608, 0.192156863, 0.184313725, 0.349019608, 0.192156863, 0.184313725,
    };

    // ENable required modes
    glPolygonMode(GL_FRONT_AND_BACK, fill_mode);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    drawFaceWithColor(vertices, color, (sizeof(vertices)/sizeof(*vertices)) / 3, mode);
    glDisableClientState(GL_DEPTH_TEST);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}


#endif
