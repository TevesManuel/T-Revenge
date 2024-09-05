#include <GameObjects/Player/Player.hpp>
#include <Engine/Primitive/PrimitiveGraphics.hpp>

#define PLAYER_VELOCITY 100.0f

sf::FloatRect dim;
sf::Vector2f pos;

Player::Player(Engine * enginePtr)
{
    if (!this->texture.loadFromFile("./Assets/Sprites/EnemyRifle.png"))
    {
        exit(-1);
    }
    
    this->sprite.setTexture(texture);
    // printf("W: %f\n", sprite.getGlobalBounds().width);
    this->sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    // printf("NW: %f\n", sprite.getGlobalBounds().width);

    pos = sprite.getPosition();
    dim = sprite.getGlobalBounds();
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(400.0f, 400.0f);
    this->body = enginePtr->addBodyDef(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(dim.width, dim.height);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(this);//Save the class on the userData inside the fixture for colision detection
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

    auto mousePos = sf::Mouse::getPosition(*windowPtr);

    double diffx = mousePos.x - position.x;
    double diffy = mousePos.y - position.y;
    float relation = diffx/diffy;
    float angle = atan2(diffy, diffx);
    body->SetTransform(position, angle);
    sprite.setRotation(angle * (180.0f / b2_pi) - 90.0f);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        // bullets.push_back(new Bullet(this->sprite.getPosition(), this->body->GetAngle()));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        this->destroy();
    }
}

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
    TPG::drawRect(pos, dim.getSize(), windowPtr, sf::Color::Yellow);
    TPG::drawPoint(playerPos, 5, windowPtr, sf::Color::Red);

    windowPtr->draw(circle);
}

void Player::onCollisionEnter(Object * collisionedObject)
{
}