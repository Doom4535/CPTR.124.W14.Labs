//
//  Tic.Tac.Toe.Game.Engine
//
//  Created by Aaron Covrig on 3/12/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>
#include "ttt_logic.h"
#include "ticktacktoe.cpp"
using namespace std;

enum Status Playing, Win_NW_NE, Win_W_E, Win_SW_SE, Win_NW_SW, Win_N_S, Win_NE_SE, Win_NW_SE, Win_NE_SW, Draw;

static Player NW_player, N_player, NE_player, W_player, C_player, E_player, SW_player, S_player, SE_player;

Player now_playing = NONE;


Status game_over = Playing; //set status to playing (inprogress)

Location sq;

Status check_status() {
    return game_over;
}


bool move(Location location) {
    if (location == NORTHWEST && NW_player == NONE) {
        NW_player = current_player();
        return true;
    }
    
    if (location == NORTH && N_player == NONE) {
        N_player = current_player();
        return true;
    }
    
    if (location == NORTHEAST && NE_player == NONE) {
        NE_player = current_player();
        return true;
    }
    
    if (location == WEST && W_player == NONE) {
        W_player = current_player();
        return true;
    }
    
    if (location == CENTER && C_player == NONE) {
        C_player = current_player();
        return true;
    }
    
    if (location == EAST && E_player == NONE) {
        E_player = current_player();
        return true;
    }
    
    if (location == SOUTHWEST && SW_player == NONE) {
        SW_player = current_player();
        return true;
    }
    
    if (location == SOUTH && S_player == NONE) {
        S_player = current_player();
        return true;
    }
    
    if (location == SOUTHEAST && SE_player == NONE) {
        SE_player = current_player();
        return true;
    }
    
    else
        return false;

    // else
        // return "Invalid move, this square is already owned"  Is this needed?
}

Player current_player() {
    // now_playing = NONE;
    return now_playing;
    }
    
void set_player(Player new_player) {
    now_playing = new_player;
}

Player look(Location location) {
    switch (location) {
        case NORTHWEST:
            return NW_player;
            break;
        case NORTH:
            return N_player;
            break;
        case NORTHEAST:
            return NE_player;
            break;
        case WEST:
            return W_player;
            break;
        case CENTER:
            return C_player;
            break;
        case EAST:
            return E_player;
            break;
        case SOUTHWEST:
            return SW_player;
            break;
        case SOUTH:
            return S_player;
            break;
        case SOUTHEAST:
            return SE_player;
            break;
        
        default:
            return NONE;
            break;
    }
    
}

void clear_board() {
    
}

    

