#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include <cmath>
class EnemyFormation {
public:
    Enemy* n[35];
    Enemy* monster_1;
    Enemy* dragon_1;
    int h = 5;
    int w = 7;


    void generate_enemy(int i, int j, int x, int y) {

        int random = rand() % 3;

        switch (random) {

        case 0:
            n[i * 7 + j] = new Alpha(x + 70, 80 + y);
            break;

        case 1:
            n[i * 7 + j] = new Beta(x + 70, 80 + y);
            break;

        case 2:
            n[i * 7 + j] = new Gamma(x + 70, 80 + y);
            break;
        }
        n[i * 7 + j]->form();


    }


    void form(int monster) {

        if (monster == 1) {


            monster_1 = new Monster(300, 40);


        }

        monster_1->form();



    }

    void form(int dragon, int x, int y) {

        if (dragon == 1) {


            dragon_1 = new Dragon(x, y);


        }

        dragon_1->form();



    }






    void form(int level, int phase) {

        if (level == 1) {
            //hollow rectangle
            if (phase == 1) {
                int x = 0, y = 0;

                for (int i = 0; i < h; i++) {

                    for (int j = 0; j < w; j++) {

                        if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {

                            generate_enemy(i, j, x, y);
                        }
                        else {

                            n[i * 7 + j] = new Gamma(x + 120, 80 + y);
                            n[i * 7 + j]->status = false;

                        }

                        x += 100;
                    }
                    y += 60;
                    x = 0;
                }

            }
            //hollow triangle
            if (phase == 2) {
                int x = 0, y = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {

                        if (i == h - 2 || i + j == h - 2 || j - i == h - 2) {

                            generate_enemy(i, j, x, y);
                        }

                        else {

                            n[i * w + j] = new Gamma(x + 120, 80 + y);
                            n[i * w + j]->status = false;

                        }

                        x += 100;

                    }

                    y += 60;
                    x = 0;



                }



            }
            //half cross
            if (phase == 3) {

                int x = 0, y = 0;
                for (int i = 0; i < h; i++) {

                    for (int j = 0; j < w; j++) {

                        if (i == j || i + j == h - 1) {

                            generate_enemy(i, j, x, y);

                        }
                        else {

                            n[i * w + j] = new Gamma(x + 120, 80 + y);
                            n[i * w + j]->status = false;

                        }

                        x += 120;
                    }


                    y += 60;
                    x = 0;

                }




            }




        }
        if (level == 2) {
            //diamond 
            if (phase == 1) {
                int x = 0, y = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        if (i <= h / 2) {
                            if (i == h - 2 || i + j == h - 2 || j - i == h - 2) {

                                generate_enemy(i, j, x, y);
                            }

                            else {

                                n[i * w + j] = new Gamma(x + 120, 80 + y);
                                n[i * w + j]->status = false;

                            }
                        }
                        else {

                            if ((i == h - 1 && j == w / 2) || ((i == h - 2) && (j == w / 2 - 1 || j == w / 2 + 1))) {

                                generate_enemy(i, j, x, y);
                            }

                            else {

                                n[i * w + j] = new Gamma(x + 120, 80 + y);
                                n[i * w + j]->status = false;

                            }

                        }

                        x += 100;

                    }

                    y += 60;
                    x = 0;



                }





            }
            //hollow heart
            if (phase == 2) {
                int x = 0, y = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {

                        if ((i == 0 && j % 3 != 0) || (i == 1 && j % 3 == 0) || (i - j == 2) || (i + j == 8)) {

                            generate_enemy(i, j, x, y);
                        }
                        else {

                            n[i * w + j] = new Gamma(x + 120, 80 + y);
                            n[i * w + j]->status = false;

                        }

                        x += 100;
                    }
                    y += 60;
                    x = 0;
                }




            }
            //circle

            if (phase == 3) {

                int r = 170;
                int x, y;
                int j = 0;

                for (float i = 0; i < 2 * 3.14; i += (2 * 3.14 / 35)) {

                    x = r * cos(i) + 340;
                    y = r * sin(i) + 100;


                    generate_enemy(0, j++, x, y);


                }

            }

        }


        if (level == 3) {
            //full rectangle
            if (phase == 1) {

                int x = 0, y = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {


                        generate_enemy(i, j, x, y);

                        x += 100;
                    }
                    y += 60;
                    x = 0;
                }
            }
            //full triangle
            if (phase == 2) {

                int x = 0, y = 0;
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < w; j++) {

                        if (i == h - 2 || i + j >= h - 2 && j - i <= h - 2) {

                            generate_enemy(i, j, x, y);

                        }

                        else {

                            n[i * w + j] = new Gamma(-100, -100);
                            n[i * w + j]->status = false;

                        }

                        x += 100;
                    }

                    y += 60;
                    x = 0;


                }





            }

            //full cross
            if (phase == 3) {
                int x = 0, y = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {

                        if (i == j || i + j == h - 1 || j == h / 2 || ((i == 0 || i == h - 1) && j < w - 2)) {

                            generate_enemy(i, j, x, y);
                        }
                        else {

                            n[i * w + j] = new Gamma(x + 120, 80 + y);
                            n[i * w + j]->status = false;

                        }

                        x += 140;
                    }

                    y += 60;
                    x = 0;

                }




            }





            //full heart
            if (phase == 4) {
                int x = 0, y = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {

                        if ((i == 0 && j % 3 != 0) || (i == 1 || i == 2) || (i == h - 2 && (j >= 1 && j < w - 1)) || (i == h - 1 && (j >= 2 && j < w - 2))) {

                            generate_enemy(i, j, x, y);
                        }
                        else {

                            n[i * w + j] = new Gamma(x + 120, 80 + y);
                            n[i * w + j]->status = false;

                        }

                        x += 100;
                    }
                    y += 60;
                    x = 0;
                }
            }


            //full diamond
            if (phase == 5) {
                int x = 0, y = 0;
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < w; j++) {
                        if (i < h / 2 + 1) {
                            if ((i == h - 3 || i + j >= h - 3 && j - i <= h - 3) && (j < 5)) {

                                generate_enemy(i, j, x, y);

                            }

                            else {

                                n[i * w + j] = new Gamma(-100, -100);
                                n[i * w + j]->status = false;

                            }

                        }
                        else {
                            if (i == h - 1 && j == h / 2) {

                                generate_enemy(i, j, x, y);

                            }
                            else if (j >= 1 && j <= 3 && i == 3) {
                                generate_enemy(i, j, x, y);
                            }

                            else {

                                n[i * w + j] = new Gamma(-100, -100);
                                n[i * w + j]->status = false;

                            }

                        }
                        x = x + 100;
                    }

                    y += 50;
                    x = 0;


                }
            }






            //full circle
            if (phase == 6) {
                int r = 200;
                int x, y;
                int j = 0;

                for (float i = 0; i < 2 * 3.14; i += (2 * 3.14 / 35)) {

                    x = r * cos(i) + 340;
                    y = r * sin(i) + 90;


                    generate_enemy(0, j++, x, y);


                }




            }





        }


    }



};



