//  File geometry.cpp

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include "geometry.h"

using std::string;
using std::ostringstream;
using std::setprecision;

static ostringstream oss;

string print_point(double x, double y)
{
	oss << setprecision(2);
	oss.str("");  //  Clear the output string
	oss << "(" << x << "," << y << ")";
	return oss.str();
}

double distance(double x1, double y1, double x2, double y2)
{
    /*  Replace with your code */
    double d;
    double x, y, x_squared, y_squared;
    x = x2 - x1;
    y = y2 - y1;
    x_squared = pow(x, 2);
    y_squared = pow(y, 2);
    d = sqrt (x_squared + y_squared);
    return d;
    // return 0.0;
}

bool equals(double a, double b)
{
	return a == b || fabs(a - b) < 0.0001;
}

double slope(double x1, double y1, double x2, double y2)
{
    double m;
    m = (y2 - y1) / (x2 - x1);
    if (m == HUGE_VAL)
        return HUGE_VAL;
    else if (m == -HUGE_VAL)
        return HUGE_VAL;
    else
        return m;

    /*  Replace with your code */
    // return 0.0;
}

double intercept(double x1, double y1, double x2, double y2)
{
    /*  Replace with your code */
    // equation_of_line_y = m * (x - x1) + y1
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

    // return 0.0;
}

string line_equation(double m, double b)
{
	oss.str("");  //  Clear the output string
    
	oss << setprecision(2);
    
     // Equation of a line y = mx +b for a slope != 1
     if (m != HUGE_VAL && (m != 1 && m != -1)) {
     if (c > 0)
     oss << "y = " << m << "x" << " + " << c << endl;
     else if (c < 0)
     oss << "y = " << m << "x" << " - " << abs(c) << endl;
     else if (c == 0)
     oss << "y = " << m << "x" << endl;
    `
    
    /*  Add your code to print the line equation to the
     oss object instead of cout.  (See print_point above
     for an example.) */
    
    
	return oss.str();
}

string line_equation(double x1, double y1, double x2, double y2)
{
	return line_equation(slope(x1, y1, x2, y2), intercept(x1, y1, x2, y2));
}

void intersection(double m1, double b1, double m2, double b2,
                  double& i_x, double& i_y)
{
    /*  Add your code here  */
}

