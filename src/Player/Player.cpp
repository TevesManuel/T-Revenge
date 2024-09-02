#include <GameObjects/Player/Player.hpp>

#define PLAYER_VELOCITY 100.0f

#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 50

Player::Player(Window * windowPtr)
{
    if (!this->texture.loadFromFile("./Assets/Sprites/EnemyRifle.png"))
    {
        exit(-1);
    }
    
    this->sprite.setTexture(texture);
    this->sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f);

    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(400.0f, 400.0f);
    this->body = windowPtr->addBodyDef(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(PLAYER_WIDTH/2, PLAYER_HEIGHT/2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

void Player::update(sf::RenderWindow * windowPtr)
{
    b2Vec2 position = this->body->GetPosition();
    
    sprite.setPosition(sf::Vector2f(position.x, position.y));

    b2Vec2 direction;
    direction.x = 0;
    direction.y = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        direction.x = -1 * PLAYER_VELOCITY;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        direction.x = 1 * PLAYER_VELOCITY;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        direction.y = -1 * PLAYER_VELOCITY;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        direction.y = 1  * PLAYER_VELOCITY;
    this->body->SetLinearVelocity(direction);

    double diffx = sf::Mouse::getPosition(*windowPtr).x - position.x;
    double diffy = sf::Mouse::getPosition(*windowPtr).y - position.y;
    float relation = diffx/diffy;
    float angle = atan2(diffy, diffx) - (b2_pi/2);
    body->SetTransform(position, angle);
    sprite.setRotation(angle * (180.0f / b2_pi));
}

#include <Primitive/PrimitiveGraphics.hpp>

void Player::render(sf::RenderWindow * windowPtr)
{
    windowPtr->draw(this->sprite);
    sf::CircleShape circle(1.0f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(this->sprite.getPosition());
    
    auto mousePos = sf::Mouse::getPosition(*windowPtr);
    auto playerPos = this->sprite.getPosition();
    TPG::drawLine(playerPos, sf::Vector2f(mousePos.x, mousePos.y), windowPtr, sf::Color::Green);
    TPG::drawLine(sf::Vector2f(playerPos.x, playerPos.y), sf::Vector2f(mousePos.x, playerPos.y), windowPtr, sf::Color::Red);
    TPG::drawLine(sf::Vector2f(mousePos.x, playerPos.y), sf::Vector2f(mousePos.x, mousePos.y), windowPtr, sf::Color::Blue);
    TPG::drawRect(playerPos, this->sprite.getGlobalBounds().getSize(), windowPtr, sf::Color::Yellow);

    windowPtr->draw(circle);
}