#include "mac_03.h"
#include "entity.h"
#include "variables.h"

API_CALLABLE(N(AddOinkHatches)) {
    Bytecode* args = script->ptrReadPos;
    pendingHatches += evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnBlast_RailRock) = {
    Set(GF_MAC03_BombedRock, TRUE)
    Return
    End
};

EvtScript N(EVS_ReadSign_LilOinks) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Oinks_Multihatch, 160, 40)
    Call(ShowChoice, MSG_Oinks_Multihatch_Choice)
    Call(DisablePlayerInput, FALSE)
    Call(EndSpeech)
    Switch(LVar0)
        CaseEq(0)
            Call(N(AddOinkHatches), 5)
        CaseEq(1)
            Call(N(AddOinkHatches), 10)
        CaseEq(2)
            Call(N(AddOinkHatches), 20)
        CaseEq(3)
            Call(N(AddOinkHatches), 50)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_OnInspect_StreetSign) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_0172, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(GetDemoState, LVar0)
    IfEq(LVar0, DEMO_STATE_NONE)
        IfEq(GF_MAC03_BombedRock, FALSE)
            Call(MakeEntity, Ref(Entity_BombableRock), -200, 0, 0, 0, MAKE_ENTITY_END)
            Call(AssignScript, Ref(N(EVS_OnBlast_RailRock)))
        EndIf
    EndIf
    Call(MakeEntity, Ref(Entity_HiddenPanel), 525, 0, 175, 0, MODEL_o11, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_MAC03_HiddenPanel)
    Call(MakeEntity, Ref(Entity_Signpost), 185, 20, -350, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign_LilOinks)))
    BindTrigger(Ref(N(EVS_OnInspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    Return
    End
};
