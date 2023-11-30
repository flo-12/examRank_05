#include "TagetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void	TargetGenerator::learnTargetType( ATarget* target )
{
	if (!target)
		return ;
	for( std::vector<ATarget*>::iterator it = _targetBook.begin(); it != _targetBook.end(); it++ ) {
		if ((*it)->getType() == target->getType())
			return ;
	}
	_targetBook.push_back(target->clone());
}

void	TargetGenerator::forgetTargetType( const std::string& targetType )
{
	for( std::vector<ATarget*>::iterator it = _targetBook.begin(); it != _targetBook.end(); it++ ) {
		if ((*it)->getType() == targetType) {
			_targetBook.erase(it);
			return ;
		}
	}
}

ATarget*	TargetGenerator::createTarget( const std::string& targetType )
{
	for( std::vector<ATarget*>::iterator it = _targetBook.begin(); it != _targetBook.end(); it++ ) {
		if ((*it)->getType() == targetType)
			return (*it);
	}
	return NULL;
}