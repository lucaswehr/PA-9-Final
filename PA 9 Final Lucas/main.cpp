#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Animation.hpp"
#include "Shape.hpp"
#include "Text.hpp"
#include "Test.hpp"

enum class gameState
{
    mainMenu,
    Playing,
    Instructions,
    gameOver,
    restart

};

int main()
{

    Test t;
    t.testFont();
    t.testMusic();
    t.testSound();
    t.testTextures();
    t.testWindow();

    std::string x;

    srand(static_cast<unsigned>(time(0)));

    gameState gameState = gameState::mainMenu;

    float speed = 2.f;
    float negSpeed = -3.f;
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
    sf::CircleShape shape(15.f);

    window.setFramerateLimit(60);



    sf::Font font;
    if (!font.openFromFile("Jersey10-Regular.ttf"))
    {
        std::cout << "Error" << std::endl;

        return 0;

    }

    std::string fontText = "Jersey10-Regular.ttf";


    //Text class that makes it easier to initlaize text
    Text fail(fontText, "YOU LOSE", 240.f, 180.f, sf::Color::Red, 100);
    Text play(fontText, "PLAY", 330.f, 200.f, sf::Color::White, 80);
    Text settings(fontText, "HOW TO PLAY", 230.f, 300.f, sf::Color::White, 80);
    Text exit(fontText, "EXIT", 340.f, 400.f, sf::Color::White, 80);
    Text restart(fontText, "RESTART", 290.f, 300.f, sf::Color::White, 80);
    Text menu(fontText, "MENU", 320.f, 400.f, sf::Color::White, 80);
    Text highscore(fontText, "HIGH SCORE:", 65.f, 100.f, sf::Color::White, 100);
    Text title(fontText, "PUG RUN", 190.f, 0.f, sf::Color::White, 150);
    Text text(fontText, " ", 290.f, 0.f, sf::Color::White, 80);
    Text Instructions(fontText, " LEFT AND RIGHT ARROW KEYS TO MOVE\n UP ARROW KEY TO BARK\n SPACE BAR TO JUMP\n ----------------------------\n DODGE THE CANNON BALLS FOR AS\n LONG AS YOU CAN\n ----------------------------\n YOUR HIGH SCORE WILL BE DISPLAYED\n AFTER THE GAME ENDS   ->", 0.f, 0.f, sf::Color::White, 60);
    Text cont(fontText, "CONTINUE", 575.f, 510.f, sf::Color::White, 60);
  

    sf::Music music;
    music.openFromFile("rhythm_factorymix4.ogg");
    music.play();

    sf::SoundBuffer buffer("Dog Bark.wav");
    sf::Sound sound(buffer);

    sf::SoundBuffer buffer2("SoundJump1.wav");
    sf::Sound sound2(buffer2);

    sf::SoundBuffer buffer3("SoundLand1.wav");
    sf::Sound sound3(buffer3);

    sf::SoundBuffer buffer4("stepstone_5.wav");
    sf::Sound sound4(buffer4);


    sf::Texture texture;
    if (!texture.loadFromFile("Ground_01.png")) {  // Adjust the path to your PNG file
        std::cerr << "Error: Could not load texture." << std::endl;
        // Return if there's an error loading the texture
    }



    sf::Texture forest;
    if (!forest.loadFromFile("forest.jpg")) {  // Adjust the path to your PNG file
        std::cerr << "Error: Could not load texture." << std::endl;
        return 0;
        // Return if there's an error loading the texture
    }

    sf::Texture pug;
    if (!pug.loadFromFile("pug-001.png")) {  // Adjust the path to your PNG file
        std::cerr << "Error: Could not load texture." << std::endl;
        // Return if there's an error loading the texture

    }

    sf::Texture enemey;
    if (!enemey.loadFromFile("cannonbobmouth.png")) {  // Adjust the path to your PNG file
        std::cerr << "Error: Could not load texture." << std::endl;
        // Return if there's an error loading the texture
        return 0;
    }

    sf::Texture pokemon;
    if (!pokemon.loadFromFile("abomasnow_front.png")) {  // Adjust the path to your PNG file
        std::cerr << "Error: Could not load texture." << std::endl;
        // Return if there's an error loading the texture
        return 0;
    }

    sf::Sprite poki(pokemon);
    poki.setScale(sf::Vector2f(10.f, 10.f));


    //ANIMATIONS
    sf::Sprite animationPug(pug);
    animationPug.setTexture(pug);

    sf::IntRect rect({ 0, 0 }, { 32, 32 });

    animationPug.setTextureRect(rect);


    Direction currentDir = Direction::None;


    Animation animation(pug, 3, 4, 0.1f, 3, true);
    sf::Clock clock;

    sf::Sprite green(forest);

    green.setScale(sf::Vector2f(1.f, 1.f));
    green.setPosition(sf::Vector2f(-250.f, -100.f));
    green.setTexture(forest);


    //Vector that pushes all the rectangles and hidden circles you see in the game. The cannon balls
    //are secretly just hidden circles that the sprite follows. Enables polymorphism for drawing both rectangles
    //and circles
    std::vector<Shape*> shapes;

    shapes.push_back(new Rectangle(120.f, 530.f, 128.f, 128.f, sf::Color::White));

    shapes.push_back(new Rectangle(570.f, 530.f, 100.f, 100.f, sf::Color::White));
    shapes.push_back(new Rectangle(640.f, 430.f, 192.f, 192.f, sf::Color::White));

    shapes.push_back(new Rectangle(30.f, 420.f, 64.f, 64.f, sf::Color::White));
    shapes.push_back(new Rectangle(94.f, 420.f, 64.f, 64.f, sf::Color::White));
    shapes.push_back(new Rectangle(270.f, 330.f, 128.f, 128.f, sf::Color::White));//
    shapes.push_back(new Rectangle(398.f, 330.f, 128.f, 128.f, sf::Color::White));//

    shapes.push_back(new Rectangle(55.f, 250.f, 32.f, 32.f, sf::Color::White));
    shapes.push_back(new Rectangle(23.f, 250.f, 32.f, 32.f, sf::Color::White));
    shapes.push_back(new Rectangle(0.f, 250.f, 32.f, 32.f, sf::Color::White));
    shapes.push_back(new Rectangle(87.f, 250.f, 32.f, 32.f, sf::Color::White));
    shapes.push_back(new Rectangle(119.f, 250.f, 32.f, 32.f, sf::Color::White));

    shapes.push_back(new Rectangle(320.f, 225.f, 150.f, 7.f, sf::Color::White));

    shapes.push_back(new Rectangle(600.f, 150.f, 128.f, 128.f, sf::Color::White));
    shapes.push_back(new Rectangle(728.f, 150.f, 128.f, 128.f, sf::Color::White));//
    shapes.push_back(new Rectangle(0.f, 90.f, 64.f, 64.f, sf::Color::White));
    shapes.push_back(new Rectangle(64.f, 90.f, 64.f, 64.f, sf::Color::White));
    shapes.push_back(new Rectangle(128.f, 90.f, 64.f, 64.f, sf::Color::White));
    shapes.push_back(new Rectangle(280.f, 35.f, 200.f, 50.f, sf::Color::Black));

    shapes.push_back(new Circle(100.f, 400.f, 56.f, sf::Color::Magenta, -2.0f, 0.f, enemey));
    shapes.push_back(new Circle(600.f, 400.f, 100.f, sf::Color::Green, 2.0f, 0.f, enemey));



    sf::Vector2u windowSize = window.getSize();
    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    bool once = false;
    float velocityY = 0.f;       // Initial vertical speed
    float gravity = 0.4f;        // Acceleration due to gravity
    float floorY = 600.f;
    bool isOnGround = true;
    float jumpStrength = -10.f;
    bool end = false;
    int seconds = 0;
    int milliseconds = 0;
    int minutes = 0;
    bool score = true;

    sf::Clock survivalClock;
    sf::Clock cooldown;
    sf::Time cooldown2 = sf::milliseconds(350);

    while (window.isOpen())
    {
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            //When you press play, everything gets reset
            if (event->is<sf::Event::MouseButtonPressed>() && gameState == gameState::mainMenu)
            {
                const auto& mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();

                if (mouseEvent->button == sf::Mouse::Button::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    if (play.getBounds().contains(mousePos))
                    {
                        shape.setPosition(sf::Vector2f(370.f, 300.f)); // wherever your player starts
                        velocityY = 0.f;
                        isOnGround = true;
                        once = false;
                        end = false;
                        survivalClock.restart();
                        clock.restart();
                        cooldown.restart();
                        cooldown2 = sf::milliseconds(250); // restore to normal cooldown if you changed it
                        text.getText().setString("0.00.000");
                        speed = 2.f;
                        negSpeed = -3.f;

                        //this code specifically clears only the circles in the vector
                        for (auto it = shapes.begin(); it != shapes.end();)
                        {
                            if (dynamic_cast<Circle*>(*it))  // If it's a Circle
                            {
                                it = shapes.erase(it);  // Removes the circle from the vector and deletes it
                            }
                            else
                            {
                                ++it;  // Move to the next element
                            }
                        }

                        shapes.push_back(new Circle(100.f, 400.f, 56.f, sf::Color::Magenta, -2.0f, 0.f, enemey));
                        shapes.push_back(new Circle(600.f, 400.f, 100.f, sf::Color::Green, 2.0f, 0.f, enemey));

                        gameState = gameState::Playing;
                    }

                    if (exit.getBounds().contains(mousePos))
                    {
                        return 0;
                    }


                    if (settings.getBounds().contains(mousePos))
                    {
                        gameState = gameState::Instructions;
                    }




                }
            }


            if (event->is<sf::Event::MouseButtonPressed>() && gameState == gameState::restart)
            {
                const auto& mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();

                if (mouseEvent->button == sf::Mouse::Button::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    if (menu.getBounds().contains(mousePos))
                    {
                        gameState = gameState::mainMenu;
                    }
                }
            }

            //Pressing the restart button resets all the variables 
            if (event->is<sf::Event::MouseButtonPressed>() && gameState == gameState::restart)
            {
                const auto& mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();

                if (mouseEvent->button == sf::Mouse::Button::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    if (restart.getBounds().contains(mousePos))
                    {
                        shape.setPosition(sf::Vector2f(370.f, 300.f)); // wherever your player starts
                        velocityY = 0.f;
                        isOnGround = true;
                        once = false;
                        end = false;
                        survivalClock.restart();
                        clock.restart();
                        cooldown.restart();
                        cooldown2 = sf::milliseconds(250); // restore to normal cooldown if you changed it
                        text.getText().setString("0.00.000");
                        speed = 2.f;
                        negSpeed = -3.f;

                        for (auto it = shapes.begin(); it != shapes.end();)
                        {
                            if (dynamic_cast<Circle*>(*it))  // If it's a Circle
                            {
                                it = shapes.erase(it);  // Removes the circle from the vector and deletes it
                            }
                            else
                            {
                                ++it;  // Move to the next element
                            }
                        }

                        shapes.push_back(new Circle(100.f, 400.f, 56.f, sf::Color::Magenta, -2.0f, 0.f, enemey));
                        shapes.push_back(new Circle(600.f, 400.f, 100.f, sf::Color::Green, 2.0f, 0.f, enemey));

                        gameState = gameState::Playing;
                    }
                }
            }


            if (event->is<sf::Event::MouseButtonPressed>() && gameState == gameState::Instructions)
            {
                const auto& mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();

                if (mouseEvent->button == sf::Mouse::Button::Left)
                {
                    if (cont.getBounds().contains(mousePos))
                    {
                        gameState = gameState::mainMenu;
                    }

                }
            }


        }
            window.clear();

            switch (gameState)
            {
            case gameState::mainMenu:
            {
                window.draw(green);
                title.draw(window);
                play.draw(window);

                
                settings.draw(window);

                exit.draw(window);

                if (play.getBounds().contains(mousePos))
                {
                    play.getText().setFillColor(sf::Color::Yellow); // Highlight
                }
                else
                {
                    play.getText().setFillColor(sf::Color::White); // Normal
                }

                if (exit.getBounds().contains(mousePos))
                {
                    exit.getText().setFillColor(sf::Color::Yellow); // Highlight
                }
                else
                {
                    exit.getText().setFillColor(sf::Color::White); // Normal
                }

                if (settings.getBounds().contains(mousePos))
                {
                    settings.getText().setFillColor(sf::Color::Yellow);
                }
                else
                {
                    settings.getText().setFillColor(sf::Color::White);
                }



                break;
            }


            case gameState::Playing:
            {
                if (!end)
                {

                    score = true;
                    text.getText().setCharacterSize(80);
                    text.getText().setPosition(sf::Vector2f(290.f, 0.f));

                    bool wasOnGround = isOnGround;

                    sf::Time timeElapsed = survivalClock.getElapsedTime();
                    int totalMilliseconds = static_cast<int>(timeElapsed.asMilliseconds());
                    window.setMouseCursorVisible(false);

                    //Timer 
                    minutes = totalMilliseconds / 60000;
                    seconds = (totalMilliseconds / 1000) % 60;
                    milliseconds = totalMilliseconds % 1000;

                    std::stringstream ss;
                    ss << std::setfill('0') << std::setw(1) << minutes << ".";
                    ss << std::setfill('0') << std::setw(2) << seconds << ".";
                    ss << std::setfill('0') << std::setw(3) << milliseconds;

                    text.getText().setString(ss.str());

                    sf::Time deltaTime = clock.restart();

                    float delts = deltaTime.asSeconds();

                    animation.setDirection(currentDir);

                    animation.setPosition(shape.getPosition().x + 15.f, shape.getPosition().y); // Set position of animated sprite

                    sf::Vector2f pos = shape.getPosition();
                    sf::FloatRect circleBounds = shape.getGlobalBounds();

                    bool blockRight = false;
                    bool blockLeft = false;

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                        sound.play();

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && isOnGround) {
                        velocityY = jumpStrength;
                        isOnGround = false;

                        sound2.play();
                    }

                    velocityY += gravity;                         // Add gravity to velocity
                    shape.move(sf::Vector2f(0.f, velocityY));                    // Move the ball by velocity


                    // ground collision
                    if (shape.getPosition().y + shape.getRadius() * 2 > floorY)
                    {
                        shape.setPosition(sf::Vector2f(shape.getPosition().x, floorY - shape.getRadius() * 2));
                        velocityY = 0.f; // Stop falling when on the ground
                        isOnGround = true;



                    }

                    if (isOnGround && !wasOnGround)
                    {
                        sound3.play();

                    }

                    wasOnGround = isOnGround;

                    animationPug.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y));


                    for (auto& genericShape : shapes)
                    {

                        if (Circle* ball = dynamic_cast<Circle*> (genericShape))
                        {
                            ball->Update(delts);

                            float rightSide = genericShape->getBounds().position.x + 2 * ball->getRadius();
                            float leftSide = genericShape->getBounds().position.x - ball->getRadius();

                            if (rightSide < 0)
                            {
                                ball->setSpeed(speed, 0.f);
                                ball->setRandomSize();
                                ball->shapeToSprite();
                                ball->setRandomCords();

                                speed = (++speed) - 0.9f;
                            }

                            if (leftSide > 770)
                            {
                                ball->setSpeed(negSpeed, 0.f);
                                ball->setRandomSize();
                                ball->shapeToSprite();
                                ball->setRandomCords();

                                negSpeed = (--negSpeed) + 0.9f;
                            }

                            if (ball->checkCircles(shape.getPosition(), shape.getRadius(), ball->getShape().getPosition(), ball->getRadius()))
                            {
                                end = true;
                            }



                            /////////////RECTANGLE LOGIC////////////////////////////////////////
                        }
                        else if (Rectangle* platform = dynamic_cast<Rectangle*> (genericShape))
                        {

                            platform->setRectTexture(texture);


                            if (platform->checkCeilingCollision(circleBounds, velocityY))
                            {
                                velocityY = 0.f;
                            }

                            if (platform->checkLandingCollision(circleBounds, velocityY))
                            {
                                float circleBottom = circleBounds.position.y + circleBounds.size.y;
                                float platformTop = genericShape->getBounds().position.y;

                                shape.setPosition({ shape.getPosition().x, platformTop - circleBounds.size.y });
                                velocityY = 0.f;
                                isOnGround = true;

                            }


                            if (circleBounds.findIntersection(platform->getBounds()))
                            {
                                if (circleBounds.position.x + circleBounds.size.x <= genericShape->getBounds().position.x + 5.f)
                                {
                                    // std::cout << "RIGHT" << std::endl;
                                    blockRight = true;
                                }
                                else if (circleBounds.position.x >= genericShape->getBounds().position.x + genericShape->getBounds().size.x - 5.f)
                                {
                                    // std::cout << "LEFT" << std::endl;
                                    blockLeft = true;
                                }
                            }
                        }
                    }



                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && pos.x > 0 && !blockLeft)
                    {
                        shape.move(sf::Vector2f(-5.f, 0.f));
                        animationPug.move(sf::Vector2f(-5.f, 0.f));
                        currentDir = Direction::Right;
                        animation.setDirection(Direction::Right);
                        animation.update(deltaTime.asSeconds());

                        if (cooldown.getElapsedTime() >= cooldown2 && isOnGround && velocityY == 0.f)
                        {
                            sound4.play();

                            cooldown.restart();
                        }

                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && pos.x + shape.getRadius() * 2 < windowWidth && !blockRight)
                    {
                        shape.move(sf::Vector2f(5.f, 0.f));
                        animationPug.move(sf::Vector2f(5.f, 0.f));
                        currentDir = Direction::Left;
                        animation.setDirection(Direction::Left);
                        animation.update(deltaTime.asSeconds());

                        if (cooldown.getElapsedTime() >= cooldown2 && isOnGround && velocityY == 0.f)
                        {
                            sound4.play();

                            cooldown.restart();
                        }

                    }

                    window.draw(green);

                    for (auto& shape : shapes)
                    {
                        shape->draw(window);

                    }

                    if (seconds == 30 && once == false)
                    {
                        shapes.push_back(new Circle(0.f, 244.f, 100.f, sf::Color::Yellow, -2.0f, 0.f, enemey));

                        once = true;

                    }


                    window.draw(animation.getSprite());
                    text.draw(window);

                    if (end)
                    {
                        gameState = gameState::gameOver;

                    }
                }
                break;

            } // PLAYING

            case gameState::gameOver:
            {
                window.draw(green);

                //Polymorhpism
                for (auto& shape : shapes)
                {
                    shape->draw(window);
                }


                window.draw(animation.getSprite());
                text.draw(window);

                fail.draw(window);

                cooldown2 = sf::milliseconds(2500);

                if (cooldown.getElapsedTime() >= cooldown2)
                {

                    cooldown.restart();

                    gameState = gameState::restart;
                }
                break;
            }

            case gameState::restart:
            {

                if (score)
                {
                    //reads the high score in a file and determines if its larger than the current score 
                    std::ifstream read("HighScore.txt");

                    int newMinutes = 0, newSeconds = 0, newMilli = 0;

                    read >> x;

                    read.close();

                    std::stringstream y(x);
                    std::string token;

                    std::getline(y, token, ':');
                    newMinutes = std::stoi(token);

                    std::getline(y, token, ':');
                    newSeconds = std::stoi(token);

                    std::getline(y, token, ':');
                    newMilli = std::stoi(token);

                    double currentScore = (minutes * 60 * 1000) + (seconds * 1000) + milliseconds;
                    double oldScore = (newMinutes * 60 * 1000) + (newSeconds * 1000) + newMilli;

                    if (currentScore > oldScore)
                    {
                        std::ofstream infile("HighScore.txt");

                        infile << minutes << ":" << seconds << ":" << milliseconds << std::endl;

                        std::stringstream ss;
                        ss << std::setfill('0') << std::setw(1) << minutes << ".";
                        ss << std::setfill('0') << std::setw(2) << seconds << ".";
                        ss << std::setfill('0') << std::setw(3) << milliseconds;

                        text.getText().setString(ss.str());


                    }
                    else {

                        std::stringstream ss2;
                        ss2 << std::setfill('0') << std::setw(1) << x;

                        text.getText().setString(ss2.str());
                    }



                    score = false;

                }


                text.getText().setCharacterSize(100);
                text.getText().setPosition(sf::Vector2f(465.f, 100.f));

                window.draw(green);
                restart.draw(window);
                menu.draw(window);
                highscore.draw(window);
                text.draw(window);
                window.setMouseCursorVisible(true);

                if (menu.getBounds().contains(mousePos))
                {
                    menu.getText().setFillColor(sf::Color::Yellow); // Highlight
                }
                else
                {
                    menu.getText().setFillColor(sf::Color::White); // Normal
                }

                if (restart.getBounds().contains(mousePos))
                {
                    restart.getText().setFillColor(sf::Color::Yellow); // Highlight
                }
                else
                {
                    restart.getText().setFillColor(sf::Color::White); // Normal

                }

                break;

            }
              case gameState::Instructions:
              {
                window.draw(green);

                Instructions.draw(window);

                cont.draw(window);

                if (cont.getBounds().contains(mousePos))
                {
                    cont.getText().setFillColor(sf::Color::Yellow); // Highlight
                }
                else
                {
                    cont.getText().setFillColor(sf::Color::White); // Normal
                }

                break;

              }




            }
            window.display();

        
    }
}