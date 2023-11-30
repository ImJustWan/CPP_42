#pragma once

class Sample {

public:

	Sample(void);
	~Sample(void);

	int		getFoo(void) const;
	void	setFoo(int v);

private:

	int		_foo;

};
