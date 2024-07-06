#!/bin/bash

if [ ! -f "./wp-config.php" ]; then
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp

	if php -m | grep -q Phar; then
		wp core download --allow-root
		wp config create --dbname="$MYSQL_DATABASE" --dbuser="$MYSQL_USER" --dbpass="$MYSQL_PASSWORD" --dbhost="$MYSQL_HOSTNAME" --allow-root
		wp core install --url="$WP_SITE_URL" --title=Inception --admin_user="$WP_ADMIN" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" --allow-root
		wp user create "$WP_USER" "$WP_USER_EMAIL" --role=author --user_pass="$WP_USER_PASSWORD" --allow-root
  else
	  echo "php phar is not installed"
    exit 1
	fi
fi

exec "$@"
# #!/bin/sh

# if [ ! -f "./wp-config.php" ]; then
# 	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# 	chmod +x wp-cli.phar
# 	mv wp-cli.phar /usr/local/bin/wp

# 	if php -m | grep -q Phar; then
# 	  wp cli version
# 		wp core download --allow-root

# 		# wait a bit to make sure the db is up and running
# 		sleep 30

# 		sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
# 		sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
# 		sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
# 		cp wp-config-sample.php wp-config.php

# 		wp config create --dbname="$MYSQL_DATABASE" --dbuser="$MYSQL_USER" --dbpass="$MYSQL_PASSWORD" --dbhost=localhost --allow-root
		
# 		# now need to be url jcros.42.fr but now is 127.0.0.1
# 		wp core install --url=jcros.42.fr --title=Inception --admin_user=jcros --admin_password=jcros --admin_email=jcros@student.42.fr --allow-root
#   else
# 	  echo "php phar is not installed"
#     exit 1
# 	fi
# fi

# echo "wordpress is running"

# exec "$@"
# #!/bin/sh

# #check if wp-config.php exist
# if [ -f ./wp-config.php ];then
# 	echo "Wordpress is already installed"
# else

# 	wget http://wordpress.org/latest.tar.gz
# 	tar xfz latest.tar.gz
# 	mv wordpress/* .
# 	rm -rf latest.tar.gz
# 	rm -rf wordpress

# 	sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
# 	sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
# 	sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
# 	sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
# 	cp wp-config-sample.php wp-config.php
# fi

# sleep 10

# echo "Wordpress is ready"

# exec "$@"