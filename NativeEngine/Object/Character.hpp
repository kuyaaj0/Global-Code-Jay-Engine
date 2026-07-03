#pragma once

#include "../Transform/Transform.hpp"
#include "../Gameplay/CharacterData.hpp"
#include "../Graphics/Sprite.hpp"
#include "../Graphics/Texture.hpp"
#include "../Graphics/SpriteAtlas.hpp"
#include "../Graphics/SpriteRenderer.hpp"
#include "../Animation/Animator.hpp"

class Character
{
public:

    Character();

    void Load(const CharacterData& data);

    Vector3 GetPosition() const;

    void SetPosition(
        const Vector3& position
    );

    Vector3 GetCameraFocus() const;

    const CharacterData& GetData() const;

    void Idle();

    bool IsSinging() const;

    void SetSinging(bool value);

    void SingLeft();

    void SingDown();

    void SingUp();

    void SingRight();

    void Sing(
    int lane);

    void Miss();

    void Update(float dt);

    void Render(Renderer* renderer);

public:

    Transform transform;

    float alpha;

    bool visible;

    bool flipX;

    bool flipY;

private:

    Texture texture;

    SpriteAtlas atlas;

    Animator animator;

    SpriteRenderer spriteRenderer;

    bool singing;

    float singTimer;

    float singDuration;

    CharacterData characterData;

    Sprite sprite;
};
