#ifndef _CRITTERFACTORY_H_
#define _CRITTERFACTORY_H_

#include "Simulation.h"
#include "BaseCritter.h"
#include "memory"
class CritterFactory {

	private :
		static int count; // number of critters created

 	private :
 		const float RandomBoundedFloat(const float min, const float max) const;
 		const bool AttemptThreshold(const float threshold) const;

 	public :
 		CritterFactory();
 		CritterInterface* CreateBaseCritter() const;
 		const static int GetNewId();
};

#endif
