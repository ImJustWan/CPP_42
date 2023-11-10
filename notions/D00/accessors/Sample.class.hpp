#ifndef SAMPLE_CLASS
# define SAMPLE_CLASS

class Sample {

public:

	Sample(void);
	~Sample(void);

	int		getFoo(void) const;
	void	setFoo(int v);

private:

	int		_foo;

};

#endif