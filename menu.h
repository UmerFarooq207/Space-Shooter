#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>


class Menu {
public:

    Font m_font;
    Font num_font;
    Texture m_texture;
    Sprite m_sprite;
    Texture ship;
    Sprite ship_s;

    Text m_title;
    Text m_startButton;
    Text m_highscore;
    Text m_instruct;
    Text m_close;


    Text m_paused;
    Text m_resumeButton;


    Texture t_first;
    Sprite s_first;
    Texture t_sec;
    Sprite s_sec;
    Texture t_thir;
    Sprite s_thir;
    Text m_highest;
    Text m_Goback;


    Text m_instructions;
    Text m_motivation;
    Text m_sentence1;
    Text m_sentence2;
    Text m_sentence3;
    Text m_Gotit;


    Text m_gameover;
    Text m_playagain;

    Text m_win;
    Text m_win1;



    Menu()
    {
        // Load fonts and textures
        m_font.loadFromFile("img/font.otf");
        num_font.loadFromFile("img/num.ttf");
        m_texture.loadFromFile("img/menu.jpg");
        ship.loadFromFile("img/s.png");
        t_first.loadFromFile("img/first.png");
        t_sec.loadFromFile("img/second.png");
        t_thir.loadFromFile("img/third.png");

        // Set up background sprite
        m_sprite.setTexture(m_texture);


        //ship sprite
        ship_s.setTexture(ship);
        ship_s.setScale(0.19, 0.19);
        ship_s.setPosition(490, 220);


        //badges sprite
        s_first.setTexture(t_first);
        s_first.setScale(0.23, 0.23);
        s_first.setPosition(490, 183);

        s_sec.setTexture(t_sec);
        s_sec.setScale(0.25, 0.25);
        s_sec.setPosition(503, 283);

        s_thir.setTexture(t_thir);
        s_thir.setScale(0.25, 0.25);
        s_thir.setPosition(505, 363);





        // Set up menu text

        //  main menu


        m_title.setFont(m_font);
        m_title.setCharacterSize(100);
        m_title.setString("Space Shooter Game");
        m_title.setPosition(80, 40);
        m_title.setFillColor(Color(75, 73, 75));

        m_paused.setFont(m_font);
        m_paused.setCharacterSize(100);
        m_paused.setString("   Game Paused   ");
        m_paused.setPosition(80, 80);
        m_paused.setFillColor(Color(75, 73, 75));




        m_startButton.setFont(m_font);
        m_startButton.setCharacterSize(50);
        m_startButton.setString("Start Game");
        m_startButton.setPosition(300, 200);
        m_startButton.setFillColor(Color(129, 225, 151));


        //resume page


        m_resumeButton.setFont(m_font);
        m_resumeButton.setCharacterSize(50);
        m_resumeButton.setString("Resume Game");
        m_resumeButton.setPosition(290, 270);
        m_resumeButton.setFillColor(Color(129, 225, 151));


        m_highscore.setFont(m_font);
        m_highscore.setCharacterSize(50);
        m_highscore.setString("High Score");
        m_highscore.setPosition(300, 270);
        m_highscore.setFillColor(Color(246, 247, 142));


        m_instruct.setFont(m_font);
        m_instruct.setCharacterSize(50);
        m_instruct.setString("Instructions");
        m_instruct.setPosition(300, 340);
        m_instruct.setFillColor(Color(246, 187, 119));


        m_close.setFont(m_font);
        m_close.setCharacterSize(50);
        m_close.setString("Exit Game");
        m_close.setPosition(300, 410);
        m_close.setFillColor(Color(202, 63, 20));


        //highscore page

        m_highest.setFont(m_font);
        m_highest.setCharacterSize(100);
        m_highest.setString("   High Score   ");
        m_highest.setPosition(80, 50);
        m_highest.setFillColor(Color(246, 247, 142));


        m_Goback.setFont(m_font);
        m_Goback.setCharacterSize(50);
        m_Goback.setString(" Go Back");
        m_Goback.setPosition(530, 460);
        m_Goback.setFillColor(Color(58, 125, 48));


        //instruction page

        m_instructions.setFont(m_font);
        m_instructions.setCharacterSize(100);
        m_instructions.setString("   How to Play   ");
        m_instructions.setPosition(80, 80);
        m_instructions.setFillColor(Color(66, 186, 142));



        m_motivation.setFont(m_font);
        m_motivation.setCharacterSize(35);
        m_motivation.setString("   More Score More Absolutes   ");
        m_motivation.setPosition(150, 230);
        m_motivation.setFillColor(Color::White);

        m_sentence1.setFont(m_font);
        m_sentence1.setCharacterSize(35);
        m_sentence1.setString("   Press Space to Shoot   ");
        m_sentence1.setPosition(150, 255);
        m_sentence1.setFillColor(Color::White);

        m_sentence2.setFont(m_font);
        m_sentence2.setCharacterSize(35);
        m_sentence2.setString("   Use Up Down Right Left key for movement   ");
        m_sentence2.setPosition(150, 280);
        m_sentence2.setFillColor(Color::White);


        m_sentence3.setFont(m_font);
        m_sentence3.setCharacterSize(35);
        m_sentence3.setString("   You can only Dodge the Monster and Dragon   ");
        m_sentence3.setPosition(150, 305);
        m_sentence3.setFillColor(Color::White);


        m_Gotit.setFont(m_font);
        m_Gotit.setCharacterSize(50);
        m_Gotit.setString("OK Got it");
        m_Gotit.setPosition(500, 400);
        m_Gotit.setFillColor(Color(58, 125, 48));




        // Game Over page

        m_gameover.setFont(m_font);
        m_gameover.setCharacterSize(150);
        m_gameover.setString("Game Over");
        m_gameover.setPosition(130, 110);
        m_gameover.setFillColor(Color(223, 52, 52));


        m_playagain.setFont(m_font);
        m_playagain.setCharacterSize(60);
        m_playagain.setString("Start New Game");
        m_playagain.setPosition(220, 310);
        m_playagain.setFillColor(Color(58, 125, 48));


        //winning page

        m_win.setFont(m_font);
        m_win.setCharacterSize(150);
        m_win.setString("Winner Winner");
        m_win.setPosition(130, 110);
        m_win.setFillColor(Color(58, 125, 48));

        m_win1.setFont(m_font);
        m_win1.setCharacterSize(120);
        m_win1.setString("Chicken Dinner");
        m_win1.setPosition(130, 140);
        m_win1.setFillColor(Color::White);



        // Set up game instance

    }

    bool display_menu(RenderWindow& window)
    {



        while (window.isOpen())
        {
            // Handle events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();

                    return false;
                }
                else if (event.type == sf::Event::MouseButtonPressed)
                {
                    // Check if start button is pressed
                    if (m_startButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || Keyboard::isKeyPressed(Keyboard::Enter))
                    {
                        return true;

                    }

                    else if (m_highscore.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        display_highscore(window);
                    }

                    else if (m_instruct.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        display_instructions(window);
                    }

                    else if (m_close.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        window.close();
                        return false;
                    }



                }
            }

            // Draw menu
            window.clear();
            window.draw(m_sprite);
            window.draw(ship_s);
            window.draw(m_title);
            window.draw(m_startButton);
            window.draw(m_highscore);
            window.draw(m_instruct);
            window.draw(m_close);

            window.display();
        }

        return true;
    }


    bool display_resume(RenderWindow& window)
    {



        while (window.isOpen())
        {
            // Handle events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();

                    return false;
                }
                else if (event.type == sf::Event::MouseButtonPressed)
                {
                    // Check if resume button is pressed
                    if (m_resumeButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        return true;

                    }

                    else if (m_instruct.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        display_instructions(window);
                    }

                    else if (m_close.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        window.close();
                        return false;
                    }



                }


                if (Keyboard::isKeyPressed(Keyboard::Escape)) {


                    return true;

                }


            }

            // Draw menu
            window.clear();
            window.draw(m_sprite);
            window.draw(m_paused);
            window.draw(m_resumeButton);
            window.draw(m_instruct);
            window.draw(m_close);

            window.display();
        }

        return true;
    }



    bool display_instructions(RenderWindow& window)
    {



        while (window.isOpen())
        {
            // Handle events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();

                    return false;
                }
                else if (event.type == sf::Event::MouseButtonPressed)
                {
                    // Check if resume button is pressed
                    if (m_Gotit.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        return true;

                    }

                }


            }

            // Draw menu
            window.clear();
            window.draw(m_sprite);
            window.draw(m_instructions);
            window.draw(m_motivation);
            window.draw(m_sentence1);
            window.draw(m_sentence2);
            window.draw(m_sentence3);
            window.draw(m_Gotit);

            window.display();
        }

        return true;
    }


    bool display_ending(RenderWindow& window)
    {



        while (window.isOpen())
        {
            // Handle events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();

                    return false;
                }
                else if (event.type == sf::Event::MouseButtonPressed)
                {
                    // Check if resume button is pressed
                    if (m_close.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        window.close();
                        return true;

                    }

                }


            }

            // Draw menu
            window.clear();
            window.draw(m_sprite);
            window.draw(m_win);
            window.draw(m_close);

            window.display();
        }

        return true;
    }



    bool display_highscore(RenderWindow& window)
    {
        // Open the score.txt file
        ifstream file("score.txt");

        // Read the number of lines in the file
        int count = 0;
        string line;
        while (getline(file, line)) {
            count++;
        }
        file.close();

        // Reopen the file to read the scores and names
        file.open("score.txt");
        const int maxScores = 3; // Maximum number of scores to display
        int size = count;
        double* scores1 = new double[size + 1];
        string* names1 = new string[size + 1];

        for (int i = 0; i < count; i++) {
            getline(file, line, ',');
            scores1[i] = stod(line);
            getline(file, names1[i], '\n');
        }

        file.close();

        // Sort the scores1 and names1 in descending order
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count - i; j++) {
                if (scores1[j] < scores1[j + 1]) {
                    // Swap scores1
                    double tempScore = scores1[j];
                    scores1[j] = scores1[j + 1];
                    scores1[j + 1] = tempScore;
                    // Swap names1
                    string tempName = names1[j];
                    names1[j] = names1[j + 1];
                    names1[j + 1] = tempName;
                }
            }
        }
        int size2 = 3;
        double* scores = new double[size2 + 1];
        string* names = new string[size2 + 1];
        if (count >= 3)
        {

            for (int i = 0; i < 3; i++)
            {
                names[i] = names1[i];
                scores[i] = scores1[i];
            }
        }
        else
        {
            size2 = count;
            delete[] scores;
            delete[] names;
            scores = new double[size2 + 1];
            names = new string[size2 + 1];
            for (int i = 0; i < size2; i++)
            {
                names[i] = names1[i];
                scores[i] = scores1[i];
            }
        }
        delete[] scores1;
        delete[] names1;

        // Clear the window
        window.clear();

        // Draw menu
        window.draw(m_sprite);
        window.draw(s_first);
        window.draw(s_sec);
        window.draw(s_thir);
        window.draw(m_highest);
        window.draw(m_Goback);

        // Create and configure the text objects
        sf::Text nameText;
        nameText.setFont(m_font);
        nameText.setCharacterSize(55);
        nameText.setFillColor(Color(255, 51, 51));

        sf::Text score;
        score.setFont(num_font);
        score.setCharacterSize(50);
        score.setFillColor(Color(255, 255, 204));



        // Display the scores and names
        for (int i = 0; i < size2 && i < count; ) {
            string scoreString = to_string(static_cast<int>(scores[i]));  // Convert score to integer and remove decimal places
            string nameString = names[i];
            string rankString = to_string(i + 1);

            nameText.setString(nameString);
            nameText.setPosition(150, 120 + 90 * (++i));
            window.draw(nameText);

            score.setString(scoreString);
            score.setPosition(300, nameText.getPosition().y);
            window.draw(score);
        }
        // Display the window
        window.display();

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return false;
                }
                else if (event.type == sf::Event::MouseButtonPressed) {
                    if (m_Goback.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        return true;
                    }
                }
            }
        }

        return true;
    }








    bool display_gameover(RenderWindow& window)
    {




        while (window.isOpen())
        {
            // Handle events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();

                }
                else if (event.type == sf::Event::MouseButtonPressed)
                {
                    // Check if resume button is pressed
                    if (m_playagain.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {

                        return true;

                    }
                    else if (m_close.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        window.close();

                    }

                }


            }

            // Draw menu
            window.clear();
            window.draw(m_sprite);
            window.draw(m_gameover);
            window.draw(m_playagain);
            window.draw(m_close);

            window.display();
        }

        return false;
    }





};
