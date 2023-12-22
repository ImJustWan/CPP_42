#pragma once

class Sample {

public:

	int foo;

	Sample(void);
	~Sample(void);

	static int	getNbInst(void);

private:

	static int	_nbInst;

};
