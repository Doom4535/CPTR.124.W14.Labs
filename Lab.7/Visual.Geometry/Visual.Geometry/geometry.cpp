//  File geometry.cpp

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include "geometry.h"

using std::string;
using std::ostringstream;
using std::setprecision;
// using namespace std;

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
    // return 0.0;
}

string line_equation(double m, double b)
{
	oss.str("");  //  Clear the output string
    
	oss << setprecision(2);
    
    // Equation of a line y = mx +b for a slope != 1
    if (m != HUGE_VAL && (m != 1 && m != -1)) {
        if (b > 0)
            oss << "y = " << m << "x" << " + " << b;
        else if (b < 0)
            oss << "y = " << m << "x" << " - " << abs(b);
        else if (b == 0)
            oss << "y = " << m << "x";
    }
    // Equation of a line for a slope of 1
    else if (m != HUGE_VAL && (m == 1)) {
        if (b > 0)
            oss << "y = " << "x" << " + " << b;
        else if (b < 0)
            oss << "y = " << "x" << " - " << abs(b);
        else if (b == 0)
            oss << "y = " << "x";
    }
    else if (m != HUGE_VAL && (m == -1)) {
        if (b > 0)
            oss << "y = " << "-x" << " + " << b;
        else if (b < 0)
            oss << "y = " << "-x" << " - " << abs(b);
        else if (b == 0)
            oss << "y = " << "-x";
    }
    else
        oss << "x = " << b;
    
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
    
    oss.str(""); // Clear string output
    oss << std::__1::setprecision(2);
    
    if ((m1 != m2) && (m1 || m2) != HUGE_VAL) {
        i_x = (b2 - b1) / (m1 - m2);
        i_y = m1 * i_x + b1;
        oss << "(" << i_x << "," << i_y << ")";
    }
    if ((m1 == m2) && (m1 || m2) != HUGE_VAL) {
        if (b1 == b2) {
            i_x = HUGE_VAL;
            i_y = HUGE_VAL;
            oss << "(" << i_x << "," << i_y << ")";
        }
    }
    else if ((m1 || m2) == HUGE_VAL){
        if (m1 == HUGE_VAL) {
            i_x = b1;
            i_y = m2 * b1 + b2;
            oss << "(" << i_x << "," << i_y << ")";
        }
        else if (m2 == HUGE_VAL) {
            i_x = b2;
            i_y = m1 * b2 + b1;
            oss << "(" << i_x << "," << i_y << ")";
        }
    }
    else {
        oss.str(""); // Clear the output string
        oss << std::__1::setprecision(2);
        i_x = HUGE_VAL;
        i_y = HUGE_VAL;
    }
    
}

