FROM debian:12

# RUN apk update 
# RUN apk add --no-cache nginx 
#openssl
# RUN rm -f /var/cache/apk/*

RUN apt update
RUN apt upgrade
RUN apt install -y nginx openssl

# RUN rm -f /etc/nginx/sites-available/default
COPY conf/default /etc/nginx/sites-available/default

RUN	openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
	-subj "/C=FR/ST=Paris/O=Julien, Inc./CN=jcros.42.fr" \
	-keyout /etc/ssl/jcros.42.fr.key \
	-out /etc/ssl/jcros.42.fr.crt

# RUN mkdir -p /run/nginx

# EXPOSE 80

CMD ["nginx", "-g", "daemon off;"]
# FROM alpine:3.20.0

# RUN apk update
# RUN apk add nginx openssl


# RUN mkdir etc/nginx/ssl
# RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=42/CN=jcros.42.fr"

# # RUN mkdir -p /var/www/html

# # COPY ./conf/index.html /var/www/html
# # RUN chmod 644 /var/www/html/index.html


# COPY ./conf/nginx.conf /etc/nginx/conf.d 
# RUN chmod 644 /etc/nginx/nginx.conf

# # RUN mkdir -p /run/nginx

# EXPOSE 443

# CMD ["nginx", "-g", "daemon off;"]

