# FROM alpine:3.20.0

# RUN apk update 
# RUN apk add --no-cache curl php php-cgi php-mysqli php-fpm php-pdo php-gd php-cli php-mbstring
# RUN rm -f /var/cache/apk/*

FROM debian:12

RUN apt update && apt upgrade
RUN apt install -y php8.2-fpm php8.2-mysqli curl mariadb-client

# RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
# 	&& chmod +x wp-cli.phar \
# 	&& mv wp-cli.phar /usr/local/bin/wp

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf
# RUN chmod 644 /etc/php/8.2/fpm/pool.d/www.conf

# RUN mkdir -p /run/php

# RUN apt-get install https://wordpress.org/latest.tar.gz
# RUN tar -xzvf latest.tar.gz

COPY ./tools/init.sh /usr/local/bin/init.sh
RUN chmod +x /usr/local/bin/init.sh

WORKDIR /var/www/html/


ENTRYPOINT ["/usr/local/bin/init.sh"]


# /etc/php/8.2/fpm/php-fpm.conf

# 	RUN mkdir /var/run/php

# COPY tools/init.sh /usr/local/bin/
# RUN chmod +x /usr/local/bin/init.sh

# ENTRYPOINT ["/usr/local/bin/init.sh"]

# WORKDIR /var/www/html/

# EXPOSE 9000

CMD ["/usr/sbin/php-fpm8.2", "-F"]
# FROM alpine:3.20.0

# RUN apk update
# RUN apk add --no-cache \
# 	wget \
# 	curl  \
#  	bash \
#  	php \
#  	php-cgi \
#  	php-mysqli \
#  	php-fpm \
#  	php-pdo \
#  	php-gd php-cli \
#  	php-mbstring

# RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
# && chmod +x wp-cli.phar \
# && mv wp-cli.phar /usr/local/bin/wp

# COPY ./conf/www.conf /etc/php/83/fpm/pool.d/

# RUN mkdir -p /run/php

# # RUN wget https://wordpress.org/latest.tar.gz
# # RUN tar -xzvf latest.tar.gz

# COPY ./tools/create_wordpress.sh /usr/local/bin/
# RUN chmod +x /usr/local/bin/create_wordpress.sh
# ENTRYPOINT ["/usr/local/bin/create_wordpress.sh"]

# # RUN mkdir -p /var/www/html
# # RUN mv wordpress /var/www/html

# # RUN rm -rf latest.tar.gz

# WORKDIR /var/www/html/

# EXPOSE 9000

# CMD ["usr/sbin/php-fpm8.3", "-F"]