#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "enemy.h"
#include "menu.h"
#include "addon.h"
#include "enemyformation.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
    /*
    private:
    sf::Font num_font;
    sf::Text scoretext;

    */
public:

    int x = 0, y = 0;
    double score = 0;
    int lives = 3;
    bool gameover = false;
    bool playagain;
    int level = 1, phase = 1, count = 0;
    int random;
    bool ch = true;
    bool win = false;
    int form_enemy = 1;
    int move;
    int random_add;
    Sprite background; //Game background sprite
    Texture bg_texture;
    Sprite p_button; // pause button
    Texture pause;

    Texture tex_left;   //left diagonal
    Texture original;   //straight
    Texture tex_right;   //right diagonal

    Texture b_left;   //left diagonal
    Texture b_original;
    Texture b_right;


    bool dodge = true;
    bool dodge_Beam = true;
    bool shield = false;
    Addon* a;
    Player* p; //player
    Enemy* n[35]; //enemy alpha beta gamma
    Enemy* monster;
    Enemy* dragon;
    Menu* m;
    EnemyFormation enemyFormation;
    // add other game attributes


    //output score and lives
    /*
    scoretext.setFont(num_font);
    scoretext.setCharacterSize(20);
    scoretext.setFillColor(Color(255,255,204));
    string scoreString = to_string(static_cast<int>(score));
    scoretext.setString(scoreString);
    scoretext.setPosition(20, 5 );
    */


    Game()
    {

        m = new Menu;

        p = new Player("img/player_ship.png");



        enemyFormation.form(1);
        monster = enemyFormation.monster_1;
        monster->status = false;

        enemyFormation.form(1, 350, 30);
        dragon = enemyFormation.dragon_1;
        dragon->status = false;

        enemyFormation.form(level, phase);		//starting the first level

        for (int i = 0; i < 35; i++) {

            n[i] = enemyFormation.n[i];

            if (n[i]->status == false) {

                count++;
            }
        }







        bg_texture.loadFromFile("img/menu.jpg");  //background
        background.setTexture(bg_texture);

        pause.loadFromFile("img/pausebutton.png");  //pause button
        p_button.setTexture(pause);
        p_button.setScale(0.15, 0.15);
        p_button.setPosition(725, 0);

    }



    void addscore(double points) { 	// adding players score
        score += points;
    }

    void dead() {		//checking whether the game is over or not
        lives -= 1;
        if (lives <= 0) {

            gameover = true;

        }
        p = new Player("img/player_ship.png");	//if dead then making a new player
    }

    // Add on functions

    void Addonlife()
    {


        a = new Lives;



    }
    void Addonshooter()
    {


        a = new Shooter;


    }
    void Addondanger()
    {


        a = new Danger;




    }
    void Addonshield() {


        a = new Shield;


    }



    void formenemy() {



        if (count == 35 && form_enemy == 1) {

            enemyFormation.form(level, phase);  // generating the new level and phases
            count = 0;
            for (int i = 0; i < 35; i++) {

                n[i] = enemyFormation.n[i];  //getting shaped & randomized enemies

                if (n[i]->status == false) {

                    count++; // counting the number of enemies who are already off

                }

            }


        }

    }

    void create_monster() {   //monster creation

        enemyFormation.form(1);
        monster = enemyFormation.monster_1;
        move = rand() % 2;
    }
    void create_dragon() {    //dragon creation

        enemyFormation.form(1, 300, 30);
        dragon = enemyFormation.dragon_1;
    }



    void check_collision() {   //function checking the collision of player and enemy	

        for (int i = 0; i < 35; i++)

            if (p->sprite.getGlobalBounds().intersects(n[i]->sprite.getGlobalBounds()) && n[i]->status) {

                n[i]->status = false;
                if (n[i]->value == 1) {
                    addscore(10 * level);
                }
                else  if (n[i]->value == 2) {
                    addscore(20 * level);
                }
                else  if (n[i]->value == 3) {
                    addscore(30 * level);
                }

                p->status = false;


                dead();		//on collision player is dead
            }
    }

    void check_pbullet_collision() {     //function checking the collision of playerbullet and enemy

        for (int i = 0; i < 35; i++) { 	// loop through all enemies
            if (n[i] != NULL && n[i]->status) {
                for (int k = 0; k < 10; k++)
                    if (p->bullet.actives[k] && p->bullet.sprites[k].getGlobalBounds().intersects(n[i]->sprite.getGlobalBounds())) {

                        p->bullet.actives[k] = false;
                        n[i]->status = false;
                        count++;

                        if (count == 35) {
                            random = rand() % 3;
                            if (random == 1) {    //generating monster on random number

                                create_monster();
                                ch = false;
                                form_enemy = 0;
                            }
                            if (random == 2) {    //generating dragon on random number

                                create_dragon();
                                ch = false;
                                form_enemy = 0;
                            }


                            phase++;

                            if (phase == 4 && level < 3) {
                                phase = 1;
                                level++;
                            }
                            else if (phase == 7 && level == 3) {

                                win = true;

                            }




                        }



                        //calculating the score according to level

                        if (n[i]->value == 1) {
                            addscore(10 * level);    //for alpha
                        }
                        else if (n[i]->value == 2) {
                            addscore(20 * level);    //for beta
                        }
                        else if (n[i]->value == 3) {
                            addscore(30 * level);    //for gamma
                        }
                        break;

                    }

            }

        }
    }





    void check_ebullet_collision() {	//function checking the collision of player and enemybomb
        for (int i = 0; i < 35; i++) { // loop through all enemies
            if (n[i] != NULL) {
                for (int k = 0; k < 100; k++)
                    if (n[i]->bomb.actives[k] && p->sprite.getGlobalBounds().intersects(n[i]->bomb.sprites[k].getGlobalBounds())) {

                        n[i]->bomb.actives[k] = false;
                        p->status = false;
                        dead();

                    }

            }
        }


    }


    void check_lazer_collision() {

        if (monster->status && p->sprite.getGlobalBounds().intersects(monster->bomb.monster_lazer.getGlobalBounds())) {

            dead();

            dodge = false;
        }


    }

    void check_Beam_collision() {

        if (dragon->status && p->sprite.getGlobalBounds().intersects(dragon->bomb.dragon_lazer1.getGlobalBounds()) || p->sprite.getGlobalBounds().intersects(dragon->bomb.dragon_lazer2.getGlobalBounds()) || p->sprite.getGlobalBounds().intersects(dragon->bomb.dragon_lazer3.getGlobalBounds())) {

            dead();

            dodge_Beam = false;
        }


    }


    void check_addon_collision() {


        if (a->shooter == true && a->tex_load.getPosition().y >= 780)
        {
            a->drop = true;
            a->status = false;
            delete[]a;
            a = NULL;
        }

        if (a->danger == true && a->tex_load.getPosition().y >= 780)
        {
            a->drop = true;
            addscore(50);
            a->status = false;
            delete[]a;
            a = NULL;
        }

        if (a->liveplus == true && a->tex_load.getPosition().y >= 780)
        {
            a->drop = true;
            a->status = false;
            delete[]a;
            a = NULL;
        }

        if (a->shield == true && a->tex_load.getPosition().y >= 780)
        {
            a->drop = true;
            a->status = false;
            delete[]a;
            a = NULL;
        }



        if (a->liveplus && p->sprite.getGlobalBounds().intersects(a->tex_load.getGlobalBounds())) {

            lives++;
            a = nullptr;


        }
        else if (a->danger && p->sprite.getGlobalBounds().intersects(a->tex_load.getGlobalBounds())) {

            dead();
            a = nullptr;


        }
        else if (a->shooter && p->sprite.getGlobalBounds().intersects(a->tex_load.getGlobalBounds())) {

            shield = true;
            a = nullptr;


        }
        else if (a->shield && p->sprite.getGlobalBounds().intersects(a->tex_load.getGlobalBounds())) {

            shield = true;
            a = nullptr;


        }


    }



    void start_game()
    {


        // loading diagonal texture
        tex_left.loadFromFile("img/left.png");
        tex_right.loadFromFile("img/right.png");
        original.loadFromFile("img/player_ship.png");
        b_left.loadFromFile("img/bullet_q.png");
        b_right.loadFromFile("img/bullet_e.png");

        srand(time(0));

        Clock clock;
        float timer = 0;
        float add_time = 0;

        RenderWindow window(VideoMode(800, 600), title);   //opening new window

        bool play = m->display_menu(window);  //display menu 

        if (play) {


            while (window.isOpen())
            {

                float time = clock.getElapsedTime().asSeconds();
                clock.restart();
                add_time += time;

                Event e;
                while (window.pollEvent(e))
                {

                    if (e.type == Event::Closed || gameover == true) {
                        playagain = m->display_gameover(window);  // If cross/close is clicked/pressed
                        window.close(); //close the game 

                    }

                }

                if (Keyboard::isKeyPressed(Keyboard::Left)) {
                    p->sprite.setTexture(original);//If left key is pressed
                    p->move("l");

                }  // Player will move to left
                if (Keyboard::isKeyPressed(Keyboard::Right)) {
                    p->sprite.setTexture(original); // If right key is pressed
                    p->move("r");

                }//player will move to right
                if (Keyboard::isKeyPressed(Keyboard::Up)) {
                    p->sprite.setTexture(original); //If up key is pressed
                    p->move("u");

                }  //playet will move upwards
                if (Keyboard::isKeyPressed(Keyboard::Down)) {
                    p->sprite.setTexture(original);// If down key is pressed
                    p->move("d");

                }  //player will move downwards
                if (Keyboard::isKeyPressed(Keyboard::Space)) {
                    p->sprite.setTexture(original);
                    p->fire();
                }
                if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up)) {//If left key is pressed
                    p->sprite.setTexture(tex_left);
                    p->move("q");

                }
                if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up)) { //If left key is pressed
                    p->sprite.setTexture(tex_right);
                    p->move("e");

                }

                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    bool resume = m->display_resume(window);
                    if (!resume) {
                        return;
                    }
                }

                if (e.type == Event::MouseButtonPressed) {

                    if (p_button.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y)) {

                        bool resume = m->display_resume(window);
                        if (!resume) {
                            return;

                        }


                    }
                }









                if (a != NULL)
                {
                    a->tex_load.move(0, 0.2);
                }





                // generating a monster

                if (monster->status == true) {




                    timer += time;

                    if (timer < 10)  //monster will disappear after 10 sec
                    {
                        if (move == 0) {
                            monster->sprite.move(0.20, 0);
                        }
                        else {
                            monster->sprite.move(-0.20, 0);
                        }

                        float temp_x, temp_y;

                        temp_x = monster->sprite.getPosition().x;
                        temp_y = monster->sprite.getPosition().y;

                        if (temp_x <= -100)
                            monster->sprite.setPosition(800, temp_y);
                        else if (temp_x >= 800)
                            monster->sprite.setPosition(-100, temp_y);

                    }
                    else {

                        if (dodge == true) {
                            addscore(40);
                        }
                        monster->status = false;
                        form_enemy = 1;
                        timer = 0;

                        /*
                        random_add = rand()%4;

                    if(random_add == 0){
                    Addonlife();
                    }
                    if(random_add == 1){
                    Addondanger();
                    }
                    if(random_add == 2){
                    Addonshield();
                    }
                    if(random_add == 3){
                    Addonshooter();
                    }

                    */

                    }




                }


                // generating a dragon

                if (dragon->status == true) {




                    timer += time;

                    if (timer < 10)  //Dragon will disappear after 10 sec
                    {



                    }
                    else {

                        if (dodge_Beam == true) {
                            addscore(50);
                        }
                        dragon->status = false;
                        form_enemy = 1;
                        timer = 0;

                    }




                }






                if (ch = true) {
                    formenemy();

                    check_pbullet_collision();

                    if (!shield) {
                        check_collision();
                        check_ebullet_collision();
                    }
                }

                if (a != NULL)
                    check_addon_collision();


                if (monster->status == true)
                    check_lazer_collision();

                if (dragon->status == true)
                    check_Beam_collision();

                ////////////////////////////////////////////////
                /////  Call your functions here            ////
                //////////////////////////////////////////////








                window.clear(Color::Black); //clears the screen
                window.draw(background);  // setting background
                window.draw(p_button); //pause button
                p->mainloop(window, time);


                if (a != NULL)
                    window.draw(a->tex_load);


                if (monster->status == true) {
                    monster->M_mainloop(window); // monster show,lazer etc
                }

                if (dragon->status == true) {
                    dragon->D_mainloop(window); // Dragon show,lazer etc
                }


                if (monster->status == false && dragon->status == false) {

                    ch = true;

                    for (int i = 0; i < 35; i++) {

                        n[i]->mainloop(window, time);	// enemy show,bomb,cooldown

                    }

                }



                if (win)
                    m->display_ending(window);

                window.display();  //Displying all the sprites

            }

        }

    }


};
