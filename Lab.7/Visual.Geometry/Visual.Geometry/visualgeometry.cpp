#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iostream>

// #include <GL/sgl.hpp>    //  or  #include "sgl.hpp"
#include "sgl.hpp"
#include "geometry.h"

using namespace std;
using namespace sgl;


/***********************************************
 *  GeoPoint code
 ***********************************************/
class GeoPoint: public GraphicalObject
{
protected:
    Color color;
public:
    GeoPoint(double x, double y, const Color& c):
    GraphicalObject(x, y, 4, 4), color(c)
    {
        set_cursor(CURSOR_CROSSHAIR);
    }
    
    ~GeoPoint() {}
    
    double get_x() const
    {
        return left + width/2;
    }
    
    double get_y() const
    {
        return bottom + height/2;
    }
    
    void paint() const
    {
        set_color(color);
        fill_circle(left + width/2, bottom + height/2, 2);
        if ( mouse_over )
            draw_circle(left + width/2, bottom + height/2, 4);
    }
    
    void mouse_pressed(double x, double y, MouseButton)
    {
        std::cout << "x=" << x << "  y=" << y << std::endl;
    }
    
};


/**************************************************
 *  GeometryWindow code
 **************************************************/

const double MIN_X = -100.0,
MAX_X = 100.0,
MIN_Y = -100.0,
MAX_Y = 100.0;

class GeometryWindow: public ObjectWindow
{
protected:
	GeoPoint *pt1,
    *pt2,
    *pt3,
    *pt4,
    *pt_inter;
    
	double xi,
    yi;
    
    
	//  Currently selected graphical object, null if none
    CursorShape normal_cursor,
    active_cursor;
    
    
public:
	GeometryWindow(const char *title, int left, int top, int width, int height,
		           double min_x, double max_x, double min_y, double max_y):
    ObjectWindow(title, left, top, width, height, min_x, max_x, min_y, max_y),
    pt1(0), pt2(0), pt3(0), pt4(0), pt_inter(0),
    xi(HUGE_VAL), yi(HUGE_VAL),
    normal_cursor(get_cursor()),
    active_cursor(CURSOR_CROSSHAIR) {}
    
	//  Removes the points from the window and
	//  there corresponding graphical objects
	void clear()
	{
		//  Remove the graphical objects from the window
		remove_all();
		//  Set all the points to null
		pt1 = pt2 = pt3 = pt4 = pt_inter = 0;
		repaint();
	}
    
    
	void draw_extended_line(GeoPoint *pt1, GeoPoint *pt2)
	{
		double m = slope(pt1->get_x(), pt1->get_y(),
			             pt2->get_x(), pt2->get_y()),
        b = intercept(pt1->get_x(), pt1->get_y(),
                      pt2->get_x(), pt2->get_y()),
        new_x1, new_y1, new_x2, new_y2;
		if ( m == HUGE_VAL )
		{
			new_x1 = new_x2 = pt1->get_x();
			new_y1 = MIN_Y;
			new_y2 = MAX_Y;
		}
		else if ( m >= -1.0 && m <= 1.0 )
		{
			intersection(m, b, HUGE_VAL, MIN_X, new_x1, new_y1);
			intersection(m, b, HUGE_VAL, MAX_X, new_x2, new_y2);
		}
		else
		{
			intersection(m, b, 0, MIN_Y, new_x1, new_y1);
			intersection(m, b, 0, MAX_Y, new_x2, new_y2);
		}
		set_line_width(2.0);
		draw_line(new_x1, new_y1, new_x2, new_y2);
		set_line_width(1.0);
	}
    
	void paint()
	{
		draw_axes(10.0, 10.0);   //  Draw axes
		set_color(DARK_GRAY);
		
		set_color(LIGHT_GRAY);
		if ( pt1 )  //  First point exists
		{
			set_color(DARK_GREEN);  //
			draw_text(print_point(pt1->get_x(), pt1->get_y()).c_str(),
				      pt1->get_x() + 5, pt1->get_y() + 5, 10);
			if ( pt2 )
			{   //  First line ready to render
				draw_extended_line(pt1, pt2);
				draw_text(line_equation(pt1->get_x(), pt1->get_y(),
                                        pt2->get_x(), pt2->get_y()).c_str(),
                          MIN_X + 10, MIN_Y + 10, 10);
				draw_text(print_point(pt2->get_x(), pt2->get_y()).c_str(),
                          pt2->get_x() + 5, pt2->get_y() + 5, 10);
				if ( pt3 )
				{
					set_color(BLUE);  //  Blue
					draw_text(print_point(pt3->get_x(),
                                          pt3->get_y()).c_str(),
                              pt3->get_x() + 5, pt3->get_y() + 5, 10);
					if ( pt4 )
					{   //  Second line ready to render
						draw_extended_line(pt3, pt4);
						draw_text(line_equation(pt3->get_x(), pt3->get_y(),
                                                pt4->get_x(), pt4->get_y()).c_str(),
                                  MIN_X + 10, MIN_Y + 15, 10);
						draw_text(print_point(pt4->get_x(),
                                              pt4->get_y()).c_str(),
                                  pt4->get_x() + 5, pt4->get_y() + 5, 10);
						double slope1 = slope(pt1->get_x(), pt1->get_y(),
							                  pt2->get_x(), pt2->get_y()),
                        intercept1 = intercept(pt1->get_x(),
                                               pt1->get_y(),
                                               pt2->get_x(),
                                               pt2->get_y()),
                        slope2 = slope(pt3->get_x(), pt3->get_y(),
                                       pt4->get_x(), pt4->get_y()),
                        intercept2 = intercept(pt3->get_x(),
                                               pt3->get_y(),
                                               pt4->get_x(),
                                               pt4->get_y());
						//  Compute intersection, if possible
						intersection(slope1, intercept1, slope2, intercept2, xi, yi);
						//  Draw the point in the window
						set_color(RED);  //  Red
						//draw_point(xi, yi);
						fill_circle(xi, yi, 2);
						draw_text(print_point(xi, yi).c_str(),
                                  xi + 5, yi + 5, 10);
					}
				}
			}
		}
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
    
    
	void mouse_dragged(double x, double y)
	{
        ObjectWindow::mouse_dragged(x, y);
        
		if ( get_key_modifiers() == ALT_KEY_MODIFIER )
			cout << "Alt key depressed" << endl;
	}
    
	void mouse_pressed(double x, double y, MouseButton button)
	{
		GeoPoint *pt = 0;
        
        if ( button == LEFT_BUTTON )
        {
            if ( !pt1 )
                pt = pt1 = new GeoPoint(x - 2, y - 2, DARK_GREEN);
            else if ( !pt2 )
                pt = pt2 = new GeoPoint(x - 2, y - 2, DARK_GREEN);
            else if ( !pt3 )
                pt = pt3 = new GeoPoint(x - 2, y - 2, BLUE);
            else if ( !pt4 )
                pt = pt4 = new GeoPoint(x - 2, y - 2, BLUE);
            if ( pt )
                add(pt);
        }
        
        ObjectWindow::mouse_pressed(x, y, button);
        
		repaint();
	}
    
    
	void key_pressed(int k, double x, double y)
	{
		cout << "key: " << k << "  ( " << static_cast<char>(k) << ")" << endl;
		ObjectWindow::key_pressed(k, x, y);
	}
    
    virtual void quit()
	{
		exit(0);
	}
    
};



int main()
{
	GeometryWindow *window = new GeometryWindow("Visual Geometry", 
		                                        100, 100, 600, 600, 
		                                        MIN_X, MAX_X, MIN_Y, MAX_Y);
	window->run();
    
}