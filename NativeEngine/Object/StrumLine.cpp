#include "StrumLine.hpp"

#include "Note3D.hpp"
#include "../Renderer/Renderer.hpp"
#include "../States/InputManager.hpp"
#include "../Math/Matrix4.hpp"
#include "../Math/Vector4.hpp"

#include <cmath>

StrumLine::StrumLine()
{
    for(int i = 0; i < 4; i++)
    {
        lanePosition[i] = Vector3();
    }

    // bottom screen positions
    lanePosition[0].x = -180.0f;
    lanePosition[1].x = -60.0f;
    lanePosition[2].x = 60.0f;
    lanePosition[3].x = 180.0f;

    for(int i = 0; i < 4; i++)
    {
        lanePosition[i].y = -250.0f;
    }

    for(int i = 0; i < 4; i++)
{
    lanePosition[i] = Vector3();
    hitFlash[i] = 0.0f;
}
}

void StrumLine::Render(Renderer* renderer)
{
    if(renderer == nullptr)
        return;

    float size = 80.0f;

    for(int i = 0; i < 4; i++)
    {
        float flash = hitFlash[i];

        // base color intensity (fake lighting effect)
        float scale = 1.0f + flash * 0.25f;

        Matrix4 world =
            Matrix4::Translation(
                lanePosition[i].x,
                lanePosition[i].y,
                0.0f
            ) *
            Matrix4::Scale(
                scale,
                scale,
                1.0f
            );

        Vector4 quad[4];

        quad[0] = Vector4(-size, -size, 0.0f, 1.0f);
        quad[1] = Vector4( size, -size, 0.0f, 1.0f);
        quad[2] = Vector4( size,  size, 0.0f, 1.0f);
        quad[3] = Vector4(-size,  size, 0.0f, 1.0f);

        renderer->DrawQuad(world, quad);
    }
}

void StrumLine::Update(InputManager* input)
{
    for(int i = 0; i < 4; i++)
    {
        if(input->IsLanePressed(i))
        {
            hitFlash[i] = 1.0f; // full brightness
        }

        // decay over time
        hitFlash[i] *= 0.85f;

        if(hitFlash[i] < 0.01f)
            hitFlash[i] = 0.0f;
    }
}

JudgeResult
StrumLine::Judge(
int lane,
float songPosition,
NoteManager* notes)
{

    Note3D* note =
        notes->FindClosestNote(
            lane,
            songPosition
        );

    if(note == nullptr)
    {
        return JudgeResult::Miss;
    }

    float diff =
        fabs(
            note->GetTime() -
            songPosition
        );

    if(diff <= 22.0f)
    {
        notes->MarkHit(note);

        return JudgeResult::Marvelous;
    }

    if(diff <= 45.0f)
    {
        notes->MarkHit(note);

        return JudgeResult::Sick;
    }

    if(diff <= 90.0f)
    {
        notes->MarkHit(note);

        return JudgeResult::Good;
    }

    if(diff <= 135.0f)
    {
        notes->MarkHit(note);

        return JudgeResult::Bad;
    }

    return JudgeResult::Miss;
}
