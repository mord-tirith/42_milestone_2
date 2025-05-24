
#include "fdf.h"
#include <math.h>

t_point	ft_project_point(t_point p, int deg)
{
	float	rad;
	t_point	ret;

	rad = deg * TO_RAD;
	ret.x = (int)((p.x - p.y) * cos(rad));
	ret.y = (int)((p.x + p.y) * sin(rad) - p.z);
	return (ret);
}
