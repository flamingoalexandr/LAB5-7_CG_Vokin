#pragma once
#include <GLFW/glfw3.h>
#include "Point.h"
#include <iostream>
#include <math.h>
class Player
{
public:
    Point* pos;
    float xAlfa = 70;
    float zAlfa = 0;
    float speed = 0;
    float rotateSpeedX = 0;
    float rotateSpeedY = 0;
    int direction = 0;




    float speedZ = 0;
    Player() {
        this->pos = new Point(0, 0, 4);
    }




    void MoveCamera() {

         float angle = (-zAlfa / 180 * 3.1415) + (direction*1.57075);



         if (speed != 0) {
             pos->x += sin(angle) * speed;
             pos->y += cos(angle) * speed;
         }               
            pos->z += 0.5 * speedZ;             
         

        zAlfa += rotateSpeedX;
        xAlfa += rotateSpeedY;

        glRotatef(-xAlfa, 1, 0, 0);
        glRotatef(-zAlfa, 0, 0, 1);

        glTranslatef(-pos->x, -pos->y, -pos->z);
        

    }

    void Player_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        /*if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            speed = 0.1;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            
        }        
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            speed = -0.1;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            speed = 0.1;
        }*/


        if ((glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS))
        {
           speedZ = 0.1;        
           std::cout << 123;
        }
        if ((glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE))
        {
            
            speedZ = 0;
        }
        if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS))
        {            
            speedZ = -0.1;   
            //printf("PRESS");
        }
        if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE))
        {
                //speedZ = 0;
                //printf("RELEASE");
        }
       /* speedZ = (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) < 0 ? 1 : glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) < 0 ? -1 : 0,
            GetKeyState('D') < 0 ? 1 : GetKeyState('A') < 0 ? -1 : 0,
            0. 1);*/

        if (speedZ > 0.1)
        {
            speedZ = 0.1;
        }
        if (speedZ < -0.1)
        {
            speed = -0.1;
        }
            




        switch (key)
        {
            case GLFW_KEY_W:
                speed = (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) ? 0.1 : 0.0;
                break;
            case GLFW_KEY_A:
                if ((glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS))
                {
                    speed = 0.1;
                    direction = -1;
                }
                else {
                    speed = 0;
                    direction = 0;
                }
                break;
            case GLFW_KEY_S:
                speed = (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) ? -0.1 : 0.0;
                break;
            case GLFW_KEY_D:
                // �������� ��� ������� ������� D
                if ((glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS))
                {
                    speed = 0.1;
                    direction = 1;
                }
                else {
                    speed = 0;
                    direction = 0;
                }   
                break;
            /*case GLFW_KEY_SPACE:               
                if ((glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS))
                {
                    if (speedZ < 0.1)
                    {
                        speedZ += 0.1;
                    }
                }
                else {
                    speedZ += -0.1;
                }
                break;
            case GLFW_KEY_LEFT_SHIFT:                
                if ((glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS))
                {
                    if (speedZ > -0.1)
                    {
                        speedZ += -0.1;
                    }
                }
                else {
                    speedZ += 0.1;
                }
                break;*/
        default:
            speed = 0;
            direction = 0;
            //speedZ = 0;
            break;
        }

        switch (key)
        {
            case GLFW_KEY_UP:
                rotateSpeedY = (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) ? 0.4 : 0.0;
                break;
            case GLFW_KEY_DOWN:
                rotateSpeedY = (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) ? -0.4 : 0.0;
                break;
            case GLFW_KEY_LEFT:
                rotateSpeedX = (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) ? 0.4 : 0.0;
                break;
            case GLFW_KEY_RIGHT:
                rotateSpeedX = (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) ? -0.4 : 0.0;
                break;
        default:
            rotateSpeedX = 0;
            break;
        }





        //if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT)) {   
        //    std::cout << 123;
        //    xAlfa += 2;
        //}

        //if ((key == GLFW_KEY_W)) {
        //    if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {                
        //        pos->y += 0.1;
        //    }
        //    else /*if (action == GLFW_RELEASE)*/ {
        //        speed = 0;
        //    }
        //}

        //if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT)) {           
        //    xAlfa -= 2;
        //    // �������� ����� ��� ��������� ������� �� ������� ����
        //}


        //if (key == GLFW_KEY_LEFT) {
        //    if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
        //        
        //        // �������� ����� ��� ��������� ������� �� ������� �����
        //        zAlfa += 2;
        //    }   
        //}
        //if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {            
        //    zAlfa -= 2;
        //}






        //
        //if (key == GLFW_KEY_A) {
        //    if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
        //        this->pos->x -= 0.1;
        //        //angle -= 3.1415 * 0.5;
        //    }
        //    else /*if (action == GLFW_RELEASE)*/ {
        //        speed = 0;
        //        //angle += 3.1415 * 0.5 ;
        //    }
        //}
        //if (key == GLFW_KEY_D) {
        //    if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
        //        /*speed = 0.1;*/
        //        this->pos->x += 0.1;
        //        //angle += 3.1415 / 2;
        //    }
        //    else /*if (action == GLFW_RELEASE)*/ {
        //        speed = 0;
        //        //angle -= 3.1415 / 2;
        //    }
        //}
        //if (key == GLFW_KEY_S) {
        //    if ((action == GLFW_PRESS || action == GLFW_REPEAT)) {
        //        this->pos->y -= 0.1;
        //    }
        //    if (action == GLFW_RELEASE) {
        //        speed = 0;
        //    }

        //}
    }
    
};

