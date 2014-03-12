#ifndef TTT_LOGIC_H_INCLUDED
#define TTT_LOGIC_H_INCLUDED

//  Tic-tac-toe is played by two players, X (CROSS) and O (NOUGHT).
//  A position on the board can be occupied by either player or
//  neither player (NONE).
//
//  These enum values are used in the following ways:
//      - return value of the look function
//      - return value of the current_player function

enum Player
{
    NOUGHT,  //  Player O's mark
    CROSS,   //  Player X's mark
    NONE     //  Neither player; the location has no mark
};


//  We will use nine enum values to represent conveniently
//  the nine board locations. The enum value names are chosen from
//  the points on a compass:
//
//            |        |
//  NORTHWEST | NORTH  | NORTHEAST
//            |        |
//  ----------+--------+----------
//            |        |
//    WEST    | CENTER |   EAST
//            |        |
//  ----------+--------+----------
//            |        |
//  SOUTHWEST | SOUTH  | SOUTHEAST
//            |        |
//
//  These enum values are used in the following ways:
//      - parameter to the move function
//      - parameter to the look function

enum Location
{
    NORTHWEST,  // left-top corner  (northwest)
    NORTH,      // center-top       (north)
    NORTHEAST,  // right-top corner (northeast)
    EAST,       // right-center     (east)
    SOUTHEAST,  // right-bottom     (southeast)
    SOUTH,      // center-bottom    (south)
    SOUTHWEST,  // left-bottom      (southwest)
    WEST,       // left-center      (west)
    CENTER,     // center square
    NOWHERE     // Unknown location
};


//  Board status values.
//  There are seven winning board cofigurations.  In addition,
//  there is one way for the game to end in a draw.  If the game is
//  not over yet because moves are available, then no one has won
//  or tied.  We encode these possible scenarios into the following
//  enum values representing the status of the board
//
//  These enum values are used as the return value of the
//  check_status function

enum Status
{
    PLAYING,   //  No one has won and a move is available
    WIN_NW_NE, //  Win across top row
    WIN_W_E,   //  Win across middle row
    WIN_SW_SE, //  Win across bottom row
    WIN_NW_SW, //  Win along left column
    WIN_N_S,   //  Win along center column
    WIN_NE_SE, //  Win along right column
    WIN_NW_SE, //  Win from left-top corner to right-bottom corner
    WIN_NE_SW, //  Win from right-top corner to left-bottom corner
    DRAW       //  All squares filled with no winner
};

//  check_status checks to see if either player has won or if the
//  board is filled.  The function returns the status of the board.
//  The status is one of PLAYING, WIN_NW_NE, WIN_W_E, etc.
Status check_status();

//  Places the current player's mark at the given location, if possible.
//  The function returns true if the move can be made.  The move is
//  only possible if the location is currently empty.  If a player
//  attempts to move to an occupied location, the function does not
//  change the board and it returns false.  If the location is
//  available (empty), the player's mark is placed in the location
//  and the function returns true.
//  The move function also controls alteranting to the next player
//  if the move was successful.
bool move(Location location);

//  Returns the player whose turn it is to move.  This allows the
//  presentation to report whose turn it is.
//  Return value is one of the constants NOUGHT or CROSS
Player current_player();

//  Sets the current player.  Useful for games that require the
//  player to answer a question correctly before a move.  If the
//  player answers incorrectly, the turn moves to the opponent.
//  Valid values for player are NOUGHT or CROSS; all other values
//  have no effect.
void set_player(Player new_player);

//  Returns the mark at the given location.
//  Returns NONE if neither player has marked
//  the given location.  The function's valid return
//  values are NONE, CROSS, or NOUGHT.
//  This function allows the presentation to draw the contents
//  of the Tic-Tac-Toe board.
Player look(Location location);

//  Make all the board locations empty and set current player to X
//  (that is, reset to the start of a new game)
void clear_board();


#endif // TTT_LOGIC_H_INCLUDED