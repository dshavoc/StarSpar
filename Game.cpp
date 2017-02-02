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

    //Update ships
    for(vector<Ship*>::iterator pShipIt = ships.begin(); pShipIt!= ships.end(); pShipIt++) {

        //Check for collisions with solars
        for(vector<Solar*>::iterator pSolarIt = solars.begin(); pSolarIt != solars.end(); pSolarIt++) {
            if( (*pShipIt)->collidesWith(*pSolarIt) ) {
                createExplosion( (*pShipIt)->getX(), (*pShipIt)->getY(), 24.f, timeNowMs);
                (*pShipIt)->markFinished();
            }
        }

        //Check for collisions with other ships
        for(vector<Ship*>::iterator pShip2It = ships.begin(); pShip2It != ships.end(); pShip2It++) {
            if( pShipIt != pShip2It && (*pShipIt)->collidesWith(*pShip2It) ) {
                createExplosion( (*pShipIt)->getX(), (*pShipIt)->getY(), 24.f, timeNowMs);
                createExplosion( (*pShip2It)->getX(), (*pShip2It)->getY(), 24.f, timeNowMs);
                (*pShipIt)->markFinished();
                (*pShip2It)->markFinished();
            }
        }

        //Check for collisions with projectiles
        for(vector<Projectile*>::iterator pProjIt = projectiles.begin(); pProjIt != projectiles.end(); pProjIt++) {
            if( (*pShipIt)->collidesWith(*pProjIt) ) {
                createExplosion( (*pShipIt)->getX(), (*pShipIt)->getY(), 24.f, timeNowMs);
                (*pShipIt)->markFinished();
                (*pProjIt)->markFinished();
            }
        }

        (*pShipIt)->update(keys, timeNowMs, solars);

        //Check for end of life
        if( (*pShipIt)->isFinished() ) {
            ships.erase(pShipIt);
            pShipIt--;
        }
    }

    //Update projectiles
    for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); it++)
    {

        //Check for collisions with solars
        for(vector<Solar*>::iterator pSolarIt = solars.begin(); pSolarIt != solars.end(); pSolarIt++) {
            if( (*it)->collidesWith(*pSolarIt) ) {
                createExplosion((*it)->getX(), (*it)->getY(), 6.f, timeNowMs);
                (*it)->markFinished();
            }
        }

        (*it)->update(timeNowMs, solars);

        //(*it)->printDistanceTo(ships[0]);

        //Check for end of life
        if((*it)->isFinished()) {
            printf("Killing projectile\r\n");
            projectiles.erase(it);
            it--;   //offset to accommodate removed element. Otherwise next element would be skipped and it would exceed end, resulting in seg fault
        }
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

    //6. Draw HUD elements


    setProjection();

    //Update screen
    glutSwapBuffers();
}

void initGamespace() {

    int timeNow = glutGet(GLUT_ELAPSED_TIME);

    resetKeys();

    //LightningAnim *l;

    //l = new LightningAnim(-50, -50, 50, 50, timeNow, 0);
    //l->start();
    //destructionAnims.push_back(l);

    //l = new LightningAnim(50, -50, -50, 50, timeNow, 0);
    //l->start();
    //destructionAnims.push_back(l);

    //SparkAnim *sa = new SparkAnim(0.f, 0.f, 10.f, timeNow);
    //sa->start();
    //destructionAnims.push_back(sa);

    //ThrusterAnim *t = new ThrusterAnim(0.f, 0.f, 0.f, 25.f);
    //destructionAnims.push_back(t);
    //t->start();

    Ship *s = new Ship(0.f, 80.f, 5.f, timeNow, addProjectile);
    s->setControlsForPlayer(1);
    ships.push_back(s);

    s = new Ship(0.f, -80.f, 5.f, timeNow, addProjectile);
    s->setControlsForPlayer(2);
    ships.push_back(s);

    Solar *sol = new Solar(0.f, 0.f, 12.f, 20.f);
    solars.push_back(sol);

}

void addProjectile(Projectile *p) {
    projectiles.push_back(p);
}

void createExplosion(float x, float y, float magnitude, int timeNow) {
    SparkAnim *sa;
    int numSparks = magnitude / 3;

    for(int i=0; i<numSparks; i++) {
        sa = new SparkAnim(x, y, magnitude, timeNow);
        destructionAnims.push_back(sa);
    }

    ShockwaveAnim *sw;
    int numShockwaves = magnitude / 6;

    for(int i=0; i<numShockwaves; i++) {
        sw = new ShockwaveAnim(x, y, magnitude, timeNow);
        destructionAnims.push_back(sw);
    }
}
