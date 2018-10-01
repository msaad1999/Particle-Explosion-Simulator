#include "Particle.h"

namespace SDLproject
{
	class Swarm
	{
	public:
		Swarm();
		~Swarm();
		const Particle * const getParticles() { return m_pParticles; };
		void update(int elapsed);

		const static int NPARTICLES = 6000;

	private:
		Particle *m_pParticles;
		int lastTime;
	};
}


