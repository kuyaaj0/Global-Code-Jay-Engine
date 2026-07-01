#include "Character.hpp"

Character::Character()
{
    alpha = 1.0f;

    visible = true;

    flipX = false;

    flipY = false;
}

Vector3 Character::GetPosition() const
{
    return transform.GetPosition();
}

void Character::SetPosition(
const Vector3& position)
{
    transform.SetPosition(position);
}

void Character::Load(const CharacterData& data)
{
    characterData = data;

    flipX = data.flipX;
    flipY = data.flipY;

    // Later:
    // Load sprite atlas
    // Load XML
    // Load animations
    // Load offsets
}

Vector3 Character::GetCameraFocus() const
{
    return
        transform.GetPosition()
        + characterData.cameraOffset;
}

const CharacterData& Character::GetData() const
{
    return characterData;
}

void Character::Idle()
{
    // TODO:
    // Play idle animation
}

void Character::SingLeft()
{

}

void Character::SingDown()
{

}

void Character::SingUp()
{

}

void Character::SingRight()
{

}

void Character::Miss()
{

}

void Character::Update(float dt)
{

}

void Character::Render(
Renderer* renderer
)
{
    sprite.Draw(renderer);
}
