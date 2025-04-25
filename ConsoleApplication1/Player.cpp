#include <string>
#include <cctype>
#include <random>
#include <time.h>


namespace Stats { // Start of namespace Stats::
	struct Structure_stats {
		int m_iCharacterPoints = rand() % 30 + 15;
		// Skill's
		int m_iCharisma;
		int m_iAgility;
		int m_iBodyBuilding;
		int m_iTechnicalAbilities;
	} PlayerStats;
} // End of namespace Stats::