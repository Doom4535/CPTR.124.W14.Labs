//
//  Tic.Tac.Toe.Game.Engine
//
//  Created by Aaron Covrig on 3/12/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>
#include "ttt_logic.h"
using namespace std;



// enum Status Playing, Win_NW_NE, Win_W_E, Win_SW_SE, Win_NW_SW, Win_N_S, Win_NE_SE, Win_NW_SE, Win_NE_SW, Draw;

static Player NW_player = NONE, N_player = NONE, NE_player = NONE, W_player = NONE, C_player = NONE, E_player = NONE, SW_player = NONE, S_player = NONE, SE_player = NONE;

// Setting starting player to None (blank board)
/* Player NW_player && N_player && NE_player && W_player && C_player && E_player && SW_player && S_player && SE_player = NONE;
 */

Player now_playing = CROSS;
Player last_play;


Status game_over = PLAYING; //set status to playing (inprogress)

int round = 0;

Location sq;

void cycle_player(Player now_playing) {
    if (now_playing == CROSS)
        ::now_playing = NOUGHT;
    else if (now_playing == NOUGHT)
        ::now_playing = CROSS;
}

Status check_status() {
    /* if (last_play == CROSS)
        last_play = NOUGHT;
    else if (last_play == NOUGHT)
        last_play = CROSS; */
    if (NW_player == last_play && N_player == last_play && NE_player == last_play)
        game_over = WIN_NW_NE;
    else if (W_player == last_play && C_player == last_play && E_player == last_play)
        game_over = WIN_W_E;
    else if (SW_player == last_play && S_player == last_play && SE_player == last_play)
        game_over = WIN_SW_SE;
    else if (NW_player == last_play && W_player == last_play && SW_player == last_play)
        game_over = WIN_NW_SW;
    else if (N_player == last_play && C_player == last_play && S_player == last_play)
        game_over = WIN_N_S;
    else if (NE_player == last_play && E_player == last_play && SE_player == last_play)
        game_over = WIN_NE_SE;
    else if (NW_player == last_play && C_player == last_play && SE_player == last_play)
        game_over = WIN_NW_SE;
    else if (NE_player == last_play&& C_player == last_play && SW_player == last_play)
        game_over = WIN_NE_SW;
    round++;
    if (round == 9 && game_over == PLAYING)
        game_over = DRAW;
    return game_over;
    
}

bool move(Location location) {
    if (location == NORTHWEST && NW_player == NONE) {
        NW_player = current_player();
        last_play = current_player();
        cycle_player(current_player());
        return true;
    }
    
    if (location == NORTH && N_player == NONE) {
        N_player = current_player();
        last_play = current_player();
        cycle_player(current_player());
        return true;
    }
    
    if (location == NORTHEAST && NE_player == NONE) {
        NE_player = current_player();
        last_play = current_player();
        cycle_player(current_player());
        return true;
    }
    
    if (location == WEST && W_player == NONE) {
        W_player = current_player();
        last_play = current_player();
        cycle_player(current_player());
        return true;
    }
    
    if (location == CENTER && C_player == NONE) {
        C_player = current_player();
        last_play = current_player();
        cycle_player(current_player());
        return true;
    }
    
    if (location == EAST && E_player == NONE) {
        E_player = current_player();
        last_play = current_player();
        cycle_player(current_player());
        return true;
    }
    
    if (location == SOUTHWEST && SW_player == NONE) {
        SW_player = current_player();
        last_play = current_player();
        cycle_player(current_player());
        return true;
    }
    
    if (location == SOUTH && S_player == NONE) {
        S_player = current_player();
        last_play = current_player();
        cycle_player(current_player());
        return true;
    }
    
    if (location == SOUTHEAST && SE_player == NONE) {
        SE_player = current_player();
        last_play = current_player();
        cycle_player(current_player());
        return true;
    }
    
    else
        return false;
    
    // void set_player(Player new_player);

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
    
    NW_player = N_player = NE_player = W_player = C_player = E_player = SW_player = S_player = SE_player = NONE;
    round = 0;
    last_play = NOUGHT;
    set_player(CROSS);
    game_over = PLAYING;
}

    

