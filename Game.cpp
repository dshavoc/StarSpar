#include "Game.h"
#include <vector>

/*
Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}*/


vector<Animation*> destructionAnims;
vector<Ship*> ships;
vector<Projectile*> projectiles;
vector<Solar*> solars;                      //Solars are gravity sources



void update(int timeNowMs)
{

    ships[0]->thrustLeft(getKey('a'));
    ships[0]->thrustRight(getKey('d'));
    ships[0]->thrustForward(getKey('w'));

    if(getKey('e')) ships[0]->fire(timeNowMs);

    ships[0]->update(timeNowMs, solars);

    for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); it++)
    {
        (*it)->update(timeNowMs, solars);
    }
}

void render()
{
    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );

    //Reset modelview matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    int timeNowMs = glutGet(GLUT_ELAPSED_TIME);

    //1. Draw grid
    drawGrid();

    //2. Draw solars (sun, commets, asteroids, etc...)
    for(unsigned int i=0; i < solars.size(); i++) {
        solars[i]->draw(timeNowMs);
    }

    //3. Draw destruction animations and debris
    for(unsigned int i = 0; i < destructionAnims.size(); i++) {
        destructionAnims[i]->draw(timeNowMs);
    }


    //4. Draw ships
    for(unsigned int i = 0; i < ships.size(); i++) {
        ships[i]->draw(timeNowMs);
    }

    //5. Draw projectiles, beam weapon discharge, explosions, and other effects
    for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); it++)
    {
        (*it)->draw(timeNowMs);
    }


    setProjection();

    //Update screen
    glutSwapBuffers();
}

void initGamespace() {

    int timeNow = glutGet(GLUT_ELAPSED_TIME);

    resetKeys();

    LightningAnim *l;

    l = new LightningAnim(-50, -50, 50, 50, timeNow, 0);
    //l->start(glutGet(GLUT_ELAPSED_TIME));
    destructionAnims.push_back(l);

    l = new LightningAnim(50, -50, -50, 50, timeNow, 0);
    //l->start(glutGet(GLUT_ELAPSED_TIME));
    destructionAnims.push_back(l);

    SparkAnim *sa = new SparkAnim(0.f, 0.f, 10.f, timeNow);
    sa->start();
    destructionAnims.push_back(sa);

    //ThrusterAnim *t = new ThrusterAnim(0.f, 0.f, 0.f, 25.f);
    //destructionAnims.push_back(t);
    //t->start();

    Ship *s = new Ship(0.f, 0.f, 5.f, timeNow, addProjectile);
    ships.push_back(s);

    Solar *sol = new Solar(-40.f, 0.f, 12.f, 20.f);
    solars.push_back(sol);

}

void addProjectile(Projectile *p) {
    projectiles.push_back(p);
}
