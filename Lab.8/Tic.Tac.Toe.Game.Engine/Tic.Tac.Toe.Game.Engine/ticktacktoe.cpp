//  File tictactoe.cpp

#include <iostream>
#include <GL/sgl.hpp>
#include "ttt_logic.h"

using namespace sgl;

class TTTBoard: public Window
{
protected:
    Status status;
    bool cursor_visible;
    
    double cursor_x,
    cursor_y;
    
    static Location point_to_square(double x, double y)
    {
        Location result = NOWHERE;
        if ( x < 200.0 && y > 400.0 )
            result = NORTHWEST;
        else if ( x > 200.0 && x < 400.0 && y > 400.0 )
            result = NORTH;
        else if ( x > 400.0 && y > 400.0 )
            result = NORTHEAST;
        else if ( x > 400.0 && y < 400.0 && y > 200.0 )
            result = EAST;
        else if ( x > 400.0 && y < 200.0 )
            result = SOUTHEAST;
        else if ( x > 200.0 && x < 400.0 && y < 200.0 )
            result = SOUTH;
        else if ( x < 200.0 && y < 200.0 )
            result = SOUTHWEST;
        else if ( x < 200.0 && y < 400.0 && y > 200.0 )
            result = WEST;
        else if ( x < 400.0 && x > 2.00 && y < 400.0 && y > 200.0 )
            result = CENTER;
        return result;
    }
    
    static Point square_to_point(Location square)
    {
        Point result(0.0, 0.0);
        switch ( square )
        {
            case NORTHWEST:
                result = Point(100.0, 500.0); break;
            case NORTH:
                result = Point(300.0, 500.0); break;
            case NORTHEAST:
                result = Point(500.0, 500.0); break;
            case EAST:
                result = Point(500.0, 300.0); break;
            case SOUTHEAST:
                result = Point(500.0, 100.0); break;
            case SOUTH:
                result = Point(300.0, 100.0); break;
            case SOUTHWEST:
                result = Point(100.0, 100.0); break;
            case WEST:
                result = Point(100.0, 300.0); break;
            case CENTER:
                result = Point(300.0, 300.0); break;
        }
        return result;
    }
    
    
    void draw_cross(const Point& p) const
    {
        glEnable(GL_LINE_SMOOTH);
        if ( status == PLAYING )
            set_color(BLUE);
        else
            set_color(LIGHT_BLUE);
        set_line_width(4);
        draw_line(p.x - 75.0, p.y - 75.0,
                  p.x + 75.0, p.y + 75.0);
        draw_line(p.x - 75.0, p.y + 75.0,
                  p.x + 75.0, p.y - 75.0);
        glDisable(GL_LINE_SMOOTH);
        
    }
    
    void draw_nought(const Point& p)
    {
        glEnable(GL_LINE_SMOOTH);
        if ( status == PLAYING )
            set_color(RED);
        else
            set_color(LIGHT_RED);
        set_line_width(4);
        draw_circle(p.x, p.y, 75.0);
        glDisable(GL_LINE_SMOOTH);
    }
    
public:
    TTTBoard(): Window("Tic Tac Toe", 100, 100, 400, 400,
                       0.0, 600.0, 0.0, 600.0),
    status(PLAYING), cursor_visible(true)
    {
        set_cursor(CURSOR_NONE);
    }
    
    
    
    void draw_win(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        if ( current_player() == CROSS )   //  NOUGHT just moved
            set_color(DARK_BLUE);
        else
            set_color(DARK_RED);
        fill_rectangle(x1 - 100.0, y1 - 100.0, 200.0, 200.0);
        fill_rectangle(x2 - 100.0, y2 - 100.0, 200.0, 200.0);
        fill_rectangle(x3 - 100.0, y3 - 100.0, 200.0, 200.0);
        
    }
    
    void draw_win()
    {
        set_color(BLACK);
        set_line_width(4);
        switch ( status )
        {
            case WIN_NW_NE:
                draw_win(100.0, 500.0, 300.0, 500.0, 500.0, 500.0);
                break;
            case WIN_W_E:
                draw_win(100.0, 300.0, 300.0, 300.0, 500.0, 300.0);
                break;
            case WIN_SW_SE:
                draw_win(100.0, 100.0, 300.0, 100.0,  500.0, 100.0);
                break;
            case WIN_NW_SW:
                draw_win(100.0, 500.0, 100.0, 300.0, 100.0, 100.0);
                break;
            case WIN_N_S:
                draw_win(300.0, 500.0, 300.0, 300.0, 300, 100.0);
                break;
            case WIN_NE_SE:
                draw_win(500.0, 500.0, 500, 300, 500.0, 100.0);
                break;
            case WIN_NW_SE:
                draw_win(100.0, 500.0, 300.0, 300.0, 500.0, 100.0);
                break;
            case WIN_NE_SW:
                draw_win(500.0, 500.0, 300.0, 300.0, 100.0, 100.0);
                break;
            case DRAW:
                draw_win(100.0, 500.0, 300.0, 300.0, 500.0, 500.0);
                draw_win(100.0, 300.0, 300.0, 300.0, 500.0, 300.0);
                draw_win(100.0, 100.0, 300.0, 100.0,  500.0, 100.0);
                draw_win(100.0, 500.0, 100.0, 300.0, 100.0, 100.0);
                draw_win(300.0, 500.0, 300.0, 300.0, 300, 100.0);
                draw_win(500.0, 500.0, 500, 300, 500.0, 100.0);
                draw_win(100.0, 500.0, 300.0, 300.0, 500.0, 100.0);
                draw_win(500.0, 500.0, 300.0, 300.0, 100.0, 100.0);
                break;
        }
    }
    
    void draw_cursor()
    {
        glEnable(GL_LINE_SMOOTH);
        if ( status != PLAYING )
        {
            set_color(GREEN);
            fill_rectangle(cursor_x - 10, cursor_y - 10, 20, 20);
        }
        else if ( current_player() == CROSS )
        {
            set_line_width(4);
            set_color(WHITE);
            draw_line(cursor_x - 20, cursor_y + 20, cursor_x + 20, cursor_y - 20);
            draw_line(cursor_x + 20, cursor_y + 20, cursor_x - 20, cursor_y - 20);
            set_line_width(2);
            set_color(BLUE);
            draw_line(cursor_x - 19, cursor_y + 19, cursor_x + 19, cursor_y - 19);
            draw_line(cursor_x + 19, cursor_y + 19, cursor_x - 19, cursor_y - 19);
        }
        else
        {
            set_line_width(4);
            set_color(WHITE);
            draw_circle(cursor_x, cursor_y, 20);
            set_line_width(2);
            set_color(RED);
            draw_circle(cursor_x, cursor_y, 20);
        }
        glDisable(GL_LINE_SMOOTH);
    }
    
    void paint()
    {
        if ( status != PLAYING )
            draw_win();
        
        set_color(BLACK);
        set_line_width(3);
        //  Draw board grid
        draw_line(200.0, 0.0, 200.0, 600.0);
        draw_line(400.0, 0.0, 400.0, 600.0);
        draw_line(0.0, 200.0, 600.0, 200.0);
        draw_line(0.0, 400.0, 600.0, 400.0);
        
        //  Draw contents of board
        for ( int i = NORTHWEST; i <= CENTER; i++ )
        {
            Location loc = static_cast<Location>(i);
            Point pt = square_to_point(loc);
            switch ( look(loc) )
            {
                case CROSS:
                    draw_cross(pt);
                    break;
                case NOUGHT:
                    draw_nought(pt);
                    break;
            }
        }
        if ( cursor_visible )
            draw_cursor();
        
    }
    
    
    void mouse_pressed(double x, double y, MouseButton b)
    {
        if ( status == PLAYING )
        {
            if ( !move(point_to_square(x, y)) )
                set_background_color(YELLOW);
        }
        else   //  Ready to play another game
            clear_board();   //  Empty the board
        status = check_status();  //  Update status
        repaint();
        Window::mouse_pressed(x, y, b);
    }
    
    
    void mouse_released(double x, double y, MouseButton b)
    {
        set_background_color(WHITE);
        Window::mouse_pressed(x, y, b);
        repaint();
    }
    
    
    void mouse_moved(double x, double y)
    {
        cursor_x = x;
        cursor_y = y;
        //cout << "(" << x << "," << y << ")" << endl;
        if ( cursor_x < 1.0 || cursor_x > 599.0
            || cursor_y < 1.0 || cursor_y > 599.0 )
            cursor_visible = false;
        else
            cursor_visible = true;
        repaint();
    }
    
    
    void key_pressed(int key, double, double)
    {
        if ( key == 'x' || key == 'X' )
            set_player(CROSS);
        else if ( key == 'o' || key == 'O' )
            set_player(NOUGHT);
        else if ( key == F4_KEY )
            exit(0);
        repaint();
    }
    
	void resized(int w, int h)
	{
		if ( w != h )  //  Force window to be square
		{
			(w > h)? w = h : h = w;
			set_window_size(w, h);
		}
		Window::resized(w, h);  //  Base class method does the rest
	}
};

int main()
{
    (new TTTBoard)->run();
}