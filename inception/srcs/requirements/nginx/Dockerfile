FROM debian:12

RUN apt update
RUN apt upgrade
RUN apt-get install -y nginx \
		openssl

COPY conf/default /etc/nginx/sites-available/default

RUN	openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
	-subj "/C=FR/ST=Paris/OU=jcros/O=Julien, Inc./CN=jcros.42.fr" \
	-keyout /etc/ssl/jcros.42.fr.key \
	-out /etc/ssl/jcros.42.fr.crt

CMD ["nginx", "-g", "daemon off;"]