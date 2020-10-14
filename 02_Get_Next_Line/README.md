# Get Next Line

This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: static variables.

사용언어 : c언어

파일 디스크립터로부터 읽혀진, newline으로 끝나는 라인을 반환하는 함수를 코드화 하는 것입니다.

## :blue_book: 작성 규칙
+ 프로젝트는 Norm 규칙에 맞춰 작성되어야 합니다. 보너스 파일/함수가 있는 경우,해당 파일/함수 들은 norm 검사에 포함되며, norm error가 있을 시, 0점을 받게 될것입니다.
+ 함수들은 정의되지 않은 행동들과는 별개로 예기치 않게 중단되어서는 안 됩니다.(예를 들어, segmentation fault, bus error, double free 등.) 만약 이렇게 중단되면, 당신의 프로젝트는 작동하지 않는 것으로 여겨지고 평가에서 0점을 받을 것입니다.
+ 필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 합니다. 메모리 누수는 용 납되지 않을 것입니다.
+ 그 과제에서 필요한 경우, Makefile을 제출해야 합니다. 그것은 -Wall -Wextra -Werror 플래그를 지정하여 컴파일할 것입니다. 그리고 Makefile은 relink 되어서는안됩니다.
+ Makefile은 최소한 $(NAME), all, clean, fclean, re를 포함해야 합니다.
+ 프로젝트에 보너스를 제출하려면, Makefile에 보너스 규칙을 포함해야 합니다. 이보너스 규칙은 프로젝트의 메인 부분에서 금지되었던 모든 다양한 헤더, 라이브러리,또는 함수들은 추가해야 할 것입니다. 보너스는 반드시 _bonus.{c/h}라는 다른 파일에 있어야 합니다. 의무적으로 해야 될 파 트과 보너스 파트는 별도로 평가될 것입니다.
+ 프로젝트에서 여러분의 libft를 허용한다면, 소스들과 그것과 연관된 Makefile을 연관된 Makefile과 함께 libft폴더에 복사해야 합니다. 프로젝트의 Makefile은 Makefile을 사용하여 라이브러리를 컴 파일한 다음, 프로젝트를 컴파일해야 합니다.
+ 이 과제물을 제출할 필요가 없고, 채점 받을 필요가 없을지라도, 우리는 프로젝트를 위한 테스트 프로그램을 만들 것을 권장합니다. 그것은 여러분의 과제물과 동료들의 과제물을 쉽게 테스트할 기회를 제공할 것입니다. 평가하는 동안 이 테스트 프로그램들이 특히 유용하다는 것을 알게 될 것입니다. 사실, 평가하는 동안, 여러분의 테스트 프로그램과 평가 받는 동료의 테스트 프로그램들을 자유롭게 사용할 수 있을것입니다.
+ 할당된 git 저장소에 과제물을 제출하세요. 오직 git 저장소에 있는 과제물만 등급이매겨질 것입 니다. 만약 과제를 평가받는데 Deepthought가 배정된다면, 그것은 동료평가 이후에 이루어질 것입니다. 만약 Deepthought 평가 중에 오류가 발생한다면, 그 즉시 평가는 중지될 것입니다.

## :blue_book: List of Func(함수 목록)

1. Mandatory Part (필수 요소) - get next line
   + get_next_line 함수를 반복문 안에서 호출하면 파일 디스크립터에서 사용할 수 있는 텍스트를 EOF가 올때까지 한 번에 한 줄씩 읽을 수 있을 것입니다.
   + 파일에서 읽을 때 그리고 표준입력으로부터 읽어드릴 때, 함수가 제대로 동작하는지 확인하십시오.
   + libft는 이 프로젝트에서 사용할 수 없습니다. get_next_line이 동작하는 데 필요한 함수들이 들어있는 get_next_line_utils.c 파일을 추가해야 합니다.
   + 당신의 프로그램은 -D BUFFER_SIZE=xx 플래그를 붙여서 컴파일 해야 합니다. 그것은 여러분의 get_next_line에서 read함수를 호출하기 위한 buffer size로 사용될 것입니다.
   + 컴파일은 이런 식으로 진행됩니다 : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
   + 여러분의 read 함수는 표준입력으로 또는 파일로부터 읽어드리기 위해서 컴파일할 때 정의된 BUFFER_SIZE를 사용해야 합니다.
   + get_next_line.h (헤더 파일)에는 적어도 get_next_line 함수의 프로토타입이 있어야 합니다.

2.
