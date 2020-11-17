#/!bin/bash

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

cp -rp ./tmp/default /etc/nginx/sites-available/default

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
rm -rf phpMyAdmin-5.0.2-all-languages.tar.gz

cp -rp ./tmp/config.sample.php var/www/html/phpmyadmin/config.inc.php

service nginx start
service mysql start
service php7.3-fpm start

echo "CREATE DATABASE wordpress;" \
	| mysql -u root --skip-password
echo "CREATE USER 'wopark'@'%' identified by '1234';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wopark'@'%' identified by '1234' WITH GRANT OPTION;" \
	| mysql -u root --skip-password

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
rm -rf latest.tar.gz

chown -R www-data:www-data /var/www/html/wordpress

cp -rp ./tmp/wp-config.php var/www/html/wordpress/wp_config.php

bash
