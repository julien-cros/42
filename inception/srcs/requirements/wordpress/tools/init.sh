#!/bin/bash

if [ -f "var/www/html/wp_config.php" ]
then
	echo "wordpress aleready installed"

else 
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp

	wp core download --allow-root
	wp config create --path="/var/www/html" --dbname="$MYSQL_DATABASE" --dbuser="$MYSQL_USER" --dbpass="$MYSQL_PASSWORD" --dbhost="$MYSQL_HOSTNAME" --allow-root
	wp core install --url="$WP_SITE_URL" --title=Inception --admin_user="$WP_ADMIN" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" --allow-root
	wp user create "$WP_USER" "$WP_USER_EMAIL" --role=author --user_pass="$WP_USER_PASSWORD" --allow-root
fi

exec "$@"