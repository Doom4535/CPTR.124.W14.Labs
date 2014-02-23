//
//  main.cpp
//  Visual.Geometry
//
//  Created by Aaron Covrig on 2/23/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>
#include "sgl.hpp"
#include "geometry.h"
#include "geometry.cpp"
#include "visualgeometry.cpp"


using namespace std;

int main()
{
    //
    //  main.cpp
    //  Geometric.Functions
    //
    //  Created by Aaron Covrig on 2/17/14.
    //  Copyright (c) 2014 Aaron Covrig. All rights reserved.
    //
    
    //  File geometry.cpp
    
#include <iostream>
#include <cmath>
    
    using namespace std;
    
    
    /*  -------------------------------------------------------  */
    /*  Do not touch anything above this line                    */
    
    //////////////////////////////////////////////////////////
    double distance(double x1, double y1, double x2, double y2)
    {
        double d;
        double x, y, x_squared, y_squared;
        x = x2 - x1;
        y = y2 - y1;
        x_squared = pow(x, 2);
        y_squared = pow(y, 2);
        d = sqrt (x_squared + y_squared);
        return d;
    }
    double slope( double x1, double y1, double x2, double y2)
    {
        double m;
        m = (y2 - y1) / (x2 - x1);
        if (m == HUGE_VAL)
            return HUGE_VAL;
        else if (m == -HUGE_VAL)
            return HUGE_VAL;
        else
            return m;
    }
    double intercept(double x1, double y1, double x2, double y2)
    {
        // equation_of_line_y = m * (x - x1) + y1
        double m;
        double y_intersect, x_intersect;
        x_intersect = x1;
        m = slope(x1, y1, x2, y2);
        y_intersect = m * ((0 - x1)) + y1;
        if (slope(x1, y1, x2, y2) != HUGE_VAL)
            return (y_intersect);
        else
            return (x_intersect);
    }
    void line_equation(double m, double c)
    {
        // Equation of a line y = mx +b for a slope != 1
        if (m != HUGE_VAL && (m != 1 && m != -1)) {
            if (c > 0)
                cout << "y = " << m << "x" << " + " << c << endl;
            else if (c < 0)
                cout << "y = " << m << "x" << " - " << abs(c) << endl;
            else if (c == 0)
                cout << "y = " << m << "x" << endl;
        }
        // Equation of a line for a slope of 1
        else if (m != HUGE_VAL && (m == 1)) {
            if (c > 0)
                cout << "y = " << "x" << " + " << c << endl;
            else if (c < 0)
                cout << "y = " << "x" << " - " << abs(c) << endl;
            else if (c == 0)
                cout << "y = " << "x" << endl;
        }
        else if (m != HUGE_VAL && (m == -1)) {
            if (c > 0)
                cout << "y = " << "-x" << " + " << c << endl;
            else if (c < 0)
                cout << "y = " << "-x" << " - " << abs(c) << endl;
            else if (c == 0)
                cout << "y = " << "-x" << endl;
        }
        else
            cout << "x = " << c << endl;
    }
    //    ADD YOUR CODE HERE
    //
    //////////////////////////////////////////////////////////
    
    /*  Do not touch anything below this line                    */
    /*  -------------------------------------------------------  */
    
    void print_point(double x, double y)
    {
        cout << "(" << x << "," << y << ")";
    }
    
    void do_distance(double x1, double y1, double x2, double y2)
    {
        cout << "The distance between ";
        print_point(x1, y1);
        cout << " and ";
        print_point(x2, y2);
        cout << " is " << distance(x1, y1, x2, y2) << endl;
    }
    
    void do_slope(double x1, double y1, double x2, double y2)
    {
        cout << "The slope of the line between ";
        print_point(x1, y1);
        cout << " and ";
        print_point(x2, y2);
        cout << " is ";
        double m = slope(x1, y1, x2, y2);
        if ( m == HUGE_VAL )
            cout << "undefined";
        else
            cout << m;
        cout << endl;
    }
    
    void do_intercept(double x1, double y1, double x2, double y2)
    {
        if ( slope(x1, y1, x2, y2) == HUGE_VAL )
            cout << "The x-";
        else
            cout << "The y-";
        cout << "intercept of the line between ";
        print_point(x1, y1);
        cout << " and ";
        print_point(x2, y2);
        cout << " is " << intercept(x1, y1, x2, y2)
        << endl;
    }
    
    void do_equation(double x1, double y1, double x2, double y2)
    {
        cout << "The equation of the line between ";
        print_point(x1, y1);
        cout << " and ";
        print_point(x2, y2);
        cout << " is ";
        line_equation(slope(x1, y1, x2, y2), intercept(x1, y1, x2, y2));
        cout << endl;
    }
    
    int main()
    {
        for (;;)   //  Infinite loop, use Control-C to quit
        {
            double p_x1, p_y1, p_x2, p_y2;
            cout << "Enter the point coordinates x1, y1, x2, y2 "
            << "(Control-C quits): ";
            cin >> p_x1 >> p_y1 >> p_x2 >> p_y2;
            do_distance(p_x1, p_y1, p_x2, p_y2);
            do_slope(p_x1, p_y1, p_x2, p_y2);
            do_intercept(p_x1, p_y1, p_x2, p_y2);
            do_equation(p_x1, p_y1, p_x2, p_y2);
            cout << "-----------------" << endl;
        }
    }
    

    return 0;
}

