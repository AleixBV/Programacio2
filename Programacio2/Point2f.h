#ifndef _Point2f_
#define _Point2f_

class Point2f
{
    public:

		float x, y;

		Point2f operator+ (const Point2f& a) const;

		Point2f operator- (const Point2f& a) const;

		Point2f operator+= (const Point2f& a);

		Point2f operator-= (const Point2f& a);
		
		void setZero();

		bool isZero() const;
};

#endif