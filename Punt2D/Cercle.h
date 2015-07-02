#ifndef _CERCLE_H_
#define _CERCLE_H_

#include "Point2D.h"

#include <math.h>
#include <stdio.h>

#define PI 3.1415926535897


class Cercle{
	public:

		Point2D position;
		double r;

		Cercle();
		Cercle(Point2D p, double radi){ position = p; r = radi;}
		~Cercle();

		double AreaCercle(double radi)const
		{
			return PI*pow(radi, 2);
		}

		bool InterseccioCercle(const Cercle c) const
		{
			double distance = sqrtf(pow(c.position.x - position.x, 2)) + (pow(c.position.y - position.y, 2));

			if (distance < r)
				return true;
			else
				return false;
		}
	
	private:

};


#endif // !_CERCLE_H_
