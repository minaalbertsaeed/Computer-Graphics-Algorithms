
#ifndef HelperFunctions
#define HelperFunctions 
inline void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

inline int Round(double x)
{
	return (int)(x + 0.5);
}

#endif
