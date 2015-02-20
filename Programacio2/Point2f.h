#ifndef _Point2f_
#define _Point2f_

class Point2f
{
	Point2f operator+ (const Point2f& a) const
	{
		Point2f tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;

		return tmp;
	}

	Point2f& operator+= (const Point2f& a)
	{
		x = x + a.x;
		y = y + a.y;

		return (*this);
	}

	public:
		float x, y;
		

		void setZero()
		{
			x = y = 0.0f;
		}

		bool checkZero() const
		{
			return x == 0.0f && y == 0.0f;
		}

		void changeSign()
		{
			x = -x;
			y = -y;
		}


		
};

#endif