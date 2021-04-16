Libasm

Assembly yourself!



요약 : 이번 프로젝트의 목표는 어셈블리어와 친숙해지는 것이다. 



---
Contents

| Chapter | Contents | Page |
|:---:|:---|:---:|
| I | [__Introduction__]() | 2 |
| II | [__Common Instructions__]() | 3 |
| III | [__Mandatory part__]() |  4 |
| IV | [__Bonus part__]() |  5 |



---





Chapter 1

Introduction

보통 `asm`이라는 약어로 불리는 어셈블리어(또는 어셈블러)는 저급 프로그래밍 언어로서, 아키텍쳐의 기계어 지시와 매우 잘 대응(1:1이 아닌 경우도 있지만)됩니다. 각각의 어셈블리어는 특정한 컴퓨터 아키텍쳐(컴퓨터 구조)에 따라 세분화된다. 반면, 대부분의 고급 프로그래밍 언어는 다양한 아키텍쳐에 호환되지만 인터프리팅이나 컴파일링의 과정이 반드시 선행되어야 합니다. 어셈블리어는 symbolic machine code라고도 불립니다. 



---



Chapter 2

Common Instructions

* 함수는 예상치 못한 오류로 종료되어서는 안 됩니다. (세그먼테이션 오류, 버스 에러, free의 중복 사용 등) 하지만 정의되지 않은 행동의 경우에는 예외입니다. 만약에 오류가 발생하면, 그 프로젝트는 제대로 기능하지 못하는 것으로 판별되며 0점을 받게될 것입니다. 
* 당신의 `Makefile`은 적어도 `$(NAME)`, `all`, `clean`, `fclean`, `re` 명령어를 가지고 있어야 합니다. 또한, 필요한 파일들만 다시 컴파일(다시 링크)해야 합니다. 
* 보너스를 함께 제출하는 경우에는, 반드시 Makefile에서 `bonus` 명령어를 추가해야 합니다. Bonus part에서는 Main part에서 금지되었던 헤더, 라이브러리, 함수들을 사용할 수 있습니다. 보너스는 `_bonus.{c/h}`라는 이름으로 구별되어야 합니다. Mandatory와 Bonus part에 대한 평가는 별개로 진행됩니다. 

* 당신의 프로젝트에 대한 테스트 프로그램을 스스로 만들어보았으면 합니다. 물론 그 내용은 제출할 필요는 없으며 평가에 반영되지 않습니다. 테스트 프로그램을 만들게 되면 당신의 프로젝트와 동료의 프로젝트를 평가하기 훨씬 수월해집니다. 그리고 그 테스트케이스들을 `defense`에서 잘 활용할 수 있을 것입니다. 당연히 `defense`에서는 당신과 동료의 테스트케이스들을 모두 자유롭게 활용할 수 있습니다. 

* 개인적으로 배정된 git repository에 과제물을 제출해주세요. git repository 내의 과제물만으로 평가가 진행됩니다. 만약 Deepthought가 평가에 참여하는 경우, 동료 평가 이후에 최종적으로 이루어질 것입니다. 만약 Deepthought가 평가하던 중 당신의 과제물 중 어느 부분에서라도 에러가 하나라도 발생하는 즉시 평가가 중단됩니다. 

  * 64비트 ASM 양식으로 작성해야 합니다. 호출 규약(calling convention)을 숙지해두세요. 
  * 인라인 ASM을 작성해서는 안 되며, 반드시 `.s` 파일에 작성하여야 합니다. 
  * `nasm`을 이용하여 컴파일하여야 합니다. 
  * AT&T가 아니라 Intel 문법을 사용하세요. 

  

---



Chapter 3

Mandatory part

* 라이브러리의 이름은 `libasm.a`여야 합니다. 
* main 함수를 과제물로 함께 제출해야 합니다. 그 함수는 당신의 라이브러리와 함께 컴파일되어 함수와 라이브러리가 정상적으로 잘 기능하는지 테스트할 것입니다. 
* 다음의 함수들을 어셈블리어로 재구현해주세요:
  * ft_strlen(man 3 strlen)
  * ft_stcpy(man 3 strcpy)
  * ft_strcmp(man 3 strcmp)
  * ft_write(man 2 write)
  * ft_read(man 2 read)
  * ft_strdup(man 3 strdup, malloc을 call할 수 있습니다.)
* syscall 도중 에러가 발생하는지 반드시 체크하여야 하며, 필요한 경우 에러를 적절히 관리해야 합니다. 
* errno 변수를 적절하게 설정하십시오. 
* 이를 위해서 extern ___error를 호출하는 것이 허용됩니다. 



---



Chapter 4

Bonus part

아래의 함수들을 어셈블리어로 재구현해주세요. linked list 함수는 다음의 구조체를 이용합니다. 



```C
typedef struct				s_list
{
	void								*data;
	struct s_list				*next;
}											t_list;
```



* ft_atoi_base(piscine 때와 같이)
* ft_list_push_front(piscine 때와 같이)

* ft_list_size(piscine 때와 같이)
* ft_list_sort(piscine 때와 같이)
* ft_list_remove_if(piscine 때와 같이)
