#include <GameObjects/Wall/Wall.hpp>

Wall::Wall(Engine * windowPtr, WallTypes::types wallType)
{
    //Load the texture
    this->label = "WALL";
    bool isLoaded = false;
    if(wallType == WallTypes::NORMAL)
    {
        isLoaded = this->texture.loadFromFile("./Assets/Sprites/Wall.png");
    }
    if(!isLoaded)
    {
        printf("\n---------------------------------------------------------\n");
        printf("[!] Error to load texture for Wall in %ds", clock() / CLOCKS_PER_SEC);
        printf("\n---------------------------------------------------------\n\n");
        exit(-1);
    }
    float x = 100;
    float y = 100;

    this->texture.setRepeated(true);
    this->sprite.setTexture(texture);
    // this->sprite.setTextureRect(sf::IntRect(0, 0, 2512, 2512));
    this->sprite.setScale(sizeBox/this->sprite.getGlobalBounds().width,
                            sizeBox/this->sprite.getGlobalBounds().height);
    // std::cout << "x: " << this->sprite.getGlobalBounds().width << " y: " << this->sprite.getLocalBounds().height << std::endl; 
    this->sprite.setOrigin(sf::Vector2f(
        250,
        250
    ));
    this->sprite.setPosition(sf::Vector2f(x, y));
    
    // Define the body
    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    bodyDef.type = b2_staticBody; 
    
    // Create the body
    b2Body* wallBody = windowPtr->addBodyDef(&bodyDef);

    // Define the shape
    b2PolygonShape wallShape;
    wallShape.SetAsBox(sizeBox / 2, sizeBox / 2);

    // Create the fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &wallShape;
    fixtureDef.density = 0.0f;  // Density for a static body is irrelevant
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(this);//Save the class on the userData inside the fixture for colision detection

    // Asociate the form to the body
    wallBody->CreateFixture(&fixtureDef);

    // printf("Wall is created with ID %d\n", this->ID);
}

void Wall::render(sf::RenderWindow * windowPtr)
{
    windowPtr->draw(this->sprite);
    TPG::drawPoint(this->sprite.getPosition(), 1, windowPtr, sf::Color::Green);
}
