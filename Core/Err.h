//
// Created by Miles on 2/17/16.
//

#ifndef CHAOS_ERR_H
#define CHAOS_ERR_H

#include <string>
#include <SDL2/SDL_error.h>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// errors
class Err
{
public:
    string msg = "";


    /**
     *
     * @param _msg
     */
    Err(string _msg)
    {
        msg = _msg;
    }

    /**
     *
     * @return
     */
    virtual string message()
    {
        return msg;
    }


    /**
     *
     * @param p
     * @param msg
     */
    static void predicate(bool p, string msg = "")
    {
        if (!p)
        {
            if (msg != "")
            {
                cout << "Error: " << msg << endl;
            }
            cout << "SDL_GetError: " << SDL_GetError() << endl;
            throw Err(msg);
        }
    }
};



#endif //CHAOS_ERR_H
