#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	// system("leaks ex03");
	return (0);
}

/*
ICharacter 및 IMateriaSource 인터페이스가 존재하며 주제와 동일합니다.

MateriaSource 클래스가 존재하며 IMateraSource를 구현합니다. 멤버 함수는 의도한 대로 작동합니다.

Amateria에서 상속받은 구체적인 Ice 및 Cure 클래스가 있습니다. 그들의 clone() 메서드는 올바르게 구현되어 있습니다. 그들의 출력은 정확합니다.
Amateria 클래스는 여전히 추상(클론은 순수)입니다.
가상 ~AMateria()가 있습니다.
Amateria에는 유형을 저장하기 위한 보호된 문자열 속성이 포함되어 있습니다.

Character 클래스가 존재하며 ICharacter를 구현합니다. 4가지 재료의 인벤토리가 있습니다.
멤버 함수는 주제가 요구하는 대로 구현됩니다.
캐릭터의 복사 및 할당은 필요에 따라 구현됩니다 => 깊은 복사
*/