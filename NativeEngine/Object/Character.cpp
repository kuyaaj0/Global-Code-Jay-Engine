#include "Character.hpp"

Character::Character()
{
    alpha = 1.0f;

    visible = true;

    flipX = false;

    flipY = false;

    singing = false;

    singTimer = 0.0f;

    singDuration = 0.15f;
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

bool Character::IsSinging() const
{
    return singing;
}

void Character::SetSinging(bool value)
{
    singing = value;

    if(value)
        singTimer = 0.0f;
}

void Character::SingLeft()
{
    SetSinging(true);
}

void Character::SingDown()
{
    SetSinging(true);
}

void Character::SingUp()
{
    SetSinging(true);
}

void Character::SingRight()
{
    SetSinging(true);
}

void Character::Miss()
{
    SetSinging(true);
}

void Character::Update(float dt)
{
    if(singing)
{
    singTimer += dt;

    if(singTimer >= singDuration)
    {
        singing = false;

        Idle();
    }
}
}

void Character::Render(
Renderer* renderer
)
{
    sprite.Draw(renderer);
}
