#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {}

void	SpellBook::learnSpell( ASpell* spell )
{
	if (!spell)
		return ;

	for( std::vector<ASpell*>::iterator it = _spellBook.begin(); it != _spellBook.end(); ++it ) {
		if ((*it)->getName() == spell->getName())
			return ;
	}
	_spellBook.push_back(spell->clone());
}

void	SpellBook::forgetSpell( const std::string& spellName )
{
	for( std::vector<ASpell*>::iterator it = _spellBook.begin(); it != _spellBook.end(); ++it ) {
		if ((*it)->getName() == spellName) {
			_spellBook.erase(it);
			return ;
		}
	}
}

ASpell*	SpellBook::createSpell( const std::string& spellName )
{
	for( std::vector<ASpell*>::iterator it = _spellBook.begin(); it != _spellBook.end(); ++it ) {
		if ((*it)->getName() == spellName)
			return (*it);
	}
	return NULL;
}
