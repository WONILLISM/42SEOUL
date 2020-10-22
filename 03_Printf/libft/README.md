# Libft
사용 언어 : c언어
나만의 라이브러리 만들기

## :blue_book: 작성 규칙
+ 프로젝트는 Norm 규칙에 맞춰 작성되어야 한다.
+ 함수들은 정의되지 않은 행동들과는 별개로 예기치 않게 중단 되어서는 안 된다. 예를 들어, segmentation fault, bus error, double free 등.
+ 필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 한다. 메모리 누수는 용납되지 않는다.
+ 이 라이브러리는 GCC로 -Wall -Wextra -Werror 플래그를 지정하여 컴파일 된다. 그리고 Makefile은 relink 되어서는 안된다.
+ 전역 변수는 사용할 수 없다.
+ 복잡한 함수를 작성하기 위해 하위 함수가 필요한 경우에는, 이러한 하위 함수를 라이브러리와 함께 publishing 하지 않도록 static(정적)으로 정의해야 한다.


## :blue_book: List of Func(함수 목록)

1. Mandatory Part(필수 요소)
   + part1 : `memset` `bzero` `memcpy` `memccpy` `memmove` `memchr` `memcmp` `strlen` `strlcpy` `strlcat` `strchr` `strrchr` `strnstr` `strncmp` `atoi` `isalpha` `isdigit` `isalnum` `isascii` `isprint` `toupper` `tolower` `calloc` `strdup`
   + part2 : `substr` `strjoin` `strtrim` `split` `itoa` `strmapi` `putchar_fd` `putstr_fd` `putendl_fd` `putnbr_fd`
2. Bonus Part(추가 요소)
   + `ft_lstnew` `ft_lstadd_front` `ft_lstsize` `ft_lstlast` `ft_lstadd_back` `ft_lstdelone` `ft_lstclear` `ft_lstiter` `ft_lstmap`

## :blue_book: Evaluation Log(평가 로그)

+ 2020/10/13
  initial_errors: | test_ft_atoi: OK | test_ft_bzero: OK | test_ft_calloc: OK | test_ft_isalnum: OK | test_ft_isalpha: OK | test_ft_isascii: OK | test_ft_isdigit: OK | test_ft_isprint: OK | test_ft_itoa: OK | test_ft_memccpy: OK | test_ft_memchr: OK | test_ft_memcmp: OK | test_ft_memcpy: OK | test_ft_memmove: OK | test_ft_memset: OK | test_ft_putchar_fd: OK | test_ft_putendl_fd: OK | test_ft_putnbr_fd: OK | test_ft_putstr_fd: OK | test_ft_split: OK | test_ft_strchr: OK | test_ft_strdup: OK | test_ft_strjoin: OK | test_ft_strlcat: OK | test_ft_strlcpy: OK | test_ft_strlen: OK | test_ft_strmapi: OK | test_ft_strncmp: OK | test_ft_strnstr: OK | test_ft_strrchr: OK | test_ft_strtrim: OK | test_ft_substr: OK | test_ft_tolower: OK | test_ft_toupper: OK | bonus: 9/9 functions correct
