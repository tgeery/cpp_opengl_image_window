#include "GL/freeglut.h"
#include "GL/gl.h"
#define cimg_use_png
#include <CImg.h>
using namespace cimg_library;

class Background
{
    float clear_color = 0.2;
    float clear_proj = 1.0;
    float bkgnd_color = 1.0;
    float bkgnd_proj = 0.7;

public:
    void drawBackground()
    {
        glutInitDisplayMode(GLUT_SINGLE);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("OpenGL - Creating a triangle");

        glClearColor(clear_color, clear_color, clear_color, clear_color);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(bkgnd_color, bkgnd_color, bkgnd_color);
        glOrtho(-clear_proj, clear_proj, -clear_proj, clear_proj, -clear_proj, clear_proj);

        glBegin(GL_QUADS);
        glVertex3f(-bkgnd_proj, bkgnd_proj, 0);
        glVertex3f(bkgnd_proj, bkgnd_proj, 0);
        glVertex3f(bkgnd_proj, -bkgnd_proj, 0);
        glVertex3f(-bkgnd_proj, -bkgnd_proj, 0);
        glEnd();

        glFlush();

        glutMainLoop();
    }

    void drawImage()
    {
        CImg<unsigned char> image("../sample.png");
        CImgDisplay display(image, "Banking");
        display.resize(image.width(), image.height());
        while(!display.is_closed()) {
            display.wait();
        }
    }
};

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    Background * bkgnd = new Background();
    // bkgnd->drawBackground();
    bkgnd->drawImage();
    return 0;
}
