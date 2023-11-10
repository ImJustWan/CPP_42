#ifndef SAMPLE_CLASS
# define SAMPLE_CLASS

class Sample {

public:

	float const	pi;
	int			qd;

	Sample( float const f );
	~Sample( void );

	void    bar( void ) const;

};

#endif