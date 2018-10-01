#pragma once

namespace SDLproject
{
	class Particle
	{ 
	public:
		Particle();
		~Particle();
		void update(int interval);

		double m_x;
		double m_y;

	private:
		double m_speed;
		double m_direction;

		void init();

	};
}


