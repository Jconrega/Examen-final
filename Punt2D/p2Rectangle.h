#ifndef _p2Rectangle_H_
#define _p2Rectangle_H_

#include <math.h>
#include "Point2DTemplate.h"

template<class Type>

class p2Rectangle
{
	public:
		Point2DTemplate<Type> position;
		Type w, h;

		p2Rectangle(Type position_x, Type position_y, Type w_, Type h_){ position.x = position_x; position.y = position_y; w = w_; h = h_; }
		p2Rectangle(p2Rectangle<Type>* format...)
		{
			format->position.x = position.x;
			format->position.y = position.y;
			format->w = w;
			format->h = h;

		}
		~p2Rectangle();

		int GetArea()
		{
			return h * w;
		}

		bool Intersects(p2Rectangle<Type>& squr)
		{
			unsigned int difx = h - position.x;
			unsigned int dify = w - position.y;
			
			if (squr.position.x <= position.x + difx && squr.position.y <= position.y + dify)
				return true;
			else		
				return false;
		}

};
#endif // !_p2Rectangle_H_
