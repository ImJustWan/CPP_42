#ifndef SAMPLE_CLASS
# define SAMPLE_CLASS

class Sample {

public:

	Sample(int v);
	~Sample(void);

	int		getFoo(void) const;
	int		compare(Sample *other) const;

private:

	int		_foo;

};

#endif