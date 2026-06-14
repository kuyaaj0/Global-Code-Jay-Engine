#include "StrumLine.hpp"

StrumLine::StrumLine()
{

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
