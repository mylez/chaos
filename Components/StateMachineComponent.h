#ifndef CHAOS_STATEMACHINECOMPONENT_H
#define CHAOS_STATEMACHINECOMPONENT_H

#include <Core/Component.h>
#include <unordered_map>

/**
 *   // example of appropriate enumerations and transition table
 *
 *
 *   enum MyState {
 *       A,
 *       B
 *   };
 *
 *   enum MyAction {
 *       GoToA,
 *       GoToB
 *   };
 *
 *    ___                ___
 *   | A | -- GoToB --> | B |
 *    ---                ---
 *   c->setTransitionTable(
 *       {
 *           {MyState::A, {
 *                            {MyAction::GoToB, MyState::B},
 *                        }}
 *       });
 *
 *
 *
 */

struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

template <typename State, typename Action>
class StateMachineComponent:
    public Component
{
private:
    State currentState;

    std::unordered_map<State, std::unordered_map<Action, State, EnumClassHash>, EnumClassHash> transitionTable;

public:

    /**
     *
     * @param table
     */
    void setTransitionTable(std::unordered_map<State, std::unordered_map<Action, State, EnumClassHash>, EnumClassHash> table)
    {
        transitionTable = table;
    }

    /**
     *
     * @param action
     * @return
     */
    bool performTransition(Action action)
    {
        if (canTransition(action))
        {
            goToState(transitionTable[currentState][action]);
            return true;
        }
        return false;
    }

    /**
     *
     * @param action
     * @return
     */
    bool canTransition(Action action)
    {
        if (transitionTable[currentState].find(action) != transitionTable[currentState].end())
        {
            return true;
        }
        return false;
    }

    /**
     *
     * @param state
     */
    void goToState(State state)
    {
        currentState = state;
    }

    State getCurrentState()
    {
        return currentState;
    }

};


#endif //CHAOS_STATEMACHINECOMPONENT_H
