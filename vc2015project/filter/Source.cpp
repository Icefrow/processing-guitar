#include <iostream>
#include <array>

const float PI = 3.14159265359f;
//extern 
const int Frequency = 48000;
const float Period = 1.f / Frequency;


class Plotter
{
public:
	Plotter()
	{
		line_.fill(' ');
		line_[100] = '*';
	}

	void plot(int value)
	{
		if (value > 50)
			value = 50;
		else if (value < -50)
			value = -50;
		std::cout.write(&line_[50 - value], 50 + value + 1);
		std::cout << std::endl;
	}

private:
	std::array <char, 101> line_;
};

class Capacitor
{
public:
	explicit Capacitor(float capacityArg = 0.000001)
		: potential_(0)
		, capacity_(capacityArg) {}

	float capacity() const {
		return capacity_;
	}

	void capacity(float newCapacity) {
		capacity_ = newCapacity;
	}

	float potential() const {
		return potential_;
	}

	void calc(float i) {
		float dq = i*Period;
		potential_ += dq / capacity_;
	}

private:
	float potential_;
	float capacity_;
};


class Filter1
{
public:
	Filter1(float f = 1000) {
		set(f);
	}

	void set(float f) {
		r_ = 1 / (2 * PI*f*c_.capacity());
	}

	float calc(float u) {
		float u_r = u - c_.potential();
		float i = u_r / r_;
		c_.calc(i);
		return c_.potential();
	}

private:
	Capacitor c_;
	float r_;
};

class Generator
{
public:
	Generator(float f = 1000)
		: dph_(2 * PI*Period*f)
		, ph_(0) {}

	float calc() {
		ph_ += dph_;
		if (ph_ > PI)
			ph_ -= 2 * PI;
		if (ph_ < 0)
			return -1;
		return 1;
	}

private:
	float dph_;
	float ph_;
};

class Inductor
{
public:
	Inductor(float inductanceArg = 0.001)
		: i_(0)
		, inductance_(inductanceArg) {}

	float inductance() const {
		return inductance_;
	}
	void inductance(float newInductance) {
		inductance_ = newInductance;
	}
	float current() const {
		return i_;
	}
	void calc(float u) {
		float di = u / inductance_ * Period;
		i_ += di;
	}

private:
	float inductance_;
	float i_;
};

int main()
{
	float f = 1000;
	Generator generator(200);
	//Filter2 filter(f, 3);
	Filter1 filter(f);
	Plotter plotter;

	for (int i = 0; i < 500; i++)
	{
		float y = 20 * generator.calc();
		float x = filter.calc(y);
		plotter.plot(x);
	}

	return 0;
}