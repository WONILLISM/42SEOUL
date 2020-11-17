# Dockerfile
# 	- Docker는 아래의 지침들을 순서대로 실행한다.

# FROM
# 	- 유효한 Dockerfile은 FROM 명령으로 시작해야한다.
# 	- 새 빌드 단계를 초기화하고 이후의 지침에 대한 기본 이미지를 설정한다.
# 	- 프로젝트를 시작할 베이스 image를 지정
FROM	debian:buster

# LABEL
# 	- image에 metadata 추가한다.
LABEL	maintainer="wopark@student.42seoul.kr"

# RUN
# 	- 현재 이미지 위에 있는 새 계층에서 명령을 실행하고 결과를 커밋한다.
RUN		apt-get update && apt-get install -y \
		nginx \
		mariadb-server \
		php-mysql \
		php-mbstring \
		openssl \
		wget \
		php7.3-fpm

# COPY
# 	- Host OS의 파일 또는 디렉토리를 컨테이너 안의 경로를 복사
COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp/
COPY	./srcs/wp-config.php ./tmp/
COPY	./srcs/config.inc.php ./tmp/

# EXPOSE
# 	- 컨테이너가 사용할 포트를 사용자에게 알려줌
EXPOSE	80 443

# CMD
# 	- 생성된 컨테이너를 실행할 명령어를 지정
CMD		bash run.sh


